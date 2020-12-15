#include "EnemyP.h"

EnemyP::EnemyP(sf::Vector2f size)
{
	enemy.getSize();
}

EnemyP::~EnemyP()
{
}

void EnemyP::setPos(sf::Vector2f newPos)
{
	enemy.setPosition(newPos);
}

void EnemyP::checkColl(BulletP bulletPlayer)
{
	if (bulletPlayer.getRight() > enemy.getPosition().x &&
		bulletPlayer.getTop() < enemy.getPosition().y + enemy.getSize().y &&
		bulletPlayer.getBottom() > enemy.getPosition().y)
	{
		enemy.setPosition(sf::Vector2f(500.0f, 600.0f));
	}
}

void EnemyP::draw(sf::RenderWindow& window)
{
	window.draw(enemy);
}
