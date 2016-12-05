// HelloSFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "InputProcessor.h"

using namespace sf;

int main()
{
	InputProcessor input;
	VideoMode vm(800, 600);

	RenderWindow window(vm, Constants::TITLE, Style::Default);

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

		MyInput::update();
	}
    return 0;
}

