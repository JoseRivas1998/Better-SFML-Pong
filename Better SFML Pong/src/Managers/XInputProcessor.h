#pragma once
class XInputProcessor
{
private:
	static const int A = 0;
	static const int B = 1;
	static const int X = 2;
	static const int Y = 3;
	static const int LB = 4;
	static const int RB = 5;
	static const int BACK = 6;
	static const int START = 7;
	static const int L3 = 8;
	static const int R3 = 9;

	static const int LEFT_X_AXIS = 0;
	static const int LEFT_Y_AXIS = 1;
	static const int TRIGGERS = 2;
	static const int RIGHT_Y_AXIS = 3;
	static const int RIGHT_X_AXIS = 4;
	static const int DPAD_X = 6;
	static const int DPAD_Y = 7;
public:
	void buttonDown(int joyId, int button);
	void buttonUp(int joyId, int button);
	void axisMoved(int joyId, int axis, float position);
};

