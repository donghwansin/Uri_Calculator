
// One_minute_adderDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// COne_minute_adderDlg ��ȭ ����
class COne_minute_adderDlg : public CDialogEx
{
	//�߰�
private:
	char m_operater_flag = 0; //plus:0/minus:1/mut:2/divi:3
	char m_step = 0; // ������ Ȯ�κ���
	int m_count = 0; // ������ ī��Ʈ����
	double m_value = 0; //���ڰ��� �����ϱ����� ����
	double m_flant = 0; //���ڸ� �ӽ� �����ϱ� ���� ���� (%����)
public:
	void M_Operate(double m_value_two); //��Ģ���� �߰��Լ�
// �����Դϴ�.
public:
	COne_minute_adderDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ONE_MINUTE_ADDER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
