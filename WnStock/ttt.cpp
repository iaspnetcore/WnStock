// ttt.cpp: 实现文件
//

#include "pch.h"
#include "WnStock.h"
#include "ttt.h"
#include "afxdialogex.h"


// ttt 对话框

IMPLEMENT_DYNAMIC(ttt, CDialog)

ttt::ttt(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_ttt, pParent)
{

}

ttt::~ttt()
{
}

void ttt::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ttt, CDialog)
END_MESSAGE_MAP()


// ttt 消息处理程序
