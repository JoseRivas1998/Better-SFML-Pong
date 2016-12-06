// HelloSFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include "Constants.h"
#include "Managers/InputProcessor.h"
#include "Managers/GameStateManager.h"

using namespace sf;

int main()
{
	InputProcessor input;
	VideoMode vm(Constants::WORLD_WIDTH, Constants::WORLD_HEIGHT);

	RenderWindow window(vm, Constants::TITLE, Style::Default);

	Constants::loadSound();
	Constants::loadFont();

	float fpsTimer = 0;
	const float fpsTime = 1;

	GameStateManager gsm;

	Clock clock;

	while (window.isOpen())
	{
		/*
		*************
		EVENT POLLING
		*************
		*/
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::KeyPressed)
			{
				input.keyDown(event.key.code);
			}
			if (event.type == Event::KeyReleased)
			{
				input.keyUp(event.key.code);
			}
		}
		if (Constants::closeWindow) window.close();
		Time deltaTime = clock.restart();
		float dt = deltaTime.asSeconds();
		fpsTimer += dt;
		if (fpsTimer > fpsTime)
		{
			std::stringstream fpsStream;
			fpsStream << Constants::TITLE << " | " << (int)(1 / dt) << " fps";
			window.setTitle(fpsStream.str());
			fpsTimer = 0;
		}
		gsm.handleInput();
		gsm.update(dt);
		window.clear();
		gsm.draw(&window);
		window.display();
		Constants::initSeed++;
		MyInput::update();
	}
    return 0;
}

