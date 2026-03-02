#pragma once
#include <iostream>
#include <string>
#include <stdint.h>
#include "common.h"

namespace payment_service
{
// #include "user.h"
// class User;
class User final
{
public:
     User(const uint64_t& id, const std::string& name);
    ~User();

private:
    DELETE_COPY_CONSTRUCTOR(User)

    uint64_t    _id       = {0};
    std::string _nickName = {"user"};
    uint64_t    _balance  = {0};

};

// класс Payment - Представляет один платёж
struct Payment final
{
public:

    enum class PaymentStatus : uint32_t
    {
        Unknown = 0,
        Pending,
        Success,
        Failed
    };

     Payment(const uint64_t& amount, const payment_service::User& sender);
    ~Payment();

    void setSuccess();
    void setFailed();
    PaymentStatus getStatus();
    bool validate();

private:

    PaymentStatus         _status;
    uint64_t              _amount; // unsigned long long int
    payment_service::User _sender;
};

}
