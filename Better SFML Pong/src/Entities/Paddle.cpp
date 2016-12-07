#include "stdafx.h"
#include "Paddle.h"
#include "../Constants.h"


Paddle::Paddle() : Paddle::Paddle(0, 0, Paddle::Side::LEFT)
{
}

Paddle::Paddle(Paddle::Side side) : Paddle::Paddle(0, 0, side)
{
}

Paddle::Paddle(float width, float height, Paddle::Side side) : Entity::Entity(0, 0, width, height)
{
	m_side = side;
	resetX(width);
	m_position.top = (Constants::WORLD_HEIGHT * .5f) - (height * .5f);
}

void Paddle::update(float dt)
{
	m_velocity.x = 0;
	m_position.top += m_velocity.y * dt;
	if (m_position.top < 0) {
		m_position.top = 0;
	}
	if (m_position.top > Constants::WORLD_HEIGHT - m_position.height)
	{
		m_position.top = Constants::WORLD_HEIGHT - m_position.height;
	}
}

void Paddle::resetX(float width)
{
	switch (m_side) {
	case Paddle::Side::LEFT:
		m_position.left = (Constants::WORLD_WIDTH * .15f) - (width * .5f);
		break;
	case Paddle::Side::RIGHT:
		m_position.left = (Constants::WORLD_WIDTH * .85f) - (width * .5f);
		break;
	default: break;
	}
}

void Paddle::resetX() {
	resetX(m_position.width);
}

Paddle::Side Paddle::getSide()
{
	return m_side;
}
