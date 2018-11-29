#include "MainWin.h"

BEGIN_MESSAGE_MAP(CMainWin, CFrameWnd)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

CMainWin::CMainWin()
{
	Create(NULL,_T("Thread tryouts"));
}

void CMainWin::OnLButtonDown(UINT nFlags, CPoint pnt)
{
	AfxBeginThread(Thread1, this);
	AfxBeginThread(Thread2, this);
}

UINT Thread1(LPVOID WinObjPtr)
{
	CMainWin* ptr = (CMainWin*)WinObjPtr;
	CSingleLock sc(&(ptr->sem));

	sc.Lock();

	CClientDC dc(ptr);
	
	for (int k = 0; k < 10; k++)
	{
		Sleep(100);

		CBrush bBrush(RGB(0,0,255));
		//CPen yPen(PS_DOT, 1, RGB(0,0,0));

		dc.SelectObject(&bBrush);
		//dc.SelectObject(&yPen);

		dc.Rectangle((k + 1) * 55, 20, 55 + (k + 1) * 55, 70);
	}

	dc.Draw3dRect(250,250, 50, 50, RGB(255, 0, 0), RGB(0, 255, 0));

	sc.Unlock();

	return 0;
}

UINT Thread2(LPVOID WinObjPtr)
{
	CMainWin* ptr = (CMainWin*)WinObjPtr;
	CSingleLock sc(&(ptr->sem));

	sc.Lock();

	CClientDC dc(ptr);

	for (int k = 0; k < 10; k++)
	{
		Sleep(100);

		CBrush yBrush(RGB(255, 255, 0));
		//CPen bPen(PS_DASHDOT, 1, RGB(0, 0, 255));

		dc.SelectObject(&yBrush);
		//dc.SelectObject(&bPen);

		dc.Rectangle((k + 1) * 55, 90, 55 + (k + 1) * 55, 140);
	}

	dc.Draw3dRect(300, 250, 50, 50, RGB(0, 255, 0), RGB(255, 0, 0));

	sc.Unlock();

	return 0;
}

CMainWin::~CMainWin()
{
}
