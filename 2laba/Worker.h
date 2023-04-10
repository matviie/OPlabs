#include "Date.h"

using namespace std;

class Date;

class Worker
{
    string surname;
    string name;
    string patronymic;
    
    Date birthdate;
    
public:
    
    Worker(){}
    
    void SetValues(); // Функція для введення ПІБ та дати народження працівника
    
    string GetSurname() { return surname; }
    string GetName() { return name; }
    string GetPatronymic() { return patronymic; }
    
   
    friend void readList(Worker* arr, int size); // Функція для виведення списку працівників
    friend void oldestWorker(Worker* workers, int size); // Функція для визначення найстаршого працівника
};
