// Bin2CanBootDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bin2CanBoot.h"
#include "Bin2CanBootDlg.h"

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
// CBin2CanBootDlg dialog

CBin2CanBootDlg::CBin2CanBootDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBin2CanBootDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBin2CanBootDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBin2CanBootDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBin2CanBootDlg)
	DDX_Control(pDX, IDC_IPADDRESS2, m_address);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBin2CanBootDlg, CDialog)
	//{{AFX_MSG_MAP(CBin2CanBootDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnSave)
	ON_BN_CLICKED(IDC_BUTTON2, OnLoad)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBin2CanBootDlg message handlers

BOOL CBin2CanBootDlg::OnInitDialog()
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
	m_address.SetAddress(000,239,002,240);
	

	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBin2CanBootDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBin2CanBootDlg::OnPaint() 
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
HCURSOR CBin2CanBootDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBin2CanBootDlg::OnOK() 
{
	// TODO: Add extra validation her

unsigned char startpoint[]={0x00,0xEF,0x02,0xF0};
FILE *fps,*fpo;
char ch;
unsigned long i=0;
CString cstmp;

	UpdateData(TRUE);
	m_address.GetAddress(a1,a2,a3,a4);
	startpoint[0] =	a1;
	startpoint[1] =	a2;
	startpoint[2] =	a3;
	startpoint[3] =	a4;
	fps=fopen("memory.bin","rb");
	fpo=fopen("CanBootLoader.cbt","wb");

	
	if ((fps==NULL)||(fpo==NULL))
	{
		::MessageBox(NULL,"程序打开错误","请检查bin文件是否存在并且可读,以及cbl文件是否被占用导致无法输出",MB_OK);
		return ;
	}

	while(!feof(fps))
	{
		ch=fgetc(fps);
		if((0<=i)&&(i<=3))
		{
			fprintf(fpo,"%c",startpoint[i]);	//将程序指针强制跳入0x400BootLoader位置
		}
		else
		{
			fprintf(fpo,"%c",ch);
		}
		
		i++;
		if(i>=0x8000)
		{
			fclose(fps);
			fclose(fpo);
			return;
		}	
	}

	return ;

}

void CBin2CanBootDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	CString Straddress1;
	CString Straddress2;
	CString Straddress3;
	CString Straddress4;

	UpdateData(TRUE);
	m_address.GetAddress(a1,a2,a3,a4);

	Straddress1.Format("%d",a1);
	Straddress2.Format("%d",a2);
	Straddress3.Format("%d",a3);
	Straddress4.Format("%d",a4);

	WritePrivateProfileString("启动地址","Address1",Straddress1,".\\setting.ini");
	WritePrivateProfileString("启动地址","Address2",Straddress2,".\\setting.ini");
	WritePrivateProfileString("启动地址","Address3",Straddress3,".\\setting.ini");
	WritePrivateProfileString("启动地址","Address4",Straddress4,".\\setting.ini");
}

void CBin2CanBootDlg::OnLoad() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	CString Straddress1;
	CString Straddress2;
	CString Straddress3;
	CString Straddress4;

	GetPrivateProfileString("启动地址","Address1","",Straddress1.GetBuffer(4),4,".\\setting.ini");
	GetPrivateProfileString("启动地址","Address2","",Straddress2.GetBuffer(4),4,".\\setting.ini");
	GetPrivateProfileString("启动地址","Address3","",Straddress3.GetBuffer(4),4,".\\setting.ini");
	GetPrivateProfileString("启动地址","Address4","",Straddress4.GetBuffer(4),4,".\\setting.ini");
	a1 = atoi(Straddress1.GetBuffer(4));
	a2 = atoi(Straddress2.GetBuffer(4));
	a3 = atoi(Straddress3.GetBuffer(4));
	a4 = atoi(Straddress4.GetBuffer(4));


	m_address.SetAddress(a1,a2,a3,a4);
	UpdateData(FALSE);

}
