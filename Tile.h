#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Tile
{
    bool isBomb = false;
    bool isFlagged = false;
    bool debug = false;
    int adjacentBombs = 0;
    vector<Tile*> neighbors;

    Sprite* sprite1 = new Sprite;
    Sprite* sprite2 = new Sprite;
    Sprite* flag = new Sprite;

public:
    // Tile Constructor
    Tile(Texture& texture, Texture& flagTexture);

    // Accessors
    Sprite* getSprite();
    Sprite* getSprite2();
    Sprite* getFlagSprite();
    bool getIsBomb();
    bool getIsFlagged();
    bool getIsDebug();
    int getAdjacentBombs();
    vector<Tile*>* getNeighbors();

    // Mutators
    void setIsBomb(bool change);
    void setIsFlagged(bool change);
    void setIsDebug(bool change);
    void setNeighbors(vector<Tile*> &neighborTiles);

    // Functions
    void move(float x, float y);
    void makeBomb();
};
