#include "stdafx.h"
#include "clock.h"
#include "Config.h"

void Clocks::CreateListDots(sf::Vector2f const& windowCenter)
{
	float angle = 0.0;
	sf::Vector2f positionDot;
	for (int i = 0; i<60; i++)
	{
		positionDot.x = (clockCircleSize - 10) * cos(angle);
		positionDot.y = (clockCircleSize - 10) * sin(angle);

		if (i % 5 == 0)
			dot[i] = sf::CircleShape(3);
		else
			dot[i] = sf::CircleShape(1);
		dot[i].setFillColor(sf::Color::Black);
		dot[i].setOrigin(dot[i].getGlobalBounds().width / 2, dot[i].getGlobalBounds().height / 2);
		dot[i].setPosition(positionDot.x + windowCenter.x, positionDot.y + windowCenter.y);

		angle = angle + ((2 * PI) / 60);
	}
}

void Clocks::CreateTimeHands(sf::Vector2f const& windowCenter)
{
	hourHand.setSize(sf::Vector2f(5, 180));
	minuteHand.setSize(sf::Vector2f(3, 240));
	secondsHand.setSize(sf::Vector2f(2, 250));

	hourHand.setFillColor(sf::Color::Black);
	minuteHand.setFillColor(sf::Color::Black);
	secondsHand.setFillColor(sf::Color::Red);

	hourHand.setOrigin(hourHand.getGlobalBounds().width / 2, hourHand.getGlobalBounds().height - 25);
	minuteHand.setOrigin(minuteHand.getGlobalBounds().width / 2, minuteHand.getGlobalBounds().height - 25);
	secondsHand.setOrigin(secondsHand.getGlobalBounds().width / 2, secondsHand.getGlobalBounds().height - 25);

	hourHand.setPosition(windowCenter);
	minuteHand.setPosition(windowCenter);
	secondsHand.setPosition(windowCenter);
}


void InitializeClock(Clocks &clock, sf::Vector2f windowCenter)
{
	clock.CreateListDots(windowCenter);
	clock.CreateTimeHands(windowCenter);
}