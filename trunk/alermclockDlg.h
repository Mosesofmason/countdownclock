// alermclockDlg.h : header file
//

#if !defined(AFX_ALERMCLOCKDLG_H__AB1B8275_27B0_4F72_AF0B_E30318554158__INCLUDED_)
#define AFX_ALERMCLOCKDLG_H__AB1B8275_27B0_4F72_AF0B_E30318554158__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAlermclockDlg dialog

class CAlermclockDlg : public CDialog
{
// Construction
public:
	CAlermclockDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAlermclockDlg)
	enum { IDD = IDD_ALERMCLOCK_DIALOG };
	CButton	m_stop;
	CButton	m_start;
	CComboBox	m_sec;
	CComboBox	m_min;
	CString	m_imin;
	CString	m_isec;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAlermclockDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAlermclockDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	long int _tot;
	int _minutes;
	int _seconds;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALERMCLOCKDLG_H__AB1B8275_27B0_4F72_AF0B_E30318554158__INCLUDED_)
