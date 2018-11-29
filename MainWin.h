#pragma once
#include <afxwin.h>
#include <afxmt.h>

class CMainWin:public CFrameWnd
{
public:
	CSemaphore sem;

	CMainWin();
	void OnLButtonDown(UINT nFlags, CPoint pnt);
	~CMainWin();
	DECLARE_MESSAGE_MAP();
};

UINT Thread1(LPVOID);
UINT Thread2(LPVOID);