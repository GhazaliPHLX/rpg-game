#include <SFML/Graphics.hpp>
#include <iostream>


int main() {

	//--------------------------INITIALIZE-------------------------------
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Kuru Kuru", sf::Style::Default, sf::State::Windowed, settings);
	
	//--------------------------INITIALIZE-------------------------------
	//--------------------------LOAD-------------------------------------
	sf::Texture playerTexture;
	

	if (playerTexture.loadFromFile("Assets/Player/Textures/spriteSheet.png")) {
		std::cout << "Texture loaded succesfully" << std::endl;
	}
	else {
		std::cout << "Texture load failed" << std::endl;
	}

	sf::Sprite playerSprite(playerTexture);

	//Set Kotak Texture yang dijadikan sprite {x,y}{width, height}
	int XIndex = 0;
	int YIndex = 0;

	playerSprite.setTextureRect(sf::IntRect({ XIndex * 64,YIndex * 64 },{64,64}));

	//--------------------------LOAD-------------------------------------




	//Main Game Loop (Wajib meimiliki fungsi Update dan Draw) (Ini adalah 1 Frame)
	while (window.isOpen()) 
	{	//----------------------UPDATE--------------------------
		//Membuat loop event (Menerima input dari OS)

		while (const std::optional event = window.pollEvent()) {
			
			//Kondisi untuk close windows
			if (event->is<sf::Event::Closed>())
				window.close();	

		}

		// Gk boleh di dalam Update loop
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) 			
			playerSprite.move(sf::Vector2f(0,-0.1));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) 
			playerSprite.move(sf::Vector2f(-0.1, 0));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) 
			playerSprite.move(sf::Vector2f(0, 0.1));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) 
			playerSprite.move(sf::Vector2f(0.1, 0));
		
		//----------------------UPDATE--------------------------

		//----------------------DRAW----------------------------
		window.clear(sf::Color::Black);
		
		window.draw(playerSprite);

		window.display();
		//----------------------DRAW----------------------------
	}

	return 0;
}

