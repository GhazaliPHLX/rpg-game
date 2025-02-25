#pragma once
#include <SFML/Graphics.hpp>

class Skeleton{

private:
    sf::Texture texture;

public:
    sf::Sprite sprite;

    Skeleton()
        : texture(), sprite(texture) // Inisialisasi sprite dengan texture
    {
        // Coba load texture, tangani error bila perlu
        if (!texture.loadFromFile("Assets/Enemy/Textures/SpriteSheet.png")) {
            // Tangani error load, misal lempar exception atau log error
        }
        // Setelah load, jika perlu, perbarui sprite
        sprite.setTexture(texture);
    }

    void Initialize();
    void Load();
    void Update();
    void Draw(sf::RenderWindow& window);
};

