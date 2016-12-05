#include "stdafx.h"
#include "GameState.h"
#include <iostream>

GameState::GameState()
{
}

GameState::GameState(GameStateManager* gsm)
{
	this->m_gsm = gsm;
}