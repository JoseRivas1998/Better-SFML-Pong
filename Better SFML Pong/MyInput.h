#pragma once
class MyInput
{
private:
	static const int NUM_KEYS = 4;
	static bool keys[NUM_KEYS];
	static bool pkeys[NUM_KEYS];
public:
	static const int UP = 0;
	static const int DOWN = 1;
	static const int START = 2;
	static const int BACK = 3;

	static void update();
	static void setKey(int key, bool b);
	static bool keyDown(int key);
	static bool keyPressed(int key);
};

