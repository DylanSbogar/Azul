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

void Mosaic::setGrid(Tile* tile, int row, int cols){
   grid[row][cols]= tile;
}

void Mosaic::setPatternLine(Tile* tile, int row, int cols){
   patternLine[row][cols]= tile;
}

Tile** Mosaic::getGrid(){
   return *grid;
}

Tile** Mosaic::getPatternLine(){
   return *patternLine;
}

void Mosaic::addBrokenTiles(Tile* broken_Tile){
   brokenTiles.push_back(broken_Tile);
}

std::vector<Tile*> Mosaic::getBrokenTiles(){
   return brokenTiles;
}

//ADD FOLLOWING TEST METHOD IN MAIN TO TEST
// void testMosaicClass() {
//     mosaic* m = new mosaic();

    
//     Tile** grid = m->getGrid();
//     std::cout << "Printing Grid" << std::endl;
//     for(int i = 0; i < ROWS; ++i) {
//         for(int j = 0; j < COLS; ++j) {
//             std::cout << grid[i]->getCharColour() << " ";
//         }
//         std::cout << std::endl;
//     }

//     Tile** p = m->getPatternLine();
//     std::cout << "Printing Patter Line (inverted)" << std::endl;

//     for(int i = 0; i < ROWS * COLS; ++i) {

//         if(p[i] != nullptr) {
//             std::cout << p[i]->getCharColour();
//         } else {
//             std::cout << "*";
//         }

//         if(i%5 == 4) {
//             std::cout << std::endl;
//         }
//     }

//     delete m;
// }
 
