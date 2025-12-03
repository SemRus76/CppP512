#pragma once
#include "list.h"

// Last In First Out - LIFO - Последний Пришел Первый Ушел
// First In Last Out - FILO

struct Stack
{
    void push(const int& value);
    int  pop ();

    int top();
    bool empty();

    int size();

private:

    List _base;

};

