#include "stdafx.h"
#include "TitleState.h"
#include "../Managers/MyInput.h"
#include <iostream>

TitleState::TitleState(GameStateManager* gsm) : GameState(gsm)
{
	init();
}

void TitleState::init()
{
	std::cout << "Title State Init" << std::endl;
}

void TitleState::handleInput()
{
	if (MyInput::keyPressed(MyInput::START))
	{
		m_gsm->setState(Constants::States::PLAY);
	}
	if (MyInput::keyPressed(MyInput::BACK))
	{
		Constants::close();
	}
}

void TitleState::update(float dt)
{
}

void TitleState::draw(RenderWindow * window)
{
}
