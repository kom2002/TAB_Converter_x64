'Imports TAB.Telephony.convertDaisyDLL
' Add an Imports statement at the top of the class or module
' where the DllImport attribute will be used.
Imports System.Runtime.InteropServices
'Imports SNDCVTXLib.SndCvtClass

Public Class FrmTest
    Inherits System.Windows.Forms.Form
    Public Declare Function Starter Lib "Converter.dll" (ByVal strPath As String) As Double
    Public Declare Function CreateConverterDll Lib "Converter.dll" () As Long
    Public Declare Sub DestroyConverterDll Lib "Converter.dll" (ByVal objptr As Long)
    Public Declare Function GetCpuSpeedConverterDll Lib "Converter.dll" (ByVal objptr As Long) As Integer
    Public Declare Function StartConverterDll Lib "Converter.dll" (ByVal strNcPath As String, ByVal strDestFolder As String, ByVal bolMakeSyntheticSound As Boolean, ByVal intOrderText2Speech As Integer, ByVal chrOutputAudioFormat As String, ByVal objptr As Long) As Integer
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
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents TextBox1 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox2 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox3 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox4 As System.Windows.Forms.TextBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents TextBox5 As System.Windows.Forms.TextBox
    Friend WithEvents Button2 As System.Windows.Forms.Button
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.TextBox1 = New System.Windows.Forms.TextBox()
        Me.TextBox2 = New System.Windows.Forms.TextBox()
        Me.TextBox3 = New System.Windows.Forms.TextBox()
        Me.TextBox4 = New System.Windows.Forms.TextBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.TextBox5 = New System.Windows.Forms.TextBox()
        Me.Button2 = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(464, 8)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(64, 64)
        Me.Button1.TabIndex = 0
        Me.Button1.Text = "Convert"
        '
        'TextBox1
        '
        Me.TextBox1.Location = New System.Drawing.Point(96, 8)
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.Size = New System.Drawing.Size(360, 20)
        Me.TextBox1.TabIndex = 1
        Me.TextBox1.Text = "D:\DTB_Library\DaisySkip202Book\ncc.html"
        '
        'TextBox2
        '
        Me.TextBox2.Location = New System.Drawing.Point(96, 32)
        Me.TextBox2.Name = "TextBox2"
        Me.TextBox2.Size = New System.Drawing.Size(360, 20)
        Me.TextBox2.TabIndex = 2
        Me.TextBox2.Text = "C:\test\"
        '
        'TextBox3
        '
        Me.TextBox3.Location = New System.Drawing.Point(96, 56)
        Me.TextBox3.Name = "TextBox3"
        Me.TextBox3.Size = New System.Drawing.Size(64, 20)
        Me.TextBox3.TabIndex = 3
        '
        'TextBox4
        '
        Me.TextBox4.Location = New System.Drawing.Point(256, 56)
        Me.TextBox4.Name = "TextBox4"
        Me.TextBox4.Size = New System.Drawing.Size(200, 20)
        Me.TextBox4.TabIndex = 4
        '
        'Label1
        '
        Me.Label1.Location = New System.Drawing.Point(8, 56)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(88, 16)
        Me.Label1.TabIndex = 5
        Me.Label1.Text = "CPU Speed :"
        Me.Label1.TextAlign = System.Drawing.ContentAlignment.BottomRight
        '
        'Label2
        '
        Me.Label2.Location = New System.Drawing.Point(168, 56)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(80, 16)
        Me.Label2.TabIndex = 6
        Me.Label2.Text = "Return Value :"
        Me.Label2.TextAlign = System.Drawing.ContentAlignment.BottomRight
        '
        'Label3
        '
        Me.Label3.Location = New System.Drawing.Point(0, 32)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(96, 16)
        Me.Label3.TabIndex = 7
        Me.Label3.Text = "Destination Path :"
        Me.Label3.TextAlign = System.Drawing.ContentAlignment.BottomRight
        '
        'Label4
        '
        Me.Label4.Location = New System.Drawing.Point(8, 8)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(88, 16)
        Me.Label4.TabIndex = 8
        Me.Label4.Text = "Source Path :"
        Me.Label4.TextAlign = System.Drawing.ContentAlignment.BottomRight
        '
        'Label5
        '
        Me.Label5.Location = New System.Drawing.Point(8, 80)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(88, 16)
        Me.Label5.TabIndex = 10
        Me.Label5.Text = "Audio Ext :"
        Me.Label5.TextAlign = System.Drawing.ContentAlignment.BottomRight
        '
        'TextBox5
        '
        Me.TextBox5.Location = New System.Drawing.Point(96, 80)
        Me.TextBox5.Name = "TextBox5"
        Me.TextBox5.Size = New System.Drawing.Size(64, 20)
        Me.TextBox5.TabIndex = 9
        Me.TextBox5.Text = "vox"
        '
        'Button2
        '
        Me.Button2.Location = New System.Drawing.Point(456, 200)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(64, 64)
        Me.Button2.TabIndex = 11
        Me.Button2.Text = "Convert"
        '
        'FrmTest
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 13)
        Me.ClientSize = New System.Drawing.Size(536, 309)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.Label5)
        Me.Controls.Add(Me.TextBox5)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.TextBox4)
        Me.Controls.Add(Me.TextBox3)
        Me.Controls.Add(Me.TextBox2)
        Me.Controls.Add(Me.TextBox1)
        Me.Controls.Add(Me.Button1)
        Me.Name = "FrmTest"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

#End Region

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim a As Double
        Dim nSpeed As Integer
        'Dim s As String
        Dim objptr As Long

        objptr = CreateConverterDll()
        nSpeed = GetCpuSpeedConverterDll(objptr)
        a = StartConverterDll(TextBox1.Text, TextBox2.Text, False, 1, TextBox5.Text, objptr)
        DestroyConverterDll(objptr)

        TextBox3.Text = nSpeed
        TextBox4.Text = a
    End Sub

    'Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
    'Dim a As New SNDCVTXLib.SndCvtClass
    'a.SoundFileConvert ( textbox1.Text , 0  
    'End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click

    End Sub

    Private Sub FrmTest_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

    End Sub
End Class
