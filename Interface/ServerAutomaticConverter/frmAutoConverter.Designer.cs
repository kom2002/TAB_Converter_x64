namespace ServerAutomaticConverter
{
    partial class frmAutoConverter
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.button1 = new System.Windows.Forms.Button();
            this.dgvDtbList = new System.Windows.Forms.DataGridView();
            this.strNcFilePath = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.strStatus = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.strDTBVersion = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.strOutputPath = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.strAudioFormat = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.strSpeechEngine = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.btnCheckNow = new System.Windows.Forms.Button();
            this.btnChooseFolder = new System.Windows.Forms.Button();
            this.txtDtbShare = new System.Windows.Forms.TextBox();
            this.button4 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.pgbCurrentDtbCompleted = new System.Windows.Forms.ProgressBar();
            this.pgbAllDtbCompleted = new System.Windows.Forms.ProgressBar();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.Panel1 = new System.Windows.Forms.Panel();
            this.lblFileTime = new System.Windows.Forms.Label();
            this.lblDtbTime = new System.Windows.Forms.Label();
            this.lblFileStatus = new System.Windows.Forms.Label();
            this.lblDtbStatus = new System.Windows.Forms.Label();
            this.Label07 = new System.Windows.Forms.Label();
            this.Label10 = new System.Windows.Forms.Label();
            this.Label09 = new System.Windows.Forms.Label();
            this.Label06 = new System.Windows.Forms.Label();
            this.lblDtbName = new System.Windows.Forms.Label();
            this.lblFileName = new System.Windows.Forms.Label();
            this.Label05 = new System.Windows.Forms.Label();
            this.Label08 = new System.Windows.Forms.Label();
            this.txtDetail = new System.Windows.Forms.TextBox();
            this.lblLastCheck = new System.Windows.Forms.Label();
            this.lblNextCheck = new System.Windows.Forms.Label();
            this.fileSystemWatcher1 = new System.IO.FileSystemWatcher();
            this.folderBrowserDialog1 = new System.Windows.Forms.FolderBrowserDialog();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.btnMoveRowUp = new System.Windows.Forms.Button();
            this.lblDiskSpace = new System.Windows.Forms.Label();
            this.lblCpuSpeed = new System.Windows.Forms.Label();
            this.tmrDelayStart = new System.Windows.Forms.Timer(this.components);
            this.lblSecondToStart = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.btnMoveRowDown = new System.Windows.Forms.Button();
            this.btnMoveRowBottom = new System.Windows.Forms.Button();
            this.btnMoveRowTop = new System.Windows.Forms.Button();
            this.btnStart = new System.Windows.Forms.Button();
            this.tmrConverting = new System.Windows.Forms.Timer(this.components);
            this.lblCurrDtbCompleted = new System.Windows.Forms.Label();
            this.lblAllDtbCompleted = new System.Windows.Forms.Label();
            this.lblHeartbeat = new System.Windows.Forms.Label();
            this.tmrHeartbeat = new System.Windows.Forms.Timer(this.components);
            this.label6 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dgvDtbList)).BeginInit();
            this.Panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fileSystemWatcher1)).BeginInit();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.button1.Location = new System.Drawing.Point(539, 497);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(116, 23);
            this.button1.TabIndex = 0;
            this.button1.Text = "Restart";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // dgvDtbList
            // 
            this.dgvDtbList.AllowUserToAddRows = false;
            this.dgvDtbList.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dgvDtbList.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.strNcFilePath,
            this.strStatus,
            this.strDTBVersion,
            this.strOutputPath,
            this.strAudioFormat,
            this.strSpeechEngine});
            this.dgvDtbList.Cursor = System.Windows.Forms.Cursors.Default;
            this.dgvDtbList.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.dgvDtbList.Location = new System.Drawing.Point(12, 68);
            this.dgvDtbList.MultiSelect = false;
            this.dgvDtbList.Name = "dgvDtbList";
            this.dgvDtbList.ReadOnly = true;
            this.dgvDtbList.RowHeadersWidthSizeMode = System.Windows.Forms.DataGridViewRowHeadersWidthSizeMode.AutoSizeToAllHeaders;
            this.dgvDtbList.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgvDtbList.Size = new System.Drawing.Size(643, 183);
            this.dgvDtbList.StandardTab = true;
            this.dgvDtbList.TabIndex = 1;
            // 
            // strNcFilePath
            // 
            this.strNcFilePath.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.ColumnHeader;
            this.strNcFilePath.HeaderText = "Navigation Control File Path";
            this.strNcFilePath.Name = "strNcFilePath";
            this.strNcFilePath.ReadOnly = true;
            this.strNcFilePath.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.NotSortable;
            this.strNcFilePath.Width = 144;
            // 
            // strStatus
            // 
            this.strStatus.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.ColumnHeader;
            this.strStatus.HeaderText = "Status";
            this.strStatus.Name = "strStatus";
            this.strStatus.ReadOnly = true;
            this.strStatus.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.NotSortable;
            this.strStatus.Width = 43;
            // 
            // strDTBVersion
            // 
            this.strDTBVersion.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.ColumnHeader;
            this.strDTBVersion.HeaderText = "DTB Version";
            this.strDTBVersion.Name = "strDTBVersion";
            this.strDTBVersion.ReadOnly = true;
            this.strDTBVersion.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.NotSortable;
            this.strDTBVersion.Width = 73;
            // 
            // strOutputPath
            // 
            this.strOutputPath.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.ColumnHeader;
            this.strOutputPath.HeaderText = "Output Path";
            this.strOutputPath.Name = "strOutputPath";
            this.strOutputPath.ReadOnly = true;
            this.strOutputPath.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.NotSortable;
            this.strOutputPath.Width = 70;
            // 
            // strAudioFormat
            // 
            this.strAudioFormat.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.ColumnHeader;
            this.strAudioFormat.HeaderText = "Audio Format";
            this.strAudioFormat.Name = "strAudioFormat";
            this.strAudioFormat.ReadOnly = true;
            this.strAudioFormat.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.NotSortable;
            this.strAudioFormat.Width = 75;
            // 
            // strSpeechEngine
            // 
            this.strSpeechEngine.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.ColumnHeader;
            this.strSpeechEngine.HeaderText = "Speech Engine";
            this.strSpeechEngine.Name = "strSpeechEngine";
            this.strSpeechEngine.ReadOnly = true;
            this.strSpeechEngine.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.NotSortable;
            this.strSpeechEngine.Width = 86;
            // 
            // btnCheckNow
            // 
            this.btnCheckNow.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnCheckNow.Enabled = false;
            this.btnCheckNow.Location = new System.Drawing.Point(661, 40);
            this.btnCheckNow.Name = "btnCheckNow";
            this.btnCheckNow.Size = new System.Drawing.Size(117, 23);
            this.btnCheckNow.TabIndex = 2;
            this.btnCheckNow.Text = "Check Now";
            this.btnCheckNow.UseVisualStyleBackColor = true;
            this.btnCheckNow.Click += new System.EventHandler(this.btnCheckNow_Click);
            // 
            // btnChooseFolder
            // 
            this.btnChooseFolder.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnChooseFolder.Location = new System.Drawing.Point(661, 10);
            this.btnChooseFolder.Name = "btnChooseFolder";
            this.btnChooseFolder.Size = new System.Drawing.Size(117, 23);
            this.btnChooseFolder.TabIndex = 3;
            this.btnChooseFolder.Text = "Choose Folder";
            this.btnChooseFolder.UseVisualStyleBackColor = true;
            this.btnChooseFolder.Click += new System.EventHandler(this.btnChooseFolder_Click);
            // 
            // txtDtbShare
            // 
            this.txtDtbShare.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txtDtbShare.Enabled = false;
            this.txtDtbShare.Location = new System.Drawing.Point(106, 10);
            this.txtDtbShare.Name = "txtDtbShare";
            this.txtDtbShare.Size = new System.Drawing.Size(549, 20);
            this.txtDtbShare.TabIndex = 4;
            this.txtDtbShare.Text = "Y:\\";
            this.txtDtbShare.TextChanged += new System.EventHandler(this.txtDtbShare_TextChanged);
            // 
            // button4
            // 
            this.button4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.button4.Location = new System.Drawing.Point(661, 497);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(117, 23);
            this.button4.TabIndex = 5;
            this.button4.Text = "Exit ออก";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 14);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(88, 13);
            this.label1.TabIndex = 6;
            this.label1.Text = "DTBs FTP Path :";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(277, 44);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(69, 13);
            this.label2.TabIndex = 7;
            this.label2.Text = "Next Check :";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 44);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(67, 13);
            this.label3.TabIndex = 8;
            this.label3.Text = "Last Check :";
            // 
            // pgbCurrentDtbCompleted
            // 
            this.pgbCurrentDtbCompleted.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pgbCurrentDtbCompleted.Location = new System.Drawing.Point(15, 342);
            this.pgbCurrentDtbCompleted.Name = "pgbCurrentDtbCompleted";
            this.pgbCurrentDtbCompleted.Size = new System.Drawing.Size(763, 16);
            this.pgbCurrentDtbCompleted.TabIndex = 9;
            // 
            // pgbAllDtbCompleted
            // 
            this.pgbAllDtbCompleted.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pgbAllDtbCompleted.Location = new System.Drawing.Point(15, 377);
            this.pgbAllDtbCompleted.Name = "pgbAllDtbCompleted";
            this.pgbAllDtbCompleted.Size = new System.Drawing.Size(763, 16);
            this.pgbAllDtbCompleted.TabIndex = 10;
            // 
            // label4
            // 
            this.label4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(12, 326);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(119, 13);
            this.label4.TabIndex = 11;
            this.label4.Text = "Current DTB Complete :";
            // 
            // label5
            // 
            this.label5.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(12, 361);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(316, 13);
            this.label5.TabIndex = 12;
            this.label5.Text = "All DTBs Complete : (Previous Accumulative Converted-Book = 0)";
            // 
            // Panel1
            // 
            this.Panel1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.Panel1.Controls.Add(this.lblFileTime);
            this.Panel1.Controls.Add(this.lblDtbTime);
            this.Panel1.Controls.Add(this.lblFileStatus);
            this.Panel1.Controls.Add(this.lblDtbStatus);
            this.Panel1.Controls.Add(this.Label07);
            this.Panel1.Controls.Add(this.Label10);
            this.Panel1.Controls.Add(this.Label09);
            this.Panel1.Controls.Add(this.Label06);
            this.Panel1.Controls.Add(this.lblDtbName);
            this.Panel1.Controls.Add(this.lblFileName);
            this.Panel1.Controls.Add(this.Label05);
            this.Panel1.Controls.Add(this.Label08);
            this.Panel1.Location = new System.Drawing.Point(12, 263);
            this.Panel1.Name = "Panel1";
            this.Panel1.Size = new System.Drawing.Size(766, 56);
            this.Panel1.TabIndex = 13;
            // 
            // lblFileTime
            // 
            this.lblFileTime.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.lblFileTime.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.lblFileTime.Location = new System.Drawing.Point(680, 32);
            this.lblFileTime.Name = "lblFileTime";
            this.lblFileTime.Size = new System.Drawing.Size(80, 16);
            this.lblFileTime.TabIndex = 11;
            this.lblFileTime.Text = "xxxxx";
            // 
            // lblDtbTime
            // 
            this.lblDtbTime.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.lblDtbTime.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.lblDtbTime.Location = new System.Drawing.Point(680, 8);
            this.lblDtbTime.Name = "lblDtbTime";
            this.lblDtbTime.Size = new System.Drawing.Size(80, 16);
            this.lblDtbTime.TabIndex = 5;
            this.lblDtbTime.Text = "xxxxx";
            // 
            // lblFileStatus
            // 
            this.lblFileStatus.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.lblFileStatus.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.lblFileStatus.Location = new System.Drawing.Point(456, 32);
            this.lblFileStatus.Name = "lblFileStatus";
            this.lblFileStatus.Size = new System.Drawing.Size(136, 16);
            this.lblFileStatus.TabIndex = 9;
            this.lblFileStatus.Text = "xxxxx";
            // 
            // lblDtbStatus
            // 
            this.lblDtbStatus.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.lblDtbStatus.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.lblDtbStatus.Location = new System.Drawing.Point(456, 8);
            this.lblDtbStatus.Name = "lblDtbStatus";
            this.lblDtbStatus.Size = new System.Drawing.Size(136, 16);
            this.lblDtbStatus.TabIndex = 3;
            this.lblDtbStatus.Text = "xxxxx";
            // 
            // Label07
            // 
            this.Label07.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.Label07.ImageAlign = System.Drawing.ContentAlignment.BottomLeft;
            this.Label07.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.Label07.Location = new System.Drawing.Point(592, 8);
            this.Label07.Name = "Label07";
            this.Label07.Size = new System.Drawing.Size(88, 16);
            this.Label07.TabIndex = 4;
            this.Label07.Text = "Total Time:";
            // 
            // Label10
            // 
            this.Label10.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.Label10.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.Label10.Location = new System.Drawing.Point(592, 32);
            this.Label10.Name = "Label10";
            this.Label10.Size = new System.Drawing.Size(88, 16);
            this.Label10.TabIndex = 10;
            this.Label10.Text = "This DTB Time:";
            // 
            // Label09
            // 
            this.Label09.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.Label09.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.Label09.Location = new System.Drawing.Point(402, 32);
            this.Label09.Name = "Label09";
            this.Label09.Size = new System.Drawing.Size(56, 16);
            this.Label09.TabIndex = 8;
            this.Label09.Text = "  Status:";
            // 
            // Label06
            // 
            this.Label06.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.Label06.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.Label06.Location = new System.Drawing.Point(402, 8);
            this.Label06.Name = "Label06";
            this.Label06.Size = new System.Drawing.Size(56, 16);
            this.Label06.TabIndex = 2;
            this.Label06.Text = "  Status:";
            // 
            // lblDtbName
            // 
            this.lblDtbName.BackColor = System.Drawing.SystemColors.Control;
            this.lblDtbName.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.lblDtbName.Location = new System.Drawing.Point(115, 8);
            this.lblDtbName.Name = "lblDtbName";
            this.lblDtbName.Size = new System.Drawing.Size(288, 16);
            this.lblDtbName.TabIndex = 1;
            this.lblDtbName.Text = "xxxxx";
            // 
            // lblFileName
            // 
            this.lblFileName.BackColor = System.Drawing.SystemColors.Control;
            this.lblFileName.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.lblFileName.Location = new System.Drawing.Point(115, 32);
            this.lblFileName.Name = "lblFileName";
            this.lblFileName.Size = new System.Drawing.Size(288, 16);
            this.lblFileName.TabIndex = 7;
            this.lblFileName.Text = "xxxxx";
            // 
            // Label05
            // 
            this.Label05.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.Label05.Location = new System.Drawing.Point(5, 8);
            this.Label05.Name = "Label05";
            this.Label05.Size = new System.Drawing.Size(120, 16);
            this.Label05.TabIndex = 0;
            this.Label05.Text = "Converting DTB name:";
            // 
            // Label08
            // 
            this.Label08.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.Label08.Location = new System.Drawing.Point(5, 32);
            this.Label08.Name = "Label08";
            this.Label08.Size = new System.Drawing.Size(120, 16);
            this.Label08.TabIndex = 6;
            this.Label08.Text = "Converting File name:";
            // 
            // txtDetail
            // 
            this.txtDetail.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txtDetail.Location = new System.Drawing.Point(12, 403);
            this.txtDetail.MaxLength = 99999;
            this.txtDetail.Multiline = true;
            this.txtDetail.Name = "txtDetail";
            this.txtDetail.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtDetail.Size = new System.Drawing.Size(766, 88);
            this.txtDetail.TabIndex = 14;
            // 
            // lblLastCheck
            // 
            this.lblLastCheck.AutoSize = true;
            this.lblLastCheck.Location = new System.Drawing.Point(85, 44);
            this.lblLastCheck.Name = "lblLastCheck";
            this.lblLastCheck.Size = new System.Drawing.Size(37, 13);
            this.lblLastCheck.TabIndex = 15;
            this.lblLastCheck.Text = "xxxxxx";
            // 
            // lblNextCheck
            // 
            this.lblNextCheck.AutoSize = true;
            this.lblNextCheck.Location = new System.Drawing.Point(345, 44);
            this.lblNextCheck.Name = "lblNextCheck";
            this.lblNextCheck.Size = new System.Drawing.Size(37, 13);
            this.lblNextCheck.TabIndex = 16;
            this.lblNextCheck.Text = "xxxxxx";
            // 
            // fileSystemWatcher1
            // 
            this.fileSystemWatcher1.EnableRaisingEvents = true;
            this.fileSystemWatcher1.SynchronizingObject = this;
            // 
            // timer1
            // 
            this.timer1.Interval = 2000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // btnMoveRowUp
            // 
            this.btnMoveRowUp.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnMoveRowUp.Location = new System.Drawing.Point(661, 174);
            this.btnMoveRowUp.Name = "btnMoveRowUp";
            this.btnMoveRowUp.Size = new System.Drawing.Size(117, 23);
            this.btnMoveRowUp.TabIndex = 18;
            this.btnMoveRowUp.Text = "Move Up";
            this.btnMoveRowUp.UseVisualStyleBackColor = false;
            this.btnMoveRowUp.Click += new System.EventHandler(this.btnMoveRowUp_Click);
            // 
            // lblDiskSpace
            // 
            this.lblDiskSpace.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblDiskSpace.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
            this.lblDiskSpace.ForeColor = System.Drawing.Color.Blue;
            this.lblDiskSpace.ImageAlign = System.Drawing.ContentAlignment.TopRight;
            this.lblDiskSpace.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.lblDiskSpace.Location = new System.Drawing.Point(9, 502);
            this.lblDiskSpace.Name = "lblDiskSpace";
            this.lblDiskSpace.Size = new System.Drawing.Size(524, 18);
            this.lblDiskSpace.TabIndex = 19;
            this.lblDiskSpace.Text = "Available space on drive x: = xxxx MB";
            this.lblDiskSpace.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // lblCpuSpeed
            // 
            this.lblCpuSpeed.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lblCpuSpeed.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
            this.lblCpuSpeed.ForeColor = System.Drawing.Color.Blue;
            this.lblCpuSpeed.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.lblCpuSpeed.Location = new System.Drawing.Point(9, 522);
            this.lblCpuSpeed.Name = "lblCpuSpeed";
            this.lblCpuSpeed.Size = new System.Drawing.Size(531, 16);
            this.lblCpuSpeed.TabIndex = 20;
            this.lblCpuSpeed.Text = "CPU Speed = xxxx MHz";
            this.lblCpuSpeed.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // tmrDelayStart
            // 
            this.tmrDelayStart.Interval = 1000;
            this.tmrDelayStart.Tick += new System.EventHandler(this.tmrDelayStart_Tick);
            // 
            // lblSecondToStart
            // 
            this.lblSecondToStart.AutoSize = true;
            this.lblSecondToStart.Location = new System.Drawing.Point(597, 44);
            this.lblSecondToStart.Name = "lblSecondToStart";
            this.lblSecondToStart.Size = new System.Drawing.Size(37, 13);
            this.lblSecondToStart.TabIndex = 22;
            this.lblSecondToStart.Text = "xxxxxx";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(507, 44);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(91, 13);
            this.label7.TabIndex = 21;
            this.label7.Text = "Second To Start :";
            // 
            // btnMoveRowDown
            // 
            this.btnMoveRowDown.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnMoveRowDown.Location = new System.Drawing.Point(661, 202);
            this.btnMoveRowDown.Name = "btnMoveRowDown";
            this.btnMoveRowDown.Size = new System.Drawing.Size(117, 23);
            this.btnMoveRowDown.TabIndex = 17;
            this.btnMoveRowDown.Text = "Move Down";
            this.btnMoveRowDown.UseVisualStyleBackColor = false;
            this.btnMoveRowDown.Click += new System.EventHandler(this.btnMoveRowDown_Click);
            // 
            // btnMoveRowBottom
            // 
            this.btnMoveRowBottom.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnMoveRowBottom.Location = new System.Drawing.Point(661, 230);
            this.btnMoveRowBottom.Name = "btnMoveRowBottom";
            this.btnMoveRowBottom.Size = new System.Drawing.Size(117, 23);
            this.btnMoveRowBottom.TabIndex = 23;
            this.btnMoveRowBottom.Text = "Move Bottom";
            this.btnMoveRowBottom.UseVisualStyleBackColor = false;
            this.btnMoveRowBottom.Click += new System.EventHandler(this.btnMoveRowBottom_Click);
            // 
            // btnMoveRowTop
            // 
            this.btnMoveRowTop.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnMoveRowTop.Location = new System.Drawing.Point(661, 146);
            this.btnMoveRowTop.Name = "btnMoveRowTop";
            this.btnMoveRowTop.Size = new System.Drawing.Size(117, 23);
            this.btnMoveRowTop.TabIndex = 24;
            this.btnMoveRowTop.Text = "Move Top";
            this.btnMoveRowTop.UseVisualStyleBackColor = false;
            this.btnMoveRowTop.Click += new System.EventHandler(this.btnMoveRowTop_Click);
            // 
            // btnStart
            // 
            this.btnStart.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnStart.Enabled = false;
            this.btnStart.Location = new System.Drawing.Point(661, 68);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(117, 72);
            this.btnStart.TabIndex = 26;
            this.btnStart.Text = "START";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // tmrConverting
            // 
            this.tmrConverting.Interval = 10000;
            this.tmrConverting.Tick += new System.EventHandler(this.tmrConverting_Tick);
            // 
            // lblCurrDtbCompleted
            // 
            this.lblCurrDtbCompleted.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.lblCurrDtbCompleted.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.lblCurrDtbCompleted.Location = new System.Drawing.Point(704, 328);
            this.lblCurrDtbCompleted.Name = "lblCurrDtbCompleted";
            this.lblCurrDtbCompleted.Size = new System.Drawing.Size(72, 11);
            this.lblCurrDtbCompleted.TabIndex = 27;
            this.lblCurrDtbCompleted.Text = "0 %";
            this.lblCurrDtbCompleted.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // lblAllDtbCompleted
            // 
            this.lblAllDtbCompleted.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.lblAllDtbCompleted.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.lblAllDtbCompleted.Location = new System.Drawing.Point(704, 358);
            this.lblAllDtbCompleted.Name = "lblAllDtbCompleted";
            this.lblAllDtbCompleted.Size = new System.Drawing.Size(72, 16);
            this.lblAllDtbCompleted.TabIndex = 28;
            this.lblAllDtbCompleted.Text = "0 %";
            this.lblAllDtbCompleted.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // lblHeartbeat
            // 
            this.lblHeartbeat.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.lblHeartbeat.AutoSize = true;
            this.lblHeartbeat.Location = new System.Drawing.Point(637, 523);
            this.lblHeartbeat.Name = "lblHeartbeat";
            this.lblHeartbeat.Size = new System.Drawing.Size(13, 13);
            this.lblHeartbeat.TabIndex = 29;
            this.lblHeartbeat.Text = "0";
            // 
            // tmrHeartbeat
            // 
            this.tmrHeartbeat.Tick += new System.EventHandler(this.tmrHeartbeat_Tick);
            // 
            // label6
            // 
            this.label6.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(536, 522);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(100, 13);
            this.label6.TabIndex = 30;
            this.label6.Text = "Heartbeat Counter :";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(438, 496);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(95, 23);
            this.button2.TabIndex = 31;
            this.button2.Text = "Gen WAV file";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Visible = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // frmAutoConverter
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(790, 541);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.lblHeartbeat);
            this.Controls.Add(this.lblAllDtbCompleted);
            this.Controls.Add(this.lblCurrDtbCompleted);
            this.Controls.Add(this.btnStart);
            this.Controls.Add(this.btnMoveRowTop);
            this.Controls.Add(this.btnMoveRowBottom);
            this.Controls.Add(this.lblSecondToStart);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.lblCpuSpeed);
            this.Controls.Add(this.lblDiskSpace);
            this.Controls.Add(this.btnMoveRowUp);
            this.Controls.Add(this.btnMoveRowDown);
            this.Controls.Add(this.lblNextCheck);
            this.Controls.Add(this.lblLastCheck);
            this.Controls.Add(this.txtDetail);
            this.Controls.Add(this.Panel1);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.pgbAllDtbCompleted);
            this.Controls.Add(this.pgbCurrentDtbCompleted);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.txtDtbShare);
            this.Controls.Add(this.btnChooseFolder);
            this.Controls.Add(this.btnCheckNow);
            this.Controls.Add(this.dgvDtbList);
            this.Controls.Add(this.button1);
            this.MinimumSize = new System.Drawing.Size(798, 567);
            this.Name = "frmAutoConverter";
            this.Text = "TAB-AutoConverter for Tatip";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dgvDtbList)).EndInit();
            this.Panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.fileSystemWatcher1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.DataGridView dgvDtbList;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.TextBox txtDtbShare;
        private System.Windows.Forms.Button btnChooseFolder;
        private System.Windows.Forms.Button btnCheckNow;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ProgressBar pgbAllDtbCompleted;
        private System.Windows.Forms.ProgressBar pgbCurrentDtbCompleted;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label5;
        internal System.Windows.Forms.Panel Panel1;
        internal System.Windows.Forms.Label lblFileTime;
        internal System.Windows.Forms.Label lblDtbTime;
        internal System.Windows.Forms.Label lblFileStatus;
        internal System.Windows.Forms.Label lblDtbStatus;
        internal System.Windows.Forms.Label Label07;
        internal System.Windows.Forms.Label Label10;
        internal System.Windows.Forms.Label Label09;
        internal System.Windows.Forms.Label Label06;
        internal System.Windows.Forms.Label lblDtbName;
        internal System.Windows.Forms.Label lblFileName;
        internal System.Windows.Forms.Label Label05;
        internal System.Windows.Forms.Label Label08;
        internal System.Windows.Forms.TextBox txtDetail;
        private System.Windows.Forms.Label lblNextCheck;
        private System.Windows.Forms.Label lblLastCheck;
        private System.IO.FileSystemWatcher fileSystemWatcher1;
        private System.Windows.Forms.FolderBrowserDialog folderBrowserDialog1;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.DataGridViewTextBoxColumn strNcFilePath;
        private System.Windows.Forms.DataGridViewTextBoxColumn strStatus;
        private System.Windows.Forms.DataGridViewTextBoxColumn strDTBVersion;
        private System.Windows.Forms.DataGridViewTextBoxColumn strOutputPath;
        private System.Windows.Forms.DataGridViewTextBoxColumn strAudioFormat;
        private System.Windows.Forms.DataGridViewTextBoxColumn strSpeechEngine;
        private System.Windows.Forms.Button btnMoveRowUp;
        internal System.Windows.Forms.Label lblDiskSpace;
        internal System.Windows.Forms.Label lblCpuSpeed;
        private System.Windows.Forms.Timer tmrDelayStart;
        private System.Windows.Forms.Label lblSecondToStart;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button btnMoveRowTop;
        private System.Windows.Forms.Button btnMoveRowBottom;
		private System.Windows.Forms.Button btnMoveRowDown;
        private System.Windows.Forms.Button btnStart;
		private System.Windows.Forms.Timer tmrConverting;
		internal System.Windows.Forms.Label lblCurrDtbCompleted;
		internal System.Windows.Forms.Label lblAllDtbCompleted;
		private System.Windows.Forms.Label lblHeartbeat;
		private System.Windows.Forms.Timer tmrHeartbeat;
		private System.Windows.Forms.Label label6;
		private System.Windows.Forms.Button button2;
    }
}

