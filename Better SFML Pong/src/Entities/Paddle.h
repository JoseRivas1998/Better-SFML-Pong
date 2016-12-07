#pragma once
#include "Entity.h"
#include "Ball.h"
class Ball;
class Paddle :
	public Entity
{
public:
	enum class Side {
		LEFT, RIGHT
	};
	Paddle();
	Paddle(Paddle::Side side);
	Paddle(float width, float height, Paddle::Side side);
	void resetX();
	void resetX(float width);
	Side getSide();
	void update(float dt);
	virtual void setY(Ball * ball) = 0;
protected:
	Side m_side;
	const float m_speed = 500;
};

