// wplayDoc.h : interface of the CWplayDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WPLAYDOC_H__3F6AE266_131B_461B_98A4_89610FA9586B__INCLUDED_)
#define AFX_WPLAYDOC_H__3F6AE266_131B_461B_98A4_89610FA9586B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWplayDoc : public CDocument
{
protected: // create from serialization only
	CWplayDoc();
	DECLARE_DYNCREATE(CWplayDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWplayDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWplayDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWplayDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WPLAYDOC_H__3F6AE266_131B_461B_98A4_89610FA9586B__INCLUDED_)
