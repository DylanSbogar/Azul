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
    index = 0;
}

Load::~Load() 
{
}

void Load::testingMode(std::string fileName) {
    isTesting = true;
    loadGame(fileName);
}

//TODO URGENT: ERROR CHECKING ON THE FILE BEING LOADED
void Load::loadGame(std::string fileName) {
    string fileText;
    ifstream loadedFile;

    isLoading = true;

    // open the desired save file from the 'saves' folder.
    loadedFile.open(".//saves-tests//" + fileName);

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

    std::cout << initTileBag << endl;
    std::cout << player1Name << endl;
    std::cout << player2Name << endl;

    for(int i = 0; i < (signed int) turns.size(); ++i) {
        std::cout << turns[i] << endl;
    }

    //DEBUGGIGN:
    // isTesting = false;
    // isLoading = true;

    // initTileBag = "RYLYRLRLLLULYYLULYUURYBYYLRUYBLUYULBRUUUUBURRBRRYBYBBUBYRRRLBRULBRYUYRBUULBYYLLBLRLYRUUBRBUYBYLBBLBR";
    // player1Name = "A";
    // player2Name = "B";

    // turns.push_back("turn 5 u 2");
    // turns.push_back("turn 3 l 3");
    // turns.push_back("turn 4 y 4");
    // turns.push_back("turn 2 r 2");
    // turns.push_back("turn 0 L 5");
    // turns.push_back("turn 2 y 1");
    // turns.push_back("turn 0 l 1");
}

string Load::getTileBag() {
    return this->initTileBag;
}

string Load::getPlayer1() {
    return this->player1Name;
}

string Load::getPlayer2() {
    return this->player2Name;
}

// // Returns the vector of strings read from the saveFile.
// vector<string> Load::getTurns() {
//     return turns;
// }

int Load::getTurnsSize() {
    return turns.size();
}

string Load::getCurrentTurn() {
    return turns[index];
}

int Load::getCurrentTurnIndex() {
    return index;
}

void Load::incrementTurn() {
    ++index;
}