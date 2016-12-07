#include "stdafx.h"
#include "AIPaddle.h"
#include "../Constants.h"

AIPaddle::AIPaddle() : AIPaddle::AIPaddle(Paddle::Side::RIGHT) {}

AIPaddle::AIPaddle(Paddle::Side side) : AIPaddle::AIPaddle(0, 0, side) {}

AIPaddle::AIPaddle(float width, float height, Paddle::Side side) : Paddle::Paddle(width, height, side)
{
	m_destination = (Constants::WORLD_HEIGHT * .5f) - (height * .5f);
}

void AIPaddle::setY(Ball * ball)
{
	if (m_destination > getY() + getHeight())
	{
		m_velocity.y = m_speed;
	}
	else if(m_destination < getY())
	{
		m_velocity.y = -m_speed;
	} 
	else
	{
		m_destination = Constants::clamp(ball->getY(), 0.0f, Constants::WORLD_HEIGHT - 1.0f);
	}
}
