#include "stdafx.h"
#include "GameStateManager.h"
#include "../GameStates/PlayState.h"
#include "../GameStates/TitleState.h"

GameStateManager::GameStateManager(Constants::States defaultState)
{
	setState(defaultState);
}

GameStateManager::GameStateManager() : GameStateManager(Constants::States::TITLE)
{}

void GameStateManager::setState(Constants::States newState)
{
	switch (newState)
	{
	case Constants::States::TITLE:
		state = new TitleState(this);
		break;
	case Constants::States::PLAY :
		state = new PlayState(this);
		break;
	default:
		state = NULL;
		break;
	}
}

void GameStateManager::handleInput()
{
	state->handleInput();
}

void GameStateManager::update(float dt)
{
	state->update(dt);
}

void GameStateManager::draw(RenderWindow * window)
{
	state->draw(window);
}
