#include "SFML\Graphics.hpp"
#include <Windows.h>
#include "Tetris.h"
#include "Arkanoid.h"
#include "Bejeweled.h"

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{
	sf::RenderWindow window(sf::VideoMode(441, 600), "Games");  // luodaan ikkuna
	// Ladataan taustakuva ohjelmalle
	sf::Texture t1;
	t1.loadFromFile("images/background.png");
	sf::Sprite background(t1);

	sf::Font font;  // luodaan fontti
	if (!font.loadFromFile("NeatChalk.ttf"))  // jos fonttia ei lˆydy, niin ei tehd‰ mit‰‰n
	{
		// error...
	}
	float x = window.getSize().x;
	float y = window.getSize().y;

	// Kovakoodataan tekstit
	sf::Text arkanoidText;
	arkanoidText.setFont(font);
	arkanoidText.setString("Arkanoid");
	arkanoidText.setCharacterSize(24);
	arkanoidText.setOrigin(0.0f, 0.0f);
	arkanoidText.setPosition(sf::Vector2f((x / 2.0f) - (arkanoidText.getLocalBounds().width / 2.0f), (y / 2.0f) - (arkanoidText.getLocalBounds().height / 2.0f) + -50));

	sf::Text tetrisText;
	tetrisText.setFont(font);
	tetrisText.setString("Tetris");
	tetrisText.setCharacterSize(24);
	tetrisText.setOrigin(0.0f, 0.0f);
	tetrisText.setPosition(sf::Vector2f((x / 2.0f) - (tetrisText.getLocalBounds().width / 2.0f), (y / 2.0f) - (tetrisText.getLocalBounds().height / 2.0f)));

	sf::Text bejeweledText;
	bejeweledText.setFont(font);
	bejeweledText.setString("Bejeweled");
	bejeweledText.setCharacterSize(24);
	bejeweledText.setOrigin(0.0f, 0.0f);
	bejeweledText.setPosition(sf::Vector2f((x / 2.0f) - (bejeweledText.getLocalBounds().width / 2.0f), (y / 2.0f) - (bejeweledText.getLocalBounds().height / 2.0f) + 50));

	sf::Text exitText;
	exitText.setFont(font);
	exitText.setString("Exit");
	exitText.setCharacterSize(24);
	exitText.setOrigin(0.0f, 0.0f);
	exitText.setPosition(sf::Vector2f((x / 2.0f) - (exitText.getLocalBounds().width / 2.0f), (y / 2.0f) - (exitText.getLocalBounds().height / 2.0f) + 150));

	// "k‰ynnistet‰‰n ohjelma" 
	while (window.isOpen())
	{
		sf::Event event;  // Luodaan tapahtumien seuranta switch casella
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:  // ohjelma sulkeutuu, kun klikkaa yl‰nurkan risti‰
					window.close();
					break;
				case sf::Event::MouseMoved:  // Luodaan teksteist‰ napit, jotka vaihtavat v‰ri‰, kun hiiri menee p‰‰lle ja pois p‰‰lt‰
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					
					if (bejeweledText.getGlobalBounds().contains(mousePosF))
					{
						bejeweledText.setFillColor(sf::Color::Red);
					}
					else
					{
						bejeweledText.setFillColor(sf::Color::White);
					}

					if (tetrisText.getGlobalBounds().contains(mousePosF))
					{
						tetrisText.setFillColor(sf::Color::Red);
					}
					else
					{
						tetrisText.setFillColor(sf::Color::White);
					}

					if (arkanoidText.getGlobalBounds().contains(mousePosF))
					{
						arkanoidText.setFillColor(sf::Color::Red);
					}
					else
					{
						arkanoidText.setFillColor(sf::Color::White);
					}

					if (exitText.getGlobalBounds().contains(mousePosF))
					{
						exitText.setFillColor(sf::Color::Red);
					}
					else
					{
						exitText.setFillColor(sf::Color::White);
					}
				}
				break;
				case sf::Event::MouseButtonPressed: // tehd‰‰n "onclick" tapahtumat teksteille.
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					if (bejeweledText.getGlobalBounds().contains(mousePosF))
					{
						Bejeweled();
					}
					if (tetrisText.getGlobalBounds().contains(mousePosF))
					{
						Tetris();
					}
					if (arkanoidText.getGlobalBounds().contains(mousePosF))
					{
						Arkanoid();
					}
					if (exitText.getGlobalBounds().contains(mousePosF))
					{
						window.close();
						break;
					}
				}
				break;
			}
		}
		// Luodaan ikkuna taustakuvineen yms.
		window.clear(sf::Color::White);	// ei pakko m‰‰ritell‰ v‰ri‰, koska taustakuva on m‰‰ritelty erikseen
		window.draw(background);
		window.draw(arkanoidText);
		window.draw(tetrisText);
		window.draw(bejeweledText);
		window.draw(exitText);
		window.display();
	}
	return 0;
}