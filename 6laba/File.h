//
// Created by Home on 25.06.2023.
//

#ifndef OP_7LABA_DA_FILE_H
#define OP_7LABA_DA_FILE_H


#include <QtWidgets>
#include <QFile>
#include <QDataStream>


class File {
public:
    static void writeBinaryFile(const QString& filename, const int* data, int size);

    static bool compareBinaryFiles(const QString& filename1, const QString& filename2);

    static int* intersectBinaryFiles(const QString& filename1, const QString& filename2, int& size);

    static int* readBinaryFile(const QString& filename, int& size);

    static void multiplyNumbersInFile(const QString& filename, int factor);
};



#endif //OP_7LABA_DA_FILE_H
