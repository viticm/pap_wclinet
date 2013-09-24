// CrashReportDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CrashReport.h"
#include "CrashReportDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCrashReportDlg 对话框



CCrashReportDlg::CCrashReportDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCrashReportDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCrashReportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FIX_SUGGESTION, m_clFixSuggestion);
	DDX_Control(pDX, ID_FULL_INFO, m_clFullInfo);
	DDX_Control(pDX, ID_DEBUG, m_clWinDebug);
}

BEGIN_MESSAGE_MAP(CCrashReportDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_DUMP_INFO, &CCrashReportDlg::OnEnChangeDumpInfo)
	ON_WM_CTLCOLOR()
	ON_EN_CHANGE(IDC_APPEND_INFO, &CCrashReportDlg::OnEnChangeAppendInfo)
END_MESSAGE_MAP()


// CCrashReportDlg 消息处理程序

BOOL CCrashReportDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将\“关于...\”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	
	// TODO: 在此添加额外的初始化代码
	
	COLORREF blue_color = RGB( 0, 0, 238 ) ;

	// 修复建议
	m_clFixSuggestion.SetURL( "#" ) ; //不要链接
	m_clFixSuggestion.SetUnderline( CHyperLink::ulAlways ) ;
	m_clFixSuggestion.SetColours( -1, blue_color, blue_color ) ;
	m_clFixSuggestion.SetTipText( "我们建议下次启动游戏时使用\"系统修复\"功能修复可能被损坏的资源文件" ) ;
	m_clFixSuggestion.SetTipDelayTime( 0 ) ;
	m_clFixSuggestion.SetTipMaxWidth( 200 ) ;

	// 查看详细信息（崩溃）
	m_clFullInfo.SetURL( m_strDumpFilePath ) ;
    m_clFullInfo.SetUnderline( CHyperLink::ulAlways ) ;
    m_clFullInfo.SetColours( -1, blue_color, blue_color ) ;
	m_clFullInfo.SetTipText( "" ) ; //不要提示

	SetDlgItemText( IDC_DUMP_INFO, m_strDumpInfo) ;
	SetDlgItemText( IDC_FILE_TITLE, m_strFileTitle ) ;
    
	if ( !m_bDebug ) GetDlgItem( ID_DEBUG )->EnableWindow( FALSE ) ;

	
	// 看来这个东东还真不好使
	RECT rect ;
	rect.left = 35 ;
	rect.top = 230 ;
	rect.right = 336 ;
	rect.bottom = 13 ;
	m_hOtherMoreTipWnd = CreateWindowEx( 0, "Static", "为了更快的解决您的问题，请你留下您的E-Mail或其他联系方式", WS_VISIBLE | WS_CHILD | WS_TABSTOP | SS_NOTIFY , 
		rect.left, rect.top, rect.right, rect.bottom, this->m_hWnd, NULL, GetModuleHandle( NULL ), NULL ) ;

	CWnd* pOtherMoreTipWnd = CWnd::FromHandle( m_hOtherMoreTipWnd ) ;
    CFont* pFont = GetFont() ; // 使用同样的字体
	pOtherMoreTipWnd->SetFont( pFont ) ;

	//::ShowWindow( m_hOtherMoreTipWnd, SW_HIDE ) ;

	return TRUE;  // 除非设置了控件的焦点，否则返回 TRUE
}

void CCrashReportDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCrashReportDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	
	CHARFORMAT charformat;
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
HCURSOR CCrashReportDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCrashReportDlg::OnEnChangeDumpInfo()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CCrashReportDlg::InitDialog( CString strFileName, CString strDumpInfo, CString strDumpFilePath, bool bDebug )
{
    m_strFileTitle = strFileName ;
	m_strDumpInfo = strDumpInfo ;
	m_strDumpFilePath = strDumpFilePath ;
	m_bDebug = bDebug ;
}

HBRUSH CCrashReportDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
    if ( ID_DEBUG == pWnd->GetDlgCtrlID() )
	{
		//pDC->SetTextColor( RGB( 172, 168, 153 ) );      //字体颜色
		//pDC->SetBkColor(RGB(0, 0, 255));       //字体背景色 
	}
	CWnd* pOtherMoreTipWnd = CWnd::FromHandle( m_hOtherMoreTipWnd ) ;
	if ( pOtherMoreTipWnd->GetDlgCtrlID() == pWnd->GetDlgCtrlID() )
	{
		pDC->SetTextColor( RGB( 172, 168, 153 ) );
		pDC->SetBkColor( RGB( 255, 255, 255 ) ) ; 
	}
	// TODO:  Return a different brush if the default is not desired
	return hbr;
}

void CCrashReportDlg::OnEnChangeAppendInfo()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	CString strAppendInfo;
	GetDlgItemText( IDC_APPEND_INFO, strAppendInfo ) ;
    if ( 0 == strcmp( "", strAppendInfo ) )
	{
		::ShowWindow( m_hOtherMoreTipWnd, SW_SHOW ) ;
	}
	else
	{
		::ShowWindow( m_hOtherMoreTipWnd, SW_HIDE ) ;
	}
}
