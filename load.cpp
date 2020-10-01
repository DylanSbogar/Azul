#include <fstream>

#include "load.h"

/* the primary difference between the two methods, is that the testingMode() function
reads from the /tests folder for a file. Whereas the loadGame() function reads from
the /saves folder. Currently deciding whether to make them both the same folder and 
just changing the extension (.test or .save) then we can do it that way. */

Load::Load(string fileName) {
    this->fileName = fileName;
    initTileBag = "";
    player1Name = "";
    player2Name = "";
    turns = {};
}

Load::Load(const Load& other){
    //TODO
}

Load::~Load() {
    //TODO
}

void Load::testingMode(std::string fileName) {
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

void Load::loadGame(std::string fileName) {
    string fileText;
    ifstream loadedFile;

    isLoading = true;

    // open the desired save file from the 'saves' folder.
    loadedFile.open(".//saves//" + fileName);

    //Get the first line of the saveFile and set it to the initial tilebag.
    getline(loadedFile, fileText);
    initTileBag = fileText;

    //Get the second line of the saveFile and set it to player 1s name
    getline(loadedFile, fileText);
    player1Name = fileText;

    //Get the third line of the saveFile and set it to player 2s name
    getline(loadedFile, fileText);
    player2Name = fileText;

    //Get every line hereafter and add it to the vector of turns.
    while(getline(loadedFile, fileText)) {
        turns.push_back(fileText);
    }

    cout << "Azul game successfully loaded" << endl;
    cout << "<game play continues from here>" << endl;
    cout << endl;
}

string Load::getTileBag() {
    //TODO
    return this->initTileBag;
}

string Load::getPlayer1() {
    //TODO
    return this->player1Name;
}

string Load::getPlayer2() {
    //TODO
    return this->player2Name;
}
vector<string> Load::getTurns() {
    //TODO
    return turns;
}