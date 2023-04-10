#pragma once
#include <iostream>
#include <string>

using namespace std;

class Worker;

class Date
{
    int day;
    int month;
    int year;

public:

    Date() {}

    void SetDate(); // Функція для введення дати
    
    int GetDay() { return day; }
    int GetMonth() { return month;}
    int GetYear() { return year; }

    bool checkDate(string str); // Функція для перевірки коректності введення дати
    Date currentDate(); // Функція для отримання поточної дати
    
    bool operator <(Date& d); // Перевантаження оператора "<" для порівняння дат
};
