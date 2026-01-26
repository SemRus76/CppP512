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
// #include <Windows.h> // Для русского языка
// #include <conio.h>
// #include <consoleapi2.h>

#include "list.h"
#include "stack.h"
#include "queue.h"
#include "vector.h"
#include "set.h"

#include "OOP/example.h"

#define STR_HELLO "Hello World"

using namespace std;

int main() // Это главная функция программы - Ее начало и ее конец
{
    // setlocale(LC_ALL, "RUS");
    // setConsoleCP(1251);
    // setConsoleOutputCP(1251);


    Example obj1, obj2;
    Example obj3 = Example("name");
    // Example obj4 = Example(obj3);
    Example* obj_ptr = new Example();
    Example* obj_n_ptr = move(obj_ptr);

    obj1.setName("Hello");
    obj2.setName("World");

    cout << obj1.getName() << " " << obj2.getName() << endl;

    // cout << obj1._name << " " << obj2._name << endl;
    delete obj_ptr;
    return 0;
}

