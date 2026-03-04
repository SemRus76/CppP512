#include "transaction_manager.h"
namespace payment_service
{
using namespace std;

TransactionManager::TransactionManager()
{}

TransactionManager::~TransactionManager()
{}

bool TransactionManager::addUser(const User& user)
{
    // Проход по всем пользователям - не должен повторяться id

    _userVec.push_back(user);

    return true;
}

std::vector<User> TransactionManager::getUserVec()
{
    return _userVec;
}

bool TransactionManager::delUser(User& user)
{
    for (int i = 0; i < _userVec.size(); ++i)
    {
        if (user.getId() == _userVec[i].getId())
        {
            _userVec.erase(_userVec.begin() + i);
            return true;
        }
    }
    return false;
}

bool TransactionManager::execute_payment(const uint64_t& userID,
                                         PaymentService* serice,
                                         const uint64_t& amount)
{
    // Проход по всем пользователям - должен существовать пользователь с таким id

    for (int i = 0; i < _userVec.size(); ++i)
    {
        if (_userVec[i].getId() == userID)
        {
            Payment pay(amount, _userVec[i]);
            serice->process(pay);
            return true;
        }
    }

    return false;
}



}
