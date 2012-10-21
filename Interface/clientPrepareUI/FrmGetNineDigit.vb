'namespaces added to support functionality 
Imports System.Data                         'Database support
Imports System.Data.OleDb                   'Oledb support
Imports System
Imports System.IO

Public Class FrmGetNineDigit
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
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents TextBox1 As System.Windows.Forms.TextBox
    Friend WithEvents Button5 As System.Windows.Forms.Button
    Friend WithEvents Button4 As System.Windows.Forms.Button
    Friend WithEvents FolderBrowserDialog1 As System.Windows.Forms.FolderBrowserDialog
    Friend WithEvents Panel1 As System.Windows.Forms.Panel
    Friend WithEvents TextBox2 As System.Windows.Forms.TextBox
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.Label4 = New System.Windows.Forms.Label
        Me.TextBox1 = New System.Windows.Forms.TextBox
        Me.Button5 = New System.Windows.Forms.Button
        Me.Button4 = New System.Windows.Forms.Button
        Me.FolderBrowserDialog1 = New System.Windows.Forms.FolderBrowserDialog
        Me.Panel1 = New System.Windows.Forms.Panel
        Me.TextBox2 = New System.Windows.Forms.TextBox
        Me.GroupBox1.SuspendLayout()
        Me.Panel1.SuspendLayout()
        Me.SuspendLayout()
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.Label4)
        Me.GroupBox1.Controls.Add(Me.TextBox1)
        Me.GroupBox1.Controls.Add(Me.Button5)
        Me.GroupBox1.Controls.Add(Me.Button4)
        Me.GroupBox1.Location = New System.Drawing.Point(0, 8)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(784, 56)
        Me.GroupBox1.TabIndex = 1
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
        'TextBox1
        '
        Me.TextBox1.Cursor = System.Windows.Forms.Cursors.No
        Me.TextBox1.Location = New System.Drawing.Point(8, 24)
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.ReadOnly = True
        Me.TextBox1.Size = New System.Drawing.Size(400, 20)
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
        'Button4
        '
        Me.Button4.Location = New System.Drawing.Point(416, 24)
        Me.Button4.Name = "Button4"
        Me.Button4.Size = New System.Drawing.Size(112, 24)
        Me.Button4.TabIndex = 1
        Me.Button4.Text = "Change Folder"
        '
        'Panel1
        '
        Me.Panel1.Anchor = CType(((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left) _
                    Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.Panel1.Controls.Add(Me.TextBox2)
        Me.Panel1.Location = New System.Drawing.Point(0, 72)
        Me.Panel1.Name = "Panel1"
        Me.Panel1.Size = New System.Drawing.Size(792, 448)
        Me.Panel1.TabIndex = 2
        '
        'TextBox2
        '
        Me.TextBox2.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
                    Or System.Windows.Forms.AnchorStyles.Left) _
                    Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.TextBox2.Enabled = False
        Me.TextBox2.Location = New System.Drawing.Point(8, 8)
        Me.TextBox2.MaxLength = 9999999
        Me.TextBox2.Multiline = True
        Me.TextBox2.Name = "TextBox2"
        Me.TextBox2.Size = New System.Drawing.Size(776, 432)
        Me.TextBox2.TabIndex = 0
        Me.TextBox2.Text = ""
        '
        'FrmGetNineDigit
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 13)
        Me.ClientSize = New System.Drawing.Size(794, 522)
        Me.Controls.Add(Me.Panel1)
        Me.Controls.Add(Me.GroupBox1)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow
        Me.Name = "FrmGetNineDigit"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "FrmGetNineDigit"
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
            Label4.Text = ""
            TextBox2.Text = ""
            TextBox2.Enabled = False
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

            Dim myCmd As OleDbCommand = New OleDbCommand("SELECT * FROM TbBookInfo ORDER BY CategoryCode, BookID ASC", myConn)
            myReader = myCmd.ExecuteReader()

            TextBox2.Enabled = True

            While myReader.Read()
                If (IsDBNull(myReader.Item("9DigitBookCode")) = False) And _
                   (IsDBNull(myReader.Item("BookName")) = False) Then

                    TextBox2.Text = TextBox2.Text & myReader.Item("9DigitBookCode")
                    TextBox2.Text = TextBox2.Text & "  "
                    TextBox2.Text = TextBox2.Text & myReader.Item("BookName")
                    TextBox2.Text = TextBox2.Text & vbCrLf
                End If
            End While

            Label4.Text = "Success."
            myConn.Close()
            myReader.Close()

        Catch ex As Exception
            'Change status of checking
            Label4.Text = "Fail."
            MsgBox("Fail.")
        End Try
    End Sub

    Private Sub FrmGetNineDigit_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'Me.Button5_Click(sender, e)
    End Sub
End Class
