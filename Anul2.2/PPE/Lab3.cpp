#include "framework.h"
#include "PPE.h"

#define MAX_LOADSTRING 100

HINSTANCE hInst;

WCHAR szWindowClass[MAX_LOADSTRING];

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

// Global
HWND mHwnd;
RECT clientRect, rc;
POINT* ptr = new POINT[4];
POINT* ptr2 = new POINT[4];
int sizeWnd = 800;
int** arr;
int pos = 2;


void setPoints(POINT* ptr, int**& arr) {
     for (int i = 0; i < 4; i++)
          arr[0][i] = ptr[i].x;
     for (int i = 0; i < 4; i++)
          arr[1][i] = ptr[i].y;
}

void PointRotate(POINT*& ptr, int** &arr, int dir) {
     if (dir == 0) {
          for (int i = 0; i < 4; i++) {
               ptr[i].x = arr[1][3 - i];
               ptr[i].y = arr[0][i];
          }
     }
     if (dir == 1) {
          for (int i = 0; i < 4; i++) {
               ptr[i].x = sizeWnd - arr[0][i];
               ptr[i].y = sizeWnd - arr[1][i];
          }
     }
     setPoints(ptr, arr);
};

int Rotate(POINT*& ptr, int** &arr, int dir) {
     if (dir == 6) {
          if (pos == 2) {
               PointRotate(ptr, arr, 0);
               return 6;
          }
          if (pos == 6) {
               PointRotate(ptr, arr, 0);
               PointRotate(ptr, arr, 1);
               return 8;
          }
          if (pos == 8) {
               PointRotate(ptr, arr, 0);
               return 4;
          }
          if (pos == 4) {
               PointRotate(ptr, arr, 1);
               PointRotate(ptr, arr, 0);
               return 2;
          }
     }
     if (dir == 4) {
          if (pos == 2) {
               PointRotate(ptr, arr, 0);
               PointRotate(ptr, arr, 1);
               return 4;
          }
          if (pos == 4) {
               PointRotate(ptr, arr, 0);
               return 8;
          }
          if (pos == 8) {
               PointRotate(ptr, arr, 1);
               PointRotate(ptr, arr, 0);
               return 6;
          }
          if (pos == 6) {
               PointRotate(ptr, arr, 0);
               return 2;
          }
          
     }
};

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
     HWND hWnd = CreateWindowW(szWindowClass, L"> Lab.3 Zavorot Daniel TI-194", WS_MINIMIZEBOX | WS_SYSMENU,
          CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
     SetWindowPos(hWnd, NULL, NULL, NULL, sizeWnd, sizeWnd, NULL);

     if (!hWnd)
     {
          return FALSE;
     }

     mHwnd = hWnd;
     ShowWindow(hWnd, nCmdShow);
     UpdateWindow(hWnd);

     arr = new int* [2];
     for (int i = 0; i < 2; i++)
          arr[i] = new int[4];

     SetTimer(mHwnd, 1000, 1000 / 60, NULL);
     int sizeL = 800;

     for (int i = 0; i < 4; i++) {
          ptr[i].x = (rand() % sizeL) + 1;
          ptr[i].y = (rand() % sizeL) + 1;
     }
     for (int i = 0; i < 4; i++) {
          ptr2[i].x = (rand() % sizeL) + 1;
          ptr2[i].y = (rand() % sizeL) + 1;
     }
     setPoints(ptr, arr);
     

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
     case WM_MOUSEMOVE:
          if (wParam & MK_LBUTTON || wParam & MK_RBUTTON)
          {
               HDC hdc = GetDC(mHwnd);
               HPEN BezierPen2 = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
               SelectObject(hdc, BezierPen2);
               if (wParam & MK_LBUTTON)
               {
                    ptr2[2].x = LOWORD(lParam);
                    ptr2[2].y = HIWORD(lParam);
               }
               if (wParam & MK_RBUTTON)
               {
                    ptr2[3].x = LOWORD(lParam);
                    ptr2[3].y = HIWORD(lParam);
               }
               DeleteObject(BezierPen2);
               ReleaseDC(mHwnd, hdc);
          }
     case WM_PAINT:
     {
          GetClientRect(mHwnd, &clientRect);
          PAINTSTRUCT ps;
          HDC hdc = BeginPaint(hWnd, &ps);
          HBRUSH rectBrush = CreateSolidBrush(RGB(0, 0, 0));
          HPEN darkPen = CreatePen(PS_SOLID, 10, RGB(0, 0, 0));
          HGDIOBJ oldbrush = SelectObject(hdc, rectBrush);
          HGDIOBJ oldpen = SelectObject(hdc, darkPen);

          Rectangle(hdc, clientRect.left, clientRect.top, clientRect.right, clientRect.bottom);

          HPEN BezierPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
          SelectObject(hdc, BezierPen);
          PolyBezier(hdc, ptr, 4);

          HPEN BezierPen2 = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
          SelectObject(hdc, BezierPen2);
          PolyBezier(hdc, ptr2, 4);

          SelectObject(hdc, oldbrush);
          SelectObject(hdc, oldpen);
          DeleteObject(rectBrush);
          DeleteObject(darkPen);
          DeleteObject(BezierPen);
          DeleteObject(BezierPen2);

          EndPaint(hWnd, &ps);
     }
     break;
     case WM_KEYDOWN: {
          switch (LOWORD(wParam))
          {
          case VK_UP: {
               for (int i = 0; i < 4; i++) {
                    ptr[i].y -= 10;
               }
               setPoints(ptr, arr);
               break;
          }

          case VK_DOWN: {
               for (int i = 0; i < 4; i++) {
                    ptr[i].y += 10;
               }
               setPoints(ptr, arr);
               break;
          }

          case VK_LEFT: {
               for (int i = 0; i < 4; i++) {
                    ptr[i].x -= 10;
               }
               setPoints(ptr, arr);
               break;
          }

          case VK_RIGHT: {
               for (int i = 0; i < 4; i++) {
                    ptr[i].x += 10;
               }
               setPoints(ptr, arr);
               break;
          }
          case VK_NUMPAD4: {
               pos = Rotate(ptr, arr, 4);
               break;
          }
          case VK_NUMPAD6: {
               pos = Rotate(ptr, arr, 6);
               break;
          }
          default:
               break;
          }
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
