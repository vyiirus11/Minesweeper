#include <iostream>
#include "Tile.h"

// Constructor
Tile::Tile(sf::Texture &texture, sf::Texture &flagTexture) {
    sprite1->setTexture(texture);
    sprite2->setTexture(texture);
    flag->setTexture(flagTexture);
}

// Accessors
Sprite* Tile::getSprite() {
    return sprite1;
}

Sprite* Tile::getSprite2() {
    return sprite2;
}

Sprite* Tile::getFlagSprite() {
    return flag;
}

bool Tile::getIsBomb() {
    return isBomb;
}

bool Tile::getIsFlagged() {
    return isFlagged;
}

bool Tile::getIsDebug() {
    return debug;
}

int Tile::getAdjacentBombs() {
    return adjacentBombs;
}

vector<Tile*>* Tile::getNeighbors() {
    return &neighbors;
}

// Mutators
void Tile::setNeighbors(vector<Tile*> &neighborTiles) {
    neighbors = neighborTiles;
    adjacentBombs = 0;

    for (int i = 0; i < neighbors.size(); i++) {
        Tile* current = neighbors.at(i);
        if (current->getIsBomb()) {
            adjacentBombs++;
        }
    }
}

void Tile::setIsBomb(bool change) {
    isBomb = change;
}

void Tile::setIsFlagged(bool change) {
    isFlagged = change;
}

void Tile::setIsDebug(bool change) {
    debug = change;
}

// Functions
void Tile::move(float x, float y) {
    sprite1->move(Vector2f(y, x));
    sprite2->move(Vector2f(y, x));
    flag->move(Vector2f(y, x));
}

void Tile::makeBomb() {
    isBomb = true;
}