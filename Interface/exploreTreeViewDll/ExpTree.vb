Imports System
Imports System.ComponentModel
Imports System.Windows.Forms
Imports System.Drawing
Imports System.Enum
Imports System.IO
Imports System.Text
Imports TAB.Telephony.exploreTreeViewDll.CShItem
Imports TAB.Telephony.exploreTreeViewDll.SystemImageListManager

<DefaultProperty("StartUpDirectory"), DefaultEvent("StartUpDirectoryChanged")> _
Public Class ExpTree
    Inherits System.Windows.Forms.UserControl

    Private Root As TreeNode

    Public Event StartUpDirectoryChanged(ByVal newVal As StartDir)

    Public Event ExpTreeNodeSelected(ByVal SelPath As String, ByVal Item As CShItem)

#Region " Windows Form Designer generated code "

    Public Sub New()
        MyBase.New()

        'This call is required by the Windows Form Designer.
        InitializeComponent()

        'Add any initialization after the InitializeComponent() call

        SystemImageListManager.SetTreeViewImageList(tv1, False)

        AddHandler StartUpDirectoryChanged, AddressOf OnStartUpDirectoryChanged
    End Sub

    'UserControl1 overrides dispose to clean up the component list.
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
    Friend WithEvents tv1 As System.Windows.Forms.TreeView
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.tv1 = New System.Windows.Forms.TreeView()
        Me.SuspendLayout()
        '
        'tv1
        '
        Me.tv1.Dock = System.Windows.Forms.DockStyle.Fill
        Me.tv1.ImageIndex = -1
        Me.tv1.Name = "tv1"
        Me.tv1.SelectedImageIndex = -1
        Me.tv1.Size = New System.Drawing.Size(200, 264)
        Me.tv1.TabIndex = 0
        '
        'ExpTree
        '
        Me.Controls.AddRange(New System.Windows.Forms.Control() {Me.tv1})
        Me.Name = "ExpTree"
        Me.Size = New System.Drawing.Size(200, 264)
        Me.ResumeLayout(False)

    End Sub

#End Region

#Region "   Public Propertys"

#Region "   StartupDir"

    Public Enum StartDir As Integer
        Desktop = &H0
        MyComputer = &H11
        Programs = &H2
        Controls = &H3
        Printers = &H4
        Personal = &H5
        Favorites = &H6
        Startup = &H7
        Recent = &H8
        SendTo = &H9
        StartMenu = &HB
        MyDocuments = &HC
        'MyMusic = &HD
        'MyVideo = &HE
        DesktopDirectory = &H10
        Internet_Cache = &H20
        Cookies = &H21
        History = &H22
        Windows = &H24
        System = &H25
        Program_Files = &H26
        MyPictures = &H27
        Systemx86 = &H29
        AdminTools = &H30
    End Enum

    Private m_StartUpDirectory As StartDir = StartDir.Desktop

    <Category("Misc"), _
     Description("Sets the Initial Directory of the Tree"), _
     DefaultValue(StartDir.Desktop), Bindable(True)> _
    Public Property StartUpDirectory() As StartDir
        Get
            Return m_StartUpDirectory
        End Get
        Set(ByVal Value As StartDir)
            If Array.IndexOf(Value.GetValues(Value.GetType), Value) >= 0 Then
                m_StartUpDirectory = Value
                'Debug.WriteLine("New Value = " & Value)
                RaiseEvent StartUpDirectoryChanged(Value)
            Else
                Throw New ApplicationException("Invalid Initial StartUpDirectory")
            End If
        End Set
    End Property
#End Region

#Region "   RootItem"
    '<Summary>
    ' RootItem is a Run-Time only Property
    ' Setting this Item via an External call results in
    '  re-setting the entire tree to be rooted in the 
    '  input CShItem
    ' The new CShItem must be a valid CShItem of some kind
    '  of Folder (File Folder or System Folder)
    ' Attempts to set it using a non-Folder CShItem are ignored
    '</Summary>
    Public Property RootItem() As CShItem
        Get
            Return Root.Tag
        End Get
        Set(ByVal Value As CShItem)
            If Value.IsFolder Then
                If Not IsNothing(Root) Then
                    ClearTree()
                End If
                Root = New TreeNode(Value.DisplayName)
                BuildTree(Value.GetDirectories)
                Root.ImageIndex = SystemImageListManager.GetIconIndex(Value, False)
                Root.SelectedImageIndex = Root.ImageIndex
                Root.Tag = Value
                tv1.Nodes.Add(Root)
                Root.Expand()
                tv1.SelectedNode = Root
            End If
        End Set
    End Property
#End Region

#End Region

#Region "   Public Methods"
    Public Sub ExpandANode(ByVal newPath As String)
        ' Is newPath Valid ?
        newPath = System.IO.Path.GetFullPath(newPath)
        If Not Directory.Exists(newPath) Then Exit Sub
        ' Is newPath a directory on a local or mapped drive?
        Dim myRoot As String = System.IO.Path.GetPathRoot(newPath)
        If myRoot.Length <> 3 OrElse _
                 Not myRoot.EndsWith(System.IO.Path.VolumeSeparatorChar & _
                 System.IO.Path.DirectorySeparatorChar) Then Exit Sub
        Dim newItem As New CShItem(newPath)
        If Not newItem.IsFileSystem OrElse Not newItem.IsFolder Then Exit Sub
        ' Ensure tree is rooted on Desktop or MyComputer
        If Me.StartUpDirectory <> StartDir.Desktop _
                AndAlso Me.StartUpDirectory <> StartDir.MyComputer Then
            Me.StartUpDirectory = StartDir.Desktop
        End If
        Dim baseNode As TreeNode
        If Me.StartUpDirectory = StartDir.MyComputer Then
            baseNode = Root
            GoTo HAVEBASE
        ElseIf Not Me.StartUpDirectory = StartDir.Desktop Then
            Me.StartUpDirectory = StartDir.Desktop
        End If
        Dim testNode As TreeNode
        For Each testNode In Root.Nodes
            If testNode.Text = CShItem.strMyComputer Then
                baseNode = testNode
                GoTo HAVEBASE
            End If
        Next
        'Cant find MyComputer
        Exit Sub
HAVEBASE:  'Now we have MyComputer in baseNode
        baseNode.Expand()   'get it filled in
        'do the drill down
        Dim dirParts() As String = newPath.Split(System.IO.Path.DirectorySeparatorChar)
        Dim tmpStr As String
        Dim dirMatch As New StringBuilder()
        For Each tmpStr In dirParts
            dirMatch.Append(tmpStr)
            For Each testNode In baseNode.Nodes
                Dim testItem As CShItem = testNode.Tag
                'Disk Path ends with \, non-disk paths do not
                Dim sCompare As String = IIf(testItem.IsDisk, dirMatch.ToString & System.IO.Path.DirectorySeparatorChar, dirMatch.ToString)
                If testItem.Path.Equals(sCompare) Then
                    baseNode = testNode
                    baseNode.Expand()
                    dirMatch.Append(System.IO.Path.DirectorySeparatorChar)
                    Exit For
                End If
            Next
        Next
        tv1.HideSelection = False
        tv1.SelectedNode = baseNode
        tv1.Select()
    End Sub
#End Region

#Region "   Initial Dir Set Handler"

    Private Sub OnStartUpDirectoryChanged(ByVal newVal As StartDir)
        If Not IsNothing(Root) Then
            ClearTree()
        End If
        'Dim L1 As ArrayList
        Dim special As CShItem
        If CType(Val(m_StartUpDirectory), StartDir) = StartDir.Desktop Then
            special = GetDeskTop()
        Else
            special = New CShItem(CType(Val(m_StartUpDirectory), ShellDll.CSIDL))
        End If
        Root = New TreeNode(special.DisplayName)
        BuildTree(special.GetDirectories)
        Root.ImageIndex = SystemImageListManager.GetIconIndex(special, False)
        Root.SelectedImageIndex = Root.ImageIndex
        Root.Tag = special
        tv1.Nodes.Add(Root)
        Root.Expand()
    End Sub

    Private Sub BuildTree(ByVal L1 As ArrayList)
        L1.Sort()
        Dim CSI As CShItem
        For Each CSI In L1
            Dim T As TreeNode = MakeNode(CSI)
            If CSI.HasSubFolders Then
                Dim T2 As New TreeNode(" : ")
                T.Nodes.Add(T2)
            End If
            Root.Nodes.Add(T)
            'CSI.DebugDump()
        Next

    End Sub

    Private Function MakeNode(ByVal fi As CShItem) As TreeNode
        Dim node As New TreeNode(fi.DisplayName)
        node.Tag = fi
        node.ImageIndex = SystemImageListManager.GetIconIndex(fi, False)
        node.SelectedImageIndex = SystemImageListManager.GetIconIndex(fi, True)
        Return node
    End Function

    Private Sub ClearTree()
        tv1.Nodes.Clear()
        Root = Nothing
    End Sub
#End Region

#Region "   TreeView BeforeExpand Event"

    Private Sub tv1_BeforeExpand(ByVal sender As Object, ByVal e As System.Windows.Forms.TreeViewCancelEventArgs) Handles tv1.BeforeExpand
        If e.Node.Nodes.Count = 1 AndAlso e.Node.Nodes(0).Text.Equals(" : ") Then
            Dim oldCursor As Cursor = Cursor
            Cursor = Cursors.WaitCursor
            e.Node.Nodes.Clear()
            Dim CSI As CShItem = e.Node.Tag
            Dim D As ArrayList = CSI.GetDirectories
            If D.Count > 0 Then
                D.Sort()    'uses the class comparer
                Dim item As CShItem
                For Each item In D
                    Dim newNode As TreeNode = MakeNode(item)
                    If item.HasSubFolders Then
                        Dim T2 As New TreeNode(" : ")
                        newNode.Nodes.Add(T2)
                    End If
                    e.Node.Nodes.Add(newNode)
                    'item.DebugDump()
                Next
            End If
            Cursor = oldCursor
        End If
    End Sub
#End Region

#Region "   TreeView AfterSelect Event"
    Private Sub tv1_AfterSelect(ByVal sender As System.Object, ByVal e As System.Windows.Forms.TreeViewEventArgs) Handles tv1.AfterSelect
        Dim node As TreeNode = e.Node
        Dim CSI As CShItem = e.Node.Tag
        If CSI.GetDirectories.Count < 1 Then
            node.Nodes.Clear()
        End If
        If CSI.Path.StartsWith(":") Then
            RaiseEvent ExpTreeNodeSelected(CSI.DisplayName, CSI)
        Else
            RaiseEvent ExpTreeNodeSelected(CSI.Path, CSI)
        End If
    End Sub
#End Region
End Class
