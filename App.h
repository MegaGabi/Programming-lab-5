#pragma once
#include <afxwin.h>

class CApp:public CWinApp
{
public:
	CApp();
	BOOL InitInstance();
	~CApp();
};

CApp app;

