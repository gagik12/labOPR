#pragma once
#include <SFML/Graphics.hpp>

struct Clocks
{
	sf::CircleShape dot[60];
	sf::RectangleShape hourHand;
	sf::RectangleShape minuteHand;
	sf::RectangleShape secondsHand;

	void Clocks::CreateListDots(sf::Vector2f const& windowCenter);
	void Clocks::CreateTimeHands(sf::Vector2f const& windowCenter);
};

void InitializeClock(Clocks &clock, sf::Vector2f windowCenter);