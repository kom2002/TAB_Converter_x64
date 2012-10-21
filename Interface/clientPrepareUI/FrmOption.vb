Imports System
Imports System.IO
Imports SpeechLib

Public Class FrmOption
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
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents TextBox1 As System.Windows.Forms.TextBox
    Friend WithEvents ComboBox3 As System.Windows.Forms.ComboBox
    Friend WithEvents ComboBox1 As System.Windows.Forms.ComboBox
    Friend WithEvents ComboBox2 As System.Windows.Forms.ComboBox
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents GroupBox2 As System.Windows.Forms.GroupBox
    Friend WithEvents GroupBox3 As System.Windows.Forms.GroupBox
    Friend WithEvents GroupBox4 As System.Windows.Forms.GroupBox
    Friend WithEvents ComboBox4 As System.Windows.Forms.ComboBox
    Friend WithEvents GroupBox5 As System.Windows.Forms.GroupBox
    Friend WithEvents Button3 As System.Windows.Forms.Button
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents PictureBox1 As System.Windows.Forms.PictureBox
    Friend WithEvents PictureBox2 As System.Windows.Forms.PictureBox
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents LblVolume As System.Windows.Forms.Label
    Friend WithEvents LblSpeed As System.Windows.Forms.Label
    Friend WithEvents TbrVolume As System.Windows.Forms.TrackBar
    Friend WithEvents TbrSpeed As System.Windows.Forms.TrackBar
    Friend WithEvents PictureBox3 As System.Windows.Forms.PictureBox
    Friend WithEvents SaveFileWav As System.Windows.Forms.SaveFileDialog
    Friend WithEvents SaveFileVox As System.Windows.Forms.SaveFileDialog
    Friend WithEvents SaveFileMp3 As System.Windows.Forms.SaveFileDialog
    Friend WithEvents Button4 As System.Windows.Forms.Button
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Dim resources As System.Resources.ResourceManager = New System.Resources.ResourceManager(GetType(FrmOption))
        Me.Button2 = New System.Windows.Forms.Button
        Me.TextBox1 = New System.Windows.Forms.TextBox
        Me.ComboBox3 = New System.Windows.Forms.ComboBox
        Me.ComboBox1 = New System.Windows.Forms.ComboBox
        Me.ComboBox2 = New System.Windows.Forms.ComboBox
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.PictureBox2 = New System.Windows.Forms.PictureBox
        Me.GroupBox2 = New System.Windows.Forms.GroupBox
        Me.TbrVolume = New System.Windows.Forms.TrackBar
        Me.LblVolume = New System.Windows.Forms.Label
        Me.LblSpeed = New System.Windows.Forms.Label
        Me.Label4 = New System.Windows.Forms.Label
        Me.Label5 = New System.Windows.Forms.Label
        Me.Label6 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label1 = New System.Windows.Forms.Label
        Me.TbrSpeed = New System.Windows.Forms.TrackBar
        Me.Button1 = New System.Windows.Forms.Button
        Me.GroupBox3 = New System.Windows.Forms.GroupBox
        Me.PictureBox3 = New System.Windows.Forms.PictureBox
        Me.GroupBox4 = New System.Windows.Forms.GroupBox
        Me.PictureBox1 = New System.Windows.Forms.PictureBox
        Me.ComboBox4 = New System.Windows.Forms.ComboBox
        Me.GroupBox5 = New System.Windows.Forms.GroupBox
        Me.Button3 = New System.Windows.Forms.Button
        Me.SaveFileWav = New System.Windows.Forms.SaveFileDialog
        Me.SaveFileVox = New System.Windows.Forms.SaveFileDialog
        Me.SaveFileMp3 = New System.Windows.Forms.SaveFileDialog
        Me.Button4 = New System.Windows.Forms.Button
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        CType(Me.TbrVolume, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.TbrSpeed, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.GroupBox3.SuspendLayout()
        Me.GroupBox4.SuspendLayout()
        Me.GroupBox5.SuspendLayout()
        Me.SuspendLayout()
        '
        'Button2
        '
        Me.Button2.Location = New System.Drawing.Point(296, 16)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(112, 24)
        Me.Button2.TabIndex = 2
        Me.Button2.Text = "Test save to .WAV"
        '
        'TextBox1
        '
        Me.TextBox1.Location = New System.Drawing.Point(16, 16)
        Me.TextBox1.Multiline = True
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.Size = New System.Drawing.Size(272, 88)
        Me.TextBox1.TabIndex = 4
        Me.TextBox1.Text = ""
        '
        'ComboBox3
        '
        Me.ComboBox3.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBox3.Location = New System.Drawing.Point(16, 16)
        Me.ComboBox3.Name = "ComboBox3"
        Me.ComboBox3.Size = New System.Drawing.Size(272, 21)
        Me.ComboBox3.TabIndex = 8
        '
        'ComboBox1
        '
        Me.ComboBox1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBox1.Location = New System.Drawing.Point(16, 16)
        Me.ComboBox1.Name = "ComboBox1"
        Me.ComboBox1.Size = New System.Drawing.Size(272, 21)
        Me.ComboBox1.TabIndex = 9
        '
        'ComboBox2
        '
        Me.ComboBox2.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBox2.Location = New System.Drawing.Point(16, 16)
        Me.ComboBox2.Name = "ComboBox2"
        Me.ComboBox2.Size = New System.Drawing.Size(272, 21)
        Me.ComboBox2.TabIndex = 11
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.PictureBox2)
        Me.GroupBox1.Controls.Add(Me.ComboBox3)
        Me.GroupBox1.Location = New System.Drawing.Point(8, 240)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(416, 48)
        Me.GroupBox1.TabIndex = 12
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "VOX setting"
        '
        'PictureBox2
        '
        Me.PictureBox2.Image = CType(resources.GetObject("PictureBox2.Image"), System.Drawing.Image)
        Me.PictureBox2.Location = New System.Drawing.Point(296, 16)
        Me.PictureBox2.Name = "PictureBox2"
        Me.PictureBox2.Size = New System.Drawing.Size(112, 24)
        Me.PictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox2.TabIndex = 9
        Me.PictureBox2.TabStop = False
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.TbrVolume)
        Me.GroupBox2.Controls.Add(Me.LblVolume)
        Me.GroupBox2.Controls.Add(Me.LblSpeed)
        Me.GroupBox2.Controls.Add(Me.Label4)
        Me.GroupBox2.Controls.Add(Me.Label5)
        Me.GroupBox2.Controls.Add(Me.Label6)
        Me.GroupBox2.Controls.Add(Me.Label3)
        Me.GroupBox2.Controls.Add(Me.Label2)
        Me.GroupBox2.Controls.Add(Me.Label1)
        Me.GroupBox2.Controls.Add(Me.TbrSpeed)
        Me.GroupBox2.Controls.Add(Me.ComboBox1)
        Me.GroupBox2.Controls.Add(Me.Button1)
        Me.GroupBox2.Location = New System.Drawing.Point(8, 8)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(416, 168)
        Me.GroupBox2.TabIndex = 13
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "Voice setting"
        '
        'TbrVolume
        '
        Me.TbrVolume.LargeChange = 10
        Me.TbrVolume.Location = New System.Drawing.Point(8, 120)
        Me.TbrVolume.Maximum = 100
        Me.TbrVolume.Name = "TbrVolume"
        Me.TbrVolume.Size = New System.Drawing.Size(288, 42)
        Me.TbrVolume.SmallChange = 10
        Me.TbrVolume.TabIndex = 25
        Me.TbrVolume.TickFrequency = 5
        Me.TbrVolume.TickStyle = System.Windows.Forms.TickStyle.TopLeft
        Me.TbrVolume.Value = 100
        '
        'LblVolume
        '
        Me.LblVolume.Location = New System.Drawing.Point(296, 128)
        Me.LblVolume.Name = "LblVolume"
        Me.LblVolume.Size = New System.Drawing.Size(112, 16)
        Me.LblVolume.TabIndex = 30
        Me.LblVolume.Text = "Voice Volume = 100"
        '
        'LblSpeed
        '
        Me.LblSpeed.Location = New System.Drawing.Point(296, 64)
        Me.LblSpeed.Name = "LblSpeed"
        Me.LblSpeed.Size = New System.Drawing.Size(112, 16)
        Me.LblSpeed.TabIndex = 29
        Me.LblSpeed.Text = "Voice Speed = 0"
        '
        'Label4
        '
        Me.Label4.Location = New System.Drawing.Point(120, 104)
        Me.Label4.Name = "Label4"
        Me.Label4.RightToLeft = System.Windows.Forms.RightToLeft.Yes
        Me.Label4.Size = New System.Drawing.Size(56, 16)
        Me.Label4.TabIndex = 28
        Me.Label4.Text = "Medium"
        Me.Label4.TextAlign = System.Drawing.ContentAlignment.TopCenter
        '
        'Label5
        '
        Me.Label5.Location = New System.Drawing.Point(248, 104)
        Me.Label5.Name = "Label5"
        Me.Label5.RightToLeft = System.Windows.Forms.RightToLeft.Yes
        Me.Label5.Size = New System.Drawing.Size(40, 16)
        Me.Label5.TabIndex = 27
        Me.Label5.Text = "Max"
        '
        'Label6
        '
        Me.Label6.Location = New System.Drawing.Point(16, 104)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(48, 16)
        Me.Label6.TabIndex = 26
        Me.Label6.Text = "Min"
        '
        'Label3
        '
        Me.Label3.Location = New System.Drawing.Point(120, 40)
        Me.Label3.Name = "Label3"
        Me.Label3.RightToLeft = System.Windows.Forms.RightToLeft.Yes
        Me.Label3.Size = New System.Drawing.Size(56, 16)
        Me.Label3.TabIndex = 24
        Me.Label3.Text = "Normal"
        Me.Label3.TextAlign = System.Drawing.ContentAlignment.TopCenter
        '
        'Label2
        '
        Me.Label2.Location = New System.Drawing.Point(248, 40)
        Me.Label2.Name = "Label2"
        Me.Label2.RightToLeft = System.Windows.Forms.RightToLeft.Yes
        Me.Label2.Size = New System.Drawing.Size(40, 16)
        Me.Label2.TabIndex = 23
        Me.Label2.Text = "Fast"
        '
        'Label1
        '
        Me.Label1.Location = New System.Drawing.Point(16, 40)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(48, 16)
        Me.Label1.TabIndex = 22
        Me.Label1.Text = "Slow"
        '
        'TbrSpeed
        '
        Me.TbrSpeed.LargeChange = 1
        Me.TbrSpeed.Location = New System.Drawing.Point(8, 56)
        Me.TbrSpeed.Minimum = -10
        Me.TbrSpeed.Name = "TbrSpeed"
        Me.TbrSpeed.Size = New System.Drawing.Size(288, 42)
        Me.TbrSpeed.TabIndex = 21
        Me.TbrSpeed.TickStyle = System.Windows.Forms.TickStyle.TopLeft
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(296, 16)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(112, 24)
        Me.Button1.TabIndex = 10
        Me.Button1.Text = "Test engine"
        '
        'GroupBox3
        '
        Me.GroupBox3.Controls.Add(Me.PictureBox3)
        Me.GroupBox3.Controls.Add(Me.ComboBox2)
        Me.GroupBox3.Location = New System.Drawing.Point(8, 184)
        Me.GroupBox3.Name = "GroupBox3"
        Me.GroupBox3.Size = New System.Drawing.Size(416, 48)
        Me.GroupBox3.TabIndex = 14
        Me.GroupBox3.TabStop = False
        Me.GroupBox3.Text = "WAV setting"
        '
        'PictureBox3
        '
        Me.PictureBox3.Image = CType(resources.GetObject("PictureBox3.Image"), System.Drawing.Image)
        Me.PictureBox3.Location = New System.Drawing.Point(296, 16)
        Me.PictureBox3.Name = "PictureBox3"
        Me.PictureBox3.Size = New System.Drawing.Size(112, 24)
        Me.PictureBox3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox3.TabIndex = 12
        Me.PictureBox3.TabStop = False
        '
        'GroupBox4
        '
        Me.GroupBox4.Controls.Add(Me.PictureBox1)
        Me.GroupBox4.Controls.Add(Me.ComboBox4)
        Me.GroupBox4.Location = New System.Drawing.Point(8, 296)
        Me.GroupBox4.Name = "GroupBox4"
        Me.GroupBox4.Size = New System.Drawing.Size(416, 48)
        Me.GroupBox4.TabIndex = 15
        Me.GroupBox4.TabStop = False
        Me.GroupBox4.Text = "MP3 setting"
        '
        'PictureBox1
        '
        Me.PictureBox1.Image = CType(resources.GetObject("PictureBox1.Image"), System.Drawing.Image)
        Me.PictureBox1.Location = New System.Drawing.Point(296, 16)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(112, 24)
        Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox1.TabIndex = 9
        Me.PictureBox1.TabStop = False
        '
        'ComboBox4
        '
        Me.ComboBox4.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBox4.Enabled = False
        Me.ComboBox4.Location = New System.Drawing.Point(16, 16)
        Me.ComboBox4.Name = "ComboBox4"
        Me.ComboBox4.Size = New System.Drawing.Size(272, 21)
        Me.ComboBox4.TabIndex = 8
        '
        'GroupBox5
        '
        Me.GroupBox5.Controls.Add(Me.Button4)
        Me.GroupBox5.Controls.Add(Me.Button3)
        Me.GroupBox5.Controls.Add(Me.TextBox1)
        Me.GroupBox5.Controls.Add(Me.Button2)
        Me.GroupBox5.Location = New System.Drawing.Point(8, 352)
        Me.GroupBox5.Name = "GroupBox5"
        Me.GroupBox5.Size = New System.Drawing.Size(416, 112)
        Me.GroupBox5.TabIndex = 16
        Me.GroupBox5.TabStop = False
        Me.GroupBox5.Text = "Test save it to file"
        '
        'Button3
        '
        Me.Button3.Location = New System.Drawing.Point(296, 48)
        Me.Button3.Name = "Button3"
        Me.Button3.Size = New System.Drawing.Size(112, 24)
        Me.Button3.TabIndex = 5
        Me.Button3.Text = "Test save to .VOX"
        '
        'Button4
        '
        Me.Button4.Location = New System.Drawing.Point(296, 80)
        Me.Button4.Name = "Button4"
        Me.Button4.Size = New System.Drawing.Size(112, 24)
        Me.Button4.TabIndex = 6
        Me.Button4.Text = "Test save to .MP3"
        Me.Button4.Visible = False
        '
        'FrmOption
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 13)
        Me.ClientSize = New System.Drawing.Size(432, 469)
        Me.Controls.Add(Me.GroupBox5)
        Me.Controls.Add(Me.GroupBox4)
        Me.Controls.Add(Me.GroupBox3)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.GroupBox1)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D
        Me.Name = "FrmOption"
        Me.Text = "Test Engine"
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox2.ResumeLayout(False)
        CType(Me.TbrVolume, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.TbrSpeed, System.ComponentModel.ISupportInitialize).EndInit()
        Me.GroupBox3.ResumeLayout(False)
        Me.GroupBox4.ResumeLayout(False)
        Me.GroupBox5.ResumeLayout(False)
        Me.ResumeLayout(False)

    End Sub

#End Region
    Private V As New SpeechLib.SpVoice
    Private T As SpeechLib.ISpeechObjectToken


    Private Sub FrmOption_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Dim strVoice As String

        'Get each token in the collection returned by GetVoices
        For Each T In V.GetVoices
            strVoice = T.GetDescription             'The token's name
            ComboBox1.Items.Add(strVoice)           'Add to listbox
        Next

        'WAV Lists
        ComboBox2.Items.Add("Linear PCM 8kHz 8Bit Mono")
        ComboBox2.Items.Add("Linear PCM 8kHz 8Bit Stereo")
        ComboBox2.Items.Add("Linear PCM 8kHz 16Bit Mono")
        ComboBox2.Items.Add("Linear PCM 8kHz 16Bit Stereo")
        ComboBox2.Items.Add("Linear PCM 11kHz 8Bit Mono (*****)")
        ComboBox2.Items.Add("Linear PCM 11kHz 8Bit Stereo")
        ComboBox2.Items.Add("Linear PCM 11kHz 16Bit Mono")
        ComboBox2.Items.Add("Linear PCM 11kHz 16Bit Stereo")
        ComboBox2.Items.Add("Linear PCM 12kHz 8Bit Mono")
        ComboBox2.Items.Add("Linear PCM 12kHz 8Bit Stereo")
        ComboBox2.Items.Add("Linear PCM 12kHz 16Bit Mono")
        ComboBox2.Items.Add("Linear PCM 12kHz 16Bit Stereo")
        ComboBox2.Items.Add("Linear PCM 16kHz 8Bit Mono")
        ComboBox2.Items.Add("Linear PCM 16kHz 8Bit Stereo")
        ComboBox2.Items.Add("Linear PCM 16kHz 16Bit Mono")
        ComboBox2.Items.Add("Linear PCM 16kHz 16Bit Stereo")
        ComboBox2.Items.Add("Linear PCM 22kHz 8Bit Mono")
        ComboBox2.Items.Add("Linear PCM 22kHz 8Bit Stereo")
        ComboBox2.Items.Add("Linear PCM 22kHz 16Bit Mono")
        ComboBox2.Items.Add("Linear PCM 22kHz 16Bit Stereo")
        ComboBox2.Items.Add("Linear PCM 24kHz 8Bit Mono")
        ComboBox2.Items.Add("Linear PCM 24kHz 8Bit Stereo")
        ComboBox2.Items.Add("Linear PCM 24kHz 16Bit Mono")
        ComboBox2.Items.Add("Linear PCM 24kHz 16Bit Stereo")
        ComboBox2.Items.Add("Linear PCM 32kHz 8Bit Mono")
        ComboBox2.Items.Add("Linear PCM 32kHz 8Bit Stereo")
        ComboBox2.Items.Add("Linear PCM 32kHz 16Bit Mono")
        ComboBox2.Items.Add("Linear PCM 32kHz 16Bit Stereo")
        ComboBox2.Items.Add("Linear PCM 44kHz 8Bit Mono")
        ComboBox2.Items.Add("Linear PCM 44kHz 8Bit Stereo")
        ComboBox2.Items.Add("Linear PCM 44kHz 16Bit Mono")
        ComboBox2.Items.Add("Linear PCM 44kHz 16Bit Stereo")
        ComboBox2.Items.Add("Linear PCM 48kHz 8Bit Mono")
        ComboBox2.Items.Add("Linear PCM 48kHz 8Bit Stereo")
        ComboBox2.Items.Add("Linear PCM 48kHz 16Bit Mono")
        ComboBox2.Items.Add("Linear PCM 48kHz 16Bit Stereo")

        'VOX Lists
        ComboBox3.Items.Add("ADPCM 8kHz mono (*)")          'SAFTADPCM_8kHzMono = 56
        ComboBox3.Items.Add("mu-law PCM 8kHz mono (***)")   'SAFTCCITT_uLaw_8kHzMono = 48
        ComboBox3.Items.Add("A-law PCM 8kHz mono (***)")    'SAFTCCITT_ALaw_8kHzMono = 41

        ComboBox4.Items.Add("-none-")

        'MP3 Lists

        Me.ComboBox1.SelectedIndex = 0
        Me.ComboBox2.SelectedIndex = 24
        Me.ComboBox3.SelectedIndex = 0
        Me.ComboBox4.SelectedIndex = 0
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click

        ' Set output stream to speaker
        V.AllowAudioOutputFormatChangesOnNextSet = True
        V.AudioOutputStream = Nothing

        'The new voice speaks its own name
        V.Speak("Unseen in thailand มุมมองใหม่เมืองไทย")
        V.WaitUntilDone(-1)

    End Sub


    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        ' create a wave stream
        Dim cpFileStream As New SpFileStream

        ' Set output format to selected format
        If Me.ComboBox2.SelectedIndex < 36 And Me.ComboBox2.SelectedIndex >= 0 Then
            'PCM
            cpFileStream.Format.Type = Me.ComboBox2.SelectedIndex + 4
        End If

        ' Open the file for write
        Dim FilePathNumber As Integer
        While File.Exists("c:\WAV" & Format(FilePathNumber, "0000") & ".wav") = True
            FilePathNumber = FilePathNumber + 1
        End While

        cpFileStream.Open("c:\WAV" & Format(FilePathNumber, "0000") & ".wav", SpeechStreamFileMode.SSFMCreateForWrite, False)

        ' Set output stream to the file stream
        V.AllowAudioOutputFormatChangesOnNextSet = False
        V.AudioOutputStream = cpFileStream

        ' speak the given text with given flags
        V.Speak(TextBox1.Text, SpeechVoiceSpeakFlags.SVSFDefault)

        ' wait until it's done speaking with a really really long timeout.
        ' the tiemout value is in unit of millisecond. -1 means forever.
        V.WaitUntilDone(-1)

        ' close the file stream
        cpFileStream.Close()
        cpFileStream = Nothing

        MsgBox("WAV file successfully written!", vbOKOnly, "File Saved")
        Exit Sub

ErrHandler:
        'User pressed the Cancel button, do not show error
        If Not (Err.Number = 32755) Then
            MsgBox("Save to Wave file Error:", Err.Description)
        End If

        If Not cpFileStream Is Nothing Then
            cpFileStream = Nothing
        End If
    End Sub

    Private Sub TbrSpeed_Scroll(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TbrSpeed.Scroll
        LblSpeed.Text = "Voice Speed =" & TbrSpeed.Value.ToString
        V.Rate = TbrSpeed.Value
    End Sub

    Private Sub TbrVolume_Scroll(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TbrVolume.Scroll
        LblVolume.Text = "Voice Volume =" & TbrVolume.Value.ToString
        V.Volume = TbrVolume.Value
    End Sub


    Private Sub ComboBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ComboBox1.SelectedIndexChanged
        If ComboBox1.SelectedIndex > -1 Then
            'Set voice object to voice name selected in list box
            V.Voice = V.GetVoices().Item(ComboBox1.SelectedIndex)
        Else
            MsgBox("Please select a voice from the listbox or install any speech engine")
        End If



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
        Exit Sub

Error_Handle:
        MsgBox("Fail to open PPA Tatip. Please open PPA Tatip manually", MsgBoxStyle.Information, "Fail to open PPA Tatip.")
    End Sub



    Private Sub PictureBox1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox1.Click
        System.Diagnostics.Process.Start("www.mp3dev.org")
    End Sub


    Private Sub PictureBox2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox2.Click
        System.Diagnostics.Process.Start("www.intel.com")
    End Sub

    Private Sub PictureBox3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PictureBox3.Click
        System.Diagnostics.Process.Start("www.microsoft.com")
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        ' create a wave stream
        Dim cpFileStream2 As New SpFileStream
        Dim FilePathNumber As Integer
        Dim Filename As String

        Select Case Me.ComboBox3.SelectedIndex
            Case 0
                cpFileStream2.Format.Type = SpeechAudioFormatType.SAFTADPCM_8kHzMono
            Case 1
                cpFileStream2.Format.Type = SpeechAudioFormatType.SAFTCCITT_uLaw_8kHzMono
            Case 2
                cpFileStream2.Format.Type = SpeechAudioFormatType.SAFTCCITT_ALaw_8kHzMono
        End Select

        ' Open the file for write
        While File.Exists("C:\VOX" & Format(FilePathNumber, "0000") & ".vox") = True
            FilePathNumber = FilePathNumber + 1
        End While
        Filename = "C:\VOX" & Format(FilePathNumber, "0000") & ".wav"
        cpFileStream2.Open(Filename, SpeechStreamFileMode.SSFMCreateForWrite, False)

        ' Set output stream to the file stream
        V.AllowAudioOutputFormatChangesOnNextSet = False
        V.AudioOutputStream = cpFileStream2

        ' speak the given text with given flags
        V.Speak(TextBox1.Text, SpeechVoiceSpeakFlags.SVSFDefault)

        ' wait until it's done speaking with a really really long timeout.
        ' the tiemout value is in unit of millisecond. -1 means forever.
        V.WaitUntilDone(-1)

        ' close the file stream
        cpFileStream2.Close()
        cpFileStream2 = Nothing

        'Rename to VOX file
        File.Move(Filename, Replace(Filename, ".wav", ".vox"))

        MsgBox("WAV/VOX file successfully written!", vbOKOnly, "File Saved")
        Exit Sub

ErrHandler:
        'User pressed the Cancel button, do not show error
        If Not (Err.Number = 32755) Then
            MsgBox("Save to Wave file Error:", Err.Description)
        End If

        If Not cpFileStream2 Is Nothing Then
            cpFileStream2 = Nothing
        End If
    End Sub

    Function FindProcess(ByVal Process As Object) As Boolean
        Dim objWMIService As Object, colProcesses As Object
        objWMIService = GetObject("winmgmts:")
        colProcesses = objWMIService.ExecQuery("Select * from Win32_Process where name='" & Process & "'")
        If colProcesses.Count Then FindProcess = True
    End Function


End Class




'comment
'Dim F As New SpAudioFormatClass
'Dim W As New SpWaveFormatExClass
'F.Type = SpeechAudioFormatType.SAFT11kHz8BitMono
'W = F.GetWaveFormatEx
'W.BitsPerSample = 20
'W.SamplesPerSec = 8000
'MsgBox("AvgBytesPerSec" & W.AvgBytesPerSec)
'MsgBox("BitsPerSample" & W.BitsPerSample)
'MsgBox("BlockAlign" & W.BlockAlign)
'MsgBox("Channels" & W.Channels)
'MsgBox("ExtraData" & W.ExtraData)
'MsgBox("FormatTag" & W.FormatTag)
'MsgBox("SamplesPerSec" & W.SamplesPerSec)
'F.SetWaveFormatEx(W)
'cpFileStream2.Format = F