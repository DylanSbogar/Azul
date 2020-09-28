#include "gameEngine.h"
#include "load.h"
#include <fstream>
#include <vector>

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
    string tileBag;
    string player1Name;
    string player2Name;
    std::vector <string> allTurns;

    // open the desired save file from the 'saves' folder.
    loadedFile.open(".//saves//" + fileName);

    // get the first line of the file and define it as the tilebag
    getline(loadedFile, fileText);
    tileBag = fileText;

    // get the second line of the file and define it as player 1's name
    getline(loadedFile, fileText);
    player1Name = fileText;

    // get the third line of the file and define it as player 2's name
    getline(loadedFile, fileText);
    player2Name = fileText;

    // for every line after, save the line to a vector of turns
    while(getline(loadedFile, fileText)) {
        allTurns.push_back(fileText);
    }

    cout << "Azul game successfully loaded" << endl;
    cout << "<game play continues from here>" << endl;
    cout << endl;

    // cout << tileBag + "\n" + player1Name + "\n" + player2Name << endl;

    // for(std::size_t i = 0; i < allTurns.size(); ++i) {
    //     cout << allTurns[i] << endl;
    // }
    // cout << endl;

    // GameEngine* gameEngine = new GameEngine();
    // gameEngine->setGameVariables(player1Name, player2Name, tileBag, allTurns);
}