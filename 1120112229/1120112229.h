
// 1120112229.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy1120112229App:
// �йش����ʵ�֣������ 1120112229.cpp
//

class CMy1120112229App : public CWinApp
{
public:
	CMy1120112229App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy1120112229App theApp;