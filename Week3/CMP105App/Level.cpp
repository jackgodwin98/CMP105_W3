#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	rect.setSize(sf::Vector2f(50, 50));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	circle.setRadius(15);
	circle.setPosition(100, 300);
	circle.setOutlineColor(sf::Color::Black);
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineThickness(2.f);

	circle2.setRadius(15);
	circle2.setPosition(400, 400);
	circle2.setOutlineColor(sf::Color::Black);
	circle2.setFillColor(sf::Color::Blue);
	circle2.setOutlineThickness(2.f);
	// initialise game objects

	speed = 1000.f;
	circleSpeed = 250.f;
	speedC2 = 500.f;
	speedC3 = 500.f;
	widthx = (window->getSize().x - 50);
	widthx2 = (window->getSize().x - 15);
	heighty = (window->getSize().y - 15);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		circle.move(0, -circleSpeed * dt);
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		circle.move(0, circleSpeed * dt);
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		circle.move(-circleSpeed * dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		circle.move(circleSpeed * dt, 0);
	}
}

// Update game objects
void Level::update(float dt)
{
	rect.move(speed*dt, 0);
	if (rect.getPosition().x > widthx)
	{
		speed *= -1.f;
		if (rect.getPosition().x > (widthx + 50))//Incase it goes glitchy and tries to fly away again 
		{
			rect.setPosition(widthx, 100);
		}
	}
	if (rect.getPosition().x < 0)
	{
		if (rect.getPosition().x < (0 - 50))//Incase it goes glitchy and tries to fly away again
		{
			rect.setPosition(0, 100);
		}
		speed *= -1.f;
	}

	circle2.move(speedC2 * dt, speedC3 * dt);
	if (circle2.getPosition().x > widthx2)
	{
		speedC2 *= -1.f;
		if (circle2.getPosition().x > (widthx2 + 15))//Incase it goes glitchy and tries to fly away again 
		{
			circle2.setPosition(widthx2, circle2.getPosition().y);
		}
	}
	if (circle2.getPosition().x < 0)
	{
		if (circle2.getPosition().x < (0 - 15))//Incase it goes glitchy and tries to fly away again
		{
			circle2.setPosition(0, circle2.getPosition().y);
		}
		speedC2 *= -1.f;
	}
	if (circle2.getPosition().y > heighty - 15)
	{
		speedC3 *= -1.f;
		if (circle2.getPosition().y > (widthx2 + 15))//Incase it goes glitchy and tries to fly away again 
		{
			circle2.setPosition(widthx2, circle2.getPosition().y);
		}
	}
	if (circle2.getPosition().y < 0)
	{
		if (circle2.getPosition().y < (0 - 15))//Incase it goes glitchy and tries to fly away again
		{
			circle2.setPosition(0, circle2.getPosition().y);
		}
		speedC3 *= -1.f;
	}
}

// Render level
void Level::render()
{
	beginDraw();
	/*window->clear(sf::Color(100, 149, 237));
	window->draw(circle);
	window->draw(rect);*/
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
	window->draw(circle);
	window->draw(circle2);
	window->draw(rect);
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}