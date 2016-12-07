#pragma once
#include "Paddle.h"
class AIPaddle :
	public Paddle
{
public:
	AIPaddle();
	AIPaddle(Paddle::Side side);
	AIPaddle(float width, float height, Paddle::Side side);
	virtual void setY(Ball * ball);
private:
	float m_destination;
};

