#include "load.h"
using std::string;
using std::ifstream;
using std::endl;
using std::cout;

/* the primary difference between the two methods, is that the testingMode() function
reads from the /tests folder for a file. Whereas the loadGame() function reads from
the /saves folder. Currently deciding whether to make them both the same folder and 
just changing the extension (.test or .save) then we can do it that way. */

void testingMode(std::string fileName) {
    cout << "you have now entered the super secret testing mode!" << std::endl;
    cout << std::endl;

    string fileText;
    ifstream loadedFile;
    loadedFile.open(".//tests//" + fileName);

    while(getline(loadedFile, fileText)) {
        cout << fileText << endl;
    }
    cout << endl;
}

void loadGame(std::string fileName) {
    string fileText;
    ifstream loadedFile;
    loadedFile.open(".//saves//" + fileName);

    while(getline(loadedFile, fileText)) {
        cout << fileText << endl;
    }
    cout << endl;
}