//
// Created by Home on 25.06.2023.
//

#include "MainWindow.h"



MainWindow::MainWindow(QWidget* parent): QMainWindow(parent){
    setWindowTitle("23");

    QLabel* label_file_1 = new QLabel("Файл 1", this);
    QLabel* label_file_2 = new QLabel("Файл 2", this);
    QLabel* label_num = new QLabel("Введіть число n для множення:", this);
    textEdit_file1 = new QTextEdit(this);
    textEdit_file2 = new QTextEdit(this);
    lineEdit_factor = new QLineEdit(this);

    setButton = new QPushButton("Вирішити", this);

    setCentralWidget(new QWidget(this));
    QGridLayout* layout = new QGridLayout(centralWidget());
    layout->addWidget(label_file_1, 0, 0);
    layout->addWidget(label_file_2, 0, 1);
    layout->addWidget(textEdit_file1, 1, 0, 2, 1);
    layout->addWidget(textEdit_file2, 1, 1, 2, 1);
    layout->addWidget(label_num, 3, 0);
    layout->addWidget(lineEdit_factor, 3, 1);
    layout->addWidget(setButton, 4, 0, 1, 2);

    connect(setButton, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
}


void MainWindow::handleButtonClick(){

    QString file1 = textEdit_file1->toPlainText();
    QString file2 = textEdit_file2->toPlainText();
    bool ok;
    int factor = lineEdit_factor->text().toInt(&ok);

    try {
        if (file1.isEmpty() || file2.isEmpty()) {
            throw QString("Введіть значення для обох файлів!");
        }

        if (!ok) {
            throw QString("Введено неприпустиме значення для числа n!");
        }

        int size1 = 0;
        int* numbers1 = readNumbersFromString(file1, size1);
        int size2 = 0;
        int* numbers2 = readNumbersFromString(file2, size2);

        File::writeBinaryFile("file1.bin", numbers1, size1);
        File::writeBinaryFile("file2.bin", numbers2, size2);

        int intersectedSize = 0;
        int* intersectedNumbers = File::intersectBinaryFiles("file1.bin", "file2.bin", intersectedSize);
        File::writeBinaryFile("intersected.bin", intersectedNumbers, intersectedSize);

        File::multiplyNumbersInFile("intersected.bin", factor);

        int multipliedSize = 0;
        int* multipliedNumbers = File::readBinaryFile("intersected.bin", multipliedSize);

        bool filesEqual = File::compareBinaryFiles("file1.bin", "file2.bin");

        QString result;
        if (multipliedNumbers != nullptr && multipliedSize > 0) {
            result += "Числа, які містяться в обох файлах та помножені на " + QString::number(factor) + ":\n";
            for (int i = 0; i < multipliedSize; i++) {
                result += QString::number(multipliedNumbers[i]) + "\n";
            }
        } else {
            result = "Файли file1.bin і file2.bin не містять однакові числа.";
        }

        QMessageBox::information(this, "Результат", result);

        delete[] numbers1;
        delete[] numbers2;
        delete[] intersectedNumbers;
        delete[] multipliedNumbers;

    } catch (const QString& errorMessage) {
        QMessageBox::critical(this, "Помилка", errorMessage);
    }
}


int* MainWindow::readNumbersFromString(const QString& text, int& size) {
    QStringList lines = text.split('\n', Qt::SkipEmptyParts);
    int* numbers = nullptr;
    int count = 0;
    for (const QString& line : lines) {
        bool ok;
        qint64 num = line.toLongLong(&ok);
        if (!ok) {
            throw QString("Переповнення при зчитуванні числа: '%1' (Введено неприпустимий символ)").arg(line);
        }
        if (num > std::numeric_limits<int>::max()) {
            throw QString("Переповнення при зчитуванні числа: '%1' (переповнення зверху)").arg(line);
        }
        if (num < std::numeric_limits<int>::min()) {
            throw QString("Переповнення при зчитуванні числа: '%1' (переповнення знизу)").arg(line);
        }

        int* temp = new int[count + 1];
        for (int i = 0; i < count; i++) {
            temp[i] = numbers[i];
        }
        temp[count] = static_cast<int>(num);
        delete[] numbers;
        numbers = temp;
        count++;
    }
    size = count;
    return numbers;
}
