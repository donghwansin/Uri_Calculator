
// One_minute_adder.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// COne_minute_adderApp:
// �� Ŭ������ ������ ���ؼ��� One_minute_adder.cpp�� �����Ͻʽÿ�.
//

class COne_minute_adderApp : public CWinApp
{
public:
	COne_minute_adderApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern COne_minute_adderApp theApp;