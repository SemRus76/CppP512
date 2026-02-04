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

/*
 * Задание
 *
 *  В математике существует особый класс чисел, называемый Комплексное множество чисел.
 *  Каждое число из этого множества состоит из пары чисел - real и image - реальное и мнимое
 *
 *  Соответственно существует прописанные способы взаимодействия с такими числа - как проводить операции сложения, вычитания, деления и умножения таких чисел.
 *
 *  Задача - необходимо реализовать класс, который будет представлять собой Комплексное число и будет позволять проводить простые математичекие операции с такими числами, а так же с целыми и дробными, Вводить и Выводить их на консоль, сравнивать между собой
 *
 *  Пример:
 *
 *  (2 + 1i) + (4 - 5i)
 *
 */



using namespace std;

int main() // Это главная функция программы - Ее начало и ее конец
{
    // setlocale(LC_ALL, "RUS");
    // setConsoleCP(1251);
    // setConsoleOutputCP(1251);


    Example obj1("Hello", 2), obj2 ("World", 4);
    Example obj3 = obj1 + obj2;

    !obj1;
    obj1++;
    ++obj1;
    // obj1 + obj2;

    //       std::string
    cout << obj1.getName() << " " << obj2.getName() << endl;
    cout << obj1 + obj2 << endl;

    cout << obj1 << endl;
    cout << obj1[2] << " " << obj1.at(2) << endl;

    // cout << Example::KeepAliveSettingsFile << endl;
    cout << obj1.KeepAliveSettingsFile << endl;
    obj2.KeepAliveSettingsFile = "Hello World";
    cout << obj1.KeepAliveSettingsFile << endl;

    cout << obj3.ClassName() << endl;
    cout << Example::ClassName() << endl;

    return 0;
}

