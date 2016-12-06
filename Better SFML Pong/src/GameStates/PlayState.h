#pragma once
#include "GameState.h"
#include "../Entities/Ball.h"
class PlayState :
	public GameState
{
private:
	Ball *ball;
public:
	PlayState(GameStateManager* gsm);
	virtual void handleInput();
	virtual void update(float dt);
	virtual void draw(RenderWindow* window);
protected:
	void init();
};

