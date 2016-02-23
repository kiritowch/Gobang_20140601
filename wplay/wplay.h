// wplay.h : main header file for the WPLAY application
//

#if !defined(AFX_WPLAY_H__75520A22_9ADF_49AD_992E_D51B1AA60FFC__INCLUDED_)
#define AFX_WPLAY_H__75520A22_9ADF_49AD_992E_D51B1AA60FFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "mmsystem.h"//导入声音头文件
#pragma comment(lib,"winmm.lib")//导入声音头文件库

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWplayApp:
// See wplay.cpp for the implementation of this class
//

class CWplayApp : public CWinApp
{
public:
	CWplayApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWplayApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CWplayApp)
	afx_msg void OnAppAbout();
	afx_msg void OnEditUndo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WPLAY_H__75520A22_9ADF_49AD_992E_D51B1AA60FFC__INCLUDED_)
