#include "abastract_class.h"
using namespace std;

Weapon::Weapon(const int& AmmoCount)
{
    _ammoCount = AmmoCount;
}

Weapon::~Weapon()
{

}

Pistol::Pistol() : Weapon(7)
{}

Pistol::~Pistol()
{}

void Pistol::fire()
{
    if (_ammoCount <= 0)
    {
        cout << "Can't fire!" << endl;
        return;
    }
    cout << "Piu Piu" << endl;
    _ammoCount -= 2;
}

void Pistol::reload()
{
    cout << "RELOAD PISTOL" << endl;
    _ammoCount = 7;
}

void Pistol::onLantern()
{
    _lanternStatus = !_lanternStatus;
}

MachinGun::MachinGun() : Weapon(100)
{
}

MachinGun::~MachinGun()
{

}

void MachinGun::fire()
{
    if (_ammoCount <= 0)
    {
        cout << "Can't fire!" << endl;
        return;
    }
    cout << "RATATATATATATATATATATATA" << endl;
    _ammoCount -= 10;
}

void MachinGun::reload()
{
    cout << "RELOAD MachinGun" << endl;
    _ammoCount = 100;
}

void MachinGun::onBipods()
{
    _bipodsStatus = !_bipodsStatus;
}

SniperGun::SniperGun() : Weapon(12)
{

}

SniperGun::~SniperGun()
{

}

void SniperGun::fire()
{
    if (_ammoCount <= 0)
    {
        cout << "Can't fire!" << endl;
        return;
    }
    cout << "Scidyish" << endl;
    _ammoCount -= 1;
}

void SniperGun::reload()
{
    cout << "RELOAD SniperGun" << endl;
    _ammoCount = 12;
}

void SniperGun::zoom()
{
    _zoomStatus = !_zoomStatus;
}
