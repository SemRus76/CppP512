#pragma once
#include "list.h"

// First In First Out - FIFO - Первый Пришел Первый Ушел
// Last In Last Out   - LILO

struct Queue
{
    void push(const int& value);
    int  pop ();

    int top ();
    int back();

    bool empty();

    int size();

private:

    List _base;
};

