cmake_minimum_required(VERSION 4.2.1) # минимальная версия Cmake


set (payment_header
            payment_service/user.h
            payment_service/payment.h
            payment_service/payment_service.h
            payment_service/transaction_manager.h

)

set (payment_source
            payment_service/user.cpp
            payment_service/payment_service.cpp
            payment_service/payment.cpp
            payment_service/transaction_manager.cpp

)


add_library(payment_service STATIC
            ${payment_header}
            ${payment_source}

            )

target_include_directories(payment_service PUBLIC .
                             ${payment_header})

set (practics_header
    common.h
)

set (practics_source
    common.cpp
)

# add_subdirectory(payment_service)

add_library(practics_object OBJECT
            ${practics_header}
            ${practics_source}
            )
target_link_libraries(practics_object PUBLIC
                        payment_service)
target_include_directories(practics_object PUBLIC .
                             ${practics_header}
                             payment_service)
