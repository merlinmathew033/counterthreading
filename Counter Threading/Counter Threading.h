
// Counter Threading.h : main header file for the Counter Threading application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCounterThreadingApp:
// See Counter Threading.cpp for the implementation of this class
//

class CCounterThreadingApp : public CWinAppEx
{
public:
	CCounterThreadingApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCounterThreadingApp theApp;
