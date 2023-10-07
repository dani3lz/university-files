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
static HWND hBtn, hNext, hPrev, hFinish, hAgain, radiob1, radiob2, radiob3, check1, check2, check3, check4, check5, check6;
static HWND hEdt1, hEdt2, text1, text2, text3, textA, textP, timer;
static HWND hNota, hTrue, hFalse;
int it, punct = 0;
char StrA[20];
WORD IDC_CHECKBOX_CTRL_ID = 1, IDC_CHECKBOX_CTRL_ID2 = 2, IDC_RADIOBUT = 3;
const UINT_PTR IDT_TIMER1 = 1;
int a, b, Len, notaint, timeleft = 60;
wchar_t notastr[20], timestr[20];
bool check11, check21, check22;

int StrToInt(char* s)
{
     int temp = 0;
     int i = 0;
     int sign = 0;
     if (s[i] == '-')
     {
          sign = 1;
          i++;
     }
     while (s[i] >= 0x30 && s[i] <= 0x39)
     {
          temp = temp + (s[i] & 0x0F);
          temp = temp * 10;
          i++;
     }
     temp = temp / 10;
     if (sign == 1)
          temp = -temp;
     return(temp);
}

void CalcNota() {
     GetWindowText(hEdt1, (LPWSTR)&StrA[0], 5);
     a = StrToInt(StrA);
     GetWindowText(hEdt2, (LPWSTR)&StrA[0], 5);
     b = StrToInt(StrA);
     if (a == 1) punct++;
     if (b == 1) punct++;
     if (check11) punct++;
     if (check21) punct++;
     if (check22) punct++;
     notaint = punct * 2;
     wsprintf(notastr, _T("%d"), notaint);
     SetWindowText(hTrue, notastr);
}

void show() {
     if (it == 0) {
          ShowWindow(hAgain, SW_HIDE);
          ShowWindow(hBtn, SW_SHOWNORMAL);
          ShowWindow(text1, SW_HIDE);
          ShowWindow(text2, SW_HIDE);
          ShowWindow(text3, SW_HIDE);
          ShowWindow(hNota, SW_HIDE);
          ShowWindow(hTrue, SW_HIDE);
          check11 = false;
          check21 = false;
          check22 = false;
          a = 0;
          b = 0;
          punct = 0;
          SendMessage(check1, BM_SETCHECK, BST_UNCHECKED, 0);
          SendMessage(check2, BM_SETCHECK, BST_UNCHECKED, 0);
          SendMessage(check3, BM_SETCHECK, BST_UNCHECKED, 0);
          SendMessage(check4, BM_SETCHECK, BST_UNCHECKED, 0);
          SendMessage(check5, BM_SETCHECK, BST_UNCHECKED, 0);
          SendMessage(check6, BM_SETCHECK, BST_UNCHECKED, 0);

          SendMessage(radiob1, BM_SETCHECK, BST_UNCHECKED, 0);
          SendMessage(radiob2, BM_SETCHECK, BST_UNCHECKED, 0);
          SendMessage(radiob3, BM_SETCHECK, BST_UNCHECKED, 0);

          SetWindowText(hEdt1, L"0");
          SetWindowText(hEdt2, L"0");

          SetWindowText(timer, L"Timpul: 60 secunde.");
     }
     if (it == 1) {
          timeleft = 60;
          SetTimer(mHwnd,
               IDT_TIMER1,
               1000,
               (TIMERPROC)NULL);

          ShowWindow(hBtn, SW_HIDE);
          ShowWindow(hPrev, SW_HIDE);

          ShowWindow(text2, SW_HIDE);
          ShowWindow(check1, SW_HIDE);
          ShowWindow(check2, SW_HIDE);
          ShowWindow(check3, SW_HIDE);
          ShowWindow(check4, SW_HIDE);
          ShowWindow(check5, SW_HIDE);
          ShowWindow(check6, SW_HIDE);

          ShowWindow(text1, SW_SHOWNORMAL);
          ShowWindow(hNext, SW_SHOWNORMAL);
          ShowWindow(radiob1, SW_SHOWNORMAL);
          ShowWindow(radiob2, SW_SHOWNORMAL);
          ShowWindow(radiob3, SW_SHOWNORMAL);
     }
     if (it == 2) {
          ShowWindow(hPrev, SW_SHOWNORMAL);
          ShowWindow(hNext, SW_SHOWNORMAL);

          ShowWindow(text1, SW_HIDE);
          ShowWindow(hFinish, SW_HIDE);
          ShowWindow(radiob1, SW_HIDE);
          ShowWindow(radiob2, SW_HIDE);
          ShowWindow(radiob3, SW_HIDE);

          ShowWindow(text3, SW_HIDE);
          ShowWindow(hEdt1, SW_HIDE);
          ShowWindow(hEdt2, SW_HIDE);
          ShowWindow(textA, SW_HIDE);
          ShowWindow(textP, SW_HIDE);

          ShowWindow(text2, SW_SHOWNORMAL);
          ShowWindow(check1, SW_SHOWNORMAL);
          ShowWindow(check2, SW_SHOWNORMAL);
          ShowWindow(check3, SW_SHOWNORMAL);
          ShowWindow(check4, SW_SHOWNORMAL);
          ShowWindow(check5, SW_SHOWNORMAL);
          ShowWindow(check6, SW_SHOWNORMAL);
     }
     if (it == 3) {
          ShowWindow(hNext, SW_HIDE);
          ShowWindow(hFinish, SW_SHOWNORMAL);

          ShowWindow(text2, SW_HIDE);
          ShowWindow(check1, SW_HIDE);
          ShowWindow(check2, SW_HIDE);
          ShowWindow(check3, SW_HIDE);
          ShowWindow(check4, SW_HIDE);
          ShowWindow(check5, SW_HIDE);
          ShowWindow(check6, SW_HIDE);

          ShowWindow(text3, SW_SHOWNORMAL);
          ShowWindow(hEdt1, SW_SHOWNORMAL);
          ShowWindow(hEdt2, SW_SHOWNORMAL);
          ShowWindow(textA, SW_SHOWNORMAL);
          ShowWindow(textP, SW_SHOWNORMAL);

     }
     if (it == 4) {
          ShowWindow(text2, SW_HIDE);
          ShowWindow(check1, SW_HIDE);
          ShowWindow(check2, SW_HIDE);
          ShowWindow(check3, SW_HIDE);
          ShowWindow(check4, SW_HIDE);
          ShowWindow(check5, SW_HIDE);
          ShowWindow(check6, SW_HIDE);
          ShowWindow(text1, SW_HIDE);
          ShowWindow(hFinish, SW_HIDE);
          ShowWindow(radiob1, SW_HIDE);
          ShowWindow(radiob2, SW_HIDE);
          ShowWindow(radiob3, SW_HIDE);

          CalcNota();
          ShowWindow(hFinish, SW_HIDE);
          ShowWindow(hNext, SW_HIDE);
          ShowWindow(hPrev, SW_HIDE);
          ShowWindow(hAgain, SW_SHOWNORMAL);
          ShowWindow(hNota, SW_SHOWNORMAL);
          ShowWindow(hTrue, SW_SHOWNORMAL);

          KillTimer(mHwnd, IDT_TIMER1);

          ShowWindow(textA, SW_HIDE);
          ShowWindow(textP, SW_HIDE);
          ShowWindow(text3, SW_HIDE);
          ShowWindow(hEdt1, SW_HIDE);
          ShowWindow(hEdt2, SW_HIDE);
     }
}

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
     HWND hWnd = CreateWindowW(szWindowClass, L"> Lab 4-5 Zavorot Daniel TI-194", WS_MINIMIZEBOX | WS_SYSMENU,
          CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
     SetWindowPos(hWnd, NULL, NULL, NULL, 544, 408, NULL);


     if (!hWnd)
     {
          return FALSE;
     }

     mHwnd = hWnd;
     ShowWindow(hWnd, nCmdShow);
     UpdateWindow(hWnd);

     SetTimer(mHwnd, 1000, 1000 / 60, NULL);

     return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

     switch (message)
     {
     case WM_CREATE: {
          hInst = ((LPCREATESTRUCT)lParam)->hInstance;

          hEdt1 = CreateWindow(L"edit", L"0",
               WS_CHILD | WS_BORDER | ES_RIGHT, 215, 128, 62, 20,
               hWnd, 0, hInst, NULL);
          hEdt2 = CreateWindow(L"edit", L"0",
               WS_CHILD | WS_BORDER | ES_RIGHT, 215, 201, 62, 20,
               hWnd, 0, hInst, NULL);

          textA = CreateWindow(L"static", L"Animala:", WS_CHILD | WS_BORDER, 140, 128, 70, 20, hWnd, 0, hInst, NULL);
          textP = CreateWindow(L"static", L"Vegetala:", WS_CHILD | WS_BORDER, 140, 201, 70, 20, hWnd, 0, hInst, NULL);

          hBtn = CreateWindow(L"button", L"Start",
               WS_CHILD | WS_BORDER | WS_VISIBLE,
               142, 162, 237, 62, hWnd, 0, hInst, NULL);
          hNext = CreateWindow(L"button", L"Next >",
               WS_CHILD | WS_BORDER,
               409, 330, 107, 29, hWnd, 0, hInst, NULL);
          hPrev = CreateWindow(L"button", L"< Prev",
               WS_CHILD | WS_BORDER,
               10, 330, 107, 29, hWnd, 0, hInst, NULL);
          hFinish = CreateWindow(L"button", L"FINISH",
               WS_CHILD | WS_BORDER,
               397, 321, 119, 36, hWnd, 0, hInst, NULL);
          hAgain = CreateWindow(L"button", L"Again?",
               WS_CHILD | WS_BORDER,
               189, 267, 118, 38, hWnd, 0, hInst, NULL);

          radiob1 = CreateWindow(L"button", L"R/U",
               WS_CHILD | BS_AUTORADIOBUTTON,
               40, 162, 54, 33, hWnd, 0, hInst, NULL);
          radiob2 = CreateWindow(L"button", L"I/U",
               WS_CHILD | BS_AUTORADIOBUTTON,
               223, 162, 54, 33, hWnd, 0, hInst, NULL);
          radiob3 = CreateWindow(L"button", L"U/I",
               WS_CHILD | BS_AUTORADIOBUTTON,
               422, 162, 54, 33, hWnd, (HMENU)IDC_RADIOBUT, hInst, NULL);

          check1 = CreateWindow(L"button", L"Na2O",
               WS_CHILD | BS_AUTOCHECKBOX,
               39, 126, 83, 33, hWnd, 0, hInst, NULL);
          check2 = CreateWindow(L"button", L"C2H5OH",
               WS_CHILD | BS_AUTOCHECKBOX,
               223, 126, 111, 33, hWnd, (HMENU)IDC_CHECKBOX_CTRL_ID, hInst, NULL);
          check3 = CreateWindow(L"button", L"K2O",
               WS_CHILD | BS_AUTOCHECKBOX,
               422, 126, 71, 33, hWnd, 0, hInst, NULL);
          check4 = CreateWindow(L"button", L"C6H6",
               WS_CHILD | BS_AUTOCHECKBOX,
               39, 198, 82, 33, hWnd, (HMENU)IDC_CHECKBOX_CTRL_ID2, hInst, NULL);
          check5 = CreateWindow(L"button", L"BaSO4",
               WS_CHILD | BS_AUTOCHECKBOX,
               223, 198, 95, 33, hWnd, 0, hInst, NULL);
          check6 = CreateWindow(L"button", L"CaCl2",
               WS_CHILD | BS_AUTOCHECKBOX,
               422, 198, 86, 33, hWnd, 0, hInst, NULL);

          text1 = CreateWindow(L"static", L"Legea 1 a lui Ohm?", WS_CHILD | WS_BORDER, 151, 66, 150, 20, hWnd, 0, hInst, NULL);
          text2 = CreateWindow(L"static", L"Care din aceste elemente fac parte din chimie organica:", WS_CHILD | WS_BORDER, 100, 66, 370, 20, hWnd, 0, hInst, NULL);
          text3 = CreateWindow(L"static", L"Cate nuclee are celula:", WS_CHILD | WS_BORDER, 151, 66, 160, 20, hWnd, 0, hInst, NULL);
          hNota = CreateWindow(L"static", L"Nota: ", WS_CHILD | WS_BORDER, 151, 66, 70, 20, hWnd, 0, hInst, NULL);
          hTrue = CreateWindow(L"static", L"", WS_CHILD | WS_BORDER, 250, 66, 50, 20, hWnd, 0, hInst, NULL);
          timer = CreateWindow(L"static", L"Timpul: 60 secunde.", WS_CHILD | WS_BORDER | WS_VISIBLE, 10, 8, 141, 22, hWnd, 0, hInst, NULL);

          break;
     }
     
     case WM_COMMAND:
          if (lParam == (LPARAM)hBtn)
          {
               it++;
               show();
               break;
          }
          
          if (lParam == (LPARAM)hNext) 
          {
               it++;
               show();
               break;
          }
          
          if (lParam == (LPARAM)hPrev) 
          {
               it--;
               show();
               break;
          }
          if (lParam == (LPARAM)hFinish) 
          {
               it++;
               show();
               break;
          }
          if (lParam == (LPARAM)hAgain)
          {
               it = 0;
               show();
               break;
          }
          if (LOWORD(wParam) == IDC_CHECKBOX_CTRL_ID)
          {
               if (HIWORD(wParam) == BN_CLICKED)
               {
                    LRESULT chkState = SendMessage((HWND)lParam, BM_GETCHECK, 0, 0);
                    if (chkState == BST_CHECKED)
                         check21 = true;
               }
          }
          if (LOWORD(wParam) == IDC_CHECKBOX_CTRL_ID2)
          {
               if (HIWORD(wParam) == BN_CLICKED)
               {
                    LRESULT chkState = SendMessage((HWND)lParam, BM_GETCHECK, 0, 0);
                    if (chkState == BST_CHECKED)
                         check22 = true;
               }
          }
          if (LOWORD(wParam) == IDC_RADIOBUT)
          {
               if (HIWORD(wParam) == BN_CLICKED)
               {
                    LRESULT chkState = SendMessage((HWND)lParam, BM_GETCHECK, 0, 0);
                    if (chkState == BST_CHECKED)
                         check11 = true;
               }
          }
          
     case WM_TIMER:
     {
          switch (wParam)
          {
          case IDT_TIMER1:
               timeleft--;
               wsprintf(timestr, _T("Timpul: %d secunde."), timeleft);
               SetWindowText(timer, timestr);
               if (timeleft == 0) {
                    it = 4;
                    show();
                    KillTimer(mHwnd, IDT_TIMER1);
                    MessageBox(mHwnd, L"TIMPUL A EXPIRAT!", L"LOSE", NULL);

               }
          }
               return 0;
          RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE);
     }
     case WM_PAINT:
     {
          PAINTSTRUCT ps;
          HDC hdc = BeginPaint(hWnd, &ps);

          EndPaint(hWnd, &ps);
          break;
     }
     
     case WM_DESTROY:
          PostQuitMessage(0);
          break;
     default:
          return DefWindowProc(hWnd, message, wParam, lParam);
     }
     return 0;
}

