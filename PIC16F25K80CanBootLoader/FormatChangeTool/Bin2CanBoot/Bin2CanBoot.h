// Bin2CanBoot.h : main header file for the BIN2CANBOOT application
//

#if !defined(AFX_BIN2CANBOOT_H__F2D2CB76_732E_4DEB_B48B_5B3F57B039A0__INCLUDED_)
#define AFX_BIN2CANBOOT_H__F2D2CB76_732E_4DEB_B48B_5B3F57B039A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBin2CanBootApp:
// See Bin2CanBoot.cpp for the implementation of this class
//

class CBin2CanBootApp : public CWinApp
{
public:
	CBin2CanBootApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBin2CanBootApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBin2CanBootApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BIN2CANBOOT_H__F2D2CB76_732E_4DEB_B48B_5B3F57B039A0__INCLUDED_)
