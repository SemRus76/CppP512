#pragma once
#include <iostream>
#include <vector>
#include <string>

/*
 * Объектно-Ориентированное Программирование
 *
 *  1. Инкапсуляция
 *  2. Сокрытие
 *  3. Наследование
 *  4. Полиморфизм
 *  5. Абстракция
 *
 *  Класс - это описание того, как нужно создавать объекты и из чего они будут состоять.
 *      Внутри классов существуют следующие вещи:
 *          1. Поля - переменные внутри объекта класса
 *          2. Методы - функции внутри объекта класса
 *
 *  Сокрытие - Модификаторы доступа:
 *
 *      public - Открывает полный доступ извне к Методу или Полю
 *          Поля и Методы доступны везде
 *
 *      private - Закрывает любой доступ извне к Методу или Полю
 *          Поля и Методы недоступны извне, но доступны внутри класса
 *
 *      protected -> Наследование
 *
 *   ВАЖНО - Классы по умолчанию имеют модификатор доступа private
 *   ВАЖНО - Модификаторы работают по принципу от себя и ниже до конца и их может скольугодно
 *      много
 *   ВАЖНО - поля класса ВСЕГДА должны быть скрыты от внешнего воздействия
 *
 */

/*
 * Конструкторы и Деструкторы
 *
 *  Конструктор - это особый метод класса, который описывает процесс создания объекта класса
 *
 *  Деструктор - это особый метод класса, который описывает процесс разрушения объекта класса
 *
 *  ВАЖНО - Особенность этих двух (видов) методов заключается в их названии - они ВСЕГДА называются так же, как и класс
 *
 *  Виды конструкторов:
 *
 *      1. Конструктор по-умолчанию - конструктор, который ничего не принимает и просто позволяет проинициализировать объект класса
 *
 *      2. Конструктор с параметром - конструктор, который принимает один или несколько параметров и передает их в поля
 *
 *      3. Делегирующий Конструктор - конструктор, который не описывает сам процесс создания, а только делегирует (передает) его другому более сложному конструктору
 *
 *      4. Два конструктора Копирования - конструкторы, которые собирают объект на основе другого объекта класса (по-простому создают копию объекта)
 *
 *
 *  Правило 4-or-0:
 *
 *      Вы ВСЕГДА либо перегружаете ВСЕ конструкторы копирования, либо не перегружаете ни один
 *
 */

/*
 * Операторы
 *
 *  Оператор - то ЧТО делается
 *  Операнды - то НАД ЧЕМ делается
 *
 *  <операнд_1> <оператор> <операнд_2> -> <операнд_1>.<оператор>(<операнд_2>);
 *
 *  <возвращаемое значение> operator<знак оператора>(<принимаемый операнд>);
 *
 *  Операторы деляться на группы по количеству операндов:
 *
 *      Унарные:
 *
 *          Логическое НЕ - ! - Example operator! () const -> Должен возвращать объект класса ОБРАТНЫЙ к существующему
 *
 *          Инкремент - ++ -> Префиксная форма:  Example& operator++ (   )
 *                            Постфиксная форма: Example  operator++ (int)
 *
 *          Декремент - -- -> Префиксная форма:  Example& operator-- (   )
 *                            Постфиксная форма: Example  operator-- (int)
 *
 *          int& operator[] (const int& index) - Индексатор - НЕ безопастно - Быстрее
 *          int& at         (const int& index) - Индексатор - Безопастно    - Медленнее
 *
 *      Бинарные:
 *
 *          Логические операторы:
 *
 *              Равно            - == - bool operator==(const Example&) const
 *              Не равно         - != - bool operator!=(const Example&) const
 *              Больше           -  > - bool operator> (const Example&) const
 *              Больше или равно - >= - bool operator>=(const Example&) const
 *              Меньше           -  < - bool operator< (const Example&) const
 *              Меньше или равно - <= - bool operator<=(const Example&) const
 *
 *          Правило 6-or-0:
 *              Вы ВСЕГДА либо перегружаете ВСЕ логические операторы, либо не перегружаете ни один
 *
 *
 *          Математические операторы:
 *
 *              Сложение           - + - Example operator+ (const Example&) const
 *              Вычитание          - - - Example operator- (const Example&) const
 *              Умножение          - * - Example operator* (const Example&) const
 *              Деление            - / - Example operator/ (const Example&) const
 *              Остаток от деления - % - Example operator% (const Example&) const
 *
 *          Операторы равно:
 *
 *              Равно                         -  = - Example& operator=   (const Example&);
 *              Сложить и приравнять          - += - Example& operator+=  (const Example&);
 *              Вычесть и приравнять          - -= - Example& operator-=  (const Example&);
 *              Умножить и приравнять         - *= - Example& operator*=  (const Example&);
 *              Разделить и приравнять        - /= - Example& operator/=  (const Example&);
 *              Получить остаток и приравнять - %= - Example& operator%=  (const Example&);
 *
 *          Операторы потокового Ввода/Вывода:
 *
 *              friend std::istream& operator>> (std::istream& stream, Example& object);
 *              friend std::ostream& operator<< (std::ostream& stream, Example& object);
 *
 */

/*
 * Дружественные функции - friend function
 *
 *      Дружественные функции - это функции-члены класса, тела которых могут быть реализованы ВНЕ класса.
 *
 *      ВАЖНО - Друзьям мы доверим даже то, что родным не всегда расскажем.
 *      АРХИВАЖНО (!!!!ALARM!!!!) - Дружественные функции имеют ПОЛНЫЙ ДОСТУП к объектам класса.
 *
 */

/*
 *  Статические методы и поля класса - static
 *
 *      Статические методы и поля класса - это методы и поля, которые могут быть вызванны БЕЗ объекта этого класса.
 *
 *      Синтаксис:
 *          inline static <поле класса>;
 *          inline static const <поле класса> = <значение для поля>;
 *
 *          static <метод класса>;
 *
 *      Статические поля - это поля, значения которых существуют не в конкретном объекте, а во всех объектах класса одновременно.
 *      Статические методы - это методы класса, для вызова которых НЕ НУЖЕН объект класса. То есть их можно вызывать прямо <имя класса>::<имя метода>
 *
 */

class Example
{
public:

     Example             (                                          ) = default; // Конструктор класса по-умолчанию
     Example             (const std::string& name                   )          ; // Делегирующий Конструктор
     Example             (const std::string& name, const int& number)          ; // Конструктор с параметром
     Example             (const Example&                            )          ; // Конструктор копирования на lvalue
     Example& operator=  (const Example&                            )          ;
     Example             (const Example&&                           )          ; // Конструктор копирования на rvalue
     Example& operator=  (const Example&&                           )          ;
    ~Example             (                                          )          ; // Деструктор класса

    // Операторы
    Example  operator!  (   ) const; // Логическое НЕ
    Example& operator++ (   )      ; // Префиксная форма Инкремента
    Example  operator++ (int)      ; // Постфиксная форма Инкремента
    Example& operator-- (   )      ; // Префиксная форма Декремента
    Example  operator-- (int)      ; // Постфиксная форма Декремента

    bool operator== (const Example&) const; // Равно
    bool operator!= (const Example&) const; // Не равно
    bool operator>  (const Example&) const; // Больше
    bool operator>= (const Example&) const; // Больше или равно
    bool operator<  (const Example&) const; // Меньше
    bool operator<= (const Example&) const; // Меньше или равно

    Example operator+ (const Example&) const; // Сложение
    Example operator- (const Example&) const; // Вычитание
    Example operator* (const Example&) const; // Умножение
    Example operator/ (const Example&) const; // Деление
    Example operator% (const Example&) const; // Остаток от деления

    // Example& operator=  (const Example&); // Равно
    Example& operator+= (const Example&); // Сложить и приравнять
    Example& operator-= (const Example&); // Вычесть и приравнять
    Example& operator*= (const Example&); // Умножить и приравнять
    Example& operator/= (const Example&); // Разделить и приравнять
    Example& operator%= (const Example&); // Получить остаток и приравнять

    friend std::istream& operator>> (std::istream& stream, Example& object);
    friend std::ostream& operator<< (std::ostream& stream, Example& object);

    int& operator[] (const int& index); // Индексатор - НЕ безопастно - Быстрее
    int& at         (const int& index); // Индексатор - Безопастно    - Медленнее

    void        setName (const std::string& name)      ; // Метод класса
    std::string getName (                       ) const; // Константный метод класса

    inline static std::string KeepAliveSettingsFile = "/etc/keepalived/keepalived.conf"; // Статическое поле

    static std::string ClassName(); // Статическое поле

private:

    std::string      _name        ; // Поле класса
    int              _number = {0}; // Поле класса
    std::vector<int> _vec         ; // Поле класса

};




