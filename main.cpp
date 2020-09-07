#include <iostream>

void mainMenu();
void showCredits();
void startNewGame();
void loadGame();

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
    std::cout << "Starting a New Game" << std::endl;
    std::cout << std::endl;
}

void loadGame() {
    std::cout << "Load Game was Selected..." << std::endl;
    std::cout << std::endl;
}


