#include "mosaic.h"

mosaic::mosaic(){

      for (int i=0; i != ROWS; ++i){
         for (int j=0; j != COLS; ++i)
               this->grid[i][j] = new Tile(NO_TILE);
      }
      int count = 5;
      for (int i=0; i != ROWS; ++i){
         int count = 5;
         for (int j=0; j != COLS; ++i){
               if(i<count)
                  this->patternLine[i][j] = nullptr;
               
               else
               this->patternLine[i][j] = new Tile(NO_TILE);        
         count-=1;
      }
   }
}

mosaic::~mosaic(){
   delete grid;
   delete patternLine;
   brokenTiles.clear();

}

void mosaic::setGrid(Tile* tile, int row, int cols){
  grid[row][cols]= tile;
}

void mosaic::setPatternLine(Tile* tile, int row, int cols){
   patternLine[row][cols]= tile;

}

Tile** mosaic::getGrid(){
   Tile** gridArray = new Tile*[ROWS];
   for (int i=0; i != ROWS; ++i){
      gridArray[i]= new Tile[ROWS];
      for (int j=0; j != COLS; ++j)
         gridArray[i][j] = grid[i][j];
   }
   return gridArray;
}
 

Tile** mosaic::getPatternLine(){
   Tile** patternArray = new Tile*[ROWS];
   for (int i=0; i != ROWS; ++i){
      patternArray[i]= new Tile[ROWS];
      for (int j=0; j != COLS; ++j)
         patternArray[i][j] = grid[i][j];
   }
   return patternArray;
 }


void mosaic::addBrokenTiles(Tile broken_Tile){
   brokenTiles.push_back(broken_Tile);
}

 std::vector<Tile> mosaic::getBrokenTiles(){
         return brokenTiles;}
 
 
 