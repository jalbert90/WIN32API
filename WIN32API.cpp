#include <Windows.h>

LRESULT CALLBACK WindowsProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void OnSize(HWND hwnd, UINT flag, int width, int height);

_Use_decl_annotations_ int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmd, int nCmdShow) {

	wchar_t CLASS_NAME[] = L"My first window class";
	WNDCLASS wd = {};
	wd.lpfnWndProc = WindowsProc;
	wd.hInstance = hInstance;
	wd.lpszClassName = CLASS_NAME;

	RegisterClass(&wd);

	// Create window instance...
	HWND hwnd = CreateWindowEx(0, CLASS_NAME, L"My first window instance", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	if (hwnd == NULL) {
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);

	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
	

	return 0;
}

LRESULT CALLBACK WindowsProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_SIZE:
	{
		int width = LOWORD(lParam);
		int height = HIWORD(lParam);

		OnSize(hwnd, (UINT)wParam, width, height);
	}
	break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	}

	return 0;
}

void OnSize(HWND hwnd, UINT flag, int width, int height) {
	//
}