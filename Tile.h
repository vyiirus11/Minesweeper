#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Tile
{
    bool debug = false;
    bool isBomb = false;
    bool isFlagged = false;
    int adjacentBombs = 0;
    vector<Tile*> neighbors;

    Sprite* sprite1 = new Sprite;
    Sprite* sprite2 = new Sprite;
    Sprite* flag = new Sprite;

public:
    // Tile Constructor
    Tile(Texture& texture, Texture& flagTexture);

    // Accessors
    Sprite* getSprite1();
    Sprite* getSprite2();
    Sprite* getFlagSprite();
    bool getIsBomb();
    bool getIsDebug();
    bool getIsFlagged();
    int getAdjacentBombs();
    vector<Tile*>* getNeighbors();

    // Mutators
    void setNeighbors(vector<Tile*> &neighborTiles);
    void setIsBomb(bool change);
    void setIsDebug(bool change);
    void setIsFlagged(bool change);

    // Functions
    void move(float x, float y);
    void makeBomb();
};

};