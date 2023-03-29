#include "FilePointer.h"

void choisepointer(){
    char* filename_ = (char*) malloc(256 * sizeof(char));
    char* newfilename_ = (char*) malloc(256 * sizeof(char));
    cout << "Введіть імʼя файлу: ";
    file_name(filename_);
    cout << "Введіть імʼя нового файлу: ";
    file_name(newfilename_);

    char* text_;
    int num;
    do{
        cout << "\nОберіть дію:\n" << "1) Очистити вміст файлу і почати нові записи;\n2) Доповнити існуючі записи;\n3) Переглянути вміст файлу;\n4) Переглянути вміст у новому файлі;\n5) Закінчити роботу;\n";
        cout << "Дія: ";
        cin >> num;
        char c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        switch (num) {
            case 1: //створення файлу, запис тексту, стирає старий текст
                cout << "Введіть текст: ";
                text_ = input_();
                write_text_in_file(filename_, text_);
                break;
            case 2: //доповнення тексту
                cout << "Введіть текст: ";
                text_ = input_();
                append_text(filename_, text_);
                break;
            case 3: //зчитування змісту у файлі
                text_ = read_(filename_);
                cout << text_;
                break;
            case 4: //запис зміненого тексту в новий файл
                text_ = read_(filename_);
                text_ = letterssymbols_c(text_);
                write_text_in_file(newfilename_, text_);
                text_ = read_(newfilename_);
                cout << text_;
                free(text_);
                break;
        }
    } while (num != 5);
    free(filename_);
    free(newfilename_);
}


void file_name(char* name){ // задання назви файлу
    char c;
    int size = 0;
    while (cin.get(c)){
        if(c == '\n'){
            break;
        }
        name[size] = c;
        size++;
    }
    strcat(name, ".txt");
}


char* input_(){ // введення тексту
    char c;
    bool check = false;
    int size = 0, size_max = 256;
    char* text_ = (char*) calloc(size_max, sizeof(char));
    while(cin.get(c)){
        if(c == '\n'){
            if(check) break;
            check = true;
        } else {
            check = false;
        }
        if (size == size_max) {
            size_max *= 2;
            char* temp = (char*)calloc(size_max, sizeof(char));
            for (int i = 0; i < size; i++) {
                temp[i] = text_[i];
            }
            free(text_);
            text_ = temp;
        }
        text_[size] = c;
        size++;
    }
    text_[size] = '\0';
    return text_;
}


void write_text_in_file(char* filename, char* text){ //запис нового тексту у файл
    FILE* file = fopen(filename, "w");
    if (file == nullptr) {
        cerr << "Неможливо відкрити файл" << endl;
        return;
    }
    fputs(text, file);
    fclose(file);
}


void append_text(char* filename, char* text){ // доповнення тексту
    FILE* file = fopen(filename, "a+");
    if (file == nullptr) {
        cerr << "Неможливо відкрити файл" << endl;
        return;
    }
    fputs(text, file);
    fclose(file);
}


char* read_(char* filename){ // зчитування тексту у файлі
    FILE* file = fopen(filename, "r");
    if (file == nullptr) {
        cerr << "Неможливо відкрити файл" << endl;
        return nullptr;
    }
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);
    char* array = (char*)calloc(file_size, sizeof(char));
    fread(array, sizeof(char), file_size, file);
    array[file_size] = '\0';
    fclose(file);
    return array;
}


char* letterssymbols_c(char* text){ // розділення символів. літери на початку, інші символи в кінці
    char* letters = (char*)calloc((strlen(text)+1), sizeof(char));
    char* symbols = (char*)calloc((strlen(text)+1), sizeof(char));
    char* result = (char*)calloc((strlen(text)+1), sizeof(char));
    for (int i = 0, j = 0, k = 0; i < strlen(text); i++) {
        if(text[i] == '\n'){
            symbols[j++] = text[i];
            letters = reverse_c(letters);
            strcat(result, letters);
            strcat(result, symbols);
            free(letters);
            free(symbols);
            letters = (char*)calloc((strlen(text)+1), sizeof(char));
            symbols = (char*)calloc((strlen(text)+1), sizeof(char));
            k = j = 0;
            continue;
        }
        if (isalpha(text[i])) {
            letters[k++] = text[i];
        } else {
            symbols[j++] = text[i];
        }
    }
    free(letters);
    free(symbols);
    return result;
}


char* reverse_c(char* letters){ // перетворення порядку літер. зворотній порядок їхнього слідування
    char* reversed = (char*)calloc((strlen(letters)+1), sizeof(char));
    for (int i = strlen(letters)-1, j = 0; i >= 0; i--, j++) {
        reversed[j] = letters[i];
    }
    reversed = countletters_c(reversed);
    return reversed;
}


char* countletters_c(char* reversed){ // заміна послідовностей символів-дублікатів одним символом і, вказаним у квадратних дужках, кількістю повторень
    int count = 0;
    char p = '\0';
    char* result = (char*)calloc(strlen(reversed)* 2, sizeof(char));
    for (int i = 0, j = 0; i < strlen(reversed); i++) {
        char c = reversed[i];
        if (c == p) {
            count++;
        } else {
            p = c;
            if (count > 1) {
                char num[10];
                sprintf(num, "%d", count);
                strcat(result, "[");
                strcat(result, num);
                strcat(result, "]");
                j += 2 + sprintf(num, "%d", count);
            }
            result[j++] = p;
            count = 1;
        }
    }
    result[strlen(result)] = '\0';
    return result;
}
