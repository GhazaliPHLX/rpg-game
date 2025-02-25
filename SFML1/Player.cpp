#include "Player.h"
#include "Math.h"



void Player::Initialize()
{
}

void Player::Load()
{
	int Xindex = 2;
	int Yindex = 0;

	//Set Kotak Texture yang dijadikan sprite {x,y}{width, height}
	sprite.setTextureRect(sf::IntRect({ Xindex * 64,Yindex * 64 }, { 64,64 }));
	sprite.setPosition(sf::Vector2f(200, 360));
}

void Player::Update(Skeleton& Skeleton)
{
	// Player Movement = Gk boleh di dalam Update loop
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		sprite.move(sf::Vector2f(0, -3));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		sprite.move(sf::Vector2f(-3, 0));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		sprite.move(sf::Vector2f(0, 3));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		sprite.move(sf::Vector2f(3, 0));


	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 5)));
		int i = bullets.size() - 1;
		bullets[i].setPosition(sprite.getPosition());

	}
	//----------------CALCULATE THE BULLET DIRECTION------------------------

	for (int i = 0; i < bullets.size();i++) {
		sf::Vector2f bulletDirection = Skeleton.sprite.getPosition() - bullets[i].getPosition();
		bulletDirection = Math::normalizeVector(bulletDirection);
		bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
	}
	//----------------CALCULATE THE BULLET DIRECTION------------------------
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	for (int i = 0; i < bullets.size();i++) {
		window.draw(bullets[i]);
	}
}
