#include "stdafx.h"
#include "clock.h"
#include "Config.h"
#include <string>

void CreateDigitList(sf::Font & fontForDigit, sf::Text digit[12], sf::Vector2f const& windowCenter)
{
	if (!fontForDigit.loadFromFile("resources/font/Rotonda.ttf"))
	{
		exit(EXIT_FAILURE);
	}
	sf::Text text("", fontForDigit, 25);
	text.setFillColor(sf::Color::Black); 

	float angle = 0;
	sf::Vector2f digitPosition(0, 0);

	for (int i = 0; i < 60; i++)
	{
		digitPosition.x = (CLOCK_CIRCLE_SIZE - 35) * cos(angle - PI / 3.f);
		digitPosition.y = (CLOCK_CIRCLE_SIZE - 35) * sin(angle - PI / 3.f);
		if (i % 5 == 0)
		{
			int number = i / 5;
			text.setString(std::to_string(number + 1));
			digit[number] = text;
			sf::Vector2f positionText(digitPosition + windowCenter);
			digit[number].setPosition(positionText.x, positionText.y - digit[number].getGlobalBounds().height / 2.f);
			digit[number].setOrigin(digit[number].getGlobalBounds().width / 2.f, digit[number].getGlobalBounds().height / 2.f);
		}
		angle += (2 * PI) / 60;
	}
}

void CreateDotsList(sf::CircleShape dot[60], sf::Vector2f const& windowCenter)
{
	float angle = 0.0;
	sf::Vector2f dotPosition(0, 0);

	for (int i = 0; i < 60; i++)
	{
		dotPosition.x = (CLOCK_CIRCLE_SIZE - 10) * cos(angle);
		dotPosition.y = (CLOCK_CIRCLE_SIZE - 10) * sin(angle);

		const float radius = (i % 5 == 0) ? 3.f : 1.f;
		dot[i] = sf::CircleShape(radius);

		dot[i].setFillColor(sf::Color::Black);
		dot[i].setOrigin(dot[i].getGlobalBounds().width / 2, dot[i].getGlobalBounds().height / 2);
		dot[i].setPosition(dotPosition + windowCenter);

		angle += (2 * PI) / 60;
	}
}

void CreateTimeHands(sf::RectangleShape &hourHand, sf::RectangleShape &minuteHand, sf::RectangleShape &secondsHand, sf::Vector2f const& windowCenter)
{
	hourHand.setSize(sf::Vector2f(5, 180));
	minuteHand.setSize(sf::Vector2f(3, 240));
	secondsHand.setSize(sf::Vector2f(2, 250));

	hourHand.setFillColor(sf::Color::Black);
	minuteHand.setFillColor(sf::Color::Black);
    secondsHand.setFillColor(sf::Color::Red);

	hourHand.setOrigin(hourHand.getGlobalBounds().width / 2, hourHand.getGlobalBounds().height - OFFSET_ARROW);
	minuteHand.setOrigin(minuteHand.getGlobalBounds().width / 2, minuteHand.getGlobalBounds().height - OFFSET_ARROW);
	secondsHand.setOrigin(secondsHand.getGlobalBounds().width / 2, secondsHand.getGlobalBounds().height - OFFSET_ARROW);

	hourHand.setPosition(windowCenter);
	minuteHand.setPosition(windowCenter);
	secondsHand.setPosition(windowCenter);
}


void InitializeClock(Clocks &clock, sf::Vector2f const& windowCenter)
{
	CreateDotsList(clock.dot, windowCenter);
	CreateDigitList(clock.fontForDigit, clock.digit, windowCenter);
	CreateTimeHands(clock.hourHand, clock.minuteHand, clock.secondsHand, windowCenter);
}