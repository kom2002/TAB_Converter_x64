'namespaces added to support functionality 
Imports System.Data                         'Database support
Imports System.Data.OleDb                   'Oledb support
Imports System
Imports System.IO
Imports SpeechLib

Public Class FrmChangeCatalog
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
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Button4 As System.Windows.Forms.Button
    Friend WithEvents TextBox1 As System.Windows.Forms.TextBox
    Friend WithEvents Button5 As System.Windows.Forms.Button
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents Button7 As System.Windows.Forms.Button
    Friend WithEvents Button11 As System.Windows.Forms.Button
    Friend WithEvents Label12 As System.Windows.Forms.Label
    Friend WithEvents FolderBrowserDialog1 As System.Windows.Forms.FolderBrowserDialog
    Friend WithEvents Button10 As System.Windows.Forms.Button
    Friend WithEvents Button12 As System.Windows.Forms.Button
    Friend WithEvents Button13 As System.Windows.Forms.Button
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Button3 As System.Windows.Forms.Button
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents Button8 As System.Windows.Forms.Button
    Friend WithEvents Button9 As System.Windows.Forms.Button
    Friend WithEvents txtMajorCode As System.Windows.Forms.TextBox
    Friend WithEvents txtMinorCode As System.Windows.Forms.TextBox
    Friend WithEvents Panel1 As System.Windows.Forms.Panel
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents Label15 As System.Windows.Forms.Label
    Friend WithEvents Label17 As System.Windows.Forms.Label
    Friend WithEvents Label8 As System.Windows.Forms.Label
    Friend WithEvents Label9 As System.Windows.Forms.Label
    Friend WithEvents Label10 As System.Windows.Forms.Label
    Friend WithEvents Label14 As System.Windows.Forms.Label
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents Label11 As System.Windows.Forms.Label
    Friend WithEvents txtMinorPrimaryName As System.Windows.Forms.TextBox
    Friend WithEvents txtMajorPrimaryName As System.Windows.Forms.TextBox
    Friend WithEvents cbbMajorTTS As System.Windows.Forms.ComboBox
    Friend WithEvents cbbMinorTTS As System.Windows.Forms.ComboBox
    Friend WithEvents txtMinorSecondaryName As System.Windows.Forms.TextBox
    Friend WithEvents txtMajorSecondaryName As System.Windows.Forms.TextBox
    Friend WithEvents ListBoxMajor As System.Windows.Forms.ListBox
    Friend WithEvents ListBoxMinor As System.Windows.Forms.ListBox
    Friend WithEvents txtMinorDescriptionName As System.Windows.Forms.TextBox
    Friend WithEvents txtMajorDescriptionName As System.Windows.Forms.TextBox
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Dim resources As System.Resources.ResourceManager = New System.Resources.ResourceManager(GetType(FrmChangeCatalog))
        Me.Label1 = New System.Windows.Forms.Label
        Me.Button4 = New System.Windows.Forms.Button
        Me.TextBox1 = New System.Windows.Forms.TextBox
        Me.Button5 = New System.Windows.Forms.Button
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.Label4 = New System.Windows.Forms.Label
        Me.ListBoxMajor = New System.Windows.Forms.ListBox
        Me.Button7 = New System.Windows.Forms.Button
        Me.Button11 = New System.Windows.Forms.Button
        Me.ListBoxMinor = New System.Windows.Forms.ListBox
        Me.Label12 = New System.Windows.Forms.Label
        Me.FolderBrowserDialog1 = New System.Windows.Forms.FolderBrowserDialog
        Me.txtMinorCode = New System.Windows.Forms.TextBox
        Me.Button10 = New System.Windows.Forms.Button
        Me.txtMinorPrimaryName = New System.Windows.Forms.TextBox
        Me.Button12 = New System.Windows.Forms.Button
        Me.Button13 = New System.Windows.Forms.Button
        Me.Label3 = New System.Windows.Forms.Label
        Me.txtMajorCode = New System.Windows.Forms.TextBox
        Me.Button3 = New System.Windows.Forms.Button
        Me.Label7 = New System.Windows.Forms.Label
        Me.txtMajorPrimaryName = New System.Windows.Forms.TextBox
        Me.Button8 = New System.Windows.Forms.Button
        Me.Button9 = New System.Windows.Forms.Button
        Me.cbbMajorTTS = New System.Windows.Forms.ComboBox
        Me.cbbMinorTTS = New System.Windows.Forms.ComboBox
        Me.Panel1 = New System.Windows.Forms.Panel
        Me.txtMinorDescriptionName = New System.Windows.Forms.TextBox
        Me.txtMajorDescriptionName = New System.Windows.Forms.TextBox
        Me.txtMinorSecondaryName = New System.Windows.Forms.TextBox
        Me.txtMajorSecondaryName = New System.Windows.Forms.TextBox
        Me.Label5 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label17 = New System.Windows.Forms.Label
        Me.Label15 = New System.Windows.Forms.Label
        Me.Label8 = New System.Windows.Forms.Label
        Me.Label9 = New System.Windows.Forms.Label
        Me.Label10 = New System.Windows.Forms.Label
        Me.Label14 = New System.Windows.Forms.Label
        Me.Label11 = New System.Windows.Forms.Label
        Me.Label6 = New System.Windows.Forms.Label
        Me.GroupBox1.SuspendLayout()
        Me.Panel1.SuspendLayout()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.Label1.ForeColor = System.Drawing.SystemColors.ActiveCaption
        Me.Label1.Location = New System.Drawing.Point(8, 16)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(72, 16)
        Me.Label1.TabIndex = 20
        Me.Label1.Text = "MAJOR:"
        Me.Label1.TextAlign = System.Drawing.ContentAlignment.BottomLeft
        '
        'Button4
        '
        Me.Button4.Location = New System.Drawing.Point(416, 24)
        Me.Button4.Name = "Button4"
        Me.Button4.Size = New System.Drawing.Size(112, 24)
        Me.Button4.TabIndex = 1
        Me.Button4.Text = "Change Folder"
        '
        'TextBox1
        '
        Me.TextBox1.Cursor = System.Windows.Forms.Cursors.No
        Me.TextBox1.Location = New System.Drawing.Point(8, 24)
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.ReadOnly = True
        Me.TextBox1.Size = New System.Drawing.Size(400, 22)
        Me.TextBox1.TabIndex = 0
        Me.TextBox1.Text = "D:\NBL"
        '
        'Button5
        '
        Me.Button5.Location = New System.Drawing.Point(536, 24)
        Me.Button5.Name = "Button5"
        Me.Button5.Size = New System.Drawing.Size(112, 24)
        Me.Button5.TabIndex = 2
        Me.Button5.Text = "Test Connection"
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.Label4)
        Me.GroupBox1.Controls.Add(Me.TextBox1)
        Me.GroupBox1.Controls.Add(Me.Button5)
        Me.GroupBox1.Controls.Add(Me.Button4)
        Me.GroupBox1.Location = New System.Drawing.Point(8, 0)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(784, 56)
        Me.GroupBox1.TabIndex = 0
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Setting Working Directory:"
        '
        'Label4
        '
        Me.Label4.Location = New System.Drawing.Point(656, 32)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(120, 16)
        Me.Label4.TabIndex = 3
        Me.Label4.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'ListBoxMajor
        '
        Me.ListBoxMajor.BackColor = System.Drawing.Color.FromArgb(CType(255, Byte), CType(192, Byte), CType(128, Byte))
        Me.ListBoxMajor.ItemHeight = 16
        Me.ListBoxMajor.Location = New System.Drawing.Point(8, 40)
        Me.ListBoxMajor.Name = "ListBoxMajor"
        Me.ListBoxMajor.Size = New System.Drawing.Size(384, 244)
        Me.ListBoxMajor.Sorted = True
        Me.ListBoxMajor.TabIndex = 1
        '
        'Button7
        '
        Me.Button7.Image = CType(resources.GetObject("Button7.Image"), System.Drawing.Image)
        Me.Button7.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Button7.Location = New System.Drawing.Point(304, 8)
        Me.Button7.Name = "Button7"
        Me.Button7.Size = New System.Drawing.Size(88, 24)
        Me.Button7.TabIndex = 0
        Me.Button7.Text = "Refresh"
        Me.Button7.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Button11
        '
        Me.Button11.Image = CType(resources.GetObject("Button11.Image"), System.Drawing.Image)
        Me.Button11.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Button11.Location = New System.Drawing.Point(696, 8)
        Me.Button11.Name = "Button11"
        Me.Button11.Size = New System.Drawing.Size(88, 24)
        Me.Button11.TabIndex = 10
        Me.Button11.Text = "Refresh"
        Me.Button11.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'ListBoxMinor
        '
        Me.ListBoxMinor.BackColor = System.Drawing.Color.FromArgb(CType(255, Byte), CType(224, Byte), CType(192, Byte))
        Me.ListBoxMinor.ItemHeight = 16
        Me.ListBoxMinor.Location = New System.Drawing.Point(400, 40)
        Me.ListBoxMinor.Name = "ListBoxMinor"
        Me.ListBoxMinor.Size = New System.Drawing.Size(384, 244)
        Me.ListBoxMinor.Sorted = True
        Me.ListBoxMinor.TabIndex = 11
        '
        'Label12
        '
        Me.Label12.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.Label12.ForeColor = System.Drawing.SystemColors.ActiveCaption
        Me.Label12.Location = New System.Drawing.Point(400, 16)
        Me.Label12.Name = "Label12"
        Me.Label12.Size = New System.Drawing.Size(64, 16)
        Me.Label12.TabIndex = 27
        Me.Label12.Text = "MINOR:"
        Me.Label12.TextAlign = System.Drawing.ContentAlignment.BottomLeft
        '
        'txtMinorCode
        '
        Me.txtMinorCode.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.txtMinorCode.Location = New System.Drawing.Point(536, 312)
        Me.txtMinorCode.MaxLength = 3
        Me.txtMinorCode.Name = "txtMinorCode"
        Me.txtMinorCode.Size = New System.Drawing.Size(64, 22)
        Me.txtMinorCode.TabIndex = 13
        Me.txtMinorCode.Text = ""
        '
        'Button10
        '
        Me.Button10.Location = New System.Drawing.Point(696, 408)
        Me.Button10.Name = "Button10"
        Me.Button10.Size = New System.Drawing.Size(88, 23)
        Me.Button10.TabIndex = 18
        Me.Button10.Text = "Test"
        '
        'txtMinorPrimaryName
        '
        Me.txtMinorPrimaryName.Location = New System.Drawing.Point(536, 336)
        Me.txtMinorPrimaryName.MaxLength = 120
        Me.txtMinorPrimaryName.Name = "txtMinorPrimaryName"
        Me.txtMinorPrimaryName.Size = New System.Drawing.Size(248, 22)
        Me.txtMinorPrimaryName.TabIndex = 14
        Me.txtMinorPrimaryName.Text = ""
        '
        'Button12
        '
        Me.Button12.Image = CType(resources.GetObject("Button12.Image"), System.Drawing.Image)
        Me.Button12.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Button12.Location = New System.Drawing.Point(536, 440)
        Me.Button12.Name = "Button12"
        Me.Button12.Size = New System.Drawing.Size(152, 32)
        Me.Button12.TabIndex = 19
        Me.Button12.Text = "Save && Update"
        '
        'Button13
        '
        Me.Button13.Image = CType(resources.GetObject("Button13.Image"), System.Drawing.Image)
        Me.Button13.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Button13.Location = New System.Drawing.Point(696, 288)
        Me.Button13.Name = "Button13"
        Me.Button13.Size = New System.Drawing.Size(88, 24)
        Me.Button13.TabIndex = 12
        Me.Button13.Text = "Delete"
        '
        'Label3
        '
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.Label3.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Label3.Location = New System.Drawing.Point(8, 312)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(160, 24)
        Me.Label3.TabIndex = 21
        Me.Label3.Text = "รหัส Major"
        Me.Label3.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'txtMajorCode
        '
        Me.txtMajorCode.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.txtMajorCode.Location = New System.Drawing.Point(136, 312)
        Me.txtMajorCode.MaxLength = 2
        Me.txtMajorCode.Name = "txtMajorCode"
        Me.txtMajorCode.Size = New System.Drawing.Size(72, 22)
        Me.txtMajorCode.TabIndex = 3
        Me.txtMajorCode.Text = ""
        '
        'Button3
        '
        Me.Button3.Location = New System.Drawing.Point(304, 408)
        Me.Button3.Name = "Button3"
        Me.Button3.Size = New System.Drawing.Size(88, 24)
        Me.Button3.TabIndex = 8
        Me.Button3.Text = "Test"
        '
        'Label7
        '
        Me.Label7.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Label7.Location = New System.Drawing.Point(8, 336)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(160, 24)
        Me.Label7.TabIndex = 22
        Me.Label7.Text = "ชื่อ Major ภาษาไทย"
        Me.Label7.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'txtMajorPrimaryName
        '
        Me.txtMajorPrimaryName.Location = New System.Drawing.Point(136, 336)
        Me.txtMajorPrimaryName.MaxLength = 120
        Me.txtMajorPrimaryName.Name = "txtMajorPrimaryName"
        Me.txtMajorPrimaryName.Size = New System.Drawing.Size(256, 22)
        Me.txtMajorPrimaryName.TabIndex = 4
        Me.txtMajorPrimaryName.Text = ""
        '
        'Button8
        '
        Me.Button8.Image = CType(resources.GetObject("Button8.Image"), System.Drawing.Image)
        Me.Button8.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Button8.Location = New System.Drawing.Point(136, 440)
        Me.Button8.Name = "Button8"
        Me.Button8.Size = New System.Drawing.Size(160, 32)
        Me.Button8.TabIndex = 9
        Me.Button8.Text = "Save && Update"
        '
        'Button9
        '
        Me.Button9.Image = CType(resources.GetObject("Button9.Image"), System.Drawing.Image)
        Me.Button9.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Button9.Location = New System.Drawing.Point(304, 288)
        Me.Button9.Name = "Button9"
        Me.Button9.Size = New System.Drawing.Size(88, 24)
        Me.Button9.TabIndex = 2
        Me.Button9.Text = "Delete"
        '
        'cbbMajorTTS
        '
        Me.cbbMajorTTS.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cbbMajorTTS.Location = New System.Drawing.Point(136, 408)
        Me.cbbMajorTTS.Name = "cbbMajorTTS"
        Me.cbbMajorTTS.Size = New System.Drawing.Size(160, 24)
        Me.cbbMajorTTS.TabIndex = 7
        '
        'cbbMinorTTS
        '
        Me.cbbMinorTTS.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cbbMinorTTS.Location = New System.Drawing.Point(536, 408)
        Me.cbbMinorTTS.Name = "cbbMinorTTS"
        Me.cbbMinorTTS.Size = New System.Drawing.Size(152, 24)
        Me.cbbMinorTTS.TabIndex = 17
        '
        'Panel1
        '
        Me.Panel1.Controls.Add(Me.txtMinorDescriptionName)
        Me.Panel1.Controls.Add(Me.txtMajorDescriptionName)
        Me.Panel1.Controls.Add(Me.txtMinorSecondaryName)
        Me.Panel1.Controls.Add(Me.txtMajorSecondaryName)
        Me.Panel1.Controls.Add(Me.Button9)
        Me.Panel1.Controls.Add(Me.Button7)
        Me.Panel1.Controls.Add(Me.cbbMajorTTS)
        Me.Panel1.Controls.Add(Me.cbbMinorTTS)
        Me.Panel1.Controls.Add(Me.ListBoxMinor)
        Me.Panel1.Controls.Add(Me.Label12)
        Me.Panel1.Controls.Add(Me.Label1)
        Me.Panel1.Controls.Add(Me.txtMinorCode)
        Me.Panel1.Controls.Add(Me.Button10)
        Me.Panel1.Controls.Add(Me.ListBoxMajor)
        Me.Panel1.Controls.Add(Me.txtMinorPrimaryName)
        Me.Panel1.Controls.Add(Me.Button11)
        Me.Panel1.Controls.Add(Me.Button12)
        Me.Panel1.Controls.Add(Me.Button13)
        Me.Panel1.Controls.Add(Me.txtMajorCode)
        Me.Panel1.Controls.Add(Me.Button3)
        Me.Panel1.Controls.Add(Me.txtMajorPrimaryName)
        Me.Panel1.Controls.Add(Me.Button8)
        Me.Panel1.Controls.Add(Me.Label5)
        Me.Panel1.Controls.Add(Me.Label2)
        Me.Panel1.Controls.Add(Me.Label17)
        Me.Panel1.Controls.Add(Me.Label15)
        Me.Panel1.Controls.Add(Me.Label3)
        Me.Panel1.Controls.Add(Me.Label7)
        Me.Panel1.Controls.Add(Me.Label8)
        Me.Panel1.Controls.Add(Me.Label9)
        Me.Panel1.Controls.Add(Me.Label10)
        Me.Panel1.Controls.Add(Me.Label14)
        Me.Panel1.Controls.Add(Me.Label11)
        Me.Panel1.Controls.Add(Me.Label6)
        Me.Panel1.Enabled = False
        Me.Panel1.Location = New System.Drawing.Point(0, 64)
        Me.Panel1.Name = "Panel1"
        Me.Panel1.Size = New System.Drawing.Size(792, 472)
        Me.Panel1.TabIndex = 1
        '
        'txtMinorDescriptionName
        '
        Me.txtMinorDescriptionName.Location = New System.Drawing.Point(536, 384)
        Me.txtMinorDescriptionName.MaxLength = 120
        Me.txtMinorDescriptionName.Name = "txtMinorDescriptionName"
        Me.txtMinorDescriptionName.Size = New System.Drawing.Size(248, 22)
        Me.txtMinorDescriptionName.TabIndex = 16
        Me.txtMinorDescriptionName.Text = ""
        '
        'txtMajorDescriptionName
        '
        Me.txtMajorDescriptionName.Location = New System.Drawing.Point(136, 384)
        Me.txtMajorDescriptionName.MaxLength = 120
        Me.txtMajorDescriptionName.Name = "txtMajorDescriptionName"
        Me.txtMajorDescriptionName.Size = New System.Drawing.Size(256, 22)
        Me.txtMajorDescriptionName.TabIndex = 6
        Me.txtMajorDescriptionName.Text = ""
        '
        'txtMinorSecondaryName
        '
        Me.txtMinorSecondaryName.Location = New System.Drawing.Point(536, 360)
        Me.txtMinorSecondaryName.MaxLength = 120
        Me.txtMinorSecondaryName.Name = "txtMinorSecondaryName"
        Me.txtMinorSecondaryName.Size = New System.Drawing.Size(248, 22)
        Me.txtMinorSecondaryName.TabIndex = 15
        Me.txtMinorSecondaryName.Text = ""
        '
        'txtMajorSecondaryName
        '
        Me.txtMajorSecondaryName.Location = New System.Drawing.Point(136, 360)
        Me.txtMajorSecondaryName.MaxLength = 120
        Me.txtMajorSecondaryName.Name = "txtMajorSecondaryName"
        Me.txtMajorSecondaryName.Size = New System.Drawing.Size(256, 22)
        Me.txtMajorSecondaryName.TabIndex = 5
        Me.txtMajorSecondaryName.Text = ""
        '
        'Label5
        '
        Me.Label5.Location = New System.Drawing.Point(608, 312)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(152, 24)
        Me.Label5.TabIndex = 33
        Me.Label5.Text = "<- 3 Digits [001-999]"
        Me.Label5.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'Label2
        '
        Me.Label2.Location = New System.Drawing.Point(216, 312)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(136, 24)
        Me.Label2.TabIndex = 26
        Me.Label2.Text = "<- 2 Digits  [01-99]"
        Me.Label2.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'Label17
        '
        Me.Label17.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Label17.Location = New System.Drawing.Point(8, 384)
        Me.Label17.Name = "Label17"
        Me.Label17.Size = New System.Drawing.Size(160, 24)
        Me.Label17.TabIndex = 24
        Me.Label17.Text = "คำอธิบาย (optional)"
        Me.Label17.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'Label15
        '
        Me.Label15.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Label15.Location = New System.Drawing.Point(8, 360)
        Me.Label15.Name = "Label15"
        Me.Label15.Size = New System.Drawing.Size(160, 24)
        Me.Label15.TabIndex = 23
        Me.Label15.Text = "ชื่อ Major ภาษาอังกฤษ"
        Me.Label15.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'Label8
        '
        Me.Label8.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Label8.Location = New System.Drawing.Point(408, 384)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(160, 24)
        Me.Label8.TabIndex = 31
        Me.Label8.Text = "คำอธิบาย (optional)"
        Me.Label8.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'Label9
        '
        Me.Label9.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Label9.Location = New System.Drawing.Point(408, 360)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(160, 24)
        Me.Label9.TabIndex = 30
        Me.Label9.Text = "ชื่อ Minor ภาษาอังกฤษ"
        Me.Label9.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'Label10
        '
        Me.Label10.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.Label10.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Label10.Location = New System.Drawing.Point(408, 312)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(160, 24)
        Me.Label10.TabIndex = 28
        Me.Label10.Text = "รหัส Minor"
        Me.Label10.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'Label14
        '
        Me.Label14.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Label14.Location = New System.Drawing.Point(408, 336)
        Me.Label14.Name = "Label14"
        Me.Label14.Size = New System.Drawing.Size(160, 24)
        Me.Label14.TabIndex = 29
        Me.Label14.Text = "ชื่อ Minor ภาษาไทย"
        Me.Label14.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'Label11
        '
        Me.Label11.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Label11.Location = New System.Drawing.Point(408, 408)
        Me.Label11.Name = "Label11"
        Me.Label11.Size = New System.Drawing.Size(160, 24)
        Me.Label11.TabIndex = 32
        Me.Label11.Text = "เสียง Text to Speech"
        Me.Label11.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'Label6
        '
        Me.Label6.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft
        Me.Label6.Location = New System.Drawing.Point(8, 408)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(160, 24)
        Me.Label6.TabIndex = 25
        Me.Label6.Text = "เสียง Text to Speech"
        Me.Label6.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'FrmChangeCatalog
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(6, 15)
        Me.ClientSize = New System.Drawing.Size(794, 538)
        Me.Controls.Add(Me.Panel1)
        Me.Controls.Add(Me.GroupBox1)
        Me.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow
        Me.Name = "FrmChangeCatalog"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "FrmChangeCatalog"
        Me.GroupBox1.ResumeLayout(False)
        Me.Panel1.ResumeLayout(False)
        Me.ResumeLayout(False)

    End Sub

#End Region

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

        Try
            'Try to open and close DB connection with read write mode
            myConn = New OleDbConnection("Provider=Microsoft.Jet.OLEDB.4.0; Data Source=" & Trim(TextBox1.Text) & "\Books.mdb")
            myConn.Open()
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
                Me.Button7_Click(sender, e)
            End If

        Catch ex As Exception
            'Change status of checking
            Label4.Text = "Fail."
            MsgBox("Fail.")
        End Try
    End Sub


    Private Sub Button7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button7.Click
        ListBoxMajor.Items.Clear()
        txtMajorCode.Text = ""
        txtMajorPrimaryName.Text = ""
        txtMajorSecondaryName.Text = ""
        txtMajorDescriptionName.Text = ""

        myConn.Open()
        Dim myCmd As OleDbCommand = New OleDbCommand("select * from TbBookCategory where CategoryCode like '__000'", myConn)
        myReader = myCmd.ExecuteReader()
        Dim tmpList As String


        While myReader.Read()
            If (IsDBNull(myReader.Item("CategoryMajorCode")) = False) And _
               (IsDBNull(myReader.Item("CategoryPrimaryName")) = False) And _
               (IsDBNull(myReader.Item("CategorySecondaryName")) = False) Then

                tmpList = myReader.Item("CategoryMajorCode")
                tmpList = tmpList & " : "
                tmpList = tmpList & myReader.Item("CategoryPrimaryName")
                tmpList = tmpList & " / "
                tmpList = tmpList & myReader.Item("CategorySecondaryName")

                ListBoxMajor.Items.Add(tmpList)
            End If
        End While

        myReader.Close()
        myConn.Close()

        If ListBoxMajor.Items.Count > 0 Then
            ListBoxMajor.SelectedIndex = 0
        End If
    End Sub

    Private Sub FrmChangeCatalog_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'Me.Button5_Click(sender, e)

        'Get each token in the collection returned by GetVoices
        Dim strVoice As String
        For Each T In V.GetVoices
            strVoice = T.GetDescription             'The token's name
            cbbMajorTTS.Items.Add(strVoice)           'Add to listbox
            cbbMinorTTS.Items.Add(strVoice)           'Add to listbox
        Next
    End Sub

    Private Sub Button11_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button11.Click
        ListBoxMinor.Items.Clear()
        txtMinorCode.Text = ""
        txtMinorPrimaryName.Text = ""
        txtMinorSecondaryName.Text = ""
        txtMinorDescriptionName.Text = ""

        myConn.Open()
        Dim tmpList As String = Microsoft.VisualBasic.Left(Trim(ListBoxMajor.SelectedItem), 2)
        Dim myCmd As OleDbCommand = New OleDbCommand("select * from TbBookCategory where CategoryCode like '" & Trim(tmpList) & "___'", myConn)
        myReader = myCmd.ExecuteReader()

        While myReader.Read()
            If (IsDBNull(myReader.Item("CategoryMinorCode")) = False) And _
               (IsDBNull(myReader.Item("CategoryPrimaryName")) = False) And _
               (IsDBNull(myReader.Item("CategorySecondaryName")) = False) And _
               (myReader.Item("CategoryMinorCode") <> "000") Then

                tmpList = myReader.Item("CategoryMinorCode")
                tmpList = tmpList & " : "
                tmpList = tmpList & myReader.Item("CategoryPrimaryName")
                tmpList = tmpList & " / "
                tmpList = tmpList & myReader.Item("CategorySecondaryName")

                ListBoxMinor.Items.Add(tmpList)

            End If
        End While
        myReader.Close()
        myConn.Close()

        If ListBoxMinor.Items.Count > 0 Then
            ListBoxMinor.SelectedIndex = 0
        End If
    End Sub


    'Private Sub CheckBox1_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs)
    '    If CheckBox1.Checked = True Then
    '        txtMajorAudioName.Text = "Auto-Generate from Text to Speech"
    '        txtMajorAudioName.ReadOnly = True
    '        Me.Button2.Enabled = False
    '        cbbMajorTTS.Enabled = True
    '    Else
    '        txtMajorAudioName.Text = ""
    '        txtMajorAudioName.ReadOnly = False
    '        Me.Button2.Enabled = True
    '        cbbMajorTTS.Enabled = False
    '        cbbMajorTTS.SelectedIndex = -1
    '    End If
    'End Sub

    Private Sub ListBoxMajor_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ListBoxMajor.SelectedIndexChanged
        'clear old value
        txtMajorCode.Text = ""
        txtMajorPrimaryName.Text = ""
        txtMajorSecondaryName.Text = ""
        txtMajorDescriptionName.Text = ""

        myConn.Open()
        Dim tmpList As String = Microsoft.VisualBasic.Left(ListBoxMajor.SelectedItem, 2)
        Dim myCmd As OleDbCommand = New OleDbCommand("select * from TbBookCategory where CategoryCode like '" & tmpList & "000'", myConn)
        myReader = myCmd.ExecuteReader()

        While myReader.Read()
            If (IsDBNull(myReader.Item("CategoryMajorCode")) = False) And _
               (IsDBNull(myReader.Item("CategoryPrimaryName")) = False) And _
               (IsDBNull(myReader.Item("CategorySecondaryName")) = False) And _
               (IsDBNull(myReader.Item("CategoryDescriptionName")) = False) Then

                'enter new value
                txtMajorCode.Text = myReader.Item("CategoryMajorCode")
                txtMajorPrimaryName.Text = myReader.Item("CategoryPrimaryName")
                txtMajorSecondaryName.Text = myReader.Item("CategorySecondaryName")
                txtMajorDescriptionName.Text = myReader.Item("CategoryDescriptionName")

            End If
        End While

        myReader.Close()
        myConn.Close()

        'update minor category
        Me.Button11_Click(sender, e)
    End Sub

    Private Sub ListBoxMinor_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ListBoxMinor.SelectedIndexChanged
        'clear old value
        txtMinorCode.Text = ""
        txtMinorPrimaryName.Text = ""
        txtMinorSecondaryName.Text = ""
        txtMinorDescriptionName.Text = ""

        myConn.Open()
        Dim tmpList As String = Trim(Microsoft.VisualBasic.Left(ListBoxMajor.SelectedItem, 2)) & Trim(Microsoft.VisualBasic.Left(ListBoxMinor.SelectedItem, 3))
        Dim myCmd As OleDbCommand = New OleDbCommand("select * from TbBookCategory where CategoryCode like '" & tmpList & "'", myConn)
        myReader = myCmd.ExecuteReader()

        While myReader.Read()
            If (IsDBNull(myReader.Item("CategoryMinorCode")) = False) And _
               (IsDBNull(myReader.Item("CategoryPrimaryName")) = False) And _
               (IsDBNull(myReader.Item("CategorySecondaryName")) = False) And _
               (IsDBNull(myReader.Item("CategoryDescriptionName")) = False) Then

                'enter new value
                txtMinorCode.Text = myReader.Item("CategoryMinorCode")
                txtMinorPrimaryName.Text = myReader.Item("CategoryPrimaryName")
                txtMinorSecondaryName.Text = myReader.Item("CategorySecondaryName")
                txtMinorDescriptionName.Text = myReader.Item("CategoryDescriptionName")

            End If
        End While

        myReader.Close()
        myConn.Close()
    End Sub

    'Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
    '    If OpenWaveFileDialog.ShowDialog() = DialogResult.OK Then
    '        txtMajorAudioName.Text = OpenWaveFileDialog.FileName
    '    End If
    'End Sub

    'Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
    '    If OpenWaveFileDialog.ShowDialog() = DialogResult.OK Then
    '        txtMinorAudioName.Text = OpenWaveFileDialog.FileName
    '    End If
    'End Sub

    'Private Sub CheckBox2_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs)
    '    If CheckBox2.Checked = True Then
    '        txtMinorAudioName.Text = "Auto-Generate from Text to Speech"
    '        txtMinorAudioName.ReadOnly = True
    '        Me.Button1.Enabled = False
    '        cbbMinorTTS.Enabled = True
    '    Else
    '        txtMinorAudioName.Text = ""
    '        txtMinorAudioName.ReadOnly = False
    '        Me.Button1.Enabled = True
    '        cbbMinorTTS.Enabled = False
    '        cbbMinorTTS.SelectedIndex = -1
    '    End If
    'End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        'If ((Trim(txtMajorAudioName.Text) = Microsoft.VisualBasic.Left(Trim(txtMajorCode.Text), 2) & "000.wav")) Then
        '    'Use PlaySoundFile function with preparation path
        '    PlaySoundFile(TextBox1.Text & "\catPrompts\" & Trim(txtMajorAudioName.Text))

        'ElseIf (Microsoft.VisualBasic.Right(Trim(txtMajorAudioName.Text), 4) = ".wav") Then
        '    'Use PlaySoundFile function without preparation path
        '    PlaySoundFile(Trim(txtMajorAudioName.Text))

        'ElseIf Trim(txtMajorAudioName.Text) = "Auto-Generate from Text to Speech" Then
            'use text to speech function

        ' Set output stream to speaker
        V.AllowAudioOutputFormatChangesOnNextSet = True
        V.AudioOutputStream = Nothing

        'The new voice speaks its own name
        V.Speak(txtMajorPrimaryName.Text)
        V.WaitUntilDone(-1)
        V.Speak(txtMajorSecondaryName.Text)
        V.WaitUntilDone(-1)
        V.Speak(txtMajorDescriptionName.Text)
        V.WaitUntilDone(-1)
        'End If
    End Sub

    Private Sub Button10_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button10.Click
        'If ((Trim(txtMinorAudioName.Text) = Microsoft.VisualBasic.Left(ListBoxMajor.SelectedItem, 2) & Microsoft.VisualBasic.Left(Trim(txtMinorCode.Text), 3) & ".wav")) Then
        '    'Use PlaySoundFile function with preparation path
        '    PlaySoundFile(TextBox1.Text & "\catPrompts\" & Trim(txtMinorAudioName.Text))

        'ElseIf (Microsoft.VisualBasic.Right(Trim(txtMinorAudioName.Text), 4) = ".wav") Then
        '    'Use PlaySoundFile function without preparation path
        '    PlaySoundFile(Trim(txtMinorAudioName.Text))

        'ElseIf Trim(txtMinorAudioName.Text) = "Auto-Generate from Text to Speech" Then

        'use text to speech function
        'Set output stream to speaker
        V.AllowAudioOutputFormatChangesOnNextSet = True
        V.AudioOutputStream = Nothing

        'The new voice speaks its own name
        V.Speak(txtMinorPrimaryName.Text)
        V.WaitUntilDone(-1)
        V.Speak(txtMinorSecondaryName.Text)
        V.WaitUntilDone(-1)
        V.Speak(txtMinorDescriptionName.Text)
        V.WaitUntilDone(-1)
        'End If
    End Sub

    Private Sub cbbMajorTTS_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles cbbMajorTTS.SelectedIndexChanged
        If cbbMajorTTS.SelectedIndex > -1 Then
            ChangeTTS(cbbMajorTTS.SelectedIndex)
        End If
    End Sub

    Private Sub Button9_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button9.Click
        If ListBoxMinor.Items.Count > 0 Then
            MsgBox("คุณต้องลบ Minor ออกให้หมดก่อน, ถึงจะสามารถลบ Major ได้", MsgBoxStyle.OKOnly, "ยังเหลือ Minor อยู่")
        Else
            If MsgBox("คุณต้องการลบ " & ListBoxMajor.SelectedItem & " ใช่ไหม?", MsgBoxStyle.YesNo, "กรุณายืนยัน") = MsgBoxResult.Yes Then
                myConn.Open()
                Dim tmpList As String = Microsoft.VisualBasic.Left(ListBoxMajor.SelectedItem, 2)
                Dim myCmd As OleDbCommand = New OleDbCommand("delete from TbBookCategory where CategoryCode like '" & tmpList & "000'", myConn)
                myCmd.ExecuteNonQuery()
                myConn.Close()

                Try
                    'ลบไฟล์เสียงของ MajorPrimaryName
                    Dim MajorPrimaryNameFilePath As String = TextBox1.Text & "\catPrompts\" & Microsoft.VisualBasic.Left(Trim(txtMajorCode.Text), 2) & "000p.wav"
                    File.Delete(MajorPrimaryNameFilePath)
                Catch ex As Exception
                End Try

                Try
                    'ลบไฟล์เสียงของ MajorSecondaryName
                    Dim MajorSecondaryNameFilePath As String = TextBox1.Text & "\catPrompts\" & Microsoft.VisualBasic.Left(Trim(txtMajorCode.Text), 2) & "000s.wav"
                    File.Delete(MajorSecondaryNameFilePath)
                Catch ex As Exception
                End Try

                Try
                    'ลบไฟล์เสียงของ MajorDescriptionName
                    Dim MajorDescriptionNameFilePath As String = TextBox1.Text & "\catPrompts\" & Microsoft.VisualBasic.Left(Trim(txtMajorCode.Text), 2) & "000d.wav"
                    File.Delete(MajorDescriptionNameFilePath)
                Catch ex As Exception
                End Try

                MsgBox("การลบเสร็จสมบูรณ์", MsgBoxStyle.OKOnly, "สมบูรณ์")
                Me.Button7_Click(sender, e)
            End If
        End If
    End Sub

    Private Sub Button13_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button13.Click
        Dim tmpList As String = Trim(Microsoft.VisualBasic.Left(ListBoxMajor.SelectedItem, 2)) & Trim(Microsoft.VisualBasic.Left(ListBoxMinor.SelectedItem, 3))
        Dim haveBook As Boolean

        'ตรวจสอบว่ามีหนังสือใน Minor อยู่หรือเปล่า
        myConn.Open()
        Dim myCmd1 As OleDbCommand = New OleDbCommand("SELECT * FROM TbBookInfo WHERE CategoryCode like '" & tmpList & "'", myConn)
        myReader = myCmd1.ExecuteReader()
        While myReader.Read()
            If (IsDBNull(myReader.Item("BookID")) = False) Then
                haveBook = True
            End If
        End While
        myReader.Close()
        myConn.Close()

        If haveBook = True Then
            MsgBox("คุณต้องลบหนังสือออกให้หมดก่อน, ถึงจะสามารถลบ Minor ได้", MsgBoxStyle.OKOnly, "ยังเหลือหนังสืออยู่")
        Else
            If ListBoxMinor.Items.Count > 0 Then
                If MsgBox("คุณต้องการลบ " & ListBoxMinor.SelectedItem & " ใช่ไหม?", MsgBoxStyle.YesNo, "กรุณายืนยัน") = MsgBoxResult.Yes Then
                    myConn.Open()
                    Dim myCmd2 As OleDbCommand = New OleDbCommand("delete from TbBookCategory where CategoryCode like '" & tmpList & "'", myConn)
                    myCmd2.ExecuteNonQuery()
                    myConn.Close()

                    Try
                        'ลบไฟล์เสียงของ MinorPrimaryName
                        Dim MinorPrimaryNameFilePath As String = TextBox1.Text & "\catPrompts\" & Microsoft.VisualBasic.Left(ListBoxMajor.SelectedItem, 2) & Microsoft.VisualBasic.Left(Trim(txtMinorCode.Text), 3) & "p.wav"      'Primary name
                        File.Delete(MinorPrimaryNameFilePath)
                    Catch ex As Exception
                    End Try

                    Try
                        'ลบไฟล์เสียงของ MinorSecondaryName
                        Dim MinorSecondaryNameFilePath As String = TextBox1.Text & "\catPrompts\" & Microsoft.VisualBasic.Left(ListBoxMajor.SelectedItem, 2) & Microsoft.VisualBasic.Left(Trim(txtMinorCode.Text), 3) & "s.wav"    'Secondary name
                        File.Delete(MinorSecondaryNameFilePath)
                    Catch ex As Exception
                    End Try

                    Try
                        'ลบไฟล์เสียงของ MinorDescriptionName
                        Dim MinorDescriptionNameFilePath As String = TextBox1.Text & "\catPrompts\" & Microsoft.VisualBasic.Left(ListBoxMajor.SelectedItem, 2) & Microsoft.VisualBasic.Left(Trim(txtMinorCode.Text), 3) & "d.wav"  'Description name
                        File.Delete(MinorDescriptionNameFilePath)
                    Catch ex As Exception
                    End Try

                    MsgBox("การลบเสร็จสมบูรณ์", MsgBoxStyle.OKOnly, "สมบูรณ์")
                    Me.Button11_Click(sender, e)
                End If
            End If
        End If
    End Sub

    Private Sub cbbMinorTTS_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles cbbMinorTTS.SelectedIndexChanged
        If cbbMinorTTS.SelectedIndex > -1 Then
            ChangeTTS(cbbMinorTTS.SelectedIndex)
        End If
    End Sub

    Private Sub txtMajorCode_LostFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles txtMajorCode.LostFocus
        txtMajorCode.Text = Format(Val(txtMajorCode.Text), "00")
        If txtMajorCode.Text = "00" Then
            txtMajorCode.Text = ""
        End If
    End Sub

    Private Sub txtMinorCode_LostFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles txtMinorCode.LostFocus
        txtMinorCode.Text = Format(Val(txtMinorCode.Text), "000")
        If txtMinorCode.Text = "000" Then
            txtMinorCode.Text = ""
        End If
    End Sub

    Private Sub Button8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button8.Click
        If Trim(txtMajorCode.Text) = "" Then
            MsgBox("ไม่มีการระบุ Major Code ไว้")
            Exit Sub
        End If

        If Trim(cbbMajorTTS.SelectedIndex < 0) Then
            MsgBox("ไม่มีการระบุ Text to Speech ไว้")
            Exit Sub
        End If

        If MsgBox("คุณต้องการบันทึกการเปลี่ยนแปลงข้อมูล Majorcode=" & txtMajorCode.Text & " ใช่ไหม?", MsgBoxStyle.YesNo, "กรุณายืนยัน") = MsgBoxResult.Yes Then
            'Copy or Genarate Wave file to catPrompts directory
            Dim MajorPrimaryNameFilePath As String = TextBox1.Text & "\catPrompts\" & Microsoft.VisualBasic.Left(Trim(txtMajorCode.Text), 2) & "000p.wav"
            Dim MajorSecondaryNameFilePath As String = TextBox1.Text & "\catPrompts\" & Microsoft.VisualBasic.Left(Trim(txtMajorCode.Text), 2) & "000s.wav"
            Dim MajorDescriptionNameFilePath As String = TextBox1.Text & "\catPrompts\" & Microsoft.VisualBasic.Left(Trim(txtMajorCode.Text), 2) & "000d.wav"

            Try
                ' Ensure that the target does not exist.
                File.Delete(MajorPrimaryNameFilePath)
            Catch ex As Exception
            End Try

            Try
                ' Ensure that the target does not exist.
                File.Delete(MajorSecondaryNameFilePath)
            Catch ex As Exception
            End Try

            Try
                ' Ensure that the target does not exist.
                File.Delete(MajorDescriptionNameFilePath)
            Catch ex As Exception
            End Try

            'If CheckBox1.Checked = True Then
            Try
                'AUTO-GENERATE
                ' create a wave stream
                Dim cpFileStream As New SpFileStream
                cpFileStream.Format.Type = SpeechAudioFormatType.SAFT11kHz8BitMono

                ' Generate Major Primary Name
                ' Open File steam for writing
                cpFileStream.Open(MajorPrimaryNameFilePath, SpeechStreamFileMode.SSFMCreateForWrite, False)
                ' Set output stream to the file stream
                V.AllowAudioOutputFormatChangesOnNextSet = False
                V.AudioOutputStream = cpFileStream
                ' Speak the given text with given flags
                V.Speak(txtMajorPrimaryName.Text, SpeechVoiceSpeakFlags.SVSFDefault)
                ' wait until it's done speaking with a really really long timeout.
                ' the tiemout value is in unit of millisecond. -1 means forever.
                V.WaitUntilDone(-1)
                ' close the file stream
                cpFileStream.Close()

                ' Generate Major Secondary Name
                ' Open File steam for writing
                cpFileStream.Open(MajorSecondaryNameFilePath, SpeechStreamFileMode.SSFMCreateForWrite, False)
                ' Set output stream to the file stream
                V.AllowAudioOutputFormatChangesOnNextSet = False
                V.AudioOutputStream = cpFileStream
                ' Speak the given text with given flags
                V.Speak(txtMajorSecondaryName.Text, SpeechVoiceSpeakFlags.SVSFDefault)
                ' wait until it's done speaking with a really really long timeout.
                ' the tiemout value is in unit of millisecond. -1 means forever.
                V.WaitUntilDone(-1)
                ' close the file stream
                cpFileStream.Close()

                ' Generate Major Description Name
                ' Open File steam for writing
                cpFileStream.Open(MajorDescriptionNameFilePath, SpeechStreamFileMode.SSFMCreateForWrite, False)
                ' Set output stream to the file stream
                V.AllowAudioOutputFormatChangesOnNextSet = False
                V.AudioOutputStream = cpFileStream
                ' Speak the given text with given flags
                V.Speak(txtMajorDescriptionName.Text, SpeechVoiceSpeakFlags.SVSFDefault)
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
            'ElseIf ((Trim(txtMajorAudioName.Text) = Microsoft.VisualBasic.Left(Trim(txtMajorCode.Text), 2) & "000.wav")) Then
            'ตรวจสอบ 3 อย่างเพื่อให้แน่ใจว่าเป็นไฟล์ที่ save ลงไปในระบบแล้ว
            'no need to change audio file.
            'Else
            'If CopyMyFile(txtMajorAudioName.Text, filePath) = False Then
            'MsgBox("ไม่สามารถคัดลอกไฟล์เสียงที่ระบุในช่อง Audio Name ได้, กรุณาตรวจสอบใหม่อีกครั้งโดยใช้ชื่อไฟล์ + Path เต็มๆ", MsgBoxStyle.OKOnly, "Incomplete")
            'Exit Sub
            'End If
            'End If

            'update database (delete old & add new)
            Try
                myConn.Open()

                Dim tmpList As String = Microsoft.VisualBasic.Left(Trim(txtMajorCode.Text), 2)
                Dim myCmd As OleDbCommand = New OleDbCommand("delete from TbBookCategory where CategoryCode like '" & tmpList & "000'", myConn)
                myCmd.ExecuteNonQuery()

                tmpList = "insert into TbBookCategory(CategoryCode,CategoryMajorCode,CategoryMinorCode,CategoryPrimaryName,CategorySecondaryName,CategoryDescriptionName) values('" & tmpList & "000','" & tmpList & "','000','" & Trim(txtMajorPrimaryName.Text) & "','" & Trim(txtMajorSecondaryName.Text) & "','" & Trim(txtMajorDescriptionName.Text) & "')"
                myCmd = New OleDbCommand(tmpList, myConn)
                myCmd.ExecuteNonQuery()

                myConn.Close()
                MsgBox("บันทึกข้อมูลเรียบร้อยแล้ว", MsgBoxStyle.OKOnly, "Completed")
            Catch err As Exception
                myConn.Close()
                MsgBox("ไม่สามารถบันทึกข้อมูลได้ กรุณาตรวจสอบข้อมูลใหม่อีกครั้ง", MsgBoxStyle.OKOnly, "Incomplete")
            End Try

            'refresh major
            Me.Button7_Click(sender, e)
        End If
    End Sub

    Private Sub Button12_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button12.Click
        If Trim(txtMinorCode.Text) = "" Then
            MsgBox("ไม่มีการระบุ Minor Code ไว้")
            Exit Sub
        End If

        If Trim(cbbMinorTTS.SelectedIndex < 0) Then
            MsgBox("ไม่มีการระบุ Text to Speech ไว้")
            Exit Sub
        End If

        If MsgBox("คุณต้องการบันทึกการเปลี่ยนแปลงข้อมูล Minorcode=" & txtMinorCode.Text & " ใช่ไหม?", MsgBoxStyle.YesNo, "กรุณายืนยัน") = MsgBoxResult.Yes Then
            'Copy or Genarate Wave file to catPrompts directory
            Dim MinorPrimaryNameFilePath As String = TextBox1.Text & "\catPrompts\" & Microsoft.VisualBasic.Left(ListBoxMajor.SelectedItem, 2) & Microsoft.VisualBasic.Left(Trim(txtMinorCode.Text), 3) & "p.wav"      'Primary name
            Dim MinorSecondaryNameFilePath As String = TextBox1.Text & "\catPrompts\" & Microsoft.VisualBasic.Left(ListBoxMajor.SelectedItem, 2) & Microsoft.VisualBasic.Left(Trim(txtMinorCode.Text), 3) & "s.wav"    'Secondary name
            Dim MinorDescriptionNameFilePath As String = TextBox1.Text & "\catPrompts\" & Microsoft.VisualBasic.Left(ListBoxMajor.SelectedItem, 2) & Microsoft.VisualBasic.Left(Trim(txtMinorCode.Text), 3) & "d.wav"  'Description name

            Try
                ' Ensure that the target does not exist.
                File.Delete(MinorPrimaryNameFilePath)
            Catch ex As Exception
            End Try

            Try
                ' Ensure that the target does not exist.
                File.Delete(MinorSecondaryNameFilePath)
            Catch ex As Exception
            End Try

            Try
                ' Ensure that the target does not exist.
                File.Delete(MinorDescriptionNameFilePath)
            Catch ex As Exception
            End Try

            'If CheckBox2.Checked = True Then
            Try
                'AUTO-GENERATE
                ' create a wave stream
                Dim cpFileStream As New SpFileStream
                cpFileStream.Format.Type = SpeechAudioFormatType.SAFT11kHz8BitMono

                ' Generate Major Primary Name
                ' Ensure that the target does not exist.
                File.Delete(MinorPrimaryNameFilePath)
                cpFileStream.Open(MinorPrimaryNameFilePath, SpeechStreamFileMode.SSFMCreateForWrite, False)
                ' Set output stream to the file stream
                V.AllowAudioOutputFormatChangesOnNextSet = False
                V.AudioOutputStream = cpFileStream
                ' speak the given text with given flags
                V.Speak(txtMinorPrimaryName.Text, SpeechVoiceSpeakFlags.SVSFDefault)
                ' wait until it's done speaking with a really really long timeout.
                ' the tiemout value is in unit of millisecond. -1 means forever.
                V.WaitUntilDone(-1)
                ' close the file stream
                cpFileStream.Close()

                ' Generate Major Secondary Name
                ' Ensure that the target does not exist.
                File.Delete(MinorSecondaryNameFilePath)
                cpFileStream.Open(MinorSecondaryNameFilePath, SpeechStreamFileMode.SSFMCreateForWrite, False)
                ' Set output stream to the file stream
                V.AllowAudioOutputFormatChangesOnNextSet = False
                V.AudioOutputStream = cpFileStream
                ' speak the given text with given flags
                V.Speak(txtMinorSecondaryName.Text, SpeechVoiceSpeakFlags.SVSFDefault)
                ' wait until it's done speaking with a really really long timeout.
                ' the tiemout value is in unit of millisecond. -1 means forever.
                V.WaitUntilDone(-1)
                ' close the file stream
                cpFileStream.Close()

                ' Generate Description Name
                ' Ensure that the target does not exist.
                File.Delete(MinorDescriptionNameFilePath)
                cpFileStream.Open(MinorDescriptionNameFilePath, SpeechStreamFileMode.SSFMCreateForWrite, False)
                ' Set output stream to the file stream
                V.AllowAudioOutputFormatChangesOnNextSet = False
                V.AudioOutputStream = cpFileStream
                ' speak the given text with given flags
                V.Speak(txtMinorDescriptionName.Text, SpeechVoiceSpeakFlags.SVSFDefault)
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
            'ElseIf ((Trim(txtMinorAudioName.Text) = Microsoft.VisualBasic.Left(ListBoxMajor.SelectedItem, 2) & Microsoft.VisualBasic.Left(Trim(txtMinorCode.Text), 3) & ".wav")) Then
            '    'no need to change audio file.
            'Else
            '    If CopyMyFile(txtMinorAudioName.Text, filePath) = False Then
            '        MsgBox("ไม่สามารถคัดลอกไฟล์เสียงที่ระบุในช่อง Audio Name ได้, กรุณาตรวจสอบใหม่อีกครั้งโดยใช้ชื่อไฟล์ + Path เต็มๆ", MsgBoxStyle.OKOnly, "Incomplete")
            '        Exit Sub
            '    End If
            'End If

            'update database (delete old & add new)
            Try
                myConn.Open()

                Dim tmpList As String = Trim(Microsoft.VisualBasic.Left(ListBoxMajor.SelectedItem, 2)) & Trim(Microsoft.VisualBasic.Left(Trim(txtMinorCode.Text), 3))
                Dim myCmd As OleDbCommand = New OleDbCommand("delete from TbBookCategory where CategoryCode like '" & tmpList & "'", myConn)
                myCmd.ExecuteNonQuery()

                tmpList = "insert into TbBookCategory(CategoryCode,CategoryMajorCode,CategoryMinorCode,CategoryPrimaryName,CategorySecondaryName,CategoryDescriptionName) values('" & tmpList & "','" & Microsoft.VisualBasic.Left(ListBoxMajor.SelectedItem, 2) & "','" & Microsoft.VisualBasic.Left(Trim(txtMinorCode.Text), 3) & "','" & Trim(txtMinorPrimaryName.Text) & "','" & Trim(txtMinorSecondaryName.Text) & "','" & Trim(txtMinorDescriptionName.Text) & "')"
                myCmd = New OleDbCommand(tmpList, myConn)
                myCmd.ExecuteNonQuery()

                myConn.Close()
                MsgBox("บันทึกข้อมูลเรียบร้อยแล้ว", MsgBoxStyle.OKOnly, "Completed")
            Catch err As Exception
                MsgBox("ไม่สามารถบันทึกข้อมูลได้ กรุณาตรวจสอบข้อมูลใหม่อีกครั้ง", MsgBoxStyle.OKOnly, "Incomplete")
            End Try

            'refresh minor
            Me.Button11_Click(sender, e)
        End If
    End Sub

    'Custom functions
    Sub ChangeTTS(ByVal selectedIndex As Byte)
        If selectedIndex > -1 Then
            'Set voice object to voice name selected in list box
            V.Voice = V.GetVoices().Item(selectedIndex)

            On Error GoTo Error_Handle
            If (cbbMajorTTS.Text = "PPA ตาทิพย์") Then
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
            'V.Speak("Test")
            'V.WaitUntilDone(-1)
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


End Class
