#include "mosaic.h"

mosaic::mosaic(){
  setGrid(this->grid);
  setPatternLine(this->patternLine);
}

mosaic::~mosaic(){
   delete grid;
   delete patternLine;
   brokenTiles.clear();

}

void mosaic::setGrid(char grid[5][5]){
   for (int i=0; i != ROWS; ++i){
      for (int j=0; j != COLS; ++i)
            grid[i][j] = '.';
   }
}

void mosaic::setPatternLine(char patternLine[5][5]){
   int count = 5;
   for (int i=0; i != ROWS; ++i){
      int count = 5;
      for (int j=0; j != COLS; ++i){
            if(i<count)
               patternLine[i][j] = ' ';
            
            else
            patternLine[i][j] = '.';
            count-=1;
   }
}
}

char** mosaic::getGrid(){
   char** gridArray = 0;
   gridArray = new char*[ROWS];

   for (int i=0; i != ROWS; ++i){
      gridArray[i]=new char[COLS];
      for (int j=0; j != COLS; ++i)
         gridArray[i][j] = grid[i][j];
   }
   return gridArray;
}
 

//  void mosaic::getGrid(){
//    for (int i=0; i != ROWS; ++i){
//       for (int j=0; j != COLS; ++i)
//          std::cout<< grid[i][j];
//    }
// }

char** mosaic::getPatternLine(){
   char** patternArray = 0;
   patternArray = new char*[ROWS];

   for (int i=0; i != ROWS; ++i){
       patternArray[i]=new char[COLS];
       for (int j=0; j != COLS; ++i)
         patternArray[i][j] = patternLine[i][j];
      }
   return patternArray;
 }

 //  void mosaic::getPatternLine(){
//    for (int i=0; i != ROWS; ++i){
//       for (int j=0; j != COLS; ++i)
//          std::cout<< patternLine[i][j];
//    }
// }

void mosaic::addBrokenTiles(Tile broken_Tile){
   brokenTiles.push_back(broken_Tile);
}

 std::vector<Tile> mosaic::getBrokenTiles(){
         return brokenTiles;}
 
 
 