#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

using namespace sf;
using namespace std;

//TextField tf(20);
//tf.setPosition(30, 30);
//
// 
// 
// 
//else if (event.type == Event::MouseButtonReleased) {
//auto pos = sf::Mouse::getPosition(window);
//tf.setFocus(false);
//if (tf.contains(sf::Vector2f(pos))) {
//    tf.setFocus(true);
//}
//            }
//else {
//tf.handleInput(event);
//            }
// 
// 
// 
//window.draw(tf.m_rect);
//storage.showText(window, tf.getText(), 30, 50, 20, Color::Black);

class TextField : public Transformable
{

public:
    unsigned int m_size;
    Font m_font;
    string m_text;
    RectangleShape m_rect;
    bool m_hasfocus;

    TextField(unsigned int maxChars);

    const string getText() const;

    void setPosition(float x, float y);

    bool contains(sf::Vector2f point) const;

    void setFocus(bool focus);

    void handleInput(Event e);
};
