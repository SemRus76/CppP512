#include "payment_service.h"
namespace payment_service
{
using namespace std;

YandexProcessor::YandexProcessor()
{}

YandexProcessor::~YandexProcessor()
{}

bool YandexProcessor::process(Payment& payment)
{
    cout << "Обработка платежа YandexProcessor" << endl;
    if (!payment.validate())
    {
        payment.setFailed();
        cout << "Провал платежа YandexProcessor" << endl;
        return false;
    }
    payment.setSuccess();
    cout << "Успех платежа YandexProcessor" << endl;
    return true;
}

OzonProcessor::OzonProcessor()
{}

OzonProcessor::~OzonProcessor()
{}

bool OzonProcessor::process(Payment& payment)
{
    cout << "Обработка платежа OzonProcessor" << endl;
    if (!payment.validate())
    {
        payment.setFailed();
        cout << "Провал платежа OzonProcessor" << endl;
        return false;
    }
    payment.setSuccess();
    cout << "Успех платежа OzonProcessor" << endl;
    return true;
}

SberBankProcessor::SberBankProcessor()
{}

SberBankProcessor::~SberBankProcessor()
{}

bool SberBankProcessor::process(Payment& payment)
{
    cout << "Обработка платежа SberBankProcessor" << endl;
    if (!payment.validate())
    {
        payment.setFailed();
        cout << "Провал платежа SberBankProcessor" << endl;
        return false;
    }
    payment.setSuccess();
    cout << "Успех платежа SberBankProcessor" << endl;
    return true;
}

}
