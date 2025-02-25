#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Skeleton.h"



int main() {

	//--------------------------INITIALIZE-------------------------------
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 2;
	sf::RenderWindow  window(sf::VideoMode({ 1280, 720 }), "Main Window", sf::Style::Default, sf::State::Windowed, settings);
	window.setFramerateLimit(60);
	//--------------------------INITIALIZE-------------------------------

	Player firstPlayer;
	Skeleton firstSkeleton;
	//--------------------------INITIALIZE-------------------------------
	firstPlayer.Initialize();
	firstSkeleton.Initialize();
	//--------------------------INITIALIZE-------------------------------
	
	//-----------------------------LOAD----------------------------------
	firstPlayer.Load();
	firstSkeleton.Load();
	//-----------------------------LOAD----------------------------------

	//Main Game Loop (Wajib meimiliki fungsi Update dan Draw) (Ini adalah 1 Frame)
	while (window.isOpen()) 
	{	//----------------------UPDATE--------------------------
		//Membuat loop event (Menerima input dari OS)

		while (const std::optional event = window.pollEvent()) {

			//Kondisi untuk close windows
			if (event->is<sf::Event::Closed>())
				window.close();

			firstSkeleton.Update();
			firstPlayer.Update(firstSkeleton);


		}

		//----------------------UPDATE--------------------------

		//----------------------DRAW----------------------------
		window.clear(sf::Color::Black);
		
		window.draw(firstSkeleton.sprite);

		firstPlayer.Draw(window);
		firstSkeleton.Draw(window);

		window.display();
		//----------------------DRAW----------------------------
	}

	return 0;
}

