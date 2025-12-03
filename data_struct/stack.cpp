#include "stack.h"

void Stack::push(const int& value)
{
    _base.push_back(value);
}

int Stack::pop()
{
    int value = _base.back();
    _base.pop_back();
    return value;
}

int Stack::top()
{
    return _base.back();
}

bool Stack::empty()
{
    return _base.empty();
}

int Stack::size()
{
    return _base.size();
}
