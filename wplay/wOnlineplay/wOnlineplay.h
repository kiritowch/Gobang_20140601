// wOnlineplay.h : main header file for the WONLINEPLAY application
//

#if !defined(AFX_WONLINEPLAY_H__D180540D_AC87_400A_B3AD_F6FC50B7B6BC__INCLUDED_)
#define AFX_WONLINEPLAY_H__D180540D_AC87_400A_B3AD_F6FC50B7B6BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWOnlineplayApp:
// See wOnlineplay.cpp for the implementation of this class
//

class CWOnlineplayApp : public CWinApp
{
public:
	CWOnlineplayApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWOnlineplayApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWOnlineplayApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WONLINEPLAY_H__D180540D_AC87_400A_B3AD_F6FC50B7B6BC__INCLUDED_)
