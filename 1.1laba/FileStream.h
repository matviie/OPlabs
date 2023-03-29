#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void choisestream();

void input(string filename);
string read(string filename);
void clearfile(string filename);
void newfile(string filename, string text);

string letterssymbols(string& str);
string reverse(string& letters);
string countletters(string& reversed);
