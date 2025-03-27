#include <Windows.h>
#include <tchar.h> 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	return 0;
	/*
	HWND hWnd; // 윈도우 핸들
	MSG  msg; // 메시지 구조체
	WNDCLASSEX WndClass; // 윈도우 클래스 구조체

	// 윈도우 클래스 구조체 초기화
	WndClass.cbSize = sizeof(WNDCLASSEX); // 윈도우 클래스 크기
	WndClass.style = CS_HREDRAW | CS_VREDRAW; // 윈도우 스타일
	WndClass.lpfnWndProc = WndProc; // 윈도우 프로시져
	WndClass.cbClsExtra = 0; // 윈도우 클래스의 여분 메모리 크기
	WndClass.cbWndExtra = 0; // 윈도우 클래스의 여분 메모리 크기
	WndClass.hInstance = hInstance; // 인스턴스 핸들
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // 아이콘 설정
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); // 커서 설정
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//배경색
	WndClass.lpszMenuName = NULL; // 메뉴 이름
	WndClass.lpszClassName = "Easy Text"; // 클래스 이름
	WndClass.hIconSm = 0;  //아이콘 설정

	// 윈도우 클래스 등록
	RegisterClassEx(&WndClass);

	// 프레임 윈도우 생성 (타이틀바, 메뉴바, 크기변경 가능)
	hWnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, _T("Easy Text"), "Practice1a", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);

	// 윈도우를 화면에 표시
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// 메시지 루프 (메시지 처리)
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); // 키보드 메시지 처리
		DispatchMessage(&msg); // 윈도우 프로시져에 메시지 전달
	}
	*/
	//return msg.wParam; // 메시지 반환
}


