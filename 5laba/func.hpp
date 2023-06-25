#include <iostream>
#include "CircularDeque.cpp"

using namespace std;


void mainMenu();

template<typename T>
void whileLoop(CircularDeque<T>& deque, typename CircularDeque<T>::DequeIterator& current); //Цикл для роботи з деком

void inputNumber(int&); //Функція для введення числа
