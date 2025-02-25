#include "Skeleton.h"

void Skeleton::Initialize()
{
}

void Skeleton::Load()
{
	int Xindex = 2;
	int Yindex = 0;

	sprite.setPosition(sf::Vector2f(1000, 360));
	//Set Kotak Texture yang dijadikan sprite {x,y}{width, height}
	sprite.setTextureRect(sf::IntRect({ Xindex * 64,Yindex * 64 }, { 64,64 }));
}

void Skeleton::Update()
{
}

void Skeleton::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
