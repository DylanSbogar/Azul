#include "tileBag.h"
#include "utils.h"
#include <utility>
#include <string>

Node::Node(Tile* tile, Node* next) {
    this->tile = tile;
    this->next = next;
}

Node::Node(const Node& other) {
    tile = new Tile(*other.tile);

    if(next != nullptr) {
        next = new Node(*other.next);
    }
}


TileBag::TileBag() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

TileBag::TileBag(const TileBag& other) :
    length(other.length)
{   
    if(head != nullptr) {
        head = new Node(*other.head);
    }
    // NOTE: when copy constructor of Node is called, all 'next' 
    // nodes are recursively copied
}

TileBag::TileBag(TileBag&& other) :
    length(other.length)
{  
    if(head != nullptr) {
        head = new Node(std::move(*other.head));
    }
}

TileBag::~TileBag() {
    clear();
}

std::string TileBag::generateFixedTileBag() {
    //Ensure tile bag is empty
    clear();

    //Read in fixed tile bag and add as tiles in the tile bag
    char fixedTileBag[] = "RYLYRLRLLLULYYLULYUURYBYYLRUYBLUYULBRUUUUBURRBRRYBYBBUBYRRRLBRULBRYUYRBUULBYYLLBLRLYRUUBRBUYBYLBBLBR";
    for(int i = 0; i < TILE_BAG_SIZE; ++i) {
        Colour colour = convertCharToColour(fixedTileBag[i]);
        addTile(new Tile(colour));
    }
    return std::string(fixedTileBag);
}

std::string TileBag::generateTileBag(std::string tileBag) {
    //Ensure tile bag is empty
    clear();

    //Read in fixed tile bag and add as tiles in the tile bag
    for(int i = 0; i < TILE_BAG_SIZE; ++i) {
        Colour colour = convertCharToColour(tileBag[i]);
        addTile(new Tile(colour));
    }
    return std::string(tileBag);
}

Tile* TileBag::drawTile() {
    //Check if head is no null, then return tile at head, otherwise return null
    return head != nullptr ? head->tile : nullptr;
}

void TileBag::removeTile() {
    //Ensure tile bag is not empty
    if(head != nullptr) {
        //Delete the head node
        Node* deleteNode = head;
        head = head->next;

        delete deleteNode;

        //Decrement size of tile bag
        --length;
    }
}

void TileBag::addTile(Tile* tile) {
    Node* newNode = new Node(tile, nullptr);

    //If tile bag is empty, set newNode as head
    //Otherwise update pointer of old tail to point to new tail
    if(head == nullptr) {
        head = newNode;
    } else {
        tail->next = newNode;
    }

    //Update newNode as tail
    tail = newNode;

    //Increment size of tile bag
    ++length;
}

int TileBag::getLength() {
    return length;
}

void TileBag::clear() {
    //Keep removing tiles until tile bag is empty
    while(head != nullptr) {
        removeTile();
    }
}

// TESTING METHOD
Tile* TileBag::get(int index) {
    //Returns nullptr if index is invalid
    Tile* tile = nullptr;

    //Ensure index is within valid range
    if(index >= 0 && index < length) {

        //Iterate through tile bag until index is reached
        int counter = 0;
        Node* current = head;
        while(counter < index) {
            current = current->next;
            ++counter;
        }

        //Update 'tile' to tile at given index
        tile = current->tile;
    }

    return tile;
}
