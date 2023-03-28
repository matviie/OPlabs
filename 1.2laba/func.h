#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

struct Date{
    int day;
    int month;
    int year;
};

struct Worker{
    string surname;
    Date birthdate;
    Date hiredate;
};

Date inputDate();
Date currentDate();

int workerExperience(Worker w, Date currentdate);

void inputWorkers(Worker& worker);

void inputFile(string filename);
void readFile(string filename);
void clearFile(string filename);

void printList(string filename);

void newfile(string filename, string newfilename);


