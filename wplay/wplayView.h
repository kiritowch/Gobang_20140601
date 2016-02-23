// wplayView.h : interface of the CWplayView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WPLAYVIEW_H__C0058B70_10E3_44E6_86CE_B8ACADBE35D7__INCLUDED_)
#define AFX_WPLAYVIEW_H__C0058B70_10E3_44E6_86CE_B8ACADBE35D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afx.h>
#include "mmsystem.h"//��������ͷ�ļ�
#pragma comment(lib,"winmm.lib")//��������ͷ�ļ���

class CWplayView : public CView
{
protected: // create from serialization only
	CWplayView();
	DECLARE_DYNCREATE(CWplayView)
		
		// Attributes
public:
	CWplayDoc* GetDocument();
	// Operations
public:
	//�������      
	HCURSOR hcursorwhite;
	HCURSOR hcursorblack;
    //��������
	int qz[19][19];   //19 19 ʵ��Ϊ19������ֹBUG

    // colorwhite TRUEʱ�����£����������
	bool colorwhite;
    //����λͼ���ڹ��캯��������Դλͼʵ�ֹҹ�
	CBitmap m_bmblack;
	CBitmap m_bmwhite;
	//��һ�η��µ����ӣ�����ʮ���ģ�
	CBitmap m_bmblackh;
	CBitmap m_bmwhiteh;

	int startflag;	
	//	CDC m_dcCompatible;//ʵ������ͼ���ڴ���ʱ����
	//	BOOL m_bLButtonDown;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWplayView)
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL
	
	// Implementation
public:
	void over(CPoint point);
	void background();
	void OnStart();
	virtual ~CWplayView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	
protected:
	
	// Generated message map functions
protected:
	//{{AFX_MSG(CWplayView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnEditCut();
	afx_msg void OnEasy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in wplayView.cpp
inline CWplayDoc* CWplayView::GetDocument()
{ return (CWplayDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WPLAYVIEW_H__C0058B70_10E3_44E6_86CE_B8ACADBE35D7__INCLUDED_)
