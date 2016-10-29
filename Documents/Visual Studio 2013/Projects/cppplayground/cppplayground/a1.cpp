#include "headers.h";
using namespace std;
using namespace sf;


auto main() -> int
{
	sf::RenderWindow window{ { sf::VideoMode(400,400) }, "magenta circle" };
	sf::CircleShape shape(200.f);
	shape.setFillColor(sf::Color::Magenta);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}


		window.clear();
		window.draw(shape);
		window.display();

	}
}

