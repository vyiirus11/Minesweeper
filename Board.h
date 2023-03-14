#include "Tile.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
using namespace std;
using namespace sf;

class Board {

    Tile* tiles[16][25];
    int bombs = 0;
    bool isDebug = false;
    bool isLost = false;
    bool isWon = false;
    int remainingTiles = 400;

    Texture digits, debug, happyFace, lostFace, winFace, flag, bomb, number1, number2, number3, number4, number5,
            number6, number7, number8, test1, test2, test3, hiddenTile, shownTile;

    Sprite faceSprite, debugSprite, test1_sprite, test2_sprite, test3_sprite, scoreSprite1, scoreSprite2, scoreSprite3;

    string score = "0000";

public:
    // Constructor
    Board();

    // Destructor
    ~Board();

    // Accessors
    Tile* getTile(int row, int column);

    // Mutators
    void setNeighbors();

    void setSprite(Sprite* sprite, Texture &text);

    // Functions
    void drawBoard(RenderWindow &window);

    void updateScore();

    void addScore(int toAdd);

    void generateBombs();

    void setup();

    void loadFromFile(string fileName);

    void onClick(int x, int y, string clickType);

    void onReveal(Tile* tile);

    void toggleFlag(Tile* tile);

    void endGame();

    void winGame();

};