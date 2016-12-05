#pragma once
#include <SFML/Graphics.hpp>
#include "../Managers/GameStateManager.h"

using namespace sf;
class GameStateManager;
class GameState
{
protected:
	virtual void init()=0;
	GameStateManager* m_gsm;
public:
	GameState();
	GameState(GameStateManager* gsm);
	virtual void handleInput()=0;
	virtual void update(float dt)=0;
	virtual void draw(RenderWindow* window)=0;
};

