#include "Worker.h"


// Функція для введення ПІБ та дати народження працівника
void Worker::SetValues()
{
    char c;
    cout << "Введіть ПІБ працівника: ";
    cin >> surname; cin >> c;
    cin >> name; cin >> c;
    cin >> patronymic;
    
    birthdate.SetDate(); 
}
