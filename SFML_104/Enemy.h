#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include "hitboxComponent.h"
class Enemy
{
public:
	Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, sf::Vector2f position); // , sf::Vector2f size
	~Enemy();

	void Update(float deltaTime, sf::Vector2f direction);
	void Draw(sf::RenderWindow& window);
	void OnCollision1(sf::Vector2f direction);
	void updateHP(int hit);
	bool checkIntersect(const sf::FloatRect& frect);
	void setPos(float x, float y);
	int getHP()
	{
		return this->hp;
	}
	sf::Vector2f GetPosition()
	{
		return body.getPosition();
	}
	Collider GetCollider1()
	{
		return Collider(body);
	}

private:
	Animation animation;
	sf::RectangleShape body;
	sf::RectangleShape hpBar;
	sf::RectangleShape hitboxEnemy;

	unsigned int row;
	float speed;
	bool faceLeft;

	sf::Vector2f velocity;
	bool canJump;
	bool fire;
	float jumpHeight;

	int hp;
};

