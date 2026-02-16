#pragma once
#include <iostream>
#include <string>
#include "common.h"

/*
 * Абстрактные классы
 *
 *  Это классы, объекты которых НЕВОЗМОЖНО создать, но при этом от них можно унаследоваться
 *      и использовать для обобщения некоторого количества классов. То есть эти классы будут
 *      хранить в себе общие методы, поля и в целом будут выступать некой логической сущностью
 *      общей для всех наследников.
 *
 *  Для того что бы класс стал абстрактным в нем обязана существовать ХОТЯ БЫ ОДНА
 *      чисто виртуальная функция.
 *
 *  Чисто виртуальные функции - это функции-методы классов, у которых нет реализации.
 *
 *      Синтаксис описания:
 *          virtual <возвращаемое значение> <имя метода> (<параметры>) = 0;
 *
 *  ВАЖНО - Любой наследник будет считаться АБСТРАКТНЫМ классом, ровно до тех пор, пока не реализует ВСЕ чисто виртуальные функции родителя
 *
 *  Интерфейс - это абстрактный класс, который не имеет полей.
 *      Интерфейс - это декларация о том, какие методы ТОЧНО будут реализованы в наследниках этого класса
 *
 */

class Weapon
{
public:

             Weapon(const int& AmmoCount);
    virtual ~Weapon();

    virtual void fire  () = 0;
    virtual void reload() = 0;

protected:
    DELETE_COPY_CONSTRUCTOR(Weapon)
    int _ammoCount = {0};
};

class Pistol : public Weapon
{
public:
     Pistol();
    ~Pistol();

    void fire() override;
    void reload() override;

    void onLantern();
private:
    DELETE_COPY_CONSTRUCTOR(Pistol)

    bool _lanternStatus = {false};

};

class MachinGun : public Weapon
{
public:
    MachinGun();
    ~MachinGun();

    void fire() override;
    void reload() override;

    void onBipods();
private:
    DELETE_COPY_CONSTRUCTOR(MachinGun)
    bool _bipodsStatus = {false};
};

class SniperGun : public Weapon
{
public:
    SniperGun();
    ~SniperGun();

    void fire() override;
    void reload() override;

    void zoom();
private:
    DELETE_COPY_CONSTRUCTOR(SniperGun)
    bool _zoomStatus = {false};
};

