#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"



class Player{
private:
	sf::Texture texture;
    std::vector<sf::RectangleShape> bullets;
    float bulletSpeed = 5.f;

public:
	sf::Sprite sprite;

    Player()
        : texture(), sprite(texture) // Inisialisasi sprite dengan texture
    {
        // Coba load texture, tangani error bila perlu
        if (!texture.loadFromFile("Assets/Player/Textures/EnemySpriteSheet.png")) {
            // Tangani error load, misal lempar exception atau log error
        }
        // Setelah load, jika perlu, perbarui sprite
        sprite.setTexture(texture);
    }

	void Initialize();
	void Load();
	void Update(Skeleton& Skeleton);
	void Draw(sf::RenderWindow& window);
};

