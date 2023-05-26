#ifndef array_h
#define array_h

#pragma once
#include "TDate1.h"
#include "TDate2.h"


class arrayDate {
private:
    int size = 0;
    TDate **array;

public:
    arrayDate(int, int);                       // конструктор з параметрами
    
    void arrayPlusOne(int *, TDate ***) const; // функція для збільшення масив на один елемент

    int findIndexLateDate() const;             // функція для знаходження найпізнішої дати

    TDate **findPeriodDate(const TDate &, const TDate &) const; // функція для знаходження дат в межах періоду

    void increaseOrDecrease(bool, int, int, int); // функція для збільшення або зменшення дати

    void printArray(TDate **, int) const;      // функція для виводу масиву
    void printOne(int i) const;                // функція для виводу найпізнішої дати

    ~arrayDate();
};


#endif 
