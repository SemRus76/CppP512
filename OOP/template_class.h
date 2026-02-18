#pragma once

/*
 * Шаблонные классы - Template Classes
 *
 *  - это пример статического полиморфизма, когда компилятор для каждого вызова на создание объекта класса создает свою перегрузку для класса
 *
 *  ВАЖНО - Template classes НЕ РАЗДЕЛЯЮТСЯ на Заголовочные файлы и Файлы Исходного кода
 *
 */

template<typename Type>
class TemplateClass
{
public:
    TemplateClass() = default;
    TemplateClass(const Type& value)
    {
        _value = value;
    }
    ~TemplateClass()
    {}

    Type getValue()
    {
        return _value;
    }

private:
    Type _value;
};

template<typename Type>
class SecondTemplate : public TemplateClass<int>
{

};
