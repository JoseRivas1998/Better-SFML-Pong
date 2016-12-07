#pragma once
#include "GameState.h"
#include "../Entities/Ball.h"
#include "../Entities/PlayerPaddle.h"
#include "../Entities/AIPaddle.h"
class PlayState :
	public GameState
{
private:
	Ball *ball;
	Paddle *player;
	Paddle *aiPaddle;
	int leftScore;
	int rightScore;
	float resetTime;
	float resetTimer = .25f;
	Text leftText;
	Text rightText;
public:
	PlayState(GameStateManager* gsm);
	virtual void handleInput();
	virtual void update(float dt);
	virtual void draw(RenderWindow* window);
protected:
	void init();
};

