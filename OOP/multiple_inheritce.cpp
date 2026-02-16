#include "multiple_inheritce.h"
using namespace std;
Nulleble::Nulleble()
{
    cout << "Construct Nulleble" << endl;
}

Nulleble::~Nulleble()
{
    cout << "DeConstruct Nulleble" << endl;
}

void Nulleble::sayDIE()
{
    cout << "MUST DIE!!!" << endl;
}

First::First()
{
    cout << "Construct First" << endl;
}

First::~First()
{
    cout << "DeConstruct First" << endl;
}

void First::sayHello()
{
    cout << "Hello" << endl;
}

Second::Second()
{
    cout << "Construct Second" << endl;
}

Second::~Second()
{
    cout << "DeConstruct Second" << endl;
}

void Second::sayNothing()
{
    cout << "Nothing" << endl;
}

Third::Third()
{
    cout << "Construct Third" << endl;
}

Third::~Third()
{
    cout << "DeConstruct Third" << endl;
}

void Third::sayNormal()
{
    cout << "Normal" << endl;
}


