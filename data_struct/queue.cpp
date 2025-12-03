#include "queue.h"

void Queue::push(const int& value)
{
    _base.push_back(value);
}

int Queue::pop()
{
    int value = _base.front();
    _base.pop_front();
    return value;
}

int Queue::top()
{
    return _base.front();
}

int Queue::back()
{
    return _base.back();
}

bool Queue::empty()
{
    return _base.empty();
}

int Queue::size()
{
    return _base.size();
}
