; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWwelcomeDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "wwelcome.h"

ClassCount=4
Class1=CWwelcomeApp
Class2=CWwelcomeDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_WWELCOME_DIALOG

[CLS:CWwelcomeApp]
Type=0
HeaderFile=wwelcome.h
ImplementationFile=wwelcome.cpp
Filter=N

[CLS:CWwelcomeDlg]
Type=0
HeaderFile=wwelcomeDlg.h
ImplementationFile=wwelcomeDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=wwelcomeDlg.h
ImplementationFile=wwelcomeDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_WWELCOME_DIALOG]
Type=1
Class=CWwelcomeDlg
ControlCount=6
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_BUTTON2,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_BUTTON3,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BUTTON4,button,1342242816

