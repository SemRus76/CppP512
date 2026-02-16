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

#include "abastract_class.h"
#include "multiple_inheritce.h"

#define STR_HELLO "Hello World"

using namespace std;

int main() // Это главная функция программы - Ее начало и ее конец
{
    // setlocale(LC_ALL, "RUS");
    // setConsoleCP(1251);
    // setConsoleOutputCP(1251);

    Weapon* gun = new MachinGun();
    gun->fire();
    gun->fire();
    gun->fire();
    gun->fire();
    gun->fire();
    gun->fire();
    gun->fire();
    delete gun;
    gun = new SniperGun();
    gun->fire();
    gun->fire();
    gun->fire();
    gun->fire();
    gun->reload();
    gun->fire();
    gun->fire();
    delete gun;
    gun = new Pistol();
    gun->fire();
    gun->fire();
    gun->fire();
    gun->fire();
    gun->fire();
    delete gun;
    cout << "-===================-" << endl;
    // gun = new Weapon(1);
    // gun->fire();
    // gun->fire();

    Third obj;
    obj.sayDIE();

    return 0;
}

