#include <SFML/Graphics.hpp>


int main() {

	//--------------------------INITIALIZE-------------------------------
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Kuru Kuru");
	//Drawing a Circle
	sf::CircleShape circle1(70.f);
	circle1.setOrigin({ 70.f, 70.f });	
	circle1.setFillColor(sf::Color::Red);
	circle1.setPosition(sf::Vector2f(400, 300));
	circle1.setOutlineThickness(10);
	circle1.setOutlineColor(sf::Color::Cyan);

	//Drawing a Rectangle
	sf::RectangleShape rect({ 400.f, 50.f });
	rect.setFillColor(sf::Color(70, 130, 180));
	rect.setOrigin(sf::Vector2f(rect.getSize().x / 2, rect.getSize().y / 2));
	rect.setRotation(sf::degrees(45));
	rect.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

	//Drawing Lines


	//--------------------------INITIALIZE-------------------------------


	//Main Game Loop (Wajib meimiliki fungsi Update dan Draw) (Ini adalah 1 Frame)
	while (window.isOpen()) 
	{	//----------------------UPDATE--------------------------
		//Membuat loop event (Menerima input dari OS)

		while (const std::optional event = window.pollEvent()) {
			
			//Kondisi untuk close windows
			if (event->is<sf::Event::Closed>())
				window.close();	
		}
		//----------------------UPDATE--------------------------

		//----------------------DRAW----------------------------
		window.clear(sf::Color::White);
		
		window.draw(rect);

		window.display();
		//----------------------DRAW----------------------------
	}

	return 0;
}

