#pragma once


// ttt 对话框

class ttt : public CDialog
{
	DECLARE_DYNAMIC(ttt)

public:
	ttt(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ttt();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ttt };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_listMenu;
};
