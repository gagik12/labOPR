#pragma once
#include <SFML/Graphics.hpp>

struct Clocks
{
	sf::CircleShape dot[60];

	sf::Font fontForDigit;
	sf::Text digit[12];

	sf::RectangleShape hourHand;
	sf::RectangleShape minuteHand;
	sf::RectangleShape secondsHand;

	void CreateDotsList(sf::Vector2f const& windowCenter);
	void CreateTimeHands(sf::Vector2f const& windowCenter);
	void CreateDigitList(sf::Vector2f const& windowCenter);
};

void InitializeClock(Clocks &clock, sf::Vector2f const& windowCenter);