
// One_minute_adderDlg.cpp : 구현 파일
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


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// COne_minute_adderDlg 대화 상자

//사칙연산 추가한 함수
void COne_minute_adderDlg::M_Operate(double m_value_two)
{
	switch (m_operater_flag)
	{
	case 0: //더하기
		m_value += m_value_two;
		break;
	case 1: //뺴기
		m_value -= m_value_two;
		break;
	case 2: //곱하기
		m_value *= m_value_two;
		break;
	case 3: //나누기
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


// COne_minute_adderDlg 메시지 처리기

BOOL COne_minute_adderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void COne_minute_adderDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR COne_minute_adderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL COne_minute_adderDlg::OnCommand(WPARAM wParam, LPARAM lParam) //매크로 id값을 이용하기 위한 함수
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (B_Number0 <= wParam&&wParam <= B_Number9) //솔루션탐색기 → Resource.h → 숫자버튼 매크로 확인
	{
		CString str, number_str, str2; //문자열
		number_str.Format(L"%d", wParam - B_Number0); //숫자'0'을 기준으로 잡는다

		if (m_step == 0) //연산자가 눌리지 않았을경우
		{
			GetDlgItemText(Print_Edit, str2); //에디트에 입력된값을 str변수에 저장
		}
		else if (m_step == 1) //연산자가 눌렸을 경우
		{
			GetDlgItemText(Print_Edit, str);
			m_step = 0;
			m_value = _wtof(str);
		}
		SetDlgItemText(Print_Edit, str2 + number_str); //str에 저장된 값에 숫자값을 더해 출력
	}
	m_flant = m_value;
	return CDialogEx::OnCommand(wParam, lParam);
}


void COne_minute_adderDlg::OnBnClickedPlus() //더하기
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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


void COne_minute_adderDlg::OnBnClickedMinus() //빼기
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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


void COne_minute_adderDlg::OnBnClickedMult() //곱하기
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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


void COne_minute_adderDlg::OnBnClickedDivi() //나누기
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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


void COne_minute_adderDlg::OnBnClickedEqual() //이꼴
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	//SetDlgItemInt(Print_Edit, m_value);//연산된 값을 화면에 출력
}


void COne_minute_adderDlg::OnBnClickedClear() //클리어버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetDlgItemText(Print_Edit, L"");

	CString str;
	GetDlgItemText(Print_Edit, str);
	str.Delete(str.GetLength() - 1, 1);
	SetDlgItemText(Print_Edit, str);
}


void COne_minute_adderDlg::OnBnClickedComma() //소수점
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(Print_Edit, str);
	SetDlgItemText(Print_Edit, str + '.');
}


void COne_minute_adderDlg::OnBnClickedBackspace() //백스페이스
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(Print_Edit, str);
	str.Delete(str.GetLength() - 1, 1);
	SetDlgItemText(Print_Edit, str);
}


void COne_minute_adderDlg::OnBnClickedAllClear() //전체 클리어
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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


void COne_minute_adderDlg::OnBnClickedSqrt() //루트
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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


void COne_minute_adderDlg::OnBnClickedZegop() //제곱
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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


void COne_minute_adderDlg::OnBnClickedBoonsoo() //분수
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
