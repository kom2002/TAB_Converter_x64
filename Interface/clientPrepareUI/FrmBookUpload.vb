'namespaces added to support functionality 
Imports System.Data                         'Database support
Imports System.Data.OleDb                   'Oledb support
Imports System
Imports System.IO
Imports System.IO.File
Imports SpeechLib
Imports Microsoft.VisualBasic

Public Class FrmBookUpload
    Inherits System.Windows.Forms.Form
    Private T As SpeechLib.ISpeechObjectToken
    Private V As New SpeechLib.SpVoice
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
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents TextBox1 As System.Windows.Forms.TextBox
    Friend WithEvents Button5 As System.Windows.Forms.Button
    Friend WithEvents Button4 As System.Windows.Forms.Button
    Friend WithEvents Panel1 As System.Windows.Forms.Panel
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents ComboBox2 As System.Windows.Forms.ComboBox
    Friend WithEvents ComboBox1 As System.Windows.Forms.ComboBox
    Friend WithEvents ListBox1 As System.Windows.Forms.ListBox
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents GroupBox2 As System.Windows.Forms.GroupBox
    Friend WithEvents ComboBox3 As System.Windows.Forms.ComboBox
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Button6 As System.Windows.Forms.Button
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents Button8 As System.Windows.Forms.Button
    Friend WithEvents Button11 As System.Windows.Forms.Button
    Friend WithEvents Button7 As System.Windows.Forms.Button
    Friend WithEvents OpenWaveFileDialog As System.Windows.Forms.OpenFileDialog
    Friend WithEvents FolderBrowserDialog1 As System.Windows.Forms.FolderBrowserDialog
    Friend WithEvents Button10 As System.Windows.Forms.Button
    Friend WithEvents Button9 As System.Windows.Forms.Button
    Friend WithEvents Button12 As System.Windows.Forms.Button
    Friend WithEvents Label9 As System.Windows.Forms.Label
    Friend WithEvents Button13 As System.Windows.Forms.Button
    Friend WithEvents Label10 As System.Windows.Forms.Label
    Friend WithEvents Label8 As System.Windows.Forms.Label
    Friend WithEvents OpenNcxFileDialog As System.Windows.Forms.OpenFileDialog
    Friend WithEvents txtBookDetail As System.Windows.Forms.TextBox
    Friend WithEvents txtNcxPath As System.Windows.Forms.TextBox
    Friend WithEvents Button16 As System.Windows.Forms.Button
    Friend WithEvents txtBookID As System.Windows.Forms.TextBox
    Friend WithEvents Label11 As System.Windows.Forms.Label
    Friend WithEvents Label12 As System.Windows.Forms.Label
    Friend WithEvents Label13 As System.Windows.Forms.Label
    Friend WithEvents Button17 As System.Windows.Forms.Button
    Friend WithEvents txtSortOrder As System.Windows.Forms.TextBox
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents txtBookName As System.Windows.Forms.TextBox
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Dim resources As System.Resources.ResourceManager = New System.Resources.ResourceManager(GetType(FrmBookUpload))
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.Label4 = New System.Windows.Forms.Label
        Me.TextBox1 = New System.Windows.Forms.TextBox
        Me.Button5 = New System.Windows.Forms.Button
        Me.Button4 = New System.Windows.Forms.Button
        Me.Panel1 = New System.Windows.Forms.Panel
        Me.Label8 = New System.Windows.Forms.Label
        Me.Button10 = New System.Windows.Forms.Button
        Me.Button9 = New System.Windows.Forms.Button
        Me.Button7 = New System.Windows.Forms.Button
        Me.Button11 = New System.Windows.Forms.Button
        Me.GroupBox2 = New System.Windows.Forms.GroupBox
        Me.Label12 = New System.Windows.Forms.Label
        Me.txtSortOrder = New System.Windows.Forms.TextBox
        Me.Label13 = New System.Windows.Forms.Label
        Me.Label11 = New System.Windows.Forms.Label
        Me.txtBookID = New System.Windows.Forms.TextBox
        Me.Button16 = New System.Windows.Forms.Button
        Me.Button13 = New System.Windows.Forms.Button
        Me.Label9 = New System.Windows.Forms.Label
        Me.txtNcxPath = New System.Windows.Forms.TextBox
        Me.Button12 = New System.Windows.Forms.Button
        Me.Label3 = New System.Windows.Forms.Label
        Me.Button8 = New System.Windows.Forms.Button
        Me.Button17 = New System.Windows.Forms.Button
        Me.txtBookDetail = New System.Windows.Forms.TextBox
        Me.Label10 = New System.Windows.Forms.Label
        Me.Label6 = New System.Windows.Forms.Label
        Me.ComboBox3 = New System.Windows.Forms.ComboBox
        Me.Button6 = New System.Windows.Forms.Button
        Me.Label7 = New System.Windows.Forms.Label
        Me.txtBookName = New System.Windows.Forms.TextBox
        Me.Button2 = New System.Windows.Forms.Button
        Me.Button1 = New System.Windows.Forms.Button
        Me.ListBox1 = New System.Windows.Forms.ListBox
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label1 = New System.Windows.Forms.Label
        Me.ComboBox2 = New System.Windows.Forms.ComboBox
        Me.ComboBox1 = New System.Windows.Forms.ComboBox
        Me.OpenWaveFileDialog = New System.Windows.Forms.OpenFileDialog
        Me.FolderBrowserDialog1 = New System.Windows.Forms.FolderBrowserDialog
        Me.OpenNcxFileDialog = New System.Windows.Forms.OpenFileDialog
        Me.GroupBox1.SuspendLayout()
        Me.Panel1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.SuspendLayout()
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.Label4)
        Me.GroupBox1.Controls.Add(Me.TextBox1)
        Me.GroupBox1.Controls.Add(Me.Button5)
        Me.GroupBox1.Controls.Add(Me.Button4)
        Me.GroupBox1.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.GroupBox1.Location = New System.Drawing.Point(8, 8)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(776, 56)
        Me.GroupBox1.TabIndex = 4
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Setting Working Directory:"
        '
        'Label4
        '
        Me.Label4.Location = New System.Drawing.Point(544, 32)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(88, 16)
        Me.Label4.TabIndex = 13
        Me.Label4.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'TextBox1
        '
        Me.TextBox1.Cursor = System.Windows.Forms.Cursors.No
        Me.TextBox1.Location = New System.Drawing.Point(8, 24)
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.ReadOnly = True
        Me.TextBox1.Size = New System.Drawing.Size(288, 22)
        Me.TextBox1.TabIndex = 0
        Me.TextBox1.Text = "D:\NBL"
        '
        'Button5
        '
        Me.Button5.Location = New System.Drawing.Point(424, 24)
        Me.Button5.Name = "Button5"
        Me.Button5.Size = New System.Drawing.Size(112, 24)
        Me.Button5.TabIndex = 2
        Me.Button5.Text = "Test Connection"
        '
        'Button4
        '
        Me.Button4.Location = New System.Drawing.Point(304, 24)
        Me.Button4.Name = "Button4"
        Me.Button4.Size = New System.Drawing.Size(112, 24)
        Me.Button4.TabIndex = 1
        Me.Button4.Text = "Change Folder"
        '
        'Panel1
        '
        Me.Panel1.Controls.Add(Me.Label8)
        Me.Panel1.Controls.Add(Me.Button10)
        Me.Panel1.Controls.Add(Me.Button9)
        Me.Panel1.Controls.Add(Me.Button7)
        Me.Panel1.Controls.Add(Me.Button11)
        Me.Panel1.Controls.Add(Me.GroupBox2)
        Me.Panel1.Controls.Add(Me.Button2)
        Me.Panel1.Controls.Add(Me.Button1)
        Me.Panel1.Controls.Add(Me.ListBox1)
        Me.Panel1.Controls.Add(Me.Label2)
        Me.Panel1.Controls.Add(Me.Label1)
        Me.Panel1.Controls.Add(Me.ComboBox2)
        Me.Panel1.Controls.Add(Me.ComboBox1)
        Me.Panel1.Enabled = False
        Me.Panel1.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.Panel1.Location = New System.Drawing.Point(0, 64)
        Me.Panel1.Name = "Panel1"
        Me.Panel1.Size = New System.Drawing.Size(792, 480)
        Me.Panel1.TabIndex = 5
        '
        'Label8
        '
        Me.Label8.Location = New System.Drawing.Point(472, 16)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(88, 16)
        Me.Label8.TabIndex = 78
        Me.Label8.Text = "Book List :"
        '
        'Button10
        '
        Me.Button10.Image = CType(resources.GetObject("Button10.Image"), System.Drawing.Image)
        Me.Button10.ImageAlign = System.Drawing.ContentAlignment.MiddleRight
        Me.Button10.Location = New System.Drawing.Point(168, 112)
        Me.Button10.Name = "Button10"
        Me.Button10.Size = New System.Drawing.Size(144, 32)
        Me.Button10.TabIndex = 4
        Me.Button10.Text = "Delete"
        '
        'Button9
        '
        Me.Button9.Image = CType(resources.GetObject("Button9.Image"), System.Drawing.Image)
        Me.Button9.ImageAlign = System.Drawing.ContentAlignment.MiddleRight
        Me.Button9.Location = New System.Drawing.Point(8, 112)
        Me.Button9.Name = "Button9"
        Me.Button9.Size = New System.Drawing.Size(152, 32)
        Me.Button9.TabIndex = 3
        Me.Button9.Text = "Edit"
        '
        'Button7
        '
        Me.Button7.Image = CType(resources.GetObject("Button7.Image"), System.Drawing.Image)
        Me.Button7.ImageAlign = System.Drawing.ContentAlignment.MiddleRight
        Me.Button7.Location = New System.Drawing.Point(8, 72)
        Me.Button7.Name = "Button7"
        Me.Button7.Size = New System.Drawing.Size(304, 32)
        Me.Button7.TabIndex = 2
        Me.Button7.Text = "Add"
        '
        'Button11
        '
        Me.Button11.Image = CType(resources.GetObject("Button11.Image"), System.Drawing.Image)
        Me.Button11.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Button11.Location = New System.Drawing.Point(688, 8)
        Me.Button11.Name = "Button11"
        Me.Button11.Size = New System.Drawing.Size(96, 24)
        Me.Button11.TabIndex = 7
        Me.Button11.Text = "Refresh"
        Me.Button11.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.Label12)
        Me.GroupBox2.Controls.Add(Me.txtSortOrder)
        Me.GroupBox2.Controls.Add(Me.Label13)
        Me.GroupBox2.Controls.Add(Me.Label11)
        Me.GroupBox2.Controls.Add(Me.txtBookID)
        Me.GroupBox2.Controls.Add(Me.Button16)
        Me.GroupBox2.Controls.Add(Me.Button13)
        Me.GroupBox2.Controls.Add(Me.Label9)
        Me.GroupBox2.Controls.Add(Me.txtNcxPath)
        Me.GroupBox2.Controls.Add(Me.Button12)
        Me.GroupBox2.Controls.Add(Me.Label3)
        Me.GroupBox2.Controls.Add(Me.Button8)
        Me.GroupBox2.Controls.Add(Me.Button17)
        Me.GroupBox2.Controls.Add(Me.txtBookDetail)
        Me.GroupBox2.Controls.Add(Me.Label10)
        Me.GroupBox2.Controls.Add(Me.Label6)
        Me.GroupBox2.Controls.Add(Me.ComboBox3)
        Me.GroupBox2.Controls.Add(Me.Button6)
        Me.GroupBox2.Controls.Add(Me.Label7)
        Me.GroupBox2.Controls.Add(Me.txtBookName)
        Me.GroupBox2.Enabled = False
        Me.GroupBox2.Location = New System.Drawing.Point(8, 152)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(448, 296)
        Me.GroupBox2.TabIndex = 12
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "Add or Edit a book"
        '
        'Label12
        '
        Me.Label12.Location = New System.Drawing.Point(184, 24)
        Me.Label12.Name = "Label12"
        Me.Label12.Size = New System.Drawing.Size(168, 16)
        Me.Label12.TabIndex = 102
        Me.Label12.Text = "<-auto4 Digits [0001-9999]"
        Me.Label12.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'txtSortOrder
        '
        Me.txtSortOrder.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.txtSortOrder.Location = New System.Drawing.Point(96, 24)
        Me.txtSortOrder.MaxLength = 4
        Me.txtSortOrder.Name = "txtSortOrder"
        Me.txtSortOrder.ReadOnly = True
        Me.txtSortOrder.Size = New System.Drawing.Size(80, 22)
        Me.txtSortOrder.TabIndex = 0
        Me.txtSortOrder.Text = ""
        '
        'Label13
        '
        Me.Label13.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.Label13.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Label13.Location = New System.Drawing.Point(8, 24)
        Me.Label13.Name = "Label13"
        Me.Label13.Size = New System.Drawing.Size(80, 16)
        Me.Label13.TabIndex = 101
        Me.Label13.Text = "Sort Order"
        Me.Label13.TextAlign = System.Drawing.ContentAlignment.BottomLeft
        '
        'Label11
        '
        Me.Label11.Location = New System.Drawing.Point(184, 48)
        Me.Label11.Name = "Label11"
        Me.Label11.Size = New System.Drawing.Size(168, 16)
        Me.Label11.TabIndex = 99
        Me.Label11.Text = "<-auto4 Digits [0001-9999]"
        Me.Label11.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'txtBookID
        '
        Me.txtBookID.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.txtBookID.Location = New System.Drawing.Point(96, 48)
        Me.txtBookID.MaxLength = 4
        Me.txtBookID.Name = "txtBookID"
        Me.txtBookID.ReadOnly = True
        Me.txtBookID.Size = New System.Drawing.Size(80, 22)
        Me.txtBookID.TabIndex = 2
        Me.txtBookID.Text = ""
        '
        'Button16
        '
        Me.Button16.Location = New System.Drawing.Point(352, 48)
        Me.Button16.Name = "Button16"
        Me.Button16.Size = New System.Drawing.Size(88, 24)
        Me.Button16.TabIndex = 3
        Me.Button16.Text = "Next ID..."
        Me.Button16.Visible = False
        '
        'Button13
        '
        Me.Button13.Location = New System.Drawing.Point(352, 72)
        Me.Button13.Name = "Button13"
        Me.Button13.Size = New System.Drawing.Size(88, 24)
        Me.Button13.TabIndex = 5
        Me.Button13.Text = "Browse..."
        '
        'Label9
        '
        Me.Label9.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Label9.Location = New System.Drawing.Point(8, 72)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(80, 16)
        Me.Label9.TabIndex = 88
        Me.Label9.Text = "NCX Path"
        Me.Label9.TextAlign = System.Drawing.ContentAlignment.BottomLeft
        '
        'txtNcxPath
        '
        Me.txtNcxPath.Location = New System.Drawing.Point(96, 72)
        Me.txtNcxPath.Name = "txtNcxPath"
        Me.txtNcxPath.ReadOnly = True
        Me.txtNcxPath.Size = New System.Drawing.Size(248, 22)
        Me.txtNcxPath.TabIndex = 4
        Me.txtNcxPath.Text = ""
        '
        'Button12
        '
        Me.Button12.Location = New System.Drawing.Point(352, 256)
        Me.Button12.Name = "Button12"
        Me.Button12.Size = New System.Drawing.Size(88, 32)
        Me.Button12.TabIndex = 11
        Me.Button12.Text = "Cancel"
        '
        'Label3
        '
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.Label3.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Label3.Location = New System.Drawing.Point(8, 48)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(80, 16)
        Me.Label3.TabIndex = 84
        Me.Label3.Text = "Book ID"
        Me.Label3.TextAlign = System.Drawing.ContentAlignment.BottomLeft
        '
        'Button8
        '
        Me.Button8.Image = CType(resources.GetObject("Button8.Image"), System.Drawing.Image)
        Me.Button8.ImageAlign = System.Drawing.ContentAlignment.MiddleRight
        Me.Button8.Location = New System.Drawing.Point(96, 256)
        Me.Button8.Name = "Button8"
        Me.Button8.Size = New System.Drawing.Size(248, 32)
        Me.Button8.TabIndex = 10
        Me.Button8.Text = "Save && Update"
        '
        'Button17
        '
        Me.Button17.Location = New System.Drawing.Point(352, 24)
        Me.Button17.Name = "Button17"
        Me.Button17.Size = New System.Drawing.Size(88, 24)
        Me.Button17.TabIndex = 1
        Me.Button17.Text = "Next Order..."
        Me.Button17.Visible = False
        '
        'txtBookDetail
        '
        Me.txtBookDetail.Location = New System.Drawing.Point(96, 120)
        Me.txtBookDetail.MaxLength = 250
        Me.txtBookDetail.Multiline = True
        Me.txtBookDetail.Name = "txtBookDetail"
        Me.txtBookDetail.Size = New System.Drawing.Size(344, 96)
        Me.txtBookDetail.TabIndex = 7
        Me.txtBookDetail.Text = ""
        '
        'Label10
        '
        Me.Label10.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Label10.Location = New System.Drawing.Point(8, 120)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(80, 16)
        Me.Label10.TabIndex = 97
        Me.Label10.Text = "บทคัดย่อ"
        Me.Label10.TextAlign = System.Drawing.ContentAlignment.BottomLeft
        '
        'Label6
        '
        Me.Label6.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Label6.Location = New System.Drawing.Point(8, 224)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(72, 24)
        Me.Label6.TabIndex = 83
        Me.Label6.Text = "เสียง TTS"
        Me.Label6.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'ComboBox3
        '
        Me.ComboBox3.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBox3.Location = New System.Drawing.Point(96, 224)
        Me.ComboBox3.Name = "ComboBox3"
        Me.ComboBox3.Size = New System.Drawing.Size(248, 24)
        Me.ComboBox3.TabIndex = 8
        '
        'Button6
        '
        Me.Button6.Location = New System.Drawing.Point(352, 224)
        Me.Button6.Name = "Button6"
        Me.Button6.Size = New System.Drawing.Size(88, 24)
        Me.Button6.TabIndex = 9
        Me.Button6.Text = "Test"
        '
        'Label7
        '
        Me.Label7.ImageAlign = System.Drawing.ContentAlignment.BottomLeft
        Me.Label7.Location = New System.Drawing.Point(8, 96)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(80, 16)
        Me.Label7.TabIndex = 82
        Me.Label7.Text = "ชื่อหนังสือไทย"
        Me.Label7.TextAlign = System.Drawing.ContentAlignment.BottomLeft
        '
        'txtBookName
        '
        Me.txtBookName.Location = New System.Drawing.Point(96, 96)
        Me.txtBookName.MaxLength = 120
        Me.txtBookName.Name = "txtBookName"
        Me.txtBookName.Size = New System.Drawing.Size(344, 22)
        Me.txtBookName.TabIndex = 6
        Me.txtBookName.Text = ""
        '
        'Button2
        '
        Me.Button2.Enabled = False
        Me.Button2.Image = CType(resources.GetObject("Button2.Image"), System.Drawing.Image)
        Me.Button2.ImageAlign = System.Drawing.ContentAlignment.MiddleRight
        Me.Button2.Location = New System.Drawing.Point(320, 112)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(136, 32)
        Me.Button2.TabIndex = 6
        Me.Button2.Text = "Move Down"
        Me.Button2.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'Button1
        '
        Me.Button1.Enabled = False
        Me.Button1.Image = CType(resources.GetObject("Button1.Image"), System.Drawing.Image)
        Me.Button1.ImageAlign = System.Drawing.ContentAlignment.MiddleRight
        Me.Button1.Location = New System.Drawing.Point(320, 72)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(136, 32)
        Me.Button1.TabIndex = 5
        Me.Button1.Text = "Move up"
        Me.Button1.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'ListBox1
        '
        Me.ListBox1.BackColor = System.Drawing.Color.LightBlue
        Me.ListBox1.ItemHeight = 16
        Me.ListBox1.Location = New System.Drawing.Point(472, 40)
        Me.ListBox1.Name = "ListBox1"
        Me.ListBox1.Size = New System.Drawing.Size(312, 404)
        Me.ListBox1.Sorted = True
        Me.ListBox1.TabIndex = 8
        '
        'Label2
        '
        Me.Label2.Location = New System.Drawing.Point(8, 40)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(88, 16)
        Me.Label2.TabIndex = 7
        Me.Label2.Text = "Minor group :"
        '
        'Label1
        '
        Me.Label1.Location = New System.Drawing.Point(8, 8)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(88, 16)
        Me.Label1.TabIndex = 6
        Me.Label1.Text = "Major group :"
        '
        'ComboBox2
        '
        Me.ComboBox2.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBox2.Location = New System.Drawing.Point(104, 40)
        Me.ComboBox2.MaxDropDownItems = 9
        Me.ComboBox2.Name = "ComboBox2"
        Me.ComboBox2.Size = New System.Drawing.Size(352, 24)
        Me.ComboBox2.Sorted = True
        Me.ComboBox2.TabIndex = 1
        '
        'ComboBox1
        '
        Me.ComboBox1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBox1.Location = New System.Drawing.Point(104, 8)
        Me.ComboBox1.MaxDropDownItems = 13
        Me.ComboBox1.Name = "ComboBox1"
        Me.ComboBox1.Size = New System.Drawing.Size(352, 24)
        Me.ComboBox1.Sorted = True
        Me.ComboBox1.TabIndex = 0
        '
        'OpenWaveFileDialog
        '
        Me.OpenWaveFileDialog.Filter = "Wave file|*.wav"
        '
        'OpenNcxFileDialog
        '
        Me.OpenNcxFileDialog.Filter = "Navigation Control File |*.ncx"
        '
        'FrmBookUpload
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 13)
        Me.ClientSize = New System.Drawing.Size(794, 522)
        Me.Controls.Add(Me.Panel1)
        Me.Controls.Add(Me.GroupBox1)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow
        Me.Name = "FrmBookUpload"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "FrmBookUpload"
        Me.GroupBox1.ResumeLayout(False)
        Me.Panel1.ResumeLayout(False)
        Me.GroupBox2.ResumeLayout(False)
        Me.ResumeLayout(False)

    End Sub

#End Region

    Dim currCatagory As String
    Dim myConn As OleDbConnection
    Dim myReader As OleDbDataReader

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        If FolderBrowserDialog1.ShowDialog() = DialogResult.OK Then
            TextBox1.Text = FolderBrowserDialog1.SelectedPath
            'Clear checking result.
            Label4.Text = ""
            Me.Panel1.Enabled = False
        End If
    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        'test DB Connection
        'test catPrompts Folder
        'test Read/Write/Delete File from working directory

        'Change status of checking
        Label4.Text = "Checking..."
        ComboBox1.Items.Clear()
        ComboBox2.Items.Clear()

        Try
            'Try to open and close DB connection with read write mode
            myConn = New OleDbConnection("Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" & Trim(TextBox1.Text) & "\Books.mdb")
            myConn.Open()

            Dim myCmd As OleDbCommand = New OleDbCommand("select * from TbBookCategory where CategoryCode like '__000'", myConn)
            myReader = myCmd.ExecuteReader()
            Dim tmpList As String

            While myReader.Read()
                If (IsDBNull(myReader.Item("CategoryMajorCode")) = False) And _
                   (IsDBNull(myReader.Item("CategoryPrimaryName")) = False) Then

                    tmpList = myReader.Item("CategoryMajorCode")
                    tmpList = tmpList & " : "
                    tmpList = tmpList & myReader.Item("CategoryPrimaryName")
                    ComboBox1.Items.Add(tmpList)
                End If
            End While

            myConn.Close()

            Dim sw As StreamWriter = New StreamWriter(Application.StartupPath & "\TestFile.txt")
            ' Add some text to the file.
            sw.WriteLine("This is the test file.")
            ' Arbitrary objects can also be written to the file.
            sw.Write("The date is: ")
            sw.Write(DateTime.Now)
            sw.Close()

            If CopyMyFile(Application.StartupPath & "\TestFile.txt", TextBox1.Text & "\catPrompts\TestFile.txt") = True Then
                'Change status of checking
                Label4.Text = "Success."
                Panel1.Enabled = True

                'เลือก Major = 1 (ถ้ามี)
                If ComboBox1.Items.Count > 0 Then
                    ComboBox1.SelectedIndex = 0
                End If
            Else
                'ถ้า Error
                ComboBox1.Items.Clear()
            End If

        Catch ex As Exception
            'Change status of checking
            Label4.Text = "Fail."
            MsgBox("Fail.")
        End Try
    End Sub

    'Custom functions
    Sub ChangeTTS(ByVal selectedIndex As Byte, ByVal HaveToSay As Boolean)
        If selectedIndex > -1 Then
            'Set voice object to voice name selected in list box
            V.Voice = V.GetVoices().Item(selectedIndex)

            On Error GoTo Error_Handle
            If (ComboBox1.Text = "PPA ตาทิพย์") Then
                'Check process name
                '   "windows_tatip.e" for windows 2000 (limited at 15 characters)
                '   "windows_tatip.exe" for windows 2003
                If (FindProcess("windows_tatip.e") = False) And (FindProcess("windows_tatip.exe") = False) Then
                    'There is no any running process of windows_tatip.
                    MsgBox("You Selected PPA Tatip engine for conversion but PPA Tatip is not running. Program will automatically open PPA Tatip.", MsgBoxStyle.Information, "Open PPA Tatip.")
                    Dim program As New Process
                    program.StartInfo.FileName = "C:\Program Files\PPA Tatip\interface\windows_tatip.exe"
                    program.StartInfo.Arguments = " "
                    program.Start()
                End If
            End If

            On Error Resume Next
            ' Set output stream to speaker
            V.AllowAudioOutputFormatChangesOnNextSet = True
            V.AudioOutputStream = Nothing

            'The new voice speaks its own name
            If HaveToSay = True Then
                V.Speak("")
                V.WaitUntilDone(-1)
            End If
        End If
        Exit Sub

Error_Handle:
        MsgBox("Fail to open PPA Tatip. Please open PPA Tatip manually", MsgBoxStyle.Information, "Fail to open PPA Tatip.")

    End Sub

    Function FindProcess(ByVal Process As Object) As Boolean
        Dim objWMIService As Object, colProcesses As Object
        objWMIService = GetObject("winmgmts:")
        colProcesses = objWMIService.ExecQuery("Select * from Win32_Process where name='" & Process & "'")
        If colProcesses.Count Then FindProcess = True
    End Function

    Function CopyMyFile(ByVal path1 As String, ByVal path2 As String) As Boolean
        Try
            'Specify the directories you want to manipulate.
            Dim fi1 As FileInfo = New FileInfo(path1)
            Dim fi2 As FileInfo = New FileInfo(path2)
            'Ensure that the target does not exist.
            'fi2.Delete()
            'Copy the file.
            'fi1.CopyTo(path2)
            'Try to copy it again, which should succeed.
            fi1.CopyTo(path2, True)
            CopyMyFile = True
        Catch
            CopyMyFile = False
        End Try
    End Function



    Private Sub FrmBookUpload_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'Me.Button5_Click(sender, e)

        'Get each token in the collection returned by GetVoices
        Dim strVoice As String
        For Each T In V.GetVoices
            strVoice = T.GetDescription             'The token's name
            ComboBox3.Items.Add(strVoice)           'Add to listbox
        Next
    End Sub

    Private Sub Button7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button7.Click
        Button12_Click(sender, e)   'clear all old data
        ComboBox1.Enabled = False   'block changing Major
        ComboBox2.Enabled = False   'block changing Minor
        Button1.Enabled = False     'block changing
        Button2.Enabled = False     'block changing
        Button7.Enabled = False     'block changing
        Button9.Enabled = False     'block changing
        Button10.Enabled = False    'block changing
        Button11.Enabled = False    'block changing
        ListBox1.Enabled = False
        GroupBox2.Enabled = True
        Button16_Click(sender, e)   'find and available slot for BookID
        Button17_Click(sender, e)   'find and available slot for SortOrder
        Button13.Focus()
    End Sub

    'Private Sub CheckBox1_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs)
    '    If CheckBox1.Checked = True Then
    '        txtBookNameAudioPath.Text = "Auto-Generate from Text to Speech"
    '        txtBookName.ReadOnly = True
    '        Me.Button3.Enabled = False
    '        ComboBox3.Enabled = True
    '    Else
    '        txtBookNameAudioPath.Text = ""
    '        txtBookName.ReadOnly = False
    '        Me.Button3.Enabled = True
    '        ComboBox3.Enabled = False
    '        ComboBox3.SelectedIndex = -1
    '    End If
    'End Sub

    Private Sub ComboBox3_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ComboBox3.SelectedIndexChanged
        If ComboBox3.SelectedIndex > -1 Then
            ChangeTTS(ComboBox3.SelectedIndex, True)
        End If
    End Sub

    Private Sub ComboBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ComboBox1.SelectedIndexChanged
        'Clear all old values
        ComboBox2.Items.Clear()

        myConn.Open()
        Dim tmpList As String = Trim(Microsoft.VisualBasic.Left(ComboBox1.SelectedItem, 2))
        Dim myCmd As OleDbCommand = New OleDbCommand("select * from TbBookCategory where CategoryCode like '" & tmpList & "___'", myConn)
        myReader = myCmd.ExecuteReader()

        While myReader.Read()
            If (IsDBNull(myReader.Item("CategoryMinorCode")) = False) And _
                (IsDBNull(myReader.Item("CategoryPrimaryName")) = False) And _
                (myReader.Item("CategoryMinorCode") <> "000") Then

                tmpList = myReader.Item("CategoryPrimaryName")
                tmpList = myReader.Item("CategoryMinorCode") & " : " & Trim(tmpList)
                ComboBox2.Items.Add(tmpList)

            End If
        End While

        myReader.Close()
        myConn.Close()

        'เลือก Minor = 1 (ถ้ามี)
        If ComboBox2.Items.Count > 0 Then
            ComboBox2.SelectedIndex = 0
        End If
    End Sub

    Private Sub Button12_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button12.Click
        'CheckBox1.Checked = False
        'CheckBox2.Checked = False
        txtBookID.Text = ""
        txtNcxPath.Text = ""
        txtSortOrder.Text = ""
        txtBookName.Text = ""
        'txtBookNameAudioPath.Text = ""
        txtBookDetail.Text = ""
        'txtBookDetailAudioPath.Text = ""

        ComboBox1.Enabled = True
        ComboBox2.Enabled = True
        Button1.Enabled = True     'unblock changing
        Button2.Enabled = True     'unblock changing
        Button7.Enabled = True     'unblock changing
        Button9.Enabled = True     'unblock changing
        Button10.Enabled = True    'unblock changing
        Button11.Enabled = True    'unblock changing
        ListBox1.Enabled = True
        GroupBox2.Enabled = False
    End Sub

    Private Sub Button8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button8.Click
        If Trim(txtBookID.Text) = "" Then
            MsgBox("ไม่มีการระบุ Book ID ไว้")
            Exit Sub
        End If

        If Trim(txtBookName.Text) = "" Then
            MsgBox("ไม่มีการระบุชื่อหนังสือไว้")
            Exit Sub
        End If

        If Trim(ComboBox3.SelectedIndex < 0) Then
            MsgBox("ไม่มีการระบุ Text to Speech ไว้")
            Exit Sub
        End If

        If Trim(txtBookDetail.Text) = "" Then
            txtBookDetail.Text = "หนังสือเล่มนี้ไม่มีบทคัดย่อ"
        End If

        If MsgBox("คุณต้องการบันทึกการเปลี่ยนแปลงข้อมูล Book ID = " & txtBookID.Text & " ใช่ไหม?", MsgBoxStyle.YesNo, "กรุณายืนยัน") = MsgBoxResult.Yes Then
            '///////////////////////////////////////////////////
            'Copy or Genarate Wave file to bookPrompts directory
            '///////////////////////////////////////////////////
            Dim BookNameFilePath As String = TextBox1.Text & "\bookPrompts\" & currCatagory & txtBookID.Text & "p.wav"
            Dim BookDetailFilePath As String = TextBox1.Text & "\bookPrompts\" & currCatagory & txtBookID.Text & "d.wav"

            Try
                ' Ensure that the target does not exist.
                File.Delete(BookNameFilePath)
            Catch ex As Exception
            End Try

            Try
                ' Ensure that the target does not exist.
                File.Delete(BookDetailFilePath)
            Catch ex As Exception
            End Try

            'If CheckBox1.Checked = True Then
            Try
                'AUTO-GENERATE
                'Change TTS for book name
                If ComboBox3.SelectedIndex > -1 Then
                    ChangeTTS(ComboBox3.SelectedIndex, False)
                End If

                ' create a wave stream
                Dim cpFileStream As New SpFileStream
                cpFileStream.Format.Type = SpeechAudioFormatType.SAFT11kHz8BitMono

                ' Generate Book Name  
                cpFileStream.Open(BookNameFilePath, SpeechStreamFileMode.SSFMCreateForWrite, False)
                ' Set output stream to the file stream
                V.AllowAudioOutputFormatChangesOnNextSet = False
                V.AudioOutputStream = cpFileStream
                ' speak the given text with given flags
                V.Speak(txtBookName.Text, SpeechVoiceSpeakFlags.SVSFDefault)
                ' wait until it's done speaking with a really really long timeout.
                ' the tiemout value is in unit of millisecond. -1 means forever.
                V.WaitUntilDone(-1)
                ' close the file stream
                cpFileStream.Close()

                ' Generate Book Detail
                cpFileStream.Open(BookDetailFilePath, SpeechStreamFileMode.SSFMCreateForWrite, False)
                ' Set output stream to the file stream
                V.AllowAudioOutputFormatChangesOnNextSet = False
                V.AudioOutputStream = cpFileStream
                ' speak the given text with given flags
                V.Speak(txtBookDetail.Text, SpeechVoiceSpeakFlags.SVSFDefault)
                ' wait until it's done speaking with a really really long timeout.
                ' the tiemout value is in unit of millisecond. -1 means forever.
                V.WaitUntilDone(-1)
                ' close the file stream
                cpFileStream.Close()

                cpFileStream = Nothing
            Catch
                MsgBox("ไม่สามารถทำงานกับ Text to Speech ได้, กรุณาตรวจสอบใหม่อีกครั้ง", MsgBoxStyle.OKOnly, "Incomplete")
                Exit Sub
            End Try
            'ElseIf (Trim(txtBookNameAudioPath.Text) = currCatagory & txtBookID.Text & ".wav") Then
            'no need to change audio file.

            'Else
            'If CopyMyFile(txtBookNameAudioPath.Text, filePath) = False Then
            'MsgBox("ไม่สามารถคัดลอกไฟล์เสียงที่ระบุในช่อง Audio Name ได้, กรุณาตรวจสอบใหม่อีกครั้งโดยใช้ชื่อไฟล์ + Path เต็มๆ", MsgBoxStyle.OKOnly, "Incomplete")
            'Exit Sub
            'End If
            'End If

            '    '/////////////////////////////////////////////////////
            '    'Copy or Genarate Wave file to detailPrompts directory
            '    '/////////////////////////////////////////////////////
            '    filePath = TextBox1.Text & "\detailPrompts\" & currCatagory & txtBookID.Text & ".wav"
            '    'If CheckBox2.Checked = True Then
            '    Try
            '        'AUTO-GENERATE
            '        'Change TTS for book name
            '        If ComboBox4.SelectedIndex > -1 Then
            '            ChangeTTS(ComboBox4.SelectedIndex, False)
            '        End If

            '        ' create a wave stream
            '        Dim cpFileStream As New SpFileStream
            '        cpFileStream.Format.Type = SpeechAudioFormatType.SAFT11kHz8BitMono

            '        ' Ensure that the target does not exist.
            '        File.Delete(filePath)

            '        cpFileStream.Open(filePath, SpeechStreamFileMode.SSFMCreateForWrite, False)

            '        ' Set output stream to the file stream
            '        V.AllowAudioOutputFormatChangesOnNextSet = False
            '        V.AudioOutputStream = cpFileStream

            '        ' speak the given text with given flags
            '        V.Speak(txtBookDetail.Text, SpeechVoiceSpeakFlags.SVSFDefault)

            '        ' wait until it's done speaking with a really really long timeout.
            '        ' the tiemout value is in unit of millisecond. -1 means forever.
            '        V.WaitUntilDone(-1)

            '        ' close the file stream
            '        cpFileStream.Close()
            '        cpFileStream = Nothing
            '    Catch
            '        MsgBox("ไม่สามารถทำงานกับ Text to Speech ได้, กรุณาตรวจสอบใหม่อีกครั้ง", MsgBoxStyle.OKOnly, "Incomplete")
            '        Exit Sub
            '    End Try
            'ElseIf (Trim(txtBookDetailAudioPath.Text) = currCatagory & txtBookID.Text & ".wav") Then
            '    'no need to change audio file.
            'Else
            '    If CopyMyFile(txtBookDetailAudioPath.Text, filePath) = False Then
            '        MsgBox("ไม่สามารถคัดลอกไฟล์เสียงที่ระบุในช่อง Audio Detail ได้, กรุณาตรวจสอบใหม่อีกครั้งโดยใช้ชื่อไฟล์ + Path เต็มๆ", MsgBoxStyle.OKOnly, "Incomplete")
            '        Exit Sub
            '    End If
            'End If

            '///////////////////////////////////////////////////
            'update database (delete old & add new) fot bookName
            '///////////////////////////////////////////////////
            Try
                myConn.Open()

                Dim tmpList As String = Trim(txtBookID.Text)
                Dim myCmd As OleDbCommand = New OleDbCommand("delete from TbBookInfo where CategoryCode like '" & currCatagory & "' and BookID like '" & tmpList & "'", myConn)
                myCmd.ExecuteNonQuery()

                tmpList = "insert into TbBookInfo(9DigitBookCode,BookID,BookName,CategoryCode,BookDetail,SortOrder) values('" & currCatagory & tmpList & "','" & tmpList & "','" & Trim(txtBookName.Text) & "','" & currCatagory & "','" & Trim(txtBookDetail.Text) & "','" & Trim(txtSortOrder.Text) & "')"
                myCmd = New OleDbCommand(tmpList, myConn)
                myCmd.ExecuteNonQuery()

                myConn.Close()
            Catch err As Exception
                myConn.Close()
                MsgBox("ไม่สามารถบันทึกข้อมูลได้ กรุณาตรวจสอบข้อมูลใหม่อีกครั้ง " & vbCrLf & err.Message, MsgBoxStyle.OKOnly, "Incomplete")
            End Try

            'ระบุ Directory ต้นทาง และ ปลายทาง
            Dim strSourceDirectory As String = Microsoft.VisualBasic.Left(txtNcxPath.Text, txtNcxPath.Text.Length - 7)
            Dim strDestinationDirectory As String = TextBox1.Text & "\Library\" & currCatagory & "\" & txtBookID.Text & "\"

            If strSourceDirectory <> "" Then
                Try
                    'Deltree สำหรับ Directory ปลายทาง
                    Directory.Delete(strDestinationDirectory, True)
                Catch err As Exception
                End Try

                Try
                    'สร้าง Directory ปลายทาง
                    Directory.CreateDirectory(strDestinationDirectory)
                    'คัดลอกไปยัง Directory ปลายทาง
                    Dim f() As String = Directory.GetFiles(strSourceDirectory)
                    For i As Integer = 0 To UBound(f)
                        File.Copy(f(i), strDestinationDirectory & fileNameWithoutThePath(f(i)))
                    Next
                    MsgBox("บันทึกข้อมูลเรียบร้อยแล้ว", MsgBoxStyle.OKOnly, "Completed")
                Catch err As Exception
                    MsgBox("ไม่คัดลอกข้อมูลได้ กรุณาตรวจสอบข้อมูลใหม่อีกครั้ง", MsgBoxStyle.OKOnly, "Incomplete")
                End Try

            End If

            'refresh major
            Me.Button11_Click(sender, e)
        End If
    End Sub

    Public Function fileNameWithoutThePath(ByVal b As String) As String
        Dim j As Int16
        j = Convert.ToInt16(b.LastIndexOf("\"))
        Return b.Substring(j + 1)
    End Function



    'Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
    '    If OpenWaveFileDialog.ShowDialog() = DialogResult.OK Then
    '        txtBookNameAudioPath.Text = OpenWaveFileDialog.FileName
    '    End If
    'End Sub

    Private Sub Button13_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button13.Click
        If OpenNcxFileDialog.ShowDialog() = DialogResult.OK Then
            txtNcxPath.Text = OpenNcxFileDialog.FileName
        End If
    End Sub

    'Private Sub Button14_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
    '    If OpenWaveFileDialog.ShowDialog() = DialogResult.OK Then
    '        txtBookDetailAudioPath.Text = OpenWaveFileDialog.FileName
    '    End If
    'End Sub

    'Private Sub CheckBox2_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs)
    '    If CheckBox1.Checked = True Then
    '        txtBookDetailAudioPath.Text = "Auto-Generate from Text to Speech"
    '        txtBookDetail.ReadOnly = True
    '        Me.Button14.Enabled = False
    '        ComboBox4.Enabled = True
    '    Else
    '        txtBookDetailAudioPath.Text = ""
    '        txtBookDetail.ReadOnly = False
    '        Me.Button14.Enabled = True
    '        ComboBox4.Enabled = False
    '        ComboBox4.SelectedIndex = -1
    '    End If
    'End Sub

    'Private Sub ComboBox4_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs)
    '    If ComboBox4.SelectedIndex > -1 Then
    '        ChangeTTS(ComboBox4.SelectedIndex, True)
    '    End If
    'End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        If ComboBox3.SelectedIndex > -1 Then
            ChangeTTS(ComboBox3.SelectedIndex, False)
        End If

        'If (Trim(txtBookNameAudioPath.Text) = currCatagory & txtBookID.Text & ".wav") Then
        '    'Use PlaySoundFile function with preparation path
        '    PlaySoundFile(TextBox1.Text & "\bookPrompts\" & Trim(txtBookNameAudioPath.Text))
        '
        'ElseIf (Microsoft.VisualBasic.Right(Trim(txtBookNameAudioPath.Text), 4) = ".wav") Then
        '    'Use PlaySoundFile function without preparation path
        '    PlaySoundFile(Trim(txtBookNameAudioPath.Text))
        '
        'ElseIf Trim(txtBookNameAudioPath.Text) = "Auto-Generate from Text to Speech" Then
            'use text to speech function

        ' Set output stream to speaker
        V.AllowAudioOutputFormatChangesOnNextSet = True
        V.AudioOutputStream = Nothing

        'The new voice speaks its own name
        V.Speak(txtBookName.Text)
        V.WaitUntilDone(-1)
        V.Speak(txtBookDetail.Text)
        V.WaitUntilDone(-1)
        'End If
    End Sub

    'Private Sub Button15_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
    '    If ComboBox4.SelectedIndex > -1 Then
    '        ChangeTTS(ComboBox4.SelectedIndex, False)
    '    End If

    '    If (Trim(txtBookDetailAudioPath.Text) = currCatagory & txtBookID.Text & ".wav") Then
    '        'Use PlaySoundFile function with preparation path
    '        PlaySoundFile(TextBox1.Text & "\detailPrompts\" & Trim(txtBookDetailAudioPath.Text))

    '    ElseIf (Microsoft.VisualBasic.Right(Trim(txtBookDetailAudioPath.Text), 4) = ".wav") Then
    '        'Use PlaySoundFile function without preparation path
    '        PlaySoundFile(Trim(txtBookDetailAudioPath.Text))

    '    ElseIf Trim(txtBookDetailAudioPath.Text) = "Auto-Generate from Text to Speech" Then
    '        'use text to speech function

    '        ' Set output stream to speaker
    '        V.AllowAudioOutputFormatChangesOnNextSet = True
    '        V.AudioOutputStream = Nothing

    '        'The new voice speaks its own name
    '        V.Speak(txtBookDetail.Text)
    '        V.WaitUntilDone(-1)
    '    End If
    'End Sub

    Private Sub ComboBox2_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ComboBox2.SelectedIndexChanged
        'Clear old data in form & refresh new data
        Button11_Click(sender, e)

        'เลือก Minor = 1 (ถ้ามี)
        If ListBox1.Items.Count > 0 Then
            ListBox1.SelectedIndex = 0
        End If
    End Sub

    Private Sub Button16_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button16.Click
        txtBookID.Text = FindAvailableSlot(9) 'for BookID
    End Sub

    Private Sub Button17_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button17.Click
        txtSortOrder.Text = FindAvailableSlot(2) 'for SortOrder
    End Sub
    Private Function FindAvailableSlot(ByVal startPosition As Byte) As String
        'for SortOrder -> startPosition = 2 (#XXXX)
        'for BookID    -> startposition = 9 (IDXXXX)

        'โปรแกรมหา ID ว่าง
        Dim i, j As Integer
        Dim k As String
        Dim FoundDuplicate As Boolean

        'เอาค่าเริ่มต้น (ถ้ามี)
        'If startValue = "" Then
        '    i = 1
        'Else
        '    i = Val(startValue) + 1
        'End If

        For i = 1 To 9999
            k = Format(i, "0000")
            FoundDuplicate = False

            For j = 0 To ListBox1.Items.Count - 1
                If (Trim(k) = Microsoft.VisualBasic.Mid(Trim(ListBox1.Items(j)), startPosition, 4)) Then
                    FoundDuplicate = True
                End If
            Next j

            If FoundDuplicate = False Then
                FindAvailableSlot = k
                Exit For
            End If
        Next i
        FindAvailableSlot = ""
    End Function



    Private Sub Button11_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button11.Click
        'Clear all information and back to normal state
        Button12_Click(sender, e) 'the cancel button

        'set public variable currCatagory
        currCatagory = Microsoft.VisualBasic.Left(Trim(ComboBox1.Text), 2) & Microsoft.VisualBasic.Left(Trim(ComboBox2.Text), 3)

        'Clear all old values
        ListBox1.Items.Clear()

        myConn.Open()
        Dim tmpList As String = currCatagory
        Dim myCmd As OleDbCommand = New OleDbCommand("select * from TbBookInfo where CategoryCode like '" & tmpList & "'", myConn)
        myReader = myCmd.ExecuteReader()

        While myReader.Read()
            If (IsDBNull(myReader.Item("BookID")) = False) And _
               (IsDBNull(myReader.Item("BookName")) = False) And _
               (IsDBNull(myReader.Item("SortOrder")) = False) Then
                tmpList = "#" & myReader.Item("SortOrder")
                tmpList = tmpList & " ID" & myReader.Item("BookID")
                tmpList = tmpList & " : " & myReader.Item("BookName")

                ListBox1.Items.Add(tmpList)

            End If
        End While

        myReader.Close()
        myConn.Close()


        'เลือก Minor = 1 (ถ้ามี)
        'If ListBox1.Items.Count > 0 Then
        '    ListBox1.SelectedIndex = 0
        'End If
    End Sub

    Private Sub Button10_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button10.Click
        If ListBox1.Items.Count > 0 Then
            If MsgBox("คุณต้องการลบ " & ListBox1.SelectedItem & " ใช่ไหม?", MsgBoxStyle.YesNo, "กรุณายืนยัน") = MsgBoxResult.Yes Then
                myConn.Open()
                Dim tmpList As String = Trim(txtBookID.Text)
                Dim myCmd As OleDbCommand = New OleDbCommand("delete from TbBookInfo where CategoryCode like '" & currCatagory & "' and BookID like '" & tmpList & "'", myConn)
                myCmd.ExecuteNonQuery()
                myConn.Close()

                Try
                    'Deltree ของ Directory ปลายทาง
                    Dim strDestinationDirectory As String = TextBox1.Text & "\Library\" & currCatagory & "\" & txtBookID.Text & "\"
                    Directory.Delete(strDestinationDirectory, True)
                Catch err As Exception
                End Try

                Try
                    'ลบไฟล์เสียงของชื่อหนังสือ
                    Dim BookNameFilePath As String = TextBox1.Text & "\bookPrompts\" & currCatagory & txtBookID.Text & "n.wav"
                    File.Delete(BookNameFilePath)
                Catch ex As Exception
                End Try

                Try
                    'ลบไฟล์เสียงของรายละเอียดหนังสือ
                    Dim BookDetailFilePath As String = TextBox1.Text & "\bookPrompts\" & currCatagory & txtBookID.Text & "d.wav"
                    File.Delete(BookDetailFilePath)
                Catch ex As Exception
                End Try

                MsgBox("การลบเสร็จสมบูรณ์", MsgBoxStyle.OKOnly, "สมบูรณ์")
                Me.Button11_Click(sender, e)
            End If
        Else
            MsgBox("ไม่มีหนังสือให้ลบ", MsgBoxStyle.OKOnly, "คำเตือน")
        End If

    End Sub

    Private Sub ListBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ListBox1.SelectedIndexChanged
        'CheckBox1.Checked = False
        'CheckBox2.Checked = False
        GroupBox1.Enabled = False
        txtSortOrder.Text = Microsoft.VisualBasic.Mid(ListBox1.SelectedItem, 2, 4)
        txtBookID.Text = Microsoft.VisualBasic.Mid(ListBox1.SelectedItem, 9, 4)
        txtNcxPath.Text = "dtb.ncx"
        'txtBookNameAudioPath.Text = currCatagory & Microsoft.VisualBasic.Mid(ListBox1.SelectedItem, 9, 4) & ".wav"
        'txtBookDetailAudioPath.Text = currCatagory & Microsoft.VisualBasic.Mid(ListBox1.SelectedItem, 9, 4) & ".wav"

        myConn.Open()
        Dim tmpList As String = Trim(txtBookID.Text)
        Dim myCmd As OleDbCommand = New OleDbCommand("select * from TbBookInfo where CategoryCode like '" & currCatagory & "' and BookID like '" & tmpList & "'", myConn)
        myReader = myCmd.ExecuteReader()

        While myReader.Read()
            If (IsDBNull(myReader.Item("BookID")) = False) And _
               (IsDBNull(myReader.Item("BookName")) = False) And _
               (IsDBNull(myReader.Item("BookDetail")) = False) Then

                'enter new value
                txtBookID.Text = myReader.Item("BookID")
                txtBookName.Text = myReader.Item("BookName")
                txtBookDetail.Text = myReader.Item("BookDetail")

            End If
        End While

        myReader.Close()
        myConn.Close()

    End Sub


    Private Sub Button9_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button9.Click
        If ListBox1.Items.Count > 0 Then
            ComboBox1.Enabled = False   'block changing Major
            ComboBox2.Enabled = False   'block changing Minor
            Button1.Enabled = False     'block changing
            Button2.Enabled = False     'block changing
            Button7.Enabled = False     'block changing
            Button9.Enabled = False     'block changing
            Button10.Enabled = False    'block changing
            Button11.Enabled = False    'block changing
            ListBox1.Enabled = False
            GroupBox2.Enabled = True
            GroupBox2.Enabled = True
        Else
            MsgBox("ไม่มีหนังสือให้แก้ไข", MsgBoxStyle.OKOnly, "คำเตือน")
        End If

    End Sub


    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        'MOVE UP
        If ListBox1.Items.Count > 0 Then
            If ListBox1.SelectedIndex <> 0 Then
                Dim intRememberSelectedIndex As Integer = ListBox1.SelectedIndex
                Dim prevOrder As String = Trim(Microsoft.VisualBasic.Mid(ListBox1.Items(ListBox1.SelectedIndex - 1), 2, 4))
                Dim currOrder As String = Trim(Microsoft.VisualBasic.Mid(ListBox1.SelectedItem, 2, 4))
                Dim prevID As String = Trim(Microsoft.VisualBasic.Mid(ListBox1.Items(ListBox1.SelectedIndex - 1), 9, 4))
                Dim currID As String = Trim(Microsoft.VisualBasic.Mid(ListBox1.SelectedItem, 9, 4))

                myConn.Open()
                Dim myCmd1 As OleDbCommand = New OleDbCommand("Update TbBookInfo SET SortOrder = '" & prevOrder & "' WHERE CategoryCode = '" & currCatagory & "' AND BookID = '" & currID & "'", myConn)
                myCmd1.ExecuteNonQuery()
                Dim myCmd2 As OleDbCommand = New OleDbCommand("Update TbBookInfo SET SortOrder = '" & currOrder & "' WHERE CategoryCode = '" & currCatagory & "' AND BookID = '" & prevID & "'", myConn)
                myCmd2.ExecuteNonQuery()
                myConn.Close()

                Button11_Click(sender, e)
                ListBox1.SelectedIndex = intRememberSelectedIndex - 1
            Else '(=0)
                MsgBox("หนังสืออยู่ตำแหน่งเริ่มแรกแล้ว", MsgBoxStyle.OKOnly, "คำเตือน")
            End If
        Else
            MsgBox("ไม่มีหนังสือให้ย้าย", MsgBoxStyle.OKOnly, "คำเตือน")
        End If
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        'MOVE DOWN
        If ListBox1.Items.Count > 0 Then
            If ListBox1.SelectedIndex <> ListBox1.Items.Count - 1 Then
                Dim intRememberSelectedIndex As Integer = ListBox1.SelectedIndex
                Dim nextOrder As String = Trim(Microsoft.VisualBasic.Mid(ListBox1.Items(ListBox1.SelectedIndex + 1), 2, 4))
                Dim currOrder As String = Trim(Microsoft.VisualBasic.Mid(ListBox1.SelectedItem, 2, 4))
                Dim nextID As String = Trim(Microsoft.VisualBasic.Mid(ListBox1.Items(ListBox1.SelectedIndex + 1), 9, 4))
                Dim currID As String = Trim(Microsoft.VisualBasic.Mid(ListBox1.SelectedItem, 9, 4))

                myConn.Open()
                Dim myCmd1 As OleDbCommand = New OleDbCommand("Update(TbBookInfo) SET SortOrder = '" & nextOrder & "' WHERE CategoryCode = '" & currCatagory & "' AND BookID = '" & currID & "'", myConn)
                myCmd1.ExecuteNonQuery()
                Dim myCmd2 As OleDbCommand = New OleDbCommand("Update(TbBookInfo) SET SortOrder = '" & currOrder & "' WHERE CategoryCode = '" & currCatagory & "' AND BookID = '" & nextID & "'", myConn)
                myCmd2.ExecuteNonQuery()
                myConn.Close()

                Button11_Click(sender, e)
                ListBox1.SelectedIndex = intRememberSelectedIndex + 1
            Else '(=ListBox1.Items.Count - 1)
                MsgBox("หนังสืออยู่ตำแหน่งสุดท้ายแล้ว", MsgBoxStyle.OKOnly, "คำเตือน")
            End If
        Else
            MsgBox("ไม่มีหนังสือให้ย้าย", MsgBoxStyle.OKOnly, "คำเตือน")
        End If
    End Sub

End Class
