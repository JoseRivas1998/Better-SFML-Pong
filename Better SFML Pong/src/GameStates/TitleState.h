#pragma once
#include "GameState.h"
class TitleState :
	public GameState
{
public:
	TitleState(GameStateManager* gsm);
	virtual void handleInput();
	virtual void update(float dt);
	virtual void draw(RenderWindow* window);
protected:
	void init();
};

