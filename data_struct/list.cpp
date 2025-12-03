#include "list.h"


int List::getValue(ListElement* element)
{
    if (!element)
        return -1;
    return element->_value;
}

void List::setValue(const int& value, ListElement* element)
{
    if (!element)
        return;
    element->_value = value;
}

bool List::push_back(const int& value)
{
    if (!_head)
    {
        _head = new ListElement();
        _head->_value = value;
    }
    else
    {
        ListElement* nowElem = _head;
        if (nowElem->_next)
        {
            while(nowElem->_next)
                nowElem = nowElem->_next;
        }
        nowElem->_next = new ListElement();
        nowElem->_next->_value = value;
        nowElem->_next->_back = nowElem;
    }
    return true;
}

bool List::push_front(const int& value)
{
    if (!_head)
    {
        _head = new ListElement();
        _head->_value = value;
    }
    else
    {
        ListElement* nowElem = _head;
        if (nowElem->_back)
        {
            while(nowElem->_back)
                nowElem = nowElem->_back;
        }
        nowElem->_back = new ListElement();
        nowElem->_back->_value = value;
        nowElem->_back->_next = nowElem;
        nowElem = nowElem->_back;
        _head = nowElem;
    }
    return true;
}

bool List::pop_back()
{
    if (!_head)
        return false;

    ListElement* nowElem = _head;
    while(nowElem->_next)
        nowElem = nowElem->_next;

    if (!nowElem->_back)
    {
        delete nowElem;
        _head = nullptr;
    }
    else
    {
        nowElem = nowElem->_back;
        delete nowElem->_next;
        nowElem->_next = nullptr;
    }
    return true;
}

bool List::pop_front()
{
    if (!_head)
        return false;

    ListElement* nowElem = _head;
    while(nowElem->_back)
        nowElem = nowElem->_back;

    if (!nowElem->_next)
    {
        delete nowElem;
        _head = nullptr;
    }
    else
    {
        nowElem = nowElem->_next;
        delete nowElem->_back;
        nowElem->_back = nullptr;
        _head = nowElem;
    }
    return true;
}

bool List::insert(const int& position, const int& value)
{
    if (!_head)
        return false;

    if (position >= size())
        return false;

    ListElement* nowElem = _head;
    for (int i = 1; i < position; ++i)
        nowElem = nowElem->_next;

    ListElement* nextElement = nowElem->_next;
    nowElem->_next = nullptr;
    nowElem->_next = new ListElement();
    nowElem->_next->_value = value;
    nowElem->_next->_back = nowElem;

    if (nextElement)
    {
        nowElem->_next->_next = nextElement;
        nextElement->_back = nowElem->_next;
    }

    return true;
}

bool List::erase(const int& position)
{
    if (!_head)
        return false;

    if (position >= size())
        return false;

    ListElement* nowElem = _head;
    for (int i = 0; i < position; ++i)
        nowElem = nowElem->_next;

    if (nowElem->_next)
    {
        if (nowElem->_back)
        {
            // Ситуация посередине
            nowElem->_back->_next = nowElem->_next;
            nowElem->_next->_back = nowElem->_back;
            delete nowElem;
        }
        else
        {
            nowElem->_next->_back = nullptr;
            delete nowElem;
        }
    }
    else if (nowElem->_back)
    {
        nowElem->_back->_next = nullptr;
        delete nowElem;
    }
    else
    {
        delete nowElem;
        _head = nullptr;
    }
    return true;
}

bool List::empty()
{
    return _head ? false : true;
}

void List::clear()
{
    if (!_head)
        return;
    ListElement* nowElement = _head;
    while (nowElement->_next)
    {
        nowElement = nowElement->_next;
        delete nowElement->_back;
    }
    delete nowElement;
    _head = nullptr;
}

int List::front()
{
    return _head->_value;
}

int List::back()
{
    ListElement* nowElem = _head;
    if (nowElem->_next)
    {
        while (nowElem->_next)
            nowElem = nowElem->_next;
    }
    return nowElem->_value;
}

int List::size()
{
    if (!_head)
        return 0;

    ListElement* nowElem = _head;

    int size = 1;
    while (nowElem->_next)
    {   
        nowElem = nowElem->_next;
        ++size;
    }

    return size;
}

bool List::swap(ListElement* first, ListElement* second, const bool& flag )
{
    if (first == second)
        return true;

    if (!_head && !first && !second)
        return false;

    if (flag)
    {
        bool flag1 = false, flag2 = false;
        ListElement* nowElem = _head;

        while(nowElem->_next && (!flag1 || !flag2))
        {
            if (nowElem == first)
                flag1 = true;
            if (nowElem == second)
                flag2 = true;
            nowElem = nowElem->_next;
        }
        if (!flag1 || !flag2)
            return false;
    }

    if (first->_back)
    {
        if (first->_next)
        {
            if (second->_back)
            {
                if (second->_next)
                {
                    if (first->_next != second && first->_back != second)
                    {
                        // Меняем местами НЕ соседние, но и НЕ крайние элементы
                        first->_back->_next = second;
                        second->_back->_next = first;
                        ListElement* temp = first->_back;
                        first->_back = second->_back;
                        second->_back = temp;

                        first->_next->_back = second;
                        second->_next->_back = first;
                        temp = first->_next;
                        first->_next = second->_next;
                        second->_next = temp;
                    }
                    else
                    {
                        // Меняем местами соседние элементы
                        if (first->_back != second)
                        {
                            // First - левый
                            // Second - правый
                            first->_back->_next = second;
                            second->_next->_back = first;

                            second->_back = first->_back;
                            first->_back = second;

                            first->_next = second->_next;
                            second->_next = first;
                        }
                        else
                        {
                            // First - правый
                            // Second - левый
                            second->_back->_next = first;
                            first->_next->_back = second;

                            first->_back = second->_back;
                            second->_back = first;

                            second->_next = first->_next;
                            first->_next = second;
                        }

                    }
                }
                else
                {
                    if (first->_next != second)
                    {
                        // Меняем местами последний и n-ый элемент списка
                        // first - где-то
                        // second - последний
                        second->_back->_next = first;
                        ListElement* temp = second->_back;
                        second->_back = first->_back;
                        first->_back->_next = second;
                        first->_back = temp;
                        first->_next->_back = second;
                        second->_next = first->_next;
                        first->_next = nullptr;
                    }
                    else
                    {
                        // Меняем местами предпоследний и последний элементы списка
                        // first - препоследний
                        // second - последний
                        second->_back = first->_back;
                        first->_back->_next = first->_next;
                        second->_next = first;

                        first->_back = second;
                        first->_next = nullptr;
                    }
                }
            }
            else
            {
                if (second->_next)
                {
                    // Элементов больше двух в списке
                    if (second->_next != first)
                    {
                        // Меняем местами первый и n-ый элемент списка
                        // first - где-то
                        // second - первый
                        second->_next->_back = first;
                        ListElement* temp = second->_next;
                        second->_next = first->_next;
                        second->_back = first->_back;
                        first->_next->_back = second;
                        first->_back->_next = second;
                        first->_next = temp;
                        first->_back = nullptr;
                    }
                    else
                    {
                        // Меняем местами первый и второй элементы списка
                        // first - второй
                        // second - первый
                        second->_next = first->_next;
                        second->_back = first;
                        first->_next->_back = second;
                        first->_next = second;
                        first->_back = nullptr;
                    }
                }
                else
                {
                    // Элементов всего два
                    // first - второй
                    // second - первый
                    first->_next = second;
                    first->_back = nullptr;
                    second->_next = nullptr;
                    second->_back = first;
                }
                _head = first;
            }
        }
        else
        {
            if (second->_back)
            {
                if (second->_next != first)
                {
                    // Меняем местами последний и n-ый элемент списка
                    // first - последний
                    // second - где-то в списке

                    second->_back->_next = first;
                    second->_next->_back = first;
                    first->_back->_next = second;
                    ListElement* temp = first->_back;
                    first->_back = second->_back;
                    second->_back = temp;
                    first->_next = second->_next;
                    second->_next = nullptr;

                }
                else
                {
                    // Меняем местами предпоследний и последний элементы списка
                    // first - последний
                    // second - предпоследний

                    second->_back->_next = first;
                    first->_back = second->_back;
                    second->_back = first;

                    first->_next = second;
                    second->_next = nullptr;
                }
            }
            else
            {
                // Меняем местами первый и последний элементы списка
                // first - последний
                // second - первый элемент

                // ListElement* temp = first;
                // first = second;
                // second = temp;
                // if (first->_next != second)
                // {
                //     // В списке больше двух элементов
                //     second->_next = first->_next;
                //     first->_next->_back = second;
                //     first->_next = nullptr;

                //     first->_back = second->_back;
                //     second->_back->_next = first;
                //     second->_back = nullptr;
                // }
                // else
                // {
                //     // В списке всего два элемента
                //     second->_next = first;
                //     first->_next = nullptr;

                //     first->_back = second;
                //     second->_back = nullptr;
                // }

                if (second->_next != first)
                {
                    // В списке больше двух элементов
                    first->_next = second->_next;
                    second->_next->_back = first;
                    second->_next = nullptr;

                    second->_back = first->_back;
                    first->_back->_next = second;
                    first->_back = nullptr;
                }
                else
                {
                    // В списке всего два элемента
                    first->_next = second;
                    second->_next = nullptr;

                    second->_back = first;
                    first->_back = nullptr;
                }
                _head = first;
            }
        }
    }
    else
    {
        if (second->_next)
        {
            if (first->_next != second)
            {
                // Меняем местами первый и n-ый элемент списка
                // first - первый
                // second - где-то
                second->_next->_back = first;
                second->_back->_next = first;
                first->_next->_back = second;
                ListElement* temp = second->_next;
                second->_next = first->_next;
                first->_next = temp;
                first->_back = second->_back;
                second->_back = nullptr;
            }
            else
            {
                // Меняем местами первый и второй элементы списка
                // first - первый
                // second - второй
                first->_next = second->_next;
                second->_next->_back = first;
                second->_next = first;
                first->_back = second;
                second->_back = nullptr;
            }
        }
        else
        {
            // Меняем местами первый и последний элементы списка
            // first - первый
            // second - последний
            if (first->_next != second)
            {
                // В списке больше двух элементов
                second->_next = first->_next;
                first->_next->_back = second;
                first->_next = nullptr;

                first->_back = second->_back;
                second->_back->_next = first;
                second->_back = nullptr;
            }
            else
            {
                // В списке всего два элемента
                second->_next = first;
                first->_next = nullptr;

                first->_back = second;
                second->_back = nullptr;
            }
        }
        _head = second;
    }

    return true;
}

bool List::swap(const int& firstPosition, const int& secondPosition)
{
    if (!_head)
        return false;

    if (firstPosition < 0 && firstPosition >= size() &&
        secondPosition < 0 && secondPosition >= size())
        return false;

    if (firstPosition == secondPosition)
        return true;

    ListElement* first = nullptr,
               * second = nullptr,
               * nowElem = _head;

    for (int i = 0; i < size(); ++i)
    {
        if (i == firstPosition)
            first = nowElem;

        if (i == secondPosition)
            second = nowElem;

        if (first && second)
            break;

        nowElem = nowElem->_next;
    }

    return swap(first, second, false);
}

int List::at(const int& position)
{
    if (!_head)
        return -1;

    if (position >= size())
        return -1;

    ListElement* nowElem = _head;
    for (int i = 0; i < position; ++i)
        nowElem = nowElem->_next;

    return nowElem->_value;
}

int List::operator[](const int& position)
{
    return at(position);
}
