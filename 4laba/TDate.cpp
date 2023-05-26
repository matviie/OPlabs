#include "TDate.h"


TDate::TDate() { // конструктор за замовчуванням
    day = 0;
    month = 0;
    year = 0;
}


TDate::TDate(int d, int m, int y) { // конструтор з параметрами
    year = y;
    month = m;
    day = d;
}


bool TDate::operator==(const TDate &other) const { // перевантажений оператор ==
    return day == other.day && month == other.month && year == other.year;
}


bool TDate::operator<(const TDate &D) const { // перевантажений оператор <
    if (year != D.year) return year < D.year;

    if (month != D.month) return month < D.month;

    if (day != D.day) return day < D.day;

    return false;
}


bool TDate::operator>(const TDate &D) const { // перевантажений оператор >
    if (year != D.year) return year > D.year;

    if (month != D.month) return month > D.month;

    if (day != D.day) return day > D.day;

    return false;
}

void TDate::decrease(int d, int m, int y) { // функція для зменшення дати
    day -= d;
    month -= m;
    year -= y;
    fixDate();
}


void TDate::increase(int d, int m, int y) { // функція для збільшення дати
    day += d;
    month += m;
    year += y;
    fixDate();
}


void TDate::fixDate() { // функція, за допомогою якої значення дати при зменшенні чи збільшенні не можуть бути помилковими (наприклад, 39.20.2000)
    while (month > 12) {
        month -= 12;
        year++;
    }
    while (month <= 0) {
        month += 12;
        year--;
    }
    while (day > GetDaysCount(month, year)) {
        day -= GetDaysCount(month, year);
        month++;
    }
    while (day <= 0) {
        day += GetDaysCount(month, year);
        month--;
    }
    if (year > 9999) {
        cout << "Рік було зменшено до 9999";
        year = 9999;
    } else if (year < 1) {
        cout << "Рік було збільшено до 1";
        year = 1;
    }
    if (!checkDate()) {
        fixDate();
    }
}


bool TDate::checkDate() { // функція для перевірки дати на правильність
    if (day < 1 || day > GetDaysCount(month, year) ||
        month < 1 || month > 12 || year < 1 || year > 9999) {
        cout << "Ви ввели недопустимі значення!";
        return false;
    }

    return true;
}


int TDate::GetDaysCount(int myMonth, int myYear) { // функція для отримання кількості днів в місяці
    if (myMonth < 1 || myMonth > 12) {
        return -1;
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (myMonth == 2) {
        if (myYear % 4 == 0) {
            if (myYear % 100 == 0 && myYear % 400 != 0) {
                return 28;
            }
            return 29;
        }
    }

    return daysInMonth[myMonth - 1];
}
