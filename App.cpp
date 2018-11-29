#include "App.h"
#include "MainWin.h"

CApp::CApp()
{
}

BOOL CApp::InitInstance()
{
	m_pMainWnd = new CMainWin;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}


CApp::~CApp()
{
}
