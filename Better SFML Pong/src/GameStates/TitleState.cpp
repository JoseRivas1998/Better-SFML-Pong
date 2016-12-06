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
	ball = new Ball(25, 25, Ball::BounceMode::ALL_SIDES);
	ballResetTimer = 0;
	title.setFont(Constants::font);
	enter.setFont(Constants::font);

	title.setCharacterSize(72);
	title.setString(Constants::TITLE);

	enter.setString("Press Enter to Play");

	FloatRect titleRect = title.getLocalBounds();
	title.setOrigin(titleRect.left + titleRect.width * .5f, titleRect.top + titleRect.height * .5f);
	title.setPosition(Constants::WORLD_WIDTH * .5f, Constants::WORLD_HEIGHT * .25f);

	FloatRect enterRect = enter.getLocalBounds();
	enter.setOrigin(enterRect.left + enterRect.width * .5f, enterRect.top + enterRect.height * .5f);
	enter.setPosition(Constants::WORLD_WIDTH * .5f, Constants::WORLD_HEIGHT * .75f);
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
	ball->update(dt);
	ballResetTimer += dt;
	if (ballResetTimer >= ballResetTime)
	{
		ball->reset();
		ballResetTimer = 0;
	}
}

void TitleState::draw(RenderWindow * window)
{
	ball->draw(window);
	window->draw(title);
	window->draw(enter);
}
