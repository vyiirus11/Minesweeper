#include <SFML/Graphics.hpp>
#include "Board.h"
using namespace std;
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "Minesweeper");

    Board board;
    while(window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            } else if (event.type == Event::MouseButtonReleased) {
                if (event.mouseButton.button == Mouse::Left) {
                    board.onClick(event.mouseButton.x, event.mouseButton.y, "left");
                } else if (event.mouseButton.button == Mouse::Right) {
                    board.onClick(event.mouseButton.x, event.mouseButton.y, "right");
                }
            }
        }
        window.clear();
        board.drawBoard(window);
        window.display();
    }
    return 0;
}