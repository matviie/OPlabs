#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

void choisepointer();

void file_name(char* name);
char* input_();
void write_text_in_file(char* filename, char* text);
void append_text(char* filename, char* text);
char* read_(char* filename);

char* letterssymbols_c(char* text);
char* reverse_c(char* letters);
char* countletters_c(char* reversed);
