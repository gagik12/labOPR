#include "stdafx.h"
#include "circle.h"
#include "Config.h"

void CreateOutlineClock(sf::CircleShape & clockCircle, sf::Vector2f const& windowCenter)
{
	clockCircle.setRadius(CLOCK_CIRCLE_SIZE);
	clockCircle.setPointCount(100);
	clockCircle.setOutlineThickness(CLOCK_CIRCLE_THICKNESS);
	clockCircle.setOutlineColor(sf::Color::Black);
	clockCircle.setOrigin(clockCircle.getGlobalBounds().width / 2, clockCircle.getGlobalBounds().height / 2);
	clockCircle.setPosition(windowCenter.x + CLOCK_CIRCLE_THICKNESS, windowCenter.y + CLOCK_CIRCLE_THICKNESS);
}

void CreateCircleAtCenter(sf::CircleShape & centerCircle, sf::Vector2f const& windowCenter)
{
	centerCircle.setRadius(10);
	centerCircle.setPointCount(100);
	centerCircle.setFillColor(sf::Color::Red);
	centerCircle.setOrigin(centerCircle.getGlobalBounds().width / 2, centerCircle.getGlobalBounds().height / 2);
	centerCircle.setPosition(windowCenter);
}

void InitializeCircle(Circle &circle, sf::Vector2f const& windowCenter)
{
	CreateOutlineClock(circle.clockCircle, windowCenter);
	CreateCircleAtCenter(circle.centerCircle, windowCenter);
}
