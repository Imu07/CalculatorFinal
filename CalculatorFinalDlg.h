
// CalculatorFinalDlg.h : header file
//

#pragma once

#include <vector>
using namespace std;
// CCalculatorFinalDlg dialog
class CCalculatorFinalDlg : public CDialogEx
{
// Construction
public:
	CCalculatorFinalDlg(CWnd* pParent = nullptr);

	// standard constructor
	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATORFINAL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton0();
	float number1;
	float number2, number0;
	CString str1, str2;
	CString m_result;
	int opera;
	vector<char> operations;
	float square(float num) {
		float result = 0;
		for (int i = 0; i < num; i++) {
			result += num;
		}
		return result;
	}
	float percentage(float num1,float num2) {
		float result;
		result = num1 * (num2 / 100);
		return result;
	}
	void updatevalue() {
		m_result = str1;
		UpdateData(FALSE);
	};
	void updatevalue2() {
		m_result = str2;
		UpdateData(FALSE);
	};
	int pos;
	int ecount;
	void removeZeros() {
		if (m_result.Find(_T(".00"), 0) != -1) {
			pos = m_result.Find(_T(".00"), 0);
			m_result.Delete(pos, 3);
		}
	}
	void remove4Zeros() {
		
		if (m_result.Find(_T(".0000"), 0) != -1) {
			pos = m_result.Find(_T(".0000"), 0);
			m_result.Delete(pos, 4);
		}
		else if (m_result.Find(_T("000"), 0) != -1) {
			pos = m_result.Find(_T("000"), 0);
			m_result.Delete(pos, 3);
		}
	}
	bool Flag;
	void divide() {
		number2 = _ttof(m_result);
		Flag = !Flag;
		m_result = _T("");
		if (opera == 4) {
			if (ecount < 2) {
				number0 = number1 / number2;
			}
			else {
				number1 = _ttof(m_result);
				number0 = number1 / number2;
			}

		}
		m_result.Format(_T("%.4f"), number0);
		UpdateData(FALSE);
		str1 = _T("");
		str2 = _T("");
		return;
	}
	void divideByZero() {
		m_result = _T("Cannot divide by zero.");
		UpdateData(FALSE);
		return;
	}
	
private:

	
	
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonDecimal();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnBnClickedButtonDivision();
	afx_msg void OnBnClickedButtonBack();
	afx_msg void OnBnClickedButtonEquals();
	afx_msg void OnBnClickedButtonPercent();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonCe();
	afx_msg void OnBnClickedButtonDivbyx();
	afx_msg void OnBnClickedButtonSqrt();
	afx_msg void OnBnClickedButtonSquare();
	afx_msg void OnBnClickedButtonMinplus();
	CMFCButton m_color2;
	CMFCButton m_colorEquals;
	CMFCButton m_colorPlus;
	CMFCButton m_colorMinus;
	CMFCButton m_colorMul;
	CMFCButton m_colorDiv;
	CMFCButton m_color1;
	CMFCButton m_color3;
	CMFCButton m_color4;
	CMFCButton m_color5;
	CMFCButton m_color6;
	CMFCButton m_color7;
	CMFCButton m_color8;
	CMFCButton m_color9;
	CMFCButton m_colorCe;
	CMFCButton m_colorC;
	CMFCButton m_colorPminus;
	CMFCButton m_color0;
	CMFCButton m_colorDecimal;
	CMFCButton m_colorBack;
	CMFCButton m_colorPerc;
	CMFCButton m_colorDivByx;
	CMFCButton m_colorRoot;
	CMFCButton m_colorSquare;
	afx_msg void OnBnClickedButtonLog();
};
