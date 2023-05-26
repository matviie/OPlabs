#include "func.h"


void mainMenu() { // меню для користувача
    int n = 0, m = 0;
    TDate1 one;
    TDate2 two;
    TDate *arr[2] = {&one, &two};
    cout << "Введіть початкову дату.";
    arr[0]->inputDate();
    cout << "\nВведіть кінцеву дату.";
    while (true) { // перевірка кінцевої дати
        arr[1]->inputDate();
        if (*arr[0] > *arr[1]) {
            cout << "Кінцева дата не може бути меншою за початкову\n";
        } else if (*arr[0] == *arr[1]) {
            cout << "Кінцева дата не може бути рівною з початковою\n";
        } else
            break;
    }
    cout << "\nВведіть кількість елементів TDate1: ";
    inputNumber(n);
    cout << "\nВведіть кількість елементів TDate2: ";
    inputNumber(m);

    if (n == 0 && m == 0) {
        cout << "Дякую за роботу! Немає дат для роботи програми!";
        return;
    }

    arrayDate Date(n, m);

    cout << "\nДати які входят в період ("; arr[0]->print(); cout << " - ";
    arr[1]->print(); cout << "):\n";
    Date.findPeriodDate(*arr[0], *arr[1]);
    cout << "\nНайпізніша дата:\n";
    Date.printOne(Date.findIndexLateDate());
    increaseAndDecrease(Date);
    cout << "\nДати які входят в період ("; arr[0]->print(); cout << " - ";
    arr[1]->print(); cout << "):\n";
    Date.findPeriodDate(*arr[0], *arr[1]);
}


void inputNumber(int &num) { // функція для введення числа
    while (true) {
        try {
            string input;
            getline(cin, input);

            if (input.empty()) {
                throw "Введено порожній рядок.";
            }

            for (size_t i = 0; i < input.length(); i++) {
                char c = input[i];

                if (!isdigit(c)) {
                    if (i == 0) {
                        continue;
                    } else {
                        throw "Неправильний ввід.";
                    }
                }
            }

            num = stoi(input);
            if (num < 0) {
                throw "Число не може бути меньше 0.";
            }
            return;

        } catch (const out_of_range &e) {
            cout << "Число занадто велике. Спробуйте ще раз:";

        } catch (const char *message) {
            cout << message << " Спробуйте ще раз:";
        }
    }
}


void increaseAndDecrease(arrayDate &arr) { // функція для збільшення або зменшення дати
    char t;
    int d, m, y;

    cout << "\nВи бажаєте збільшити чи зменшити?(Y/N) ";
    cin >> t;

    while (t != 'y' && t != 'Y' && t != 'n' && t != 'N') {
        cout << "\nТакого варіанту не існує.\nСпробуйте ще раз!";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> t;
    }

    cin.clear();
    cin.ignore(INT_MAX, '\n');

    cout << "\nВведіть кількість днів:";
    inputNumber(d);
    cout << "\nВведіть кількість місяців:";
    inputNumber(m);
    cout << "\nВведіть кількість років:";
    inputNumber(y);

    if (t == 'Y' || t == 'y') {
        arr.increaseOrDecrease(true, d, m, y);
    } else
        arr.increaseOrDecrease(false, d, m, y);
}
