#include "func.h"
#include "Worker.h"


// Функція для виведення меню
void print_menu() {
    cout << "\n\nОберіть дію: " << endl;
    cout << "1) Переглянути список працівників;" << endl;
    cout << "2) Додати нового працівника;" << endl;
    cout << "3) Визначити найстаршого працівника;" << endl;
    cout << "4) Завершити роботу." << endl;
}


// Функція для обробки введеного користувачем варіанту з меню
bool menu(Worker*& workers, int& size)
{
    int n;
    print_menu();
    
    cout << "Дія: "; cin >> n;
    switch (n) {
        case 1:
            readList(workers, size);
            break;
        case 2:
            addWorker(workers, size);
            break;
        case 3:
            oldestWorker(workers, size);
            break;
        default:
            return true;
    }
    return false;
}


// Функція для додавання нового працівника
void addWorker(Worker*& arr, int& size)
{
    Worker* new_arr = new Worker[size + 1];
    for (int i = 0; i < size; i++) { new_arr[i] = arr[i]; }
    new_arr[size].SetValues();
    delete[] arr;
    arr = new_arr; // Переназначити вказівник на новий масив
    size++;
}


// Функція для виведення списку працівників
void readList(Worker* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\nПІБ: " << arr[i].GetSurname() << " " << arr[i].GetName() << " " << arr[i].GetPatronymic() << endl;
        cout << "Дата народження: " << right << setw(2) << arr[i].birthdate.GetDay() << "." << setw(2) << arr[i].birthdate.GetMonth() << "." << arr[i].birthdate.GetYear() << endl;
    }
}


// Функція для визначення найстаршого працівника
void oldestWorker(Worker* workers, int size)
{
    Worker oldest = workers[0];
    for(int i = 1; i < size; i++)
    {
        if(workers[i].birthdate < oldest.birthdate)oldest = workers[i];
    }
    cout << "\nПІБ: " << oldest.GetSurname() << " " << oldest.GetName() << " " << oldest.GetPatronymic() << endl;
    cout << "Дата народження: " << right << setw(2) << oldest.birthdate.GetDay() << "." << setw(2) << oldest.birthdate.GetMonth() << "." << oldest.birthdate.GetYear() << endl;
}
