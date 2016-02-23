// wplayView.cpp : implementation of the CWplayView class
//

#include "stdafx.h"
#include "wplay.h"

#include "wplayDoc.h"
#include "wplayView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWplayView

IMPLEMENT_DYNCREATE(CWplayView, CView)

BEGIN_MESSAGE_MAP(CWplayView, CView)
//{{AFX_MSG_MAP(CWplayView)
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_COMMAND(ID_EDIT_CUT, OnEditCut)
ON_COMMAND(ID_EASY, OnEasy)
//}}AFX_MSG_MAP
// Standard printing commands
ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWplayView construction/destruction

CWplayView::CWplayView()
{
	// TODO: add construction code here
	
	//������ͨ����λͼ
	m_bmwhite.LoadBitmap(IDB_BITMAP4);//����  ����λͼ��Դ~~~~~~~~~~~~~~~~~~~~~~~~~~~��,�˴�һ��Ҫ���ڹ��캯�����棬�Ƚ���Ҫ
	m_bmblack.LoadBitmap(IDB_BITMAP3);//����
	
	//��һ�����ӣ���������	
	m_bmwhiteh.LoadBitmap(IDB_BITMAP7);//����  ����λͼ��Դ~~~~~~~~~~~~~~~~~~~~~~~~~~~��,�˴�һ��Ҫ���ڹ��캯�����棬�Ƚ���Ҫ
	m_bmblackh.LoadBitmap(IDB_BITMAP8);//����
	
	//��������
	//����ֵΪ 0 ��ʾû������
	for(int i=0;i<19;i++)
		for(int j=0;j<19;j++)
			qz[i][j]=0;
		//��������
		colorwhite=true;
		startflag=0;
}

CWplayView::~CWplayView()
{
}

BOOL CWplayView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWplayView drawing

void CWplayView::OnDraw(CDC* pDC)
{
	CWplayDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//������
	CBrush m_brushBackground;
	CBitmap bmp;   
	bmp.LoadBitmap(IDB_BITMAP6); //��������λͼ    
	m_brushBackground.CreatePatternBrush(&bmp); //����λͼ��ˢ	
	CRect rect;  
	GetClientRect(rect);//ȡ�ÿͻ�����     
	pDC->FillRect(rect,&m_brushBackground); //�ñ�����ˢ�������
	
											/*---ԭ�ֹ���ͼ����------------------------
											CBrush mybrush1;
											mybrush1.CreateSolidBrush(RGB(192,192,192));	
											CRect myrect1(0,0,1200,800);
											pDC->FillRect(myrect1,&mybrush1);
											//�����̿���
											CPen mypen;
											CPen*myoldPen;
											mypen.CreatePen(PS_SOLID,1,RGB(0,0,0));
											myoldPen=pDC->SelectObject(&mypen);
											for(int i=0;i<19;i++)
											{		
											pDC->MoveTo(40,40+i*20);
											pDC->LineTo(400,40+i*20);
											pDC->MoveTo(40+i*20,40);
											pDC->LineTo(40+i*20,400);
											}
	*/ 			
}

/////////////////////////////////////////////////////////////////////////////
// CWplayView printing

BOOL CWplayView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWplayView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWplayView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CWplayView diagnostics

#ifdef _DEBUG
void CWplayView::AssertValid() const
{
	CView::AssertValid();
}

void CWplayView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}


CWplayDoc* CWplayView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWplayDoc)));
	return (CWplayDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWplayView message handlers

void CWplayView::background()
{
	return ;
}

void CWplayView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default	
	CView::OnLButtonDown(nFlags, point);
}

void CWplayView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default	
	
	/*	�����˶�սģʽ��������Ϊresource�л������ģ�ԭ��
	CDC Dc;
	CDC* pDC;
	CWplayDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	m_bmwhite.LoadBitmap(IDB_BITMAP1);//����λͼ��Դ~~~~~~~~~~~~~~~~~~~~~~~~~~~��������
	m_bmblack.LoadBitmap(IDB_BITMAP2);
	
	  
		if(point.x>30&&point.x<410&&point.y>30&&point.y<410)
		{
		int px=(point.x-30)/20;
		int py=(point.y-30)/20;
		//�Ƿ��Ѿ�������
		if(colorwhite&&qz[px][py]==0)
		{
		//	Dc.SelectObject(m_bmwhite);
		//	pDC->BitBlt(px*20+32,py*20+32,160,160,&Dc,0,0,SRCCOPY);
		//��ʾ���ڰ���
		qz[px][py]=1;
		//����Ƿ����
		//			over(point);
		//��������
		colorwhite=false;
		}
		else if(qz[px][py]==0)
		{
		//	Dc.SelectObject(m_bmblack);
		//	pDC->BitBlt(px*20+32,py*20+32,160,160,&Dc,0,0,SRCCOPY);
		qz[px][py]=-1;
		//			over(point);
		colorwhite=true;
		}
}*/
	
	
	
	//���ĺ��--------------------------------------------------------
	if(startflag==1)
	{
		CDC *pDC=GetDC();
		CDC Dc;
		if(Dc.CreateCompatibleDC(pDC)==FALSE)
			AfxMessageBox("Can't create DC");
		//��ʾ����
		
		//�ػ����ӣ�������������������ÿ����ͼ�ĸ��£�ʹÿһ�ε�һ������������ʵ���Զ����ģ�		
		for(int n=0;n<19;n++)
			for(int m=0;m<19;m++)
				if(qz[n][m]==1)
				{
					//��ʾ����
					Dc.SelectObject(m_bmwhite);
					pDC->BitBlt(n*20+32,m*20+32,160,160,&Dc,0,0,SRCCOPY);	
				}
				else if(qz[n][m]==-1)
				{
					//��ʾ����
					Dc.SelectObject(m_bmblack);
					pDC->BitBlt(n*20+32,m*20+32,160,160,&Dc,0,0,SRCCOPY);	
				}
				
				//���˼�ģʽ
				
				if(point.x>30&&point.x<410&&point.y>30&&point.y<410)
				{
					int px=(point.x-30)/20;
					int py=(point.y-30)/20;
					if(colorwhite&&qz[px][py]==0)
					{
						Dc.SelectObject(m_bmwhiteh);
						pDC->BitBlt(px*20+32,py*20+32,160,160,&Dc,0,0,SRCCOPY);
						qz[px][py]=1;
						over(point);
						colorwhite=false;
					}
					else if(qz[px][py]==0)
					{
						Dc.SelectObject(m_bmblackh);
						pDC->BitBlt(px*20+32,py*20+32,160,160,&Dc,0,0,SRCCOPY);
						qz[px][py]=-1;
						over(point);
						colorwhite=true;
					}
				}
				
	}			
	/*---------------ʵ������ͼ���ڴ��е���ʱ����-------------
	ReleaseCapture();//ȡ����겶��
	m_bLButtonDown=false;//��־��ԭ
	
	  CClientDC dc(this);//����DC
	  
		if(!m_dcCompatible.m_hDC)//������DCδ����,����֮  
		{  
		m_dcCompatible.CreateCompatibleDC(&dc);  
		}
		
		  //����ͼ������Ϊλͼ
		  CRect rect; 
		  GetClientRect(&rect);  
		  CBitmap bitmap;  
		  bitmap.CreateCompatibleBitmap(&dc,rect.Width(),rect.Height());  
		  
			//����DC��λͼ��������
			m_dcCompatible.SelectObject(&bitmap); 
			
			  //���豸�������Ƶ�����DC��
			  m_dcCompatible.BitBlt(0,0,rect.Width(),rect.Height(),&dc,0,0,SRCCOPY);   
	*/
	CView::OnLButtonUp(nFlags, point);
}

void CWplayView::over(CPoint point)
{
	
	//��ȡ��ǰ������һ�ε����ָ������λ�ã����ж���Ϸ�Ƿ����
	int x=(point.x-30)/20;
	int y=(point.y-30)/20;
	//���㿪ʼ�жϵ����� xx,yy
	int xx,yy;
	if(x<4)
		xx=0;
	else
		xx=x-4;
	if(y<4)
		yy=0;
	else
		yy=y-4;
	int i,j,a;
	//�����ж�

	for(i=0;i<8;i++)
	{
		a=0;
		for(j=xx+i;j<xx+i+5&&j<19;j++)
		{
			a=a+qz[j][y];
			//������ǰ���
				if(a==5)
				{
					MessageBox("����ʤ!");//�˴���BUG����������(���޸�)
					//���¿�ʼ
					OnStart();
					return;
				}
				//������Ǻ���
				if(a==-5)
				{
					MessageBox("����ʤ!");
					OnStart();
					return;
				}
		}
	}
	//�����ж�
	for(i=0;i<8;i++)
	{
		a=0;
		for(j=yy+i;j<yy+i+5&&j<19;j++)
		{
			a=a+qz[x][j];
			//������ǰ���
			if(a==5)
			{
				MessageBox("����ʤ!");
				//���¿�ʼ
				OnStart();
				return;
			}
			//������Ǻ���
			if(a==-5)
			{
				MessageBox("����ʤ!");
				OnStart();
				return;
			}		
		}
	}
	//б�ŵ��ж��������һ����Ч����΢��һЩ������֤����������㵽Ұֵ
	//�����½�
	int min;//�Ƚϵõ������Ͻǵ�λ��
	if(x<y) min=x;
	else min=y;
	
	xx=x-min;
	yy=y-min;
	
	int over=0;
	do
	{
		a=0;
		for(i=0;i<5;i++)
		{
			if((xx+i)<19&&(yy+i)<19)
			{
				a=a+qz[xx+i][yy+i];
				if(a==5)
				{
					MessageBox("����ʤ!");
					OnStart();
					return;
				}
				if(a==-5)
				{
					MessageBox("����ʤ!");
					OnStart();
					return;
				}
			}
			//���˱߽�
			else
				over=1;
		}
		xx+=1;
		yy+=1;
	}while(over==0);
	
	//�����½�
	int min2;//�Ƚϵõ������Ͻǵ�λ��
	if(18-x<y) min2=18-x;//18-xΪ���ŵ����ұߵľ��룬�磨0��17��
	else min2=y;	
	
	xx=x+min2;
	yy=y-min2;
	
	over=0;
	do
	{
		a=0;
		for(i=0;i<5;i++)
		{
			if((xx-i)>=0&&(yy+i)<19)
			{
				a=a+qz[xx-i][yy+i];
				if(a==5)
				{
					AfxMessageBox("����ʤ!");//�˴�������һBUG����ע���޸ģ����������޸ģ�
					OnStart();
					return;
				}
				if(a==-5)
				{
					AfxMessageBox("����ʤ!");
					OnStart();
					return;
				}
			}
			//���˱߽�
			else
				over=1;
		}
		xx-=1;
		yy+=1;
	}while(over==0);
}

void CWplayView::OnStart()
{
	for(int i=0;i<19;i++)
		for(int j=0;j<19;j++)
			qz[i][j]=0;         //���̳�ʼ��
		colorwhite=true;
		Invalidate(false);	
}




void CWplayView::OnEditCut() //�򿪱������֣�û��ʵ�֣����Ҳûʵ���������Ч
{
	// TODO: Add your command handler code here
	//	MessageBox("hello");
	//	ShellExecute(NULL, _T("open"), _T("C:\\wwhelp.txt"), NULL, NULL, SW_SHOW);//-----------------------���·�������÷���
	PlaySound("C:\\test.wma",NULL,SND_FILENAME | SND_ASYNC);
	//	PlaySound("C:\\test.wma",NULL, SND_ASYNC|SND_NODEFAULT );
	//PlaySound(MAKEINTRESOURCE(IDR_WAVE1),AfxGetResourceHandle(),SND_ASYNC|SND_RESOURCE|SND_NODEFAULT|SND_LOOP);//�������ļ�д�뵽������
	//	sndPlaySound ("../�����ı�����/�ֺ�-������.wma",SND_ASYNC);
}


void CWplayView::OnEasy() 
{
	// TODO: Add your command handler code here
	OnStart();
	startflag=1;
	MessageBox("����ģʽ�ѿ���");
}

