#include "stdafx.h"
#include "circle.h"
#include "Config.h"

void Circle::CreateOutlineClock(sf::Vector2f const& windowCenter)
{
	clockCircle.setRadius(clockCircleSize);
	clockCircle.setPointCount(100);
	clockCircle.setOutlineThickness(clockCircleThickness);
	clockCircle.setOutlineColor(sf::Color::Black);
	clockCircle.setOrigin(clockCircle.getGlobalBounds().width / 2, clockCircle.getGlobalBounds().height / 2);
	clockCircle.setPosition(windowCenter.x + clockCircleThickness, windowCenter.y + clockCircleThickness);
}

void Circle::CreateCircleAtCenter(sf::Vector2f const& windowCenter)
{
	centerCircle.setRadius(10);
	centerCircle.setPointCount(100);
	centerCircle.setFillColor(sf::Color::Red);
	centerCircle.setOrigin(centerCircle.getGlobalBounds().width / 2, centerCircle.getGlobalBounds().height / 2);
	centerCircle.setPosition(windowCenter);
}

void InitializeCircle(Circle &circle, sf::Vector2f const& windowCenter)
{
	circle.CreateOutlineClock(windowCenter);
	circle.CreateCircleAtCenter(windowCenter);
}
