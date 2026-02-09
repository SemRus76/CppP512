#pragma once

#include <iostream>
#include <string>
#include "common.h"

/*
 * Наследование
 *
 *  - это процесс, при котором на базе УЖЕ существующего класса создается новый класс со всеми полями и методами прежнего.
 *
 *      Класс ОТ которого идет наследование называет РОДИТЕЛЬСКИМ
 *      Класс КОТОРЫЙ наследует параметры родительского НАСЛЕДНИКОМ
 *
 *  ВАЖНО - Наследники знают о Родителях все что доступно, Родители НИЧЕГО НЕ ЗНАЮ о наследниках
 *
 *  Синтаксис:
 *
 *      При создании класса наследника:
 *          class <Имя класса наследника> : <модификатор доступа наследования> <Имя класса родителя>
 *          class Inherit : public Parent
 *
 *      ВАЖНО - Для того что бы ЗАПРЕТИТЬ наследования от класса необходимо добавить модификатор
 *          final к его названию
 *          class Parent final  //-> запрещает наследование от Parent
 *          {}
 *
 *      <модификатор доступа наследования> - это модификатор, который говорит под каким доступом будут
 *              у НАСЛЕДНИКА поля и методы РОДИТЕЛЯ
 *      ВАЖНО - В C++ применяется по-умолчанию модификатор доступа наследования private
 *
 *      Модификаторы доступа:
 *
 *      public    - полный доступ из любой части кода
 *      protected - запрещает доступ извне, но разрешает внутри методов класса и наследникам класса
 *      private   - запрет для доступа извне, разрешен только методам класса
 *          |
 *          V
 *      public - Доступно везде
 *      protected - Извне недоступно, но разрешено внутри класса и классам наследникам
 *      private - Извне и классам наследникам недоступно, но разрешено внутри класса
 *
 */

class Parent
{
public:

    Parent();
    ~Parent();

    Parent(const double& value);

    double getValue(                );
    bool   setValue(const int& value);

    friend std::istream& operator>> (std::istream& stream,       Parent& object);
    friend std::ostream& operator<< (std::ostream& stream, const Parent& object);

    static void sayHello();

protected:
    DELETE_COPY_CONSTRUCTOR(Parent)

    double _value;
};

class Inherit : public Parent
{
public:

    Inherit();
    ~Inherit();

    Inherit(const double& real, const double& imagen);

    double getReal(                );
    bool   setReal(const int& value);

    double getImgn(                );
    bool   setImgn(const int& value);

    friend std::istream& operator>> (std::istream& stream,       Inherit& object);
    friend std::ostream& operator<< (std::ostream& stream, const Inherit& object);


private:
    DELETE_COPY_CONSTRUCTOR(Inherit)

    double _imgn;
};


class GrandInherit : public Inherit
{

};







