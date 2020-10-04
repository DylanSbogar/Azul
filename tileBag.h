#ifndef TILE_BAG_H
#define TILE_BAG_H

#include "tile.h"
#include <iostream>
#include <utility>
#include <string>

#define TILE_BAG_SIZE 100

//Node class utilized by TileBag to implement Linked List
class Node {
public:
   Node(Tile* tile, Node* next);
   Node(const Node& other);

   Tile* tile;
   Node* next;
};

class TileBag {
public:
    TileBag();
    TileBag(const TileBag& other);
    ~TileBag();

    //OUTPUT: Generates fixed Tile bag
    std::string generateFixedTileBag();

    //INPUT: String of uppercase letters corresponding to chars of Colour
    //OUTPUT: Generates fixed tile bag from given colour chars
    std::string generateTileBag(std::string tileBag);

    //OUTPUT: Tiles returned from the front of the tile bag
    //NOTE: returns nullptr if bag is empty
    Tile* drawTile();

    //ENSURE: Tile bag contains tiles
    //OUTPUT: Tile is removed from the front of the tile bag
    void removeTile();

    //INPUT: All tiles aside from FIRST_PLAYER, NO_TILE and BLANK should be allowed to be added
    //OUTPUT: Tile is added to the back of the tile bag
    void addTile(Tile* tile);

    //OUTPUT: Returns the current length of the tile Bag
    int getLength();

    //OUTPUT: Clears all tiles currenty in the tile bag
    void clear();

    //OUTPUT: Returns tile at given index
    //NOTE: If invalid index is given, method returns nullptr
    Tile* get(int index);

private:
    Node* head;
    Node* tail;
    int length;
};

#endif // TILE_BAG_H