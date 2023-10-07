#include "framework.h"
#include "PPE.h"

#define MAX_LOADSTRING 100

HINSTANCE hInst;

WCHAR szWindowClass[MAX_LOADSTRING];

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
HWND mHwnd;
RECT clientRect;
RECT objRect;
bool border = true;
int sizeLeft, sizeRight, sizeTop, sizeBottom;
int sizeLeft1, sizeRight1, sizeTop1, sizeBottom1;
int arctop, arcleft, arcright, arcbottom;
int it;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
     _In_opt_ HINSTANCE hPrevInstance,
     _In_ LPWSTR    lpCmdLine,
     _In_ int       nCmdShow)
{
     UNREFERENCED_PARAMETER(hPrevInstance);
     UNREFERENCED_PARAMETER(lpCmdLine);

     LoadStringW(hInstance, IDC_PPE, szWindowClass, MAX_LOADSTRING);
     MyRegisterClass(hInstance);

     if (!InitInstance(hInstance, nCmdShow))
     {
          return FALSE;
     }

     HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PPE));

     MSG msg;

     while (GetMessage(&msg, nullptr, 0, 0))
     {
          if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
          {
               TranslateMessage(&msg);
               DispatchMessage(&msg);
          }
     }

     return (int)msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
     WNDCLASSEXW wcex;

     wcex.cbSize = sizeof(WNDCLASSEX);

     wcex.style = CS_HREDRAW | CS_VREDRAW;
     wcex.lpfnWndProc = WndProc;
     wcex.cbClsExtra = 0;
     wcex.cbWndExtra = 0;
     wcex.hInstance = hInstance;
     wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_PPE));
     wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
     wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
     wcex.lpszMenuName = 0;
     wcex.lpszClassName = szWindowClass;
     wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

     return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
     hInst = hInstance;
     HWND hWnd = CreateWindowW(szWindowClass, L"> Lab.2", WS_OVERLAPPEDWINDOW,
          CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
     SetWindowPos(hWnd, NULL, NULL, NULL, 250, 370, NULL);

     if (!hWnd)
     {
          return FALSE;
     }

     mHwnd = hWnd;
     ShowWindow(hWnd, nCmdShow);
     UpdateWindow(hWnd);

     SetTimer(mHwnd, 1000, 1000 / 60, NULL);
     sizeLeft = 30;
     sizeRight = sizeLeft + 5;
     sizeTop = 5;
     sizeBottom = sizeLeft * 2;

     sizeLeft1 = 80;
     sizeRight1 = sizeLeft1 - 45;
     sizeTop1 = 5;
     sizeBottom1 = sizeLeft1 + 30;

     arctop = 5;
     arcleft = 230;
     arcright = 35;
     arcbottom = arcleft + 30;

     return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
     switch (message)
     {
     case WM_TIMER:
     {
          RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
     }
     case WM_PAINT:
     {
          GetClientRect(mHwnd, &clientRect);

          PAINTSTRUCT ps;
          HDC hdc = BeginPaint(hWnd, &ps);

          HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
          HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
          HPEN darkPen = CreatePen(PS_SOLID, 10, RGB(0, 0, 0));
          HPEN darkLightPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
          HGDIOBJ oldbrush = SelectObject(hdc, blueBrush);
          HGDIOBJ oldpen = SelectObject(hdc, darkPen);
          Rectangle(hdc, clientRect.left, clientRect.top, clientRect.right, clientRect.bottom);

          SelectObject(hdc, darkLightPen);
          SelectObject(hdc, redBrush);

          if (border) {
               sizeTop++; sizeRight++;
               sizeTop1++; sizeRight1++;
               arctop++; arcright++;
          }
          else {
               sizeTop--; sizeRight--;
               sizeTop1--; sizeRight1--;
               arctop--; arcright--;
          }

          if (sizeRight >= clientRect.right - 5) border = false;
          if (sizeTop <= clientRect.left + 5) border = true;

          Rectangle(hdc, sizeTop, sizeLeft, sizeRight, sizeBottom);
          Ellipse(hdc, sizeTop1, sizeLeft1, sizeRight1, sizeBottom1);
          RoundRect(hdc, sizeTop, sizeLeft + 100, sizeRight, sizeBottom + 100, 10, 10);
          Chord(hdc, sizeTop1, sizeLeft1 + 100, sizeRight1, sizeBottom1 + 100, sizeTop1, sizeLeft1 + 100, sizeTop1, sizeLeft1 + 100);

          Arc(hdc, arctop, arcleft, arcright, arcbottom, arctop, arcleft, arctop, arcleft);
          Pie(hdc, arctop, arcleft + 50, arcright, arcbottom + 50, arctop, arcleft + 50, arctop, arcleft + 50);

          SelectObject(hdc, oldbrush);
          SelectObject(hdc, oldpen);
          DeleteObject(blueBrush);
          DeleteObject(darkPen);
          DeleteObject(redBrush);
          DeleteObject(darkLightPen);

          EndPaint(hWnd, &ps);
     }
     break;
     case WM_DESTROY:
          PostQuitMessage(0);
          break;
     default:
          return DefWindowProc(hWnd, message, wParam, lParam);
     }
     return 0;
}
