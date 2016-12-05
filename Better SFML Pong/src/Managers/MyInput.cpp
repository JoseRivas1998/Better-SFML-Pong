#include "stdafx.h"
#include "MyInput.h"

bool MyInput::keys[MyInput::NUM_KEYS];
bool MyInput::pkeys[MyInput::NUM_KEYS];

void MyInput::update()
{
	for (int i = 0; i < NUM_KEYS; i++) {
		MyInput::pkeys[i] = MyInput::keys[i];
	}
}

void MyInput::setKey(int key, bool b)
{
	MyInput::keys[key] = b;
}

bool MyInput::keyDown(int key)
{
	return MyInput::keys[key];
}

bool MyInput::keyPressed(int key)
{
	return MyInput::keys[key] && !MyInput::pkeys[key];
}
