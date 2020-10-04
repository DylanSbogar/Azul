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
   Node(Node&& other);

   Tile* tile;
   Node* next;
};

class TileBag {
public:
    TileBag();
    TileBag(const TileBag& other);
    TileBag(TileBag&& other);
    ~TileBag();

     //Generates fixed Tile bag
    std::string generateFixedTileBag();

    //Generates fixed Tile bag
    std::string generateTileBag(std::string tileBag);

    //Tiles returned from the front of the tile bag
    //NOTE: returns nullptr if bag is empty
    Tile* drawTile();

    //Tile is removed from the front of the tile bag
    void removeTile();

    //Tile is added to the back of the tile bag
    void addTile(Tile* tile);

    //Returns the current length of the tile Bag
    int getLength();

    //Clear all elements in the tile bag
    void clear();

    //This method should only be used for testing
    //NOTE: if invalud index is given, method returns nullptr
    Tile* get(int index);

private:
    Node* head;
    Node* tail;
    int length;
};

#endif // TILE_BAG_H