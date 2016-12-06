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
	ball = new Ball(25, 25, Ball::BounceMode::TOP_BOTTOM);
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
	ball->update(dt);
}

void PlayState::draw(RenderWindow* window)
{
	ball->draw(window);
}
