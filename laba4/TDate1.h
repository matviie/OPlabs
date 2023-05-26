#ifndef TDate1_h
#define TDate1_h

#pragma once
#include "TDate.h"


class TDate1 : public TDate {
public:
    TDate1() : TDate() {};       // конструктор за замовчуванням

    void inputDate() override;   // функція для введення
    void print() const override; // функція для виведення
};


#endif
