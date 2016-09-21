#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <cmath>

static const int screenWidth = 800;
static const int screenHeight = 600;
static const const float PI = 3.1415927;
static const int clockCircleSize = 250;
static const int clockCircleThickness = 2;
 
struct Clocks
{

};

struct FigureCircle
{
	int x, y;
	float angle = 0.0;
	sf::CircleShape dot[60];
	sf::CircleShape clockCircle;
	sf::CircleShape centerCircle;

	void FigureCircle::CreateListDots(sf::Vector2f const& windowCenter);
	void FigureCircle::CreateOutlineClock(sf::Vector2f const& windowCenter);
	void FigureCircle::CreateĐircleAtCenter(sf::Vector2f const& windowCenter);
};


void FigureCircle::CreateListDots(sf::Vector2f const& windowCenter)
{
	for (int i = 0; i<60; i++)
	{
		x = (clockCircleSize - 10) * cos(angle);
		y = (clockCircleSize - 10) * sin(angle);

		if (i % 5 == 0)
			dot[i] = sf::CircleShape(3);
		else
			dot[i] = sf::CircleShape(1);
		dot[i].setFillColor(sf::Color::Black);
		dot[i].setOrigin(dot[i].getGlobalBounds().width / 2, dot[i].getGlobalBounds().height / 2);
		dot[i].setPosition(x + windowCenter.x, y + windowCenter.y);

		angle = angle + ((2 * PI) / 60);
	}
}

void FigureCircle::CreateOutlineClock(sf::Vector2f const& windowCenter)
{
	clockCircle.setRadius(clockCircleSize);
	clockCircle.setPointCount(100);
	clockCircle.setOutlineThickness(clockCircleThickness);
	clockCircle.setOutlineColor(sf::Color::Black);
	clockCircle.setOrigin(clockCircle.getGlobalBounds().width / 2, clockCircle.getGlobalBounds().height / 2);
	clockCircle.setPosition(windowCenter.x + clockCircleThickness, windowCenter.y + clockCircleThickness);
}

void FigureCircle::CreateĐircleAtCenter(sf::Vector2f const& windowCenter)
{
	centerCircle.setRadius(10);
	centerCircle.setPointCount(100);
	centerCircle.setFillColor(sf::Color::Red);
	centerCircle.setOrigin(centerCircle.getGlobalBounds().width / 2, centerCircle.getGlobalBounds().height / 2);
	centerCircle.setPosition(windowCenter);
}

void InitializeCircle(FigureCircle &circle, sf::Vector2f windowCenter)
{
	circle.CreateListDots(windowCenter);
	circle.CreateOutlineClock(windowCenter);
	circle.CreateĐircleAtCenter(windowCenter);
}

void ProcessingEvent(sf::RenderWindow &window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}


int main()
{
	const int clockCircleSize = 250;
	const int clockCircleThickness = 2;

	// Set multisampling level
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	// Create the window of the application
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML Analog Clock", sf::Style::Close, settings);

	// Define windowCenter which gets the center of the window here, right after creating window
	sf::Vector2f windowCenter = sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f);





	FigureCircle circle;
	InitializeCircle(circle, windowCenter);

	// Create a list for clock's dots


	


	// Crate another circle for center













	// Create hour, minute, and seconds hands
	sf::RectangleShape hourHand(sf::Vector2f(5, 180));
	sf::RectangleShape minuteHand(sf::Vector2f(3, 240));
	sf::RectangleShape secondsHand(sf::Vector2f(2, 250));

	hourHand.setFillColor(sf::Color::Black);
	minuteHand.setFillColor(sf::Color::Black);
	secondsHand.setFillColor(sf::Color::Red);

	hourHand.setOrigin(hourHand.getGlobalBounds().width / 2, hourHand.getGlobalBounds().height - 25);
	minuteHand.setOrigin(minuteHand.getGlobalBounds().width / 2, minuteHand.getGlobalBounds().height - 25);
	secondsHand.setOrigin(secondsHand.getGlobalBounds().width / 2, secondsHand.getGlobalBounds().height - 25);

	hourHand.setPosition(windowCenter);
	minuteHand.setPosition(windowCenter);
	secondsHand.setPosition(windowCenter);

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

		hourHand.setRotation(ptm.tm_hour * 30 + (ptm.tm_min / 2));
		minuteHand.setRotation(ptm.tm_min * 6 + (ptm.tm_sec / 12));
		secondsHand.setRotation(ptm.tm_sec * 6);

		// Clear the window
		window.clear(sf::Color::White);

		// Draw all parts of clock
		window.draw(circle.clockCircle);

		for (int i = 0; i<60; i++)
		{
			window.draw(circle.dot[i]);
		}

		window.draw(clockBrandSprite);
		window.draw(hourHand);
		window.draw(minuteHand);
		window.draw(secondsHand);
		window.draw(circle.centerCircle);

		// Display things on screen
		window.display();
	}

	return EXIT_SUCCESS;
}