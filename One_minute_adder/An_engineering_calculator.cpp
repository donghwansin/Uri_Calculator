// An_engineering_calculator.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "One_minute_adder.h"
#include "An_engineering_calculator.h"
#include "afxdialogex.h"
#include "One_minute_adderDlg.h"

// An_engineering_calculator 대화 상자입니다.

IMPLEMENT_DYNAMIC(An_engineering_calculator, CDialogEx)

An_engineering_calculator::An_engineering_calculator(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_AN_ENGINEERING_CALCULATOR, pParent)
{
	m_infixExpression = "";
	m_postfixExpression = "";
	m_Number = "";
	m_HistoryText = "";
	m_Output = "";
	m_cstrEmpty = "";

	m_countNumber = false;
	m_toggle = false;
	m_Invalid = false;
	m_mode = false;
	m_operate = false;
	m_kinds = 0;
	m_oldFirstNum = 0;
	m_totalparenthesis = 0;
}

An_engineering_calculator::~An_engineering_calculator()
{
}

void An_engineering_calculator::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_HISTORY, m_HistoryText);
	DDX_Control(pDX, IDC_EDIT_HISTORY, m_EditHistory);
	DDX_Text(pDX, IDC_EDIT_FIRST_PRINT, m_Output);
	DDX_Control(pDX, IDC_EDIT_FIRST_PRINT, m_EditOutput);
}

BEGIN_MESSAGE_MAP(An_engineering_calculator, CDialogEx)
	ON_COMMAND(ID_MANU_ANENGINEERINGCALCULATOR, &An_engineering_calculator::OnManuAnengineeringcalculator)
	ON_BN_CLICKED(IDC_BUTTON_EQURE, &An_engineering_calculator::OnBnClickedButtonEqure)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &An_engineering_calculator::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &An_engineering_calculator::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULTI, &An_engineering_calculator::OnBnClickedButtonMulti)
	ON_BN_CLICKED(IDC_BUTTON_NANUGI, &An_engineering_calculator::OnBnClickedButtonNanugi)
	ON_BN_CLICKED(IDC_BUTTON_LEFT_G, &An_engineering_calculator::OnBnClickedButtonLeftG)
	ON_BN_CLICKED(IDC_BUTTON_RIGTH_G, &An_engineering_calculator::OnBnClickedButtonRigthG)
	ON_BN_CLICKED(IDC_BUTTON_ZERO, &An_engineering_calculator::OnBnClickedButtonZero)
	ON_BN_CLICKED(IDC_BUTTON_ONE, &An_engineering_calculator::OnBnClickedButtonOne)
	ON_BN_CLICKED(IDC_BUTTON_TWO, &An_engineering_calculator::OnBnClickedButtonTwo)
	ON_BN_CLICKED(IDC_BUTTON_THREE, &An_engineering_calculator::OnBnClickedButtonThree)
	ON_BN_CLICKED(IDC_BUTTON_FOUR, &An_engineering_calculator::OnBnClickedButtonFour)
	ON_BN_CLICKED(IDC_BUTTON_FIVE, &An_engineering_calculator::OnBnClickedButtonFive)
	ON_BN_CLICKED(IDC_BUTTON_SIX, &An_engineering_calculator::OnBnClickedButtonSix)
	ON_BN_CLICKED(IDC_BUTTON_SEVEN, &An_engineering_calculator::OnBnClickedButtonSeven)
	ON_BN_CLICKED(IDC_BUTTON_EHIGH, &An_engineering_calculator::OnBnClickedButtonEhigh)
	ON_BN_CLICKED(IDC_BUTTON_NINE, &An_engineering_calculator::OnBnClickedButtonNine)
	ON_BN_CLICKED(IDC_BUTTON_JUM, &An_engineering_calculator::OnBnClickedButtonJum)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &An_engineering_calculator::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_BACK, &An_engineering_calculator::OnBnClickedButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_CE, &An_engineering_calculator::OnBnClickedButtonCe)
	ON_BN_CLICKED(IDC_BUTTON_P_AND_M, &An_engineering_calculator::OnBnClickedButtonPAndM)
	ON_BN_CLICKED(IDC_BUTTON_SQURT, &An_engineering_calculator::OnBnClickedButtonSqurt)
	ON_BN_CLICKED(IDC_BUTTON_FACTORYAL, &An_engineering_calculator::OnBnClickedButtonFactoryal)
	ON_BN_CLICKED(IDC_BUTTON_PAI, &An_engineering_calculator::OnBnClickedButtonPai)
	ON_BN_CLICKED(IDC_BUTTON_ZEGOP, &An_engineering_calculator::OnBnClickedButtonZegop)
	ON_BN_CLICKED(IDC_BUTTON_YZEGOP, &An_engineering_calculator::OnBnClickedButtonYzegop)
	ON_BN_CLICKED(IDC_BUTTON_TEN_X, &An_engineering_calculator::OnBnClickedButtonTenX)
	ON_BN_CLICKED(IDC_BUTTON_SIN, &An_engineering_calculator::OnBnClickedButtonSin)
	ON_BN_CLICKED(IDC_BUTTON_COS, &An_engineering_calculator::OnBnClickedButtonCos)
	ON_BN_CLICKED(IDC_BUTTON_TAN, &An_engineering_calculator::OnBnClickedButtonTan)
	ON_BN_CLICKED(IDC_BUTTON_LOG, &An_engineering_calculator::OnBnClickedButtonLog)
	ON_BN_CLICKED(IDC_BUTTON_EXP, &An_engineering_calculator::OnBnClickedButtonExp)
	ON_BN_CLICKED(IDC_BUTTON_Mod, &An_engineering_calculator::OnBnClickedButtonMod)
	ON_BN_CLICKED(IDC_BUTTON_UP, &An_engineering_calculator::OnBnClickedButtonUp)
END_MESSAGE_MAP()


// An_engineering_calculator 메시지 처리기입니다.
void An_engineering_calculator::OnManuAnengineeringcalculator() //메뉴바
{
	OnOK();
	COne_minute_adderDlg dlg;
	dlg.DoModal();
}

void An_engineering_calculator::InFixExpression(string ntext, bool Number/*1*/) //string 변수에 대입
{
	if (Number) //숫자 클릭, "."클릭
	{
		m_Number += ntext;
		m_operate = true;
		m_Invalid = false;
	}
	else if (ntext == "=" && Number == false) //"="클릭
	{
		m_infixExpression += m_Number;
	}
	else 
	{
		m_infixExpression += (m_Number + ntext);
		m_toggle = false;
		m_Number = "";
	}

	if (m_countNumber)
	{
		TwoOperation();
	}
}

void An_engineering_calculator::TwoOperation()
{
	double number;
	double result = 1;
	string newNumber;

	number = atof(m_Number.c_str());

	switch (m_kinds)
	{
	case X_NSQUARE:
		for (double i = 0; i < number; i++)
		{
			result *= m_oldFirstNum;
		}
		break;

	case MOD:
		//visual studio 에서 제공해주는 %연산자는 실수만 가능
		//math.h 에서 제공해주는 fmod함수를 사용하여 정수도 가능하도록 변경
		result = fmod(m_oldFirstNum, number);
		break;

	case EXP:
		for (double i = 0; i < number; i++)
		{
			m_oldFirstNum *= 10;
		}
		result = m_oldFirstNum;
		break;

	case X_SQUARE_Y:
		result = pow(number, (1.0 / m_oldFirstNum));
		break;

	default:
		break;
	}

	newNumber = to_string(result);
	m_Number.clear();
	m_Number = newNumber;

	m_kinds = KINDS;
	m_countNumber = false;
}

void An_engineering_calculator::PostFixExpression(string infixExpression) //정렬
{
	m_postfixExpression = GetPostFix(infixExpression);
}

double An_engineering_calculator::Result(string postfixExpression) //결과도출
{
	double result;

	result = Calculate(postfixExpression);

	return result;
}

void An_engineering_calculator::OnBnClickedButtonEqure() //"="
{
	double result;
	CString str;
	str = "";

	InFixExpression("=", false);
	EditTextPrint(str, false);

	if (m_totalparenthesis > 0 || m_Invalid)
	{
		MessageBox(m_HistoryText + _T("\nInvalid formula."), _T("Warning"), MB_ICONEXCLAMATION | MB_ICONWARNING);
		btn_Clear();
		return;
	}

	PostFixExpression(m_infixExpression);

	result = Result(m_postfixExpression);
	m_Output.Format(_T("%f"), result);

	SetDlgItemText(IDC_EDIT_FIRST_PRINT, m_Output);

	Clear();
}

void An_engineering_calculator::EditTextPrint(CString ntext, bool Number/*1*/) //버튼 클릭시 EditBoxPrint
{
	if (Number)
	{
		m_HistoryText += "";
		SetDlgItemText(IDC_EDIT_HISTORY, m_HistoryText);
		m_Output += ntext;
		SetDlgItemText(IDC_EDIT_FIRST_PRINT, m_Output);
	}
	else
	{
		m_HistoryText += (m_Output + ntext);
		SetDlgItemText(IDC_EDIT_HISTORY, m_HistoryText);
		m_Output = "";
		SetDlgItemText(IDC_EDIT_FIRST_PRINT, m_Output);
	}
}

void An_engineering_calculator::OnBnClickedButtonPlus() //"+"
{
	if (m_operate == false)
	{
		return;
	}

	CString str;
	str = "+";
	
	InFixExpression((LPSTR)(LPCTSTR)str, false);
	EditTextPrint(str, false);

	m_Invalid = true;
	m_operate = false;
}

void An_engineering_calculator::OnBnClickedButtonMinus() //"-"
{
	if (m_operate == false)
	{
		return;
	}

	CString str;
	str = "-";

	InFixExpression((LPSTR)(LPCTSTR)str, false);
	EditTextPrint(str, false);

	m_Invalid = true;
	m_operate = false;
}

void An_engineering_calculator::OnBnClickedButtonMulti() //"*"
{
	if (m_operate == false)
	{
		return;
	}

	CString str;
	str = "*";

	InFixExpression((LPSTR)(LPCTSTR)str, false);
	EditTextPrint(str, false);

	m_Invalid = true;
	m_operate = false;
}

void An_engineering_calculator::OnBnClickedButtonNanugi() //"/"
{
	if (m_operate == false)
	{
		return;
	}

	CString str;
	str = "/";

	InFixExpression((LPSTR)(LPCTSTR)str, false);
	EditTextPrint(str, false);

	m_Invalid = true;
	m_operate = false;
}

void An_engineering_calculator::OnBnClickedButtonLeftG() //"("
{
	CString str;
	str = "(";

	m_totalparenthesis++;

	InFixExpression((LPSTR)(LPCTSTR)str, false);
	EditTextPrint(str, false);
}

void An_engineering_calculator::OnBnClickedButtonRigthG() //")"
{
	if (m_totalparenthesis <= 0)
	{
		return;
	}

	CString str;
	str = ")";

	m_totalparenthesis--;

	InFixExpression((LPSTR)(LPCTSTR)str, false);
	EditTextPrint(str, false);
}

void An_engineering_calculator::OnBnClickedButtonZero() //0
{
	CString str;
	str = "0";

	InFixExpression((LPSTR)(LPCTSTR)str);
	EditTextPrint(str);
}

void An_engineering_calculator::OnBnClickedButtonOne() //1
{
	CString str;
	str = "1";

	InFixExpression((LPSTR)(LPCTSTR)str);
	EditTextPrint(str);
}

void An_engineering_calculator::OnBnClickedButtonTwo() //2
{
	CString str;
	str = "2";

	InFixExpression((LPSTR)(LPCTSTR)str);
	EditTextPrint(str);
}

void An_engineering_calculator::OnBnClickedButtonThree() //3
{
	CString str;
	str = "3";

	InFixExpression((LPSTR)(LPCTSTR)str);
	EditTextPrint(str);
}

void An_engineering_calculator::OnBnClickedButtonFour() //4
{
	CString str;
	str = "4";

	InFixExpression((LPSTR)(LPCTSTR)str);
	EditTextPrint(str);
}

void An_engineering_calculator::OnBnClickedButtonFive() //5
{
	CString str;
	str = "5";

	InFixExpression((LPSTR)(LPCTSTR)str);
	EditTextPrint(str);
}

void An_engineering_calculator::OnBnClickedButtonSix() //6
{
	CString str;
	str = "6";

	InFixExpression((LPSTR)(LPCTSTR)str);
	EditTextPrint(str);
}

void An_engineering_calculator::OnBnClickedButtonSeven() //7
{
	CString str;
	str = "7";

	InFixExpression((LPSTR)(LPCTSTR)str);
	EditTextPrint(str);
}

void An_engineering_calculator::OnBnClickedButtonEhigh() //8
{
	CString str;
	str = "8";

	InFixExpression((LPSTR)(LPCTSTR)str);
	EditTextPrint(str);
}

void An_engineering_calculator::OnBnClickedButtonNine() //9
{
	CString str;
	str = "9";

	InFixExpression((LPSTR)(LPCTSTR)str);
	EditTextPrint(str);
}

void An_engineering_calculator::OnBnClickedButtonJum() //"."
{
	if (m_Number == m_strEmpty)
	{
		return;
	}

	CString str;
	str = ".";

	InFixExpression((LPSTR)(LPCTSTR)str);
	EditTextPrint(str);
}

void An_engineering_calculator::Clear()
{
	m_Output = "";
	m_HistoryText = "";
	m_infixExpression.clear();
	m_postfixExpression.clear();
	m_Number.clear();

	m_countNumber = false;
	m_toggle = false;
	m_Invalid = false;
	m_operate = false;
	m_kinds = 0;
	m_oldFirstNum = 0;
	m_totalparenthesis = 0;
}

void An_engineering_calculator::btn_Clear()
{
	Clear();
	SetDlgItemText(IDC_EDIT_HISTORY, m_HistoryText);
	SetDlgItemText(IDC_EDIT_FIRST_PRINT, m_Output);
}

void An_engineering_calculator::OnBnClickedButtonClear() //C
{
	btn_Clear();
}

void An_engineering_calculator::OnBnClickedButtonBack() //←
{
	int n_size, output_length; //n_size : string 변수, output_length : CString 변수

	n_size = m_Number.size();
	m_Number.erase(n_size - 1, 1); //문자 삭제

	output_length = m_Output.GetLength();
	m_Output.Delete(output_length - 1, 1); //문자 삭제

	SetDlgItemText(IDC_EDIT_FIRST_PRINT, m_Output);
}

void An_engineering_calculator::OnBnClickedButtonCe() //CE
{
	m_Number.clear();
	m_Output = "";
	SetDlgItemText(IDC_EDIT_FIRST_PRINT, m_Output);
}

void An_engineering_calculator::Calculus(CString str1, CString str2, int kinds)
{
	double number;
	string newNumber;

	m_Number == m_strEmpty ? m_Number = "0" : m_Number;
	number = atof(m_Number.c_str()); //c_str() : string의 멤버함수로써 string -> char*로 변환
									 //atof() : char* -> double로 변환
	//newNumber = to_string(number); //double -> string 변환

	switch (kinds)
	{
	case SQRT:
		newNumber = to_string(sqrt(number));
		break;

	case FACTORIAL:
		newNumber = to_string(Factorial(number));
		break;

	case SQUARE:
		newNumber = to_string(Square(number));
		break;

	case TENSQUARE:
		newNumber = to_string(TenSquare(number));
		break;

	case SIN:
	case ASIN:
		newNumber = to_string(GetSin(number));
		break;

	case COS:
	case ACOS:
		newNumber = to_string(GetCos(number));
		break;

	case TAN:
	case ATAN:
		newNumber = to_string(GetTan(number));
		break;

	case LOG:
	case LN:
		newNumber = to_string(GetLog(number));
		break;

	case FOUNTAIN:
		newNumber = to_string(GetFountain(number));
		break;

	case LOGEXP:
		newNumber = to_string(GetLogEXP(number));
		break;

	case DEGREES:
		newNumber = to_string(GetDegree(number));
		break;

	default:
		break;
	}
	
	m_Number.clear();
	m_Number = newNumber;

	m_Output == m_cstrEmpty ? m_Output = str1 + "0" + str2 : m_Output = str1 + m_Output + str2;
	SetDlgItemText(IDC_EDIT_FIRST_PRINT, m_Output);
}

double An_engineering_calculator::Factorial(double number)
{
	if (number == 1 || number == 0)
	{
		return 1;
	}
	return number * Factorial(number - 1);
}

double An_engineering_calculator::Square(double number)
{
	return number * number;
}

double An_engineering_calculator::TenSquare(double number)
{
	double result = 1;

	for (double i = 0; i < number; i++)
	{
		result *= 10;
	}

	return result;
}

double An_engineering_calculator::GetDegree(double number)
{
	return number * (3.14159265 / 180.0);
}

double An_engineering_calculator::GetRadian(double number)
{
	return number * (180.0 / 3.14159265);
}

double An_engineering_calculator::GetSin(double number)
{
	if (m_mode)
	{
		return GetRadian(asin(number)); // Rad로 표시됨
	}
	else
	{
		return sin(GetDegree(number));;
	}
}

double An_engineering_calculator::GetCos(double number)
{
	if (m_mode)
	{
		return GetRadian(acos(number));
	}
	else
	{
		return cos(GetDegree(number));
	}
}

double An_engineering_calculator::GetTan(double number)
{
	if (m_mode)
	{
		return GetRadian(atan(number));
	}
	else
	{
		return tan(GetDegree(number));
	}
}

double An_engineering_calculator::GetLog(double number)
{
	return m_mode == true ? log(number) : log10(number);
}

double An_engineering_calculator::GetFountain(double number)
{
	return 1.0 / number;
}

double An_engineering_calculator::GetLogEXP(double number)
{
	return exp(number);
}

void An_engineering_calculator::OnBnClickedButtonSqurt() 
{
	if (m_mode) // 1/x
	{
		if (m_Number == m_strEmpty)
		{
			CString str;

			str = "Input is invalid.";
			SetDlgItemText(IDC_EDIT_FIRST_PRINT, str);
			return;
		}

		CString str1, str2;

		str1 = "1/(";
		str2 = ")";

		Calculus(str1, str2, FOUNTAIN);
	}
	else //√
	{
		CString str1, str2;

		str1 = "√(";
		str2 = ")";

		Calculus(str1, str2, SQRT);
	}
}

void An_engineering_calculator::OnBnClickedButtonFactoryal() //n! (자연수만가능)
{
	CString str1, str2;

	str1 = "fact(";
	str2 = ")";

	Calculus(str1, str2, FACTORIAL);
}

void An_engineering_calculator::OnBnClickedButtonPai() //pi
{
	CString str1;
	str1 = "π";

	InFixExpression("3.14159265");
	EditTextPrint(str1);
}

void An_engineering_calculator::OnBnClickedButtonZegop() //Square(x^2)
{
	CString str1, str2;

	str1 = "(";
	str2 = ")²";

	Calculus(str1, str2, SQUARE);
}

void An_engineering_calculator::OnBnClickedButtonTenX() 
{
	if (m_mode) //e^x
	{
		CString str1, str2;

		str1 = "e^(";
		str2 = ")";

		Calculus(str1, str2, LOGEXP);
	}
	else //10^n
	{
		CString str1, str2;

		str1 = "10^(";
		str2 = ")";

		Calculus(str1, str2, TENSQUARE);
	}
}

void An_engineering_calculator::OnBnClickedButtonSin() 
{
	if (m_mode) //asin
	{
		CString str1, str2;

		str1 = "sin-¹(";
		str2 = ")";

		Calculus(str1, str2, ASIN);
	}
	else //SIN
	{
		CString str1, str2;

		str1 = "sin(";
		str2 = ")";

		Calculus(str1, str2, SIN);
	}
}

void An_engineering_calculator::OnBnClickedButtonCos()
{
	if (m_mode) //acos
	{
		CString str1, str2;

		str1 = "cos-¹(";
		str2 = ")";

		Calculus(str1, str2, ACOS);
	}
	else //COS
	{
		CString str1, str2;

		str1 = "cos(";
		str2 = ")";

		Calculus(str1, str2, COS);
	}
}

void An_engineering_calculator::OnBnClickedButtonTan()
{
	if (m_mode) //atan
	{
		CString str1, str2;

		str1 = "tan-¹(";
		str2 = ")";

		Calculus(str1, str2, ATAN);
	}
	else //TAN
	{
		CString str1, str2;

		str1 = "tan(";
		str2 = ")";

		Calculus(str1, str2, TAN);
	}
}

void An_engineering_calculator::OnBnClickedButtonLog() 
{
	if (m_Number == m_strEmpty)
	{
		CString str;

		str = "Input is invalid.";
		SetDlgItemText(IDC_EDIT_FIRST_PRINT, str);
		return;
	}

	if (m_mode) //ln
	{
		CString str1, str2;

		str1 = "ln(";
		str2 = ")";

		Calculus(str1, str2, LN);
	}
	else //LOG
	{
		CString str1, str2;

		str1 = "Log(";
		str2 = ")";

		Calculus(str1, str2, LOG);
	}
}

void An_engineering_calculator::SetFirstNumber()
{
	m_oldFirstNum = atof(m_Number.c_str()); //c_str() : string의 멤버함수로써 string -> char*로 변환
									 //atof() : char* -> double로 변환
	m_countNumber = true;

	m_Number.clear();
}

void An_engineering_calculator::OnBnClickedButtonYzegop()
{
	if (m_Number == m_strEmpty)
	{
		return;
	}

	if (m_mode) //xsqrtn
	{
		string newNumber;
		CString str;

		str = "yroot";

		SetFirstNumber();
		m_kinds = X_SQUARE_Y;

		m_Output += str;
		SetDlgItemText(IDC_EDIT_FIRST_PRINT, m_Output);
	}
	else //X^n
	{
		string newNumber;
		CString str;

		str = "^";

		SetFirstNumber();
		m_kinds = X_NSQUARE;

		m_Output += str;
		SetDlgItemText(IDC_EDIT_FIRST_PRINT, m_Output);
	}
}

void An_engineering_calculator::OnBnClickedButtonMod()
{
	if (m_Number == m_strEmpty)
	{
		return;
	}

	if (m_mode) //deg Radian 값을 받아 Degree로 표시
	{
		CString str1, str2;

		str1 = "degrees(";
		str2 = ")";

		Calculus(str1, str2, DEGREES);
	}
	else  //MOD
	{
		string newNumber;
		CString str;

		str = "Mod";

		SetFirstNumber();
		m_kinds = MOD;

		m_Output += str;
		SetDlgItemText(IDC_EDIT_FIRST_PRINT, m_Output);
	}
}

void An_engineering_calculator::OnBnClickedButtonExp()
{
	if (m_Number == m_strEmpty)
	{
		return;
	}

	if (m_mode) //dms
	{
		CString str;

		str = "I do not know what function";
		SetDlgItemText(IDC_EDIT_FIRST_PRINT, str);
		Clear();
		return;
	}
	else  //EXP
	{
		string newNumber;
		CString str;

		str = "Exp";

		SetFirstNumber();
		m_kinds = EXP;

		m_Output += str;
		SetDlgItemText(IDC_EDIT_FIRST_PRINT, m_Output);
	}
}

void An_engineering_calculator::OnBnClickedButtonPAndM() //±
{
	if (m_Number == m_strEmpty)
	{
		return;
	}

	CString str1, str2;

	if (m_toggle)
	{
		m_toggle = false;
		str1 = m_cstrEmpty;
		str2 = m_cstrEmpty;
		m_Output = m_oldNumber.c_str();
		m_Number = m_oldNumber;
	}
	else
	{
		m_toggle = true;
		str1 = "(-";
		str2 = ")";
		m_oldNumber = m_Number;
		m_Number = "(0-" + m_oldNumber + ")";
	}

	m_Output = str1 + m_Output + str2;
	SetDlgItemText(IDC_EDIT_FIRST_PRINT, m_Output);
}

void An_engineering_calculator::OnBnClickedButtonUp() //↑
{
	CButton* pBtn;
	m_mode == false ? m_mode = true : m_mode = false;

	if (m_mode)
	{
		pBtn = (CButton*)GetDlgItem(IDC_BUTTON_SQURT);
		pBtn->SetWindowText(_T("1/X"));
		pBtn = (CButton*)GetDlgItem(IDC_BUTTON_TEN_X);
		pBtn->SetWindowText(_T("eⁿ"));
		pBtn = (CButton*)GetDlgItem(IDC_BUTTON_YZEGOP);
		pBtn->SetWindowText(_T("ⁿ√x"));
		pBtn = (CButton*)GetDlgItem(IDC_BUTTON_SIN);
		pBtn->SetWindowText(_T("sin-¹"));
		pBtn = (CButton*)GetDlgItem(IDC_BUTTON_COS);
		pBtn->SetWindowText(_T("cos-¹"));
		pBtn = (CButton*)GetDlgItem(IDC_BUTTON_TAN);
		pBtn->SetWindowText(_T("tan-¹"));
		pBtn = (CButton*)GetDlgItem(IDC_BUTTON_LOG);
		pBtn->SetWindowText(_T("ln"));
		pBtn = (CButton*)GetDlgItem(IDC_BUTTON_EXP);
		pBtn->SetWindowText(_T("dms"));
		pBtn = (CButton*)GetDlgItem(IDC_BUTTON_Mod);
		pBtn->SetWindowText(_T("deg"));
	}
	else
	{
		pBtn = (CButton*)GetDlgItem(IDC_BUTTON_SQURT);
		pBtn->SetWindowText(_T("√"));
		pBtn = (CButton*)GetDlgItem(IDC_BUTTON_TEN_X);
		pBtn->SetWindowText(_T("10ⁿ"));
		pBtn = (CButton*)GetDlgItem(IDC_BUTTON_YZEGOP);
		pBtn->SetWindowText(_T("Xⁿ"));
		pBtn = (CButton*)GetDlgItem(IDC_BUTTON_SIN);
		pBtn->SetWindowText(_T("sin"));
		pBtn = (CButton*)GetDlgItem(IDC_BUTTON_COS);
		pBtn->SetWindowText(_T("cos"));
		pBtn = (CButton*)GetDlgItem(IDC_BUTTON_TAN);
		pBtn->SetWindowText(_T("tan"));
		pBtn = (CButton*)GetDlgItem(IDC_BUTTON_LOG);
		pBtn->SetWindowText(_T("log"));
		pBtn = (CButton*)GetDlgItem(IDC_BUTTON_EXP);
		pBtn->SetWindowText(_T("Exp"));
		pBtn = (CButton*)GetDlgItem(IDC_BUTTON_Mod);
		pBtn->SetWindowText(_T("Mod"));
	}
}