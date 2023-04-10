#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


class Date;
class Worker;

void print_menu(); // Функція для виведення меню
bool menu(Worker*&, int&); // Функція для обробки введеного користувачем варіанту з меню

void addWorker(Worker*&, int&); // Функція для додавання нового працівника
void readList(Worker*, int); // Функція для виведення списку працівників
void oldestWorker(Worker* workers, int size); // Функція для визначення найстаршого працівника
