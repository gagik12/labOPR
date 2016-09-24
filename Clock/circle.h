#pragma once
#include <SFML/Graphics.hpp>

struct Circle
{
	sf::CircleShape clockCircle;
	sf::CircleShape centerCircle;

	void CreateOutlineClock(sf::Vector2f const& windowCenter);
	void CreateCircleAtCenter(sf::Vector2f const& windowCenter);
};

void InitializeCircle(Circle &circle, sf::Vector2f const& windowCenter);