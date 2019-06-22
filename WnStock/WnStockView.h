
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
};

#ifndef _DEBUG  // WnStockView.cpp 中的调试版本
inline CWnStockDoc* CWnStockView::GetDocument() const
   { return reinterpret_cast<CWnStockDoc*>(m_pDocument); }
#endif

