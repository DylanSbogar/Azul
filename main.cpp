#include <iostream>
#include <fstream>
#include <vector>
#include "load.cpp"
#include "factories.cpp"
#include "tileBag.cpp"


using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
using std::ofstream;

void mainMenu();
void showCredits();
void startNewGame();
void loadGame();
void saveGame(string fileName, string player1, string player2, vector <string> turns);

vector <string> turns;

int main(int argc, char **argv) {
    // if the only thing input at run was ./Azul
    if(argc == 1) {
        mainMenu();
    // else if the second input was -t (the testing mode keyword)
    } else if( strcmp(argv[1], "-t") == 0) {
        testingMode(argv[2]);
    } else {
        mainMenu();
    }
    return EXIT_SUCCESS;
}

// print out the main menu
void mainMenu() {
    cout << "Welcome to Azul! " << endl;
    cout << "-----------------" << endl;
    cout << endl;

    bool notQuit = true;
    string menuInput;

    while (notQuit) {
        cout << "Menu" << endl;
        cout << "------" << endl;

        cout << "1. New Game" << endl;
        cout << "2. Load Game" << endl;
        cout << "3. Credits" << endl;
        cout << "4. Quit" << endl;
        
        cout << "> ";
        cin >> menuInput;
        cout << endl;

        if(cin.eof()) {
            notQuit = false;
        } else if(menuInput == "1") {
            startNewGame();
        } else if(menuInput == "2") {
            loadGame();
        } else if(menuInput == "3") {
            showCredits();
        } else if(menuInput == "4") {
            cout << "Game is exiting..." << endl;
            exit(EXIT_SUCCESS);
        } else {
            cout << "Invalid input, try entering a number corresponding to the menu items" << endl;
        }
    }
    cout << "Goodbye." << endl;
    exit(EXIT_SUCCESS);
}

void showCredits() {
    cout << "Credits" << endl;
    cout << "------" << endl;
    cout << "Name:\t Dylan Sbogar (s3718036)" << endl;
    cout << "Email:\t s3718036@student.rmit.edu.au" << endl;
    cout << endl;

    cout << "Name:\t Ruchelle Balasuriya (s3781183)" << endl;
    cout << "Email:\t s3781183@student.rmit.edu.au" << endl;
    cout << endl;

    cout << "Name:\t Surinder Kaur (s3785282)" << endl;
    cout << "Email:\t s3785282@student.rmit.edu.au" << endl;
    cout << endl;
}

void startNewGame() {
    // change these names if needed/wanted
    string player1Name;
    string player2Name;

    string function;
    string param1;
    string param2;
    string param3;

    cout << "Starting a New Game" << endl;
    cout << "Enter a name for player 1" << endl;
    cout << "> ";
    cin >> player1Name;
    cout << endl;

    cout << "Starting a New Game" << endl;
    cout << "Enter a name for player 2" << endl;
    cout << "> ";
    cin >> player2Name;
    cout << endl;

    bool keepPlaying = true;

    // TODO: MOVE THIS WHILE LOOP TO GAMEENGINE.CPP?
    while(keepPlaying) {
        cout << "> ";
        cin >> function;

        /*If the user inputs ^D, the game will close without saving safely by returning to the 
        main menu and closing from there. */
        if(cin.eof()) {
            keepPlaying = false;
            // if the user types "save x x x" only take the first x value as the fileName and pass
        } else if(function == "save") {
            cin >> param1;
            saveGame(param1, player1Name, player2Name, turns);
            keepPlaying = false;
            // if the user types "turn x y z" use x,y,z and take the turn.
        } else if(function == "turn") {
            cin >> param1 >> param2 >> param3;
            turns.push_back(function + " " + param1 + " " + param2 + " " + param3);
        } else {
            cout << "error: unknown function defined, please try again." << endl;
        }
        cout << endl;
    }
}

void loadGame() {
    string fileName;

    cout << "Enter the filename from which to load a game" << endl;
    cout << "> ";
    cin >> fileName;
    cout << endl;

    loadGame(fileName);
}

void saveGame(string fileName, string player1, string player2, vector <string> turns) {
    // Create a new file with name defined by 'fileName' var
    ofstream saveFile(fileName);
    string allTurns;
    string initTileBag;
    TileBag tileBag;

    // loop through the turns array and add each turn to a formatted string to save
    for(size_t n = 0; n < turns.size(); ++n) {
        allTurns.append(turns[n] + "\n");
    }
    // Write to this new file we created.
    saveFile << tileBag.generateFixedTileBag() + "\n" + player1 + "\n" + player2 + "\n" + allTurns;
}
