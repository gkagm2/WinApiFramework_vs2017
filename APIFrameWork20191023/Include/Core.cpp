#include "Core.h"

CCore* CCore::m_pInst = NULL;
bool CCore::m_bLoop = true;

CCore::CCore()
{
}


CCore::~CCore()
{
}

bool CCore::Init(HINSTANCE hInst)
{
	m_hInst = hInst;

	MyRegisterClass();

	// �ػ� ����
	m_tRS.iW = 1280;
	m_tRS.iH = 720;

	Create();
	return true;
}

int CCore::Run()
{
	MSG msg;

	// �⺻ �޽��� �����Դϴ�:
	while (m_bLoop)
	{

		// PeekMessage�� �޼����� �޼���ť�� ��� �ٷ� ���� ���´�.
		// �޼����� ���� ��� True, ���� ��� False�� �ȴ�. �޼����� ���� �ð��� �������� ����Ÿ���̴�.

		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else { // �������� ����Ÿ���� ���.
		}
	}
	return (int)msg.wParam;
}

ATOM CCore::MyRegisterClass()
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = CCore::WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_hInst;
	wcex.hIcon = LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL; // MAKEINTRESOURCEW(IDC_WIN32GAMETEST);
	wcex.lpszClassName = L"AR13API";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

	return RegisterClassExW(&wcex);
}

BOOL CCore::Create()
{
	m_hWnd = CreateWindowW(L"AR13API", L"AR13API Titile", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, m_hInst, nullptr);

	if (!m_hWnd)
	{
		return FALSE;
	}

	// ���� ������ Ÿ��Ʋ�ٳ� �޴��� ������ �������� ũ�⸦ �����ش�.
	RECT rc = { 0, 0, m_tRS.iW, m_tRS.iH};
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	// HWND_TOPMOST�� â���߿� ���� �ֻ�ܿ� ����	
	SetWindowPos(m_hWnd, HWND_TOPMOST, 100, 100, rc.right - rc.left, rc.bottom - rc.top, SWP_NOMOVE | SWP_NOZORDER);
	// ������ ������ ũ��� �����츦 Ŭ���̾�Ʈ ������ ũ�⸦ ���ϴ� ũ��� ������� �Ѵ�.

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	return TRUE;
}

LRESULT CCore::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN: // ���콺 ���� ��ư�� ������ �� ���´�.

		break;
	case WM_MOUSEMOVE: // ���콺�� ������ �� ������ �޽����̴�.

		break;
	case WM_LBUTTONUP: // ���콺 ���� ��ư�� ���� ���¿��� �� �� ���´�.

		break;

	case WM_KEYDOWN: // Ű�� ������ ��� ������ �޼����̴�.
		// �� �޼����� ���� ��� wParam�� � Ű�� ���������� ���´�.
		switch (wParam) {
		case VK_ESCAPE:
			DestroyWindow(hWnd);
			break;
		}

		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
	
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY: // �����츦 �����ų �� ������ �޼����̴�.		
		m_bLoop = false;
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
