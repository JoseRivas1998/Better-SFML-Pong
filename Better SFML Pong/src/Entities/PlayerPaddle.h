#pragma once
#include "Paddle.h"
class PlayerPaddle :
	public Paddle
{
public:
	PlayerPaddle();
	PlayerPaddle(Paddle::Side side);
	PlayerPaddle(float width, float height, Paddle::Side side);
	virtual void setY(Ball * b);
};

