#include <iostream>
#include <vector> 

#include "tile.h"
#ifndef MOSAIC_H
#define MOSAIC_H 

#define COLS                5 
#define ROWS                5

class mosaic{


public:  
    mosaic();
    ~mosaic();
    
    //cadds inital elements grid for mosaic, called in constructor
    void setGrid(char grid[5][5]);

     //adds inital elements to patternLine for mosaic, called in constructor
    void setPatternLine(char patternLine[5][5]);

    //returns all elements of grid array for mosaic
    char** getGrid();

    //returns all elements of patternLine array for mosaic
    char** getPatternLine();

    //returns all elements of brokenTile array for mosaic
    std::vector<Tile> getBrokenTiles();

    //adds new broken tiles to brokenTile array for mosaic
    void addBrokenTiles(Tile tile);
    

private:


    char patternLine[ROWS][COLS];

    char grid[ROWS][COLS];

    std::vector<Tile> brokenTiles{};




};

#endif 