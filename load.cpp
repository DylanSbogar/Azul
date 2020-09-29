#include "gameEngine.h"
#include "load.h"
#include <fstream>
#include <vector>

using std::string;
using std::ifstream;
using std::endl;
using std::cin;
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

    isLoading = true;

    // open the desired save file from the 'saves' folder.
    loadedFile.open(".//saves//" + fileName);

    std::streambuf *cinbuf = cin.rdbuf();
    cin.rdbuf(loadedFile.rdbuf());

    while(getline(cin, fileText)) {
        cout << fileText << endl;
    }
    
    std::cin.rdbuf(cinbuf);

    cout << "Azul game successfully loaded" << endl;
    cout << "<game play continues from here>" << endl;
    cout << endl;

    GameEngine* gameEngine = new GameEngine();
    // gameEngine->setGameVariables(player1Name, player2Name, tileBag, allTurns);
    gameEngine->runGame();
}