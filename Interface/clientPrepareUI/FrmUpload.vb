Imports SpeechLib

Public Class FrmUpload
    Inherits System.Windows.Forms.Form

#Region " Windows Form Designer generated code "

    Public Sub New()
        MyBase.New()

        'This call is required by the Windows Form Designer.
        InitializeComponent()

        'Add any initialization after the InitializeComponent() call

    End Sub

    'Form overrides dispose to clean up the component list.
    Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing Then
            If Not (components Is Nothing) Then
                components.Dispose()
            End If
        End If
        MyBase.Dispose(disposing)
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    Friend WithEvents MainMenu1 As System.Windows.Forms.MainMenu
    Friend WithEvents MenuItem1 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem2 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem3 As System.Windows.Forms.MenuItem
    Friend WithEvents GroupBox2 As System.Windows.Forms.GroupBox
    Friend WithEvents Panel22 As System.Windows.Forms.Panel
    Friend WithEvents LblFileTime As System.Windows.Forms.Label
    Friend WithEvents LblDtbTime As System.Windows.Forms.Label
    Friend WithEvents LblFileStatus As System.Windows.Forms.Label
    Friend WithEvents LblDtbStatus As System.Windows.Forms.Label
    Friend WithEvents Label07 As System.Windows.Forms.Label
    Friend WithEvents Label10 As System.Windows.Forms.Label
    Friend WithEvents Label09 As System.Windows.Forms.Label
    Friend WithEvents Label06 As System.Windows.Forms.Label
    Friend WithEvents LblDtbName As System.Windows.Forms.Label
    Friend WithEvents LblFileName As System.Windows.Forms.Label
    Friend WithEvents Label05 As System.Windows.Forms.Label
    Friend WithEvents Label08 As System.Windows.Forms.Label
    Friend WithEvents Panel31 As System.Windows.Forms.Panel
    Friend WithEvents Label12 As System.Windows.Forms.Label
    Friend WithEvents LblAllDtbCompleted As System.Windows.Forms.Label
    Friend WithEvents Panel32 As System.Windows.Forms.Panel
    Friend WithEvents PgbAllDtbCompleted As System.Windows.Forms.ProgressBar
    Friend WithEvents DataGrid2 As System.Windows.Forms.DataGrid
    Friend WithEvents StatusBar1 As System.Windows.Forms.StatusBar
    Friend WithEvents MenuItem4 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem5 As System.Windows.Forms.MenuItem
    Friend WithEvents Panel1 As System.Windows.Forms.Panel
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents Panel4 As System.Windows.Forms.Panel
    Friend WithEvents Panel2 As System.Windows.Forms.Panel
    Friend WithEvents Panel3 As System.Windows.Forms.Panel
    Friend WithEvents Panel5 As System.Windows.Forms.Panel
    Friend WithEvents Panel6 As System.Windows.Forms.Panel
    Friend WithEvents Panel7 As System.Windows.Forms.Panel
    Friend WithEvents Panel10 As System.Windows.Forms.Panel
    Friend WithEvents Panel8 As System.Windows.Forms.Panel
    Friend WithEvents Panel18 As System.Windows.Forms.Panel
    Friend WithEvents Panel19 As System.Windows.Forms.Panel
    Friend WithEvents Panel21 As System.Windows.Forms.Panel
    Friend WithEvents Panel23 As System.Windows.Forms.Panel
    Friend WithEvents TreeView2 As System.Windows.Forms.TreeView
    Friend WithEvents TreeView1 As System.Windows.Forms.TreeView
    Friend WithEvents Button5 As System.Windows.Forms.Button
    Friend WithEvents Button9 As System.Windows.Forms.Button
    Friend WithEvents Button7 As System.Windows.Forms.Button
    Friend WithEvents Button6 As System.Windows.Forms.Button
    Friend WithEvents Button3 As System.Windows.Forms.Button
    Friend WithEvents Button4 As System.Windows.Forms.Button
    Friend WithEvents Button10 As System.Windows.Forms.Button
    Friend WithEvents Button11 As System.Windows.Forms.Button
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents ComboBox3 As System.Windows.Forms.ComboBox
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents ComboBox2 As System.Windows.Forms.ComboBox
    Friend WithEvents Button17 As System.Windows.Forms.Button
    Friend WithEvents Button18 As System.Windows.Forms.Button
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents ExpTree1 As exploreTreeViewDll.ExpTree
    Friend WithEvents Button8 As System.Windows.Forms.Button
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents ComboBox1 As System.Windows.Forms.ComboBox
    Friend WithEvents MenuItem6 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem7 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem8 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem9 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem10 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem11 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem12 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem13 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem14 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem15 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem16 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem17 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem18 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem19 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem20 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem21 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem22 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem23 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem24 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem25 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem26 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem27 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem28 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem29 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem30 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem31 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem32 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem33 As System.Windows.Forms.MenuItem
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(FrmUpload))
        Me.MainMenu1 = New System.Windows.Forms.MainMenu(Me.components)
        Me.MenuItem1 = New System.Windows.Forms.MenuItem()
        Me.MenuItem2 = New System.Windows.Forms.MenuItem()
        Me.MenuItem6 = New System.Windows.Forms.MenuItem()
        Me.MenuItem7 = New System.Windows.Forms.MenuItem()
        Me.MenuItem8 = New System.Windows.Forms.MenuItem()
        Me.MenuItem3 = New System.Windows.Forms.MenuItem()
        Me.MenuItem14 = New System.Windows.Forms.MenuItem()
        Me.MenuItem15 = New System.Windows.Forms.MenuItem()
        Me.MenuItem16 = New System.Windows.Forms.MenuItem()
        Me.MenuItem17 = New System.Windows.Forms.MenuItem()
        Me.MenuItem21 = New System.Windows.Forms.MenuItem()
        Me.MenuItem22 = New System.Windows.Forms.MenuItem()
        Me.MenuItem13 = New System.Windows.Forms.MenuItem()
        Me.MenuItem12 = New System.Windows.Forms.MenuItem()
        Me.MenuItem18 = New System.Windows.Forms.MenuItem()
        Me.MenuItem19 = New System.Windows.Forms.MenuItem()
        Me.MenuItem20 = New System.Windows.Forms.MenuItem()
        Me.MenuItem4 = New System.Windows.Forms.MenuItem()
        Me.MenuItem23 = New System.Windows.Forms.MenuItem()
        Me.MenuItem24 = New System.Windows.Forms.MenuItem()
        Me.MenuItem25 = New System.Windows.Forms.MenuItem()
        Me.MenuItem26 = New System.Windows.Forms.MenuItem()
        Me.MenuItem27 = New System.Windows.Forms.MenuItem()
        Me.MenuItem28 = New System.Windows.Forms.MenuItem()
        Me.MenuItem29 = New System.Windows.Forms.MenuItem()
        Me.MenuItem30 = New System.Windows.Forms.MenuItem()
        Me.MenuItem31 = New System.Windows.Forms.MenuItem()
        Me.MenuItem32 = New System.Windows.Forms.MenuItem()
        Me.MenuItem33 = New System.Windows.Forms.MenuItem()
        Me.MenuItem5 = New System.Windows.Forms.MenuItem()
        Me.MenuItem9 = New System.Windows.Forms.MenuItem()
        Me.MenuItem10 = New System.Windows.Forms.MenuItem()
        Me.MenuItem11 = New System.Windows.Forms.MenuItem()
        Me.GroupBox2 = New System.Windows.Forms.GroupBox()
        Me.Panel22 = New System.Windows.Forms.Panel()
        Me.LblFileTime = New System.Windows.Forms.Label()
        Me.LblDtbTime = New System.Windows.Forms.Label()
        Me.LblFileStatus = New System.Windows.Forms.Label()
        Me.LblDtbStatus = New System.Windows.Forms.Label()
        Me.Label07 = New System.Windows.Forms.Label()
        Me.Label10 = New System.Windows.Forms.Label()
        Me.Label09 = New System.Windows.Forms.Label()
        Me.Label06 = New System.Windows.Forms.Label()
        Me.LblDtbName = New System.Windows.Forms.Label()
        Me.LblFileName = New System.Windows.Forms.Label()
        Me.Label05 = New System.Windows.Forms.Label()
        Me.Label08 = New System.Windows.Forms.Label()
        Me.Panel31 = New System.Windows.Forms.Panel()
        Me.Label12 = New System.Windows.Forms.Label()
        Me.LblAllDtbCompleted = New System.Windows.Forms.Label()
        Me.Panel32 = New System.Windows.Forms.Panel()
        Me.PgbAllDtbCompleted = New System.Windows.Forms.ProgressBar()
        Me.DataGrid2 = New System.Windows.Forms.DataGrid()
        Me.StatusBar1 = New System.Windows.Forms.StatusBar()
        Me.Panel1 = New System.Windows.Forms.Panel()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox()
        Me.Panel2 = New System.Windows.Forms.Panel()
        Me.Panel21 = New System.Windows.Forms.Panel()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.ComboBox1 = New System.Windows.Forms.ComboBox()
        Me.Panel23 = New System.Windows.Forms.Panel()
        Me.Button8 = New System.Windows.Forms.Button()
        Me.Panel4 = New System.Windows.Forms.Panel()
        Me.Panel7 = New System.Windows.Forms.Panel()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.Button2 = New System.Windows.Forms.Button()
        Me.Panel6 = New System.Windows.Forms.Panel()
        Me.TreeView1 = New System.Windows.Forms.TreeView()
        Me.Panel8 = New System.Windows.Forms.Panel()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.ComboBox2 = New System.Windows.Forms.ComboBox()
        Me.Panel10 = New System.Windows.Forms.Panel()
        Me.Button5 = New System.Windows.Forms.Button()
        Me.Button9 = New System.Windows.Forms.Button()
        Me.Button7 = New System.Windows.Forms.Button()
        Me.Button6 = New System.Windows.Forms.Button()
        Me.Panel5 = New System.Windows.Forms.Panel()
        Me.Button17 = New System.Windows.Forms.Button()
        Me.Button18 = New System.Windows.Forms.Button()
        Me.Panel3 = New System.Windows.Forms.Panel()
        Me.TreeView2 = New System.Windows.Forms.TreeView()
        Me.Panel18 = New System.Windows.Forms.Panel()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.ComboBox3 = New System.Windows.Forms.ComboBox()
        Me.Panel19 = New System.Windows.Forms.Panel()
        Me.Button3 = New System.Windows.Forms.Button()
        Me.Button4 = New System.Windows.Forms.Button()
        Me.Button10 = New System.Windows.Forms.Button()
        Me.Button11 = New System.Windows.Forms.Button()
        Me.ExpTree1 = New TAB.Telephony.exploreTreeViewDll.ExpTree()
        Me.GroupBox2.SuspendLayout()
        Me.Panel22.SuspendLayout()
        Me.Panel31.SuspendLayout()
        Me.Panel32.SuspendLayout()
        CType(Me.DataGrid2, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.Panel1.SuspendLayout()
        Me.GroupBox1.SuspendLayout()
        Me.Panel2.SuspendLayout()
        Me.Panel21.SuspendLayout()
        Me.Panel23.SuspendLayout()
        Me.Panel4.SuspendLayout()
        Me.Panel7.SuspendLayout()
        Me.Panel6.SuspendLayout()
        Me.Panel8.SuspendLayout()
        Me.Panel10.SuspendLayout()
        Me.Panel5.SuspendLayout()
        Me.Panel3.SuspendLayout()
        Me.Panel18.SuspendLayout()
        Me.Panel19.SuspendLayout()
        Me.SuspendLayout()
        '
        'MainMenu1
        '
        Me.MainMenu1.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem1, Me.MenuItem3, Me.MenuItem4, Me.MenuItem5})
        '
        'MenuItem1
        '
        Me.MenuItem1.Index = 0
        Me.MenuItem1.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem2, Me.MenuItem6, Me.MenuItem7, Me.MenuItem8})
        Me.MenuItem1.Text = "&File"
        '
        'MenuItem2
        '
        Me.MenuItem2.Index = 0
        Me.MenuItem2.Text = "&Open Connection"
        '
        'MenuItem6
        '
        Me.MenuItem6.Index = 1
        Me.MenuItem6.Text = "-"
        '
        'MenuItem7
        '
        Me.MenuItem7.Index = 2
        Me.MenuItem7.Text = "&Switch to converter"
        '
        'MenuItem8
        '
        Me.MenuItem8.Index = 3
        Me.MenuItem8.Text = "&Exit Program"
        '
        'MenuItem3
        '
        Me.MenuItem3.Index = 1
        Me.MenuItem3.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem14, Me.MenuItem17, Me.MenuItem13, Me.MenuItem12, Me.MenuItem18, Me.MenuItem19, Me.MenuItem20})
        Me.MenuItem3.Text = "Catagory &A"
        '
        'MenuItem14
        '
        Me.MenuItem14.Index = 0
        Me.MenuItem14.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem15, Me.MenuItem16})
        Me.MenuItem14.Text = "Move"
        '
        'MenuItem15
        '
        Me.MenuItem15.Index = 0
        Me.MenuItem15.Text = "from Client"
        '
        'MenuItem16
        '
        Me.MenuItem16.Index = 1
        Me.MenuItem16.Text = "to Catagory B"
        '
        'MenuItem17
        '
        Me.MenuItem17.Index = 1
        Me.MenuItem17.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem21, Me.MenuItem22})
        Me.MenuItem17.Text = "Rename"
        '
        'MenuItem21
        '
        Me.MenuItem21.Index = 0
        Me.MenuItem21.Text = "Rename Text"
        '
        'MenuItem22
        '
        Me.MenuItem22.Index = 1
        Me.MenuItem22.Text = "Rename Audio"
        '
        'MenuItem13
        '
        Me.MenuItem13.Index = 2
        Me.MenuItem13.Text = "-"
        '
        'MenuItem12
        '
        Me.MenuItem12.Index = 3
        Me.MenuItem12.Text = "Refresh"
        '
        'MenuItem18
        '
        Me.MenuItem18.Index = 4
        Me.MenuItem18.Text = "Remove"
        '
        'MenuItem19
        '
        Me.MenuItem19.Index = 5
        Me.MenuItem19.Text = "Move up"
        '
        'MenuItem20
        '
        Me.MenuItem20.Index = 6
        Me.MenuItem20.Text = "Move down"
        '
        'MenuItem4
        '
        Me.MenuItem4.Index = 2
        Me.MenuItem4.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem23, Me.MenuItem26, Me.MenuItem29, Me.MenuItem30, Me.MenuItem31, Me.MenuItem32, Me.MenuItem33})
        Me.MenuItem4.Text = "Catagory &B"
        '
        'MenuItem23
        '
        Me.MenuItem23.Index = 0
        Me.MenuItem23.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem24, Me.MenuItem25})
        Me.MenuItem23.Text = "Move"
        '
        'MenuItem24
        '
        Me.MenuItem24.Index = 0
        Me.MenuItem24.Text = "from Client"
        '
        'MenuItem25
        '
        Me.MenuItem25.Index = 1
        Me.MenuItem25.Text = "to Catagory A"
        '
        'MenuItem26
        '
        Me.MenuItem26.Index = 1
        Me.MenuItem26.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem27, Me.MenuItem28})
        Me.MenuItem26.Text = "Rename"
        '
        'MenuItem27
        '
        Me.MenuItem27.Index = 0
        Me.MenuItem27.Text = "Rename Text"
        '
        'MenuItem28
        '
        Me.MenuItem28.Index = 1
        Me.MenuItem28.Text = "Rename Audio"
        '
        'MenuItem29
        '
        Me.MenuItem29.Index = 2
        Me.MenuItem29.Text = "-"
        '
        'MenuItem30
        '
        Me.MenuItem30.Index = 3
        Me.MenuItem30.Text = "Refresh"
        '
        'MenuItem31
        '
        Me.MenuItem31.Index = 4
        Me.MenuItem31.Text = "Remove"
        '
        'MenuItem32
        '
        Me.MenuItem32.Index = 5
        Me.MenuItem32.Text = "Move up"
        '
        'MenuItem33
        '
        Me.MenuItem33.Index = 6
        Me.MenuItem33.Text = "Move down"
        '
        'MenuItem5
        '
        Me.MenuItem5.Index = 3
        Me.MenuItem5.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem9, Me.MenuItem10, Me.MenuItem11})
        Me.MenuItem5.Text = "&Help"
        '
        'MenuItem9
        '
        Me.MenuItem9.Index = 0
        Me.MenuItem9.Text = "Help"
        '
        'MenuItem10
        '
        Me.MenuItem10.Index = 1
        Me.MenuItem10.Text = "-"
        '
        'MenuItem11
        '
        Me.MenuItem11.Index = 2
        Me.MenuItem11.Text = "About"
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.Panel22)
        Me.GroupBox2.Controls.Add(Me.Panel31)
        Me.GroupBox2.Controls.Add(Me.Panel32)
        Me.GroupBox2.Controls.Add(Me.DataGrid2)
        Me.GroupBox2.Dock = System.Windows.Forms.DockStyle.Bottom
        Me.GroupBox2.Enabled = False
        Me.GroupBox2.Location = New System.Drawing.Point(0, 477)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(888, 184)
        Me.GroupBox2.TabIndex = 5
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "Status"
        '
        'Panel22
        '
        Me.Panel22.Controls.Add(Me.LblFileTime)
        Me.Panel22.Controls.Add(Me.LblDtbTime)
        Me.Panel22.Controls.Add(Me.LblFileStatus)
        Me.Panel22.Controls.Add(Me.LblDtbStatus)
        Me.Panel22.Controls.Add(Me.Label07)
        Me.Panel22.Controls.Add(Me.Label10)
        Me.Panel22.Controls.Add(Me.Label09)
        Me.Panel22.Controls.Add(Me.Label06)
        Me.Panel22.Controls.Add(Me.LblDtbName)
        Me.Panel22.Controls.Add(Me.LblFileName)
        Me.Panel22.Controls.Add(Me.Label05)
        Me.Panel22.Controls.Add(Me.Label08)
        Me.Panel22.Dock = System.Windows.Forms.DockStyle.Bottom
        Me.Panel22.Location = New System.Drawing.Point(3, 13)
        Me.Panel22.Name = "Panel22"
        Me.Panel22.Size = New System.Drawing.Size(882, 56)
        Me.Panel22.TabIndex = 0
        '
        'LblFileTime
        '
        Me.LblFileTime.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.LblFileTime.Location = New System.Drawing.Point(770, 32)
        Me.LblFileTime.Name = "LblFileTime"
        Me.LblFileTime.Size = New System.Drawing.Size(88, 16)
        Me.LblFileTime.TabIndex = 11
        Me.LblFileTime.Text = "xxxxx"
        '
        'LblDtbTime
        '
        Me.LblDtbTime.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.LblDtbTime.Location = New System.Drawing.Point(770, 8)
        Me.LblDtbTime.Name = "LblDtbTime"
        Me.LblDtbTime.Size = New System.Drawing.Size(88, 16)
        Me.LblDtbTime.TabIndex = 5
        Me.LblDtbTime.Text = "xxxxx"
        '
        'LblFileStatus
        '
        Me.LblFileStatus.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.LblFileStatus.Location = New System.Drawing.Point(610, 32)
        Me.LblFileStatus.Name = "LblFileStatus"
        Me.LblFileStatus.Size = New System.Drawing.Size(88, 16)
        Me.LblFileStatus.TabIndex = 9
        Me.LblFileStatus.Text = "xxxxx"
        '
        'LblDtbStatus
        '
        Me.LblDtbStatus.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.LblDtbStatus.Location = New System.Drawing.Point(610, 8)
        Me.LblDtbStatus.Name = "LblDtbStatus"
        Me.LblDtbStatus.Size = New System.Drawing.Size(88, 16)
        Me.LblDtbStatus.TabIndex = 3
        Me.LblDtbStatus.Text = "xxxxx"
        '
        'Label07
        '
        Me.Label07.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.Label07.Location = New System.Drawing.Point(698, 8)
        Me.Label07.Name = "Label07"
        Me.Label07.Size = New System.Drawing.Size(72, 16)
        Me.Label07.TabIndex = 4
        Me.Label07.Text = "  Total Time:"
        '
        'Label10
        '
        Me.Label10.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.Label10.Location = New System.Drawing.Point(698, 32)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(72, 16)
        Me.Label10.TabIndex = 10
        Me.Label10.Text = "  Total Time:"
        '
        'Label09
        '
        Me.Label09.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.Label09.Location = New System.Drawing.Point(554, 32)
        Me.Label09.Name = "Label09"
        Me.Label09.Size = New System.Drawing.Size(56, 16)
        Me.Label09.TabIndex = 8
        Me.Label09.Text = "  Status:"
        '
        'Label06
        '
        Me.Label06.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.Label06.Location = New System.Drawing.Point(554, 8)
        Me.Label06.Name = "Label06"
        Me.Label06.Size = New System.Drawing.Size(56, 16)
        Me.Label06.TabIndex = 2
        Me.Label06.Text = "  Status:"
        '
        'LblDtbName
        '
        Me.LblDtbName.BackColor = System.Drawing.SystemColors.Control
        Me.LblDtbName.Location = New System.Drawing.Point(144, 8)
        Me.LblDtbName.Name = "LblDtbName"
        Me.LblDtbName.Size = New System.Drawing.Size(320, 16)
        Me.LblDtbName.TabIndex = 1
        '
        'LblFileName
        '
        Me.LblFileName.BackColor = System.Drawing.SystemColors.Control
        Me.LblFileName.Location = New System.Drawing.Point(144, 32)
        Me.LblFileName.Name = "LblFileName"
        Me.LblFileName.Size = New System.Drawing.Size(320, 16)
        Me.LblFileName.TabIndex = 7
        '
        'Label05
        '
        Me.Label05.Location = New System.Drawing.Point(24, 8)
        Me.Label05.Name = "Label05"
        Me.Label05.Size = New System.Drawing.Size(120, 16)
        Me.Label05.TabIndex = 0
        Me.Label05.Text = "Transfering DTB name:"
        '
        'Label08
        '
        Me.Label08.Location = New System.Drawing.Point(24, 32)
        Me.Label08.Name = "Label08"
        Me.Label08.Size = New System.Drawing.Size(120, 16)
        Me.Label08.TabIndex = 6
        Me.Label08.Text = "Transfering File name:"
        '
        'Panel31
        '
        Me.Panel31.Controls.Add(Me.Label12)
        Me.Panel31.Controls.Add(Me.LblAllDtbCompleted)
        Me.Panel31.Dock = System.Windows.Forms.DockStyle.Bottom
        Me.Panel31.Location = New System.Drawing.Point(3, 69)
        Me.Panel31.Name = "Panel31"
        Me.Panel31.Size = New System.Drawing.Size(882, 24)
        Me.Panel31.TabIndex = 2
        '
        'Label12
        '
        Me.Label12.Location = New System.Drawing.Point(0, 8)
        Me.Label12.Name = "Label12"
        Me.Label12.Size = New System.Drawing.Size(176, 16)
        Me.Label12.TabIndex = 0
        Me.Label12.Text = "Percent tranfer DTB Completed:"
        '
        'LblAllDtbCompleted
        '
        Me.LblAllDtbCompleted.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.LblAllDtbCompleted.Location = New System.Drawing.Point(810, 8)
        Me.LblAllDtbCompleted.Name = "LblAllDtbCompleted"
        Me.LblAllDtbCompleted.Size = New System.Drawing.Size(72, 16)
        Me.LblAllDtbCompleted.TabIndex = 1
        Me.LblAllDtbCompleted.Text = "0 %"
        Me.LblAllDtbCompleted.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Panel32
        '
        Me.Panel32.Controls.Add(Me.PgbAllDtbCompleted)
        Me.Panel32.Dock = System.Windows.Forms.DockStyle.Bottom
        Me.Panel32.Location = New System.Drawing.Point(3, 93)
        Me.Panel32.Name = "Panel32"
        Me.Panel32.Size = New System.Drawing.Size(882, 24)
        Me.Panel32.TabIndex = 3
        '
        'PgbAllDtbCompleted
        '
        Me.PgbAllDtbCompleted.Dock = System.Windows.Forms.DockStyle.Top
        Me.PgbAllDtbCompleted.Location = New System.Drawing.Point(0, 0)
        Me.PgbAllDtbCompleted.Name = "PgbAllDtbCompleted"
        Me.PgbAllDtbCompleted.Size = New System.Drawing.Size(882, 16)
        Me.PgbAllDtbCompleted.Step = 1
        Me.PgbAllDtbCompleted.TabIndex = 0
        '
        'DataGrid2
        '
        Me.DataGrid2.DataMember = ""
        Me.DataGrid2.Dock = System.Windows.Forms.DockStyle.Bottom
        Me.DataGrid2.HeaderForeColor = System.Drawing.SystemColors.ControlText
        Me.DataGrid2.Location = New System.Drawing.Point(3, 117)
        Me.DataGrid2.Name = "DataGrid2"
        Me.DataGrid2.Size = New System.Drawing.Size(882, 64)
        Me.DataGrid2.TabIndex = 4
        '
        'StatusBar1
        '
        Me.StatusBar1.Location = New System.Drawing.Point(0, 661)
        Me.StatusBar1.Name = "StatusBar1"
        Me.StatusBar1.Size = New System.Drawing.Size(888, 24)
        Me.StatusBar1.TabIndex = 4
        Me.StatusBar1.Text = "Connected to ""TAB_IVR"". Start 2/2/04 12:20AM. Up time = 3 days 12 hr 34 minute.  " & _
            "Last log-in 30/1/04 11:12AM."
        '
        'Panel1
        '
        Me.Panel1.Controls.Add(Me.GroupBox1)
        Me.Panel1.Dock = System.Windows.Forms.DockStyle.Fill
        Me.Panel1.Location = New System.Drawing.Point(0, 0)
        Me.Panel1.Name = "Panel1"
        Me.Panel1.Size = New System.Drawing.Size(888, 477)
        Me.Panel1.TabIndex = 6
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.Panel2)
        Me.GroupBox1.Controls.Add(Me.Panel4)
        Me.GroupBox1.Dock = System.Windows.Forms.DockStyle.Fill
        Me.GroupBox1.Location = New System.Drawing.Point(0, 0)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(888, 477)
        Me.GroupBox1.TabIndex = 0
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "No Connection"
        '
        'Panel2
        '
        Me.Panel2.Controls.Add(Me.ExpTree1)
        Me.Panel2.Controls.Add(Me.Panel21)
        Me.Panel2.Controls.Add(Me.Panel23)
        Me.Panel2.Dock = System.Windows.Forms.DockStyle.Fill
        Me.Panel2.Location = New System.Drawing.Point(3, 16)
        Me.Panel2.Name = "Panel2"
        Me.Panel2.Size = New System.Drawing.Size(290, 458)
        Me.Panel2.TabIndex = 0
        '
        'Panel21
        '
        Me.Panel21.BackColor = System.Drawing.SystemColors.Control
        Me.Panel21.Controls.Add(Me.Label4)
        Me.Panel21.Controls.Add(Me.ComboBox1)
        Me.Panel21.Dock = System.Windows.Forms.DockStyle.Top
        Me.Panel21.Location = New System.Drawing.Point(0, 0)
        Me.Panel21.Name = "Panel21"
        Me.Panel21.Size = New System.Drawing.Size(290, 40)
        Me.Panel21.TabIndex = 0
        '
        'Label4
        '
        Me.Label4.Location = New System.Drawing.Point(8, 16)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(64, 16)
        Me.Label4.TabIndex = 68
        Me.Label4.Text = "Client Drive"
        '
        'ComboBox1
        '
        Me.ComboBox1.AccessibleDescription = "Drive"
        Me.ComboBox1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBox1.ItemHeight = 13
        Me.ComboBox1.Location = New System.Drawing.Point(72, 14)
        Me.ComboBox1.Name = "ComboBox1"
        Me.ComboBox1.Size = New System.Drawing.Size(40, 21)
        Me.ComboBox1.TabIndex = 69
        '
        'Panel23
        '
        Me.Panel23.BackColor = System.Drawing.SystemColors.Control
        Me.Panel23.Controls.Add(Me.Button8)
        Me.Panel23.Dock = System.Windows.Forms.DockStyle.Bottom
        Me.Panel23.Location = New System.Drawing.Point(0, 402)
        Me.Panel23.Name = "Panel23"
        Me.Panel23.Size = New System.Drawing.Size(290, 56)
        Me.Panel23.TabIndex = 2
        '
        'Button8
        '
        Me.Button8.Anchor = CType((System.Windows.Forms.AnchorStyles.Left Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.Button8.Location = New System.Drawing.Point(80, 8)
        Me.Button8.Name = "Button8"
        Me.Button8.Size = New System.Drawing.Size(120, 32)
        Me.Button8.TabIndex = 69
        Me.Button8.Text = "Refresh Client"
        '
        'Panel4
        '
        Me.Panel4.BackColor = System.Drawing.SystemColors.Control
        Me.Panel4.Controls.Add(Me.Panel7)
        Me.Panel4.Controls.Add(Me.Panel6)
        Me.Panel4.Controls.Add(Me.Panel5)
        Me.Panel4.Controls.Add(Me.Panel3)
        Me.Panel4.Dock = System.Windows.Forms.DockStyle.Right
        Me.Panel4.Location = New System.Drawing.Point(293, 16)
        Me.Panel4.Name = "Panel4"
        Me.Panel4.Size = New System.Drawing.Size(592, 458)
        Me.Panel4.TabIndex = 0
        '
        'Panel7
        '
        Me.Panel7.BackColor = System.Drawing.SystemColors.Control
        Me.Panel7.Controls.Add(Me.Button1)
        Me.Panel7.Controls.Add(Me.Button2)
        Me.Panel7.Dock = System.Windows.Forms.DockStyle.Fill
        Me.Panel7.Location = New System.Drawing.Point(0, 0)
        Me.Panel7.Name = "Panel7"
        Me.Panel7.Size = New System.Drawing.Size(72, 458)
        Me.Panel7.TabIndex = 0
        '
        'Button1
        '
        Me.Button1.Anchor = CType((System.Windows.Forms.AnchorStyles.Left Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.Button1.Image = CType(resources.GetObject("Button1.Image"), System.Drawing.Image)
        Me.Button1.Location = New System.Drawing.Point(8, 233)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(56, 32)
        Me.Button1.TabIndex = 1
        Me.Button1.Text = "<<"
        '
        'Button2
        '
        Me.Button2.Anchor = CType((System.Windows.Forms.AnchorStyles.Left Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.Button2.Image = CType(resources.GetObject("Button2.Image"), System.Drawing.Image)
        Me.Button2.Location = New System.Drawing.Point(8, 193)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(56, 32)
        Me.Button2.TabIndex = 0
        Me.Button2.Text = ">>"
        '
        'Panel6
        '
        Me.Panel6.BackColor = System.Drawing.SystemColors.Control
        Me.Panel6.Controls.Add(Me.TreeView1)
        Me.Panel6.Controls.Add(Me.Panel8)
        Me.Panel6.Controls.Add(Me.Panel10)
        Me.Panel6.Dock = System.Windows.Forms.DockStyle.Right
        Me.Panel6.Location = New System.Drawing.Point(72, 0)
        Me.Panel6.Name = "Panel6"
        Me.Panel6.Size = New System.Drawing.Size(224, 458)
        Me.Panel6.TabIndex = 1
        '
        'TreeView1
        '
        Me.TreeView1.AccessibleDescription = "Lists in Catagory A"
        Me.TreeView1.Dock = System.Windows.Forms.DockStyle.Fill
        Me.TreeView1.Location = New System.Drawing.Point(0, 40)
        Me.TreeView1.Name = "TreeView1"
        Me.TreeView1.Size = New System.Drawing.Size(224, 362)
        Me.TreeView1.TabIndex = 1
        '
        'Panel8
        '
        Me.Panel8.Controls.Add(Me.Label3)
        Me.Panel8.Controls.Add(Me.ComboBox2)
        Me.Panel8.Dock = System.Windows.Forms.DockStyle.Top
        Me.Panel8.Location = New System.Drawing.Point(0, 0)
        Me.Panel8.Name = "Panel8"
        Me.Panel8.Size = New System.Drawing.Size(224, 40)
        Me.Panel8.TabIndex = 0
        '
        'Label3
        '
        Me.Label3.Location = New System.Drawing.Point(0, 16)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(64, 16)
        Me.Label3.TabIndex = 0
        Me.Label3.Text = "Catagory A"
        '
        'ComboBox2
        '
        Me.ComboBox2.AccessibleDescription = "Catagory A"
        Me.ComboBox2.AccessibleName = "Catagory A"
        Me.ComboBox2.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBox2.ItemHeight = 13
        Me.ComboBox2.Items.AddRange(New Object() {"1-New Comming", "2-Children's Books", "3-Entertainment", "4-Computers & Internet", "5-Religion & Spirituality", "6-Outdoors & Nature", "7-Law", "8-History", "9-Health, Mind & Body"})
        Me.ComboBox2.Location = New System.Drawing.Point(64, 14)
        Me.ComboBox2.MaxDropDownItems = 10
        Me.ComboBox2.Name = "ComboBox2"
        Me.ComboBox2.Size = New System.Drawing.Size(160, 21)
        Me.ComboBox2.TabIndex = 1
        '
        'Panel10
        '
        Me.Panel10.Controls.Add(Me.Button5)
        Me.Panel10.Controls.Add(Me.Button9)
        Me.Panel10.Controls.Add(Me.Button7)
        Me.Panel10.Controls.Add(Me.Button6)
        Me.Panel10.Dock = System.Windows.Forms.DockStyle.Bottom
        Me.Panel10.Location = New System.Drawing.Point(0, 402)
        Me.Panel10.Name = "Panel10"
        Me.Panel10.Size = New System.Drawing.Size(224, 56)
        Me.Panel10.TabIndex = 2
        '
        'Button5
        '
        Me.Button5.Location = New System.Drawing.Point(56, 12)
        Me.Button5.Name = "Button5"
        Me.Button5.Size = New System.Drawing.Size(56, 32)
        Me.Button5.TabIndex = 1
        Me.Button5.Text = "Remove"
        '
        'Button9
        '
        Me.Button9.Location = New System.Drawing.Point(0, 12)
        Me.Button9.Name = "Button9"
        Me.Button9.Size = New System.Drawing.Size(56, 32)
        Me.Button9.TabIndex = 0
        Me.Button9.Text = "Refresh"
        '
        'Button7
        '
        Me.Button7.Location = New System.Drawing.Point(168, 12)
        Me.Button7.Name = "Button7"
        Me.Button7.Size = New System.Drawing.Size(56, 32)
        Me.Button7.TabIndex = 3
        Me.Button7.Text = "Down"
        '
        'Button6
        '
        Me.Button6.Location = New System.Drawing.Point(112, 12)
        Me.Button6.Name = "Button6"
        Me.Button6.Size = New System.Drawing.Size(56, 32)
        Me.Button6.TabIndex = 2
        Me.Button6.Text = "Up"
        '
        'Panel5
        '
        Me.Panel5.BackColor = System.Drawing.SystemColors.Control
        Me.Panel5.Controls.Add(Me.Button17)
        Me.Panel5.Controls.Add(Me.Button18)
        Me.Panel5.Dock = System.Windows.Forms.DockStyle.Right
        Me.Panel5.Location = New System.Drawing.Point(296, 0)
        Me.Panel5.Name = "Panel5"
        Me.Panel5.Size = New System.Drawing.Size(72, 458)
        Me.Panel5.TabIndex = 2
        '
        'Button17
        '
        Me.Button17.Anchor = CType((System.Windows.Forms.AnchorStyles.Left Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.Button17.Image = CType(resources.GetObject("Button17.Image"), System.Drawing.Image)
        Me.Button17.Location = New System.Drawing.Point(8, 233)
        Me.Button17.Name = "Button17"
        Me.Button17.Size = New System.Drawing.Size(56, 32)
        Me.Button17.TabIndex = 1
        Me.Button17.Text = "<<"
        '
        'Button18
        '
        Me.Button18.Anchor = CType((System.Windows.Forms.AnchorStyles.Left Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.Button18.Image = CType(resources.GetObject("Button18.Image"), System.Drawing.Image)
        Me.Button18.Location = New System.Drawing.Point(8, 193)
        Me.Button18.Name = "Button18"
        Me.Button18.Size = New System.Drawing.Size(56, 32)
        Me.Button18.TabIndex = 0
        Me.Button18.Text = ">>"
        '
        'Panel3
        '
        Me.Panel3.BackColor = System.Drawing.SystemColors.Control
        Me.Panel3.Controls.Add(Me.TreeView2)
        Me.Panel3.Controls.Add(Me.Panel18)
        Me.Panel3.Controls.Add(Me.Panel19)
        Me.Panel3.Dock = System.Windows.Forms.DockStyle.Right
        Me.Panel3.Location = New System.Drawing.Point(368, 0)
        Me.Panel3.Name = "Panel3"
        Me.Panel3.Size = New System.Drawing.Size(224, 458)
        Me.Panel3.TabIndex = 3
        '
        'TreeView2
        '
        Me.TreeView2.AccessibleDescription = "Lists in Catagory B"
        Me.TreeView2.Dock = System.Windows.Forms.DockStyle.Fill
        Me.TreeView2.ItemHeight = 16
        Me.TreeView2.Location = New System.Drawing.Point(0, 40)
        Me.TreeView2.Name = "TreeView2"
        Me.TreeView2.Size = New System.Drawing.Size(224, 362)
        Me.TreeView2.TabIndex = 1
        '
        'Panel18
        '
        Me.Panel18.Controls.Add(Me.Label6)
        Me.Panel18.Controls.Add(Me.ComboBox3)
        Me.Panel18.Dock = System.Windows.Forms.DockStyle.Top
        Me.Panel18.Location = New System.Drawing.Point(0, 0)
        Me.Panel18.Name = "Panel18"
        Me.Panel18.Size = New System.Drawing.Size(224, 40)
        Me.Panel18.TabIndex = 0
        '
        'Label6
        '
        Me.Label6.Location = New System.Drawing.Point(0, 16)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(64, 16)
        Me.Label6.TabIndex = 0
        Me.Label6.Text = "Catagory B"
        '
        'ComboBox3
        '
        Me.ComboBox3.AccessibleDescription = "Catagory B"
        Me.ComboBox3.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBox3.ItemHeight = 13
        Me.ComboBox3.Items.AddRange(New Object() {"1-New Comming", "2-Children's Books", "3-Entertainment", "4-Computers & Internet", "5-Religion & Spirituality", "6-Outdoors & Nature", "7-Law", "8-History", "9-Health, Mind & Body"})
        Me.ComboBox3.Location = New System.Drawing.Point(64, 14)
        Me.ComboBox3.MaxDropDownItems = 10
        Me.ComboBox3.Name = "ComboBox3"
        Me.ComboBox3.Size = New System.Drawing.Size(160, 21)
        Me.ComboBox3.TabIndex = 1
        '
        'Panel19
        '
        Me.Panel19.Controls.Add(Me.Button3)
        Me.Panel19.Controls.Add(Me.Button4)
        Me.Panel19.Controls.Add(Me.Button10)
        Me.Panel19.Controls.Add(Me.Button11)
        Me.Panel19.Dock = System.Windows.Forms.DockStyle.Bottom
        Me.Panel19.Location = New System.Drawing.Point(0, 402)
        Me.Panel19.Name = "Panel19"
        Me.Panel19.Size = New System.Drawing.Size(224, 56)
        Me.Panel19.TabIndex = 2
        '
        'Button3
        '
        Me.Button3.Location = New System.Drawing.Point(56, 12)
        Me.Button3.Name = "Button3"
        Me.Button3.Size = New System.Drawing.Size(56, 32)
        Me.Button3.TabIndex = 1
        Me.Button3.Text = "Remove"
        '
        'Button4
        '
        Me.Button4.Location = New System.Drawing.Point(0, 12)
        Me.Button4.Name = "Button4"
        Me.Button4.Size = New System.Drawing.Size(56, 32)
        Me.Button4.TabIndex = 0
        Me.Button4.Text = "Refresh"
        '
        'Button10
        '
        Me.Button10.Location = New System.Drawing.Point(168, 12)
        Me.Button10.Name = "Button10"
        Me.Button10.Size = New System.Drawing.Size(56, 32)
        Me.Button10.TabIndex = 3
        Me.Button10.Text = "Down"
        '
        'Button11
        '
        Me.Button11.Location = New System.Drawing.Point(112, 12)
        Me.Button11.Name = "Button11"
        Me.Button11.Size = New System.Drawing.Size(56, 32)
        Me.Button11.TabIndex = 2
        Me.Button11.Text = "Up"
        '
        'ExpTree1
        '
        Me.ExpTree1.Dock = System.Windows.Forms.DockStyle.Fill
        Me.ExpTree1.Location = New System.Drawing.Point(0, 40)
        Me.ExpTree1.Name = "ExpTree1"
        Me.ExpTree1.Size = New System.Drawing.Size(290, 362)
        Me.ExpTree1.StartUpDirectory = TAB.Telephony.exploreTreeViewDll.ExpTree.StartDir.Desktop
        Me.ExpTree1.TabIndex = 1
        '
        'FrmUpload
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 13)
        Me.ClientSize = New System.Drawing.Size(888, 685)
        Me.Controls.Add(Me.Panel1)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.StatusBar1)
        Me.Menu = Me.MainMenu1
        Me.Name = "FrmUpload"
        Me.Text = "DAISY 3 - Digital Talking Book Uploader."
        Me.WindowState = System.Windows.Forms.FormWindowState.Maximized
        Me.GroupBox2.ResumeLayout(False)
        Me.Panel22.ResumeLayout(False)
        Me.Panel31.ResumeLayout(False)
        Me.Panel32.ResumeLayout(False)
        CType(Me.DataGrid2, System.ComponentModel.ISupportInitialize).EndInit()
        Me.Panel1.ResumeLayout(False)
        Me.GroupBox1.ResumeLayout(False)
        Me.Panel2.ResumeLayout(False)
        Me.Panel21.ResumeLayout(False)
        Me.Panel23.ResumeLayout(False)
        Me.Panel4.ResumeLayout(False)
        Me.Panel7.ResumeLayout(False)
        Me.Panel6.ResumeLayout(False)
        Me.Panel8.ResumeLayout(False)
        Me.Panel10.ResumeLayout(False)
        Me.Panel5.ResumeLayout(False)
        Me.Panel3.ResumeLayout(False)
        Me.Panel18.ResumeLayout(False)
        Me.Panel19.ResumeLayout(False)
        Me.ResumeLayout(False)

    End Sub

#End Region

    Private Sub FrmUpload_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        'declare the string array to hold drive names
        Dim drives() As String
        'load drives string array by retrieving all the logical drives names
        'Directory.GetLogicalDrives will retrive all the logical drives names and return to the array
        drives = System.IO.Directory.GetLogicalDrives

        'for enumeration of array declaring 
        'variable to hold name
        Dim adrive As String
        'clearing the combobox.items collection
        ComboBox1.Items.Clear()
        'loading drives in combobox 
        For Each adrive In drives
            ComboBox1.Items.Add(adrive)
        Next

        'Set Default Combobox
        Me.ComboBox1.SelectedIndex = 0
        Me.ComboBox2.SelectedIndex = 0
        Me.ComboBox3.SelectedIndex = 0

    End Sub



    Private Sub Button8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button8.Click
        'Dim mySpeech As ISpVoice


        'Dim v As SpVoice
        'v = New SpVoice
        ''Speak literal text


        ''Speak with/without punctuation
        'v.Speak("one, two, three!", SpeechVoiceSpeakFlags.SVSFlagsAsync)
        'v.Speak("one, two, three!", SpeechVoiceSpeakFlags.SVSFNLPSpeakPunc + SpeechVoiceSpeakFlags.SVSFlagsAsync)

        ''Speak text with/without XML tags
        'v.Speak("text with XML", SpeechVoiceSpeakFlags.SVSFIsXML + SpeechVoiceSpeakFlags.SVSFlagsAsync)
        'v.Speak("text with XML", SpeechVoiceSpeakFlags.SVSFIsNotXML + SpeechVoiceSpeakFlags.SVSFlagsAsync)
        Dim V As SpeechLib.SpVoice
        Dim T As SpeechLib.ISpeechObjectToken
        Dim strVoice As String

        V = New SpVoice

        'Get each token in the collection returned by GetVoices
        strVoice = ""
        For Each T In V.GetVoices
            strVoice = strVoice & "   " & T.GetDescription     'The token's name

        Next
        'MsgBox(strVoice)
    End Sub

    Private Sub MenuItem8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem8.Click
        End
    End Sub

    Private Sub MenuItem7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem7.Click
        Me.Close()
    End Sub
End Class
