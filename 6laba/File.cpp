//
// Created by Home on 25.06.2023.
//

#include "File.h"


void File::writeBinaryFile(const QString& filename, const int* data, int size) {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream stream(&file);
        for (int i = 0; i < size; i++) {
            stream << data[i];
        }
        file.close();
    }
}


bool File::compareBinaryFiles(const QString& filename1, const QString& filename2) {
    QFile file1(filename1);
    QFile file2(filename2);
    if (file1.open(QIODevice::ReadOnly) && file2.open(QIODevice::ReadOnly)) {
        QDataStream stream1(&file1);
        QDataStream stream2(&file2);
        while (!stream1.atEnd() && !stream2.atEnd()) {
            int num1, num2;
            stream1 >> num1;
            stream2 >> num2;
            if (num1 != num2) {
                file1.close();
                file2.close();
                return false;
            }
        }
        bool filesEqual = stream1.atEnd() && stream2.atEnd();
        file1.close();
        file2.close();
        return filesEqual;
    }
    return false;
}


int* File::intersectBinaryFiles(const QString& filename1, const QString& filename2, int& size) {
    int* intersectedNumbers = nullptr;
    QFile file1(filename1);
    QFile file2(filename2);
    if (file1.open(QIODevice::ReadOnly) && file2.open(QIODevice::ReadOnly)) {
        QDataStream stream1(&file1);
        QDataStream stream2(&file2);

        // Зчитуємо числа з першого файлу у динамічний масив
        int* numbers1 = nullptr;
        int count1 = 0;
        while (!stream1.atEnd()) {
            int num;
            stream1 >> num;
            int* temp = new int[count1 + 1];
            for (int i = 0; i < count1; i++) {
                temp[i] = numbers1[i];
            }
            temp[count1] = num;
            delete[] numbers1;
            numbers1 = temp;
            count1++;
        }

        // Перевіряємо кожне число з другого файлу на наявність у динамічному масиві з першого файлу
        int* tempIntersected = nullptr;
        int intersectedCount = 0;
        while (!stream2.atEnd()) {
            int num2;
            stream2 >> num2;
            for (int i = 0; i < count1; i++) {
                if (numbers1[i] == num2) {
                    int* temp = new int[intersectedCount + 1];
                    for (int j = 0; j < intersectedCount; j++) {
                        temp[j] = tempIntersected[j];
                    }
                    temp[intersectedCount] = num2;
                    delete[] tempIntersected;
                    tempIntersected = temp;
                    intersectedCount++;
                    break;
                }
            }
        }

        delete[] numbers1;
        file1.close();
        file2.close();
        intersectedNumbers = tempIntersected;
        size = intersectedCount;
    }
    return intersectedNumbers;
}


int* File::readBinaryFile(const QString& filename, int& size) {
    int* numbers = nullptr;
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream stream(&file);
        int count = 0;
        while (!stream.atEnd()) {
            int num;
            stream >> num;
            int* temp = new int[count + 1];
            for (int i = 0; i < count; i++) {
                temp[i] = numbers[i];
            }
            temp[count] = num;
            delete[] numbers;
            numbers = temp;
            count++;
        }
        file.close();
        size = count;
    }
    return numbers;
}


void File::multiplyNumbersInFile(const QString& filename, int factor) {
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QDataStream stream(&file);
        while (!stream.atEnd()) {
            int num;
            stream >> num;
            num *= factor;
            file.seek(file.pos() - sizeof(int));
            stream << num;
        }
        file.close();
    }
}

