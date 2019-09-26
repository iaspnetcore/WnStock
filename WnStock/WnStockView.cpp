
// WnStockView.cpp: CWnStockView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "WnStock.h"
#endif

#include "WnStockDoc.h"
#include "WnStockView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWnStockView

IMPLEMENT_DYNCREATE(CWnStockView, CView)

BEGIN_MESSAGE_MAP(CWnStockView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CWnStockView 构造/析构

CWnStockView::CWnStockView() noexcept
{
	// TODO: 在此处添加构造代码

}

CWnStockView::~CWnStockView()
{
}

BOOL CWnStockView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWnStockView 绘图

void CWnStockView::OnDraw(CDC* pDC)
{
	CWnStockDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	DrowMyStockUI(pDC);

	// TODO: 在此处为本机数据添加绘制代码
}


// CWnStockView 打印

BOOL CWnStockView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CWnStockView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CWnStockView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CWnStockView 诊断

#ifdef _DEBUG
void CWnStockView::AssertValid() const
{
	CView::AssertValid();
}

void CWnStockView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWnStockDoc* CWnStockView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWnStockDoc)));
	return (CWnStockDoc*)m_pDocument;
}
#endif //_DEBUG


// CWnStockView 消息处理程序

void CWnStockView::DrowMyStockUI(CDC* pDC)
{
	CWnStockDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//设置背景颜色
	CRect rect;
	GetClientRect(&rect);
	CSize totalSize = 32;
	if (rect.bottom <= totalSize.cy)
	{
		rect.bottom = totalSize.cy;
	}

	//pDC->SetBkMode(TRANSPARENT);   //透明
	////pDC->SetBkMode(OPAQUE);
	//pDC->SetBkColor(RGB(0, 0, 0));
	//pDC->SelectStockObject(BLACK_BRUSH);
	//pDC->Rectangle(&rect);

	//添加修改选中股的底色
	CRect rect1;
	rect1.left = rect.left;
	rect1.right = rect.right;
	rect1.top = rect.top + 30 + 20 * (m_selectLine - 1);
	rect1.bottom = rect.top + 30 + 20 * m_selectLine;
	pDC->SetBkColor(RGB(255, 255, 0));
	pDC->SelectStockObject(GRAY_BRUSH);
	pDC->Rectangle(&rect1);

	GetClientRect(&rect);

	//获得数据
	CString strLine;
	//m_totalNum = pDoc->vMystock.size();
	m_totalNum = 32;

	m_width = 90;
	m_height = 20;

	//CString strLine;

	//pDC->SetTextColor(RGB(200, 200, 200));

	/*strLine.Format("编号");
	pDC->TextOut(m_width / 8, 0 + m_posY, strLine);
	strLine.Format("代码");
	pDC->TextOut(m_width / 8 + m_width, 0 + m_posY, strLine);
	strLine.Format("名称");
	pDC->TextOut(m_width / 8 + 2 * m_width, 0 + m_posY, strLine);
	strLine.Format("涨幅");
	

	pDC->TextOut(m_width / 8 + 3 * m_width, 0 + m_posY, strLine);
	strLine.Format("现价");
	pDC->TextOut(m_width / 8 + 4 * m_width, 0 + m_posY, strLine);
	strLine.Format("涨跌");
	pDC->TextOut(m_width / 8 + 5 * m_width, 0 + m_posY, strLine);
	strLine.Format("开盘价");
	pDC->TextOut(m_width / 8 + 6 * m_width, 0 + m_posY, strLine);
	strLine.Format("最高价");
	pDC->TextOut(m_width / 8 + 7 * m_width, 0 + m_posY, strLine);
	strLine.Format("最低价");
	pDC->TextOut(m_width / 8 + 8 * m_width, 0 + m_posY, strLine);
	strLine.Format("成交量");
	pDC->TextOut(m_width / 8 + 9 * m_width, 0 + m_posY, strLine);*/
	strLine.Format("成交额");
	pDC->TextOut(m_width / 8 + 10 * m_width, 0 + m_posY, strLine);
	
	CClientDC dc(this);
	
	// dc.TextOut(0, 0, _T("这是一个MFC程序!"));
	//dc.TextOutW(8 + 10 , 0 , _T("成交额"));

	




	
	return;
}