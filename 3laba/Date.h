#include <iostream>
#include <iomanip>


using namespace std;


class Date
{
    int day, month, year;
    
    bool checkDate(string str); // Функція для перевірки коректності введення дати
    static Date currentDate(); // Функція для отримання поточної дати
    
public:
    
    Date(); // Конструктор за замовчуванням
    Date(int y, int m, int d); // Конструктор з параметрами
    
    
    Date operator ++(); // перевантажений оператор префіксний "++"
    Date operator ++(int); // перевантажений оператор постфіксний "++"
    bool operator>(const Date& D); // перевантажений оператор ">"
    
    void SetDate(); // Функція для введення дати
    
    int GetDay() { return day; }
    int GetMonth() { return month;}
    int GetYear() { return year; }
    

    unsigned int YearEnd(); //функція визначення терміну, що залишився до кінця року
    
    void Print(); // функція для виведення дати
};
