#include "FileStream.h"
#include "FilePointer.h"


int checkArgument(int argc, char* argv[]){
    if (argc != 3) {
        cout << "Error" << endl;
        return -1;
    }
    else if(!strcmp(argv[1], "-mode")){
        if(!strcmp(argv[2], "FilePointer")){
            cout << "file pointer is runing" << endl;
            return 1;
        }
        else if(!strcmp(argv[2], "FileStream")){
            cout << "file stream is runing" << endl;
            return 2;
        }
    }
    cout << "invalid arguments" << endl;
    return -1;
}


int main(int argc, char* argv[]) {
    int choice = checkArgument(argc, argv); //виклик фунції для перевірки аргуменів
    switch (choice) {
        case 1:
            choisepointer(); // функція для початку роботи з char* and File*
            break;
        case 2:
            choisestream(); // функція для початку роботи з ifstream/ofstream та через клас string
            break;
        default:
            return -1;
    }
}
