// HelloSFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Managers/InputProcessor.h"
#include "Managers/GameStateManager.h"

using namespace sf;

int main()
{
	InputProcessor input;
	VideoMode vm(800, 600);

	RenderWindow window(vm, Constants::TITLE, Style::Default);

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
		gsm.handleInput();
		gsm.update(dt);
		window.clear();
		gsm.draw(&window);
		window.display();
		MyInput::update();
	}
    return 0;
}

