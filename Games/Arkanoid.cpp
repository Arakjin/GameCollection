#include "Arkanoid.h"

#include <SFML/Graphics.hpp>
#include <time.h>

Arkanoid::Arkanoid()
{
	srand(time(0));

	sf::RenderWindow app(sf::VideoMode(520, 450), "Arkanoid!");
	app.setFramerateLimit(60);

	sf::Texture t1, t2, t3, t4;
	t1.loadFromFile("images/arkanoid/block01.png");
	t2.loadFromFile("images/arkanoid/background.jpg");
	t3.loadFromFile("images/arkanoid/ball.png");
	t4.loadFromFile("images/arkanoid/paddle.png");

	sf::Sprite sBackground(t2), sBall(t3), sPaddle(t4);
	sPaddle.setPosition(300, 440);

	sf::Sprite block[1000];

	int n = 0;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			block[n].setTexture(t1);
			block[n].setPosition(i * 43, j * 20);
			n++;
		}

	float dx = 6, dy = 5;
	float x = 300, y = 300;

	while (app.isOpen())
	{
		sf::Event e;
		while (app.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				app.close();
		}

		x += dx;
		for (int i = 0; i<n; i++)
			if (sf::FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds()))
			{
				block[i].setPosition(-100, 0); dx = -dx;
			}

		y += dy;
		for (int i = 0; i<n; i++)
			if (sf::FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds()))
			{
				block[i].setPosition(-100, 0); dy = -dy;
			}

		if (x<0 || x>520)  dx = -dx;
		if (y<0 || y>450)  dy = -dy;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) sPaddle.move(6, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) sPaddle.move(-6, 0);

		if (sf::FloatRect(x, y, 12, 12).intersects(sPaddle.getGlobalBounds())) dy = -(rand() % 5 + 2);

		sBall.setPosition(x, y);

		app.clear();
		app.draw(sBackground);
		app.draw(sBall);
		app.draw(sPaddle);

		for (int i = 0; i<n; i++)
			app.draw(block[i]);

		app.display();
	}
}

Arkanoid::~Arkanoid()
{

}