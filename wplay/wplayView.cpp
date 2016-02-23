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
	
	//载入普通棋子位图
	m_bmwhite.LoadBitmap(IDB_BITMAP4);//白棋  调入位图资源~~~~~~~~~~~~~~~~~~~~~~~~~~~啦,此处一定要放在构造函数里面，比较重要
	m_bmblack.LoadBitmap(IDB_BITMAP3);//黑棋
	
	//第一个棋子！！！！！	
	m_bmwhiteh.LoadBitmap(IDB_BITMAP7);//白棋  调入位图资源~~~~~~~~~~~~~~~~~~~~~~~~~~~啦,此处一定要放在构造函数里面，比较重要
	m_bmblackh.LoadBitmap(IDB_BITMAP8);//黑棋
	
	//清理棋盘
	//数组值为 0 表示没有棋子
	for(int i=0;i<19;i++)
		for(int j=0;j<19;j++)
			qz[i][j]=0;
		//白棋先下
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
	//画背景
	CBrush m_brushBackground;
	CBitmap bmp;   
	bmp.LoadBitmap(IDB_BITMAP6); //加载棋盘位图    
	m_brushBackground.CreatePatternBrush(&bmp); //创建位图画刷	
	CRect rect;  
	GetClientRect(rect);//取得客户区域     
	pDC->FillRect(rect,&m_brushBackground); //用背景画刷填充区域
	
											/*---原手工画图棋盘------------------------
											CBrush mybrush1;
											mybrush1.CreateSolidBrush(RGB(192,192,192));	
											CRect myrect1(0,0,1200,800);
											pDC->FillRect(myrect1,&mybrush1);
											//画棋盘框线
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
	
	/*	（人人对战模式，且棋子为resource中画出来的，原）
	CDC Dc;
	CDC* pDC;
	CWplayDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	m_bmwhite.LoadBitmap(IDB_BITMAP1);//调入位图资源~~~~~~~~~~~~~~~~~~~~~~~~~~~啦啦啦啦
	m_bmblack.LoadBitmap(IDB_BITMAP2);
	
	  
		if(point.x>30&&point.x<410&&point.y>30&&point.y<410)
		{
		int px=(point.x-30)/20;
		int py=(point.y-30)/20;
		//是否已经有棋子
		if(colorwhite&&qz[px][py]==0)
		{
		//	Dc.SelectObject(m_bmwhite);
		//	pDC->BitBlt(px*20+32,py*20+32,160,160,&Dc,0,0,SRCCOPY);
		//表示存在白棋
		qz[px][py]=1;
		//检查是否结束
		//			over(point);
		//换黑棋下
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
	
	
	
	//更改后的--------------------------------------------------------
	if(startflag==1)
	{
		CDC *pDC=GetDC();
		CDC Dc;
		if(Dc.CreateCompatibleDC(pDC)==FALSE)
			AfxMessageBox("Can't create DC");
		//显示棋子
		
		//重画棋子！！！！！！！！！（每次视图的更新，使每一次第一个的特殊棋子实现自动更改）		
		for(int n=0;n<19;n++)
			for(int m=0;m<19;m++)
				if(qz[n][m]==1)
				{
					//显示白棋
					Dc.SelectObject(m_bmwhite);
					pDC->BitBlt(n*20+32,m*20+32,160,160,&Dc,0,0,SRCCOPY);	
				}
				else if(qz[n][m]==-1)
				{
					//显示黑棋
					Dc.SelectObject(m_bmblack);
					pDC->BitBlt(n*20+32,m*20+32,160,160,&Dc,0,0,SRCCOPY);	
				}
				
				//人人简单模式
				
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
	/*---------------实现类视图在内存中的暂时保存-------------
	ReleaseCapture();//取消鼠标捕获
	m_bLButtonDown=false;//标志复原
	
	  CClientDC dc(this);//建立DC
	  
		if(!m_dcCompatible.m_hDC)//若兼容DC未建立,则建立之  
		{  
		m_dcCompatible.CreateCompatibleDC(&dc);  
		}
		
		  //将视图区保存为位图
		  CRect rect; 
		  GetClientRect(&rect);  
		  CBitmap bitmap;  
		  bitmap.CreateCompatibleBitmap(&dc,rect.Width(),rect.Height());  
		  
			//兼容DC与位图产生关联
			m_dcCompatible.SelectObject(&bitmap); 
			
			  //将设备描述表复制到兼容DC中
			  m_dcCompatible.BitBlt(0,0,rect.Width(),rect.Height(),&dc,0,0,SRCCOPY);   
	*/
	CView::OnLButtonUp(nFlags, point);
}

void CWplayView::over(CPoint point)
{
	
	//获取当前及最新一次的鼠标指向数组位置，以判断游戏是否结束
	int x=(point.x-30)/20;
	int y=(point.y-30)/20;
	//计算开始判断的坐标 xx,yy
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
	//横向判断

	for(i=0;i<8;i++)
	{
		a=0;
		for(j=xx+i;j<xx+i+5&&j<19;j++)
		{
			a=a+qz[j][y];
			//五个都是白棋
				if(a==5)
				{
					MessageBox("白棋胜!");//此处有BUG，。。。。(已修改)
					//重新开始
					OnStart();
					return;
				}
				//五个都是黑棋
				if(a==-5)
				{
					MessageBox("黑棋胜!");
					OnStart();
					return;
				}
		}
	}
	//竖向判断
	for(i=0;i<8;i++)
	{
		a=0;
		for(j=yy+i;j<yy+i+5&&j<19;j++)
		{
			a=a+qz[x][j];
			//五个都是白棋
			if(a==5)
			{
				MessageBox("白棋胜!");
				//重新开始
				OnStart();
				return;
			}
			//五个都是黑棋
			if(a==-5)
			{
				MessageBox("黑棋胜!");
				OnStart();
				return;
			}		
		}
	}
	//斜着的判断与横竖不一样，效率稍微低一些，但保证不会溢出计算到野值
	//向右下角
	int min;//比较得到最左上角的位置
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
					MessageBox("白棋胜!");
					OnStart();
					return;
				}
				if(a==-5)
				{
					MessageBox("黑棋胜!");
					OnStart();
					return;
				}
			}
			//到了边界
			else
				over=1;
		}
		xx+=1;
		yy+=1;
	}while(over==0);
	
	//向左下角
	int min2;//比较得到最右上角的位置
	if(18-x<y) min2=18-x;//18-x为横着到最右边的距离，如（0，17）
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
					AfxMessageBox("白棋胜!");//此处左下有一BUG，请注意修改！！！（已修改）
					OnStart();
					return;
				}
				if(a==-5)
				{
					AfxMessageBox("黑棋胜!");
					OnStart();
					return;
				}
			}
			//到了边界
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
			qz[i][j]=0;         //棋盘初始化
		colorwhite=true;
		Invalidate(false);	
}




void CWplayView::OnEditCut() //打开背景音乐，没有实现，因此也没实现下棋的音效
{
	// TODO: Add your command handler code here
	//	MessageBox("hello");
	//	ShellExecute(NULL, _T("open"), _T("C:\\wwhelp.txt"), NULL, NULL, SW_SHOW);//-----------------------相对路径的设置方法
	PlaySound("C:\\test.wma",NULL,SND_FILENAME | SND_ASYNC);
	//	PlaySound("C:\\test.wma",NULL, SND_ASYNC|SND_NODEFAULT );
	//PlaySound(MAKEINTRESOURCE(IDR_WAVE1),AfxGetResourceHandle(),SND_ASYNC|SND_RESOURCE|SND_NODEFAULT|SND_LOOP);//将声音文件写入到程序中
	//	sndPlaySound ("../其他文本内容/林海-琵琶语.wma",SND_ASYNC);
}


void CWplayView::OnEasy() 
{
	// TODO: Add your command handler code here
	OnStart();
	startflag=1;
	MessageBox("人人模式已开启");
}

