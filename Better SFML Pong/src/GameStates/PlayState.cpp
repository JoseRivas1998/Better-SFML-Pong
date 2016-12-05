#include "stdafx.h"
#include "PlayState.h"
#include "../Managers/MyInput.h"
#include <iostream>

PlayState::PlayState(GameStateManager* gsm) : GameState(gsm)
{
	std::cout << "Play State Init Const" << std::endl;
	init();
}

void PlayState::init()
{
	std::cout << "Play State Init" << std::endl;
}

void PlayState::handleInput()
{
	if (MyInput::keyPressed(MyInput::BACK))
	{
		m_gsm->setState(Constants::States::TITLE);
	}
}

void PlayState::update(float dt)
{
	std::cout << "Play State Update" << std::endl;
}

void PlayState::draw(RenderWindow* window)
{

}
