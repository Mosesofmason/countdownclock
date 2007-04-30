// alermclock.h : main header file for the ALERMCLOCK application
//

#if !defined(AFX_ALERMCLOCK_H__32866F11_A928_4743_954F_4DD71B1ACC60__INCLUDED_)
#define AFX_ALERMCLOCK_H__32866F11_A928_4743_954F_4DD71B1ACC60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAlermclockApp:
// See alermclock.cpp for the implementation of this class
//

class CAlermclockApp : public CWinApp
{
public:
	CAlermclockApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAlermclockApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAlermclockApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALERMCLOCK_H__32866F11_A928_4743_954F_4DD71B1ACC60__INCLUDED_)
