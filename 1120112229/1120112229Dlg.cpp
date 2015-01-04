

// 1120112229Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "1120112229.h"
#include "1120112229Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy1120112186Dlg 对话框



CMy1120112229Dlg::CMy1120112229Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy1120112229Dlg::IDD, pParent)
	, m_strEditRXDataDisp(_T(""))
	, m_strEditTXDataInput(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bSerialPortOpened=FALSE;
}

void CMy1120112229Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_PORTNO, m_ctrlComboPortNO);
	DDX_Text(pDX, IDC_EDIT_RXDATADISP, m_strEditRXDataDisp);
	DDX_Text(pDX, IDC_EDIT_TXDATAINPUT, m_strEditTXDataInput);
}

BEGIN_MESSAGE_MAP(CMy1120112229Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OPENPORT, &CMy1120112229Dlg::OnBnClickedButtonOpenport)
	ON_BN_CLICKED(IDC_BUTTON_CLOSEPORT, &CMy1120112229Dlg::OnBnClickedButtonCloseport)
	ON_BN_CLICKED(IDC_BUTTON_SENDDATA, &CMy1120112229Dlg::OnBnClickedButtonSenddata)
	ON_MESSAGE(ON_COM_RECEIVE, OnReceive)
	ON_CBN_SELCHANGE(IDC_COMBO_PORTNO, &CMy1120112229Dlg::OnCbnSelchangeComboPortno)
END_MESSAGE_MAP()


// CMy1120112186Dlg 消息处理程序

BOOL CMy1120112229Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_ctrlComboPortNO.SetCurSel(0);
	GetDlgItem(IDC_BUTTON_OPENPORT)->EnableWindow(!m_bSerialPortOpened);
	GetDlgItem(IDC_BUTTON_CLOSEPORT)->EnableWindow(m_bSerialPortOpened);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy1120112229Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy1120112229Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy1120112229Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy1120112229Dlg::OnBnClickedButtonOpenport()
{
	// TODO: 在此添加控件通知处理程序代码
	int nPortNo = m_ctrlComboPortNO.GetCurSel()+1;
	m_CnComm.Open(nPortNo);
	if(m_CnComm.IsOpen())
	{
		AfxMessageBox(_T("串口已经成功打开"));
		m_CnComm.SetWnd(this->m_hWnd);
		m_bSerialPortOpened=TRUE;
	}
	else
	{
		AfxMessageBox(_T("串口打开失败"));
		m_bSerialPortOpened=false;
	}
	GetDlgItem(IDC_BUTTON_OPENPORT)->EnableWindow(!m_bSerialPortOpened);
	GetDlgItem(IDC_BUTTON_CLOSEPORT)->EnableWindow(m_bSerialPortOpened);

}


void CMy1120112229Dlg::OnBnClickedButtonCloseport()
{
	// TODO: 在此添加控件通知处理程序代码
	m_CnComm.Close();
	m_bSerialPortOpened=FALSE;
	GetDlgItem(IDC_BUTTON_OPENPORT)->EnableWindow(!m_bSerialPortOpened);
	GetDlgItem(IDC_BUTTON_CLOSEPORT)->EnableWindow(m_bSerialPortOpened);
}


void CMy1120112229Dlg::OnBnClickedButtonSenddata()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!m_bSerialPortOpened)
	{
		AfxMessageBox(_T("请先打开串口"));
		return;
	}
	UpdateData(TRUE);
	//AfxMessageBox(m_strEditTXDataInput);
	CStringA strTemp;
	strTemp = m_strEditTXDataInput; //UniCode字符串与ANSI字符串之间的转换
	m_CnComm.Write(strTemp);
	UpdateData(FALSE);
}
LRESULT CMy1120112229Dlg::OnReceive(WPARAM port, LPARAM ch)
{
	char str[100];
	m_CnComm.ReadString(str, 100);
	m_strEditRXDataDisp += str;
	UpdateData(false);
	return 0;
}

void CMy1120112229Dlg::OnCbnSelchangeComboPortno()
{
	// TODO: 在此添加控件通知处理程序代码
}
