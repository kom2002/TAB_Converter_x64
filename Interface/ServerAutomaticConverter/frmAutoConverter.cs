using System;
using System.IO;
using System.Runtime.InteropServices;   // For DllImport
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Data.OleDb;
using System.Diagnostics;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Threading;
using SpeechLib;

namespace ServerAutomaticConverter
{


	public partial class frmAutoConverter : Form
	{
		[DllImport("kernel32")]
		public static extern int GetDiskFreeSpaceEx(
		string lpDirectoryName,
		ref long lpFreeBytesAvailable,
		ref long lpTotalNumberOfBytes,
		ref long lpTotalNumberOfFreeBytes
		);

		private byte bytTimerStep = 0;
		private string strDtbShare = "";
		private int intDelayStart = 60; //delay 60 seconds

		private int intPPATatipNumber = 0;

		private BackgroundConverter b = new BackgroundConverter();
		private Thread a;

		private string strNewDirectory = "";
		private string strOutputDirectory = "";
		private string strTempOutputDirectory = "";
		private string strCompletedSuccessDirectory = "";
		private string strCompletedFailDirectory = "";

		private int intCurrentBookOrder = 0;
		private int intTotalBook = 0;
		private double dobCurrentDtbTimer = 0;
		private double dobCurrentFileTimer = 0;

		private string strSharePromptDirectory = @"W:\";
		private string strShareFtpDailynewsDirectory = @"DAILYNEWS\";

		public frmAutoConverter()
		{
			InitializeComponent();
		}

		private int fnGetPPATatipNumber()
		{
			SpeechLib.SpVoice V = new SpeechLib.SpVoice();
			int intNumOfVoice = 0; //start at 0 because, in DLL, index is zero based

			foreach (ISpeechObjectToken Token in V.GetVoices())
			{
				if (Token.GetDescription() == "PPA ตาทิพย์")
					break;
				else
					intNumOfVoice++;
			}

			return intNumOfVoice;
		}

		private void fnUpdateFreeDiskSpace(string strDrive)
		{
			//returns total space in MB, formatted to two decimal places
			long lngBytesTotal = 0, lngFreeBytes = 0, lngFreeBytesAvailable = 0;
			int intFreeBytes;
			intFreeBytes = GetDiskFreeSpaceEx(strDrive, ref lngFreeBytesAvailable, ref lngBytesTotal, ref lngFreeBytes);
			if (intFreeBytes > 0)
			{
				//update label on the frmAutoConverter
				lblDiskSpace.Text = @"Available space on drive " + strDrive + @" = " + fnBytesToMegabytes(lngFreeBytes) + @" MB.";
				lblDiskSpace.ForeColor = Color.Blue;
			}
			else
			{
				lblDiskSpace.Text = @"Cannot get available space on drive " + strDrive + @" because of invalid or unreadable drive.";
				lblDiskSpace.ForeColor = Color.Red;
			}
		}

		private string fnBytesToMegabytes(long lngBytes)
		{
			double dobMegaBytes = 0;
			dobMegaBytes = (lngBytes / 1024) / 1024;
			return dobMegaBytes.ToString("N");
		}

		//private bool fnCloseProcessServerAutomaticConverter()
		//{
		//    try
		//    {
		//        //Check all running processes in order to kill the running windows_tatip process
		//        foreach (Process clsProcess in Process.GetProcesses())
		//        {
		//            if (clsProcess.ProcessName.Contains("ServerAutomaticConverter"))
		//            {
		//                //Kill, if the process is found to be running
		//                clsProcess.Kill();
		//            }
		//        }
		//    }
		//    catch (Exception ex)
		//    {
		//        txtDetail.Text = txtDetail.Text + @" There is an error while closing the previous ServerAutomaticConverter application. " + ex.Message;
		//        return false;
		//    }

		//    return true;
		//}

		private bool fnCloseTatip()
		{
			try
			{
				//Check all running processes in order to kill the running windows_tatip process
				foreach (Process clsProcess in Process.GetProcesses())
				{
					if (clsProcess.ProcessName.Contains("windows_tatip"))
					{
						//Kill, if the process is found to be running
						clsProcess.Kill();
					}
				}
			}
			catch (Exception ex)
			{
				txtDetail.Text = txtDetail.Text + @" There is an error while closing the Tatip application. " + ex.Message;
				return false;
			}

			return true;
		}

		private bool fnOpenTatip()
		{
			try
			{
				fnCloseTatip();

				//Run the windows_tatip.exe from program file directory
				Process pcsTatip = new Process();
				pcsTatip.StartInfo.FileName = @"C:\Program Files\PPA Tatip\interface\windows_tatip.exe";
				pcsTatip.StartInfo.Arguments = " ";
				pcsTatip.Start();

				return true;
			}
			catch (Exception ex)
			{
				txtDetail.Text = txtDetail.Text + @" There is an error while opening the Tatip application. " + ex.Message;
				bytTimerStep = 240;
				timer1.Enabled = true;
				return false;
			}
		}


		private List<string> fnDiscoverNewDtb(string strDTBSHARRPath, string strDtbSubFolder)
		{
			string[] arrayStrRootFolders = null;
			string[] arrayStrNewDtbFolders = null;
			List<string> listStrNewDtbFolder = new List<string>();

			if (System.IO.Directory.Exists(strDTBSHARRPath) == true)
			{
				arrayStrRootFolders = System.IO.Directory.GetDirectories(strDTBSHARRPath);
			}
			else
			{
				txtDetail.Text = "The system cannot access the specific DTB Share folder " + strDTBSHARRPath;
				return listStrNewDtbFolder;  // Return Empty List
			}

			foreach (string strRootFolder in arrayStrRootFolders)
			{
				if (Directory.Exists(strDTBSHARRPath) == true)
				{
					if (Directory.Exists(strRootFolder + @"\" + strDtbSubFolder + @"\") == false)
						continue;
					else
						arrayStrNewDtbFolders = System.IO.Directory.GetDirectories(strRootFolder + @"\" + strDtbSubFolder + @"\");

					foreach (string strNewDtbFolder in arrayStrNewDtbFolders)
					{
						if (File.Exists(strNewDtbFolder + @"\ncc.htm"))
							listStrNewDtbFolder.Add(strNewDtbFolder + @"\ncc.htm");
						else if (File.Exists(strNewDtbFolder + @"\ncc.html"))
							listStrNewDtbFolder.Add(strNewDtbFolder + @"\ncc.html");
						else
						{
							//searching for ncx file name
							string[] arrayStrNewDtbFile = null;
							arrayStrNewDtbFile = Directory.GetFiles(strNewDtbFolder, "*.ncx");
							if (arrayStrNewDtbFile.Length == 1)
							{
								if (File.Exists(arrayStrNewDtbFile[0]))
									listStrNewDtbFolder.Add(arrayStrNewDtbFile[0]);
							}
						}
					}
				}
			}
			return listStrNewDtbFolder;
		}

		private bool fnCheckInNewDtb()
		{
			//Clear all rows in datagrid
			dgvDtbList.Rows.Clear();

			//Clear the both progress bars and text status
			this.pgbAllDtbCompleted.Value = 0;
			this.pgbCurrentDtbCompleted.Value = 0;
			this.lblAllDtbCompleted.Text = "0 %";
			this.lblCurrDtbCompleted.Text = "0 %";
			this.txtDetail.Text = "";

			//get the list of all new DTB paths from the DTB_SHARE folder
			List<string> mylistStrNewDtbNcPath = mylistStrNewDtbNcPath = fnDiscoverNewDtb(txtDtbShare.Text, @"NEW");

			//get the list of all "Dropbox" DTB paths from the DTB_SHARE folder
			List<string> mylistStrNewDropboxDtbNcPath = fnDiscoverNewDtb(txtDtbShare.Text, @"Dropbox\NEW");

			//combile both lists
			foreach (string strForEachNcPath in mylistStrNewDropboxDtbNcPath)
			{
				string strForEachNcDirectory = strForEachNcPath.Substring(0, strForEachNcPath.LastIndexOf(@"\"));
				int intTotalNumberofMp3File = 0;
				int intTotalNumberofSmilFile = 0;
				int intTotalNumberofAllFile = 0;
				intTotalNumberofMp3File = Directory.GetFiles(strForEachNcDirectory, "*.mp3", SearchOption.TopDirectoryOnly).Length;
				intTotalNumberofSmilFile = Directory.GetFiles(strForEachNcDirectory, "*.smil", SearchOption.TopDirectoryOnly).Length;
				intTotalNumberofAllFile = Directory.GetFiles(strForEachNcDirectory, "*.*", SearchOption.TopDirectoryOnly).Length;

				//if there are the total number of file equal or more than six files
				if ((intTotalNumberofAllFile >= 6) && (intTotalNumberofMp3File >= 1) && (intTotalNumberofMp3File >= intTotalNumberofSmilFile))
				{
					mylistStrNewDtbNcPath.Add(strForEachNcPath);
				}
			}

			//string for manupulate the output folder
			string strOutputFolder = "";
			int intBookIndex = 0;

			//loop all new dtb paths
			foreach (string strNewDtbNcPath in mylistStrNewDtbNcPath)
			{
				//check the prospective destination
				strOutputFolder = strNewDtbNcPath.Replace(@"\NEW\", @"\OUTPUT\");
				strOutputFolder = strOutputFolder.Replace(@"\Dropbox\", @"\");
				strOutputFolder = strOutputFolder.Substring(0, strOutputFolder.LastIndexOf(@"\"));
				strOutputFolder = strOutputFolder + @"_" + DateTime.Now.ToString("yyyyMMdd_HHmm") + @"\";


				//Check availability of the destination folder
				if (System.IO.Directory.Exists(strOutputFolder) == true)
				{
					//detele, in case it is existing
					System.IO.Directory.Delete(strOutputFolder, true);
				}

				dgvDtbList.Rows.Add();
				dgvDtbList.Rows[intBookIndex].Cells["strNcFilePath"].Value = strNewDtbNcPath;
				dgvDtbList.Rows[intBookIndex].Cells["strStatus"].Value = "waiting";

				if (strNewDtbNcPath.ToLower().EndsWith("ncc.html") || strNewDtbNcPath.ToLower().EndsWith("ncc.htm"))
					dgvDtbList.Rows[intBookIndex].Cells["strDTBVersion"].Value = "DAISY 2.02";
				else if (strNewDtbNcPath.ToLower().EndsWith(".ncx"))
					dgvDtbList.Rows[intBookIndex].Cells["strDTBVersion"].Value = "ANSI/NISO Z39.86";
				else
					dgvDtbList.Rows[intBookIndex].Cells["strDTBVersion"].Value = "Unknown";

				dgvDtbList.Rows[intBookIndex].Cells["strOutputPath"].Value = strOutputFolder;
				dgvDtbList.Rows[intBookIndex].Cells["strAudioFormat"].Value = "VOX 8K MONO ADPCM";
				dgvDtbList.Rows[intBookIndex].Cells["strSpeechEngine"].Value = "windows_tatip.exe";
				intBookIndex++;

				//In order to set priority of the NEWS converter
				//In this point should re-load all NEW DTBs
				//By giving the highest priority to NEWS DTBs

			}

			dgvDtbList.AutoResizeColumns();
			return true;
		}

		private void btnCheckNow_Click(object sender, EventArgs e)
		{
			fnCheckInNewDtb();
			if (dgvDtbList.RowCount > 0)
			{
				intDelayStart = 29; //delay 29 seconds before start
			}
			else
			{
				if (intAccumulativeConvetedBook < 20)
				{
					//This process was used to convert book less than 20 titles
					intDelayStart = 300; //delay 300 seconds (5 minutes) before start
				}
				else
				{
					//This process was used to convert book greater than 20 titles
					//Restart the process
					if (bytTimerStep < 240)
					{
						bytTimerStep = 240;
						timer1.Enabled = true;
						return;
					}
				}
			}
			tmrDelayStart.Interval = 1000; // 1000 = 1 second
			tmrDelayStart.Enabled = true;



			//update the last-check label
			lblLastCheck.Text = DateTime.Now.ToString();

			//update the next-check label
			lblNextCheck.Text = DateTime.Now.AddMinutes(20).ToString();


		}

		private void btnChooseFolder_Click(object sender, EventArgs e)
		{
			// Show the FolderBrowserDialog.
			DialogResult result = folderBrowserDialog1.ShowDialog();
			if (result == DialogResult.OK)
			{

				txtDtbShare.Text = folderBrowserDialog1.SelectedPath;
			}

		}

		//Include following code with yours to refresh System Tray.
		public const int WM_PAINT = 0xF;
		[DllImport("USER32.DLL")]
		public static extern int SendMessage(IntPtr hwnd, int msg, int character, IntPtr lpsText);
		[DllImport("user32.dll", SetLastError = true)]
		static extern IntPtr FindWindow(string lpClassName, string lpWindowName);
		//[DllImport("user32.dll", SetLastError = true)]
		//public static extern IntPtr FindWindowEx(IntPtr parentHandle, IntPtr childAfter, string className, IntPtr windowTitle);
		[DllImport("user32.dll", SetLastError = true)]
		static extern IntPtr FindWindowEx(IntPtr hwndParent, IntPtr hwndChildAfter, string lpszClass, string lpszWindow);
		[DllImport("user32.dll")]
		static extern bool GetClientRect(IntPtr hWnd, out System.Drawing.Rectangle lpRect);
		const uint WM_MOUSEMOVE = 0x0200;

		private void RefreshSystemTray()
		{
			//Send WM_PAINT Message to paint System Tray which will refresh it.
			IntPtr ipTray = FindWindow("Shell_TrayWnd", null);
			if (ipTray == null) return;
			IntPtr ipTrayNotify = FindWindowEx(ipTray, IntPtr.Zero, "TrayNotifyWnd", "");
			if (ipTrayNotify == null) return;
			IntPtr ipSysPager = FindWindowEx(ipTrayNotify, IntPtr.Zero, "SysPager", "");
			if (ipSysPager == null) return;
			IntPtr ipNotificationArea = FindWindowEx(ipSysPager, IntPtr.Zero, "ToolbarWindow32", "Notification Area");
			if (ipNotificationArea == null) return;
			//SendMessage(ipNotificationArea, WM_PAINT, 0, IntPtr.Zero);	

			System.Drawing.Rectangle r;
			GetClientRect(ipTray, out r);

			for (int x = r.Location.X; x < r.Location.X + r.Right; x += 5)
				for (int y = r.Location.Y; y < r.Location.Y + r.Bottom; y += 5)
					Cursor.Position = new Point(x, y);


		}



		private void Form1_Load(object sender, EventArgs e)
		{
			tmrHeartbeat.Interval = 60000;
			tmrHeartbeat.Enabled = true;

			//Delete unused Tatip Icon placed on the system-tray
			//RefreshSystemTray();

			//Get PPA Tatip ID
			intPPATatipNumber = fnGetPPATatipNumber();

			//Reset the strDtbShare variable
			txtDtbShare_TextChanged(sender, e);

			//Check Available space on the DTB_SHARE drive
			if (txtDtbShare.Text.Substring(1, 2) == @":\")
				fnUpdateFreeDiskSpace(strDtbShare.Substring(0, 3));
			else
				fnUpdateFreeDiskSpace(@"C:\");

			//Check CPU Speed
			b.fnGetCpuSpeed();
			lblCpuSpeed.Text = "CPU Speed = " + b.intCpuSpeed.ToString() + " MHz";

			bytTimerStep = 0;
			timer1.Interval = 2000;
			timer1.Enabled = true;
		}

		private void timer1_Tick(object sender, EventArgs e)
		{
			if (bytTimerStep == 0)
			{
				bytTimerStep++;
				fnCloseTatip();
			}
			else if (bytTimerStep == 1)
			{
				timer1.Interval = 15000;
				bytTimerStep++;
				//Launch TATIP text-to-speech software
				fnOpenTatip();
			}
			else if (bytTimerStep == 2)
			{
				timer1.Interval = 2000;
				bytTimerStep++;

				//Upload News to the Telephony2 MDB
				fnCheckInForUpload(txtDtbShare.Text + strShareFtpDailynewsDirectory);
			}
			else if (bytTimerStep == 3)
			{
				timer1.Interval = 2000;
				bytTimerStep++;

				//Get & Convert All Unconverted text to Audio Name as label
				fnConvertAllAudioFiles(strSharePromptDirectory);

				//Get & Move all new books to the library
				fnMoveNewBookToLibrary();
			}
			else if (bytTimerStep == 4)
			{
				btnCheckNow.Enabled = true;
				btnStart.Enabled = true;
				//Stop timer1   
				this.timer1.Enabled = false;
				//Check-In NEW DTB(s) from all share folders
				btnCheckNow_Click(sender, e);
			}

			else if (bytTimerStep == 6)
			{
				//Start Converting
			}
			else if (bytTimerStep == 240)
			{
				bytTimerStep++;
                if (b != null)
                {
                    //b.fnDestroyConverter();
                    b = null;
                }

				if (a != null)
				{
					a.Abort();
					a = null;
				}
				tmrHeartbeat.Enabled = false;
				tmrConverting.Enabled = false;
				tmrDelayStart.Enabled = false;
				button1.Enabled = false;
				button4.Enabled = false;
				fnCloseTatip();
			}
			else if (bytTimerStep == 241)
			{
				timer1.Enabled = false;
				Application.Restart();
			}
			else if (bytTimerStep == 250)
			{
				bytTimerStep++;
                if (b != null)
                {
                    //b.fnDestroyConverter();
                    b = null;
                }

				if (a != null)
				{
					a.Abort();
					a = null;
				}
				tmrHeartbeat.Enabled = false;
				tmrConverting.Enabled = false;
				tmrDelayStart.Enabled = false;
				button1.Enabled = false;
				button4.Enabled = false;
				fnCloseTatip();
			}
			else if (bytTimerStep == 251)
			{
				timer1.Enabled = false;
				Application.Exit();
			}
		}

		private void Form1_FormClosing(object sender, FormClosingEventArgs e)
		{
			if ((bytTimerStep < 240))
			{
				e.Cancel = true;
				bytTimerStep = 250;
				timer1.Enabled = true;
			}
		}

		private void button1_Click(object sender, EventArgs e)
		{
			if (bytTimerStep < 240)
			{
				if (MessageBox.Show("Do you really want to restart the application?", "Restart Application", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning) == DialogResult.OK)
				{
					bytTimerStep = 240;
					timer1.Enabled = true;
				}
			}
		}

		private void button4_Click(object sender, EventArgs e)
		{
			if (bytTimerStep < 240)
			{
				if (MessageBox.Show("Do you really want to exit?", "Exit Application", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning) == DialogResult.OK)
				{
					bytTimerStep = 250;
					timer1.Enabled = true;
				}
			}
		}

		private void txtDtbShare_TextChanged(object sender, EventArgs e)
		{
			strDtbShare = txtDtbShare.Text;
		}

		private void tmrDelayStart_Tick(object sender, EventArgs e)
		{
			if (intDelayStart <= 0)
			{
				//Stop Timer
				tmrDelayStart.Enabled = false;

				//Update The Time-To-Start Lable
				lblSecondToStart.Text = "Started";

				//Start Converting Process
				btnStart_Click(sender, e);
			}

			if (intDelayStart == 30)		//check new book 30 sec prior start converting
			{
				btnCheckNow_Click(sender, e);
			}
			else if (intDelayStart == 60)	// upload remaining news 60 sec prior start converting
			{
				//Upload News to the Telephony2 MDB
				fnCheckInForUpload(txtDtbShare.Text + strShareFtpDailynewsDirectory);
				intDelayStart--;
			}
			else if (intDelayStart == 90)	// convert audio label 90 sec prior start converting
			{
				//Get & Convert All Unconverted text to Audio Name as label
				fnConvertAllAudioFiles(strSharePromptDirectory);
				
				//Get & Move all new books to the library
				fnMoveNewBookToLibrary(); 
				
				intDelayStart--;
			}
			else
			{
				intDelayStart--;

				//Update The Time-To-Start Lable
				lblSecondToStart.Text = intDelayStart.ToString();
			}
		}

		private void btnMoveRowUp_Click(object sender, EventArgs e)
		{
			if (dgvDtbList.RowCount > 0)
				moveDgvRowUp();
		}

		private void btnMoveRowDown_Click(object sender, EventArgs e)
		{
			if (dgvDtbList.RowCount > 0)
				moveDgvRowDown();
		}

		private void btnMoveRowTop_Click(object sender, EventArgs e)
		{
			if (dgvDtbList.RowCount > 0)
			{
				while (dgvDtbList.CurrentRow.Index > 0)
				{
					moveDgvRowUp();
				}
			}
		}

		private void btnMoveRowBottom_Click(object sender, EventArgs e)
		{
			if (dgvDtbList.RowCount > 0)
			{
				while (dgvDtbList.CurrentRow.Index < dgvDtbList.RowCount - 1)
				{
					moveDgvRowDown();
				}
			}
		}

		private void moveDgvRowUp()
		{
			if ((dgvDtbList.SelectedRows != null) && (dgvDtbList.CurrentRow.Index > 0))
			{
				string[] strTempValue = new string[6];

				strTempValue[0] = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index - 1].Cells[0].Value.ToString();
				strTempValue[1] = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index - 1].Cells[1].Value.ToString();
				strTempValue[2] = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index - 1].Cells[2].Value.ToString();
				strTempValue[3] = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index - 1].Cells[3].Value.ToString();
				strTempValue[4] = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index - 1].Cells[4].Value.ToString();
				strTempValue[5] = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index - 1].Cells[5].Value.ToString();

				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index - 1].Cells[0].Value = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[0].Value;
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index - 1].Cells[1].Value = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[1].Value;
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index - 1].Cells[2].Value = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[2].Value;
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index - 1].Cells[3].Value = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[3].Value;
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index - 1].Cells[4].Value = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[4].Value;
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index - 1].Cells[5].Value = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[5].Value;

				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[0].Value = strTempValue[0];
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[1].Value = strTempValue[1];
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[2].Value = strTempValue[2];
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[3].Value = strTempValue[3];
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[4].Value = strTempValue[4];
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[5].Value = strTempValue[5];

				dgvDtbList.CurrentCell = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index - 1].Cells[0];
				dgvDtbList.AutoResizeColumns();
				strTempValue = null;
			}

		}

		private void moveDgvRowDown()
		{
			if ((dgvDtbList.SelectedRows != null) && (dgvDtbList.CurrentRow.Index < dgvDtbList.RowCount - 1))
			{
				string[] strTempValue = new string[6];

				strTempValue[0] = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index + 1].Cells[0].Value.ToString();
				strTempValue[1] = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index + 1].Cells[1].Value.ToString();
				strTempValue[2] = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index + 1].Cells[2].Value.ToString();
				strTempValue[3] = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index + 1].Cells[3].Value.ToString();
				strTempValue[4] = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index + 1].Cells[4].Value.ToString();
				strTempValue[5] = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index + 1].Cells[5].Value.ToString();

				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index + 1].Cells[0].Value = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[0].Value;
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index + 1].Cells[1].Value = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[1].Value;
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index + 1].Cells[2].Value = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[2].Value;
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index + 1].Cells[3].Value = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[3].Value;
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index + 1].Cells[4].Value = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[4].Value;
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index + 1].Cells[5].Value = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[5].Value;

				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[0].Value = strTempValue[0];
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[1].Value = strTempValue[1];
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[2].Value = strTempValue[2];
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[3].Value = strTempValue[3];
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[4].Value = strTempValue[4];
				dgvDtbList.Rows[dgvDtbList.CurrentRow.Index].Cells[5].Value = strTempValue[5];

				dgvDtbList.CurrentCell = dgvDtbList.Rows[dgvDtbList.CurrentRow.Index + 1].Cells[0];
				dgvDtbList.AutoResizeColumns();
				strTempValue = null;
			}
		}

		private void btnStopNow_Click(object sender, EventArgs e)
		{
			if (tmrDelayStart.Enabled == true)
			{
				tmrDelayStart.Enabled = false;
			}
		}

		private void SetEnableAllControl(bool Enabled)
		{
			if (Enabled == false)
			{
				btnChooseFolder.Enabled = false;
				btnCheckNow.Enabled = false;
				btnStart.Enabled = false;
				btnMoveRowBottom.Enabled = false;
				btnMoveRowDown.Enabled = false;
				btnMoveRowTop.Enabled = false;
				btnMoveRowUp.Enabled = false;
				txtDtbShare.Enabled = false;
				dgvDtbList.Enabled = false;
			}
			else
			{
				btnChooseFolder.Enabled = true;
				btnCheckNow.Enabled = true;
				btnStart.Enabled = true;
				btnMoveRowBottom.Enabled = true;
				btnMoveRowDown.Enabled = true;
				btnMoveRowTop.Enabled = true;
				btnMoveRowUp.Enabled = true;
				txtDtbShare.Enabled = true;
				dgvDtbList.Enabled = true;
			}
		}


		private bool boolFoundErrorBook = false;
		private int intAccumulativeConvetedBook = 0;
		private void btnStart_Click(object sender, EventArgs e)
		{
			try
			{
				if (dgvDtbList.RowCount <= 0)
					return;
				else
					SetEnableAllControl(false);

				//Stop DelayStart Timer
				tmrDelayStart.Enabled = false;

				//Update The Time-To-Start Lable
				lblSecondToStart.Text = "Started";

				//Get Total Book in the grid
				intTotalBook = dgvDtbList.RowCount;

				//Reset Current book order
				intCurrentBookOrder = 0;

				for (int intLoop = 0; intLoop < intTotalBook; intLoop++)
				{
					//Adjust Book Order
					intCurrentBookOrder = intLoop;


					//Change Display
					label5.Text = "All DTBs Complete : " + intLoop.ToString() + @"/" + intTotalBook.ToString() + @" (Previous Accumulative Converted-Book = " + intAccumulativeConvetedBook.ToString() + @")";

					//Rows[0] is source            ex.     dgvDtbList.Rows[intBookIndex].Cells["strNcFilePath"].Value = strNewDtbNcPath;
					//Rows[1] is status            ex.     dgvDtbList.Rows[intBookIndex].Cells["strStatus"].Value = "waiting";
					//Rows[2] is DTB version       ex.     dgvDtbList.Rows[intBookIndex].Cells["strDTBVersion"].Value = "ANSI/NISO Z39.86"; [or] "DAISY 2.02";
					//Rows[3] is destination       ex.     dgvDtbList.Rows[intBookIndex].Cells["strOutputPath"].Value = strOutputFolder;
					//Rows[4] is Audio Format      ex.     dgvDtbList.Rows[intBookIndex].Cells["strAudioFormat"].Value = "VOX 8K MONO ADPCM";
					//Rows[5] is speech engine     ex.     dgvDtbList.Rows[intBookIndex].Cells["strSpeechEngine"].Value = "windows_tatip.exe";

					if (dgvDtbList.Rows[intLoop].Cells["strStatus"].Value.ToString() == "waiting")
					{
						//Change the status
						dgvDtbList.Rows[intLoop].Cells["strStatus"].Value = "converting";

						//Update intAccumulativeConvetedBook
						intAccumulativeConvetedBook = intAccumulativeConvetedBook + 1;

						//Setup the new path
						strNewDirectory = dgvDtbList.Rows[intLoop].Cells["strNcFilePath"].Value.ToString().ToLower(); //strOutputDirectory.Replace(@"\output\", @"\new\");
						strNewDirectory = strNewDirectory.Substring(0, strNewDirectory.LastIndexOf(@"\") + 1);

						//Remember the current output path
						strOutputDirectory = dgvDtbList.Rows[intLoop].Cells["strOutputPath"].Value.ToString().ToLower();

						//Setup the strCompletedSuccessDirectory
						strCompletedSuccessDirectory = strOutputDirectory.Replace(@"\output\", @"\completed\success\");

						//Setup the strCompletedFailDirectory
						strCompletedFailDirectory = strOutputDirectory.Replace(@"\output\", @"\completed\fail\");

						//Setup the Temp output path In order to prevent user(librarian) use uncompleted book 
						//Loop for finding an available directory using as TEMP folder
						for (int intTempDiretoryExtension = 0; intTempDiretoryExtension < 500; intTempDiretoryExtension++)
						{
							strTempOutputDirectory = strOutputDirectory.Substring(0, strOutputDirectory.LastIndexOf(@"\output\") + 8) + intTempDiretoryExtension.ToString("00000000") + @"\";
							if (Directory.Exists(strTempOutputDirectory) == true)
							{
								try
								{
									Directory.Delete(strTempOutputDirectory);
									break;
								}
								catch (Exception)
								{
									continue;
								}
							}
							else
							{
								break;
							}
						}

						//Check Signature
						if (File.Exists(strNewDirectory + "TAB_AUTOCONVERTER.TXT") == false)
						{
							//This DTB has not been converted before
							//Create Signature mention that this book will have been converting
							StreamWriter writer = new StreamWriter(strNewDirectory + "TAB_AUTOCONVERTER.TXT");
							writer.Write(@"This DTB has been started by the converting process at " + DateTime.Now.ToLongDateString() + @" " + DateTime.Now.ToLongTimeString());
							writer.Close();
						}
						else
						{
							//This DTB has been conveted and There is ERROR without reason
							dgvDtbList.Rows[intCurrentBookOrder].Cells["strStatus"].Value = "error#" + b.intReturnValue.ToString();

							//Move the source folder to the completed FAIL folder
							if (Directory.Exists(strCompletedFailDirectory) == true)
								Directory.Delete(strCompletedFailDirectory, true); //clear completed fail folder
							if (Directory.Exists(strNewDirectory) == true)
								Directory.Move(strNewDirectory, strCompletedFailDirectory);

							//Tell the tmrConverting Timer that เจอหนังสือที่ Errror ซึ่งได้ย้ายไปเก็บที่ Fail เรียบร้อยแล้ว ให้เลือเล่มใหม่มาแปลงได้เลย
							boolFoundErrorBook = true;

							//Setup and Start Timer
							dobCurrentFileTimer = 0;
							tmrConverting.Enabled = true;

							return;
						}

						//create the temp output folder
						if (Directory.Exists(strTempOutputDirectory) == true)
							Directory.Delete(strTempOutputDirectory, true);
						Directory.CreateDirectory(strTempOutputDirectory);

						//Pass value to the coverter DLL
						b.myStrNcPath = dgvDtbList.Rows[intLoop].Cells["strNcFilePath"].Value.ToString();
						b.myStrDestFolder = strTempOutputDirectory;
						b.myBolMakeSyntheticSound = false;
						b.myintOrderText2Speech = intPPATatipNumber;
						b.myChrOutputAudioFormat = "vox"; // FIX for only VOX format
						b.intReturnValue = -9999; //reset value

						//Setup and Start Timer
						dobCurrentFileTimer = 0;
						tmrConverting.Enabled = true;

						a = null;
						a = new Thread(b.fnConvertBook);
						a.Priority = ThreadPriority.Normal;
						a.Start();

						return;
					}
				}
			}
			catch (Exception ex)
			{
				txtDetail.Text = "Error message from btnStart_Click " + ex.Message;
				if (a != null)
				{
					a.Abort();
					a = null;
				}
			}


			//Enable and Run the CheckNow Button
			tmrConverting.Enabled = false;
			btnCheckNow.Enabled = true;
			btnCheckNow_Click(sender, e);
		}

		private int fnCountFileSizeEqualZero(string strCheckingPath)
		{
			int intNumberOfVoxFileSizeEqualZero = 0;

			try
			{
				string[] arrStrVoxFiles = Directory.GetFiles(strCheckingPath, @"*.vox");

				foreach (string strVoxFileName in arrStrVoxFiles)
				{
					FileInfo fiVoxFile = new FileInfo(strVoxFileName);
					if (fiVoxFile.Exists == true)
						if (fiVoxFile.Length == 0)
							intNumberOfVoxFileSizeEqualZero++;
					fiVoxFile = null;
				}
			}
			catch (Exception)
			{
				intNumberOfVoxFileSizeEqualZero++;
			}

			return intNumberOfVoxFileSizeEqualZero;
		}
		private void tmrConverting_Tick(object sender, EventArgs e)
		{
			try
			{
				if (boolFoundErrorBook == true)
				{
					//หนังสือที่แปลงเป็นหนังสือที่เคยเกิด Error มาแล้ว

					//Stop DTB TIMER
					tmrConverting.Enabled = false;
					dobCurrentFileTimer = 0;

					//reset state
					boolFoundErrorBook = false;

					//look for other unconverted DTBs
					btnStart_Click(sender, e);

					return;
				}

				try
				{
					StreamReader myStreamReader1 = new StreamReader(strTempOutputDirectory + "status.log", System.Text.Encoding.GetEncoding("windows-874"));
					int intCurrentPercent = int.Parse(myStreamReader1.ReadLine());
					lblDtbName.Text = myStreamReader1.ReadLine();
					lblDtbStatus.Text = myStreamReader1.ReadLine();
					lblFileName.Text = myStreamReader1.ReadLine();
					lblFileStatus.Text = myStreamReader1.ReadLine();
					myStreamReader1.Close();


					pgbCurrentDtbCompleted.Value = intCurrentPercent;
					lblCurrDtbCompleted.Text = intCurrentPercent + "%";
					if (intTotalBook > 0)
					{
						pgbAllDtbCompleted.Value = ((intCurrentBookOrder / intTotalBook) * 100);// +(intCurrentPercent / intTotalBook);
						lblAllDtbCompleted.Text = pgbAllDtbCompleted.Value.ToString() + "%";
					}

					//Update Log every 1 minute while converting is not done yet
					if ((dobCurrentFileTimer % 30 == 0) && (b.intReturnValue == -9999))
					{
						if (File.Exists(strTempOutputDirectory + "result.log") == true)
						{
							//Copy the file for display.
							System.IO.File.Copy(strTempOutputDirectory + "result.log", strTempOutputDirectory + "result2.log", true);
							StreamReader myStreamReader2 = new StreamReader(strTempOutputDirectory + "result2.log", System.Text.Encoding.GetEncoding("windows-874"));
							txtDetail.Text = myStreamReader2.ReadToEnd();
							myStreamReader2.Close();
							if (File.Exists(strTempOutputDirectory + "result2.log") == true)
								System.IO.File.Delete(strTempOutputDirectory + "result2.log");
							intCurrentPercent = pgbAllDtbCompleted.Value;
							intCurrentPercent = intCurrentPercent - (intCurrentPercent % 5);
							//mdlPublic.PlayMod5Percent(currentPercent) //play sound
						}
					}
				}
				catch (Exception ex)
				{
					txtDetail.Text = "Error message from tmrConverting_Tick (Display status part) " + ex.Message;
				}


				//FILE TIMER
				dobCurrentDtbTimer = dobCurrentDtbTimer + 10;
				TimeSpan myTimeSpan = TimeSpan.FromSeconds(dobCurrentDtbTimer);
				lblDtbTime.Text = myTimeSpan.ToString();

				if (b.intReturnValue == -9999)
				{	//Converting is NOT DONE

					//Adjust DTB TIMER
					dobCurrentFileTimer = dobCurrentFileTimer + 10;
					myTimeSpan = TimeSpan.FromSeconds(dobCurrentFileTimer);
					lblFileTime.Text = myTimeSpan.ToString();
				}
				else
				{	//Converting is DONE

					//Stop DTB TIMER
					tmrConverting.Enabled = false;
					dobCurrentFileTimer = 0;

					//Check the Return Value AND Check the Empty File size
					if ((b.intReturnValue == 9999) && (fnCountFileSizeEqualZero(strTempOutputDirectory) < 2))
					{
						//SUCCESS

						//Delete the SIGNTURE file
						if (File.Exists(strNewDirectory + "TAB_AUTOCONVERTER.TXT") == true)
						{
							File.Delete(strNewDirectory + "TAB_AUTOCONVERTER.TXT");
						}

						dgvDtbList.Rows[intCurrentBookOrder].Cells["strStatus"].Value = "completed";

						//Rename(Move) the temp to the real output folder
						if (Directory.Exists(strOutputDirectory) == true)
							Directory.Delete(strOutputDirectory, true); //clear output folder
						if (Directory.Exists(strTempOutputDirectory) == true)
							Directory.Move(strTempOutputDirectory, strOutputDirectory); //Rename

						//Move the source folder to the completed SUCCESS folder
						if (Directory.Exists(strCompletedSuccessDirectory) == true)
							Directory.Delete(strCompletedSuccessDirectory, true); //clear completed success folder
						if (Directory.Exists(strNewDirectory) == true)
							Directory.Move(strNewDirectory, strCompletedSuccessDirectory);
					}
					else
					{
						//FAIL

						dgvDtbList.Rows[intCurrentBookOrder].Cells["strStatus"].Value = "error#" + b.intReturnValue.ToString();

						//Delete the temp output folder
						if (Directory.Exists(strTempOutputDirectory) == true)
							System.IO.Directory.Delete(strTempOutputDirectory, true);

						//Move the source folder to the completed FAIL folder
						if (Directory.Exists(strCompletedFailDirectory) == true)
							Directory.Delete(strCompletedFailDirectory, true); //clear completed fail folder
						if (Directory.Exists(strNewDirectory) == true)
							Directory.Move(strNewDirectory, strCompletedFailDirectory);
					}

					b.intReturnValue = -9999; //reset value
					pgbCurrentDtbCompleted.Value = 100;

					//Resize Column
					dgvDtbList.AutoResizeColumns();

					//look for other unconverted DTBs
					btnStart_Click(sender, e);
				}
			}
			catch (Exception ex)
			{
				//MessageBox.Show(ex.Message, "Error Message from tmrConverting_Tick");
				txtDetail.Text = "Error Message from tmrConverting_Tick" + ex.Message;

				//look for the unconverted DTBs
				//btnStart_Click(sender, e);

				//Restart application without any asking
				if (bytTimerStep < 240)  //เช็คว่าไม่ได้กำลังถูกปิดอยู่
				{
					bytTimerStep = 240;
					timer1.Enabled = true;
				}
			}
		}


		long lngPreviousOutputDirectorySize = 0;
		long lngCurrentOutputDirectorySize = 0;
		private void tmrHeartbeat_Tick(object sender, EventArgs e)
		{
			lblHeartbeat.Text = (int.Parse(lblHeartbeat.Text) + 1).ToString();

			if (tmrConverting.Enabled == true)
			{
				//The converting process is working

				//Get the size of the (temp) output directory
				lngCurrentOutputDirectorySize = GetDirectorySize(strTempOutputDirectory);

				if (lngPreviousOutputDirectorySize != lngCurrentOutputDirectorySize)
				{
					//The converting process is working PROPERLY
					lngPreviousOutputDirectorySize = lngCurrentOutputDirectorySize;
				}
				else
				{
					//THERE IS AN ERROR OCCUR AT THIS MOMENT
					//GRACEFULLY RE-START
					//Restart application without any asking
					if (bytTimerStep < 240)  //เช็คว่าไม่ได้กำลังถูกปิดอยู่
					{
						bytTimerStep = 240;
						timer1.Enabled = true;
					}
				}
			}
			else
			{
				//The converting process is NOT working

				//reset values
				lngPreviousOutputDirectorySize = 0;
				lngCurrentOutputDirectorySize = 0;

			}
		}

		private long GetDirectorySize(string strDirectoryPath)
		{
			try
			{
				// Get array of all file names.
				string[] a = Directory.GetFiles(strDirectoryPath, "*.*");

				// Calculate total bytes of all files in a loop.
				long b = 0;
				foreach (string name in a)
				{
					// Use FileInfo to get length of each file.
					FileInfo info = new FileInfo(name);
					b += info.Length;
				}
				// Return total size
				return b;
			}
			catch (Exception)
			{
				return 1;  //1 is not equal as 0 so the application will not stop at this time(this loop).
			}
		}

		private NewsItem SqlFuncGetNewItem(int intContentItemId)
		{
			string strContentTitle = "";
			string strContentInfo = "";

			try
			{
				SqlConnection con = new SqlConnection("Server=192.168.100.8;Database=DaisyNews;Integrated Security=SSPI");
				con.Open();
				SqlCommand com = new SqlCommand();
				com.Connection = con;
				com.CommandType = CommandType.StoredProcedure;
				com.CommandText = "nrGetNewsItem";
				com.Parameters.Add(new SqlParameter("@ContentItemId", intContentItemId));
				//com.ExecuteNonQuery();

				SqlDataReader reader = com.ExecuteReader();
				if (reader.HasRows)
				{
					reader.Read();
					strContentTitle = reader["ContentTitle"].ToString();
					strContentInfo = @" เวปไซต์ต้นฉบับคือ " + reader["ContentURL"].ToString();
				}
				reader.Close();
				com.Dispose();
				con.Close();
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
			}

			return new NewsItem(strContentTitle, strContentInfo);
		}

		private void fnCheckInForUpload(string strConvertedDaisyNewsPath)
		{
			//get all directories in strConvertedDaisyNewsPath
			//This will return all OUTPUT DTBs in all folder including NLB\OUTPUT ORGNEWS\OUTPUT DAILYNEWS\OUTPUT
			//BUT we need only DAILYNEWS\OUTPUT
			List<string> lstStrDtbsToUpload = fnDiscoverNewDtb(txtDtbShare.Text, @"OUTPUT");

			//loop all new dtb paths
			foreach (string strOutputPath in lstStrDtbsToUpload)
			{
				//EXAMPLE = F:\DTB_SHARE_FTP\DAILYNEWS\OUTPUT\[09007]_25531015_0305_7764_ไอเอ็นเอ็น_บันเทิง_25531015_0323\dtb.ncx
				if (strOutputPath.Contains(@"\DAILYNEWS\OUTPUT\") && (strOutputPath.Length > 80))
				{
					try
					{
						//Get Catalog Code from Path name (LIMIT CATALOGCODE=1)
                        string strSingleCatalogCode = strOutputPath.Substring(strOutputPath.IndexOf(@"\DAILYNEWS\OUTPUT\") + 19, 5);
						//Get NEWS ID from Path name 
						//int intNewsId = int.Parse(strOutputPath.Substring(56,5)); 
						string[] strParameterToken = strOutputPath.Split(new Char[] { '_' });

						//Search for Title and Detail from database by using NEWS ID 
						NewsItem currentNewsItem = SqlFuncGetNewItem(int.Parse(strParameterToken[3]));

						currentNewsItem.strDetail = @"ข่าวนี้นำมาจากหนังสือพิมพ์ " + strParameterToken[4] +
													@" หัวข้อข่าว " + strParameterToken[5] +
													@" เมื่อวันที่ " + strParameterToken[1].Substring(6, 2) +
													@" เดือน " + strParameterToken[1].Substring(4, 2) +
													@" ปี " + strParameterToken[1].Substring(0, 4) +
													@" เวลา " + strParameterToken[2].Substring(0, 2) +
													@" นาฬิกา " + strParameterToken[2].Substring(2, 2) + @" นาที " + currentNewsItem.strDetail;


						currentNewsItem.strTitle = currentNewsItem.strTitle.Replace(@"'", @"");
						currentNewsItem.strTitle = currentNewsItem.strTitle.Replace(@"""", @"");
						currentNewsItem.strTitle = currentNewsItem.strTitle.Trim();
						if (currentNewsItem.strTitle.Length > 253)
							currentNewsItem.strTitle = currentNewsItem.strTitle.Substring(0, 253);

						currentNewsItem.strDetail = currentNewsItem.strDetail.Replace(@"'", @"");
						currentNewsItem.strDetail = currentNewsItem.strDetail.Replace(@"""", @"");
						currentNewsItem.strDetail = currentNewsItem.strDetail.Replace(@" เมื่อวันที่ 0", @" เมื่อวันที่ ");
						currentNewsItem.strDetail = currentNewsItem.strDetail.Replace(@" เดือน 01 ปี ", @" มกราคม ");
						currentNewsItem.strDetail = currentNewsItem.strDetail.Replace(@" เดือน 02 ปี ", @" กุมภาพันธ์ ");
						currentNewsItem.strDetail = currentNewsItem.strDetail.Replace(@" เดือน 03 ปี ", @" มีนาคม ");
						currentNewsItem.strDetail = currentNewsItem.strDetail.Replace(@" เดือน 04 ปี ", @" เมษายน ");
						currentNewsItem.strDetail = currentNewsItem.strDetail.Replace(@" เดือน 05 ปี ", @" พฤษภาคม ");
						currentNewsItem.strDetail = currentNewsItem.strDetail.Replace(@" เดือน 06 ปี ", @" มิถุนายน ");
						currentNewsItem.strDetail = currentNewsItem.strDetail.Replace(@" เดือน 07 ปี ", @" กรกฎาคม ");
						currentNewsItem.strDetail = currentNewsItem.strDetail.Replace(@" เดือน 08 ปี ", @" สิงหาคม ");
						currentNewsItem.strDetail = currentNewsItem.strDetail.Replace(@" เดือน 09 ปี ", @" กันยายน ");
						currentNewsItem.strDetail = currentNewsItem.strDetail.Replace(@" เดือน 10 ปี ", @" ตุลาคม ");
						currentNewsItem.strDetail = currentNewsItem.strDetail.Replace(@" เดือน 11 ปี ", @" พฤศจิกายน ");
						currentNewsItem.strDetail = currentNewsItem.strDetail.Replace(@" เดือน 12 ปี ", @" ธันวาคม ");
						currentNewsItem.strDetail = currentNewsItem.strDetail.Replace(@" เวลา 0", @" เวลา ");
						currentNewsItem.strDetail = currentNewsItem.strDetail.Replace(@" นาฬิกา 0", @" นาฬิกา ");
						currentNewsItem.strDetail = currentNewsItem.strDetail.Trim();
						if (currentNewsItem.strDetail.Length > 253)
							currentNewsItem.strDetail = currentNewsItem.strDetail.Substring(0, 253);

						//Start Uploading TO SQL SERVER at Telephony-New-IBM
						fnAutoUploadNewsToSqlServer(strOutputPath, strSingleCatalogCode, currentNewsItem.strTitle, currentNewsItem.strDetail);

                        //Move the new book to library immediately
                        fnMoveNewBookToLibrary();
						//Start Uploading TO MDB at Telephony-Dell
						//fnAutoUploadNews(strOutputPath, @"U:\", strSingleCatalogCode, currentNewsItem.strTitle, currentNewsItem.strDetail);
						//////if (fnAutoUploadNews(strOutputPath, @"U:\", strSingleCatalogCode, currentNewsItem.strTitle, currentNewsItem.strDetail) == true)
						//////{
						//////Move OUTPUT to UPLOADED folder
						////string _strOutputPath = strOutputPath.Replace(@"\dtb.ncx", "");
						////string _strUploadedPath = _strOutputPath.Replace("OUTPUT", "UPLOADED");

						////////Move the OUTPUT folder to the UPLOADED folder
						//////if (Directory.Exists(_strUploadedPath) == true)
						//////    Directory.Delete(_strUploadedPath, true); //clear completed success folder
						//////if (Directory.Exists(_strOutputPath) == true)
						//////    Directory.Move(_strOutputPath, _strUploadedPath);

						//////Delete the OUTPUT folder for Saving space
						//////Intend to use for auto uploading content such as Dailynews 
						////if (Directory.Exists(_strOutputPath) == true)
						////    Directory.Delete(_strOutputPath, true); //clear completed success folder
						//////}
					}
					catch (Exception)
					{ }
				}
			}
		}

		private string fnGetFileNameWithoutThePath(string strInputFileWithFullPath)
		{
			return strInputFileWithFullPath.Substring(strInputFileWithFullPath.LastIndexOf(@"\"));
		}


		private int fnConverCatalogCode(string strCatalogCode, bool isCatalogForAllNews)
		{
			if (isCatalogForAllNews == true)
			{
				if (strCatalogCode.StartsWith("01"))
					return 20;
				else if (strCatalogCode.StartsWith("02"))
					return 21;
				else if (strCatalogCode.StartsWith("03"))
					return 22;
				else if (strCatalogCode.StartsWith("04"))
					return 23;
				else if (strCatalogCode.StartsWith("05"))
					return 24;
				else if (strCatalogCode.StartsWith("06"))
					return 28;
				else if (strCatalogCode.StartsWith("07"))
					return 25;
				else if (strCatalogCode.StartsWith("08"))
					return 26;
				else if (strCatalogCode.StartsWith("09"))
					return 27;
				else
					return 0;
			}
			else
			{
				if (strCatalogCode == "01001")
					return 29;
				else if (strCatalogCode == "01002")
					return 30;
				else if (strCatalogCode == "01003")
					return 31;
				else if (strCatalogCode == "01004")
					return 32;
				else if (strCatalogCode == "01005")
					return 33;
				else if (strCatalogCode == "01006")
					return 34;
				else if (strCatalogCode == "01007")
					return 35;
				else if (strCatalogCode == "01008")
					return 36;
				else if (strCatalogCode == "01009")
					return 37;

				else if (strCatalogCode == "02001")
					return 38;
				else if (strCatalogCode == "02002")
					return 39;
				else if (strCatalogCode == "02003")
					return 40;
				else if (strCatalogCode == "02004")
					return 41;
				else if (strCatalogCode == "02005")
					return 42;
				else if (strCatalogCode == "02006")
					return 43;
				else if (strCatalogCode == "02007")
					return 44;
				else if (strCatalogCode == "02008")
					return 45;
				else if (strCatalogCode == "02009")
					return 46;

				else if (strCatalogCode == "03001")
					return 47;
				else if (strCatalogCode == "03002")
					return 48;
				else if (strCatalogCode == "03003")
					return 49;
				else if (strCatalogCode == "03004")
					return 50;
				else if (strCatalogCode == "03005")
					return 51;
				else if (strCatalogCode == "03006")
					return 52;
				else if (strCatalogCode == "03007")
					return 53;
				else if (strCatalogCode == "03008")
					return 54;
				else if (strCatalogCode == "03009")
					return 55;

				else if (strCatalogCode == "04001")
					return 56;
				else if (strCatalogCode == "04002")
					return 57;
				else if (strCatalogCode == "04003")
					return 58;
				else if (strCatalogCode == "04004")
					return 59;
				else if (strCatalogCode == "04005")
					return 60;
				else if (strCatalogCode == "04006")
					return 61;
				else if (strCatalogCode == "04007")
					return 62;
				else if (strCatalogCode == "04008")
					return 63;
				else if (strCatalogCode == "04009")
					return 64;

				else if (strCatalogCode == "05001")
					return 65;
				else if (strCatalogCode == "05002")
					return 66;
				else if (strCatalogCode == "05003")
					return 67;
				else if (strCatalogCode == "05004")
					return 68;
				else if (strCatalogCode == "05005")
					return 69;
				else if (strCatalogCode == "05006")
					return 70;
				else if (strCatalogCode == "05007")
					return 71;
				else if (strCatalogCode == "05008")
					return 72;
				else if (strCatalogCode == "05009")
					return 73;

				else if (strCatalogCode == "06001")
					return 74;
				else if (strCatalogCode == "06002")
					return 75;
				else if (strCatalogCode == "06003")
					return 76;
				else if (strCatalogCode == "06004")
					return 77;
				else if (strCatalogCode == "06005")
					return 78;
				else if (strCatalogCode == "06006")
					return 79;
				else if (strCatalogCode == "06007")
					return 80;

				else if (strCatalogCode == "07001")
					return 81;
				else if (strCatalogCode == "07002")
					return 82;
				else if (strCatalogCode == "07003")
					return 83;
				else if (strCatalogCode == "07004")
					return 84;
				else if (strCatalogCode == "07005")
					return 85;
				else if (strCatalogCode == "07006")
					return 86;
				else if (strCatalogCode == "07007")
					return 87;

				else if (strCatalogCode == "08001")
					return 88;
				else if (strCatalogCode == "08002")
					return 89;
				else if (strCatalogCode == "08003")
					return 90;
				else if (strCatalogCode == "08004")
					return 91;
				else if (strCatalogCode == "08005")
					return 92;
				else if (strCatalogCode == "08006")
					return 93;
				else if (strCatalogCode == "08007")
					return 94;
				else if (strCatalogCode == "08008")
					return 95;
				else if (strCatalogCode == "08009")
					return 96;

				else if (strCatalogCode == "09001")
					return 97;
				else if (strCatalogCode == "09002")
					return 98;
				else if (strCatalogCode == "09003")
					return 99;
				else if (strCatalogCode == "09004")
					return 100;
				else if (strCatalogCode == "09005")
					return 101;
				else if (strCatalogCode == "09006")
					return 102;
				else if (strCatalogCode == "09007")
					return 103;
				else if (strCatalogCode == "09008")
					return 104;
				else if (strCatalogCode == "09009")
					return 105;


				else
					return 0;
			}
		}


		private bool fnAutoUploadNewsToSqlServer(string strNcxPath,
												 string strCatalogCode,		//For single Catalog code only, need to convert before use
												 string strBookTitle,
												 string strBookDetail)
		{
			int intAuthorId = int.Parse(strCatalogCode.Substring(0, 2)) + 1;		//For single Catalog code ONLY!
			int intPublisherId = int.Parse(strCatalogCode.Substring(0, 2)) + 1;		//For single Catalog code ONLY!
			int intCatalogId = fnConverCatalogCode(strCatalogCode, false);
			int intAllNewsCatalogId = fnConverCatalogCode(strCatalogCode, true);

			//ระบุ Directory ต้นทาง 
			string strSourceDirectory = strNcxPath.Substring(0, strNcxPath.Length - 8); //ลบ \dtb.ncx

			//ADD a record in to Master_BookItem as NEW1
			try
			{
				SqlConnection con = new SqlConnection("Data Source=192.168.100.6;Initial Catalog=Telephony2;Persist Security Info=True;User ID=sa;Password=Mcse2000");
				con.Open();
				SqlCommand com = new SqlCommand();
				com.Connection = con;
				com.CommandType = CommandType.StoredProcedure;
				com.CommandText = "ServerAutomaticConverter_AddNews1Item";
				com.Parameters.Add(new SqlParameter("@BookTitle", strBookTitle));
				com.Parameters.Add(new SqlParameter("@BookDetail", strBookDetail));
				//com.Parameters.Add(new SqlParameter("@Enabled", true));
				//com.Parameters.Add(new SqlParameter("@CreditPerMinute", 99999));
				//com.Parameters.Add(new SqlParameter("@NarratorId1", 2));
				//com.Parameters.Add(new SqlParameter("@NarratorId2", 2));
				com.Parameters.Add(new SqlParameter("@AuthorId1", intAuthorId));
				//com.Parameters.Add(new SqlParameter("@AuthorId2", 0));
				//com.Parameters.Add(new SqlParameter("@TranslatorId1", 1));
				//com.Parameters.Add(new SqlParameter("@TranslatorId2", 1));
				com.Parameters.Add(new SqlParameter("@PublisherId1", intPublisherId));
				//com.Parameters.Add(new SqlParameter("@PublisherId2", 0));
				com.Parameters.Add(new SqlParameter("@SourceFolderName", strSourceDirectory));
				com.Parameters.Add(new SqlParameter("@NewsCatalogId", intCatalogId));
				com.Parameters.Add(new SqlParameter("@AllNewsCatalogId", intAllNewsCatalogId));

				//SqlParameter returnValue = new SqlParameter("@Return_Value", DbType.Int32);
				//returnValue.Direction = ParameterDirection.ReturnValue;
				//com.Parameters.Add(returnValue);
				com.ExecuteNonQuery();
				com.Dispose();
				con.Close();
			}
			catch (Exception)
			{
				return false;
			}
			
			return true;
		}

			
		private SpeechLib.SpVoice V = new SpeechLib.SpVoice();
		private OleDbConnection myConn;
		private OleDbDataReader myReader;
		private OleDbCommand myCmd;
		private bool fnAutoUploadNews(string strNcxPath, string strDestinationOfAutoNewsPath, string strCatalogCode, string strBookTitle, string strBookDetail)
		{
			int intBookId = 1;
			try
			{
				myConn = new OleDbConnection(@"Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" + strDestinationOfAutoNewsPath + @"Books.mdb");
				myConn.Open();
				//Looking for the last(less) book ID
				OleDbCommand myCmd = new OleDbCommand(@"Select BookID from TbBookInfo where CategoryCode like '" + strCatalogCode.Trim() + @"' order by BookID asc", myConn);
				myReader = myCmd.ExecuteReader();
				if (myReader.HasRows == true)
				{
					while (myReader.Read())
					{
						if (intBookId == int.Parse(myReader[0].ToString()))
						{
							intBookId++;
						}
						else
						{
							break;
						}
					}
				}
				else
				{
					//return false;
					intBookId = 1;
				}

				myConn.Close();
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message, "Error in fnAutoUploadNews");
				myConn.Close();
				return false;

			}

			string strBookId = intBookId.ToString("0000").Trim();
			string strBookNameFilePath = strDestinationOfAutoNewsPath + @"bookPrompts\" + strCatalogCode + strBookId + @"p.wav";
			string strBookDetailFilePath = strDestinationOfAutoNewsPath + @"bookPrompts\" + strCatalogCode + strBookId + @"d.wav";

			try
			{	//Ensure that the target does not exist.
				if (File.Exists(strBookNameFilePath) == true)
					File.Delete(strBookNameFilePath);
			}
			catch (Exception)
			{ }

			try
			{	//Ensure that the target does not exist.
				if (File.Exists(strBookDetailFilePath) == true)
					File.Delete(strBookDetailFilePath);
			}
			catch (Exception)
			{ }

			try
			{
				V.Voice = V.GetVoices().Item(intPPATatipNumber);

				//Set output stream to speaker
				V.AllowAudioOutputFormatChangesOnNextSet = true;
				V.AudioOutputStream = null;
				//AUTO-GENERATE
				//Change TTS for book name

				//create a wave stream
				SpFileStream cpFileStream = new SpFileStream();
				cpFileStream.Format.Type = SpeechAudioFormatType.SAFT11kHz8BitMono;

				//Generate Book Name  
				cpFileStream.Open(strBookNameFilePath, SpeechStreamFileMode.SSFMCreateForWrite, false);
				//Set output stream to the file stream
				V.AllowAudioOutputFormatChangesOnNextSet = false;
				V.AudioOutputStream = cpFileStream;
				//speak the given text with given flags
				V.Speak(strBookTitle, SpeechVoiceSpeakFlags.SVSFDefault);
				//wait until it's done speaking with a really really long timeout.
				//the tiemout value is in unit of millisecond. -1 means forever.
				V.WaitUntilDone(-1);
				//close the file stream
				cpFileStream.Close();

				//Generate Book Detail
				cpFileStream.Open(strBookDetailFilePath, SpeechStreamFileMode.SSFMCreateForWrite, false);
				//Set output stream to the file stream
				V.AllowAudioOutputFormatChangesOnNextSet = false;
				V.AudioOutputStream = cpFileStream;
				//speak the given text with given flags
				V.Speak(strBookDetail, SpeechVoiceSpeakFlags.SVSFDefault);
				//wait until it's done speaking with a really really long timeout.
				//the tiemout value is in unit of millisecond. -1 means forever.
				V.WaitUntilDone(-1);
				//close the file stream
				cpFileStream.Close();
				cpFileStream = null;
			}
			catch (Exception)
			{
				MessageBox.Show(@"There is an error while converting The book Title and detail to WAV files.", @"fnAutoUploadNews");
				return false;
			}


			///////////////////////////////////////////////////////
			//update database (delete old & add new) for bookName//
			///////////////////////////////////////////////////////
			try
			{
				myConn = new OleDbConnection(@"Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" + strDestinationOfAutoNewsPath + @"Books.mdb");
				myConn.Open();

				myCmd = new OleDbCommand(@"delete from TbBookInfo where CategoryCode like '" + strCatalogCode + @"' and BookID like '" + strBookId + @"'", myConn);
				myCmd.ExecuteNonQuery();

				string tmpList = @"insert into TbBookInfo(9DigitBookCode,BookID,BookName,CategoryCode,BookDetail,SortOrder) values('" + strCatalogCode + strBookId + @"','" + strBookId + @"','" + strBookTitle.Trim() + @"','" + strCatalogCode + @"','" + strBookDetail.Trim() + @"','" + strBookId.Trim() + @"')";
				myCmd = new OleDbCommand(tmpList, myConn);
				myCmd.ExecuteNonQuery();

				myConn.Close();
			}
			catch (Exception ex)
			{
				myConn.Close();
				MessageBox.Show(@"There is an error while inserting DTBs record to the book.mdb. " + ex.Message, @"Error in fnAutoUploadNews");
				return false;
			}


			//ระบุ Directory ต้นทาง และ ปลายทาง
			string strSourceDirectory = strNcxPath.Substring(0, strNcxPath.Length - 7);

			string strDestinationDirectory = strDestinationOfAutoNewsPath + @"Library\" + strCatalogCode + @"\" + strBookId + @"\";

			if (strSourceDirectory != "")
			{
				try
				{
					//Deltree สำหรับ Directory ปลายทาง
					Directory.Delete(strDestinationDirectory, true);
				}
				catch (Exception)
				{ }

				try
				{
					//สร้าง Directory ปลายทาง
					Directory.CreateDirectory(strDestinationDirectory);
					//คัดลอกไปยัง Directory ปลายทาง
					string[] f = Directory.GetFiles(strSourceDirectory);
					foreach (string s in f)
					{
						File.Copy(s, strDestinationDirectory + fnGetFileNameWithoutThePath(s));
					}
					//DONE
				}
				catch (Exception)
				{
					MessageBox.Show(@"There is an error while copying NEWS to the destination.", @"fnAutoUploadNews");
					return false;
				}
			}
			return true;
		}

		//Get names of all unmoved books from the BookItem table
		//Move Books from Repository to Library
		//Update BookTable by clearing the SourceFolderName field
		private void fnMoveNewBookToLibrary()
		{
			//Please note that: UnconvertedName in this function will use only 2 properties including
			//                  strName1     = BookId
			//                  strFileName1 = SourceFolderName

			List<UnconvertedName> lstNewBookInfo = SqlFuncGetNewBookInfo();
			string strFormattedBookId = "";
			string strUploadedFolderPath = "";

			try 
			{
				foreach (UnconvertedName NewBookInfo in lstNewBookInfo)
				{
					strFormattedBookId = "";
					strFormattedBookId = NewBookInfo.strName1;
					strFormattedBookId = strFormattedBookId.Substring(0, 4) + @"\" + strFormattedBookId.Substring(4, 3) + @"\" + strFormattedBookId.Substring(7, 3) + @"\";

					//CHECK WHETHER ITEM IS NEWS OR BOOK
					if (NewBookInfo.strFileName1.Contains(@"\DAILYNEWS\") == true)
						strFormattedBookId = @"W:\LIBRARY_NEWS1\LIBRARY\" + strFormattedBookId;
					else
						strFormattedBookId = @"W:\LIBRARY_BOOKS\LIBRARY\" + strFormattedBookId;

                    //Check Existing of the source
                    if (Directory.Exists(NewBookInfo.strFileName1 + @"\") == false)
                        continue;

					//COPY DTB FILES
					if (fnCopyDirectory(NewBookInfo.strFileName1 + @"\", strFormattedBookId, true) == true)
					{
						//Clean the SourceFolderName field in the Master_BookItem table (with success)
						SqlFuncFinishMovingNewBookToLibrary(int.Parse(NewBookInfo.strName1), true);

						//Move the "OUTPUT" Source folder to the "UPLOADED" folde
						strUploadedFolderPath = NewBookInfo.strFileName1.Replace("OUTPUT", "UPLOADED") + @"\";

						if (Directory.Exists(strUploadedFolderPath) == true)
							Directory.Delete(strUploadedFolderPath, true); //clear completed fail folder

						//Check Existing again before moving
						if (Directory.Exists(NewBookInfo.strFileName1 + @"\") == true) 
							Directory.Move(NewBookInfo.strFileName1 + @"\", strUploadedFolderPath);

						//Delete, if the item is NEWS
						//if (NewBookInfo.strFileName1.Contains(@"\DAILYNEWS\") == true)
						//		Directory.Delete(strUploadedFolderPath, true);
					}
					else
					{
						//Clean the SourceFolderName field in the Master_BookItem table (with failure)
						SqlFuncFinishMovingNewBookToLibrary(int.Parse(NewBookInfo.strName1), false);
					}
				}
			}
			catch (Exception)
			{
				MessageBox.Show(@"There is an error while copying an unmoved book to the destination library.", @"fnMoveNewBookToLibrary");
				return;
			}
		}


		private List<UnconvertedName> SqlFuncGetNewBookInfo()
		{
			//Please note that: UnconvertedName in this function will use only 2 properties including
			//                  strName1     = BookId
			//                  strFileName1 = SourceFolderName

			List<UnconvertedName> lstReturnNewBookInfo = new List<UnconvertedName>();

			try
			{
				SqlConnection con = new SqlConnection("Data Source=192.168.100.6;Initial Catalog=Telephony2;User ID=sa;Password=Mcse2000");
				con.Open();
				SqlCommand com = new SqlCommand();
				SqlDataReader reader;
				com.Connection = con;
				com.CommandType = CommandType.StoredProcedure;

				com.CommandText = "ServerAutomaticConverter_GetNewBookInfo";
				reader = com.ExecuteReader();
				if (reader.HasRows)
					while (reader.Read())
						lstReturnNewBookInfo.Add(new UnconvertedName(reader["BookId"].ToString(),"",reader["SourceFolderName"].ToString(),""));
				reader.Close();
		
				com.Dispose();
				con.Close();
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
				lstReturnNewBookInfo.Clear();
			}

			return lstReturnNewBookInfo;
		
		}


		//Start Here by passing strSharePromptDirectory to this function
		private void fnConvertAllAudioFiles(string strPathToSave) // e.g. strPathToSave = @"C:\JUKEBOX\"  (strSharePromptDirectory)
		{
			//get list of all unconverted audio files
			List<UnconvertedName> lstUnconvertedName = SqlFuncGetUnconvertedAudio();
			int intMaxRepeat = 10; //repeat for 5 times (if not success converting)
			int intRepeatCounter = 0;
			bool boolResult = true;

			foreach (UnconvertedName ucName in lstUnconvertedName)
			{
				boolResult = true;

				//convert name to audio file
				for (intRepeatCounter = 0; intRepeatCounter < intMaxRepeat; intRepeatCounter++)
				{
					if (fnSpeakToWav(ucName.strName1, strPathToSave + ucName.strFileName1) == true)
					{
						boolResult = true;
						break;
					}
					else
					{
						boolResult = false;
					}
				}

				if ((ucName.strName2 != "") && (boolResult == true))
				{
					for (intRepeatCounter = 0; intRepeatCounter < intMaxRepeat; intRepeatCounter++)
					{
						if (fnSpeakToWav(ucName.strName2, strPathToSave + ucName.strFileName2) == true)
						{
							boolResult = true;
							break;
						}
						else
						{
							boolResult = false;
						}
					}
				}

				//Finish each audio
				if (boolResult == true)
					SqlFuncFinishUnconvertedAudio(ucName.strFileName1, ucName.strFileName2);
			}
		}

		private bool fnSpeakToWav(string strWordToSpeak, string strPathToSave)
		{
			string aaa = strPathToSave.Substring(0, strPathToSave.LastIndexOf(@"\") + 1);

			try
			{
				//Ensure that the target'directory is exis
				if (Directory.Exists(strPathToSave.Substring(0, strPathToSave.LastIndexOf(@"\") + 1)) == false)
					Directory.CreateDirectory(strPathToSave.Substring(0, strPathToSave.LastIndexOf(@"\") + 1));
			}
			catch (Exception)
			{ }

			try
			{	//Ensure that the target does not exist.
				if (File.Exists(strPathToSave) == true)
					File.Delete(strPathToSave);
			}
			catch (Exception)
			{ }

			//speak
			try
			{
				V.Voice = V.GetVoices().Item(intPPATatipNumber);

				//Set output stream to speaker
				V.AllowAudioOutputFormatChangesOnNextSet = true;
				//V.AudioOutputStream = null;  //migrate to vmware (no audio device)
				//AUTO-GENERATE
				//Change TTS for book name

				//create a wave stream
				SpFileStream cpFileStream = new SpFileStream();
				cpFileStream.Format.Type = SpeechAudioFormatType.SAFT11kHz8BitMono;

				//Generate Book Name  
				cpFileStream.Open(strPathToSave, SpeechStreamFileMode.SSFMCreateForWrite, false);
				//Set output stream to the file stream
				V.AllowAudioOutputFormatChangesOnNextSet = false;
				V.AudioOutputStream = cpFileStream;
				//speak the given text with given flags
				V.Speak(strWordToSpeak, SpeechVoiceSpeakFlags.SVSFDefault);
				//wait until it's done speaking with a really really long timeout.
				//the tiemout value is in unit of millisecond. -1 means forever.
				V.WaitUntilDone(-1);
				//close the file stream
				cpFileStream.Close();
			}
			catch (Exception ex)
			{
				MessageBox.Show(@"There is an error while converting The book Title and detail to WAV files. " + ex.Message, @"fnSpeakToWav");
				return false;
			}

			//Check Size
			System.IO.FileInfo currentfileInfo = new System.IO.FileInfo(strPathToSave);

			if (currentfileInfo.Length > 0)
				return true;
			else
				return false;
		}

		private void SqlFuncFinishMovingNewBookToLibrary(int intBookId, bool isSuccess)
		{
			//This function will be used after successful moving book from repository to the library

			try
			{
				SqlConnection con = new SqlConnection("Data Source=192.168.100.6;Initial Catalog=Telephony2;User ID=sa;Password=Mcse2000");
				con.Open();
				SqlCommand com = new SqlCommand();
				com.Connection = con;
				com.CommandType = CommandType.StoredProcedure;

				com.CommandText = "ServerAutomaticConverter_FinishMovingNewBookToLibrary";
				com.Parameters.Add(new SqlParameter("@BookId", intBookId));
				
				if (isSuccess == true)
					com.Parameters.Add(new SqlParameter("@Result", "DONE"));	//Result = "DONE" for success
				else
					com.Parameters.Add(new SqlParameter("@Result", "ERROR"));	//Result = "ERROR" for error

				com.ExecuteNonQuery();
				com.Dispose();
				con.Close();
			}
			catch (Exception)
			{
				//MessageBox.Show(ex.Message);  //FOR DEBUG ONLY
			}
		}

		private void SqlFuncFinishUnconvertedAudio(string strAudioFilename1, string strAudioFilename2)
		{
			//STORED PROCEDURE WILL AUTOMATICALLY CHECK THAT WHAT IS THE TYPE OF AUDIO FILE

			try
			{
				SqlConnection con = new SqlConnection("Data Source=192.168.100.6;Initial Catalog=Telephony2;User ID=sa;Password=Mcse2000");
				con.Open();
				SqlCommand com = new SqlCommand();
				com.Connection = con;
				com.CommandType = CommandType.StoredProcedure;

				com.CommandText = "[ServerAutomaticConverter_FinishUnconverted_Audio_All]";
				com.Parameters.Add(new SqlParameter("@AudioFileName1", strAudioFilename1));
				com.Parameters.Add(new SqlParameter("@AudioFileName2", strAudioFilename2));

				com.ExecuteNonQuery();
				com.Dispose();
				con.Close();
			}
			catch (Exception)
			{
				//MessageBox.Show(ex.Message);  //FOR DEBUG ONLY
			}
		}


		private List<UnconvertedName> SqlFuncGetUnconvertedAudio()
		{
			List<UnconvertedName> lstReturnUnconvertedName = new List<UnconvertedName>();

			try
			{
				SqlConnection con = new SqlConnection("Data Source=192.168.100.6;Initial Catalog=Telephony2;User ID=sa;Password=Mcse2000");
				con.Open();
				SqlCommand com = new SqlCommand();
				SqlDataReader reader;
				com.Connection = con;
				com.CommandType = CommandType.StoredProcedure;
				string strFirstName = "";
				string strSecondName = "";

				/////////////////////////////// AUTHOR //////////////////////////////////
				com.CommandText = "ServerAutomaticConverter_GetUnconverted_Audio_Author";
				reader = com.ExecuteReader();
				if (reader.HasRows)
					while (reader.Read())
						lstReturnUnconvertedName.Add(new UnconvertedName(reader["Name"].ToString(), "", reader["Filename"].ToString(), ""));
				reader.Close();

				////////////////////////////// NARRATOR /////////////////////////////////
				com.CommandText = "ServerAutomaticConverter_GetUnconverted_Audio_Narrator";
				reader = com.ExecuteReader();
				if (reader.HasRows)
					while (reader.Read())
						lstReturnUnconvertedName.Add(new UnconvertedName(reader["Name"].ToString(), "", reader["Filename"].ToString(), ""));
				reader.Close();

				////////////////////////////// PUBLISHER /////////////////////////////////
				com.CommandText = "ServerAutomaticConverter_GetUnconverted_Audio_Publisher";
				reader = com.ExecuteReader();
				if (reader.HasRows)
					while (reader.Read())
						lstReturnUnconvertedName.Add(new UnconvertedName(reader["Name"].ToString(), "", reader["Filename"].ToString(), ""));
				reader.Close();

				////////////////////////////// TRANSLATOR /////////////////////////////////
				com.CommandText = "ServerAutomaticConverter_GetUnconverted_Audio_Translator";
				reader = com.ExecuteReader();
				if (reader.HasRows)
					while (reader.Read())
						lstReturnUnconvertedName.Add(new UnconvertedName(reader["Name"].ToString(), "", reader["Filename"].ToString(), ""));
				reader.Close();

				//////////////////////////// BOOK CATALOG ///////////////////////////////
				com.CommandText = "ServerAutomaticConverter_GetUnconverted_Audio_BookCatalog";
				com.ExecuteNonQuery();
				reader = com.ExecuteReader();
				if (reader.HasRows)
					while (reader.Read())
					{
						strFirstName = reader["CatalogName1"].ToString();
						strSecondName = reader["CatalogName2"].ToString();

						if (strSecondName.Trim() == "")
							strSecondName = strFirstName;

						lstReturnUnconvertedName.Add(new UnconvertedName(strFirstName, strSecondName, reader["CatalogFilename1"].ToString(), reader["CatalogFilename2"].ToString()));
					}
				reader.Close();

				//////////////////////////// BOOK ITEM ////////////////////////////////
				com.CommandText = "ServerAutomaticConverter_GetUnconverted_Audio_BookItem";
				com.ExecuteNonQuery();
				reader = com.ExecuteReader();
				if (reader.HasRows)
					while (reader.Read())
						lstReturnUnconvertedName.Add(new UnconvertedName(reader["TitleName"].ToString(), reader["DetailName"].ToString(), reader["TitleFilename"].ToString(), reader["DetailFilename"].ToString()));
				reader.Close();


				//////////////////////////// NEWS1 ITEM ////////////////////////////////
				com.CommandText = "ServerAutomaticConverter_GetUnconverted_Audio_News1Item";
				com.ExecuteNonQuery();
				reader = com.ExecuteReader();
				if (reader.HasRows)
					while (reader.Read())
						lstReturnUnconvertedName.Add(new UnconvertedName(reader["TitleName"].ToString(), reader["DetailName"].ToString(), reader["TitleFilename"].ToString(), reader["DetailFilename"].ToString()));
				reader.Close();

				com.Dispose();
				con.Close();
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
				lstReturnUnconvertedName.Clear();
			}

			return lstReturnUnconvertedName;
		}


		private static bool fnCopyDirectory(string SourcePath, string DestinationPath, bool overwriteexisting)
		{
			bool ret = false;
			try
			{
				SourcePath = SourcePath.EndsWith(@"\") ? SourcePath : SourcePath + @"\";
				DestinationPath = DestinationPath.EndsWith(@"\") ? DestinationPath : DestinationPath + @"\";

				if (Directory.Exists(SourcePath))
				{
					if (Directory.Exists(DestinationPath) == false)
						Directory.CreateDirectory(DestinationPath);

					foreach (string fls in Directory.GetFiles(SourcePath))
					{
						FileInfo flinfo = new FileInfo(fls);
						flinfo.CopyTo(DestinationPath + flinfo.Name, overwriteexisting);
					}
					foreach (string drs in Directory.GetDirectories(SourcePath))
					{
						DirectoryInfo drinfo = new DirectoryInfo(drs);
						if (fnCopyDirectory(drs, DestinationPath + drinfo.Name, overwriteexisting) == false)
							ret = false;
					}
				}
				ret = true;
			}
			catch (Exception ex)
			{
				MessageBox.Show(ex.Message);
				ret = false;
			}
			return ret;
		}

		private void button2_Click(object sender, EventArgs e)
		{
			fnSpeakToWav("ชื่อผู้แต่งชั่วคราว", @"c:\waiting_author_name.wav");
			fnSpeakToWav("ชื่อผู้แปลชั่วคราว", @"c:\waiting_translator_name.wav");
			fnSpeakToWav("ชื่อสำนักพิมพ์ชั่วคราว", @"c:\waiting_publisher_name.wav");
			fnSpeakToWav("ชื่อผู้อ่านชั่วคราว", @"c:\waiting_narrator_name.wav");
			fnSpeakToWav("ชื่อหมวดหมู่ชั่วคราว", @"c:\waiting_catalog_name.wav");
			fnSpeakToWav("ชื่อหนังสือชั่วคราว", @"c:\waiting_book_title_name.wav");
			fnSpeakToWav("ชื่อบทคัดย่อหนังสือชั่วคราว", @"c:\waiting_book_detail_name.wav");
		}
	}

	/// <summary>
	/// User-Defined Data Classes
	/// </summary>
	public class NewsItem
	{
		public string strTitle = "";
		public string strDetail = "";

		public NewsItem(string _strTitle, string _strDetail)
		{
			strTitle = _strTitle;
			strDetail = _strDetail;
		}
	}

    public class BackgroundConverter
    {
        //Public Declare Function CreateConverterDll Lib "Converter.dll" () As Long
        //Public Declare Sub DestroyConverterDll Lib "Converter.dll" (ByVal objptr As Long)
        //Public Declare Function GetCpuSpeedConverterDll Lib "Converter.dll" (ByVal objptr As Long) As 
        //Public Declare Function StartConverterDll Lib "Converter.dll" (ByVal strNcPath As String, ByVal strDestFolder As String, ByVal bolMakeSyntheticSound As Boolean, ByVal intOrderText2Speech As Integer, ByVal chrOutputAudioFormat As String, ByVal objptr As Long) As Integer

        [DllImport("Converter.dll")]
        public static extern IntPtr CreateConverterDll();

        [DllImport("Converter.dll")]
        public static extern void DestroyConverterDll(IntPtr objptr);

        [DllImport("Converter.dll")]
        public static extern int GetCpuSpeedConverterDll(IntPtr objptr);

        [DllImport("Converter.dll")]
        public static extern int StartConverterDll(string strNcPath, string strDestFolder, bool bolMakeSyntheticSound, int intOrderText2Speech, string chrOutputAudioFormat, IntPtr objptr);


        public string myStrNcPath = "";
        public string myStrDestFolder = "";
        public bool myBolMakeSyntheticSound = false;
        public int myintOrderText2Speech = 0;
        public string myChrOutputAudioFormat = "";
        public int intReturnValue = 0;
        public int intCpuSpeed = 0;
		private IntPtr intPtrConvertBook = IntPtr.Zero;

		public void fnConvertBook()
		{
			intPtrConvertBook = IntPtr.Zero;
			try
			{
				//Clear value
				intReturnValue = -9999;
				//Create DLL Object
				intPtrConvertBook = CreateConverterDll();
			}
			catch (Exception)
			{
				//MessageBox.Show("Call DLL Error! :: " + ex.Message);
			}


			try
			{
				intReturnValue = StartConverterDll(myStrNcPath, myStrDestFolder, myBolMakeSyntheticSound, myintOrderText2Speech, myChrOutputAudioFormat, intPtrConvertBook);
			    //Destroy DLL Object
				DestroyConverterDll(intPtrConvertBook);
			}
			catch (Exception)
			{
			    //MessageBox.Show("Error in DLL! :: " + ex.Message);
			}		
		}



		public bool fnDestroyConverter()  //return true if success, false in case of failure
		{
			if (intPtrConvertBook != IntPtr.Zero)
			{
				try
				{
					//Destroy DLL Object
					DestroyConverterDll(intPtrConvertBook);
					return true;
				}
				catch (Exception)
				{
					return false;
				}
			}
			else
			{
				return true;
			}
		}


        public void fnGetCpuSpeed()
        { 
            IntPtr objptr;
            try
            {
                //Create DLL Object
                objptr = CreateConverterDll();
                //Check CPU speed.
                intCpuSpeed = GetCpuSpeedConverterDll(objptr);
                //Destroy DLL Object
                DestroyConverterDll(objptr);
            }
            catch (Exception ex)
            { 
                MessageBox.Show("Application cannot get CPU speed! because " + ex.Message);
            }
        }


    }


	public class UnconvertedName
	{
		public string strName1 = "";
		public string strName2 = "";
		public string strFileName1 = "";
		public string strFileName2 = "";

		public UnconvertedName(string _strName1, string _strName2, string _strFileName1, string _strFileName2)
		{
			strName1 = _strName1;
			strName2 = _strName2;
			strFileName1 = _strFileName1;
			strFileName2 = _strFileName2;
		}
	}
}
