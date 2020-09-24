#include "load.h"

void loadGame(std::string fileName) {
    std::string fileText;
    std::ifstream loadedFile(fileName);
    while(getline(loadedFile, fileText)) {
        std::cout << fileText << std::endl;
    }
    std::cout << std::endl;
}

void testingMode(std::string fileName) {
    std::cout << "you have now entered the super secret testing mode!" << std::endl;
    std::cout << std::endl;

    std::string fileText;
    std::ifstream loadedFile(fileName);
    while(getline(loadedFile, fileText)) {
        std::cout << fileText << std::endl;
    }
    std::cout << std::endl;
}