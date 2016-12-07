#include "stdafx.h"
#include "Constants.h"

const std::string Constants::TITLE = "Pong";
bool Constants::closeWindow = false;
const float Constants::PI = 3.14159265358f;
const float Constants::PI2 = Constants::PI * 2;
long Constants::initSeed = 0;
bool Constants::soundsLoaded = false;
bool Constants::fontLoaded = false;
SoundBuffer Constants::resetBuffer;
SoundBuffer Constants::bounceXBuffer;
SoundBuffer Constants::bounceYBuffer;
Sound Constants::resetSound;
Sound Constants::bounceXSound;
Sound Constants::bounceYSound;
Font Constants::font;

void Constants::close()
{
	Constants::closeWindow = true;
}

void Constants::loadSound()
{
	if (!Constants::soundsLoaded) {
		if (Constants::resetBuffer.loadFromFile("assets/sound/ping_pong_8bit_peeeeeep.ogg") &&
			Constants::bounceXBuffer.loadFromFile("assets/sound/ping_pong_8bit_beeep.ogg") &&
			Constants::bounceYBuffer.loadFromFile("assets/sound/ping_pong_8bit_plop.ogg"))
		{
			Constants::resetSound.setBuffer(Constants::resetBuffer);
			Constants::bounceXSound.setBuffer(Constants::bounceXBuffer);
			Constants::bounceYSound.setBuffer(Constants::bounceYBuffer);
			Constants::soundsLoaded = true;
		}
		else
		{
			Constants::soundsLoaded = false;
		}
	}
}

void Constants::loadFont()
{
	if (!Constants::fontLoaded)
	{
		Constants::font.loadFromFile("assets/font/prstartk.ttf");
		Constants::fontLoaded = true;
		//Constants::fontLoaded = Constants::font.loadFromFile("assets/font/prstartk.ttf");
	}
}

float Constants::clamp(float n, float min, float max)
{
	float r = n;
	if (r < min)
	{
		r = min;
	}
	if (r > max)
	{
		r = max;
	}
	return r;
}

int Constants::clamp(int n, int min, int max)
{
	int r = n;
	if (r < min)
	{
		r = min;
	}
	if (r > max)
	{
		r = max;
	}
	return r;
}
