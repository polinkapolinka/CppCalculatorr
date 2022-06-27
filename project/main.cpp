#include <iostream>
#include <cmath>
 //getch
#include <cstdlib>
#include <string.h> //puts
#include <windows.h>
#import "funcs.h"

LRESULT WINAPI WndProc(HWND, UINT, WPARAM,
                       LPARAM); // функция обработки сообщений окна

// Стартовая функция
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    HWND hwnd;                       // дескриптор окна
    MSG msg;                         // структура сообщения
    WNDCLASS w;                      // структура класса окна
    memset(&w, 0, sizeof(WNDCLASS)); // очистка памяти для структуры
    w.style = CS_HREDRAW | CS_VREDRAW;
    w.lpfnWndProc = WndProc;
    w.hInstance = hInstance;
    w.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(0, 182, 151)));
    w.lpszClassName = "MyClass";
    RegisterClass(&w); // регистрация класса окна
    // Создание окна
    hwnd = CreateWindow(
            "MyClass", "Calculator", //создание и расположение рабочего окна
            WS_OVERLAPPEDWINDOW, 300, 300, 1600, 600, nullptr, nullptr, hInstance, nullptr);
    ShowWindow(hwnd, nCmdShow); // отображение окна
    UpdateWindow(hwnd);         // перерисовка окна
    // Цикл обработки сообщений
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

// Функция обработки сообщений
LRESULT WINAPI WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam) {
    HDC hdc;
    HWND hwnd2;
    HINSTANCE hInst;
    PAINTSTRUCT ps;
    static HWND Button; // дескриптор кнопки
    static HWND Button2;
    static HWND Button3;
    static HWND Button0;
    static HWND Button4;
    static HWND Button5;
    static HWND Button6;
    static HWND Button7;
    static HWND Button8;
    static HWND Button9;
    static HWND Button10;
    static HWND Button11;
    static HWND Button12;
    static HWND Button13;
    static HWND Button14;
    static HWND Button15;
    static HWND Button16;
    static HWND hEdt1, hEdt2, hEdt3, hEdt4, hEdt5, hEdt6, hEdt7, hEdt8,
            hEdt9, hEdt10, hEdt11; // дескрипторы полей редактирования
    static HWND hStat;
    static HWND hStat1;
    static HWND hStat2;
    static HWND hStat3;
    static HWND hStat4;
    static HWND hStat5;
    static HWND hStat6;
    static HWND hStat7;
    static HWND hStat8;
    TCHAR StrA[20];
    int a, b, sum, Len;

    switch (Message) {
        case WM_CREATE: // сообщение создания окна
            hInst = ((LPCREATESTRUCT)lparam)->hInstance;

            hEdt1 =
                    CreateWindow("edit", " ", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
                                 50, 120, 120, 20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hEdt1, SW_SHOWNORMAL);

            hEdt2 =
                    CreateWindow("edit", " ", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
                                 250, 120, 120, 20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hEdt2, SW_SHOWNORMAL);
            hEdt3 =
                    CreateWindow("edit", " ", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
                                 150, 340, 120, 20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hEdt1, SW_SHOWNORMAL);
            hEdt4 =
                    CreateWindow("edit", " ", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
                                 550, 300, 120, 20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hEdt1, SW_SHOWNORMAL);
            hEdt5 =
                    CreateWindow("edit", " ", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
                                 750, 300, 120, 20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hEdt1, SW_SHOWNORMAL);
            hEdt6 =
                    CreateWindow("edit", " ", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
                                 1150, 300, 120, 20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hEdt1, SW_SHOWNORMAL);

            hEdt7 =
                    CreateWindow("edit", " ", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
                                 990, 300, 120, 20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hEdt1, SW_SHOWNORMAL);
            hEdt8 =
                    CreateWindow("edit", " ", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
                                 1350, 70, 120, 20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hEdt1, SW_SHOWNORMAL);
            hEdt9 =
                    CreateWindow("edit", " ", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
                                 1350, 250, 120, 20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hEdt1, SW_SHOWNORMAL);

            hEdt10 =
                    CreateWindow("edit", " ", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
                                 1350, 290, 120, 20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hEdt1, SW_SHOWNORMAL);

            hEdt10 =
                    CreateWindow("edit", " ", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
                                 950, 80, 120, 20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hEdt1, SW_SHOWNORMAL);

            hEdt11 =
                    CreateWindow("edit", " ", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
                                 1070, 80, 120, 20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hEdt1, SW_SHOWNORMAL);

            // Создаем и показываем кнопки
            Button2 = CreateWindow("button", "+", WS_CHILD | WS_VISIBLE | WS_BORDER, 130,
                                   180, 70, 30, hwnd, nullptr, hInst, nullptr);
            Button3 = CreateWindow("button", "-", WS_CHILD | WS_VISIBLE | WS_BORDER, 210,
                                   180, 70, 30, hwnd, nullptr, hInst, nullptr);
            Button4 = CreateWindow("button", "*", WS_CHILD | WS_VISIBLE | WS_BORDER, 290,
                                   180, 70, 30, hwnd, nullptr, hInst, nullptr);
            Button5 = CreateWindow("button", "square", WS_CHILD | WS_VISIBLE | WS_BORDER,
                                   175, 360, 70, 30, hwnd, nullptr, hInst, nullptr);
            Button6 =
                    CreateWindow("button", "password", WS_CHILD | WS_VISIBLE | WS_BORDER,
                                 650, 60, 70, 30, hwnd, nullptr, hInst, nullptr);
            Button7 = CreateWindow("button", "sqrt", WS_CHILD | WS_VISIBLE | WS_BORDER,
                                   550, 330, 70, 30, hwnd, nullptr, hInst, nullptr);
            Button8 = CreateWindow("button", "10", WS_CHILD | WS_VISIBLE | WS_BORDER, 750,
                                   330, 70, 30, hwnd, nullptr, hInst, nullptr);
            Button9 = CreateWindow("button", "2", WS_CHILD | WS_VISIBLE | WS_BORDER, 820,
                                   330, 70, 30, hwnd, nullptr, hInst, nullptr);
            Button10 = CreateWindow("button", "5", WS_CHILD | WS_VISIBLE | WS_BORDER, 890,
                                    330, 70, 30, hwnd, nullptr, hInst, nullptr);
            Button11 = CreateWindow("button", "Log", WS_CHILD | WS_VISIBLE | WS_BORDER,
                                    1100, 330, 70, 30, hwnd, nullptr, hInst, nullptr);

            Button12 = CreateWindow("button", "2", WS_CHILD | WS_VISIBLE | WS_BORDER,
                                    1360, 100, 70, 30, hwnd, nullptr, hInst, nullptr);
            Button13 = CreateWindow("button", "8", WS_CHILD | WS_VISIBLE | WS_BORDER,
                                    1430, 100, 70, 30, hwnd, nullptr, hInst, nullptr);
            Button14 = CreateWindow("button", "4", WS_CHILD | WS_VISIBLE | WS_BORDER,
                                    1500, 100, 70, 30, hwnd, nullptr, hInst, nullptr);
            Button15 =
                    CreateWindow("button", "convert", WS_CHILD | WS_VISIBLE | WS_BORDER,
                                 1400, 320, 70, 30, hwnd, nullptr, hInst, nullptr);
            Button16 = CreateWindow("button", "%", WS_CHILD | WS_VISIBLE | WS_BORDER,
                                    1025, 110, 70, 30, hwnd, nullptr, hInst, nullptr);
            ShowWindow(Button, SW_SHOWNORMAL);
            ShowWindow(Button2, SW_SHOWNORMAL);
            // Создаем и показываем поле текста для результата
            hStat = CreateWindow("static", " ", WS_CHILD | WS_VISIBLE, 125, 260, 200,
                                 20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hStat, SW_SHOWNORMAL);

            hStat1 = CreateWindow("static", " ", WS_CHILD | WS_VISIBLE, 125, 420, 200,
                                  20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hStat, SW_SHOWNORMAL);

            hStat2 = CreateWindow("static", " ", WS_CHILD | WS_VISIBLE, 590, 100, 200,
                                  20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hStat, SW_SHOWNORMAL);

            hStat3 = CreateWindow("static", "0", WS_CHILD | WS_VISIBLE, 550, 390, 100,
                                  20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hStat, SW_SHOWNORMAL);
            hStat4 = CreateWindow("static", "0", WS_CHILD | WS_VISIBLE, 750, 390, 100,
                                  20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hStat, SW_SHOWNORMAL);
            hStat5 = CreateWindow("static", "0", WS_CHILD | WS_VISIBLE, 1080, 390, 100,
                                  20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hStat, SW_SHOWNORMAL);

            hStat6 = CreateWindow("static", "0", WS_CHILD | WS_VISIBLE, 1350, 170, 120,
                                  20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hStat, SW_SHOWNORMAL);
            hStat7 = CreateWindow("static", "0", WS_CHILD | WS_VISIBLE, 1350, 400, 120,
                                  20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hStat, SW_SHOWNORMAL);
            hStat8 = CreateWindow("static", "0", WS_CHILD | WS_VISIBLE, 1010, 180, 120,
                                  20, hwnd, nullptr, hInst, nullptr);
            ShowWindow(hStat, SW_SHOWNORMAL);

        case WM_COMMAND: // сообщение о команде
            if (lparam == (LPARAM)Button4) {
                Len = GetWindowText(hEdt1, StrA, 20);
                a = StrToInt(StrA);
                Len = GetWindowText(hEdt2, StrA, 20);
                b = StrToInt(StrA);
                sum = Mult(a, b);
                SetWindowText(hStat, IntToStr(sum));
            }

            if (lparam == (LPARAM)Button2) {
                Len = GetWindowText(hEdt1, StrA, 20);
                a = StrToInt(StrA);
                Len = GetWindowText(hEdt2, StrA, 20);
                b = StrToInt(StrA);
                sum = Summ(a, b);
                SetWindowText(hStat, IntToStr(sum));
            }
            if (lparam == (LPARAM)Button3) {
                Len = GetWindowText(hEdt1, StrA, 20);
                a = StrToInt(StrA);
                Len = GetWindowText(hEdt2, StrA, 20);
                b = StrToInt(StrA);
                sum = Diff(a, b);
                SetWindowText(hStat, IntToStr(sum));
            }

            if (lparam == (LPARAM)Button5) {
                Len = GetWindowText(hEdt3, StrA, 20);
                a = StrToInt(StrA);
                sum = Square(a);
                SetWindowText(hStat1, IntToStr(sum));
            }
            if (lparam == (LPARAM)Button6) {
                Len = GetWindowText(hEdt3, StrA, 20);
                a = StrToInt(StrA);
                sum = Rnd();
                SetWindowText(hStat2, IntToStr(sum));
            }
            if (lparam == (LPARAM)Button7) {
                Len = GetWindowText(hEdt4, StrA, 20);
                a = StrToInt(StrA);
                sum = std::sqrt(a);
                SetWindowText(hStat3, IntToStr(sum));
            }
            if (lparam == (LPARAM)Button8) // если нажали на кнопку
            {
                Len = GetWindowText(hEdt5, StrA, 20);
                a = StrToInt(StrA);
                sum = std::log(a) / log(10);
                SetWindowText(hStat4, IntToStr(sum));
            }
            if (lparam == (LPARAM)Button9) {
                Len = GetWindowText(hEdt5, StrA, 20);
                a = StrToInt(StrA);
                sum = std::log(a) / log(2);
                SetWindowText(hStat4, IntToStr(sum));
            }
            if (lparam == (LPARAM)Button10) {
                Len = GetWindowText(hEdt5, StrA, 20);
                a = StrToInt(StrA);
                sum = std::log(a) / log(5); // находим логарифм 5
                SetWindowText(hStat4, IntToStr(sum));
            }
            if (lparam == (LPARAM)Button11) {
                Len = GetWindowText(hEdt7, StrA, 20);
                a = StrToInt(StrA);
                Len = GetWindowText(hEdt6, StrA, 20);
                b = StrToInt(StrA);
                sum = Loga_b(a, b); // находим логарифм
                SetWindowText(hStat5, IntToStr(sum));
            }
            if (lparam == (LPARAM)Button12) {
                Len = GetWindowText(hEdt8, StrA, 20);
                a = StrToInt(StrA); //
                sum = from10to2(a); // переводим из 10-чной в 2
                SetWindowText(hStat6, IntToStr(sum));
            }
            if (lparam == (LPARAM)Button13) {
                Len = GetWindowText(hEdt8, StrA, 20);
                a = StrToInt(StrA); //
                sum = from10to8(a); //переводим из 10-чной в 8
                SetWindowText(hStat6, IntToStr(sum));
            }
            if (lparam == (LPARAM)Button14) {
                Len = GetWindowText(hEdt8, StrA, 20);
                a = StrToInt(StrA); //
                sum = from10to4(a); // переводим из 10-чной в 4
                SetWindowText(hStat6, IntToStr(sum));
            }
            if (lparam == (LPARAM)Button15) {
                Len = GetWindowText(hEdt9, StrA, 20);
                a = StrToInt(StrA); //
                Len = GetWindowText(hEdt10, StrA, 20);
                b = StrToInt(StrA);       //
                sum = from10toyour(a, b); // переводим из 10-чной в заданную пользователем
                SetWindowText(hStat7, IntToStr(sum)); //
            }
            if (lparam == (LPARAM)Button16) {
                Len = GetWindowText(hEdt10, StrA, 20);
                a = StrToInt(StrA);
                Len = GetWindowText(hEdt11, StrA, 20);
                b = StrToInt(StrA);
                sum = Persent(a, b); // находим процент по функции
                SetWindowText(hStat8, IntToStr(sum));
            }

            break;
        case WM_PAINT:                 // перерисовка окна
            hdc = BeginPaint(hwnd, &ps); // начало перерисовки
            TextOut(hdc, 180, 30, "Calculator", 10); // вывод текстовых сообщений
            TextOut(hdc, 180, 230, "Result:", 8);
            TextOut(hdc, 40, 100, "Enter first number:", 20);
            TextOut(hdc, 240, 100, "Enter second number:", 20);
            TextOut(hdc, 180, 300, "Square:", 8);
            TextOut(hdc, 180, 400, "Result:", 8);
            TextOut(hdc, 600, 30, "Come up with a password:", 23);
            TextOut(hdc, 550, 230, "Sqrt:", 5);
            TextOut(hdc, 550, 365, "Result:", 8);
            TextOut(hdc, 550, 270, "Enter argument:", 16);
            TextOut(hdc, 750, 230, "Log:", 5);
            TextOut(hdc, 750, 270, "Enter argument:", 16);
            TextOut(hdc, 750, 365, "Result:", 8);
            TextOut(hdc, 1070, 230, "Your Base Log:", 14);
            TextOut(hdc, 990, 270, "Enter argument:", 16);
            TextOut(hdc, 1150, 270, "Enter base:", 12);
            TextOut(hdc, 1100, 370, "Result:", 8);
            TextOut(hdc, 1350, 30, "Number systems:", 16);
            TextOut(hdc, 1350, 50, "From 10:", 8);
            TextOut(hdc, 1350, 140, "Result:", 6);
            TextOut(hdc, 1350, 200, "From 10 to your:", 16);
            TextOut(hdc, 1350, 230, "Enter number:", 14);
            TextOut(hdc, 1350, 272, "Enter base:", 12);
            TextOut(hdc, 1350, 380, "Result:", 6);
            TextOut(hdc, 1000, 30, "Percentages", 10);
            TextOut(hdc, 950, 50, "Enter number:", 14);
            TextOut(hdc, 1070, 50, "Enter persent:", 14);
            TextOut(hdc, 1050, 160, "Result:", 6);
            TextOut(hdc, 550, 460, "All results are integer only!", 29);

            EndPaint(hwnd, &ps); // конец перерисовки
            break;
        case WM_DESTROY: // закрытие окна
            PostQuitMessage(0);
            break;
        default: // обработка сообщения по умолчанию
            return DefWindowProc(hwnd, Message, wparam, lparam);
    }
    return 0;
}
