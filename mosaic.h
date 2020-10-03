#ifndef MOSAIC_H
#define MOSAIC_H 

#include <iostream>
#include <vector> 
#include "tile.h"

#define COLS                5 
#define ROWS                5

class Mosaic {
public:  
    Mosaic();
    ~Mosaic();
    
    //adds tiles into the patternLine array for mosaic
    void setGrid(Tile* tile, int row, int colm);

    // //adds tiles into the patternLine array for mosaic
    // void setPatternLine(Tile* tile, int row, int colm);

    // //returns all elements of grid array for mosaic
    // Tile** getGrid();

    // //returns all elements of patternLine array for mosaic
    // Tile** getPatternLine();

    //returns all elements of brokenTile array for mosaic
    std::vector<Tile*> getBrokenTiles();

    //adds new broken tiles to brokenTile array for mosaic
    void addBrokenTiles(Tile* tile);

    // Removes tile at given index
    void removeBrokenTiles(int index);

    //Adds tile to the front of broken tile.
    void addBrokenTileAtFront(Tile* tile);


    /**
     * NEW METHOD TO REPLACE 'getGrid()', 'getPatternLine()', 
     * and 'setPatternLine(Tile* tile, int row, int colm)'
     */

    //INPUT: row must be between 0 and ROWS and colm must be between 0 and COLS
    //OUTPUT: Returns tile at specified row and column
    Tile* getGridTile(int row, int colm);

    //INPUT: row must be between 0 and ROWS
    //OUTPUT: If tile colour matches patternLine adds tile and returns true
    //NOTE: Patternline row SHOULD NOT be full and should match tiles already in patternLine
    void addTileToPatternLine(Tile* tile, int row); 

    //INPUT: row must be between 0 and ROWS
    //OUTPUT: Returns pointer to the array at specified row
    Tile** getPatternLineRow(int row);   

    //INPUT: row must be between 0 and ROWS
    //OUTPUT: Returns true if patternLine row is full
    bool patternLineFull(int row);

    //INPUT: row must be between 0 and ROWS
    //OUTPUT: returns colour of patternline
    Colour getPatternLineColour(int row);

    
    
private:
    Tile *patternLine[ROWS][COLS];

    Tile* grid[ROWS][COLS];

    std::vector<Tile*> brokenTiles;

};

#endif //MOSAIC_H