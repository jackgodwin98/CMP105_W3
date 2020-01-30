#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	sf::RectangleShape rect;
	sf::CircleShape circle;
	sf::CircleShape circle2;
	float speed;
	float speedC2;
	float speedC3;
	float circleSpeed;
	int widthx;
	int widthx2;
	int heighty;
	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
};