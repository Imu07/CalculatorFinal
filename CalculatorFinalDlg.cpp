
// CalculatorFinalDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CalculatorFinal.h"
#include "CalculatorFinalDlg.h"
#include "afxdialogex.h"
#include <cmath>
#include <vector>
#include <iostream>
#include<string>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CCalculatorFinalDlg dialog



CCalculatorFinalDlg::CCalculatorFinalDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATORFINAL_DIALOG, pParent)
	, m_result(_T("0"))
{
	number1 = number2 = number0 = 0;
	str1 = _T("");
	str2 =_T("");
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorFinalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_result);
	DDX_Control(pDX, IDC_BUTTON2, m_color2);
	DDX_Control(pDX, IDC_BUTTON_EQUALS, m_colorEquals);
	DDX_Control(pDX, IDC_BUTTON_PLUS, m_colorPlus);
	DDX_Control(pDX, IDC_BUTTON_MINUS, m_colorMinus);
	DDX_Control(pDX, IDC_BUTTON_MULTIPLY, m_colorMul);
	DDX_Control(pDX, IDC_BUTTON_DIVISION, m_colorDiv);
	DDX_Control(pDX, IDC_BUTTON1, m_color1);
	DDX_Control(pDX, IDC_BUTTON3, m_color3);
	DDX_Control(pDX, IDC_BUTTON4, m_color4);
	DDX_Control(pDX, IDC_BUTTON5, m_color5);
	DDX_Control(pDX, IDC_BUTTON6, m_color6);
	DDX_Control(pDX, IDC_BUTTON7, m_color7);
	DDX_Control(pDX, IDC_BUTTON8, m_color8);
	DDX_Control(pDX, IDC_BUTTON9, m_color9);
	DDX_Control(pDX, IDC_BUTTON_CE, m_colorCe);
	DDX_Control(pDX, IDC_BUTTON_CLEAR, m_colorC);
	DDX_Control(pDX, IDC_BUTTON_MINPLUS, m_colorPminus);
	DDX_Control(pDX, IDC_BUTTON0, m_color0);
	DDX_Control(pDX, IDC_BUTTON_DECIMAL, m_colorDecimal);
	DDX_Control(pDX, IDC_BUTTON_BACK, m_colorBack);
	DDX_Control(pDX, IDC_BUTTON_PERCENT, m_colorPerc);
	DDX_Control(pDX, IDC_BUTTON_DIVBYX, m_colorDivByx);
	DDX_Control(pDX, IDC_BUTTON_SQRT, m_colorRoot);
	DDX_Control(pDX, IDC_BUTTON_SQUARE, m_colorSquare);
}

BEGIN_MESSAGE_MAP(CCalculatorFinalDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON0, &CCalculatorFinalDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorFinalDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorFinalDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorFinalDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorFinalDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorFinalDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorFinalDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorFinalDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorFinalDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorFinalDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_DECIMAL, &CCalculatorFinalDlg::OnBnClickedButtonDecimal)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalculatorFinalDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCalculatorFinalDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CCalculatorFinalDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_DIVISION, &CCalculatorFinalDlg::OnBnClickedButtonDivision)
	ON_BN_CLICKED(IDC_BUTTON_BACK, &CCalculatorFinalDlg::OnBnClickedButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_EQUALS, &CCalculatorFinalDlg::OnBnClickedButtonEquals)
	ON_BN_CLICKED(IDC_BUTTON_PERCENT, &CCalculatorFinalDlg::OnBnClickedButtonPercent)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CCalculatorFinalDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_CE, &CCalculatorFinalDlg::OnBnClickedButtonCe)
	ON_BN_CLICKED(IDC_BUTTON_DIVBYX, &CCalculatorFinalDlg::OnBnClickedButtonDivbyx)
	
	ON_BN_CLICKED(IDC_BUTTON_SQRT, &CCalculatorFinalDlg::OnBnClickedButtonSqrt)
	ON_BN_CLICKED(IDC_BUTTON_SQUARE, &CCalculatorFinalDlg::OnBnClickedButtonSquare)
	ON_BN_CLICKED(IDC_BUTTON_MINPLUS, &CCalculatorFinalDlg::OnBnClickedButtonMinplus)
	ON_BN_CLICKED(IDC_BUTTON_LOG, &CCalculatorFinalDlg::OnBnClickedButtonLog)
END_MESSAGE_MAP()


// CCalculatorFinalDlg message handlers

BOOL CCalculatorFinalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	CFont SFont;
	SFont.CreateFont(50, 10, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, L"Times New Roman");
	m_color1.SetFont(&SFont);
	m_color0.EnableMenuFont(FALSE);
	m_colorDivByx.SetFaceColor(RGB(255, 165, 0), true);
	m_colorDivByx.SetTextColor(RGB(255, 255, 255));
	m_colorDivByx.EnableWindowsTheming(FALSE);
	m_colorRoot.SetFaceColor(RGB(255, 165, 0), true);
	m_colorRoot.SetTextColor(RGB(255, 255, 255));
	m_colorRoot.EnableWindowsTheming(FALSE);
	m_colorSquare.SetFaceColor(RGB(255, 165, 0), true);
	m_colorSquare.SetTextColor(RGB(255, 255, 255));
	m_colorSquare.EnableWindowsTheming(FALSE);
	m_colorPerc.SetFaceColor(RGB(255, 165, 0), true);
	m_colorPerc.SetTextColor(RGB(255, 255, 255));
	m_colorPerc.EnableWindowsTheming(FALSE);
	m_colorBack.SetFaceColor(RGB(255, 165, 0), true);
	m_colorBack.SetTextColor(RGB(255, 255, 255));
	m_colorBack.EnableWindowsTheming(FALSE);
	m_colorDecimal.EnableWindowsTheming(FALSE);
	m_colorDecimal.SetFaceColor(RGB(128, 128, 128), true);
	m_colorDecimal.SetTextColor(RGB(255, 255, 255));
	m_color0.EnableWindowsTheming(FALSE);
	m_color0.SetFaceColor(RGB(128, 128, 128), true);
	m_color0.SetTextColor(RGB(255, 255, 255));
	m_colorPminus.EnableWindowsTheming(FALSE);
	m_colorPminus.SetFaceColor(RGB(128, 128, 128), true);
	m_colorPminus.SetTextColor(RGB(255, 255, 255));
	m_colorC.EnableWindowsTheming(FALSE);
	m_colorC.SetFaceColor(RGB(255, 255, 240), true);
	m_colorC.SetTextColor(RGB(0, 0, 0));
	m_colorCe.EnableWindowsTheming(FALSE);
	m_colorCe.SetFaceColor(RGB(255, 255, 240), true);
	m_colorCe.SetTextColor(RGB(0,0,0));
	m_color9.EnableWindowsTheming(FALSE);
	m_color9.SetFaceColor(RGB(128, 128, 128), true);
	m_color9.SetTextColor(RGB(255, 255, 255));
	m_color8.EnableWindowsTheming(FALSE);
	m_color8.SetFaceColor(RGB(128, 128, 128), true);
	m_color8.SetTextColor(RGB(255, 255, 255));
	m_color7.EnableWindowsTheming(FALSE);
	m_color7.SetFaceColor(RGB(128, 128, 128), true);
	m_color7.SetTextColor(RGB(255, 255, 255));
	m_color6.EnableWindowsTheming(FALSE);
	m_color6.SetFaceColor(RGB(128, 128, 128), true);
	m_color6.SetTextColor(RGB(255, 255, 255));
	m_color5.EnableWindowsTheming(FALSE);
	m_color5.SetFaceColor(RGB(128, 128, 128), true);
	m_color5.SetTextColor(RGB(255, 255, 255));
	m_color4.EnableWindowsTheming(FALSE);
	m_color4.SetFaceColor(RGB(128, 128, 128), true);
	m_color4.SetTextColor(RGB(255, 255, 255));
	m_color3.EnableWindowsTheming(FALSE);
	m_color3.SetFaceColor(RGB(128, 128, 128), true);
	m_color3.SetTextColor(RGB(255, 255, 255));
	m_color1.EnableWindowsTheming(FALSE);
	m_color1.SetFaceColor(RGB(128, 128, 128), true);
	m_color1.SetTextColor(RGB(255, 255, 255));
	m_colorDiv.EnableWindowsTheming(FALSE);
	m_colorDiv.SetFaceColor(RGB(255, 165, 0), true);
	m_colorDiv.SetTextColor(RGB(255, 255, 255));
	m_colorMul.EnableWindowsTheming(FALSE);
	m_colorMul.SetFaceColor(RGB(255, 165, 0), true);
	m_colorMul.SetTextColor(RGB(255, 255, 255));
	m_colorMinus.EnableWindowsTheming(FALSE);
	m_colorMinus.SetFaceColor(RGB(255, 165, 0), true);
	m_colorMinus.SetTextColor(RGB(255, 255, 255));
	m_colorPlus.SetFaceColor(RGB(255, 165, 0), true);
	m_colorPlus.SetTextColor(RGB(255, 255, 255));
	m_colorPlus.EnableWindowsTheming(FALSE);
	m_colorPlus.SetFaceColor(RGB(255, 165, 0), true);
	m_colorPlus.SetTextColor(RGB(255, 255, 255));
	m_colorEquals.EnableWindowsTheming(FALSE);
	m_colorEquals.SetFaceColor(RGB(255, 165, 0), true);
	m_colorEquals.SetTextColor(RGB(255, 255, 255));
	m_color2.EnableWindowsTheming(FALSE);
	m_color2.SetFaceColor(RGB(128, 128, 128),true);
	m_color2.SetTextColor(RGB(255, 255, 255));
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorFinalDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorFinalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorFinalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorFinalDlg::OnBnClickedButton0()
{
	if (Flag == true) {
		str1 += _T("0");
		updatevalue();
	}
	else {
		str2 += _T("0");
		updatevalue2();
	}
}

void CCalculatorFinalDlg::OnBnClickedButton1()
{
	if (Flag == true) {
		str1 += _T("1");
		updatevalue();
	}
	else {
		str2 += _T("1");
		updatevalue2();
	}
}

void CCalculatorFinalDlg::OnBnClickedButton2()
{
	if (Flag == true) {
		str1 += _T("2");
		m_result = str1;
		UpdateData(FALSE);
	}
	else {
		str2 += _T("2");
		m_result = str2;
		UpdateData(FALSE);
	}
}



void CCalculatorFinalDlg::OnBnClickedButton3()
{
	if (Flag == true) {
		str1 += _T("3");
		updatevalue();
	}
	else {
		str2 += _T("3");
		updatevalue2();
	}
}



void CCalculatorFinalDlg::OnBnClickedButton4()
{
	if (Flag == true){
		str1 += _T("4");
		updatevalue();
	}
	else {
		str2 += _T("4");
		updatevalue2();
	}
	

}


void CCalculatorFinalDlg::OnBnClickedButton5()
{
	if (Flag == true) {
		str1 += _T("5");
		updatevalue();
	}
	else {
		str2 += _T("5");
		updatevalue2();
	}
}


void CCalculatorFinalDlg::OnBnClickedButton6()
{
	if (Flag == true) {
		str1 += _T("6");
		updatevalue();
	}
	else {
		str2 += _T("6");
		updatevalue2();
	}
}


void CCalculatorFinalDlg::OnBnClickedButton7()
{
	if (Flag == true) {
		str1 += _T("7");
		updatevalue();
	}
	else {
		str2 += _T("7");
		updatevalue2();
	}
}


void CCalculatorFinalDlg::OnBnClickedButton8()
{
	if (Flag == true) {
		str1 += _T("8");
		updatevalue();
	}
	else {
		str2 += _T("8");
		updatevalue2();
	}
}


void CCalculatorFinalDlg::OnBnClickedButton9()
{
	if (Flag == true) {
		str1 += _T("9");
		updatevalue();
	}
	else {
		str2 += _T("9");
		updatevalue2();
	}
}

void CCalculatorFinalDlg::OnBnClickedButtonDecimal()
{
	if (Flag == true) {
		if (m_result.Find('.') == -1) {
			str1 += _T(".");
			m_result = str1;
			UpdateData(FALSE);
		}
	}
	else {
		if (m_result.Find('.') == -1) {
			str2 += _T(".");
			m_result = str2;
			UpdateData(FALSE);
			return;
		}
	}
	
}
int mincount=0;
int pos;
int opcount = 0;
int pcount=0;
void CCalculatorFinalDlg::OnBnClickedButtonPlus()
{
	pcount++;
	opera = 1;
	if ((m_result != _T("") && opcount % 2 == 0 && pcount > 1) || (m_result != _T("") && pcount > 1 && opcount % 2 == 1)) {
			number2 = _ttof(m_result);
			m_result.Format(_T("%.2f"), number1 + number2);
			removeZeros();
			UpdateData(FALSE);
			number1 = _ttof(m_result);
			str1 = _T("");
			str2 = _T("");
			opcount = 0;
		}
		if (m_result != _T("")) {
			number1 = _ttof(m_result);
			Flag = !Flag;
			m_result = _T("");
			opera = 1;
		}
}

void CCalculatorFinalDlg::OnBnClickedButtonMinus()
{
	mincount++;
	opcount++;
	if (pcount > 1) {
		if (m_result != _T("") && opcount % 2 == 0 || opcount % 2 == 1) {
			number2 = _ttof(m_result);
			m_result.Format(_T("%.2f"), number1 - number2);
			removeZeros();
			UpdateData(FALSE);
			number1 = _ttof(m_result);
			str1 = _T("");
			str2 = _T("");
			opcount = 0;
		}
		if (m_result != _T("")) {
			number1 = _ttof(m_result);
			Flag = !Flag;
			m_result = _T("");
			opera = 2;
		}
	}
	else {
		if ((m_result != _T("") && opcount % 2 == 0 && mincount > 1) || (m_result != _T("") && mincount > 1 && opcount % 2 == 1)) {
			number2 = _ttof(m_result);
			m_result.Format(_T("%.2f"), number1 - number2);
			removeZeros();
			UpdateData(FALSE);
			number1 = _ttof(m_result);
			str1 = _T("");
			str2 = _T("");
			opcount = 0;
		}
		if (m_result != _T("")) {
			number1 = _ttof(m_result);
			Flag = !Flag;
			m_result = _T("");
			opera = 2;
		}
	}
}

void CCalculatorFinalDlg::OnBnClickedButtonMultiply()
{
	if (m_result != _T("")) {
		number1 = _ttof(m_result);
		Flag = !Flag;
		m_result = _T("");
		opera = 3;
	}
}

int dcount = 0;
void CCalculatorFinalDlg::OnBnClickedButtonDivision()
{
	dcount++;
	if (m_result != _T("")) {
		number1 = _ttof(m_result);
		Flag = !Flag;
		m_result = _T("");
		opera = 4;
	}
}


void CCalculatorFinalDlg::OnBnClickedButtonBack()
{

	if (m_result != _T("")) {
		m_result.Delete(m_result.GetLength() - 1);
		if (m_result.IsEmpty()) {
			m_result = _T("0");
		}
		UpdateData(FALSE);
	}
}

int ecount = 0;
void CCalculatorFinalDlg::OnBnClickedButtonEquals()
{
	pcount = 0;
	mincount = 0;
	ecount++;
	/*if (opera==4 && m_result != _T("") && ecount < 2) {
		divide();
	}*/
	/*if (m_result != _T("") &&opera!=4) {
		number2 = _ttof(m_result);
		Flag = !Flag;
		m_result = _T("");
	}*/
	if (m_result != _T("")) {
		number2 = _ttof(m_result);
		Flag = !Flag;
		m_result = _T("");
	}
	if (opera == 1) {
		number0 = number1 + number2;
	}
	else if (opera == 2) {
		number0 = number1 - number2;
	}
	else if (opera == 3) {
		number0 = number1 * number2;
	}
	if (opera == 4) {
		number0 = number1 / number2;
		if (number2 == 0) {
			m_result = _T("Cannot divide by zero.");
			UpdateData(FALSE);
			return;
		}
		m_result.Format(_T("%.4f"), number0);
		UpdateData(FALSE);
		str1 = _T("");
		str2 = _T("");
		return;
	}
		/*if (number2 == 0) {
			m_result = _T("Cannot divide by zero.");
			UpdateData(FALSE);
			return;
		}
		if(ecount<2){
			number0 = number1 / number2;
		}
		else {
			number1 = _ttof(m_result);
			number0 = number1 / number2;
		}
	}*/
		m_result.Format(_T("%.4f"), number0);
		remove4Zeros();
		UpdateData(FALSE);
		str1 = _T("");
		str2 = _T("");
	}



void CCalculatorFinalDlg::OnBnClickedButtonPercent()
{
	number2 = _ttof(m_result);
	m_result.Format(_T("%.4f"), number1 * (number2 / 100));
	if (m_result.Find(_T(".0000"), 0) != -1) {
		pos = m_result.Find(_T(".0000"), 0);
		m_result.Delete(pos, 5);
	}
	UpdateData(FALSE);
	
}


void CCalculatorFinalDlg::OnBnClickedButtonClear()
{
	number1 = 0, number2 = 0, number0 = 0, mincount = 0,ecount=0,pcount=0;
	str1 = _T("");
	str2 = _T("");
	m_result = _T("0");
	UpdateData(FALSE);
}


void CCalculatorFinalDlg::OnBnClickedButtonCe()
{
	number2 = 0;
	if (!str2.IsEmpty()) {
		str2 = _T("");
		number2 = 0;
		m_result = _T("0");
		UpdateData(FALSE);
	}
	else {
		str1 = _T("");
		number1 = 0;
		m_result = _T("0");
		UpdateData(FALSE);
	}
}


void CCalculatorFinalDlg::OnBnClickedButtonDivbyx()
{	
	number1 = _ttof(m_result);
	if (number1 == 0) {
		m_result = _T("Cannot divide by Zero.");
		UpdateData(FALSE);
	}else{
		m_result.Format(_T("%.3f"), 1 / number1);
		UpdateData(FALSE);
	}	
}

void CCalculatorFinalDlg::OnBnClickedButtonSqrt()
{
	number1 = _ttof(m_result);
	m_result.Format(_T("%.3f"), sqrt(number1));
	UpdateData(FALSE);
}

void CCalculatorFinalDlg::OnBnClickedButtonSquare()
{
	number1 = _ttof(m_result);
	m_result.Format(_T("%.3f"), square(number1));
	UpdateData(FALSE);
}


void CCalculatorFinalDlg::OnBnClickedButtonMinplus()
{
	if (m_result.Find('-') == -1) {
		m_result = _T("-") + m_result;
		UpdateData(FALSE);
	}
	else {
		m_result.Remove('-');
		UpdateData(FALSE);
	}
}


void CCalculatorFinalDlg::OnBnClickedButtonLog()
{
	number1 = _ttof(m_result);
	number1 = log10(number1);
	m_result.Format(_T("% .3f"), number1);
	UpdateData(FALSE);
}
