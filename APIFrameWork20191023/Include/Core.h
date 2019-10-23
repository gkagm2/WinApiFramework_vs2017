#pragma once
#include "Game.h"

class CCore
{
private:
	static CCore* m_pInst; // 싱글톤을 위함. // 프로그램이 시작하면 힙 메모리에 올라갑니다. 힙 메모리가 올라가면 프로그램이 끝날때나 충돌이 나서 종료가 될 떄까지 게속 살아있습니다. 어디서든 접근이 가능합니다.

public:
	static CCore* GetInst() {
		if (!m_pInst) {
			m_pInst = new CCore;
		}
		return m_pInst;
	}
	static void DestroyInst() {
		SAFE_DELETE(m_pInst);
	}

private:
	CCore();
	~CCore();

private:
	static bool m_bLoop;

private:
	HINSTANCE m_hInst;
	HWND m_hWnd;
	RESOLUTION m_tRS;
	

public:
	bool Init(HINSTANCE hInst);
	int Run();

private:
	ATOM MyRegisterClass();
	BOOL Create();

public:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};
