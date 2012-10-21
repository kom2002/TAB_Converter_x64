Imports System
Imports System.IO
Imports System.Data
Imports System.Threading
Imports Microsoft.Win32

Public Class FrmConvert
    Inherits System.Windows.Forms.Form
    Public Declare Sub InitCommonControls Lib "comctl32.dll" ()

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
    Friend WithEvents Panel1 As System.Windows.Forms.Panel
    Friend WithEvents Panel3 As System.Windows.Forms.Panel
    Friend WithEvents Label01 As System.Windows.Forms.Label
    Friend WithEvents Panel5 As System.Windows.Forms.Panel
    Friend WithEvents Panel2 As System.Windows.Forms.Panel
    Friend WithEvents Panel6 As System.Windows.Forms.Panel
    Friend WithEvents Panel7 As System.Windows.Forms.Panel
    Friend WithEvents Panel8 As System.Windows.Forms.Panel
    Friend WithEvents Panel9 As System.Windows.Forms.Panel
    Friend WithEvents Panel13 As System.Windows.Forms.Panel
    Friend WithEvents Panel14 As System.Windows.Forms.Panel
    Friend WithEvents Panel15 As System.Windows.Forms.Panel
    Friend WithEvents Panel16 As System.Windows.Forms.Panel
    Friend WithEvents Panel4 As System.Windows.Forms.Panel
    Friend WithEvents Panel10 As System.Windows.Forms.Panel
    Friend WithEvents Panel11 As System.Windows.Forms.Panel
    Friend WithEvents Panel12 As System.Windows.Forms.Panel
    Friend WithEvents Label03 As System.Windows.Forms.Label
    Friend WithEvents Label04 As System.Windows.Forms.Label
    Friend WithEvents Panel21 As System.Windows.Forms.Panel
    Friend WithEvents Panel23 As System.Windows.Forms.Panel
    Friend WithEvents Panel24 As System.Windows.Forms.Panel
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents Panel25 As System.Windows.Forms.Panel
    Friend WithEvents Panel27 As System.Windows.Forms.Panel
    Friend WithEvents Panel28 As System.Windows.Forms.Panel
    Friend WithEvents Panel18 As System.Windows.Forms.Panel
    Friend WithEvents Button10 As System.Windows.Forms.Button
    Friend WithEvents FolderBrowserDialog1 As System.Windows.Forms.FolderBrowserDialog
    Friend WithEvents OpenFileDialog1 As System.Windows.Forms.OpenFileDialog
    Friend WithEvents Button01 As System.Windows.Forms.Button
    Friend WithEvents Button02 As System.Windows.Forms.Button
    Friend WithEvents Button04 As System.Windows.Forms.Button
    Friend WithEvents Button03 As System.Windows.Forms.Button
    Friend WithEvents Button05 As System.Windows.Forms.Button
    Friend WithEvents Button06 As System.Windows.Forms.Button
    Friend WithEvents Button15 As System.Windows.Forms.Button
    Friend WithEvents Button13 As System.Windows.Forms.Button
    Friend WithEvents Button07 As System.Windows.Forms.Button
    Friend WithEvents Button08 As System.Windows.Forms.Button
    Friend WithEvents Button09 As System.Windows.Forms.Button
    Friend WithEvents Label02 As System.Windows.Forms.Label
    Friend WithEvents DataSet1 As System.Data.DataSet
    Friend WithEvents DataTable1 As System.Data.DataTable
    Friend WithEvents DataColumn1 As System.Data.DataColumn
    Friend WithEvents DataColumn2 As System.Data.DataColumn
    Friend WithEvents DataColumn3 As System.Data.DataColumn
    Friend WithEvents DataColumn4 As System.Data.DataColumn
    Friend WithEvents Panel17 As System.Windows.Forms.Panel
    Friend WithEvents Panel20 As System.Windows.Forms.Panel
    Friend WithEvents Panel19 As System.Windows.Forms.Panel
    Friend WithEvents TxtDestFolder As System.Windows.Forms.TextBox
    Friend WithEvents ComboBox1 As System.Windows.Forms.ComboBox
    Friend WithEvents DataColumn5 As System.Data.DataColumn
    Friend WithEvents OpenXML As System.Windows.Forms.OpenFileDialog
    Friend WithEvents SaveXML As System.Windows.Forms.SaveFileDialog
    Friend WithEvents MainMenu1 As System.Windows.Forms.MainMenu
    Friend WithEvents MenuItem1 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem2 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem3 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem4 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem5 As System.Windows.Forms.MenuItem
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
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Panel26 As System.Windows.Forms.Panel
    Friend WithEvents Panel33 As System.Windows.Forms.Panel
    Friend WithEvents Panel34 As System.Windows.Forms.Panel
    Friend WithEvents Panel35 As System.Windows.Forms.Panel
    Friend WithEvents ComboBox2 As System.Windows.Forms.ComboBox
    Friend WithEvents TxtNccName As System.Windows.Forms.TextBox
    Friend WithEvents DataColumn6 As System.Data.DataColumn
    Friend WithEvents MenuItem28 As System.Windows.Forms.MenuItem
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Public WithEvents DataGrid1 As System.Windows.Forms.DataGrid
    Public WithEvents Button12 As System.Windows.Forms.Button
    Friend WithEvents FileTimer As System.Windows.Forms.Timer
    Friend WithEvents TextBox1 As System.Windows.Forms.TextBox
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
    Friend WithEvents Panel29 As System.Windows.Forms.Panel
    Friend WithEvents Label11 As System.Windows.Forms.Label
    Friend WithEvents LblCurrDtbCompleted As System.Windows.Forms.Label
    Friend WithEvents Panel30 As System.Windows.Forms.Panel
    Friend WithEvents PgbCurrDtbCompleted As System.Windows.Forms.ProgressBar
    Friend WithEvents Panel31 As System.Windows.Forms.Panel
    Friend WithEvents Label12 As System.Windows.Forms.Label
    Friend WithEvents LblAllDtbCompleted As System.Windows.Forms.Label
    Friend WithEvents Panel32 As System.Windows.Forms.Panel
    Friend WithEvents PgbAllDtbCompleted As System.Windows.Forms.ProgressBar
    Friend WithEvents MenuItem29 As System.Windows.Forms.MenuItem
    Friend WithEvents Button14 As System.Windows.Forms.Button
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents Button3 As System.Windows.Forms.Button
    Friend WithEvents Button4 As System.Windows.Forms.Button
    Friend WithEvents Button5 As System.Windows.Forms.Button
    Friend WithEvents Button6 As System.Windows.Forms.Button
    Friend WithEvents MenuItem30 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem31 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem32 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem33 As System.Windows.Forms.MenuItem
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(FrmConvert))
        Me.Panel1 = New System.Windows.Forms.Panel()
        Me.Panel2 = New System.Windows.Forms.Panel()
        Me.Panel26 = New System.Windows.Forms.Panel()
        Me.Panel33 = New System.Windows.Forms.Panel()
        Me.Panel34 = New System.Windows.Forms.Panel()
        Me.TxtNccName = New System.Windows.Forms.TextBox()
        Me.Panel35 = New System.Windows.Forms.Panel()
        Me.ComboBox2 = New System.Windows.Forms.ComboBox()
        Me.Panel5 = New System.Windows.Forms.Panel()
        Me.Label01 = New System.Windows.Forms.Label()
        Me.Panel3 = New System.Windows.Forms.Panel()
        Me.Button01 = New System.Windows.Forms.Button()
        Me.Panel6 = New System.Windows.Forms.Panel()
        Me.Panel7 = New System.Windows.Forms.Panel()
        Me.Panel17 = New System.Windows.Forms.Panel()
        Me.Panel20 = New System.Windows.Forms.Panel()
        Me.TxtDestFolder = New System.Windows.Forms.TextBox()
        Me.Panel19 = New System.Windows.Forms.Panel()
        Me.ComboBox1 = New System.Windows.Forms.ComboBox()
        Me.Panel8 = New System.Windows.Forms.Panel()
        Me.Label02 = New System.Windows.Forms.Label()
        Me.Panel9 = New System.Windows.Forms.Panel()
        Me.Button02 = New System.Windows.Forms.Button()
        Me.Panel13 = New System.Windows.Forms.Panel()
        Me.Panel14 = New System.Windows.Forms.Panel()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Button04 = New System.Windows.Forms.Button()
        Me.Button03 = New System.Windows.Forms.Button()
        Me.Button05 = New System.Windows.Forms.Button()
        Me.Button06 = New System.Windows.Forms.Button()
        Me.Panel15 = New System.Windows.Forms.Panel()
        Me.Panel16 = New System.Windows.Forms.Panel()
        Me.Panel4 = New System.Windows.Forms.Panel()
        Me.Panel10 = New System.Windows.Forms.Panel()
        Me.DataGrid1 = New System.Windows.Forms.DataGrid()
        Me.DataTable1 = New System.Data.DataTable()
        Me.DataColumn1 = New System.Data.DataColumn()
        Me.DataColumn2 = New System.Data.DataColumn()
        Me.DataColumn3 = New System.Data.DataColumn()
        Me.DataColumn4 = New System.Data.DataColumn()
        Me.DataColumn5 = New System.Data.DataColumn()
        Me.DataColumn6 = New System.Data.DataColumn()
        Me.Panel11 = New System.Windows.Forms.Panel()
        Me.Label04 = New System.Windows.Forms.Label()
        Me.Label03 = New System.Windows.Forms.Label()
        Me.Panel12 = New System.Windows.Forms.Panel()
        Me.Button07 = New System.Windows.Forms.Button()
        Me.Button08 = New System.Windows.Forms.Button()
        Me.Button09 = New System.Windows.Forms.Button()
        Me.Panel21 = New System.Windows.Forms.Panel()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox()
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
        Me.Panel29 = New System.Windows.Forms.Panel()
        Me.Label11 = New System.Windows.Forms.Label()
        Me.LblCurrDtbCompleted = New System.Windows.Forms.Label()
        Me.Panel30 = New System.Windows.Forms.Panel()
        Me.PgbCurrDtbCompleted = New System.Windows.Forms.ProgressBar()
        Me.Panel31 = New System.Windows.Forms.Panel()
        Me.Label12 = New System.Windows.Forms.Label()
        Me.LblAllDtbCompleted = New System.Windows.Forms.Label()
        Me.Panel32 = New System.Windows.Forms.Panel()
        Me.PgbAllDtbCompleted = New System.Windows.Forms.ProgressBar()
        Me.TextBox1 = New System.Windows.Forms.TextBox()
        Me.Panel23 = New System.Windows.Forms.Panel()
        Me.Panel24 = New System.Windows.Forms.Panel()
        Me.Button6 = New System.Windows.Forms.Button()
        Me.Button5 = New System.Windows.Forms.Button()
        Me.Button4 = New System.Windows.Forms.Button()
        Me.Button3 = New System.Windows.Forms.Button()
        Me.Button2 = New System.Windows.Forms.Button()
        Me.Button14 = New System.Windows.Forms.Button()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.Button15 = New System.Windows.Forms.Button()
        Me.Panel25 = New System.Windows.Forms.Panel()
        Me.Panel18 = New System.Windows.Forms.Panel()
        Me.Button10 = New System.Windows.Forms.Button()
        Me.Button12 = New System.Windows.Forms.Button()
        Me.Button13 = New System.Windows.Forms.Button()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Panel27 = New System.Windows.Forms.Panel()
        Me.Panel28 = New System.Windows.Forms.Panel()
        Me.FolderBrowserDialog1 = New System.Windows.Forms.FolderBrowserDialog()
        Me.OpenFileDialog1 = New System.Windows.Forms.OpenFileDialog()
        Me.DataSet1 = New System.Data.DataSet()
        Me.OpenXML = New System.Windows.Forms.OpenFileDialog()
        Me.SaveXML = New System.Windows.Forms.SaveFileDialog()
        Me.MainMenu1 = New System.Windows.Forms.MainMenu(Me.components)
        Me.MenuItem1 = New System.Windows.Forms.MenuItem()
        Me.MenuItem2 = New System.Windows.Forms.MenuItem()
        Me.MenuItem3 = New System.Windows.Forms.MenuItem()
        Me.MenuItem6 = New System.Windows.Forms.MenuItem()
        Me.MenuItem7 = New System.Windows.Forms.MenuItem()
        Me.MenuItem29 = New System.Windows.Forms.MenuItem()
        Me.MenuItem30 = New System.Windows.Forms.MenuItem()
        Me.MenuItem32 = New System.Windows.Forms.MenuItem()
        Me.MenuItem33 = New System.Windows.Forms.MenuItem()
        Me.MenuItem31 = New System.Windows.Forms.MenuItem()
        Me.MenuItem21 = New System.Windows.Forms.MenuItem()
        Me.MenuItem4 = New System.Windows.Forms.MenuItem()
        Me.MenuItem5 = New System.Windows.Forms.MenuItem()
        Me.MenuItem8 = New System.Windows.Forms.MenuItem()
        Me.MenuItem28 = New System.Windows.Forms.MenuItem()
        Me.MenuItem9 = New System.Windows.Forms.MenuItem()
        Me.MenuItem10 = New System.Windows.Forms.MenuItem()
        Me.MenuItem11 = New System.Windows.Forms.MenuItem()
        Me.MenuItem12 = New System.Windows.Forms.MenuItem()
        Me.MenuItem15 = New System.Windows.Forms.MenuItem()
        Me.MenuItem13 = New System.Windows.Forms.MenuItem()
        Me.MenuItem14 = New System.Windows.Forms.MenuItem()
        Me.MenuItem16 = New System.Windows.Forms.MenuItem()
        Me.MenuItem17 = New System.Windows.Forms.MenuItem()
        Me.MenuItem18 = New System.Windows.Forms.MenuItem()
        Me.MenuItem19 = New System.Windows.Forms.MenuItem()
        Me.MenuItem20 = New System.Windows.Forms.MenuItem()
        Me.MenuItem26 = New System.Windows.Forms.MenuItem()
        Me.MenuItem27 = New System.Windows.Forms.MenuItem()
        Me.MenuItem22 = New System.Windows.Forms.MenuItem()
        Me.MenuItem23 = New System.Windows.Forms.MenuItem()
        Me.MenuItem24 = New System.Windows.Forms.MenuItem()
        Me.MenuItem25 = New System.Windows.Forms.MenuItem()
        Me.FileTimer = New System.Windows.Forms.Timer(Me.components)
        Me.Panel1.SuspendLayout()
        Me.Panel2.SuspendLayout()
        Me.Panel26.SuspendLayout()
        Me.Panel33.SuspendLayout()
        Me.Panel34.SuspendLayout()
        Me.Panel35.SuspendLayout()
        Me.Panel5.SuspendLayout()
        Me.Panel3.SuspendLayout()
        Me.Panel6.SuspendLayout()
        Me.Panel7.SuspendLayout()
        Me.Panel17.SuspendLayout()
        Me.Panel20.SuspendLayout()
        Me.Panel19.SuspendLayout()
        Me.Panel8.SuspendLayout()
        Me.Panel9.SuspendLayout()
        Me.Panel13.SuspendLayout()
        Me.Panel14.SuspendLayout()
        Me.Panel4.SuspendLayout()
        Me.Panel10.SuspendLayout()
        CType(Me.DataGrid1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.DataTable1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.Panel11.SuspendLayout()
        Me.Panel12.SuspendLayout()
        Me.Panel21.SuspendLayout()
        Me.GroupBox1.SuspendLayout()
        Me.Panel22.SuspendLayout()
        Me.Panel29.SuspendLayout()
        Me.Panel30.SuspendLayout()
        Me.Panel31.SuspendLayout()
        Me.Panel32.SuspendLayout()
        Me.Panel24.SuspendLayout()
        Me.Panel25.SuspendLayout()
        Me.Panel18.SuspendLayout()
        CType(Me.DataSet1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'Panel1
        '
        resources.ApplyResources(Me.Panel1, "Panel1")
        Me.Panel1.Controls.Add(Me.Panel2)
        Me.Panel1.Controls.Add(Me.Panel5)
        Me.Panel1.Controls.Add(Me.Panel3)
        Me.Panel1.Name = "Panel1"
        '
        'Panel2
        '
        resources.ApplyResources(Me.Panel2, "Panel2")
        Me.Panel2.BackColor = System.Drawing.SystemColors.Control
        Me.Panel2.Controls.Add(Me.Panel26)
        Me.Panel2.Name = "Panel2"
        '
        'Panel26
        '
        resources.ApplyResources(Me.Panel26, "Panel26")
        Me.Panel26.BackColor = System.Drawing.SystemColors.Control
        Me.Panel26.Controls.Add(Me.Panel33)
        Me.Panel26.Name = "Panel26"
        '
        'Panel33
        '
        resources.ApplyResources(Me.Panel33, "Panel33")
        Me.Panel33.BackColor = System.Drawing.SystemColors.Control
        Me.Panel33.Controls.Add(Me.Panel34)
        Me.Panel33.Controls.Add(Me.Panel35)
        Me.Panel33.Name = "Panel33"
        '
        'Panel34
        '
        resources.ApplyResources(Me.Panel34, "Panel34")
        Me.Panel34.BackColor = System.Drawing.SystemColors.Control
        Me.Panel34.Controls.Add(Me.TxtNccName)
        Me.Panel34.Name = "Panel34"
        '
        'TxtNccName
        '
        resources.ApplyResources(Me.TxtNccName, "TxtNccName")
        Me.TxtNccName.BackColor = System.Drawing.SystemColors.Info
        Me.TxtNccName.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.TxtNccName.Name = "TxtNccName"
        '
        'Panel35
        '
        resources.ApplyResources(Me.Panel35, "Panel35")
        Me.Panel35.BackColor = System.Drawing.SystemColors.Control
        Me.Panel35.Controls.Add(Me.ComboBox2)
        Me.Panel35.Name = "Panel35"
        '
        'ComboBox2
        '
        resources.ApplyResources(Me.ComboBox2, "ComboBox2")
        Me.ComboBox2.BackColor = System.Drawing.SystemColors.Info
        Me.ComboBox2.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBox2.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.ComboBox2.Name = "ComboBox2"
        '
        'Panel5
        '
        resources.ApplyResources(Me.Panel5, "Panel5")
        Me.Panel5.Controls.Add(Me.Label01)
        Me.Panel5.Name = "Panel5"
        '
        'Label01
        '
        resources.ApplyResources(Me.Label01, "Label01")
        Me.Label01.Name = "Label01"
        '
        'Panel3
        '
        resources.ApplyResources(Me.Panel3, "Panel3")
        Me.Panel3.Controls.Add(Me.Button01)
        Me.Panel3.Name = "Panel3"
        '
        'Button01
        '
        resources.ApplyResources(Me.Button01, "Button01")
        Me.Button01.Name = "Button01"
        '
        'Panel6
        '
        resources.ApplyResources(Me.Panel6, "Panel6")
        Me.Panel6.Controls.Add(Me.Panel7)
        Me.Panel6.Controls.Add(Me.Panel8)
        Me.Panel6.Controls.Add(Me.Panel9)
        Me.Panel6.Name = "Panel6"
        '
        'Panel7
        '
        resources.ApplyResources(Me.Panel7, "Panel7")
        Me.Panel7.BackColor = System.Drawing.SystemColors.Control
        Me.Panel7.Controls.Add(Me.Panel17)
        Me.Panel7.Name = "Panel7"
        '
        'Panel17
        '
        resources.ApplyResources(Me.Panel17, "Panel17")
        Me.Panel17.BackColor = System.Drawing.SystemColors.Control
        Me.Panel17.Controls.Add(Me.Panel20)
        Me.Panel17.Controls.Add(Me.Panel19)
        Me.Panel17.Name = "Panel17"
        '
        'Panel20
        '
        resources.ApplyResources(Me.Panel20, "Panel20")
        Me.Panel20.BackColor = System.Drawing.SystemColors.Control
        Me.Panel20.Controls.Add(Me.TxtDestFolder)
        Me.Panel20.Name = "Panel20"
        '
        'TxtDestFolder
        '
        resources.ApplyResources(Me.TxtDestFolder, "TxtDestFolder")
        Me.TxtDestFolder.BackColor = System.Drawing.SystemColors.Info
        Me.TxtDestFolder.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.TxtDestFolder.Name = "TxtDestFolder"
        '
        'Panel19
        '
        resources.ApplyResources(Me.Panel19, "Panel19")
        Me.Panel19.BackColor = System.Drawing.SystemColors.Control
        Me.Panel19.Controls.Add(Me.ComboBox1)
        Me.Panel19.Name = "Panel19"
        '
        'ComboBox1
        '
        resources.ApplyResources(Me.ComboBox1, "ComboBox1")
        Me.ComboBox1.BackColor = System.Drawing.SystemColors.Info
        Me.ComboBox1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBox1.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.ComboBox1.Items.AddRange(New Object() {resources.GetString("ComboBox1.Items"), resources.GetString("ComboBox1.Items1")})
        Me.ComboBox1.Name = "ComboBox1"
        '
        'Panel8
        '
        resources.ApplyResources(Me.Panel8, "Panel8")
        Me.Panel8.Controls.Add(Me.Label02)
        Me.Panel8.Name = "Panel8"
        '
        'Label02
        '
        resources.ApplyResources(Me.Label02, "Label02")
        Me.Label02.Name = "Label02"
        '
        'Panel9
        '
        resources.ApplyResources(Me.Panel9, "Panel9")
        Me.Panel9.Controls.Add(Me.Button02)
        Me.Panel9.Name = "Panel9"
        '
        'Button02
        '
        resources.ApplyResources(Me.Button02, "Button02")
        Me.Button02.Name = "Button02"
        '
        'Panel13
        '
        resources.ApplyResources(Me.Panel13, "Panel13")
        Me.Panel13.Controls.Add(Me.Panel14)
        Me.Panel13.Controls.Add(Me.Panel15)
        Me.Panel13.Controls.Add(Me.Panel16)
        Me.Panel13.Name = "Panel13"
        '
        'Panel14
        '
        resources.ApplyResources(Me.Panel14, "Panel14")
        Me.Panel14.BackColor = System.Drawing.SystemColors.Control
        Me.Panel14.Controls.Add(Me.Label2)
        Me.Panel14.Controls.Add(Me.Button04)
        Me.Panel14.Controls.Add(Me.Button03)
        Me.Panel14.Controls.Add(Me.Button05)
        Me.Panel14.Controls.Add(Me.Button06)
        Me.Panel14.Name = "Panel14"
        '
        'Label2
        '
        resources.ApplyResources(Me.Label2, "Label2")
        Me.Label2.ForeColor = System.Drawing.Color.Blue
        Me.Label2.Name = "Label2"
        '
        'Button04
        '
        resources.ApplyResources(Me.Button04, "Button04")
        Me.Button04.Name = "Button04"
        '
        'Button03
        '
        resources.ApplyResources(Me.Button03, "Button03")
        Me.Button03.Name = "Button03"
        '
        'Button05
        '
        resources.ApplyResources(Me.Button05, "Button05")
        Me.Button05.Name = "Button05"
        '
        'Button06
        '
        resources.ApplyResources(Me.Button06, "Button06")
        Me.Button06.Name = "Button06"
        '
        'Panel15
        '
        resources.ApplyResources(Me.Panel15, "Panel15")
        Me.Panel15.Name = "Panel15"
        '
        'Panel16
        '
        resources.ApplyResources(Me.Panel16, "Panel16")
        Me.Panel16.Name = "Panel16"
        '
        'Panel4
        '
        resources.ApplyResources(Me.Panel4, "Panel4")
        Me.Panel4.Controls.Add(Me.Panel10)
        Me.Panel4.Controls.Add(Me.Panel11)
        Me.Panel4.Controls.Add(Me.Panel12)
        Me.Panel4.Name = "Panel4"
        '
        'Panel10
        '
        resources.ApplyResources(Me.Panel10, "Panel10")
        Me.Panel10.BackColor = System.Drawing.SystemColors.Control
        Me.Panel10.Controls.Add(Me.DataGrid1)
        Me.Panel10.Name = "Panel10"
        '
        'DataGrid1
        '
        resources.ApplyResources(Me.DataGrid1, "DataGrid1")
        Me.DataGrid1.AccessibleRole = System.Windows.Forms.AccessibleRole.Table
        Me.DataGrid1.AllowNavigation = False
        Me.DataGrid1.CaptionVisible = False
        Me.DataGrid1.CausesValidation = False
        Me.DataGrid1.DataMember = ""
        Me.DataGrid1.DataSource = Me.DataTable1
        Me.DataGrid1.GridLineColor = System.Drawing.SystemColors.ControlDark
        Me.DataGrid1.HeaderForeColor = System.Drawing.SystemColors.ControlText
        Me.DataGrid1.Name = "DataGrid1"
        Me.DataGrid1.ParentRowsBackColor = System.Drawing.SystemColors.ActiveCaptionText
        Me.DataGrid1.ParentRowsVisible = False
        Me.DataGrid1.PreferredColumnWidth = 70
        Me.DataGrid1.ReadOnly = True
        Me.DataGrid1.RowHeaderWidth = 30
        '
        'DataTable1
        '
        Me.DataTable1.Columns.AddRange(New System.Data.DataColumn() {Me.DataColumn1, Me.DataColumn2, Me.DataColumn3, Me.DataColumn4, Me.DataColumn5, Me.DataColumn6})
        Me.DataTable1.Constraints.AddRange(New System.Data.Constraint() {New System.Data.UniqueConstraint("Constraint1", New String() {"Destination Path"}, True)})
        Me.DataTable1.MinimumCapacity = 100
        Me.DataTable1.PrimaryKey = New System.Data.DataColumn() {Me.DataColumn4}
        Me.DataTable1.TableName = "Table1"
        '
        'DataColumn1
        '
        Me.DataColumn1.ColumnName = "Navigation Control File Path"
        '
        'DataColumn2
        '
        Me.DataColumn2.ColumnName = "Convertion Result"
        '
        'DataColumn3
        '
        Me.DataColumn3.ColumnName = "DTB Version"
        '
        'DataColumn4
        '
        Me.DataColumn4.AllowDBNull = False
        Me.DataColumn4.ColumnName = "Destination Path"
        '
        'DataColumn5
        '
        Me.DataColumn5.ColumnName = "Final Audio Format"
        '
        'DataColumn6
        '
        Me.DataColumn6.ColumnName = "Speech Engine"
        '
        'Panel11
        '
        resources.ApplyResources(Me.Panel11, "Panel11")
        Me.Panel11.Controls.Add(Me.Label04)
        Me.Panel11.Controls.Add(Me.Label03)
        Me.Panel11.Name = "Panel11"
        '
        'Label04
        '
        resources.ApplyResources(Me.Label04, "Label04")
        Me.Label04.Name = "Label04"
        '
        'Label03
        '
        resources.ApplyResources(Me.Label03, "Label03")
        Me.Label03.Name = "Label03"
        '
        'Panel12
        '
        resources.ApplyResources(Me.Panel12, "Panel12")
        Me.Panel12.Controls.Add(Me.Button07)
        Me.Panel12.Controls.Add(Me.Button08)
        Me.Panel12.Controls.Add(Me.Button09)
        Me.Panel12.Name = "Panel12"
        '
        'Button07
        '
        resources.ApplyResources(Me.Button07, "Button07")
        Me.Button07.Name = "Button07"
        '
        'Button08
        '
        resources.ApplyResources(Me.Button08, "Button08")
        Me.Button08.Name = "Button08"
        '
        'Button09
        '
        resources.ApplyResources(Me.Button09, "Button09")
        Me.Button09.Name = "Button09"
        '
        'Panel21
        '
        resources.ApplyResources(Me.Panel21, "Panel21")
        Me.Panel21.Controls.Add(Me.GroupBox1)
        Me.Panel21.Controls.Add(Me.Panel23)
        Me.Panel21.Controls.Add(Me.Panel24)
        Me.Panel21.Name = "Panel21"
        '
        'GroupBox1
        '
        resources.ApplyResources(Me.GroupBox1, "GroupBox1")
        Me.GroupBox1.Controls.Add(Me.Panel22)
        Me.GroupBox1.Controls.Add(Me.Panel29)
        Me.GroupBox1.Controls.Add(Me.Panel30)
        Me.GroupBox1.Controls.Add(Me.Panel31)
        Me.GroupBox1.Controls.Add(Me.Panel32)
        Me.GroupBox1.Controls.Add(Me.TextBox1)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.TabStop = False
        '
        'Panel22
        '
        resources.ApplyResources(Me.Panel22, "Panel22")
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
        Me.Panel22.Name = "Panel22"
        '
        'LblFileTime
        '
        resources.ApplyResources(Me.LblFileTime, "LblFileTime")
        Me.LblFileTime.Name = "LblFileTime"
        '
        'LblDtbTime
        '
        resources.ApplyResources(Me.LblDtbTime, "LblDtbTime")
        Me.LblDtbTime.Name = "LblDtbTime"
        '
        'LblFileStatus
        '
        resources.ApplyResources(Me.LblFileStatus, "LblFileStatus")
        Me.LblFileStatus.Name = "LblFileStatus"
        '
        'LblDtbStatus
        '
        resources.ApplyResources(Me.LblDtbStatus, "LblDtbStatus")
        Me.LblDtbStatus.Name = "LblDtbStatus"
        '
        'Label07
        '
        resources.ApplyResources(Me.Label07, "Label07")
        Me.Label07.Name = "Label07"
        '
        'Label10
        '
        resources.ApplyResources(Me.Label10, "Label10")
        Me.Label10.Name = "Label10"
        '
        'Label09
        '
        resources.ApplyResources(Me.Label09, "Label09")
        Me.Label09.Name = "Label09"
        '
        'Label06
        '
        resources.ApplyResources(Me.Label06, "Label06")
        Me.Label06.Name = "Label06"
        '
        'LblDtbName
        '
        resources.ApplyResources(Me.LblDtbName, "LblDtbName")
        Me.LblDtbName.BackColor = System.Drawing.SystemColors.Control
        Me.LblDtbName.Name = "LblDtbName"
        '
        'LblFileName
        '
        resources.ApplyResources(Me.LblFileName, "LblFileName")
        Me.LblFileName.BackColor = System.Drawing.SystemColors.Control
        Me.LblFileName.Name = "LblFileName"
        '
        'Label05
        '
        resources.ApplyResources(Me.Label05, "Label05")
        Me.Label05.Name = "Label05"
        '
        'Label08
        '
        resources.ApplyResources(Me.Label08, "Label08")
        Me.Label08.Name = "Label08"
        '
        'Panel29
        '
        resources.ApplyResources(Me.Panel29, "Panel29")
        Me.Panel29.Controls.Add(Me.Label11)
        Me.Panel29.Controls.Add(Me.LblCurrDtbCompleted)
        Me.Panel29.Name = "Panel29"
        '
        'Label11
        '
        resources.ApplyResources(Me.Label11, "Label11")
        Me.Label11.Name = "Label11"
        '
        'LblCurrDtbCompleted
        '
        resources.ApplyResources(Me.LblCurrDtbCompleted, "LblCurrDtbCompleted")
        Me.LblCurrDtbCompleted.Name = "LblCurrDtbCompleted"
        '
        'Panel30
        '
        resources.ApplyResources(Me.Panel30, "Panel30")
        Me.Panel30.Controls.Add(Me.PgbCurrDtbCompleted)
        Me.Panel30.Name = "Panel30"
        '
        'PgbCurrDtbCompleted
        '
        resources.ApplyResources(Me.PgbCurrDtbCompleted, "PgbCurrDtbCompleted")
        Me.PgbCurrDtbCompleted.Name = "PgbCurrDtbCompleted"
        Me.PgbCurrDtbCompleted.Step = 1
        '
        'Panel31
        '
        resources.ApplyResources(Me.Panel31, "Panel31")
        Me.Panel31.Controls.Add(Me.Label12)
        Me.Panel31.Controls.Add(Me.LblAllDtbCompleted)
        Me.Panel31.Name = "Panel31"
        '
        'Label12
        '
        resources.ApplyResources(Me.Label12, "Label12")
        Me.Label12.Name = "Label12"
        '
        'LblAllDtbCompleted
        '
        resources.ApplyResources(Me.LblAllDtbCompleted, "LblAllDtbCompleted")
        Me.LblAllDtbCompleted.Name = "LblAllDtbCompleted"
        '
        'Panel32
        '
        resources.ApplyResources(Me.Panel32, "Panel32")
        Me.Panel32.Controls.Add(Me.PgbAllDtbCompleted)
        Me.Panel32.Name = "Panel32"
        '
        'PgbAllDtbCompleted
        '
        resources.ApplyResources(Me.PgbAllDtbCompleted, "PgbAllDtbCompleted")
        Me.PgbAllDtbCompleted.Name = "PgbAllDtbCompleted"
        Me.PgbAllDtbCompleted.Step = 1
        '
        'TextBox1
        '
        resources.ApplyResources(Me.TextBox1, "TextBox1")
        Me.TextBox1.Name = "TextBox1"
        '
        'Panel23
        '
        resources.ApplyResources(Me.Panel23, "Panel23")
        Me.Panel23.Name = "Panel23"
        '
        'Panel24
        '
        resources.ApplyResources(Me.Panel24, "Panel24")
        Me.Panel24.Controls.Add(Me.Button6)
        Me.Panel24.Controls.Add(Me.Button5)
        Me.Panel24.Controls.Add(Me.Button4)
        Me.Panel24.Controls.Add(Me.Button3)
        Me.Panel24.Controls.Add(Me.Button2)
        Me.Panel24.Controls.Add(Me.Button14)
        Me.Panel24.Controls.Add(Me.Button1)
        Me.Panel24.Controls.Add(Me.Button15)
        Me.Panel24.Name = "Panel24"
        '
        'Button6
        '
        resources.ApplyResources(Me.Button6, "Button6")
        Me.Button6.Name = "Button6"
        '
        'Button5
        '
        resources.ApplyResources(Me.Button5, "Button5")
        Me.Button5.Name = "Button5"
        '
        'Button4
        '
        resources.ApplyResources(Me.Button4, "Button4")
        Me.Button4.Name = "Button4"
        '
        'Button3
        '
        resources.ApplyResources(Me.Button3, "Button3")
        Me.Button3.Name = "Button3"
        '
        'Button2
        '
        resources.ApplyResources(Me.Button2, "Button2")
        Me.Button2.Name = "Button2"
        '
        'Button14
        '
        resources.ApplyResources(Me.Button14, "Button14")
        Me.Button14.Name = "Button14"
        '
        'Button1
        '
        resources.ApplyResources(Me.Button1, "Button1")
        Me.Button1.Name = "Button1"
        '
        'Button15
        '
        resources.ApplyResources(Me.Button15, "Button15")
        Me.Button15.Name = "Button15"
        '
        'Panel25
        '
        resources.ApplyResources(Me.Panel25, "Panel25")
        Me.Panel25.Controls.Add(Me.Panel18)
        Me.Panel25.Controls.Add(Me.Panel27)
        Me.Panel25.Controls.Add(Me.Panel28)
        Me.Panel25.Name = "Panel25"
        '
        'Panel18
        '
        resources.ApplyResources(Me.Panel18, "Panel18")
        Me.Panel18.BackColor = System.Drawing.SystemColors.Control
        Me.Panel18.Controls.Add(Me.Button10)
        Me.Panel18.Controls.Add(Me.Button12)
        Me.Panel18.Controls.Add(Me.Button13)
        Me.Panel18.Controls.Add(Me.Label1)
        Me.Panel18.Name = "Panel18"
        '
        'Button10
        '
        resources.ApplyResources(Me.Button10, "Button10")
        Me.Button10.Name = "Button10"
        '
        'Button12
        '
        resources.ApplyResources(Me.Button12, "Button12")
        Me.Button12.Name = "Button12"
        '
        'Button13
        '
        resources.ApplyResources(Me.Button13, "Button13")
        Me.Button13.Name = "Button13"
        '
        'Label1
        '
        resources.ApplyResources(Me.Label1, "Label1")
        Me.Label1.ForeColor = System.Drawing.Color.Blue
        Me.Label1.Name = "Label1"
        '
        'Panel27
        '
        resources.ApplyResources(Me.Panel27, "Panel27")
        Me.Panel27.Name = "Panel27"
        '
        'Panel28
        '
        resources.ApplyResources(Me.Panel28, "Panel28")
        Me.Panel28.Name = "Panel28"
        '
        'FolderBrowserDialog1
        '
        resources.ApplyResources(Me.FolderBrowserDialog1, "FolderBrowserDialog1")
        '
        'OpenFileDialog1
        '
        resources.ApplyResources(Me.OpenFileDialog1, "OpenFileDialog1")
        '
        'DataSet1
        '
        Me.DataSet1.DataSetName = "NewDataSet"
        Me.DataSet1.Locale = New System.Globalization.CultureInfo("th-TH")
        Me.DataSet1.Tables.AddRange(New System.Data.DataTable() {Me.DataTable1})
        '
        'OpenXML
        '
        resources.ApplyResources(Me.OpenXML, "OpenXML")
        '
        'SaveXML
        '
        resources.ApplyResources(Me.SaveXML, "SaveXML")
        '
        'MainMenu1
        '
        Me.MainMenu1.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem1, Me.MenuItem4, Me.MenuItem16, Me.MenuItem22})
        resources.ApplyResources(Me.MainMenu1, "MainMenu1")
        '
        'MenuItem1
        '
        resources.ApplyResources(Me.MenuItem1, "MenuItem1")
        Me.MenuItem1.Index = 0
        Me.MenuItem1.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem2, Me.MenuItem3, Me.MenuItem6, Me.MenuItem7, Me.MenuItem29, Me.MenuItem30, Me.MenuItem32, Me.MenuItem33, Me.MenuItem31, Me.MenuItem21})
        '
        'MenuItem2
        '
        resources.ApplyResources(Me.MenuItem2, "MenuItem2")
        Me.MenuItem2.Index = 0
        '
        'MenuItem3
        '
        resources.ApplyResources(Me.MenuItem3, "MenuItem3")
        Me.MenuItem3.Index = 1
        '
        'MenuItem6
        '
        resources.ApplyResources(Me.MenuItem6, "MenuItem6")
        Me.MenuItem6.Index = 2
        '
        'MenuItem7
        '
        resources.ApplyResources(Me.MenuItem7, "MenuItem7")
        Me.MenuItem7.Index = 3
        '
        'MenuItem29
        '
        resources.ApplyResources(Me.MenuItem29, "MenuItem29")
        Me.MenuItem29.Index = 4
        '
        'MenuItem30
        '
        resources.ApplyResources(Me.MenuItem30, "MenuItem30")
        Me.MenuItem30.Index = 5
        '
        'MenuItem32
        '
        resources.ApplyResources(Me.MenuItem32, "MenuItem32")
        Me.MenuItem32.Index = 6
        '
        'MenuItem33
        '
        resources.ApplyResources(Me.MenuItem33, "MenuItem33")
        Me.MenuItem33.Index = 7
        '
        'MenuItem31
        '
        resources.ApplyResources(Me.MenuItem31, "MenuItem31")
        Me.MenuItem31.Index = 8
        '
        'MenuItem21
        '
        resources.ApplyResources(Me.MenuItem21, "MenuItem21")
        Me.MenuItem21.Index = 9
        '
        'MenuItem4
        '
        resources.ApplyResources(Me.MenuItem4, "MenuItem4")
        Me.MenuItem4.Index = 1
        Me.MenuItem4.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem5, Me.MenuItem8, Me.MenuItem28, Me.MenuItem9, Me.MenuItem10, Me.MenuItem11, Me.MenuItem12, Me.MenuItem15, Me.MenuItem13, Me.MenuItem14})
        '
        'MenuItem5
        '
        resources.ApplyResources(Me.MenuItem5, "MenuItem5")
        Me.MenuItem5.Index = 0
        '
        'MenuItem8
        '
        resources.ApplyResources(Me.MenuItem8, "MenuItem8")
        Me.MenuItem8.Index = 1
        '
        'MenuItem28
        '
        resources.ApplyResources(Me.MenuItem28, "MenuItem28")
        Me.MenuItem28.Index = 2
        '
        'MenuItem9
        '
        resources.ApplyResources(Me.MenuItem9, "MenuItem9")
        Me.MenuItem9.Index = 3
        '
        'MenuItem10
        '
        resources.ApplyResources(Me.MenuItem10, "MenuItem10")
        Me.MenuItem10.Index = 4
        '
        'MenuItem11
        '
        resources.ApplyResources(Me.MenuItem11, "MenuItem11")
        Me.MenuItem11.Index = 5
        '
        'MenuItem12
        '
        resources.ApplyResources(Me.MenuItem12, "MenuItem12")
        Me.MenuItem12.Index = 6
        '
        'MenuItem15
        '
        resources.ApplyResources(Me.MenuItem15, "MenuItem15")
        Me.MenuItem15.Index = 7
        '
        'MenuItem13
        '
        resources.ApplyResources(Me.MenuItem13, "MenuItem13")
        Me.MenuItem13.Index = 8
        '
        'MenuItem14
        '
        resources.ApplyResources(Me.MenuItem14, "MenuItem14")
        Me.MenuItem14.Index = 9
        '
        'MenuItem16
        '
        resources.ApplyResources(Me.MenuItem16, "MenuItem16")
        Me.MenuItem16.Index = 2
        Me.MenuItem16.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem17, Me.MenuItem18, Me.MenuItem19, Me.MenuItem20, Me.MenuItem26, Me.MenuItem27})
        '
        'MenuItem17
        '
        resources.ApplyResources(Me.MenuItem17, "MenuItem17")
        Me.MenuItem17.Index = 0
        '
        'MenuItem18
        '
        resources.ApplyResources(Me.MenuItem18, "MenuItem18")
        Me.MenuItem18.Index = 1
        '
        'MenuItem19
        '
        resources.ApplyResources(Me.MenuItem19, "MenuItem19")
        Me.MenuItem19.Index = 2
        '
        'MenuItem20
        '
        resources.ApplyResources(Me.MenuItem20, "MenuItem20")
        Me.MenuItem20.Index = 3
        '
        'MenuItem26
        '
        resources.ApplyResources(Me.MenuItem26, "MenuItem26")
        Me.MenuItem26.Index = 4
        '
        'MenuItem27
        '
        resources.ApplyResources(Me.MenuItem27, "MenuItem27")
        Me.MenuItem27.Index = 5
        '
        'MenuItem22
        '
        resources.ApplyResources(Me.MenuItem22, "MenuItem22")
        Me.MenuItem22.Index = 3
        Me.MenuItem22.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem23, Me.MenuItem24, Me.MenuItem25})
        '
        'MenuItem23
        '
        resources.ApplyResources(Me.MenuItem23, "MenuItem23")
        Me.MenuItem23.Index = 0
        '
        'MenuItem24
        '
        resources.ApplyResources(Me.MenuItem24, "MenuItem24")
        Me.MenuItem24.Index = 1
        '
        'MenuItem25
        '
        resources.ApplyResources(Me.MenuItem25, "MenuItem25")
        Me.MenuItem25.Index = 2
        '
        'FileTimer
        '
        Me.FileTimer.Interval = 2000
        '
        'FrmConvert
        '
        resources.ApplyResources(Me, "$this")
        Me.Controls.Add(Me.Panel25)
        Me.Controls.Add(Me.Panel21)
        Me.Controls.Add(Me.Panel4)
        Me.Controls.Add(Me.Panel13)
        Me.Controls.Add(Me.Panel6)
        Me.Controls.Add(Me.Panel1)
        Me.Menu = Me.MainMenu1
        Me.Name = "FrmConvert"
        Me.WindowState = System.Windows.Forms.FormWindowState.Maximized
        Me.Panel1.ResumeLayout(False)
        Me.Panel2.ResumeLayout(False)
        Me.Panel26.ResumeLayout(False)
        Me.Panel33.ResumeLayout(False)
        Me.Panel34.ResumeLayout(False)
        Me.Panel34.PerformLayout()
        Me.Panel35.ResumeLayout(False)
        Me.Panel5.ResumeLayout(False)
        Me.Panel3.ResumeLayout(False)
        Me.Panel6.ResumeLayout(False)
        Me.Panel7.ResumeLayout(False)
        Me.Panel17.ResumeLayout(False)
        Me.Panel20.ResumeLayout(False)
        Me.Panel20.PerformLayout()
        Me.Panel19.ResumeLayout(False)
        Me.Panel8.ResumeLayout(False)
        Me.Panel9.ResumeLayout(False)
        Me.Panel13.ResumeLayout(False)
        Me.Panel14.ResumeLayout(False)
        Me.Panel4.ResumeLayout(False)
        Me.Panel10.ResumeLayout(False)
        CType(Me.DataGrid1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.DataTable1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.Panel11.ResumeLayout(False)
        Me.Panel12.ResumeLayout(False)
        Me.Panel21.ResumeLayout(False)
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox1.PerformLayout()
        Me.Panel22.ResumeLayout(False)
        Me.Panel29.ResumeLayout(False)
        Me.Panel30.ResumeLayout(False)
        Me.Panel31.ResumeLayout(False)
        Me.Panel32.ResumeLayout(False)
        Me.Panel24.ResumeLayout(False)
        Me.Panel25.ResumeLayout(False)
        Me.Panel18.ResumeLayout(False)
        CType(Me.DataSet1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub

#End Region

    Private intCurrentRowDTB As Integer = 0 'ตำแหน่ง(ในตาราง)ของหนังสือที่ถูกแปลอยู่
    Private intRemainDTB As Integer = 0     'จำนวนหนังสือที่ยังไม่ได้แปลง
    Private intAllDTB As Integer = 0        'จำนวนหนังสือทั้งหมดที่ต้องแปลง

    Private Declare Function GetDiskFreeSpaceEx Lib "kernel32" Alias "GetDiskFreeSpaceExA" (ByVal lpDirectoryName As String, ByRef lpFreeBytesAvailableToCaller As Long, ByRef lpTotalNumberOfBytes As Long, ByRef lpTotalNumberOfFreeBytes As Long) As Long
    Private b As New BackGroundTask
    Private a As Thread
    Private currentDtbTimer As Double
    Private currentFileTimer As Double

    Public Function OpenTatip() As Boolean
        'Check process name
        '   "windows_tatip.e" for windows 2000 (limited at 15 characters)
        '   "windows_tatip.exe" for windows 2003
        If (FindProcess("windows_tatip.e") = False) And (FindProcess("windows_tatip.exe") = False) Then
            'There is no any running process of windows_tatip.
            'MsgBox("You Selected PPA Tatip engine for conversion but PPA Tatip is not running. Program will automatically open PPA Tatip.", MsgBoxStyle.Information, "Open PPA Tatip.")

            '            'เรียกดู Path ไปยัง Tatip จาก HKEY_CURRENT_USER\Software\Microsoft\Windows\ShellNoRoam\MUICache\windows_tatip
            '            Dim regKey As RegistryKey
            '            Dim strTatipPath As String = ""
            '            regKey = Registry.CurrentUser.OpenSubKey("Software\Microsoft\Windows\ShellNoRoam\MUICache", False)
            '
            '            If (regKey.ValueCount > 0) Then
            '                For Each valueName As String In regKey.GetValueNames()
            '                    If Microsoft.VisualBasic.Right(valueName, 17) = "windows_tatip.exe" Then
            '                        If regKey.GetValue(valueName) = "windows_tatip" Then
            '                            strTatipPath = valueName
            '                            GoTo Start_Handle
            '                        End If
            '                    End If
            '                Next
            '            End If
            '            regKey.Close()
            '
            'Start_Handle:
            '            'There is no regKey for Windows 2000; I add below for shortcut.
            '            If strTatipPath = "" Then
            '                strTatipPath = "C:\Program Files\PPA Tatip\interface\windows_tatip.exe"
            '            End If

            Try
                Dim program As New Process
                'program.StartInfo.FileName = strTatipPath
                program.StartInfo.FileName = "C:\Program Files\PPA Tatip\interface\windows_tatip.exe"
                program.StartInfo.Arguments = " "
                program.Start()
                OpenTatip = True
            Catch ex As Exception
                OpenTatip = False
            End Try
        End If
    End Function

    Public Function GetFreeSpace(ByVal Drive As String) As Long
        'returns free space in MB, formatted to two decimal places
        'e.g., msgbox("Free Space on D: "& GetFreeSpace("D:\") & "MB")
        Dim lBytesTotal, lFreeBytes, lFreeBytesAvailable As Long
        Dim a_counter As Long

        a_counter = GetDiskFreeSpaceEx(Drive, lFreeBytesAvailable, lBytesTotal, lFreeBytes)
        If a_counter > 0 Then
            Return BytesToMegabytes(lFreeBytes)
        Else
            Throw New Exception("Invalid or unreadable drive")
        End If
    End Function

    Public Function GetTotalSpace(ByVal Drive As String) As String
        'returns total space in MB, formatted to two decimal places
        'e.g., msgbox("Free Space on D: "& GetTotalSpace("D:\") & "MB")
        Dim lBytesTotal, lFreeBytes, lFreeBytesAvailable As Long
        Dim a_counter As Long

        a_counter = GetDiskFreeSpaceEx(Drive, lFreeBytesAvailable, lBytesTotal, lFreeBytes)
        If a_counter > 0 Then
            Return BytesToMegabytes(lBytesTotal)
        Else
            Throw New Exception("Invalid or unreadable drive")
        End If
    End Function

    Private Function BytesToMegabytes(ByVal Bytes As Long) As Long
        Dim check_counter As Double
        check_counter = (Bytes / 1024) / 1024
        BytesToMegabytes = Format(check_counter, "###,###,##0.00")
    End Function

    Private Sub Button03_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button03.Click
        If (TxtNccName.Text = "") Then
            MsgBox("Please check source path of DTB again!", MsgBoxStyle.Exclamation, "DTB source empty!")
            Exit Sub
        ElseIf (TxtDestFolder.Text = "") Then
            MsgBox("Please check destination path of DTB again!", MsgBoxStyle.Exclamation, "DTB destination empty!")
            Exit Sub
        ElseIf LCase(TxtDestFolder.Text) = LCase(TxtNccName.Text.Substring(0, TxtNccName.Text.LastIndexOf("\") + 1)) Then
            MsgBox("Please check destination path and Source path again because it is a same position!", MsgBoxStyle.Exclamation, "DTB destination same as source!")
            Exit Sub
        ElseIf (Me.ComboBox2.Text = "") Then
            MsgBox("Please check selection of Speech Engine for Convertion again!", MsgBoxStyle.Exclamation, "No speech engine is selected.")
            Exit Sub
        ElseIf (Trim(Microsoft.VisualBasic.Mid(ComboBox2.Text, 3, 5)) = "None") Then
            If (Trim(LCase(Microsoft.VisualBasic.Right(TxtNccName.Text, 3))) <> "ncx") Then
                MsgBox("""Option " & Trim(Microsoft.VisualBasic.Left(ComboBox2.Text, 7)) & """ uses for DAISY3 Only", MsgBoxStyle.Exclamation, "Wrong Selection.")
                Exit Sub
            End If
        End If

        'Record important information to DataGrid Table.
        Dim myDataRow As DataRow = Me.DataSet1.Tables(0).NewRow()

        myDataRow("Navigation Control File Path") = Me.TxtNccName.Text
        myDataRow("Convertion Result") = "Waiting"
        If Trim(LCase(Trim(Microsoft.VisualBasic.Right(TxtNccName.Text, 8)))) = "ncc.html" Then
            myDataRow("DTB Version") = "DAISY 2.02"
        ElseIf Trim(LCase(Trim(Microsoft.VisualBasic.Right(TxtNccName.Text, 7)))) = "ncc.htm" Then
            myDataRow("DTB Version") = "DAISY 2.02"
        ElseIf Trim(LCase(Trim(Microsoft.VisualBasic.Right(TxtNccName.Text, 3)))) = "ncx" Then
            myDataRow("DTB Version") = "ANSI/NISO Z39.86"
        End If

        myDataRow("Destination Path") = Me.TxtDestFolder.Text
        myDataRow("Final Audio Format") = Me.ComboBox1.Text
        myDataRow("Speech Engine") = Me.ComboBox2.Text
        On Error GoTo ErrorHandle
        Me.DataSet1.Tables(0).Rows.Add(myDataRow)
        Call updateLabel()
        Exit Sub

ErrorHandle:
        MsgBox("Duplicate destination folder is prohibited")
    End Sub

    Private Sub FrmConvert_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Button5.TabIndex = 0
        Button4.TabIndex = 1
        Button2.TabIndex = 2
        Button3.TabIndex = 3
        Button1.TabIndex = 4
        Button15.TabIndex = 5

        'On Error Resume Next
        'Set Default Combobox
        Me.ComboBox1.SelectedIndex = 1
        updateLabel()

        Dim V As New SpeechLib.SpVoice
        Dim T As SpeechLib.ISpeechObjectToken
        Dim strVoice As String
        Dim intNumOfVoice As Integer = 1   'start @ 1 you must - 1 then don't forget to when you call DLL also

        'Get each token in the collection returned by GetVoices
        For Each T In V.GetVoices
            strVoice = T.GetDescription             'The token's name
            ComboBox2.Items.Add(Trim(Str(intNumOfVoice)) & ". " & strVoice)           'Add to listbox
            intNumOfVoice = intNumOfVoice + 1
        Next

        Me.DataGrid1.PreferredColumnWidth = 20

        'Check Available space on drive C
        Me.Label2.Text = "Available space on drive C: = " & Trim(Str(GetFreeSpace("C:\"))) & " MB."

        'Check CPU Speed
        Call b.getCpuSpeed()
        Label1.Text = "CPU Speed = " & Trim(Str(b.intCpuSpeed)) & " MHz"
    End Sub

    Private Sub Button04_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button04.Click
        ' Get the selected row through the CurrentCell.
        Dim rowNum As Integer = DataGrid1.CurrentCell.RowNumber

        If DataSet1.Tables(0).Rows.Count > 0 Then
            Me.TxtNccName.Text = Me.DataSet1.Tables(0).Rows(rowNum).Item("Navigation Control File Path")
            Me.TxtDestFolder.Text() = Me.DataSet1.Tables(0).Rows(rowNum).Item("Destination Path")
            Me.ComboBox1.Text() = Me.DataSet1.Tables(0).Rows(rowNum).Item("Final Audio Format")
            Me.ComboBox2.Text() = Me.DataSet1.Tables(0).Rows(rowNum).Item("Speech Engine")

            Me.DataSet1.Tables(0).Rows(rowNum).Delete()
            Call updateLabel()
        End If
    End Sub

    Private Sub Button09_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button09.Click
        'Remove Button
        ' Get the selected row through the CurrentCell.
        Dim rowNum As Integer = DataGrid1.CurrentCell.RowNumber

        If DataSet1.Tables(0).Rows.Count > 0 Then
            Me.DataSet1.Tables(0).Rows(rowNum).Delete()
            Call updateLabel()
        End If
    End Sub

    Private Sub Button07_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button07.Click
        'Move up button
        ' Get the selected row through the CurrentCell.
        Dim rowNum As Integer = DataGrid1.CurrentCell.RowNumber
        If rowNum > 0 Then
            Dim currentTempRow As Array = Me.DataSet1.Tables(0).Rows(rowNum).ItemArray
            Dim PreviousTempRow As Array = Me.DataSet1.Tables(0).Rows(rowNum - 1).ItemArray

            Me.DataSet1.Tables(0).Rows(rowNum).Item("Destination Path") = "Temp"
            Me.DataSet1.Tables(0).Rows(rowNum - 1).ItemArray = currentTempRow
            Me.DataSet1.Tables(0).Rows(rowNum).ItemArray = PreviousTempRow
            Me.DataGrid1.CurrentRowIndex = rowNum - 1
        End If

    End Sub

    Private Sub Button08_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button08.Click
        'Move down button
        ' Get the selected row through the CurrentCell.
        Dim rowNum As Integer = DataGrid1.CurrentCell.RowNumber

        If rowNum < DataSet1.Tables(0).Rows.Count - 1 Then
            Dim currentTempRow As Array = Me.DataSet1.Tables(0).Rows(rowNum).ItemArray
            Dim NextTempRow As Array = Me.DataSet1.Tables(0).Rows(rowNum + 1).ItemArray

            Me.DataSet1.Tables(0).Rows(rowNum).Item("Destination Path") = "Temp"
            Me.DataSet1.Tables(0).Rows(rowNum + 1).ItemArray = currentTempRow
            Me.DataSet1.Tables(0).Rows(rowNum).ItemArray = NextTempRow
            Me.DataGrid1.CurrentRowIndex = rowNum + 1
        End If
    End Sub

    Sub updateLabel()
        If DataSet1.Tables(0).Rows.Count < 2 Then
            Label04.Text = DataSet1.Tables(0).Rows.Count.ToString & " DTB waiting..."
        Else
            Label04.Text = DataSet1.Tables(0).Rows.Count.ToString & " DTBs waiting..."
        End If
        Call DataGridApplyAutomaticWidths(DataGrid1)
    End Sub

    Sub DataGridApplyAutomaticWidths(ByVal DataGrid As System.Windows.Forms.DataGrid)

        'Define new table style.
        Dim TableStyle As DataGridTableStyle = New DataGridTableStyle

        'Define new data Table
        Dim DataTable As DataTable
        DataTable = DataGrid.DataSource.DataSet.Tables(0)

        'Clear any existing table styles.
        DataGrid.TableStyles.Clear()

        'Use mapping name that is defined in the data source.
        TableStyle.MappingName = DataTable.TableName

        'Now create the column styles within the table style.
        Dim Column As DataColumn
        Dim ColumnStyle As DataGridTextBoxColumn

        For Each Column In DataTable.Columns
            ColumnStyle = New DataGridTextBoxColumn
            ColumnStyle.HeaderText = Column.ColumnName
            ColumnStyle.MappingName = Column.ColumnName
            If Column.Ordinal = 0 Or Column.Ordinal = 3 Then
                ColumnStyle.Width = 0.24 * Me.DataGrid1.Width
            Else
                ColumnStyle.Width = 0.15 * Me.DataGrid1.Width
            End If
            'Add the new column style to the table style.
            TableStyle.GridColumnStyles.Add(ColumnStyle)
        Next
        'Add the new table style to the data grid.
        DataGrid.TableStyles.Add(TableStyle)
    End Sub


    Private Sub Button05_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button05.Click
        ' Save to XML
        Me.SaveXML.ShowDialog()
        If Me.SaveXML.FileName <> "" Then
            Dim SwFromFile As StreamWriter = New StreamWriter(Me.SaveXML.FileName)
            Me.DataSet1.WriteXml(SwFromFile)
            SwFromFile.Close()
        End If
    End Sub

    Private Sub Button06_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button06.Click
        ' Load from XML
        On Error GoTo ReadXmlError
        Me.OpenXML.ShowDialog()
        If OpenXML.FileName <> "" Then
            Dim SrFromFile As StreamReader = New StreamReader(Me.OpenXML.FileName)
            Me.DataSet1.Clear()
            Me.DataSet1.ReadXml(SrFromFile)
            SrFromFile.Close()
            updateLabel()
            Exit Sub
ReadXmlError:
            MsgBox("Please check your XML File again.")
            Me.DataSet1.Clear()
            SrFromFile.Close()
            updateLabel()
        End If
    End Sub

    Private Sub Button15_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button15.Click
        If MsgBox("Do you really want to exit?", MsgBoxStyle.Question Or MsgBoxStyle.YesNo, "Exit Program") = MsgBoxResult.Yes Then
            End
        End If
    End Sub

    Private Sub FrmConvert_Resize(ByVal sender As Object, ByVal e As System.EventArgs) Handles MyBase.Resize
        If Me.Width < 800 Then
            Me.Width = 800
        End If

        If Me.Height < 600 Then
            Me.Height = 600
        End If

        Me.Label1.Left = (Me.Panel18.Width - Me.Label1.Width) / 2
    End Sub

    Private Sub MenuItem27_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem27.Click
        'Open Test Engine Page
        Call Me.Button1_Click(sender, e)
    End Sub

    Private Sub Button01_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button01.Click
        'Show Dialog for destination folder button
        Me.OpenFileDialog1.ShowDialog()
        Me.TxtNccName.Text = Me.OpenFileDialog1.FileName
    End Sub

    Private Sub Button02_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button02.Click
        'Show Dialog for DTB source selection.
        Me.FolderBrowserDialog1.ShowDialog()
        If Me.FolderBrowserDialog1.SelectedPath <> "" Then
            Me.TxtDestFolder.Text = Me.FolderBrowserDialog1.SelectedPath
            If Microsoft.VisualBasic.Right(Me.TxtDestFolder.Text, 1) <> "\" Then
                Me.TxtDestFolder.Text = Me.TxtDestFolder.Text & "\"
            End If

            Dim myDrive As String = UCase(Microsoft.VisualBasic.Left(Me.TxtDestFolder.Text, 1))

            If GetFreeSpace(myDrive & ":\") < 1024 Then
                MsgBox("You can not use drive " & myDrive & ":" & " because of space available has remain less than 1 GB. Please selects new drive.", MsgBoxStyle.Critical Or MsgBoxStyle.OKOnly, "There is no space enough!")
                Me.TxtDestFolder.Text = ""
            End If

            'Update label for Available space on lastest selected drive 
            Me.Label2.Text = "Available space on drive " & myDrive & ":" & " = " & Trim(Str(GetFreeSpace(myDrive & ":\"))) & " MB."
        End If
    End Sub

    Private Sub ComboBox2_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ComboBox2.SelectedIndexChanged
        On Error Resume Next
        If (Microsoft.VisualBasic.Right(ComboBox2.Text, 11) = "PPA ตาทิพย์") Then
            If OpenTatip() = False Then
                MsgBox("Fail to automatic open PPA Tatip. Please open PPA Tatip manually", MsgBoxStyle.Information, "Fail to open PPA Tatip.")
            End If
        End If
    End Sub

    Function FindProcess(ByVal Process As Object) As Boolean
        Dim objWMIService As Object, colProcesses As Object
        objWMIService = GetObject("winmgmts:")
        colProcesses = objWMIService.ExecQuery("Select * from Win32_Process where name='" & Process & "'")
        If colProcesses.Count Then FindProcess = True
    End Function

    Private Sub MenuItem2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem2.Click
        'load XML list
        Call Me.Button06_Click(sender, e)
    End Sub

    Private Sub MenuItem3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem3.Click
        'Save XML list
        Call Me.Button05_Click(sender, e)
    End Sub

    Private Sub MenuItem7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem7.Click
        'Go to UpLoad Module
        Call Me.Button2_Click(sender, e)
    End Sub

    Private Sub MenuItem21_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem21.Click
        'Exit Program
        Call Me.Button15_Click(sender, e)
    End Sub

    Private Sub MenuItem5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem5.Click
        'Select DTB Source for conversion
        Call Me.Button01_Click(sender, e)
    End Sub

    Private Sub MenuItem8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem8.Click
        'Select Path of Destination
        Call Me.Button02_Click(sender, e)
    End Sub

    Private Sub MenuItem29_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem29.Click
        'Go to Change Catalog Module
        Call Me.Button3_Click(sender, e)
    End Sub
    Private Sub MenuItem28_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem28.Click
        'select speech engine
        Me.ComboBox2.Focus()
    End Sub

    Private Sub MenuItem9_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem9.Click
        'select final audio output format
        Me.ComboBox1.Focus()
    End Sub

    Private Sub MenuItem11_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem11.Click
        'Add this item to list
        Call Me.Button03_Click(sender, e)
    End Sub

    Private Sub MenuItem12_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem12.Click
        'Edit this item
        Call Me.Button04_Click(sender, e)
    End Sub

    Private Sub MenuItem15_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem15.Click
        'Remove this item from list
        Call Me.Button09_Click(sender, e)
    End Sub

    Private Sub MenuItem13_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem13.Click
        'move this item up
        Call Me.Button07_Click(sender, e)
    End Sub

    Private Sub MenuItem14_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem14.Click
        'move this item down
        Call Me.Button08_Click(sender, e)
    End Sub

    Private Sub MenuItem23_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem23.Click
        MsgBox("Sorry, This feature is under construction.", MsgBoxStyle.Information, "Help")
    End Sub

    Private Sub MenuItem25_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem25.Click
        Dim myFrmAbout As New FrmAbout
        myFrmAbout.ShowDialog()
    End Sub

    Private Sub MenuItem32_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem32.Click
        'Go to Set Password Module
        Call Me.Button5_Click(sender, e)
    End Sub

    Private Sub MenuItem33_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem33.Click
        'Go to scan Library Modue
        Call Me.Button6_Click(sender, e)
    End Sub


    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim myFrmOption As New FrmOption
        myFrmOption.ShowDialog()
    End Sub

    Private Sub FrmConvert_Closing(ByVal sender As Object, ByVal e As System.ComponentModel.CancelEventArgs) Handles MyBase.Closing
        If MsgBox("Do you really want to exit?", MsgBoxStyle.Question Or MsgBoxStyle.YesNo, "Exit Program") = MsgBoxResult.No Then
            e.Cancel = True
        End If
    End Sub

    Private Sub Button10_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button10.Click
        'On Error Resume Next
        'Get value from Datagrid
        Dim myTable As DataTable
        Dim myRow As DataRow

        'Dim HaveWaitingDTB As Boolean = False
        Dim AreDtbInListSuccess As Boolean = True

        myTable = CType(DataGrid1.DataSource, DataTable)
        If myTable.Rows.Count <= 0 Then
            MsgBox("Please specific path and destination first.", MsgBoxStyle.Exclamation, "Empty Path!")
            Exit Sub
        Else
            'Check for waiting DTB for converting
            AreDtbInListSuccess = True
            intAllDTB = myTable.Rows.Count
            intRemainDTB = 0
            For intCurrentRowDTB = 0 To myTable.Rows.Count - 1
                myRow = myTable.Rows(intCurrentRowDTB)
                If myRow(1) = "Waiting" Then
                    intRemainDTB = intRemainDTB + 1
                End If
                If myRow(1) <> "Completed" Then
                    AreDtbInListSuccess = False
                End If
            Next intCurrentRowDTB

            If (AreDtbInListSuccess = True) Then
                MsgBox("All DTB was converted with success.", MsgBoxStyle.OKOnly, "No remains DTB to convert!")
                Exit Sub
            End If

            If intRemainDTB = 0 Then
                MsgBox("There is no remain DTB to convert. Please select and insert new book.", MsgBoxStyle.Exclamation, "No remains DTB to convert!")
                Exit Sub
            End If
        End If

        'Loop for convertion
        For intCurrentRowDTB = 0 To myTable.Rows.Count - 1   'Convert DTB"
            myRow = myTable.Rows(intCurrentRowDTB)
            'myRow(0) is source
            'myRow(1) is status
            'myRow(3) is destination
            'myRow(5) is speech engine

            If myRow(1) = "Waiting" Then
                'If (Microsoft.VisualBasic.Right(myRow(5), 11) = "PPA ตาทิพย์") Then
                'If OpenTatip() = False Then
                'MsgBox("Fail to automatic open PPA Tatip. Please open PPA Tatip manually before clicking OK button!", MsgBoxStyle.Information, "Fail to open PPA Tatip.")
                'Exit Sub
                'End If
                'End If

                'setup value for label
                LblDtbName.Text = ""
                LblFileName.Text = ""
                LblDtbStatus.Text = "Converting"
                LblFileStatus.Text = "Reading"

                'Convert
                Dim intOrderSpeechEngine As Integer = Val(Microsoft.VisualBasic.Left(myRow(5), 2)) - 1
                Dim strAudioFileExtension As String = Trim(LCase(Microsoft.VisualBasic.Mid(myRow(4), 4, 3)))
                myRow(1) = "Converting"

                b.myStrNcPath = myRow(0)
                b.myStrDestFolder = myRow(3)
                b.myBolMakeSyntheticSound = False
                b.myintOrderText2Speech = intOrderSpeechEngine
                b.myChrOutputAudioFormat = strAudioFileExtension

                'setup Timer
                currentFileTimer = 0
                FileTimer.Enabled = True
                a = Nothing
                a = New Thread(AddressOf b.Task)
                a.Priority = ThreadPriority.Normal
                a.Start()
                Exit Sub
            End If
        Next intCurrentRowDTB
        Exit Sub

Error_Exit:
        'Destroy DLL Object
        On Error Resume Next
        MsgBox("some thing error during call DLL", MsgBoxStyle.Critical, "CALL DLL ERROR.")
        myRow(1) = "Error #0000 Call DLL error."
    End Sub

    Class BackGroundTask
        'Public Declare Function Starter Lib "Converter.dll" (ByVal strPath As String) As Double
        Public Declare Function CreateConverterDll Lib "Converter.dll" () As Long
        Public Declare Sub DestroyConverterDll Lib "Converter.dll" (ByVal objptr As Long)
        Public Declare Function GetCpuSpeedConverterDll Lib "Converter.dll" (ByVal objptr As Long) As Integer
        Public Declare Function StartConverterDll Lib "Converter.dll" (ByVal strNcPath As String, ByVal strDestFolder As String, ByVal bolMakeSyntheticSound As Boolean, ByVal intOrderText2Speech As Integer, ByVal chrOutputAudioFormat As String, ByVal objptr As Long) As Integer

        Public myStrNcPath As String
        Public myStrDestFolder As String
        Public myBolMakeSyntheticSound As Boolean
        Public myintOrderText2Speech As Integer
        Public myChrOutputAudioFormat As String
        Public intReturnValue As Integer
        Public intCpuSpeed As Integer

        Public Sub Task()
            Dim objptr As Long
            Try
                'Clear value
                intReturnValue = -9999
                'Create DLL Object
                objptr = CreateConverterDll()
            Catch ex As Exception
                MsgBox("Call DLL Error! :: " & ex.Message)
                Exit Sub
            End Try

            Try
                intReturnValue = StartConverterDll(myStrNcPath, Me.myStrDestFolder, myBolMakeSyntheticSound, myintOrderText2Speech, myChrOutputAudioFormat, objptr)
                'Destroy DLL Object
                DestroyConverterDll(objptr)
            Catch ex As Exception
                MsgBox("Error in DLL! :: " & ex.Message)
                Exit Sub
            End Try
        End Sub

        Public Sub getCpuSpeed()
            Dim objptr As Long
            Try
                'Create DLL Object
                objptr = CreateConverterDll()
                'Check CPU speed.
                intCpuSpeed = GetCpuSpeedConverterDll(objptr)
                'Destroy DLL Object
                DestroyConverterDll(objptr)
            Catch ex As Exception
                MsgBox("Can't get CPU speed!")
            End Try
        End Sub
    End Class

    Public Function formatSecondLength(ByVal howManySeconds As Double) As String
        Dim mySeconds As Double
        Dim myHours As Double
        Dim myMinutes As Double

        On Error GoTo errCheck 'just incase of an error 

        'duration
        mySeconds = howManySeconds

        'if mySeconds is greater or equal to 3,600 seconds 

        If mySeconds >= 3600 Then
            'get hours which is equal to seconds divided by 3600 
            myHours = mySeconds / 3600
            'set the seconds to the numbers after the decimal sign thats what mod does 
            mySeconds = mySeconds Mod 3600
        Else
            'if not greater than 3600, just set it to 0 
            myHours = 0
        End If

        If mySeconds >= 60 Then
            'greater than or equal to 60 set the minutes equal to the value of (seconds divided by 60). 
            myMinutes = mySeconds \ 60
            'get the remaining numbers after the decimal which will be the seconds using the mod sign 
            mySeconds = mySeconds Mod 60
        Else
            'if not set to 0 
            myMinutes = 0
        End If

        'return 
        formatSecondLength = Format$(myHours, "00:") & Format$(myMinutes, "00:") & Format$(mySeconds, "00")
        Exit Function

errCheck:
        formatSecondLength = ""
    End Function

    Private Sub FileTimer_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles FileTimer.Tick
        On Error Resume Next
        Dim myStreamReader1 As New StreamReader(b.myStrDestFolder & "status.log", System.Text.Encoding.GetEncoding("windows-874"))
        Dim currentPercent As Integer = CInt(Val(myStreamReader1.ReadLine()))
        LblDtbName.Text = myStreamReader1.ReadLine()
        LblDtbStatus.Text = myStreamReader1.ReadLine()
        LblFileName.Text = myStreamReader1.ReadLine()
        LblFileStatus.Text = myStreamReader1.ReadLine()
        myStreamReader1.Close()

        PgbCurrDtbCompleted.Value = currentPercent
        LblCurrDtbCompleted.Text = Str(PgbCurrDtbCompleted.Value) & "%"
        PgbAllDtbCompleted.Value = ((((intAllDTB - intRemainDTB) / intAllDTB) * 100) + (currentPercent / intAllDTB))
        LblAllDtbCompleted.Text = Str(PgbAllDtbCompleted.Value) & "%"

        If (currentFileTimer Mod 30 = 0) Or (b.intReturnValue <> -9999) Then
            'Copy the file for display.
            System.IO.File.Copy(b.myStrDestFolder & "result.log", b.myStrDestFolder & "result2.log", True)
            Dim myStreamReader2 As New StreamReader(b.myStrDestFolder & "result2.log", System.Text.Encoding.GetEncoding("windows-874"))
            TextBox1.Text = myStreamReader2.ReadToEnd()
            myStreamReader2.Close()
            System.IO.File.Delete(b.myStrDestFolder & "result2.log")
            currentPercent = PgbAllDtbCompleted.Value
            currentPercent = currentPercent - (currentPercent Mod 5)
            mdlPublic.PlayMod5Percent(currentPercent)
        End If

        'FILE TIMER
        currentDtbTimer = currentDtbTimer + 2
        LblDtbTime.Text = formatSecondLength(currentDtbTimer)

        If b.intReturnValue = -9999 Then
            'DTB TIMER
            currentFileTimer = currentFileTimer + 2
            LblFileTime.Text = formatSecondLength(currentFileTimer)
        Else
            Dim myTable As DataTable
            Dim myRow As DataRow
            myTable = CType(DataGrid1.DataSource, DataTable)
            myRow = myTable.Rows(intCurrentRowDTB)
            FileTimer.Enabled = False
            currentFileTimer = 0
            If b.intReturnValue = 9999 Then
                myRow(1) = "Completed"
            Else
                myRow(1) = "Error#" & Str(b.intReturnValue)
            End If
            b.intReturnValue = -9999 'reset value
            PgbCurrDtbCompleted.Value = 100
            Button10_Click(sender, e)
            Exit Sub
        End If
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Dim myFrmbookUpload As New FrmBookUpload
        myFrmbookUpload.ShowDialog()
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        Dim myFrmChangeCatalog As New FrmChangeCatalog
        myFrmChangeCatalog.ShowDialog()
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        Dim myFrmGetNineDigit As New FrmGetNineDigit
        myFrmGetNineDigit.ShowDialog()
    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        If MsgBox("This module was protected to use by a librarian only!", MsgBoxStyle.OKCancel) = MsgBoxResult.OK Then
            Dim myFrmSetPassword As New FrmSetPassword
            myFrmSetPassword.ShowDialog()
        End If
    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click

        If MsgBox("This function may take a lot of time to process depend on the size of your library. Do you want to continue?", MsgBoxStyle.YesNo) = MsgBoxResult.Yes Then
            Dim myFrmScanlibrary As New FrmScanLibrary
            myFrmScanlibrary.ShowDialog()
        End If
    End Sub

End Class
