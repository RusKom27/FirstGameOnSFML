#include "TextField.h"


TextField::TextField(unsigned int maxChars) :
    m_size(maxChars),
    m_rect(Vector2f(15 * m_size, 20)),
    m_hasfocus(false)
{
    m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
    m_rect.setOutlineThickness(2);
    m_rect.setFillColor(Color::White);
    m_rect.setOutlineColor(Color(127, 127, 127));
    m_rect.setPosition(this->getPosition());
}
const string TextField::getText() const {
    return m_text;
}

void TextField::setPosition(float x, float y) {
    Transformable::setPosition(x, y);
    m_rect.setPosition(x, y);
}

bool TextField::contains(sf::Vector2f point) const {
    return m_rect.getGlobalBounds().contains(point);
}

void TextField::setFocus(bool focus) {
    m_hasfocus = focus;
    if (focus) {
        m_rect.setOutlineColor(Color::Blue);
    }
    else {
        m_rect.setOutlineColor(Color(127, 127, 127)); 
    }
}

void TextField::handleInput(Event e) {
    if (!m_hasfocus || e.type != Event::TextEntered)
        return;

    if (e.text.unicode == 8) { 
        m_text = m_text.substr(0, m_text.size() - 1);
    }
    else if (m_text.size() < m_size) {
        m_text += e.text.unicode;
    }
}