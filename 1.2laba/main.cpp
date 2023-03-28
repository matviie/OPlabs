#include "func.h"


int main() {
    int n;
    char s;
    string filename = "file.txt", newfilename = "new.txt";

    cout << "Оберіть дію:\n1) Очистити вміст файлу і почати нові записи;\n2) Доповнити існуючі записи;\n3) Переглянути вміст файлу;\n4) Закінчити роботу з файлом та перейти до списків\n";
    do{
        cout << "Дія: ";
        cin >> n;
        switch (n) {
            case 1:
                clearFile(filename);
                inputFile(filename);
                break;
            case 2:
                do{
                    inputFile(filename);
                    cout << "Ви хочете додати нового працівника? (-/+)\n";
                    cin >> s;
                    if(s == '-') break;
                } while(s == '+');
                break;
            case 3:
                readFile(filename);
                break;
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    } while (n != 4);

    cout << "-------------------------------------------\nСписок працівників, у яких день народження у поточному місяці та \nякі пропрацювати на підприємстві не менше 5-ти років:\n";
    printList(filename);
    cout << "-------------------------------------------\nСтворення нового файлу та перегляд його вмісту, де знаходиться \nінформація про робітників, які оформилися на роботу на дане підприємство \nу віці не старше 25-ти років та пропрацювали на ньому менше 10-ти років.\n";
    newfile(filename, newfilename);
    readFile(newfilename);
}
