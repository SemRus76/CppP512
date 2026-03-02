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
    }
    payment.setSuccess();
    cout << "Успех платежа YandexProcessor" << endl;
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
    }
    payment.setSuccess();
    cout << "Успех платежа OzonProcessor" << endl;
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
    }
    payment.setSuccess();
    cout << "Успех платежа SberBankProcessor" << endl;
}

}
