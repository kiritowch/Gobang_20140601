// wplayDoc.cpp : implementation of the CWplayDoc class
//

#include "stdafx.h"
#include "wplay.h"

#include "wplayDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWplayDoc

IMPLEMENT_DYNCREATE(CWplayDoc, CDocument)

BEGIN_MESSAGE_MAP(CWplayDoc, CDocument)
	//{{AFX_MSG_MAP(CWplayDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWplayDoc construction/destruction

CWplayDoc::CWplayDoc()
{
	// TODO: add one-time construction code here

}

CWplayDoc::~CWplayDoc()
{
}

BOOL CWplayDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWplayDoc serialization

void CWplayDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWplayDoc diagnostics

#ifdef _DEBUG
void CWplayDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWplayDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWplayDoc commands
