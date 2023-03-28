#include "func.h"


bool check(string date_str){ // перевірка коректності введення дати
    if (date_str[2] != '.' || date_str[5] != '.') {
        cout << "Помилка. Введіть дату через крапку, наприклад, 01.01.2001.\n";
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) {
            continue;
        }
        if (!isdigit(date_str[i])) {
            cout << "Помилка. Введіть дату за допомогою цифр.\n";
            return false;
        }
    }

    int day = stoi(date_str.substr(0, 2));
    int month = stoi(date_str.substr(3, 2));
    int year = stoi(date_str.substr(6, 4));
    Date current = currentDate();
    int leap_year = (year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0);
    if(year > current.year || month <= 0 || month > 12 || day <= 0 || day > 31){
        cout << "Помилка. Рік не більше поточного року, місяць лежить в межах від 1 до 12 включно, день лежить в межах від 1 до 31 включно\n";
        cout << "Введіть дату: ";
        return false;
    } else if (month == 2 && leap_year && day > 29) {
        cout << "У " << year << " році другий місяць має 29 днів\n";
        cout << "Введіть дату: ";
        return false;
    } else if (month == 2 && !leap_year && day > 28){
        cout << "У " << year << " році другий місяць має 29 днів\n";
        cout << "Введіть дату: ";
        return false;
    } else if (month == 4 || month == 6 || month == 9 || month == 11 && day > 30) {
        cout << "Цей місяць має 30 днів\n";
        cout << "Введіть дату: ";
        return false;
    } else return true;
}


Date inputDate(){ //ввід дати
    Date date;
    string date_str;
    do{
        cin >> date_str;
    } while (!check(date_str));
    date.day = stoi(date_str.substr(0, 2));
    date.month = stoi(date_str.substr(3, 2));
    date.year = stoi(date_str.substr(6, 4));
    return date;
}


Date currentDate(){ //поточна дата
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    Date currentdate;
    currentdate.day = now->tm_mday;
    currentdate.month = now->tm_mon + 1;
    currentdate.year = now->tm_year + 1900;
    return currentdate;
}


int workerExperience(Worker w, Date currentdate){ //роки роботи на підприємстві
    int exp = currentdate.year - w.hiredate.year; // exp = experience
    if (currentdate.month < w.hiredate.month) exp--;
    else if (currentdate.month == w.hiredate.month && currentdate.day < w.hiredate.day) exp--;
    return exp;
}


void inputWorkers(Worker& worker){ // додавання працівника
    bool f = true;
    cout << "Запишіть інформацію про працівника." << endl;
    do{
        cout << "Прізвище: "; cin >> worker.surname;
        for(char c : worker.surname){
            if(!isalpha(c) && c != ' ' && c != '-'){
                cout << "Помилка. Некоректне введення прізвища.\n";
                f = false;
                break;
            } else f = true;
        }
    } while(!f);

    do{
        cout << "Дата народження (наприклад, 10.10.2020): "; worker.birthdate = inputDate();
        cout << "Дата прийому на роботу (наприклад, 10.10.2020): "; worker.hiredate = inputDate();
        if(worker.hiredate.year <= worker.birthdate.year) cout << "Помилка. Некоректне введення дат. Рік прийому на роботу не може бути меншим за рік народження.\n";
    } while (worker.hiredate.year <= worker.birthdate.year);
}


void inputFile(string filename){ // запис у файл
    Worker worker;
    ofstream file;
    file.open(filename, ios::binary | ios::app);
    if (!file) {
        cerr << "Не вдалося відкрити файл з даними про працівників." << endl;
        return;
    }
    inputWorkers(worker);
    file.write((char*)&worker, sizeof(Worker));
    file.close();
}


void readFile(string filename){ // зчитування записів у файлі
    Worker worker;
    ifstream file;
    file.open(filename, ios::binary);
    if (!file) {
        cerr << "Не вдалося відкрити файл з даними про працівників." << endl;
        return;
    }
    while(file.read((char*)&worker, sizeof (Worker))){
        cout << left << setw(12) << worker.surname << ": " << worker.birthdate.day << "." << worker.birthdate.month << "." << worker.birthdate.year << "  " << worker.hiredate.day << "." << worker.hiredate.month << "." << worker.hiredate.year << endl;
    }
    file.close();
}


void clearFile(string filename){ // видалення всіх записів у файлі
    ofstream file;
    file.open(filename, ios::binary | ios::trunc);
    if (!file) {
        cerr << "Не вдалося відкрити файл з даними про працівників." << endl;
        return;
    }
    file.close();
}


void printList(string filename){ // Вивести список працівників, у яких день народження у поточному місяці та які пропрацювати на підприємстві не менше 5-ти років
    Date currentdate = currentDate();
    Worker worker;
    ifstream file;
    file.open(filename, ios::binary);
    if (!file) {
        cerr << "Не вдалося відкрити файл з даними про працівників." << endl;
        return;
    }
    while (file.read((char*)&worker, sizeof (Worker))){
        if (worker.birthdate.month == currentdate.month) {
            int exp = workerExperience(worker, currentdate);
            if (exp >= 5) cout << worker.surname << endl;
        }
    }
    file.close();
}


void newfile(string filename, string newfilename) { // створення нового файлу з інформацією про співробітників, які оформилися на роботу на дане підприємство у віці не старше 25-ти років та пропрацювали на ньому менше 10-ти років
    ifstream file;
    file.open(filename, ios::binary);
    if (!file) {
        cerr << "Не вдалося відкрити файл з даними про працівників." << endl;
        return;
    }
    ofstream newfile;
    newfile.open(newfilename, ios::binary);
    if (!file) {
        cerr << "Не вдалося відкрити файл з даними про працівників." << endl;
        return;
    }

    Worker worker;
    Date currentdate = currentDate();
    int agestart = worker.hiredate.year - worker.birthdate.year;
    if (worker.hiredate.month < worker.birthdate.month) agestart--;
    else if (worker.hiredate.month == worker.birthdate.month && worker.hiredate.day < worker.birthdate.day) agestart--;

    while (file.read((char *) &worker, sizeof(Worker))) {
        if (agestart <= 25) {
            int exp = workerExperience(worker, currentdate);
            if (exp >= 10) newfile.write((char *) &worker, sizeof(Worker));
        }
    }
    newfile.close();
    file.close();
}
