#pragma once
#include "GameState.h"
class PlayState :
	public GameState
{
public:
	PlayState(GameStateManager* gsm);
	virtual void handleInput();
	virtual void update(float dt);
	virtual void draw(RenderWindow* window);
protected:
	void init();
};

