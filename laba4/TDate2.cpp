#include "TDate2.h"


void TDate2::inputDate() { // функція для введення
    char dot1, dot2;

    cout << "\nВведіть дату(ММ-ЧЧ-РРРР):";
    cin >> month >> dot1 >> day >> dot2 >> year;

    while (dot1 != '-' || dot2 != '-' || !checkDate()) {
        cout << "\nПомилка введення дати";
        cout << "\nВведіть дату(ММ-ЧЧ-РРРР):";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> month >> dot1 >> day >> dot2 >> year;
    }

    cin.clear();
    cin.ignore(INT_MAX, '\n');
}


void TDate2::print() const { // функція для виведення
    cout << right << setfill('0') << setw(2) << month << "-" << setfill('0') << setw(2) << day << "-" << year << "(TDate2) ";
}
