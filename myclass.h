#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <vector>
#include <atomic>


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

    void stopThread();

    // Функтор - это особый оператор класса, который позволяет вызывать объект класса подобно функции
    void operator() ();

    std::vector<uint64_t> getFibbonachiNumber();
    bool isReadyRead();
    void setFibbonachiNumberCount(const int& number);
    int  getFibbonachiNumberCount();


private:

    std::mutex            _mutex;
    std::atomic_bool      _stopThread = {false};

    int                   _count  = {0};
    bool                  _readyRead = {false};
    std::vector<uint64_t> _fibbon = {};

};

