// wwelcomeDlg.h : header file
//

#if !defined(AFX_WWELCOMEDLG_H__57D0912E_2495_4292_86CB_75EBB847B0C2__INCLUDED_)
#define AFX_WWELCOMEDLG_H__57D0912E_2495_4292_86CB_75EBB847B0C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWwelcomeDlg dialog

class CWwelcomeDlg : public CDialog
{
// Construction
public:
	CWwelcomeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWwelcomeDlg)
	enum { IDD = IDD_WWELCOME_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWwelcomeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWwelcomeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WWELCOMEDLG_H__57D0912E_2495_4292_86CB_75EBB847B0C2__INCLUDED_)
