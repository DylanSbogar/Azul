#include "load.h"

//Constructor
Load::Load(string fileName) {
    this->fileName = fileName;
    initTileBag = "";
    player1Name = "";
    player2Name = "";
    turns = {};
    index = 0;
}

//Deconstructor
Load::~Load() {
}

//Calls loadGame() and sets global var isTesting to true
void Load::testingMode(std::string fileName) {
    isTesting = true;
    loadGame(fileName);
}

/*First checks if the save file is valid, if true then it 
will read the file line-by-line, variables to the load object*/
void Load::loadGame(std::string fileName) {
    string fileText;
    ifstream loadedFile;

    isLoading = true;

    loadedFile.open(".//saves-tests//" + fileName);
    // open the desired save file from the 'saves' folder.
        if(loadedFile.is_open()) {
            //Get the first line of the saveFile and set it to the initial tilebag.
            getline(loadedFile, fileText);
            initTileBag = fileText;

            //Get the second line of the saveFile and set it to player 1s name
            getline(loadedFile, fileText);
            player1Name = fileText;

            //Get the third line of the saveFile and set it to player 2s name
            getline(loadedFile, fileText);
            player2Name = fileText;

            // Get every line hereafter and add it to the vector of turns.
            while(getline(loadedFile, fileText)) {
                turns.push_back(fileText);
            } 
        } else {
            /*If the user inputs an incorrect fileName for something that does not exist,
            an error is issued, and users are allowed to try again until they input a fileName
            that is correct. */
            cout << "Error: Save file does not exist!" << endl;
            cout << "Please try again." << endl;
            cout << endl;
            cout << "> ";
            cin >> fileName;
            loadGame(fileName);
        }
}

//Returns a string of the tileBag being loaded
string Load::getTileBag() {
    return this->initTileBag;
}

//Returns a string of player 1's name being loaded
string Load::getPlayer1() {
    return this->player1Name;
}

//Returns a string of player 2's name being loaded
string Load::getPlayer2() {
    return this->player2Name;
}

//Returns the total size of the turns vector
int Load::getTurnsSize() {
    return turns.size();
}

//Returns a string of the current turn to be input
string Load::getCurrentTurn() {
    return turns[index];
}

//Returns the current index of the turn vector that is being loaded
int Load::getCurrentTurnIndex() {
    return index;
}

//Increments the turn counter after each turn has been loaded
void Load::incrementTurn() {
    ++index;
}