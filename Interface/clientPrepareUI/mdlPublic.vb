Module mdlPublic
    Declare Auto Function PlaySound Lib "winmm.dll" (ByVal name _
       As String, ByVal hmod As Integer, ByVal flags As Integer) As Integer
    ' name specifies the sound file when the SND_FILENAME flag is set.
    ' hmod specifies an executable file handle.
    ' hmod must be Nothing if the SND_RESOURCE flag is not set.
    ' flags specifies which flags are set. 

    ' The PlaySound documentation lists all valid flags.
    Public Const SND_SYNC As Object = &H0          ' play synchronously
    Public Const SND_ASYNC As Object = &H1         ' play asynchronously
    Public Const SND_FILENAME As Object = &H20000  ' name is file name
    Public Const SND_RESOURCE As Object = &H40004  ' name is resource name or atom

    Public Sub PlaySoundFile(ByVal filename As String)
        ' Plays a sound from filename.
        PlaySound(filename, Nothing, SND_FILENAME Or SND_ASYNC)
    End Sub

    Public Sub PlaySoundFileSYNC(ByVal filename As String)
        ' Plays a sound from filename.
        PlaySound(filename, Nothing, SND_FILENAME Or SND_SYNC)
    End Sub

    Public Sub PlayMod5Percent(ByVal intPercent As Integer)
        ' Plays a sound from filename.
        PlaySound(Application.StartupPath & "\" & Trim(Str(intPercent)) & "percent.wav", Nothing, SND_FILENAME Or SND_SYNC)
    End Sub

    '    'Public Declare Function Start Lib "../../../Converter/Debug/Converter.dll" _
    '    '                        (ByVal strPath As String) As Integer

    '    'Public Declare Function AddNcc Lib "../../../Converter/Debug/Converter.dll" _
    '    '                        (ByVal strNccPath As String, _
    '    '                         ByVal strDestinationPath As String, _
    '    '                         ByVal strAudioOutputFormat As String) As String

    '    ' Public Declare Function Multiply Lib "../../../Converter/Debug/Converter.dll" _
    '    '                         (ByVal ParOne As Integer, _
    '    '                          ByVal ParTwo As Integer) As Integer

    '    '<DllImport("E:\My Data\My Documents\Visual Studio Projects\TAB\DaisyEngine\bin\SearchDaisy.dll", EntryPoint:="SEARCHDAISY_API", SetLastError:=True, _
    '    'CharSet:=CharSet.Unicode, ExactSpelling:=True, _
    '    'CallingConvention:=CallingConvention.StdCall)> _
    '    'Public Shared Function Add(ByVal num1 As Integer, ByVal num2 As Integer) As Integer

    '    'End Function

End Module
