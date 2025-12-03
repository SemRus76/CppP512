#include "vector.h"

int Vector::getValue(VectorElement* element)
{
    if (!element)
        return -1;
    return element->_value;
}

void Vector::setValue(const int& value, VectorElement* element)
{
    if (!element)
        return;
    element->_value = value;
}

bool Vector::push_back(const int& value)
{
    if (_array)
    {
        VectorElement* newArray = new VectorElement[_size + 1];
        for (int i = 0; i < _size; ++i)
        {
            newArray[i]._value = _array[i]._value;
        }
        delete[] _array;
        _array = newArray;
        ++_size;

        _array[_size - 1]._value = value;
    }
    else
    {
        _array = new VectorElement[_size + 1];
        ++_size;
        _array[_size - 1]._value = value;
    }
    return true;
}

bool Vector::pop_back()
{
    if (!_array)
        return false;

    VectorElement* newArray = new VectorElement[_size - 1];
    for (int i = 0; i < _size - 1; ++i)
    {
        newArray[i]._value = _array[i]._value;
    }
    delete[] _array;
    _array = newArray;
    --_size;
    return true;
}

bool Vector::insert(const int& position, const int& value)
{
    if (position < 0 || position >= _size)
        return false;

    if (!_array)
        return push_back(value);

    VectorElement* newArray = new VectorElement[_size + 1];
    for (int i = 0; i < _size + 1; ++i)
    {
        if (i == position + 1)
            continue;
        if (i <= position)
        {
            newArray[i]._value = _array[i]._value;
        }
        else
        {
            newArray[i]._value = _array[i - 1]._value;
        }
    }
    delete[] _array;
    _array = newArray;
    ++_size;

    _array[position + 1]._value = value;
    return true;
}

bool Vector::erase(const int& position)
{
    if (position < 0 || position >= _size)
        return false;

    if (!_array)
        return false;

    VectorElement* newArray = new VectorElement[_size - 1];
    for (int i = 0; i < _size; ++i)
    {
        if (i == position)
            continue;

        if (i < position)
        {
            newArray[i]._value = _array[i]._value;
        }
        else
        {
            newArray[i - 1]._value = _array[i]._value;
        }
    }
    delete[] _array;
    _array = newArray;
    --_size;
    return true;
}

bool Vector::empty()
{
    return _size == 0 && !_array ? true : false;
}

void Vector::clear()
{
    _size = {0};
    delete[] _array;
    _array = nullptr;
}

int Vector::front()
{
    if (!_array)
        return  -1;
    return _array[0]._value;
}

int Vector::back()
{
    if (!_array)
        return  -1;
    return _array[_size - 1]._value;
}

int Vector::size()
{
    return _size;
}

bool Vector::swap(VectorElement* first, VectorElement* second, const bool& flag)
{
    (void)flag;
    if (!first || !second || !_array)
        return false;

    if (first == second)
        return true;

    if (first < _array && first >= (_array + _size) &&
        second < _array && second >= (_array + _size))
        return false;

    first->_value = first->_value + second->_value;
    second->_value = first->_value - second->_value;
    first->_value = first->_value - second->_value;

    return true;
}

bool Vector::swap(const int& firstPosition, const int& secondPosition)
{
    if (firstPosition < 0 || firstPosition >= _size ||
        secondPosition < 0 || secondPosition >= _size || !_array)
        return false;

    _array[firstPosition]._value = _array[firstPosition]._value + _array[secondPosition]._value;
    _array[secondPosition]._value = _array[firstPosition]._value - _array[secondPosition]._value;
    _array[firstPosition]._value = _array[firstPosition]._value - _array[secondPosition]._value;
    return true;
}

int Vector::at(const int& position) // Используется тогда, когда идет работа с пользователем, либо вы
// не уверены, что позиция элемента существует
{
    if (position < 0 || position >= _size)
        return -1;
    return _array[position]._value;
}

int Vector::operator[](const int& position) // Используется тогда, когда вы ЖЕЛЕЗОБЕТОННО уверенны,
// что мимо не прочитаетесь
{
    return (_array + position)->_value;
}
