#include <iostream>

using namespace std;


template<typename T>
class CircularDeque {
private:
    T* dequeArray;  // Масив для зберігання елементів дека
    int capacity;   // Максимальна ємність дека
    int front;      // Індекс першого елемента
    int rear;       // Індекс останнього елемента
    int count;      // Кількість елементів в деку

public:
    CircularDeque(int size);

    ~CircularDeque();

    bool isEmpty() const;               // функція, що перевіряє, чи є дек порожнім

    bool isFull();                      //функція, що перевіряє, чи є дек повним

    void clear();                       //функція, що очищує дек, видаляючи всі його елементи

    void removeFront();                 //функція, що видаляє елемент з початку дека

    void removeRear();                  //функція, що видаляє елемент з кінця дека

    void insertFront(const T& item);    //функція, що вставляє новий елемент на початок дека

    void insertRear(const T& item);     //функція, що вставляє новий елемент в кінець дека

    template<typename T1>
    friend ostream& operator<<(ostream& os, const CircularDeque<T1>& deque);//

    //Клас ітератор для дека
    class DequeIterator {
    private:
        const CircularDeque<T>& deque;  // Посилання на дек
        int current;                    // Поточна позиція ітератора

    public:
        DequeIterator(const CircularDeque<T>& dq, int pos) : deque(dq), current(pos) {}

        bool isEnd();           //функція, що перевіряє, чи досягнуто кінця дека

        bool isBegin();         //функція, що перевіряє, чи досягнуто початку дека

        void next();            //функція, що пересуває ітератор до наступного елемента дека

        void previous();        //функція, що пересуває ітератор до попереднього елемента дека

        const T& value();       //функція, що повертає значення поточного елемента ітератора

        DequeIterator operator++() {
            DequeIterator temp = *this;
            next();
            return temp;
        }

        DequeIterator operator--() {
            DequeIterator temp = *this;
            previous();
            return temp;
        }

        const T& operator*() {
            return value();
        }
    };

    DequeIterator begin() const;
};
