#include "inheritance.h"

using namespace std;
Parent::Parent()
{
    cout << "Создан объект Parent" << endl;
}

Parent::~Parent()
{
    cout << "Удален объект Parent" << endl;
}

Parent::Parent(const double& value)
{
    _value = value;
}

double Parent::getValue()
{
    return _value;
}

bool Parent::setValue(const int& value)
{
    if ((value % 2) == 0)
        return false;
    _value = value;
    return true;
}

string Parent::getName()
{
    return std::string("Parent");
}

void Parent::sayHello()
{
    std::cout << "Hello World" << std::endl;
}

std::istream& operator>> (std::istream& stream, Parent& object)
{
    stream >> object._value;
    return stream;
}

std::ostream& operator<< (std::ostream& stream, const Parent& object)
{
    stream << object._value;
    return stream;
}







Inherit::Inherit()
{
    cout << "Создан объект Inherit" << endl;
}

Inherit::~Inherit()
{
    cout << "Удален объект Inherit" << endl;
}

Inherit::Inherit(const double& real, const double& imagen) : Parent(real)
{
    _imgn = imagen;
}

double Inherit::getReal()
{
    return _value;
}

bool Inherit::setReal(const int& value)
{
    return setValue(value);
}

double Inherit::getImgn()
{
    return _imgn;
}

bool Inherit::setImgn(const int& value)
{
    _imgn = value;
    return true;
}

string Inherit::getName()
{
    return std::string("Inherit");
}

std::istream& operator>> (std::istream& stream, Inherit& object)
{
    double tmp;
    stream >> tmp;
    object.setReal(tmp);
    stream >> object._imgn;
    return stream;
}

std::ostream& operator<< (std::ostream& stream, const Inherit& object)
{
    stream << object._value << " + " << object._imgn << "i ";
    return stream;
}










