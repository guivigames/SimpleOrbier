#include "Planet.hpp"

Planet::Planet( sf::Vector2f _pos, float _radius)
{
    m_pos = _pos;
    m_radius = _radius;
    m_shape.setPosition(m_pos);
    m_shape.setRadius(m_radius);
}

Planet::~Planet()
{
    
}

void Planet::SetPos(sf::Vector2f _pos)
{
    m_pos = _pos;
}

void Planet::SetAccel(sf::Vector2f _accel)
{
    m_acceleration = _accel;
}

void Planet::Draw(sf::RenderWindow &window)
{
    m_shape.setPosition(m_pos);
    m_shape.setRadius(m_radius);
    window.draw(m_shape);
}

void Planet::SetTexture(sf::Texture texture)
{
    m_texture = texture;
    m_texture.generateMipmap();
    m_shape.setTexture(&m_texture);
}

