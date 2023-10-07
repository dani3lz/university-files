#include <windows.h>

LRESULT CALLBACK Action(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = CS_HREDRAW |CS_VREDRAW;
    wc.lpfnWndProc   = Action;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = "myWindowClass";
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc)) {
        return 0;
    }

    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        "myWindowClass",
        " > Lab. 1",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 500,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while(GetMessage(&Msg, NULL, 0, 0) > 0) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}

LRESULT CALLBACK Action(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;
    switch(msg)
    {
    	case WM_PAINT:
    	hdc = BeginPaint(hwnd,&ps);
        GetClientRect(hwnd,&rect);
            SetTextColor(hdc,RGB(255,255,255));
            SetBkMode(hdc,TRANSPARENT);
            DrawText(hdc, "[PPE] Lab. 1 Zavorot Daniel TI-194", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
            EndPaint(hwnd, &ps) ;
    		return 0;
        	case WM_CLOSE:
            	DestroyWindow(hwnd);
        	break;
        	case WM_DESTROY:
            	PostQuitMessage(0);
        	break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
