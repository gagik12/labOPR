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
};

void CreateDigitList(sf::Font & fontForDigit, sf::Text digit[12], sf::Vector2f const& windowCenter);
void CreateDotsList(sf::CircleShape dot[60], sf::Vector2f const& windowCenter);
void CreateTimeHands(sf::RectangleShape &hourHand, sf::RectangleShape &minuteHand, sf::RectangleShape &secondsHand, sf::Vector2f const& windowCenter);
void InitializeClock(Clocks &clock, sf::Vector2f const& windowCenter);