#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>


class MyClass
{
public:
     MyClass() = default;
     MyClass(const int& number);
    ~MyClass();

     MyClass           (const MyClass& ) = delete;
     MyClass operator= (const MyClass& ) = delete;
     MyClass           (      MyClass&&) = delete;
     MyClass operator= (      MyClass&&) = delete;

    void run();

    // Функтор - это особый оператор класса, который позволяет вызывать объект класса подобно функции
    void operator() (const int& number);


    int count() const;
    void setCount(int newCount);

private:

    int _count = {0};
    std::recursive_mutex _mutex;
    std::mutex _mutex2;
};

