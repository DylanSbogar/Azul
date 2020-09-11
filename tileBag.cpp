#include "tileBag.h"
#include "utils.h"

Node::Node(Tile* tile, Node* next) {
    this->tile = tile;
    this->next = next;
}

Node::Node(Node& other) {
    this->tile = other.tile;
    next = new Node(*other.next);
}

TileBag::TileBag() {
    head = nullptr;
    length = 0;
}

TileBag::~TileBag() {
    clear();
}

void TileBag::generateFixedTileBag() {
    clear();
    char fixedTileBag[] = "RYLYRLRLLLULYYLULYUURYBYYLRUYBLUYULBRUUUUBURRBRRYBYBBUBYRRRLBRULBRYUYRBUULBYYLLBLRLYRUUBRBUYBYLBBLBR";
    for(int i = 0; i < TILE_BAG_SIZE; ++i) {
        Colour colour = convertCharToColour(fixedTileBag[i]);
        addTile(new Tile(colour));
    }
}

Tile* TileBag::drawTile() {
    return head->tile;
}

void TileBag::removeTile() {
    if(head != nullptr) {
        Node* deleteNode = head;
        head = head->next;

        delete deleteNode;
        --length;
    }
}

void TileBag::addTile(Tile* tile) {
    Node* newNode = new Node(tile, nullptr);

    if(head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    ++length;
}

int TileBag::getLength() {
    return length;
}

void TileBag::clear() {
    while(head != nullptr) {
        removeTile();
    }
}

// TESTING METHOD
// Tile* TileBag::get(int i) {
//     Tile* tile = nullptr;
//     if(i >= 0 && i < length) {
//         int counter = 0;
//         Node* current = head;
//         while(counter < i) {
//             current = current->next;
//             ++counter;
//         }

//         tile = current->tile;
//     }

//     return tile;
// }