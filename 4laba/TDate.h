#pragma once
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;


class TDate {
protected:
    int day, month, year;

    void fixDate();             // функція, за допомогою якої значення дати при зменшенні чи збільшенні не можуть бути помилковими (наприклад, 39.20.2000)

    bool checkDate();           // функція для перевірки дати на правильність

    int GetDaysCount(int, int); // функція для отримання кількості днів в місяці

public:
    TDate();                              // конструктор за замовчуванням
    TDate(int, int, int);                 // конструтор з параметрами
    
    virtual void print() const = 0;       // функція для виведення дати

    void decrease(int, int, int);         // функція для зменшення дати
    void increase(int, int, int);         // функція для збільшення дати

    bool operator>(const TDate &) const;  // перевантажений оператор >
    bool operator==(const TDate &) const; // перевантажений оператор ==
    bool operator<(const TDate &) const;  // перевантажений оператор <

    unsigned int GetYear() const { return year; }
    unsigned int GetMonth() const { return month; }
    unsigned int GetDay() const { return day; }

    virtual void inputDate() = 0;         // функція для введення дати

};
