#include "stdafx.h"
#include "Config.h"
#include "circle.h"
#include "clock.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

struct Application
{
	FigureCircle circle;
	Clocks clock;
};

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

struct tm GetSystemTime()
{
	std::time_t currentTime = std::time(NULL);
	struct tm ptm;
	localtime_s(&ptm, &currentTime);
	return ptm;
}

void SeTheTimeForClockHands(Clocks &clock)
{
	struct tm ptm = GetSystemTime();

	clock.hourHand.setRotation(ptm.tm_hour * 30 + (ptm.tm_min / 2));
	clock.minuteHand.setRotation(ptm.tm_min * 6 + (ptm.tm_sec / 12));
	clock.secondsHand.setRotation(ptm.tm_sec * 6);
}

void ApplicationMainLoop(sf::RenderWindow &window, Application & application)
{
	while (window.isOpen())
	{
		ProcessingEvent(window);
		SeTheTimeForClockHands(application.clock);
		Render(window, application.clock, application.circle);
	}
}

void InitializeApplication(Application &application, sf::Vector2f const& windowCenter)
{
	InitializeCircle(application.circle, windowCenter);
	InitializeClock(application.clock, windowCenter);
}

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML Analog Clock", sf::Style::Close, settings);

	sf::Vector2f windowCenter = sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

	Application application;
	InitializeApplication(application, windowCenter);

	sf::Music clockTick;
	if (!clockTick.openFromFile("resources/clock-1.wav"))
	{
		return EXIT_FAILURE;
	}
	clockTick.setLoop(true);
	clockTick.play();
	
	ApplicationMainLoop(window, application);
	return EXIT_SUCCESS;
}