
// 11201122229Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "CnComm.h"

// CMy1120112186Dlg �Ի���
class CMy1120112229Dlg : public CDialogEx
{
// ����
public:
	CMy1120112229Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY1120112229_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
