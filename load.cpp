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

    //Open the desired save file from the 'saves' folder.
    loadedFile.open(".//saves-tests//" + fileName);
    //Only advance if the file exists
    if(loadedFile.is_open()) {
        //Get the first line of the saveFile and set it to the initial tilebag.
        getline(loadedFile, fileText);
        initTileBag = fileText;

        //If the check returns true (the tileBag is valid)
        if(checkTileBag(initTileBag)) {
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
            /*If the save file contains an invalid tileBag, an error is issued, 
            and users are allowed to try enter another save file until a valid one
            is given.*/
        } else {
            cout << "Error: Invalid game detected!" << endl;
            cout << "Please enter a valid game name." << endl;
            cout << endl;
            cout << "> ";
            cin >> fileName;
            loadGame(fileName);
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

//Iterates through the tileBag and checks for any incorrect characters, returns false if 1 or more incorrect chars found.
bool Load::checkTileBag(string tileBag) {
    bool isGood = true;
    int errors = 0;
    for(string::size_type i = 0; i < tileBag.size(); ++i) {
        if(tileBag[i] == 'R' || tileBag[i] == 'Y' || tileBag[i] == 'L' || tileBag[i] == 'U' || tileBag[i] == 'B') {
        } else {
            ++errors;
        }
        //If there is 1 or more errors, the tileBag is not good.
        if(errors > 0) {
            isGood = false;
        }
    }
    return isGood;
}