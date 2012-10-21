Public Class FrmAbout
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
    Friend WithEvents Panel1 As System.Windows.Forms.Panel
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents TextBox1 As System.Windows.Forms.TextBox
    Friend WithEvents PictureBox1 As System.Windows.Forms.PictureBox
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Dim resources As System.Resources.ResourceManager = New System.Resources.ResourceManager(GetType(FrmAbout))
        Me.Panel1 = New System.Windows.Forms.Panel
        Me.Label1 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.Label4 = New System.Windows.Forms.Label
        Me.Button1 = New System.Windows.Forms.Button
        Me.Label5 = New System.Windows.Forms.Label
        Me.Label6 = New System.Windows.Forms.Label
        Me.TextBox1 = New System.Windows.Forms.TextBox
        Me.PictureBox1 = New System.Windows.Forms.PictureBox
        Me.Panel1.SuspendLayout()
        Me.SuspendLayout()
        '
        'Panel1
        '
        Me.Panel1.BackColor = System.Drawing.Color.White
        Me.Panel1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.Panel1.Controls.Add(Me.Label5)
        Me.Panel1.Controls.Add(Me.Label6)
        Me.Panel1.Location = New System.Drawing.Point(-8, -8)
        Me.Panel1.Name = "Panel1"
        Me.Panel1.Size = New System.Drawing.Size(520, 64)
        Me.Panel1.TabIndex = 0
        '
        'Label1
        '
        Me.Label1.Location = New System.Drawing.Point(80, 64)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(432, 16)
        Me.Label1.TabIndex = 3
        Me.Label1.Text = "About TAB Converter"
        '
        'Label2
        '
        Me.Label2.Location = New System.Drawing.Point(80, 88)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(432, 16)
        Me.Label2.TabIndex = 4
        Me.Label2.Text = "Version"
        '
        'Label3
        '
        Me.Label3.Location = New System.Drawing.Point(80, 112)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(432, 16)
        Me.Label3.TabIndex = 5
        Me.Label3.Text = "This application is use for convert any DAISY format to ANSI/NISO Z39.86-2005"
        '
        'Label4
        '
        Me.Label4.Location = New System.Drawing.Point(80, 136)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(432, 16)
        Me.Label4.TabIndex = 6
        Me.Label4.Text = "Contact Us via E-mail: kom2002@yahoo.com"
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(408, 240)
        Me.Button1.Name = "Button1"
        Me.Button1.TabIndex = 7
        Me.Button1.Text = "&Close"
        '
        'Label5
        '
        Me.Label5.Font = New System.Drawing.Font("Microsoft Sans Serif", 10.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(222, Byte))
        Me.Label5.Location = New System.Drawing.Point(16, 16)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(416, 16)
        Me.Label5.TabIndex = 8
        Me.Label5.Text = "About and Disclaimer of TAB Converter"
        '
        'Label6
        '
        Me.Label6.Location = New System.Drawing.Point(24, 40)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(408, 16)
        Me.Label6.TabIndex = 8
        Me.Label6.Text = "In this page you can read about and disclaimer of TAB Converter."
        '
        'TextBox1
        '
        Me.TextBox1.Location = New System.Drawing.Point(8, 160)
        Me.TextBox1.Multiline = True
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.ScrollBars = System.Windows.Forms.ScrollBars.Vertical
        Me.TextBox1.Size = New System.Drawing.Size(480, 72)
        Me.TextBox1.TabIndex = 8
        Me.TextBox1.Text = "TAB Converter is one part of TAB-IVR project which was developed by Mr.Tanakom Ta" & _
        "lawat and Miss Supharat Piamlaphpitaya under financial supported by TAB, TOT, Ra" & _
        "tchasuda Foundation. " & Microsoft.VisualBasic.ChrW(13) & Microsoft.VisualBasic.ChrW(10) & Microsoft.VisualBasic.ChrW(13) & Microsoft.VisualBasic.ChrW(10) & "BETA SUPPORT POLICY" & Microsoft.VisualBasic.ChrW(13) & Microsoft.VisualBasic.ChrW(10) & "----------------------------------" & _
        "------------" & Microsoft.VisualBasic.ChrW(13) & Microsoft.VisualBasic.ChrW(10) & "Important Information:  This is pre-release (beta) software distri" & _
        "buted for feedback and testing purposes. TAB does not provide technical support " & _
        "for beta products (see above for information about how to contact me). If TAB Co" & _
        "nverter is causing an issue with your system we recommend removing it by using A" & _
        "dd or Remove Programs and even using System Restore if the problem persists." & Microsoft.VisualBasic.ChrW(13) & Microsoft.VisualBasic.ChrW(10) & Microsoft.VisualBasic.ChrW(13) & Microsoft.VisualBasic.ChrW(10) & _
        "Support" & Microsoft.VisualBasic.ChrW(13) & Microsoft.VisualBasic.ChrW(10) & "------------------" & Microsoft.VisualBasic.ChrW(13) & Microsoft.VisualBasic.ChrW(10) & "For more information on the TAB Converter (Beta) pr" & _
        "oduct, contact me via e-mail." & Microsoft.VisualBasic.ChrW(13) & Microsoft.VisualBasic.ChrW(10) & Microsoft.VisualBasic.ChrW(13) & Microsoft.VisualBasic.ChrW(10) & "Assisted support for this beta product is not a" & _
        "vailable.  Once the final release of TAB Converter  has been made publicly avail" & _
        "able, customers will be able to contact Product Support Services for help. In th" & _
        "e meantime, we have provided online support resources to help you try out the TA" & _
        "B Converter beta."
        '
        'PictureBox1
        '
        Me.PictureBox1.Image = CType(resources.GetObject("PictureBox1.Image"), System.Drawing.Image)
        Me.PictureBox1.Location = New System.Drawing.Point(8, 64)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(64, 88)
        Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox1.TabIndex = 9
        Me.PictureBox1.TabStop = False
        '
        'FrmAbout
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 13)
        Me.ClientSize = New System.Drawing.Size(490, 271)
        Me.Controls.Add(Me.PictureBox1)
        Me.Controls.Add(Me.TextBox1)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Panel1)
        Me.Controls.Add(Me.Label1)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog
        Me.Name = "FrmAbout"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "TAB Converter"
        Me.Panel1.ResumeLayout(False)
        Me.ResumeLayout(False)

    End Sub

#End Region

    Private Sub FrmAbout_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Me.Label2.Text = "Version " & Application.ProductVersion()
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Me.Close()
    End Sub
End Class
