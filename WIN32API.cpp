#include <Windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) 
{
	const wchar_t CLASS_NAME[] = L"My First Window Class";

	WNDCLASS wc = { 0 };

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	//Create a new instance of a window.


	return 0;
}