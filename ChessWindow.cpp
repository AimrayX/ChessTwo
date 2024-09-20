#include "ChessWindow.h"

ChessWindow::ChessWindow(float w, float h)
    : width(w), height(h) {
    
    sf::RectangleShape rectangle(sf::Vector2f(width / 8.0f, height / 8.0f));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((j+i) % 2 == 0) {
                rectangle.setFillColor(sf::Color::White);
                
            }
            else {
                rectangle.setFillColor(sf::Color::Black);
            }
            rectangle.setPosition(sf::Vector2f(j * (height / 8.0f), i * (width / 8.0f)));
            board.push_back(rectangle);
        }
    }
    
}

void ChessWindow::run() {
    sf::RenderWindow window(sf::VideoMode(width, height), "Chess SFML");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (sf::RectangleShape rect : board) {
            window.draw(rect);
        }
        window.display();
    }
}