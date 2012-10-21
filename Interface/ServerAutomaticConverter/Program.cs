using System;
using System.Collections.Generic;
using System.Windows.Forms;

using System.Diagnostics;
using System.Threading;



namespace ServerAutomaticConverter
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
			if (DestroyPreviousInstanceWindowHandle() == IntPtr.Zero)
			{
				Application.EnableVisualStyles();
				Application.SetCompatibleTextRenderingDefault(false);
				Application.Run(new frmAutoConverter());
			}
			else
			{
				MessageBox.Show("There is an error during the opening process. Please Tye again!");
				return;
			}
        }



		private static IntPtr DestroyPreviousInstanceWindowHandle()
		{
			IntPtr hWnd = IntPtr.Zero;
			Process process = Process.GetCurrentProcess();
			Process[] processes = Process.GetProcessesByName(process.ProcessName);
			foreach (Process _process in processes)
			{
				// Get the first instance that is not this instance, has the
				// same process name and was started from the same file name
				// and location. Also check that the process has a valid
				// window handle in this session to filter out other user's
				// processes.
				if (_process.Id != process.Id &&
				    _process.MainModule.FileName == process.MainModule.FileName)// &&
				    //_process.MainWindowHandle != IntPtr.Zero)
				{
					//hWnd = _process.MainWindowHandle;
					//MessageBox.Show("There is a running instance of this process.");
					_process.Kill();
					Thread.Sleep(2000);
					hWnd = IntPtr.Zero;
					//continue;
				}
			}
			return hWnd;
		}
    }
}
