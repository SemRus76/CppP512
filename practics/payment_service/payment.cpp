#include "payment.h"
namespace payment_service
{
using namespace std;

User::User(const uint64_t& id, const std::string& name)
    : _id(id), _nickName(name)
{

}

User::~User()
{

}

Payment::Payment(const uint64_t& amount, const User& sender) :
    _sender(sender), _amount(amount), _status(PaymentStatus::Pending)
{}

Payment::~Payment()
{}

void Payment::setSuccess()
{
    _status = PaymentStatus::Success;
}

void Payment::setFailed()
{
    _status = PaymentStatus::Failed;
}

Payment::PaymentStatus Payment::getStatus()
{
    return _status;
}

bool Payment::validate()
{
    if (!_amount)
        return false;

    return true;
}



}
