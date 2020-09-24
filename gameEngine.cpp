#include <iostream>
#include <fstream>

#include "gameEngine.h"
#include "tileBag.h"
#include "factories.h"
#include "utils.h"


using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::vector;

GameEngine::GameEngine() {
    //Create and fill TileBag
    tileBag = new TileBag();
    tileBag->generateFixedTileBag();

    //Create and fill factories
    factories = new Factories();
    factories->FillFactoriesFromTileBag(tileBag);
}

GameEngine::GameEngine(const GameEngine& other) {

}

GameEngine::GameEngine(GameEngine&& other) {

}

GameEngine::~GameEngine() {
    delete tileBag;
    delete factories;

    for(int i = 0; i < TOTAL_PLAYERS; ++i) {
        if(players[i] != nullptr) {
            delete players[i];
            players[i] = nullptr;
        }
    }
}

void GameEngine::runGame() {
    //Create players 
    createPlayers();

    cout << "Let's Play!" << endl;
    cout << endl;

    //Run Round
    bool keepPlaying = true;
    bool firstPlayerTurn = true;
    Player* currentPlayer;

    while(keepPlaying && !cin.eof()) {
        cout << "=== Start Round ===" << endl;

        //TODO Add loops to run 5 rounds
        //TODO check if round has ended 
        

        //Check which players turn it is:
        if(firstPlayerTurn) {
            currentPlayer = players[0];
        } else {
            currentPlayer = players[1];
        }

        //Flip the player turn for next turn.
        firstPlayerTurn = !firstPlayerTurn;

        keepPlaying = runTurn(currentPlayer);

    }
}

bool GameEngine::runTurn(Player* currentPlayer) {
    bool keepPlaying = true;

    cout << "TURN FOR PLAYER: " << currentPlayer->getPlayerName() << endl;

    //Display Factories:
    cout << "Factories: " << endl;
    printFactories();

    cout << "Mosaic for " << currentPlayer->getPlayerName() << ": " << endl;
    printPlayerMosaic(currentPlayer);
    cout << endl;

    //Get player input 
    if(playerEntersTurn(currentPlayer)) {
        turns.back();

    } else {
        keepPlaying = false;
    }

    return keepPlaying;
}

void GameEngine::printFactories() {
    for(int i = 0; i < NUMBER_OF_FACTORIES; ++i) {
        Factory* current = factories->getFactory(i);

        std::cout << i << ": ";
        for(int j = 0; j < current->size(); ++j) {
            std::cout << current->getTileAt(j)->getCharColour() << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void GameEngine::createPlayers() {
    //Create players
    string playerName;
    int i = 0;
    while(i < TOTAL_PLAYERS && !cin.eof()) {
        cout << "Enter a name for player " << i + 1 << endl;
        cout << "> ";

        if(cin.good()) {
            cin >> playerName;
            players[i] = new Player(playerName);
            ++i;
        } else {
            cout << "Input was not accepted, please try again." << endl;
        }

        cout << endl;
    }
}

bool GameEngine::playerEntersTurn(Player* currentPlayer) {
    bool turnEntered = false;
    string function;
    
    bool invalidInput = true;
    do {
        invalidInput = true;

            cout << "> ";
            cin >> function;

        if(cin.eof()) {
            invalidInput = false;
            turnEntered = false;
        } else {
            // if the user types "save x x x" only take the first x value as the fileName and pass
            if(function == "save") {
                string fileName;
                cin >> fileName;
                saveGame(fileName);
                invalidInput = false;

            // if the user types "turn x y z" use x,y,z and take the turn.
            } else if(function == "turn") {

                char colour;
                int factoryNumber, patternLineRow;
                cin >> factoryNumber;
                cin >> colour;
                cin >> patternLineRow;

                if(cin.good()) {
                    //Process turns
                    addTileFromFactoryToMosaic(currentPlayer, factoryNumber, colour, patternLineRow);

                    //Save turn variable for saving
                    turns.push_back(function + " " + std::to_string(factoryNumber) + " " + colour + " " + std::to_string(patternLineRow));

                    turnEntered = true;
                    invalidInput = false;
                } else {
                    cout << "Invalid turn entered. Should enter <Factory Row Number> <Colour> <Mosaic Row>" << endl;
                    cout << "EXAMPLE: 2 B 3" << endl;
                    invalidInput = true;

                    //TODO Fix looping error
                    //Clear current input, so user can re enter input.
                    cin.clear();
                }

            } else {
                cout << "error: unknown function defined, please try again." << endl;
            }
            
            cout << endl;
        }
        
    } while (invalidInput);

    return turnEntered;
}

void GameEngine::addTileFromFactoryToMosaic(Player* currentPlayer, int factoryNumber, char colour, int patternLineRow) {
    // Colour tileCol = convertCharToColour(colour);

    // //TODO check if patterline already full.

    // //Index of Colour in Factory
    // Factory* factory = factories->getFactory(factoryNumber);
    // int colourIndex = factory->getIndexOfSameColourTile(tileCol);

    // //loop through factor and get all same colour tiles
    // while(colourIndex != INVALID_INDEX) {
    //     //Add to tile to mosaic
    //     currentPlayer->getMosaic()->setPatternLine(factory->getTileAt(colourIndex), patternLineRow, cols);

    //     //make sure to remove tile from factory after adding to mosaic
    // }
    
    
    // currentPlayer->getMosaic()->setPatternLine();
}

void GameEngine::addTilesToMosaicFromPatternLine(Player* currentPlayer) {
    //TODO
}



void GameEngine::saveGame(string fileName) {
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
    saveFile << tileBag.generateFixedTileBag() + "\n";
    
    for(int i = 0; i < TOTAL_PLAYERS; ++i) {
        saveFile << players[i]->getPlayerName() << "\n";
    }
    
    saveFile << allTurns;
}


void GameEngine::printPlayerMosaic(Player* player) {
    Tile** grid = player->getMosaic()->getGrid();
    Tile** patternLine = player->getMosaic()->getPatternLine();
    vector<Tile*> brokenTile = player->getMosaic()->getBrokenTiles();

    int num = 0;
    
    //prints first number for first row
    std::cout << ++num <<": ";

    //prints patternLine
    for(int i = 0; i < ROWS*COLS; ++i) {
        if(patternLine[i] != nullptr) 
            std::cout << patternLine[i]->getCharColour() << " ";

        else 
            std::cout << "*";

        if(i%5 == 4) {
            std::cout <<"|| ";
            //prints grid
             for(int a = 0; a < ROWS; ++a) {
                std::cout << grid[i]->getCharColour() << " ";   
            }
            std::cout << std::endl;
            //prints number for each row
            if(num<ROWS){
                std::cout << ++num <<": ";}
        }
    }

    //prints broken tile
    std::cout << "broken: " ;
    for(int i = 0; i < (signed int) brokenTile.size(); ++i){
        std::cout << brokenTile.at(i);
    }
    
    std::cout << std::endl;
}

int GameEngine::calculatePlayerScores(Player* player) {
    //TODO caclculate player scores

    //PLACEHOLDER, please replace
    return 0;
}