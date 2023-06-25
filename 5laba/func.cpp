#include "func.hpp"


template<typename T>
void whileLoop(CircularDeque<T>& deque, typename CircularDeque<T>::DequeIterator& current) {
    int choice;
    T item;

    while (true) {
        cout << "\nCircular Deque:\n";
        cout << "1. Перевірити, чи дек порожній\n";
        cout << "2. Перевірити, чи дек повний\n";
        cout << "3. Очистити дек\n";
        cout << "4. Видалити елемент з початку дека\n";
        cout << "5. Видалити елемент з кінця дека\n";
        cout << "6. Додати елемент на початок дека\n";
        cout << "7. Додати елемент в кінець дека\n";
        cout << "8. Перехід до наступного елемента\n";
        cout << "9. Перехід до попереднього елемента\n";
        cout << "10. Завершити роботу\n";
        cout << "Дія: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (deque.isEmpty()) {
                    cout << "Дек порожній.\n";
                }
                else {
                    cout << "Дек не порожній.\n";
                }
                break;
            case 2:
                if (deque.isFull()) {
                    cout << "Дек повний.\n";
                }
                else {
                    cout << "Дек не повний.\n";
                }
                break;
            case 3:
                deque.clear();
                cout << "Дек очищено.\n";
                break;
            case 4:
                deque.removeFront();
                cout << "Елемент видалено з початку дека.\n";
                break;
            case 5:
                deque.removeRear();
                cout << "Елемент видалено з кінця дека.\n";
                break;
            case 6:
                if (deque.isFull()) {
                    cout << "Дек повний.\n";
                    break;
                }
                cout << "Введіть значення для додавання: ";
                cin >> item;
                deque.insertFront(item);
                cout << "Елемент додано на початок дека.\n";
                break;
            case 7:
                if (deque.isFull()) {
                    cout << "Дек повний.\n";
                    break;
                }
                cout << "Введіть значення для додавання: ";
                cin >> item;
                deque.insertRear(item);
                cout << "Елемент додано в кінець дека.\n";
                break;
            case 10:
                return;
            case 8:
                if (deque.isEmpty()) {
                    cout << "Дек порожній.\n";
                }
                else {
                    cout << "Поточний елемент: " << *current << endl;
                    ++current;
                    cout << "Поточний елемент: " << *current << endl;
                }
                break;
            case 9:
                if (deque.isEmpty()) {
                    cout << "Дек порожній.\n";
                }
                else {
                    cout << "Поточний елемент: " << *current << endl;
                    --current;
                    cout << "Поточний елемент: " << *current << endl;
                }
                break;
            default:
                cout << "Неправильний вибір. Спробуйте ще раз.\n";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                break;
        }
    }
}


void mainMenu() {
    int capacity;
    cout << "Введіть ємність дека: ";
    inputNumber(capacity);

    string dataType;
    cout << "Введіть бажаний тип даних: ";
    cin >> dataType;

    if (dataType == "int") {
        CircularDeque<int> deque(capacity);
        CircularDeque<int>::DequeIterator current = deque.begin();
        whileLoop(deque, current);
    }
    else if (dataType == "double") {
        CircularDeque<double> deque(capacity);
        CircularDeque<double>::DequeIterator current = deque.begin();
        whileLoop(deque, current);
    }
    else if (dataType == "string") {
        CircularDeque<string> deque(capacity);
        CircularDeque<string>::DequeIterator current = deque.begin();
        whileLoop(deque, current);
    }
    else {
        cout << "Невідомий тип даних." << endl;
        return;
    }
}


void inputNumber(int& num) {
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
                    if (i == 0 && (c == '+')) {
                        continue;
                    }
                    else {
                        throw "Неправильний ввід.";
                    }
                }
            }
            num = stoi(input);
            if (num < 0) {
                throw "Число не може бути меньше 0.";
            }
            return;
        }
        catch (const out_of_range& e) {
            cout << "Число занадто велике. Спробуйте ще раз:";
        }
        catch (const char* message) {
            cout << message << " Спробуйте ще раз:";
        }
    }
}
