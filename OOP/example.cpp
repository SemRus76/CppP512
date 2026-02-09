#include <example.h>

using namespace std;

// Example::Example()
// {
//     _name = std::string();
//     cout << "Вызыван конструктор по-умолчанию" << endl;
// }

Example::Example(const std::string& name) : Example(name, 0)
{
    // cout << "Вызыван делегирующий конструктор" << endl;
}

//                                                                 Поле преинициализации
//                                                                                 |
Example::Example(const std::string& name, const int& number) : _number(number) // <- <имя поля класса>(<имя параметра констуктора>)
{
    // this->_name = name;
    _name = name;
    _vec = {1,2,3,4,5,6,7,8};
    // cout << "Вызыван конструктор с параметром" << endl;
}

Example::Example(const Example& object)
{
    _name = object._name;
    _number = object._number;
    // cout << "Вызыван lvalue Конструктор копирования" << endl;
}

Example& Example::operator=(const Example& value)
{
    _name = value._name;
    _number = value._number;
    return *this;
}

Example::Example(const Example&& object)
{
    _name = object._name;
    _number = object._number;
    // cout << "Вызыван rvalue Конструктор копирования" << endl;
}

Example& Example::operator=(const Example&& value)
{
    _name = value._name;
    _number = value._number;
    return *this;
}

Example::~Example()
{
    _name.clear();
    // cout << "Вызыван деструктор по-умолчанию" << endl;
}

Example Example::operator!() const
{
    return Example(_name, -_number);
}

Example& Example::operator++()
{
    ++_number;
    return *this;
}

Example Example::operator++(int)
{
    Example cry(_name, _number);
    ++_number;
    return cry;
}

Example& Example::operator--()
{
    --_number;
    return *this;
}

bool Example::operator==(const Example& value) const
{
    return _number == value._number;
}

bool Example::operator!=(const Example& value) const
{
    return _number != value._number;
}

bool Example::operator>(const Example&  value) const
{
    return _number > value._number;
}

bool Example::operator>=(const Example& value) const
{
    return _number >= value._number;
}

bool Example::operator<(const Example&  value) const
{
    return _number < value._number;
}

bool Example::operator<=(const Example& value) const
{
    return _number <= value._number;
}

Example Example::operator+(const Example& value) const
{
    return Example(_name + " " + value._name, _number + value._number);
}

Example Example::operator-(const Example& value) const
{
    return Example("", _number - value._number);
}

Example Example::operator*(const Example& value) const
{
    return Example("", _number * value._number);
}

Example Example::operator/(const Example& value) const
{
    return Example("", _number / value._number);
}

Example Example::operator%(const Example& value) const
{
    return Example("", _number % value._number);
}

Example& Example::operator+=(const Example& value)
{
    _name = value._name;
    _number = _number + value._number;
    return *this;
}

Example& Example::operator-=(const Example& value)
{
    _name = value._name;
    _number = _number - value._number;
    return *this;
}

Example& Example::operator*=(const Example& value)
{
    _name = value._name;
    _number = _number * value._number;
    return *this;
}

Example& Example::operator/=(const Example& value)
{
    _name = value._name;
    _number = _number / value._number;
    return *this;
}

Example& Example::operator%=(const Example& value)
{
    _name = value._name;
    _number = _number % value._number;
    return *this;
}

int& Example::operator[](const int& index)
{
    return _vec[index];
}

int& Example::at(const int& index)
{
    if (index > _vec.size() - 1 || index < 0)
    {
        int val = -1;
        return val;
    }
    return _vec[index];
}

Example Example::operator--(int)
{
    Example cry(_name, _number);
    --_number;
    return cry;
}

std::istream& operator>> (std::istream& stream, Example& object)
{
    stream >> object._name;
    stream >> object._number;
    return stream;
}

std::ostream& operator<< (std::ostream& stream, Example object)
{
    stream << object._name << " " << object._number;
    return stream;
}

void Example::setName(const std::string& name)
{
    _name = name;
}

string Example::getName() const
{
    return _name;
}

string Example::ClassName()
{
    return std::string("Example");
}
