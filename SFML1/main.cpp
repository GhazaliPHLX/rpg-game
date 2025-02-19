#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

sf::Vector2f normalizeVector(sf::Vector2f vector) {
	float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	sf::Vector2f normalizedVector;
	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;
	return normalizedVector;
}

int main() {

	//--------------------------INITIALIZE-------------------------------
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 2;
	sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "Main Window", sf::Style::Default, sf::State::Windowed, settings);
	window.setFramerateLimit(60);
	//--------------------------INITIALIZE-------------------------------


	//--------------------------LOAD-------------------------------------

	//--------------------------PLAYER-------------------------------------

	sf::Texture playerTexture;
	if (playerTexture.loadFromFile("Assets/Player/Textures/EnemySpriteSheet.png")) {
		std::cout << "Texture loaded succesfully" << std::endl;
	}
	else {
		std::cout << "Texture load failed" << std::endl;
	}

	sf::Sprite playerSprite(playerTexture);

	//Set Kotak Texture yang dijadikan sprite {x,y}{width, height}
	int XIndex = 0;
	int YIndex = 2;
	playerSprite.setTextureRect(sf::IntRect({ XIndex * 64,YIndex * 64 },{64,64}));
	playerSprite.setPosition(sf::Vector2f(200, 360));
	float playerSpeed = 3.0f;
	//--------------------------PLAYER-------------------------------------


	//--------------------------SKELETON LOAD-------------------------------------

	sf::Texture skeletonTexture;
	if (skeletonTexture.loadFromFile("Assets/Enemy/Textures/spriteSheet.png")) {
		std::cout << "Texture loaded succesfully" << std::endl;
	}
	else {
		std::cout << "Texture load failed" << std::endl;
	}

	sf::Sprite skeletonSprite(skeletonTexture);

	skeletonSprite.setPosition(sf::Vector2f(1000, 360));
	//--------------------------SKELETON LOAD-------------------------------------

	//Set Kotak Texture yang dijadikan sprite {x,y}{width, height}
	skeletonSprite.setTextureRect(sf::IntRect({ XIndex * 64,YIndex * 64 }, { 64,64 }));

	//------------------------------BULLET------------------------------
	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 5.f;

	//------------------------------BULLET------------------------------

	
	// var direction == Koordinat jarak dari asal peluru ke musuh

	




	//--------------------------LOAD-------------------------------------




	//Main Game Loop (Wajib meimiliki fungsi Update dan Draw) (Ini adalah 1 Frame)
	while (window.isOpen()) 
	{	//----------------------UPDATE--------------------------
		//Membuat loop event (Menerima input dari OS)

		while (const std::optional event = window.pollEvent()) {

			//Kondisi untuk close windows
			if (event->is<sf::Event::Closed>())
				window.close();

			// Player Movement = Gk boleh di dalam Update loop
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
				playerSprite.move(sf::Vector2f(0, -playerSpeed));

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
				playerSprite.move(sf::Vector2f(-playerSpeed, 0));

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
				playerSprite.move(sf::Vector2f(0, playerSpeed));

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
				playerSprite.move(sf::Vector2f(playerSpeed, 0));

			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 5)));
				int i = bullets.size() - 1;
				bullets[i].setPosition(playerSprite.getPosition());

			}
			//----------------CALCULATE THE BULLET DIRECTION------------------------

			for (int i = 0; i < bullets.size();i++) {

				sf::Vector2f cursorPosition =window.mapPixelToCoords(sf::Mouse::getPosition(window));

				sf::Vector2f bulletDirection = cursorPosition - bullets[i].getPosition();
				bulletDirection = normalizeVector(bulletDirection);
				bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
			}
			//----------------CALCULATE THE BULLET DIRECTION------------------------

		}

		//----------------------UPDATE--------------------------

		//----------------------DRAW----------------------------
		window.clear(sf::Color::Black);
		
		window.draw(skeletonSprite);
		window.draw(playerSprite);

		for (int i = 0; i < bullets.size();i++) {
			window.draw(bullets[i]);
		}
		


		window.display();
		//----------------------DRAW----------------------------
	}

	return 0;
}

