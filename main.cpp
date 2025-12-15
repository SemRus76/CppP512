// Текст комментариев
#include <iostream> // Подключение библиотеки ввода/вывода
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>
#include <termios.h>
#include <unistd.h>
// #include <Windows.h> // Для русского языка
// #include <conio.h>
// #include <consoleapi2.h>

#include "list.h"
#include "stack.h"
#include "queue.h"
#include "vector.h"
#include "set.h"

using namespace std;

/*
 * Задание на зачет
 *
 * Необходимо создать консольную игру в жанре roguelike
 *
 * Минимальные требования к проекту:
 *
 * - Движение персонажа
 * - Взаимодействие с окружением
 * - Бой
 * - Несколько уровней (уровни должны подгружатся из файлов) - минимум 7 уровней
 *
 *
 * Дополнительные требования:
 *
 * - Система характеристик
 * - Инвентарь и снарежение
 * - Сюжет
 * - Диалоги
 * - Квесты
 * - Сохранения
 *
 */


char getch()
{
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    char c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

int main() // Это главная функция программы - Ее начало и ее конец
{
    // setlocale(LC_ALL, "RUS");
    // setConsoleCP(1251);
    // setConsoleOutputCP(1251);

    cout << "Hello World" << endl;

    // cout << "\033[31mred text\n" << endl;

    std::cout << "Нажмите любую клавишу..." << std::endl;
    char c = getch();
    c = getch();
    std::cout << "\nВы нажали: " << c << std::endl;
    return 0;
}

// int menu(string* strMenu, const int& size)
// {
//     int punctMenu = -1;
//     int nowPunct = 0;
//     HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//     int back = 2, front = 0;
//     while (punctMenu < 0)
//     {
//         for (int i = 0; i < size; ++i)
//         {
//             if (i == nowPunct)
//                 SetConsoleTextAttribute(console, (WORD) back  << 4 | front);
//             else
//                 SetConsoleTextAttribute(console, (WORD) front << 4 | back);

//             cout << strMenu[i] << endl;
//         }

//         int numKey = _getch();
//         if (numKey == 224)
//             numKey = _getch();

//         switch (numKey)
//         {
//         case 72: // Key_UP
//             if (nowPunct == 0)
//                 nowPunct = size - 1;
//             else
//                 --nowPunct;
//             break;
//         case 80: // Key_DOWN
//             if (nowPunct == size - 1)
//                 nowPunct = 0;
//             else
//                 ++nowPunct;
//             break;
//         case 13: // Key_Enter
//             punctMenu = nowPunct;
//             break;
//         default:
//             break;
//         }

//         system("cls");

//     }

//     return punctMenu;
// }



