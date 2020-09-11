#ifndef TILE_BAG_H
#define TILE_BAG_H

#include "tile.h"

#define TILE_BAG_SIZE 100

class Node {
public:
   Node(Tile* tile, Node* next);
   Node(Node& other);

   Tile* tile;
   Node* next;
};

class TileBag {
public:
    TileBag();
    ~TileBag();

    //Generates fixed Tile bag
    void generateFixedTileBag();

    //Tiles returned from the front of the list 
    Tile* drawTile();

    //Tile is removed from the front of the list
    void removeTile();

    //Tiles added to the back of the list
    void addTile(Tile* tile);

    //Returns the current length of the Tile Bag
    int getLength();


    // This method should only be used for testing
    // Tile* get(int i);

private:
    //clears tile bag
    void clear();

    Node* head;
    int length;
};

#endif // TILE_BAG_H