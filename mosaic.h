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
    void setGrid(Tile* tile, int row, int colm);

     //adds inital elements to patternLine for mosaic, called in constructor
    void setPatternLine(Tile* tile, int row, int colm);

    //returns all elements of grid array for mosaic
    Tile** getGrid();

    //returns all elements of patternLine array for mosaic
    Tile** getPatternLine();

    //returns all elements of brokenTile array for mosaic
    std::vector<Tile> getBrokenTiles();

    //adds new broken tiles to brokenTile array for mosaic
    void addBrokenTiles(Tile tile);
    

private:


    Tile *patternLine[ROWS][COLS];

    Tile *grid[ROWS][COLS];

    std::vector<Tile> brokenTiles{};




};

#endif 