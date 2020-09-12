#include <iostream>
#include <fstream>
#include <vector>

void mainMenu();
void showCredits();
void startNewGame();
void loadGame();
void saveGame(std::string fileName, std::string player1, std::string player2, std::vector <std::string> turns);

// TESTING: a vector for turns (since its size is dynamic)
std::vector <std::string> turns;

int main(void) {
    mainMenu();
    return EXIT_SUCCESS;
}

// print out the main menu
void mainMenu() {
    std::cout << "Welcome to Azul! " << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << std::endl;

    bool notQuit = true;
    std::string menuInput;

    while (notQuit) {
        std::cout << "Menu" << std::endl;
        std::cout << "------" << std::endl;

        std::cout << "1. New Game" << std::endl;
        std::cout << "2. Load Game" << std::endl;
        std::cout << "3. Credits" << std::endl;
        std::cout << "4. Quit" << std::endl;
        
        std::cout << "> ";
        std::cin >> menuInput;
        std::cout << std::endl;

        if(std::cin.eof()) {
            notQuit = false;
        } else if(menuInput == "1") {
            startNewGame();
        } else if(menuInput == "2") {
            loadGame();
        } else if(menuInput == "3") {
            showCredits();
        } else if(menuInput == "4") {
            std::cout << "Game is exiting..." << std::endl;
            exit(EXIT_SUCCESS);
        } else {
            std::cout << "Invalid input, try entering a number corresponding to the menu items" << std::endl;
        }
    }
    std::cout << "Goodbye." << std::endl;
    exit(EXIT_SUCCESS);
}

void showCredits() {
    std::cout << "Credits" << std::endl;
    std::cout << "------" << std::endl;
    std::cout << "Name:\t Dylan Sbogar (s3718036)" << std::endl;
    std::cout << "Email:\t s3718036@student.rmit.edu.au" << std::endl;
    std::cout << std::endl;

    std::cout << "Name:\t Ruchelle Balasuriya (s3781183)" << std::endl;
    std::cout << "Email:\t s3781183@student.rmit.edu.au" << std::endl;
    std::cout << std::endl;

    std::cout << "Name:\t Surinder Kaur (s3785282)" << std::endl;
    std::cout << "Email:\t s3785282@student.rmit.edu.au" << std::endl;
    std::cout << std::endl;
}

void startNewGame() {
    // change these names if needed/wanted
    std::string player1Name;
    std::string player2Name;

    std::string function;
    std::string param1;
    std::string param2;
    std::string param3;

    std::cout << "Starting a New Game" << std::endl;
    std::cout << "Enter a name for player 1" << std::endl;
    std::cout << "> ";
    std::cin >> player1Name;
    std::cout << std::endl;

    std::cout << "Starting a New Game" << std::endl;
    std::cout << "Enter a name for player 2" << std::endl;
    std::cout << "> ";
    std::cin >> player2Name;
    std::cout << std::endl;

    //DEBUG: ALLOW THE USER TO KEEP PLAYING UNTIL THEY SAVE THE GAME
    bool keepPlaying = true;

    // PLEASE DONT USE THIS LATER, THIS IS JUST FOR ME TO TEST
    while(keepPlaying) {
        std::cout << "> ";
        std::cin >> function >> param1 >> param2 >> param3;
        std::cout << std::endl;
        // IF THE USER INPUTS ^D, THEY WILL AUTOMATICALLY RETURN TO THE MAIN MENU AND CLOSE THE GAME.
        if(std::cin.eof()) {
         keepPlaying = false;
        } else if(function == "save") {
            saveGame(param1, player1Name, player2Name, turns);
            keepPlaying = false;
        } else if(function == "turn") {
            turns.push_back(function + " " + param1 + " " + param2 + " " + param3);
        } else {
            std::cout << "error: unknown function defined, please try again." << std::endl;
        }
    }
    // THIS JUST CLEANS UP THE TERMINAL LOOK WHEN HITTING EOF, SPACING THINGS OUT (NOT NECESSARY BUT LOOKS NICE)
    std::cout << std::endl;
}

void loadGame() {
    std::string loadFileInput;

    std::cout << "Enter the filename from which to load a game" << std::endl;
    std::cout << "> ";
    std::cin >> loadFileInput;
    std::cout << std::endl;
}

void saveGame(std::string fileName, std::string player1, std::string player2, std::vector <std::string> turns) {
    // Create a new file with name defined by 'fileName' var
    std::ofstream saveFile(fileName);
    std::string allTurns;

    // loop through the turns array and add each turn to a formatted string to save
    for(size_t n = 0; n < turns.size(); ++n) {
        allTurns.append(turns[n] + "\n");
    }

    // Write to this new file we created.
    saveFile << "<initial tile bag>\n" + player1 + "\n" + player2 + "\n" + allTurns;
}


