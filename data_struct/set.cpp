#include "set.h"

int Set::getValue(SetElement* element)
{
    if (!element)
        return -1;
    return element->_value;
}

void Set::setValue(const int& value, SetElement* element)
{
    if (!element)
        return;
    element->_value = value;
}

bool Set::emplace(const int& value)
{
    if (_root)
    {
        return emplace(_root, value);
    }
    else
    {
        _root = new SetElement();
        _root->_value = value;
        ++_size;
        return true;
    }
}

bool Set::erase(const int& value)
{
    if (!_root)
        return false;

    if (!find(value))
        return false;

    return erase(_root, value);
}

bool Set::empty()
{
    return _size && _root ? false : true;
}

void Set::clear()
{
    if (!_root)
        return;
    while (_size)
        erase(_root, _root->_value);
}

int Set::size()
{
    return _size;
}

bool Set::find(const int& value)
{
    return true;
}

void Set::print()
{
    if (!_root)
        return;
    print(_root);
    std::cout << std::endl;
}

bool Set::emplace(SetElement* element, const int& value)
{
    if (value == element->_value)
        return false;

    if (value < element->_value)
    {
        if (element->_left)
        {
            return emplace(element->_left, value);
        }
        else
        {
            element->_left = new SetElement();
            element->_left->_value = value;
            element->_left->_before = element;
            ++_size;
            return true;
        }
    }
    else
    {
        if (element->_right)
        {
            return emplace(element->_right, value);
        }
        else
        {
            element->_right = new SetElement();
            element->_right->_value = value;
            element->_right->_before = element;
            ++_size;
            return true;
        }
    }
}

bool Set::erase(SetElement* element, const int& value)
{
    if (element->_value == value)
    {
        if (element->_before)
        {
            if (!element->_left && element->_right)
            {
                // Простая замена
                if (element->_before->_left == element)
                {
                    element->_before->_left = element->_right;
                    element->_right->_before = element->_before;
                }
                else
                {
                    element->_before->_right = element->_right;
                    element->_right->_before = element->_before;
                }
            }
            else if (element->_left && !element->_right)
            {
                // Простая замена
                if (element->_before->_left == element)
                {
                    element->_before->_left = element->_left;
                    element->_left->_before = element->_before;
                }
                else
                {
                    element->_before->_right = element->_left;
                    element->_left->_before = element->_before;
                }
            }
            else if (element->_left && element->_right)
            {
                // Есть оба
                if (element->_before->_left == element)
                    element->_before->_left = element->_right;
                else
                    element->_before->_right = element->_right;
                element->_right->_before = element->_before;

                SetElement* tmp = element->_right;
                while(tmp->_left)
                    tmp = tmp->_left;
                tmp->_left = element->_left;
                element->_left->_before = tmp;
            }
            else
            {
                // Никого ниже нет
                if (element->_before->_left == element)
                    element->_before->_left = nullptr;
                else
                    element->_before->_right = nullptr;
            }
        }
        else
        {
            // Удаляется _root
            if (element->_right)
            {
                _root = element->_right;
                element->_right->_before = nullptr;
                SetElement* tmp = element->_right;
                while(tmp->_left)
                    tmp = tmp->_left;
                tmp->_left = element->_left;
                if (element->_left)
                    element->_left->_before = tmp;
            }
            else if (element->_left)
            {
                _root = element->_left;
                element->_left->_before = nullptr;
            }
            else
            {
                _root = nullptr;
            }
        }

        delete element;
        --_size;
        return true;
    }
    else if (value < element->_value)
    {
        return element->_left ? erase(element->_left, value) : false;
    }
    else
    {
        return element->_right ? erase(element->_right, value) : false;
    }
}

void Set::print(const SetElement* now)
{
    if (now->_left)
        print(now->_left);
    std::cout << " " << now->_value;
    if (now->_right)
        print(now->_right);
}












