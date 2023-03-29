#include "FileStream.h"


void choisestream(){
    string filename, newfilename, text;
    cout << "Введіть імʼя файлу: ";
    cin >> filename;
    filename += ".txt";
    cout << "Введіть імʼя нового файлу: ";
    cin >> newfilename;
    newfilename += ".txt";

    int num;
    do{
        cout << "\nОберіть дію:\n" << "1) Очистити вміст файлу і почати нові записи;\n2) Доповнити існуючі записи;\n3) Переглянути вміст файлу;\n4) Переглянути вміст у новому файлі;\n5) Закінчити роботу;\n";
        cout << "Дія: ";
        cin >> num;
        switch (num) {
            case 1:
                //очищення вмісту у файлі та запис нового тексту
                clearfile(filename);
                input(filename);
                break;
            case 2:
                // створення файлу, запис тексту
                input(filename);
                break;
            case 3:
                // зчитування змісту у файлі
                text = read(filename);
                cout << text;
                break;
            case 4:
                //запис зміненого тексту в новий файл
                text = read(filename);
                text = letterssymbols(text);
                newfile(newfilename, text);
                text = read(newfilename);
                cout << text;
                break;
        }
    } while (num != 5);
}


void input(string filename){ // запис/доповнення тексту
    ofstream file;
    file.open(filename, ofstream::app);
    if(!file.is_open()){
        cerr << "Неможливо відкрити файл" << endl;
        return;
    }
    string text;
    cout << "Введіть текст: " << endl;
    getline(cin, text);
    do {
        text = "";
        getline(cin, text);
        if (text != "") {
            file << text << endl;
        }
    } while (!text.empty());
    file.close();
}


string read(string filename){ // зчитування тексту у файлі
    ifstream file;
    file.open(filename);
    if(!file.is_open()){
        cout << "Неможливо відкрити файл" << endl;
        return 0;
    }
    string contents, line;
    while (getline(file, line)) {
        contents += line + "\n";
    }
    file.close();
    return contents;
}


void clearfile(string filename){ // очищення вмісту файлу
    ofstream file;
    file.open(filename, ofstream::trunc);
    if(!file.is_open()){
        cout << "Неможливо відкрити файл" << endl;
        return;
    }
    file.close();
}


void newfile(string filename, string text){ // створення нового файлу (пустий)
    ofstream file;
    file.open(filename, ofstream::trunc);
    if(!file.is_open()){
        cout << "Неможливо відкрити файл" << endl;
        return;
    }
    file << text << endl;
    file.close();
}


string letterssymbols(string& str){ // розділення символів. літери на початку, інші символи в кінці
    string letters, symbols, result;
    for (char c : str) {
        if (c == '\n') {
            symbols += c;
            letters = reverse(letters);
            result += letters;
            result += symbols;
            letters.clear();
            symbols.clear();
            continue;
        }
        if (isalpha(c)) {
            letters += c;
        } else {
            symbols += c;
        }
    }
    return result;
}


string reverse(string& letters){ // записує рядок з літер у зворотньому напрямку
    string reversed;
    for(int i = letters.length()-1; i >= 0; i--){
        reversed += letters[i];
    }
    reversed = countletters(reversed);
    return reversed;
}


string countletters(string& reversed) { // заміна послідовностей символів-дублікатів одним символом і, вказаним у квадратних дужках, кількістю повторень
    int count = 0;
    char p = '\0';        // p =>> попередній символ
    string result;
    for (char c: reversed) {
        if (c == p) {
            count++;
        } else {
            p = c;
            if (count > 1) {
                result += "[" + to_string(count) + "]";
            }
            result += p;
            count = 1;
        }
    }
    return result;
}
