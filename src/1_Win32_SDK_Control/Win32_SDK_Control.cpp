//프로젝트 속성 → Linker → System → SubSystem -> Windows(/SUBSYSTEM:WINDOWS)로 변경 [콘솔을 사용하지 않고 윈도우로 사용하기 위함]
#include <Windows.h>
#include <tchar.h> 


// 윈도우 프로시져
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;   //디바이스 컨텍스트 핸들
	RECT rect; //사각형 구조체
	PAINTSTRUCT ps; //페인트 구조체
	LPCSTR str = _T("Hello, Windows!");
	LPCSTR str2 = _T("좌클릭!!!"); //출력 문자열
	LPCSTR str3 = _T("마우스이동!"); //출력 문자열

	// 커널에 들어온 메시지	처리
	switch (message)
	{
	case WM_CREATE:
		break;// Initialize the window.
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps); //페인트 시작
		TextOut(hdc, 0, 0, str, lstrlen(str)); //문자열 출력
		EndPaint(hWnd, &ps); //페인트 끝
		break;
	/*
	case WM_KEYDOWN:
		hdc = GetDC(hWnd); //디바이스 컨텍스트 핸들 얻기
		GetClientRect(hWnd, &rect); //클라이언트 영역 사각형 얻기
		DrawText(hdc, str2, lstrlen(str2), &rect, DT_CENTER); //문자열 출력
		ReleaseDC(hWnd, hdc); //디바이스 컨텍스트 핸들 해제
		break;
	case WM_KEYUP:
		hdc = GetDC(hWnd); //디바이스 컨텍스트 핸들 얻기
		GetClientRect(hWnd, &rect); //클라이언트 영역 사각형 얻기
		DrawText(hdc, str3, lstrlen(str3), &rect, DT_CENTER); //문자열 출력
		ReleaseDC(hWnd, hdc); //디바이스 컨텍스트 핸들 해제
		break;
		
	*/
	case WM_LBUTTONDOWN:
		hdc = GetDC(hWnd); //디바이스 컨텍스트 핸들 얻기
		GetClientRect(hWnd, &rect); //클라이언트 영역 사각형 얻기
		DrawText(hdc, str2, lstrlen(str2), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER); //문자열 출력
		ReleaseDC(hWnd, hdc); //디바이스 컨텍스트 핸들 해제
		break;
	case WM_LBUTTONUP:
		InvalidateRect(hWnd, NULL, TRUE); //사각형 영역 갱신
		break;
	case WM_MOUSEMOVE:
		hdc = GetDC(hWnd); //디바이스 컨텍스트 핸들 얻기
		GetClientRect(hWnd, &rect); //클라이언트 영역 사각형 얻기
		DrawText(hdc, str3, lstrlen(str3), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER); //문자열 출력
		ReleaseDC(hWnd, hdc); //디바이스 컨텍스트 핸들 해제
		break;
	case WM_DESTROY:
		PostQuitMessage(0); // WM_QUIT 메시지를 보낸다.
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam); // 기본 윈도우 프로시져
	}

}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
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
	return msg.wParam; // 메시지 반환
}


