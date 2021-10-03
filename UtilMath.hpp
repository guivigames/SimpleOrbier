#include <SFML/Graphics.hpp>

template <typename T>
sf::Vector2<T> operator*(const sf::Vector2<T>& left, const sf::Vector2<T>& right)
{
    T X = left.x * right.x;
    T Y = left.y * right.y;
    return sf::Vector2<T>(X,Y);
}

template<typename T>
sf::Vector2<T> operator*(const sf::Vector2<T>& left, const T& right)
{
    T X = left.x * right;
    T Y = left.y * right;
    return sf::Vector2<T>(X,Y);
}

template<typename T>
sf::Vector2<T> operator/(const sf::Vector2<T>& left, const T right)
{
    T X = left.x / right;
    T Y = left.y / right;
    return sf::Vector2<T>(X,Y);
}

template<typename T>
sf::Vector2<T> operator+(const sf::Vector2<T>& left, const T& right)
{
    T X = left.x + right;
    T Y = left.y + right;
    return sf::Vector2<T>(X,Y);
}