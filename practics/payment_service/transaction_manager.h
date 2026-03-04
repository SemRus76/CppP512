#pragma once
#include <iostream>
#include <string>
#include <stdint.h>
#include <vector>
#include "common.h"
#include "payment_service.h"

namespace payment_service
{
class TransactionManager final
{
public:
     TransactionManager();
    ~TransactionManager();

    bool                               addUser    (const User&);
    std::vector<payment_service::User> getUserVec (           );
    bool                               delUser    (      User&);

    bool execute_payment (const uint64_t&, PaymentService*, const uint64_t&);

private:
    DELETE_COPY_CONSTRUCTOR(TransactionManager)

    std::vector<payment_service::User> _userVec = {};

};
}
