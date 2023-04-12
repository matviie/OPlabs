#include "func.h"
#include "Date.h"

void n1()
{
    // D1
    Date D1;
    cout << "Введіть дату для D1: ";
    D1.SetDate();
    ++D1;
    cout << "\nДата D1 збільшена на 1 місяць: ";
    D1.Print();
    cout << endl;
    
    //D2
    Date D2;
    cout << "\nВведіть дату для D2: ";
    D2.SetDate();
    D2++;
    cout << "Дата D2 збільшена на 1 день: ";
    D2.Print();
    cout << endl;
    
    // D1 > D2
    string d1 = "D1 "; string d2 = "D2 ";
    cout << "\nБільш пізня дата: ";
    if(D1 > D2) 
    {
        cout << d1 << "(";
        D1.Print(); cout << ")";
    }
    else
    {
        cout << d2 << "(";
        D2.Print(); cout << ")";
    }
    cout << endl;
    
    // D3
    Date D3;
    cout << "\nВведіть дату для D3: ";
    D3.SetDate();
    cout << "\nДо кінця " << D3.GetYear() << " залишилось ";
    cout << D3.YearEnd() << " днів." << endl << endl;
    cout << endl;
}


void n2()
{
    // D1
    Date D1;   
    cout << "\nD1: ";
    D1.Print();
    ++D1;
    cout << "\nДата D1 збільшена на 1 місяць: ";
    D1.Print();
    cout << endl;
    
    // D2
    Date D2(D1);
    cout << "\nD2: ";
    D2.Print();
    D2++;
    cout << "\nДата D2 збільшена на 1 день: ";
    D2.Print();
    cout << endl;
    
    // D1 > D2
    string d1 = "D1 "; string d2 = "D2 ";
    cout << "\nБільш пізня дата: ";
    if(D1 > D2)
    {
        cout << d1 << "(";
        D1.Print(); cout << ")";
    }
    else
    {
        cout << d2 << "(";
        D2.Print(); cout << ")";
    }
    cout << endl;
    
    // D3
    Date D3(2023, 4, 14);
    cout << "\nD3: ";
    D3.Print();
    cout << "\nДо кінця " << D3.GetYear() << " залишилось ";
    cout << D3.YearEnd() << " днів." << endl << endl;
    cout << endl;
}

int max_days(int month, int year)
{
    int leap_year = (year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0);
    int days[12]  = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (month == 2 && leap_year) ? 29 : days[month - 1];
}
