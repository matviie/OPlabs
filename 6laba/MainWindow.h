//
// Created by Home on 25.06.2023.
//

#ifndef OP_7LABA_DA_MAINWINDOW_H
#define OP_7LABA_DA_MAINWINDOW_H

#include "File.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
    QPushButton* setButton;
    QTextEdit* textEdit_file1;
    QTextEdit* textEdit_file2;
    QLineEdit* lineEdit_factor;
public:
    MainWindow(QWidget* parent = nullptr);

private slots:

    void handleButtonClick();
    int* readNumbersFromString(const QString& text, int& size);
};

#endif //OP_7LABA_DA_MAINWINDOW_H
