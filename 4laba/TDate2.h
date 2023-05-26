#ifndef TDate2_h
#define TDate2_h

#pragma once
#include "TDate.h"


class TDate2 : public TDate {
public:
    TDate2() : TDate() {};       // конструктор за замовчуванням

    void inputDate() override;   // функція для введення
    void print() const override; // функція для виведення
};


#endif
