//Розробити клас "Працівник", який характеризує ПІБ працівника, датою
//його народження (у форматі ММ-ДД-РРРР). Створити масив обʼєктів даного
//класу. Визначити найстаршого працівника (на вказану дату).


#include "func.h"
#include "Worker.h"


int main() {
    int arr_size = 0;
    
    Worker *workers;
    workers = new Worker[arr_size];
    
    bool should_exit;
    
    do{
        should_exit = menu(workers, arr_size);
    } while(!should_exit);
    
    delete[] workers;
}
