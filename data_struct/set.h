#pragma once

#include <iostream>

struct Set
{
    struct SetElement
    {
        int _value = {0};

        SetElement* _before = nullptr;

        SetElement* _left = nullptr;
        SetElement* _right = nullptr;
    };

    int  getValue(                  SetElement* element); // Получение значение элемента
    void setValue(const int& value, SetElement* element); // Задание значения текущему элементу

    bool emplace (const int& value); // Добавляет элемент со значением value в дерево
    bool erase   (const int& value); // Убирает элемнет со значением value из дерева

    bool empty(                ); // Проверка на пустоту
    void clear(                ); // Очистить дерево
    int  size (                ); // Вернуть размер списка
    bool find (const int& value); // Проверяет наличие элемента в дереве. Есть элемент - true, нет - false

    void print();

public:

    SetElement* _root = nullptr;
    int _size = {0};

    bool emplace (SetElement* element, const int& value);
    bool erase   (SetElement* element, const int& value);
    void print   (const SetElement* now);
};

