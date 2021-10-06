#ifndef PLANET_HPP
#define PLANET_HPP
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class Planet
{
protected:
    sf::Vector2f m_pos;
    float m_radius;
    sf::Vector2f m_gravity;
    sf::Vector2f m_acceleration;
    sf::CircleShape m_shape;
    sf::Texture m_texture;
public:
    Planet( sf::Vector2f _pos, float _radius);
    ~Planet();
    void Draw(sf::RenderWindow &window);
    sf::Vector2f GetPos() { return m_pos; };
    sf::Vector2f GetAccel() { return m_acceleration; };
    void SetPos(sf::Vector2f pos);
    void SetAccel(sf::Vector2f accel);
    float GetRadius(){ return m_radius; };
    void SetTexture(sf::Texture texture);
};

#endif