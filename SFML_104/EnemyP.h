#pragma once

#include <SFML/Graphics.hpp>
#include "BulletP.h"

class EnemyP
{
public:
	EnemyP(sf::Vector2f size)
	{ 
		enemy.setSize(size);
		enemy.setFillColor(sf::Color::Red);
	}
	~EnemyP();
	
	void setPos(sf::Vector2f newPos);
	void checkColl(BulletP bulletPlayer);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape enemy;
};

