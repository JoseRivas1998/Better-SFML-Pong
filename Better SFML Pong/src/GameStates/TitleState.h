#pragma once
#include "GameState.h"
#include "../Entities/Ball.h"
class TitleState :
	public GameState
{
private:
	Ball *ball;
	const float ballResetTime = 30;
	float ballResetTimer;
	Text title;
	Text enter;
public:
	TitleState(GameStateManager* gsm);
	virtual void handleInput();
	virtual void update(float dt);
	virtual void draw(RenderWindow* window);
protected:
	void init();
};

