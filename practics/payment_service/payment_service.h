#pragma once
#include <iostream>
#include <string>
#include "common.h"
#include "payment.h"

namespace payment_service
{
struct Payment;
// класс PaymentService - Определяет стандартный интерфейс для обработки платежей
class PaymentService
{
public:
             PaymentService() = default;
    virtual ~PaymentService() = default;

    virtual bool process(payment_service::Payment&) = 0;

private:
    DELETE_COPY_CONSTRUCTOR(PaymentService)
};

// класс YandexProcessor - Определяет интерфейс для Yandex
class YandexProcessor final : public PaymentService
{
public:
     YandexProcessor();
    ~YandexProcessor();

    bool process(payment_service::Payment&) override;

private:
    DELETE_COPY_CONSTRUCTOR(YandexProcessor)
};

// класс OzonProcessor - Определяет интерфейс для Ozon
class OzonProcessor final : public PaymentService
{
public:
     OzonProcessor();
    ~OzonProcessor();

    bool process(payment_service::Payment&) override;

private:
    DELETE_COPY_CONSTRUCTOR(OzonProcessor)
};

// класс SberBankProcessor - Определяет интерфейс для SberBank
class SberBankProcessor final : public PaymentService
{
public:
     SberBankProcessor();
    ~SberBankProcessor();

    bool process(Payment&) override;

private:
    DELETE_COPY_CONSTRUCTOR(SberBankProcessor)
};

}
