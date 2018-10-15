
// One_minute_adderDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// COne_minute_adderDlg 대화 상자
class COne_minute_adderDlg : public CDialogEx
{
	//추가
private:
	char m_operater_flag = 0; //plus:0/minus:1/mut:2/divi:3
	char m_step = 0; // 연산자 확인변수
	int m_count = 0; // 연산자 카운트변수
	double m_value = 0; //숫자값을 저장하기위한 변수
	double m_flant = 0; //숫자를 임시 저장하기 위한 변수 (%연산)
public:
	void M_Operate(double m_value_two); //사칙연산 추가함수
// 생성입니다.
public:
	COne_minute_adderDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ONE_MINUTE_ADDER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnBnClickedPlus();
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedMult();
	afx_msg void OnBnClickedDivi();
	afx_msg void OnBnClickedEqual();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedComma();
	afx_msg void OnBnClickedBackspace();
	afx_msg void OnBnClickedAllClear();
	afx_msg void OnBnClickedSqrt();
	afx_msg void OnBnClickedZegop();
	afx_msg void OnBnClickedBoonsoo();
	afx_msg void OnBnClickedPm();
	afx_msg void OnBnClickedPercent();
	afx_msg void OnManuAnengineeringcalculator();
};
