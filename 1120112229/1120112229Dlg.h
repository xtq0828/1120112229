
// 11201122229Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "CnComm.h"

// CMy1120112186Dlg 对话框
class CMy1120112229Dlg : public CDialogEx
{
// 构造
public:
	CMy1120112229Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY1120112229_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	LRESULT OnReceive(WPARAM port, LPARAM ch);
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_ctrlComboPortNO;
	CString m_strEditRXDataDisp;
	CString m_strEditTXDataInput;
	CnComm m_CnComm; 
	BOOL m_bSerialPortOpened;
	afx_msg void OnBnClickedButtonOpenport();
	afx_msg void OnBnClickedButtonCloseport();
	afx_msg void OnBnClickedButtonSenddata();
	afx_msg void OnCbnSelchangeComboPortno();
};
