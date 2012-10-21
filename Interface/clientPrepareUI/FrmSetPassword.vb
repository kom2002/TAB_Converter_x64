'namespaces added to support functionality 
Imports System.Data                         'Database support
Imports System.Data.OleDb                   'Oledb support
Imports System

Public Class FrmSetPassword
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
    Friend WithEvents Panel1 As System.Windows.Forms.Panel
    Friend WithEvents ListBox1 As System.Windows.Forms.ListBox
    Friend WithEvents TextBox2 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox3 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox4 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox5 As System.Windows.Forms.TextBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents FolderBrowserDialog1 As System.Windows.Forms.FolderBrowserDialog
    Friend WithEvents Button3 As System.Windows.Forms.Button
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.Label4 = New System.Windows.Forms.Label
        Me.TextBox1 = New System.Windows.Forms.TextBox
        Me.Button5 = New System.Windows.Forms.Button
        Me.Button4 = New System.Windows.Forms.Button
        Me.Panel1 = New System.Windows.Forms.Panel
        Me.Button3 = New System.Windows.Forms.Button
        Me.Button2 = New System.Windows.Forms.Button
        Me.Button1 = New System.Windows.Forms.Button
        Me.Label5 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label1 = New System.Windows.Forms.Label
        Me.TextBox5 = New System.Windows.Forms.TextBox
        Me.TextBox4 = New System.Windows.Forms.TextBox
        Me.TextBox3 = New System.Windows.Forms.TextBox
        Me.TextBox2 = New System.Windows.Forms.TextBox
        Me.ListBox1 = New System.Windows.Forms.ListBox
        Me.FolderBrowserDialog1 = New System.Windows.Forms.FolderBrowserDialog
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
        Me.GroupBox1.Location = New System.Drawing.Point(8, 8)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(568, 56)
        Me.GroupBox1.TabIndex = 2
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Setting Working Directory:"
        '
        'Label4
        '
        Me.Label4.Location = New System.Drawing.Point(432, 32)
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
        Me.TextBox1.Size = New System.Drawing.Size(176, 20)
        Me.TextBox1.TabIndex = 0
        Me.TextBox1.Text = "D:\NBL"
        '
        'Button5
        '
        Me.Button5.Location = New System.Drawing.Point(312, 24)
        Me.Button5.Name = "Button5"
        Me.Button5.Size = New System.Drawing.Size(112, 24)
        Me.Button5.TabIndex = 2
        Me.Button5.Text = "&Test Connection"
        '
        'Button4
        '
        Me.Button4.Location = New System.Drawing.Point(192, 24)
        Me.Button4.Name = "Button4"
        Me.Button4.Size = New System.Drawing.Size(112, 24)
        Me.Button4.TabIndex = 1
        Me.Button4.Text = "&Change Folder"
        '
        'Panel1
        '
        Me.Panel1.Controls.Add(Me.Button3)
        Me.Panel1.Controls.Add(Me.Button2)
        Me.Panel1.Controls.Add(Me.Button1)
        Me.Panel1.Controls.Add(Me.Label5)
        Me.Panel1.Controls.Add(Me.Label3)
        Me.Panel1.Controls.Add(Me.Label2)
        Me.Panel1.Controls.Add(Me.Label1)
        Me.Panel1.Controls.Add(Me.TextBox5)
        Me.Panel1.Controls.Add(Me.TextBox4)
        Me.Panel1.Controls.Add(Me.TextBox3)
        Me.Panel1.Controls.Add(Me.TextBox2)
        Me.Panel1.Controls.Add(Me.ListBox1)
        Me.Panel1.Enabled = False
        Me.Panel1.Location = New System.Drawing.Point(0, 72)
        Me.Panel1.Name = "Panel1"
        Me.Panel1.Size = New System.Drawing.Size(576, 424)
        Me.Panel1.TabIndex = 3
        '
        'Button3
        '
        Me.Button3.Location = New System.Drawing.Point(504, 144)
        Me.Button3.Name = "Button3"
        Me.Button3.Size = New System.Drawing.Size(64, 24)
        Me.Button3.TabIndex = 9
        Me.Button3.Text = "&Delete"
        '
        'Button2
        '
        Me.Button2.Location = New System.Drawing.Point(504, 112)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(64, 24)
        Me.Button2.TabIndex = 6
        Me.Button2.Text = "&Refersh"
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(224, 80)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(64, 24)
        Me.Button1.TabIndex = 4
        Me.Button1.Text = "&Add"
        '
        'Label5
        '
        Me.Label5.Location = New System.Drawing.Point(8, 32)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(80, 16)
        Me.Label5.TabIndex = 8
        Me.Label5.Text = "Month of birth"
        '
        'Label3
        '
        Me.Label3.Location = New System.Drawing.Point(8, 80)
        Me.Label3.Name = "Label3"
        Me.Label3.TabIndex = 7
        Me.Label3.Text = "4 digits password"
        '
        'Label2
        '
        Me.Label2.Location = New System.Drawing.Point(8, 56)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(128, 16)
        Me.Label2.TabIndex = 6
        Me.Label2.Text = "4 digits Thai year of birth"
        '
        'Label1
        '
        Me.Label1.Location = New System.Drawing.Point(8, 8)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(72, 16)
        Me.Label1.TabIndex = 5
        Me.Label1.Text = "Date of birth"
        '
        'TextBox5
        '
        Me.TextBox5.AccessibleDescription = "4 digits password"
        Me.TextBox5.Location = New System.Drawing.Point(136, 80)
        Me.TextBox5.MaxLength = 4
        Me.TextBox5.Name = "TextBox5"
        Me.TextBox5.Size = New System.Drawing.Size(72, 20)
        Me.TextBox5.TabIndex = 3
        Me.TextBox5.Text = ""
        '
        'TextBox4
        '
        Me.TextBox4.AccessibleDescription = "4 digitsThai year of birth"
        Me.TextBox4.AccessibleName = "4 digitsThai year of birth"
        Me.TextBox4.Location = New System.Drawing.Point(136, 56)
        Me.TextBox4.MaxLength = 4
        Me.TextBox4.Name = "TextBox4"
        Me.TextBox4.Size = New System.Drawing.Size(72, 20)
        Me.TextBox4.TabIndex = 2
        Me.TextBox4.Text = ""
        '
        'TextBox3
        '
        Me.TextBox3.AccessibleDescription = "Month of birth"
        Me.TextBox3.AccessibleName = "Month of birth"
        Me.TextBox3.Location = New System.Drawing.Point(136, 32)
        Me.TextBox3.MaxLength = 2
        Me.TextBox3.Name = "TextBox3"
        Me.TextBox3.Size = New System.Drawing.Size(72, 20)
        Me.TextBox3.TabIndex = 1
        Me.TextBox3.Text = ""
        '
        'TextBox2
        '
        Me.TextBox2.AccessibleDescription = "Date of Birth"
        Me.TextBox2.AccessibleName = "Date of Birth"
        Me.TextBox2.Location = New System.Drawing.Point(136, 8)
        Me.TextBox2.MaxLength = 2
        Me.TextBox2.Name = "TextBox2"
        Me.TextBox2.Size = New System.Drawing.Size(72, 20)
        Me.TextBox2.TabIndex = 0
        Me.TextBox2.Text = ""
        '
        'ListBox1
        '
        Me.ListBox1.Location = New System.Drawing.Point(8, 112)
        Me.ListBox1.Name = "ListBox1"
        Me.ListBox1.Size = New System.Drawing.Size(488, 303)
        Me.ListBox1.TabIndex = 5
        '
        'FrmSetPassword
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 13)
        Me.ClientSize = New System.Drawing.Size(578, 498)
        Me.Controls.Add(Me.Panel1)
        Me.Controls.Add(Me.GroupBox1)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow
        Me.Name = "FrmSetPassword"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "FrmSetPassword"
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
            Panel1.Enabled = False
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

            Label4.Text = "Success."
            Panel1.Enabled = True
            Button2_Click(sender, e)
            TextBox2.Focus()
        Catch ex As Exception
            'Change status of checking
            Label4.Text = "Fail."
            MsgBox("Fail.")
        End Try
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        If (Len(TextBox2.Text) <> 2) Then
            MsgBox("Date of birth field ไม่ถูกต้อง")
            Exit Sub
        End If

        If (Len(TextBox3.Text) <> 2) Then
            MsgBox("Month of birth field ไม่ถูกต้อง")
            Exit Sub
        End If

        If (Len(TextBox4.Text) <> 4) Then
            MsgBox("4 digits Thai year of birth field ไม่ถูกต้อง")
            Exit Sub
        End If

        If (Len(TextBox5.Text) <> 4) Then
            MsgBox("4 digits password field ไม่ถูกต้อง")
            Exit Sub
        End If

        
        '///////////////////////////////////////////////////
        'update database (delete old & add new) fot bookName
        '///////////////////////////////////////////////////
        Try
            myConn.Open()

            Dim MyAccessCode As String = Trim(TextBox2.Text) & Trim(TextBox3.Text) & Trim(TextBox4.Text) & Trim(TextBox5.Text)
            Dim MyBithDate As String = Trim(TextBox2.Text) & Trim(TextBox3.Text) & Trim(TextBox4.Text)
            Dim MyPassword As String = Trim(TextBox5.Text)
            Dim tmpList As String

            Dim myCmd As OleDbCommand = New OleDbCommand("delete from TbUserPassword where AccessCode like '" & MyAccessCode & "'", myConn)
            myCmd.ExecuteNonQuery()

            tmpList = "insert into TbUserPassword(BirthDate, [Password], AccessCode) values('" & MyBithDate & "','" & MyPassword & "','" & MyAccessCode & "')"
            myCmd = New OleDbCommand(tmpList, myConn)
            myCmd.ExecuteNonQuery()

            myConn.Close()

            MsgBox("บันทึกข้อมูล Password เรียบร้อย")

            TextBox2.Clear()
            TextBox3.Clear()
            TextBox4.Clear()
            TextBox5.Clear()
            Button2_Click(sender, e)
        Catch err As Exception
            myConn.Close()
            MsgBox("ไม่สามารถบันทึกข้อมูลได้ กรุณาตรวจสอบข้อมูลใหม่อีกครั้ง " & vbCrLf & err.Message, MsgBoxStyle.OKOnly, "Incomplete")
        End Try

    End Sub

    Private Sub TextBox2_LostFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles TextBox2.LostFocus
        If Len(TextBox2.Text) = 1 Then
            TextBox2.Text = "0" & TextBox2.Text
        End If
    End Sub

    Private Sub TextBox3_LostFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles TextBox3.LostFocus
        If Len(TextBox3.Text) = 1 Then
            TextBox3.Text = "0" & TextBox3.Text
        End If
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        ListBox1.Items.Clear()

        myConn.Open()
        Dim myCmd As OleDbCommand = New OleDbCommand("select * from TbUserPassword order by AccessCode ASC", myConn)
        myReader = myCmd.ExecuteReader()
        Dim tmpList As String

        While myReader.Read()
            If (IsDBNull(myReader.Item("BirthDate")) = False) And _
               (IsDBNull(myReader.Item("Password")) = False) And _
               (IsDBNull(myReader.Item("AccessCode")) = False) Then

                tmpList = myReader.Item("AccessCode")
                tmpList = tmpList & " : "
                tmpList = tmpList & myReader.Item("BirthDate")
                tmpList = tmpList & " / "
                tmpList = tmpList & myReader.Item("Password")

                ListBox1.Items.Add(tmpList)
            End If
        End While

        myReader.Close()
        myConn.Close()

        If ListBox1.Items.Count > 0 Then
            ListBox1.SelectedIndex = 0
        End If

    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        myConn.Open()
        Dim tmpList As String = Microsoft.VisualBasic.Left(ListBox1.SelectedItem, 12)
        Dim myCmd As OleDbCommand = New OleDbCommand("delete from TbUserPassword where AccessCode like '" & tmpList & "'", myConn)
        myCmd.ExecuteNonQuery()
        myConn.Close()
        Button2_Click(sender, e)
    End Sub
End Class
