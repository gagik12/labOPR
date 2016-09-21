#pragma once
#include <SFML/Graphics.hpp>

struct FigureCircle
{
	sf::CircleShape clockCircle;
	sf::CircleShape centerCircle;

	void FigureCircle::CreateOutlineClock(sf::Vector2f const& windowCenter);
	void FigureCircle::CreateĐircleAtCenter(sf::Vector2f const& windowCenter);
};

void InitializeCircle(FigureCircle &circle, sf::Vector2f const& windowCenter);