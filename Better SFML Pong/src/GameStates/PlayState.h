#pragma once
#include "GameState.h"
#include "../Entities/Entity.h"
class PlayState :
	public GameState
{
private:
	Entity e;
public:
	PlayState(GameStateManager* gsm);
	virtual void handleInput();
	virtual void update(float dt);
	virtual void draw(RenderWindow* window);
protected:
	void init();
};

