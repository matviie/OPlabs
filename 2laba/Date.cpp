#include "Date.h"


// Функція для введення дати
void Date::SetDate()
{
    cout << "Введіть дату народження працівника: ";
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
    
    int leap_year = (year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0);
    
    if(year > current.year || month <= 0 || month > 12 || day <= 0 || day > 31)
    {
        cout << "Помилка. Рік не більше поточного року, місяць лежить в межах від 1 до 12 включно, день лежить в межах від 1 до 31 включно\n";
        cout << "Введіть дату: ";
        return false;
    }
    else if (month == 2 && leap_year && day > 29)
    {
        cout << "У " << year << " році другий місяць має 29 днів\n";
        cout << "Введіть дату: ";
        return false;
    }
    else if (month == 2 && !leap_year && day > 28)
    {
        cout << "У " << year << " році другий місяць має 29 днів\n";
        cout << "Введіть дату: ";
        return false;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        cout << "Цей місяць має 30 днів\n";
        cout << "Введіть дату: ";
        return false;
    }
    else return true;
}


// Перевантаження оператора "<" для порівняння дат
bool Date::operator <(Date& d)
{
    if(year != d.year) return year < d.year;
    
    if(month != d.month) return month < d.month;
    
    if(day != d.day) return day < d.day;
    
    return false;
}
