; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWplayView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "wplay.h"
LastPage=0

ClassCount=5
Class1=CWplayApp
Class2=CWplayDoc
Class3=CWplayView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX

[CLS:CWplayApp]
Type=0
HeaderFile=wplay.h
ImplementationFile=wplay.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CWplayDoc]
Type=0
HeaderFile=wplayDoc.h
ImplementationFile=wplayDoc.cpp
Filter=N

[CLS:CWplayView]
Type=0
HeaderFile=wplayView.h
ImplementationFile=wplayView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_EASY




[CLS:CAboutDlg]
Type=0
HeaderFile=wplay.cpp
ImplementationFile=wplay.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EASY
Command2=ID_HARD
Command3=ID_HARD
Command4=ID_EDIT_CUT
Command5=ID_EDIT_UNDO
CommandCount=5

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
CommandCount=0

