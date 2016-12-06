#pragma once
#include "Entity.h"
class Ball :
	public Entity
{
public:
	enum class BounceMode {
		ALL_SIDES, TOP_BOTTOM
	};
	Ball();
	Ball(Ball::BounceMode bounceMode);
	Ball(float width, float height, Ball::BounceMode bounceMode);
	Ball(float x, float y, float width, float height, Ball::BounceMode bounceMode);
	void reset();
	void update(float dt);
	//void collision(Paddle p);
private:
	BounceMode m_bounceMode;
	float m_speed;
	float m_radians;
	int m_seed;
	const float speedIncrement = 50;
	void updateBounceAllSides();
	void updateTopBottom();
	void bounceX();
	void bounceY();
};

