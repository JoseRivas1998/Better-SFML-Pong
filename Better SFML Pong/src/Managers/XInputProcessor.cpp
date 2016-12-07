#include "stdafx.h"
#include "XInputProcessor.h"
#include "MyInput.h"

void XInputProcessor::buttonDown(int joyId, int button)
{
	if (button == XInputProcessor::START) 
	{
		MyInput::setKey(MyInput::START, true);
	}
	if (button == XInputProcessor::BACK)
	{
		MyInput::setKey(MyInput::BACK, true);
	}
}

void XInputProcessor::buttonUp(int joyId, int button)
{
	if (button == XInputProcessor::START)
	{
		MyInput::setKey(MyInput::START, false);
	}
	if (button == XInputProcessor::BACK)
	{
		MyInput::setKey(MyInput::BACK, false);
	}
}

void XInputProcessor::axisMoved(int joyId, int axis, float position)
{
	if (axis == XInputProcessor::DPAD_Y)
	{
		if (position > 30)
		{
			MyInput::setKey(MyInput::UP, true);
		}
		else
		{
			MyInput::setKey(MyInput::UP, false);
		}
		if (position < -30)
		{
			MyInput::setKey(MyInput::DOWN, true);
		}
		else
		{
			MyInput::setKey(MyInput::DOWN, false);
		}
	}
	if (axis == XInputProcessor::LEFT_Y_AXIS)
	{
		if (position < -30)
		{
			MyInput::setKey(MyInput::UP, true);
		}
		else
		{
			MyInput::setKey(MyInput::UP, false);
		}
		if (position > 30)
		{
			MyInput::setKey(MyInput::DOWN, true);
		}
		else
		{
			MyInput::setKey(MyInput::DOWN, false);
		}

	}
}
