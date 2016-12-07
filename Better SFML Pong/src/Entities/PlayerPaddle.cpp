#include "stdafx.h"
#include "PlayerPaddle.h"
#include "../Managers/MyInput.h"


PlayerPaddle::PlayerPaddle() : Paddle::Paddle() {}

PlayerPaddle::PlayerPaddle(Paddle::Side side) : Paddle::Paddle(side) {}

PlayerPaddle::PlayerPaddle(float width, float height, Paddle::Side side) : Paddle::Paddle(width, height, side) {}

void PlayerPaddle::setY(Ball * b)
{
	if (MyInput::keyDown(MyInput::UP))
	{
		m_velocity.y = -m_speed;
	}
	else if (MyInput::keyDown(MyInput::DOWN))
	{
		m_velocity.y = m_speed;
	}
	else
	{
		m_velocity.y = 0;
	}
}


