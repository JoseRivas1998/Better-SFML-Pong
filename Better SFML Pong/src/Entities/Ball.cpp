#include "stdafx.h"
#include "Ball.h"
#include "../Constants.h"
#include <iostream>

Ball::Ball() : Ball::Ball(0, 0, 0, 0, Ball::BounceMode::TOP_BOTTOM)
{
}

Ball::Ball(Ball::BounceMode bounceMode) : Ball::Ball(0, 0, 0, 0, bounceMode)
{
}

Ball::Ball(float width, float height, Ball::BounceMode bounceMode) : Ball::Ball(0, 0, width, height, bounceMode)
{
}

Ball::Ball(float x, float y, float width, float height, Ball::BounceMode bounceMode) : Entity::Entity(x, y, width, height)
{
	std::cout << "(" << m_position.left << "," << m_position.top << ") (" << m_position.width << "," << m_position.height << ")" << std::endl;
	m_bounceMode = bounceMode;
	m_seed = 0;
	reset();
}

void Ball::reset()
{
	m_speed = 500;

	m_position.left = (Constants::WORLD_WIDTH * .5f) - (m_position.width * .5f);
	m_position.top = (Constants::WORLD_HEIGHT * .5f) - (m_position.height * .5f);

	srand(((int)time(0) * m_seed) + Constants::initSeed);
	m_radians = (float(rand()) / float(RAND_MAX)) * Constants::PI2;
	m_velocity.x = cos(m_radians) * m_speed;
	m_velocity.y = sin(m_radians) * m_speed;
	Constants::resetSound.play();
}

void Ball::update(float dt)
{
	m_position.left += m_velocity.x * dt;
	m_position.top += m_velocity.y * dt;
	switch (m_bounceMode)
	{
	case BounceMode::ALL_SIDES:
		updateBounceAllSides();
		break;
	case BounceMode::TOP_BOTTOM:
		updateTopBottom();
		break;
	default: break;
	}
	m_seed++;
}

void Ball::updateBounceAllSides()
{
	if (m_position.left < 0)
	{
		m_position.left++;
		bounceX();
	}
	if (m_position.left + m_position.width > Constants::WORLD_WIDTH)
	{
		m_position.left--;
		bounceX();
	}
	updateTopBottom();
}

void Ball::updateTopBottom()
{
	if (m_position.top < 0) 
	{
		m_position.top++;
		bounceY();
	}
	if (m_position.top + m_position.height > Constants::WORLD_HEIGHT)
	{
		m_position.top--;
		bounceY();
	}
}

void Ball::bounceX()
{
	m_velocity.x *= -1;
	m_radians = atan2(m_velocity.y, m_velocity.x);
	m_speed += speedIncrement;
	m_velocity.x = cos(m_radians) * m_speed;
	Constants::bounceXSound.play();
}

void Ball::bounceY()
{
	m_velocity.y *= -1;
	m_radians = atan2(m_velocity.y, m_velocity.x);
	m_speed += speedIncrement;
	m_velocity.y = sin(m_radians) * m_speed;
	Constants::bounceYSound.play();
}
