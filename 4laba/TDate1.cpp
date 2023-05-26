#include "TDate1.h"


void TDate1::inputDate() { // функція для введення
    char dot1, dot2;

    cout << "\nВведіть дату(ЧЧ.ММ.РРРР):";
    cin >> day >> dot1 >> month >> dot2 >> year;

    while (dot1 != '.' || dot2 != '.' || !checkDate()) {
        cout << "\nПомилка введення дати";
        cout << "\nВведіть дату(ЧЧ.ММ.РРРР):";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> day >> dot1 >> month >> dot2 >> year;
    }

    cin.clear();
    cin.ignore(INT_MAX, '\n');
}


void TDate1::print() const { //функція для виведення
    cout << right << setfill('0') << setw(2) << day << "." << setfill('0') << setw(2) << month << "." << year <<"(TDate1) ";
}
