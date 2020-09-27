#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>

#include "load.h"
#include "gameEngine.h"


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

// vector <string> turns;

int main(int argc, char **argv) {
    // if the only thing input at run was ./Azul
    if(argc == 1) {
        mainMenu();
    // else if the second input was -t (the testing mode keyword)
    } else if(strcmp(argv[1], "-t") == 0) {
        // testingMode(argv[2]);
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
    GameEngine* gameEngine = new GameEngine();
    gameEngine->runGame();
    delete gameEngine;
}

void loadGame() {
    string fileName;

    cout << "Enter the filename from which to load a game" << endl;
    cout << "> ";
    cin >> fileName;
    cout << endl;

    loadGame(fileName);
}