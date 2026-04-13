#include "myclass.h"
using namespace std;

MyClass::MyClass(const int& number) : _count(number)
{}

MyClass::~MyClass()
{}

void MyClass::run()
{
    int number = {0};
    {
        // lock_guard guard(_mutex);
        scoped_lock locker(_mutex);
        if (_count < 0)
        {
            return;
        }
        if (_count == 0)
        {
            cout << 0 << endl;
            return;
        }

        if (_count == 1)
        {
            cout << 0 << " " << 1 << " " << endl;
            return;
        }
        number = _count;
    }

    int First = 0;
    int Second = 1;
    std::vector<int> result;
    result.reserve(number);
    for (int i = 0; i < number; ++i)
    {
        First = First + Second;
        Second = First - Second;
        result.push_back(First);
    }

    {
        // lock_guard<std::mutex> guard(_mutex2);
        scoped_lock locker(_mutex2);
        cout << 0 << " " ;
        for (auto& element : result)
            cout << element << " ";
        cout << endl;
    }
    return;
}

void MyClass::operator()(const int& number)
{
    {
        lock_guard guard(_mutex);
        if (number > _count)
            _count = number;
        // this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    run();
}

int MyClass::count() const
{
    return _count;
}

void MyClass::setCount(int newCount)
{
    scoped_lock guard(_mutex);
    _count = newCount;
}
