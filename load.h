#ifndef LOAD_H
#define LOAD_H

#include <iostream>
#include <vector>

using std::string;
using std::ifstream;
using std::endl;
using std::cin;
using std::cout;
using std::vector;

extern bool isLoading;
extern bool isTesting;

class Load {
public:
    Load(string fileName);
    ~Load();

    void loadGame(std::string fileName);
    void testingMode(std::string fileName);

    string getTileBag();
    string getPlayer1();
    string getPlayer2();
    vector<string> getTurns();
    
private:
    string fileName;
    string initTileBag;
    string player1Name;
    string player2Name;
    vector<string> turns;
};

#endif //LOAD_H