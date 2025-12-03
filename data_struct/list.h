#pragma once

struct List
{
    struct ListElement
    {
        int _value = {0};

        ListElement* _back = {nullptr};
        ListElement* _next = {nullptr};
    };

    int  getValue(                  ListElement* element); // Получение значение элемента
    void setValue(const int& value, ListElement* element); // Задание значения текущему элементу

    bool push_back (const int& value); // Добавить новый элемент в конец с значением value
    bool push_front(const int& value); // Добавить новый элемент в начало с значением value

    bool pop_back (); // Удалить последний элемент
    bool pop_front(); // Удалить первый элемент

    bool insert(const int& position, const int& value); // Добавить элемент в позицию следующую за position со значем value
    bool erase (const int& position                  ); // Удалить элемент на позиции position

    bool empty(); // Проверка на пустоту
    void clear(); // Очистить список
    int  front(); // Вернуть значение первого элемента
    int  back (); // Вернуть значение последнего элемента

    int  size(                                                                ); // Вернуть размер списка
    bool swap(ListElement* first, ListElement* second, const bool& flag = true); // Поменять местами элементы first и second
    bool swap(const int& firstPosition, const int& secondPosition             ); // Поменять местами элементы на firstPosition и secondPosition

    int  at         (const int& position); // Вернуть значение элемента на позиции position
    int  operator[] (const int&);

private:
    ListElement* _head = nullptr;
};
