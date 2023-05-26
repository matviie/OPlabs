#include "array.h"


arrayDate::arrayDate(int n, int m) { // конструктор з параметрами
    size = n + m;
    array = new TDate *[size];

    int i;
    for (i = 0; i < n; i++) {
        array[i] = new TDate1;
        array[i]->inputDate();
    }
    for (; i < size; i++) {
        array[i] = new TDate2;
        array[i]->inputDate();
    }
}


arrayDate::~arrayDate() {
    for (int i = 0; i < size; i++) {
        delete array[i];
    }
    size = 0;
    delete[] array;
}


int arrayDate::findIndexLateDate() const { // функція для знаходження найпізнішої дати
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (*array[i] > *array[index]) {
            index = i;
        }
    }

    return index;
}


void arrayDate::arrayPlusOne(int *arraySize, TDate ***dArray) const { // функція для збільшення масив на один елемент
    TDate **newArray = new TDate *[*arraySize + 1];
    for (int i = 0; i < *arraySize; i++) {
        newArray[i] = (*dArray)[i];
    }
    delete[] *dArray;
    *dArray = newArray;
}


TDate **arrayDate::findPeriodDate(const TDate &D1, const TDate &D2) const { // функція для знаходження дат в межах періоду
    TDate **arr = new TDate *[1];
    int s = 0;
    for (int i = 0; i < size; i++) {
        if (*array[i] > D1 && *array[i] < D2) {
            arr[s++] = array[i];
            arrayPlusOne(&s, &arr);
        }
    }
    printArray(arr, s);
    return arr;
}


void arrayDate::printArray(TDate **arr, int s) const { // функція для виводу масиву
    for (int i = 0; i < s; i++) {
        arr[i]->print();
    }
}


void arrayDate::printOne(int i) const { // функція для виводу найпізнішої дати
    array[i]->print();
}


void arrayDate::increaseOrDecrease(bool choice, int d, int m, int y) {
    if (choice) {
        for (int i = 0; i < size; i++) {
            array[i]->increase(d, m, y);
            printOne(i);
        }
    } else {
        for (int i = 0; i < size; i++) {
            array[i]->decrease(d, m, y);
            printOne(i);
        }
    }
}
