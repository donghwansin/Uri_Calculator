
// One_minute_adderDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "One_minute_adder.h"
#include "One_minute_adderDlg.h"
#include "afxdialogex.h"
#include <math.h>
#include "An_engineering_calculator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COne_minute_adderDlg ��ȭ ����

//��Ģ���� �߰��� �Լ�
void COne_minute_adderDlg::M_Operate(double m_value_two)
{
	switch (m_operater_flag)
	{
	case 0: //���ϱ�
		m_value += m_value_two;
		break;
	case 1: //����
		m_value -= m_value_two;
		break;
	case 2: //���ϱ�
		m_value *= m_value_two;
		break;
	case 3: //������
		if (m_value_two != 0)
		{
			m_value /= m_value_two;
		}
		else
		{
			m_value = 0;
		}
		break;
	}
}

COne_minute_adderDlg::COne_minute_adderDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ONE_MINUTE_ADDER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COne_minute_adderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COne_minute_adderDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(B_Plus, &COne_minute_adderDlg::OnBnClickedPlus)
	ON_BN_CLICKED(B_Minus, &COne_minute_adderDlg::OnBnClickedMinus)
	ON_BN_CLICKED(B_Mult, &COne_minute_adderDlg::OnBnClickedMult)
	ON_BN_CLICKED(B_Divi, &COne_minute_adderDlg::OnBnClickedDivi)
	ON_BN_CLICKED(B_Equal, &COne_minute_adderDlg::OnBnClickedEqual)
	ON_BN_CLICKED(B_Clear, &COne_minute_adderDlg::OnBnClickedClear)
	ON_BN_CLICKED(B_Comma, &COne_minute_adderDlg::OnBnClickedComma)
	ON_BN_CLICKED(B_Backspace, &COne_minute_adderDlg::OnBnClickedBackspace)
	ON_BN_CLICKED(B_All_Clear, &COne_minute_adderDlg::OnBnClickedAllClear)
	ON_BN_CLICKED(B_Sqrt, &COne_minute_adderDlg::OnBnClickedSqrt)
	ON_BN_CLICKED(B_Zegop, &COne_minute_adderDlg::OnBnClickedZegop)
	ON_BN_CLICKED(B_Boonsoo, &COne_minute_adderDlg::OnBnClickedBoonsoo)
	ON_BN_CLICKED(B_PM, &COne_minute_adderDlg::OnBnClickedPm)
	ON_BN_CLICKED(B_Percent, &COne_minute_adderDlg::OnBnClickedPercent)
	ON_COMMAND(ID_MANU_ANENGINEERINGCALCULATOR, &COne_minute_adderDlg::OnManuAnengineeringcalculator)
END_MESSAGE_MAP()


// COne_minute_adderDlg �޽��� ó����

BOOL COne_minute_adderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void COne_minute_adderDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void COne_minute_adderDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR COne_minute_adderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL COne_minute_adderDlg::OnCommand(WPARAM wParam, LPARAM lParam) //��ũ�� id���� �̿��ϱ� ���� �Լ�
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (B_Number0 <= wParam&&wParam <= B_Number9) //�ַ��Ž���� �� Resource.h �� ���ڹ�ư ��ũ�� Ȯ��
	{
		CString str, number_str, str2; //���ڿ�
		number_str.Format(L"%d", wParam - B_Number0); //����'0'�� �������� ��´�

		if (m_step == 0) //�����ڰ� ������ �ʾ������
		{
			GetDlgItemText(Print_Edit, str2); //����Ʈ�� �ԷµȰ��� str������ ����
		}
		else if (m_step == 1) //�����ڰ� ������ ���
		{
			GetDlgItemText(Print_Edit, str);
			m_step = 0;
			m_value = _wtof(str);
		}
		SetDlgItemText(Print_Edit, str2 + number_str); //str�� ����� ���� ���ڰ��� ���� ���
	}
	m_flant = m_value;
	return CDialogEx::OnCommand(wParam, lParam);
}


void COne_minute_adderDlg::OnBnClickedPlus() //���ϱ�
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str, str2, omg;

	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	m_count++;
	if (m_count == 1)
	{
		m_value = m_value_two;
	}
	else
	{
		M_Operate(m_value_two);
	}

	m_operater_flag = 0;
	m_step = 1;

	GetDlgItemText(Print_Edit, str2);
	GetDlgItemText(Print_Edit2, str);
	SetDlgItemText(Print_Edit2, str + str2 + '+');

	omg.Format(L"%f", m_value);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");
	SetDlgItemText(Print_Edit, omg);
}


void COne_minute_adderDlg::OnBnClickedMinus() //����
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str, str2, omg;
	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	m_count++;
	if (m_count == 1)
	{
		m_value = m_value_two;
	}
	else
	{
		M_Operate(m_value_two);
	}

	m_operater_flag = 1;
	m_step = 1;

	GetDlgItemText(Print_Edit, str2);
	GetDlgItemText(Print_Edit2, str);
	SetDlgItemText(Print_Edit2, str + str2 + '-');

	omg.Format(L"%f", m_value);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");
	SetDlgItemText(Print_Edit, omg);
}


void COne_minute_adderDlg::OnBnClickedMult() //���ϱ�
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str, str2, omg;
	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	m_count++;
	if (m_count == 1)
	{
		m_value = m_value_two;
	}
	else
	{
		M_Operate(m_value_two);
	}

	m_operater_flag = 2;
	m_step = 1;

	GetDlgItemText(Print_Edit, str2);
	GetDlgItemText(Print_Edit2, str);
	SetDlgItemText(Print_Edit2, str + str2 + '*');

	omg.Format(L"%f", m_value);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");
	SetDlgItemText(Print_Edit, omg);
}


void COne_minute_adderDlg::OnBnClickedDivi() //������
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str, str2, omg;
	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	m_count++;
	if (m_count == 1)
	{
		m_value = m_value_two;
	}
	else
	{
		M_Operate(m_value_two);
	}

	m_operater_flag = 3;
	m_step = 1;

	GetDlgItemText(Print_Edit, str2);
	GetDlgItemText(Print_Edit2, str);
	SetDlgItemText(Print_Edit2, str + str2 + '/');

	omg.Format(L"%f", m_value);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");
	SetDlgItemText(Print_Edit, omg);
}


void COne_minute_adderDlg::OnBnClickedEqual() //�̲�
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, str);
	m_value_two = _wtof(str);

	CEdit* pEdit2 = (CEdit*)GetDlgItem(Print_Edit2);
	pEdit2->SetWindowTextW(L"");

	M_Operate(m_value_two);

	m_count = 0;

	str.Format(L"%f", m_value);
	str.TrimRight(L"0");
	str.TrimRight(L".");
	SetDlgItemText(Print_Edit, str);
	//SetDlgItemInt(Print_Edit, m_value);//����� ���� ȭ�鿡 ���
}


void COne_minute_adderDlg::OnBnClickedClear() //Ŭ�����ư
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetDlgItemText(Print_Edit, L"");

	CString str;
	GetDlgItemText(Print_Edit, str);
	str.Delete(str.GetLength() - 1, 1);
	SetDlgItemText(Print_Edit, str);
}


void COne_minute_adderDlg::OnBnClickedComma() //�Ҽ���
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	GetDlgItemText(Print_Edit, str);
	SetDlgItemText(Print_Edit, str + '.');
}


void COne_minute_adderDlg::OnBnClickedBackspace() //�齺���̽�
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	GetDlgItemText(Print_Edit, str);
	str.Delete(str.GetLength() - 1, 1);
	SetDlgItemText(Print_Edit, str);
}


void COne_minute_adderDlg::OnBnClickedAllClear() //��ü Ŭ����
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CEdit* pEdit = (CEdit*)GetDlgItem(Print_Edit);
	pEdit->SetWindowTextW(L"");

	CEdit* pEdit2 = (CEdit*)GetDlgItem(Print_Edit2);
	pEdit2->SetWindowTextW(L"");

	m_value = 0;
	m_step = 0;
	m_operater_flag = 0;
	m_count = 0;

	UpdateData(FALSE);
}


void COne_minute_adderDlg::OnBnClickedSqrt() //��Ʈ
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CString omg;
	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	omg.Format(L"%f", sqrt(m_value_two));
	omg.TrimRight(L"0");
	omg.TrimRight(L".");

	SetDlgItemText(Print_Edit, omg);

	UpdateData(FALSE);
}


void COne_minute_adderDlg::OnBnClickedZegop() //����
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CString omg;
	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	omg.Format(L"%f", m_value_two * m_value_two);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");

	SetDlgItemText(Print_Edit, omg);

	UpdateData(FALSE);
}


void COne_minute_adderDlg::OnBnClickedBoonsoo() //�м�
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CString omg;
	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	omg.Format(L"%f", 1 / m_value_two);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");

	SetDlgItemText(Print_Edit, omg);

	UpdateData(FALSE);
}


void COne_minute_adderDlg::OnBnClickedPm()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CString omg;
	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);


	omg.Format(L"%f", -1 * m_value_two);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");

	SetDlgItemText(Print_Edit, omg);

	UpdateData(FALSE);
}


void COne_minute_adderDlg::OnBnClickedPercent()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CString omg;
	double m_value_two = GetDlgItemInt(Print_Edit);
	double m_flant2;
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	m_flant2 = m_flant * (m_value_two / 100.0);
	omg.Format(L"%f", m_flant2);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");

	SetDlgItemText(Print_Edit, omg);

	UpdateData(FALSE);
}


void COne_minute_adderDlg::OnManuAnengineeringcalculator()
{
	OnOK();
	An_engineering_calculator dlg;
	dlg.DoModal();
}
