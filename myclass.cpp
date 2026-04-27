#include "myclass.h"
using namespace std;

MyClass::MyClass(const int& number) : _count(number)
{}

MyClass::~MyClass()
{}

void MyClass::stopThread()
{
    unique_lock guard(_mutex);
    _stopThread = true;
}

void MyClass::operator()()
{
    // Первичная инициализация перед основым циклом работы потока
    while(true)
    {
        { /// Блок для мьютекса
            unique_lock guard(_mutex);
            if (_stopThread)
                break;
        }
        // Основым цикл работы потока
        if (_fibbon.size() < _count)
        {
            unique_lock guard(_mutex);
            int oldSize = _fibbon.size();
            if (!oldSize)
            {
                _fibbon.push_back(0);
                _fibbon.push_back(1);
                oldSize = 2;
            }
            _fibbon.resize(_count + 1);
            for (int i = oldSize; i < _fibbon.size(); ++i)
                _fibbon[i] = _fibbon[i-1] + _fibbon[i-2];
        }
        else if (_fibbon.size() > _count)
        {
            _fibbon.resize(_count + 1);
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        {
            unique_lock guard(_mutex);
            if (!_readyRead)
            {
                _readyRead = true;
            }
        }
    }
}

std::vector<uint64_t> MyClass::getFibbonachiNumber()
{
    unique_lock guard(_mutex);
    return std::move(_fibbon);
}

bool MyClass::isReadyRead()
{
    bool flag = {false};
    {
        unique_lock guard(_mutex);
        flag = _readyRead;
    }
    return flag;
}

void MyClass::setFibbonachiNumberCount(const int& number)
{
    unique_lock guard(_mutex);
    _count = number;
    _readyRead = false;
}

int MyClass::getFibbonachiNumberCount()
{
    bool count = {0};
    {
        unique_lock guard(_mutex);
        count = _count;
    }
    return count;
}
