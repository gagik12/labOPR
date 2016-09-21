#include "stdafx.h"
#include "Config.h"
#include "circle.h"
#include "clock.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <cmath>


void ProcessingEvent(sf::RenderWindow &window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void Render(sf::RenderWindow &window, Clocks const& clock, FigureCircle const& circle)
{
	window.clear(sf::Color::White);
	window.draw(circle.clockCircle);

	for (int i = 0; i<60; i++)
	{
		window.draw(clock.dot[i]);
	}

	window.draw(clock.hourHand);
	window.draw(clock.minuteHand);
	window.draw(clock.secondsHand);
	window.draw(circle.centerCircle);
	window.display();
}

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML Analog Clock", sf::Style::Close, settings);

	sf::Vector2f windowCenter = sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

	FigureCircle circle;
	InitializeCircle(circle, windowCenter);

	Clocks clock;
	InitializeClock(clock, windowCenter);

	// Create sound effect
	sf::SoundBuffer clockSoundBuffer;

	if (!clockSoundBuffer.loadFromFile("resources/clock-1.wav"))
		return EXIT_FAILURE;
	sf::Sound clockTick;
	clockTick.setBuffer(clockSoundBuffer);
	clockTick.play();
	clockTick.setLoop(true);
	

	// Use a part of SFML logo as clock brand
	sf::Texture clockBrand;
	if (!clockBrand.loadFromFile("resources/clock-brand.png"))
	{
		//return EXIT_FAILURE;
	}

	sf::Sprite clockBrandSprite;
	clockBrandSprite.setTexture(clockBrand);
	clockBrandSprite.setOrigin(clockBrandSprite.getTextureRect().left + clockBrandSprite.getTextureRect().width / 2.0f,
		clockBrandSprite.getTextureRect().top + clockBrandSprite.getTextureRect().height / 2.0f);

	clockBrandSprite.setPosition(window.getSize().x / 2, window.getSize().y - 100);


	// Create clock background
	sf::Texture clockImage;
	if (!clockImage.loadFromFile("resources/clock-image.png"))
	{
		//return EXIT_FAILURE;
	}

	circle.clockCircle.setTexture(&clockImage);
	circle.clockCircle.setTextureRect(sf::IntRect(40, 0, 500, 500));

	while (window.isOpen())
	{
		ProcessingEvent(window);
		// Get system time
		std::time_t currentTime = std::time(NULL);

		struct tm ptm;
		localtime_s(&ptm, &currentTime);

		clock.hourHand.setRotation(ptm.tm_hour * 30 + (ptm.tm_min / 2));
		clock.minuteHand.setRotation(ptm.tm_min * 6 + (ptm.tm_sec / 12));
		clock.secondsHand.setRotation(ptm.tm_sec * 6);
		Render(window, clock, circle);
	}

	return EXIT_SUCCESS;
}