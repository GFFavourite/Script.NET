////////////////////////////////////////////////////////////////////////////
//	File:		LuaExCmd.h
//	Version:	1.0.0.0
//	Created:	2007-12-20
//
//	Author:		xieyongfang
//	E-mail:		script.net@gmail.com
//
//	Interface define of LuaExCmd.
////////////////////////////////////////////////////////////////////////////
#ifndef __LUAEXCMD_H_
#define __LUAEXCMD_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


typedef struct _TOPTITEM
{
	HTREEITEM	hItem;		// ���ڵ���(�ڲ�ʹ��)
	INT			iType;		// �ڵ�����
	CString		lpszText;	// ��Ϣ
	CString		lpszEdit;	// �ɱ༭�ַ���
	CString		lpszList;	// Combo�б�
	BOOL		bCheck;		// �����
	INT			iImage;		// ͼ��
	INT			iParent;	// ���ڵ�����
	CString		strTclVar;	// TCL�б���������
public:
	_TOPTITEM& operator = (const _TOPTITEM& other)
	{
		hItem	= other.hItem;
		iType	= other.iType;
		lpszText= other.lpszText;
		lpszEdit= other.lpszEdit;
		lpszList= other.lpszList;
		bCheck	= other.bCheck;
		iImage	= other.iImage;
		iParent	= other.iParent;
		strTclVar=other.strTclVar;
		return *this;
	};
} TOPTITEM, FAR* LPTOPTITEM;

typedef CArray<TOPTITEM, TOPTITEM&> CTOptArray;

// ��������������
enum {
	TOPT_MSG,			// ���ñ������Ϣ
	TOPT_HELP,			// ���ð����ļ�
	TOPT_ITEM,			// �����
	TOPT_GROUP,			// �����
	TOPT_CHECKBOX,		// ��Ӽ���
	TOPT_RADIOBUTTON,	// ��ӹ㲥��ť
	TOPT_EDIT,			// ��ӱ༭��
	TOPT_COMBO,			// �����Ͽ�
	TOPT_FONT,			// ѡ������
	TOPT_TIME,			// ����ʱ������
	TOPT_COLOR,			// ѡ����ɫ
	TOPT_CHOOSEDIR,		// ѡ��·��
	TOPT_CHOOSEFILE,	// �ļ�����
};

// ����������ͼ��
enum {
	TOPTI_FOLDER,		// �ļ���
	TOPTI_GROUP,		// ��
	TOPTI_EDIT,			// �༭��
	TOPTI_COMBO,		// ��Ͽ�
	TOPTI_M_FOLDER,		// �ļ���(������)
	TOPTI_M_GROUP,		// ��(������)
	TOPTI_M_EDIT,		// �༭��(������)
	TOPTI_M_COMBO,		// ��Ͽ�(������)
	TOPTI_INFO,			// ��Ϣ
	TOPTI_PROJECT,		// ����
	TOPTI_FILE,			// �ļ�
	TOPTI_VERSION,		// �汾
	TOPTI_INTERFACE,	// �ӿ�
	TOPTI_ITEM,			// ��Ŀ
	TOPTI_HELP,			// ����
	TOPTI_BOARD,		// ����
	TOPTI_WORNING,		// �澯
	TOPTI_CONNECT,		// ��������
	TOPTI_USER,			// �û�
	TOPTI_FONT,			// ����
	TOPTI_TIME,			// ʱ��
	TOPTI_COLOR,		// ��ɫ
};


// ͨ�õ�¼��Ϣ�ṹ
struct TCommLoginInfo
{
	CString	strAddress;		// ��¼��ַ
	CString	strUserName;	// �û���
	CString	strPassword;	// ����
	CString	strDomain;		// ��¼��
	CString	strDomainList;	// ��¼���б�
	CString	strTitle;		// ����
	CString	strInfo;		// ��ʾ��Ϣ
	CString	strLAddress;	// ��ַ�����ǩ
	CString	strLUserName;	// �û������ǩ
	CString	strLPassword;	// ���������ǩ
	CString	strLDomain;		// �������ǩ
	CString	strCheck;		// ��������
	BOOL	bCheck;			// ����ֵ
	BOOL	bUseAddress;	// ʹ�õ�ַ�ֶ�
	BOOL	bUseUserName;	// ʹ���û����ֶ�
	BOOL	bUsePassword;	// ʹ�ÿ����ֶ�
	BOOL	bUseDomain;		// ʹ�õ�¼���ֶ�
	CString	varAddress;		// ��¼��ַTCL����
	CString	varUserName;	// �û���TCL����
	CString	varPassword;	// ����TCL����
	CString	varDomain;		// ��¼��TCL����
	CString	varCheck;		// ����TCL����
	CString	strFocus;		// ���뽹��

public:
	TCommLoginInfo()
	{
		strAddress		= "";
		strUserName		= "";
		strPassword		= "";
		strDomain		= "";
		strDomainList	= "";
		strTitle		= "";
		strInfo			= "";
		strLAddress		= "";
		strLUserName	= "";
		strLPassword	= "";
		strLDomain		= "";
		strCheck		= "";
		bCheck			= FALSE;
		bUseAddress		= FALSE;
		bUseUserName	= FALSE;
		bUsePassword	= FALSE;
		bUseDomain		= FALSE;
		varAddress		= "";
		varUserName		= "";
		varPassword		= "";
		varDomain		= "";
		varCheck		= "";
		strFocus		= "";
	};
};


// ͨ������Ի�����Ϣ�ṹ
struct TTaskDialogInfo
{
	IInterp*	pInterp;		// ������ָ��
	CString	strWindowTitle;		// ���ڱ���
	CString	strVerificationText;// ��֤����
	CString	strExpandedControlText;	// ��չ�ؼ�����
	CString	strCollapsedControlText;// �����ؼ�����
	CString	strMainInstruction;	// ������
	CString	strContent;			// ����
	CString	strExpandedInformation;// չ����Ϣ
	CString	strFooter;			// ��ע
	CString	strMainIcon;		// ��ͼ��
	CString	strFooterIcon;		// ��עͼ��
	int		nWidth;				// ���ڿ��
	CStringArray	asButtonText;// ��ť����
	CUIntArray		auButtonID;	// ��ťID����
	CStringArray	asButtonScript;// ��ť�ű�����
	CStringArray	asRadioButtonText;// Radio��ť����
	CUIntArray		auRadioButtonID;// Radio��ťID����
	BOOL	bEnableCommandLinks;// ������������
	BOOL	bEnableHyperlinks;	// �������ֳ�����
	BOOL	bEnableRelativePosition;// ������ݸ�����ȷ������λ��
	BOOL	bShowProgressBar;	// ��ʾ������
	int		nProgressBarPos;	// ������λ��
	int		nProgressBarRangeMin;// ��������Сֵ
	int		nProgressBarRangeMax;// ���������ֵ
	BOOL	bMarquee;			// ������ʹ�û���ģʽ
	BOOL	bExpandedByDefault;	// Ĭ��������Ƿ���ʾ����������
	BOOL	bExpandFooterArea;	// ���������Ƿ���ʾ�ڽ�ע��
	int		nDefaultButton;		// Ĭ�ϰ�ťID
	int		nDefaultRadioButton;// Ĭ��Radio��ťID
	BOOL	bNoDefaultRadioButton;// û��Ĭ�ϵ�radio��ť
	BOOL	bVerifyCheckState;	// check���״̬
	BOOL	bEnableCallbackTimer;// ����ص�ʱ��
	int		nTimerTimeout;		// ��ʱ����ʱʱ��
	CString	strTimerScript;		// ��ʱ����ʱ�ű�
	BOOL	bCommonButtonOk;	// ��ʾ������ťOk
	BOOL	bCommonButtonYes;	// ��ʾ������ťYes
	BOOL	bCommonButtonNo;	// ��ʾ������ťNo
	BOOL	bCommonButtonCancel;// ��ʾ������ťCancel
	BOOL	bCommonButtonRetry;	// ��ʾ������ťRetry
	BOOL	bCommonButtonClose;	// ��ʾ������ťClose
	int		nSelectedButtonId;	// ����ѡ��İ�ťID
	int		nSelectedRadioButtonId;// ����ѡ���Radio��ťID
	BOOL	bIsVerificiationChecked;// ����check���״̬

public:
	TTaskDialogInfo()
	{
		pInterp						= NULL;
		strWindowTitle				= "";
		strVerificationText			= "";
		strExpandedControlText		= "";
		strCollapsedControlText		= "";
		strMainInstruction			= "";
		strContent					= "";
		strExpandedInformation		= "";
		strFooter					= "";
		strFooterIcon				= "";
		nWidth						= 0;
		bEnableCommandLinks			= TRUE;
		bEnableHyperlinks			= TRUE;
		bEnableRelativePosition		= FALSE;
		bShowProgressBar			= FALSE;
		nProgressBarPos				= 0;
		nProgressBarRangeMin		= 0;
		nProgressBarRangeMax		= 100;
		bMarquee					= FALSE;
		bExpandedByDefault			= FALSE;
		bExpandFooterArea			= FALSE;
		nDefaultButton				= 0;
		nDefaultRadioButton			= 0;
		bNoDefaultRadioButton		= FALSE;
		bVerifyCheckState			= FALSE;
		bEnableCallbackTimer		= FALSE;
		nTimerTimeout				= 0;
		strTimerScript				= "";
		bCommonButtonOk				= TRUE;
		bCommonButtonYes			= FALSE;
		bCommonButtonNo				= FALSE;
		bCommonButtonCancel			= TRUE;
		bCommonButtonRetry			= FALSE;
		bCommonButtonClose			= FALSE;
		nSelectedButtonId			= 0;
		nSelectedRadioButtonId		= 0;
		bIsVerificiationChecked		= FALSE;
	};
};


/////////////////////////////////////////////////////////////////
// Popup control struct
struct TPopupControlInfo
{
	IInterp*	pInterp;	// ������ָ��
	CString	strTheme;		// ���
	CString	strIcon;		// ͼ��
	CString	strCaption;		// ���ڱ���
	CString	strTitle;		// �������ı�
	CString	strText;		// ������
	CString	strLinkTitle;	// ����������
	CString	strLinkText;	// ��������
	BOOL	bRTFText;		// �Ƿ�RTF��ʽ�ı�
	int		nShowDelay;		// ��ʾʱ��
	int		nTransparency;	// ͸����
	int		nWidth;			// ���ڿ��
	int		nHight;			// ���ڸ߶�
	int		nAddHight;		// ���ӵĸ߶�
	CStringArray	asButtonText;// ��ť����
	CStringArray	asButtonScript;// ��ť�ű�����
	CStringArray	asRadioButtonText;// Radio��ť����

public:
	TPopupControlInfo()
	{
		pInterp			= NULL;
		strTheme		= "";
		strIcon			= "";
		strCaption		= "";
		strTitle		= "";
		strText			= "";
		strLinkTitle	= "";
		strLinkText		= "";
		bRTFText		= FALSE;
		nShowDelay		= 0;
		nTransparency	= 0;
		nWidth			= 0;
		nHight			= 0;
		nAddHight		= 0;
	};

	TPopupControlInfo& operator = (const TPopupControlInfo& other)
	{
		pInterp			= other.pInterp;
		strTheme		= other.strTheme;
		strIcon			= other.strIcon;
		strCaption		= other.strCaption;
		strTitle		= other.strTitle;
		strText			= other.strText;
		strLinkTitle	= other.strLinkTitle;
		strLinkText		= other.strLinkText;
		bRTFText		= other.bRTFText;
		nShowDelay		= other.nShowDelay;
		nTransparency	= other.nTransparency;
		nWidth			= other.nWidth;
		nHight			= other.nHight;
		nAddHight		= other.nAddHight;
		asButtonText.RemoveAll();
		for(int i=0; i<other.asButtonText.GetSize(); i++)
		{
			asButtonText.Add(other.asButtonText[i]);
		}
		asButtonScript.RemoveAll();
		for(i=0; i<other.asButtonScript.GetSize(); i++)
		{
			asButtonScript.Add(other.asButtonScript[i]);
		}
		return *this;
	};
};

//
// ��չ�˵���Ϣ��
//
class CExtMenuInfo : public CObject
{
public:
	CExtMenuInfo()
	{
		m_strVciId		= "";
		m_strMainMenu	= "";
		m_strSubMenu	= "";
		pProc			= NULL;
		pUpdateProc		= NULL;
		nId				= 0;
		nGrade			= 0;
		//--------��չ��Ա����----------
		nProcType		= 0;
		m_strAction		= "";
	}
	~CExtMenuInfo() {};

	CExtMenuInfo(const CExtMenuInfo& other)
	{
		m_strVciId		= other.m_strVciId;
		m_strMainMenu	= other.m_strMainMenu;
		m_strSubMenu	= other.m_strSubMenu;
		pProc			= other.pProc;
		pUpdateProc		= other.pUpdateProc;
		nId				= other.nId;
		nGrade			= other.nGrade;
		nProcType		= other.nProcType;
		m_strAction		= other.m_strAction;
	}

	CExtMenuInfo& operator = (const CExtMenuInfo& other)
	{
		m_strVciId		= other.m_strVciId;
		m_strMainMenu	= other.m_strMainMenu;
		m_strSubMenu	= other.m_strSubMenu;
		pProc			= other.pProc;
		pUpdateProc		= other.pUpdateProc;
		nId				= other.nId;
		nGrade			= other.nGrade;
		nProcType		= other.nProcType;
		m_strAction		= other.m_strAction;
		return *this;
	}

public:
	CString	m_strVciId;		// �����OWM����չ�˵�,���ʾOWM��ID
	CString	m_strMainMenu;	// ���˵���
	CString	m_strSubMenu;	// �Ӳ˵���
	TYPEOF_ClientMenu *pProc;	// �˵�����
	TYPEOF_UpdateClientMenu	*pUpdateProc;	// ˢ�²˵�����
	int nId;					// �˵�ID
	int nGrade;					// Ȩ��
	int nProcType;				// �˵���������(0��ʾ��ͨ����,1��ʾ��һ�������Ĳ˵�����)
	CString	m_strAction;	// �˵�ִ�еĶ���
};


#endif	// __LUAEXCMD_H_