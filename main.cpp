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
using namespace std;
// Пометка к потокам - Взаимная блокировка, Deadlock, Гонка, move-семантика

/*
 * Обработка исключений
 *
 *  Синтаксис:
 *      try
 *      {
 *          <код, который может привести к ошибке>
 *      }
 *      catch(std::logic_error)
 *      {
 *          <действия при ошибке>
 *      }
 *      catch(std::exception)
 *      {
 *          <действия при ошибке>
 *      }
 *      catch(...)
 *      {
 *          <действия при ошибке>
 *      }
 *
 *      catch(...) - это ловля ошибок, которые вы НЕ предсказывали и НЕ можете обработать
 *      throw <создание объекта ошибки> - бросает ошибку <объект ошибки>
 *
 */

int main() // Это главная функция программы - Ее начало и ее конец
{
    // setlocale(LC_ALL, "RUS");
    // setConsoleCP(1251);
    // setConsoleOutputCP(1251);
    try
    {
        vector<int> myVec;
        // myVec.push_back(0);
        if (!(myVec.size() > 10))
            throw std::out_of_range("ТЫ ЗАЧЕМ ВЫШЕЛ ЗА ГРАНИЦУ МАССИВА!");
        cout << myVec[10] << endl;
    }
    catch(std::out_of_range error)
    {
        cout << "Выход за границу массива - " << error.what() << endl;
    }
    catch(std::logic_error error)
    {
        cout << "Произошла какая то логическая ошибка - "  << error.what() << endl;
    }
    catch(std::exception error)
    {
        cout << "Произошла какое то исключение - " << error.what() << endl;
    }
    catch(...)
    {
        cout << "Произошла какая то ошибка" << endl;
    }
    cout << "Hello World" << endl;

    return 0;
}

