// alermclockDlg.cpp : implementation file
//

#include "stdafx.h"
#include "alermclock.h"
#include "alermclockDlg.h"
#include <stdio.h>
#include <stdlib.h>
#include <mmsystem.h>  
	#pragma   comment(lib,"Winmm.lib")   

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAlermclockDlg dialog

CAlermclockDlg::CAlermclockDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAlermclockDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAlermclockDlg)
	m_imin = _T("");
	m_isec = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAlermclockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAlermclockDlg)
	DDX_Control(pDX, IDC_STOP, m_stop);
	DDX_Control(pDX, IDC_START, m_start);
	DDX_Control(pDX, IDC_SEC, m_sec);
	DDX_Control(pDX, IDC_MIN, m_min);
	DDX_CBString(pDX, IDC_MIN, m_imin);
	DDX_CBString(pDX, IDC_SEC, m_isec);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAlermclockDlg, CDialog)
	//{{AFX_MSG_MAP(CAlermclockDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_STOP, OnStop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAlermclockDlg message handlers

BOOL CAlermclockDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	
    char str_combolist[60][30];

	for (int i=0; i<60; i++)
	{
		itoa(i, str_combolist[i], 10);
	}
	// init context of comboBox
	int nIdx;
	for (i=0; i<60; i++)
	{
		nIdx=m_min.AddString (str_combolist[i]);
		m_min.SetItemData(nIdx, i);

		nIdx=m_sec.AddString (str_combolist[i]);
		m_sec.SetItemData(nIdx, i);
	}
	//m_sec.

/*
		char buff[30];
		itoa(m_sec.GetItemData(5), buff, 10);
		MessageBox(LPCTSTR(buff));
	
*/
	// Change Font of countdown second box
	CStatic *pStc=(CStatic*) GetDlgItem(IDC_SSEC); // point to CStatic
	LOGFONT lf; // create a logfont
	_pfont=new CFont; // create a CFont
	lf.lfHeight=lf.lfHeight*10; // power logfont Height
//	_pfont->DeleteObject();
	_pfont->CreateFontIndirect(&lf); // let CFont get current powered logfont
	pStc->SetFont(_pfont); // set CStatic Font

	_pfont->DeleteObject(); // delete CFont



	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAlermclockDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

//  If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAlermclockDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAlermclockDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// start countdown
void CAlermclockDlg::OnStart() 
{
	// TODO: Add your control notification handler code here
//	char buff[30];
	UpdateData(TRUE);
	// get current select item
	int i=m_min.GetCurSel();
	int j=m_sec.GetCurSel();
	_minutes=m_min.GetItemData(i);
	_seconds=m_sec.GetItemData(j);
	// if not selected, let value(s) is/are 0
	if (_minutes<0)
	{
		_minutes=0;
	}
	if (_seconds<0)
	{
		_seconds=0;
	}
	// disable comboBox
	m_min.EnableWindow(FALSE);
	m_sec.EnableWindow(FALSE);
	m_start.EnableWindow(FALSE);
	m_stop.EnableWindow(TRUE);
	// cal total seconds
	_tot=_minutes*60+_seconds;
	
/*
		itoa(_tot, buff, 10);
		MessageBox(LPCTSTR(buff));
*/
	// start timer
	SetTimer (ID_TIMER, 1000, NULL);
	// goto onTimer()



}

void CAlermclockDlg::OnTimer(UINT nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	// if time's up
	if (_tot<=0)
	{
		KillTimer(ID_TIMER);
// MessageBox("Time's up!");
		// enable comboBox
		m_min.EnableWindow(TRUE);
		m_sec.EnableWindow(TRUE);
		m_start.EnableWindow(TRUE);
		// disable stop button
	//	m_stop.EnableWindow(FALSE);
		// play sound
		// The MAKEINTRESOURCE macro converts an integer value 
		// to a resource type compatible with Win32 resource-management functions. 
		// This macro is used in place of a string containing the name of the 
		// resource. 
		PlaySound(MAKEINTRESOURCE(IDS_SWAVE), NULL, SND_NOSTOP|SND_ASYNC|SND_RESOURCE|SND_LOOP);
	}
	else
	{
		// countdown
		_tot--;
		_chars.Format("%d", _tot);
		// display countdown seconds in CStatic label
		SetDlgItemText(IDC_SSEC, _chars);
	}
	CDialog::OnTimer(nIDEvent);
}

void CAlermclockDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	// stop timer
	KillTimer(ID_TIMER);
	m_start.EnableWindow(TRUE);
	m_sec.EnableWindow(TRUE);
	m_min.EnableWindow(TRUE);
	m_stop.EnableWindow(FALSE);
	PlaySound(MAKEINTRESOURCE(IDS_SWAVE), NULL, SND_NOSTOP|SND_ASYNC|SND_RESOURCE);
}
