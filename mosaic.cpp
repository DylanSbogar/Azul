#include "mosaic.h"

Mosaic::Mosaic() {

   //Instantiating all grid tiles to NO_TILE
   for (int i = 0; i != ROWS; ++i){
      for (int j = 0; j != COLS; ++j) {
         grid[i][j] = new Tile(NO_TILE);
      }
   }

   //Instantiating patternline 
   for(int row = 0; row <= ROWS; row++) {
      for(int col = 0; col < COLS - 1 - row; ++col) {
         patternLine[row][col] = new Tile(BLANK);
      }
      for(int col = COLS - 1 - row; col < COLS ; ++col) {
         patternLine[row][col] = new Tile(NO_TILE);
      }
    }
}

Mosaic::~Mosaic(){
   //Iterated through grid array and deletes all the tiles within it
   for (int i = 0; i != ROWS; ++i){
      for (int j = 0; j != COLS; ++j) {
         if(grid[i][j] != nullptr) {
            delete grid[i][j];
            grid[i][j] = nullptr;
         }
      }
   }  

   //Iterated through patternLine array and deletes all the tiles within it
   for (int i = 0; i != ROWS; ++i){
      for (int j = 0; j != COLS; ++j) {
         if(grid[i][j] != nullptr) {
            delete patternLine[i][j];
            patternLine[i][j] = nullptr;
         }
      }
   }
   brokenTiles.clear();
}

//adds tile to specific grid element
void Mosaic::setGrid(Tile* tile, int row, int cols){
   grid[row][cols]= tile;
}

//adds broken tile to vector
void Mosaic::addBrokenTiles(Tile* broken_Tile){
   brokenTiles.push_back(broken_Tile);
}

//returns vector with all broken tiles
std::vector<Tile*> Mosaic::getBrokenTiles(){
   return brokenTiles;
}

//returns tile of spefic grid element of row and colm inputted
Tile* Mosaic::getGridTile(int row, int colm) {
   return grid[row][colm];
}

//returns full row of the patternLine row inputted
Tile** Mosaic::getPatternLineRow(int row) {
   return patternLine[row];
}

//adds tile inputted, into the patternLine row inputted
void Mosaic::addTileToPatternLine(Tile* tile, int row) {
   int colm = COLS-1;
   //goes through each element in patternLine row 
   while(patternLine[row][colm]->getColour() != NO_TILE && colm >= 0) {
      --colm;
   }

   //delete empty tile
   delete patternLine[row][colm];
   patternLine[row][colm] = nullptr;

   //Add new tile
   patternLine[row][colm] = tile;
}

//return boolean depending on if patternLine row has no tile
bool Mosaic::patternLineFull(int row) {
   bool rowIsFull = true;

   //Iterate through patternLine row and check for NO_TILE tiles
   for(int colm = 0; colm < COLS; ++colm) {
      if(patternLine[row][colm]->getColour() == NO_TILE) {
         rowIsFull = false;
      }
   }
   return rowIsFull;
}

//returns colour of patternLine row 
Colour Mosaic::getPatternLineColour(int row) {
   return patternLine[row][COLS-1]->getColour();
}

//removes specific broken tile from vector
void Mosaic::removeBrokenTiles(int index) {
   if ((signed int) brokenTiles.size() > 0 && index >= 0 && index < (signed int) brokenTiles.size()) {
      for (int i = index; i < (signed int) brokenTiles.size() - 1; ++i) {
         brokenTiles[i] = brokenTiles[i+1];
      }
      brokenTiles.pop_back();
   }
}

void Mosaic::addBrokenTileAtFront(Tile* tile) {
   if (brokenTiles.size() == 0 ) {
      brokenTiles.push_back(tile);
   } else {
      //Re size array to fit new value
      int newSize = (signed int) brokenTiles.size() + 1;
      brokenTiles.resize(newSize);

      //Move all the tiles infront
      for(int i = newSize - 1; i >= 0; --i) {
         brokenTiles[i] = brokenTiles[i-1];
      }

      //Add new tile to position 0
      brokenTiles[0] = tile;
   }
}