
// WnStockView.h: CWnStockView 类的接口
//

#pragma once


class CWnStockView : public CView
{
protected: // 仅从序列化创建
	CWnStockView() noexcept;
	DECLARE_DYNCREATE(CWnStockView)

// 特性
public:
	CWnStockDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CWnStockView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

	/*******************自定义变量*****************************/
public:
	//CRect rect;
	bool		bScroll;		//是否显示滚动条
	CString		m_stockCode;	//当前股票代码
	CString		m_stockName;	//当前股票名称

	//自选股UI所用变量
	int			m_drawStatus;	//0:股票展示，1:画分时线，2:画K线
	int			m_selectLine;   //表示自选股中当前选中的行
	int			m_mouseLine;	//表示自选股中鼠标所在的行
	int			m_totalNum;		//My Stock的数量
	int			m_width;		//自选股区每一行显示数据的增量
	int			m_height;		//自选股区每一列显示数据的增量
	int			m_posY;			//滚动条下滑距离顶部高度，固定自选界面首行使用

	/******************自定义函数******************************/
protected:
	//自选股UI所用函数
	void		DrowMyStockUI(CDC* pDc);			//画自选股部分
};

#ifndef _DEBUG  // WnStockView.cpp 中的调试版本
inline CWnStockDoc* CWnStockView::GetDocument() const
   { return reinterpret_cast<CWnStockDoc*>(m_pDocument); }
#endif

