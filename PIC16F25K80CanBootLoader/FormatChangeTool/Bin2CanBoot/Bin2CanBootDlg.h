// Bin2CanBootDlg.h : header file
//

#if !defined(AFX_BIN2CANBOOTDLG_H__159C0B3E_48F5_4C0D_A84F_BCF8B251E2DA__INCLUDED_)
#define AFX_BIN2CANBOOTDLG_H__159C0B3E_48F5_4C0D_A84F_BCF8B251E2DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBin2CanBootDlg dialog

class CBin2CanBootDlg : public CDialog
{
// Construction
public:
	CBin2CanBootDlg(CWnd* pParent = NULL);	// standard constructor
	BYTE a1,a2,a3,a4;

// Dialog Data
	//{{AFX_DATA(CBin2CanBootDlg)
	enum { IDD = IDD_BIN2CANBOOT_DIALOG };
	CIPAddressCtrl	m_address;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBin2CanBootDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBin2CanBootDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnSave();
	afx_msg void OnLoad();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BIN2CANBOOTDLG_H__159C0B3E_48F5_4C0D_A84F_BCF8B251E2DA__INCLUDED_)
