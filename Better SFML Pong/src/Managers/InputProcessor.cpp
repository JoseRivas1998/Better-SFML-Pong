#include "stdafx.h"
#include "InputProcessor.h"
#include <SFML/Window.hpp>

void InputProcessor::keyDown(int keycode)
{
	if (keycode == sf::Keyboard::Up || keycode == sf::Keyboard::W)
	{
		MyInput::setKey(MyInput::UP, true);
	}
	if (keycode == sf::Keyboard::Down || keycode == sf::Keyboard::S)
	{
		MyInput::setKey(MyInput::DOWN, true);
	}
	if (keycode == sf::Keyboard::Return)
	{
		MyInput::setKey(MyInput::START, true);
	}
	if (keycode == sf::Keyboard::Escape)
	{
		MyInput::setKey(MyInput::BACK, true);
	}
}

void InputProcessor::keyUp(int keycode)
{
	if (keycode == sf::Keyboard::Up || keycode == sf::Keyboard::W)
	{
		MyInput::setKey(MyInput::UP, false);
	}
	if (keycode == sf::Keyboard::Down || keycode == sf::Keyboard::S)
	{
		MyInput::setKey(MyInput::DOWN, false);
	}
	if (keycode == sf::Keyboard::Return)
	{
		MyInput::setKey(MyInput::START, false);
	}
	if (keycode == sf::Keyboard::Escape)
	{
		MyInput::setKey(MyInput::BACK, false);
	}
}
