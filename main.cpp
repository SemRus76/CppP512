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
#include <stdexcept>
#include <cerrno>

// #include <Windows.h> // Для русского языка
// #include <conio.h>
// #include <consoleapi2.h>
#include <vector>
#include <memory>
// #include "OOP/example.h"
using namespace std;
// Пометка к потокам - Взаимная блокировка, Deadlock, Гонка, move-семантика

/*
 *  Умные указатели - Smart Pointer's
 *
 *      * - система оберток вокруг привычных "сырых" указателей, которая служит для автоматической вычистки памяти, в случае уничтожения объекта (RAII)
 *
 *  Виды умных указателей:
 *
 *      1. auto_ptr<Type> - максимально простой и тупой указатель, служащий для хранения и уничтожения объекта - deprecated
 *
 *          Методы:
 *              get() - возвращает "сырой" указатель на объект внутри auto_ptr
 *              release() - возвращает "сырой" указатель на объект внутри auto_ptr И вычищает указатель внутри auto_ptr
 *              reset(Type* ptr) - заменяет указатель внутри auto_ptr на ptr
 *
 *      2. unique_ptr<Type>
 *      3. shared_ptr<Type>
 *      4. weak_ptr<Type>
 *
 *  ВАЖНО - НИ ОДИН Smart Pointer НЕ создает объект при создании себя.
 *
 *      std::make_unique(<объект>) - помещает <объект> в unique_ptr и вернет его для использования
 *      std::make_shared(<объект>) - помещает <объект> в shared_ptr и вернет его для использования
 *
 */

void func (int number, string* str)
{
    weak_ptr<string> ptr = std::make_shared<string>(*str);
    if (number < 5)
        func(number + 1, str);
}

int main() // Это главная функция программы - Ее начало и ее конец
{
    // setlocale(LC_ALL, "RUS");
    // setConsoleCP(1251);
    // setConsoleOutputCP(1251);

    unique_ptr<string> unPtr;
    unPtr.reset(new string("Hello World"));
    unique_ptr<string> unPtr2(new string("Hi"));
    unPtr.swap(unPtr2);

    cout << *unPtr2 << endl;
    cout << *unPtr << endl;

    cout << "-====================-" << endl;

    shared_ptr<string> shPtr(new string("Hello World"));
    shared_ptr<string> shPtr2(shPtr);

    cout << shPtr << endl << shPtr2 << endl;
    cout << shPtr.use_count() << endl;
    cout << shPtr2.use_count() << endl;
    shPtr2.reset();
    cout << shPtr.use_count() << endl;

    cout << "-====================-" << endl;

    func(0, new string("Number"));

    return 0;
}

