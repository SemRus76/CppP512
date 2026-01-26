#include <example.h>

using namespace std;

// Example::Example()
// {
//     _name = std::string();
//     cout << "Вызыван конструктор по-умолчанию" << endl;
// }

Example::Example(const std::string& name) : Example(name, 0)
{
    cout << "Вызыван делегирующий конструктор" << endl;
}

//                                                                 Поле преинициализации
//                                                                                 |
Example::Example(const std::string& name, const int& number) : _number(number) // <- <имя поля класса>(<имя параметра констуктора>)
{
    // this->_name = name;
    _name = name;
    cout << "Вызыван конструктор с параметром" << endl;
}

// Example::Example(const Example& object)
// {
//     _name = object._name;
//     _number = object._number;
//     cout << "Вызыван lvalue Конструктор копирования" << endl;
// }

// Example::Example(const Example&& object)
// {
//     _name = object._name;
//     _number = object._number;
//     cout << "Вызыван rvalue Конструктор копирования" << endl;
// }

Example::~Example()
{
    _name.clear();
    cout << "Вызыван деструктор по-умолчанию" << endl;
}

void Example::setName(const std::string& name)
{
    _name = name;
}

string Example::getName()
{
    return _name;
}
