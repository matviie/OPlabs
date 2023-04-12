#include "Date.h"
#include "func.h"


Date::Date() // Конструктор за замовчуванням
{
    year = 2000;
    month = 1;
    day = 1;
}


Date::Date(int y, int m, int d) // Конструктор з параметрами
{
    year = y;
    month = m;
    day = d;
}


Date Date::operator ++() // перевантажений оператор префіксний "++"
{
    ++month;
    return *this;
}


Date Date::operator ++(int) // перевантажений оператор постфіксний "++"
{
    Date temp(*this);
    ++day;
    return temp;
}


bool Date::operator >(const Date& D) // перевантажений оператор ">"
{
    if(year != D.year) return year > D.year;
        
    if(month != D.month) return month > D.month;
        
    if(day != D.day) return day > D.day;
        
    return false;
}


// Функція для введення дати
void Date::SetDate()
{
    string date_str;
    do{
        cin >> date_str;
    } while(!checkDate(date_str));
    day = stoi(date_str.substr(0, 2));
    month = stoi(date_str.substr(3, 2));
    year = stoi(date_str.substr(6, 4));
}


// Функція для отримання поточної дати
Date Date::currentDate()
{
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    Date currentdate;
    currentdate.day = now->tm_mday;
    currentdate.month = now->tm_mon + 1;
    currentdate.year = now->tm_year + 1900;
    return currentdate;
}


// Функція для перевірки коректності введення дати
bool Date::checkDate(string str)
{
    if (str[2] != '.' || str[5] != '.')
    {
        cout << "Помилка. Введіть дату через крапку, наприклад, 01.01.2001.\n";
        return false;
    }
    for (int i = 0; i < 10; i++)
    {
        if (i == 2 || i == 5) continue;
        if (!isdigit(str[i]))
        {
            cout << "Помилка. Введіть дату за допомогою цифр.\n";
            return false;
        }
    }
    int day = stoi(str.substr(0, 2));
    int month = stoi(str.substr(3, 2));
    int year = stoi(str.substr(6, 4));
    
    Date current = currentDate();
    
    if(day > max_days(month, year))
    {
        cout << "Введена неправильна кількість днів для цього місяця\n";
        cout << "Введіть дату: ";
        return false;
    }
        
    if(year > current.year || month <= 0 || month > 12)
    {
        cout << "Помилка. Рік не більше поточного року, місяць лежить в межах від 1 до 12 включно.\n";
        cout << "Введіть дату: ";
        return false;
    }
    else return true;
}


unsigned int Date::YearEnd() //функція визначення терміну, що залишився до кінця року
{
    int days_left = 0;
    for(int i = month; i <= 12; ++i)
    {
        int days = max_days(i, year);
        if(i == month) days_left += days - day;
        else days_left += days;
    }
    return days_left;
}

void Date::Print() // функція для виведення дати
{
        cout << right << setfill('0') << setw(2) << day << "." << setfill('0') << setw(2) << month << "." << year;
}
