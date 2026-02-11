// Текст комментариев
#include <iostream> // Подключение библиотеки ввода/вывода
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
// #include <cstdlib>
#include <math.h>
#include <termios.h>
#include <unistd.h>
#include <vector>
#include <list>
// #include <Windows.h> // Для русского языка
// #include <conio.h>
// #include <consoleapi2.h>

#include "list.h"
#include "stack.h"
#include "queue.h"
#include "vector.h"
#include "set.h"

#include "OOP/example.h"
#include "OOP/template_class.h"
#include "OOP/inheritance.h"

#define STR_HELLO "Hello World"

using namespace std;

template <typename Type1, typename Type2>
Type1 summer (const Type1& First, const Type2& Second)
{
    return First + Second;
}

int main() // Это главная функция программы - Ее начало и ее конец
{
    // setlocale(LC_ALL, "RUS");
    // setConsoleCP(1251);
    // setConsoleOutputCP(1251);

    Parent* obj = new Inherit();

    Inherit* iObj = static_cast<Inherit*>(obj);

    cout << obj->getName() << endl;
    cout << iObj->getName() << endl;

    delete obj;

    return 0;
}

