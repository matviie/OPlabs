#include "CircularDeque.hpp"


template<typename T>
CircularDeque<T>::CircularDeque(int size)
{
    dequeArray = new T[size];
    capacity = size;
    front = rear = -1;
    count = 0;
}


template<typename T>
CircularDeque<T>::~CircularDeque()
{
    delete[] dequeArray;
}


// функція, що перевіряє, чи є дек порожнім
template<typename T>
bool CircularDeque<T>::isEmpty() const
{
    return count == 0;
}


template<typename T>
bool CircularDeque<T>::isFull() //функція, що перевіряє, чи є дек повним
{
    return count == capacity;
}


template<typename T>
void CircularDeque<T>::clear() //функція, що очищує дек, видаляючи всі його елементи
{
    front = rear = -1;
    count = 0;
}


template<typename T>
void CircularDeque<T>::removeFront() //функція, що видаляє елемент з початку дека
{
    if (isEmpty()) {
        return;
    }

    if (front == rear) {
        clear();
    }
    else {
        front = (front + 1) % capacity;
        count--;
    }
}


template<typename T>
void CircularDeque<T>::removeRear() //функція, що видаляє елемент з кінця дека
{
    if (isEmpty()) {
        return;
    }
    if (front == rear) {
        clear();
    }
    else {
        rear = (rear - 1 + capacity) % capacity;
        count--;
    }
}


template<typename T>
void CircularDeque<T>::insertFront(const T& item) //функція, що вставляє новий елемент на початок дека
{
    if (isFull()) {
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    }
    else {
        front = (front - 1 + capacity) % capacity;
    }
    dequeArray[front] = item;
    count++;
}


template<typename T>
void CircularDeque<T>::insertRear(const T& item) //функція, що вставляє новий елемент в кінець дека
{
    if (isFull()) {
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % capacity;
    }

    dequeArray[rear] = item;
    count++;
}


template <typename T1>
ostream& operator<<(ostream& os, const CircularDeque<T1>& deque)
{
    typename CircularDeque<T1>::DequeIterator it = deque.begin();
    os << "Deque: [";
    if (!deque.isEmpty()) {
        os << *it;
        ++it;
        while (!it.isEnd()) {
            os << ", " << *it;
            ++it;
        }
    }
    else {
        os << "None";
    }
    os << "]";
    return os;
}


template<typename T>
typename CircularDeque<T>::DequeIterator CircularDeque<T>::begin() const //
{
    return DequeIterator(*this, front);
}


template<typename T>
bool CircularDeque<T>::DequeIterator::isEnd() //
{
    return current == (deque.rear + 1) % deque.capacity;
}


template<typename T>
bool CircularDeque<T>::DequeIterator::isBegin()
{
    return current == deque.front;
}


template<typename T>
void CircularDeque<T>::DequeIterator::next() {
    if (!deque.isEmpty()) {
        if (current == deque.rear)
            current = deque.front;
        else
            current = (current + 1) % deque.capacity;
    }
}


template<typename T>
void CircularDeque<T>::DequeIterator::previous() {
    if (!deque.isEmpty()) {
        if (current == deque.front)
            current = deque.rear;
        else
            current = (current - 1 + deque.capacity) % deque.capacity;
    }
}


template<typename T>
const T& CircularDeque<T>::DequeIterator::value() //
{
    return deque.dequeArray[current];
}
