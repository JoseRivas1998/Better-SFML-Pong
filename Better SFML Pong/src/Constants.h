#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class Constants
{
private:
	static SoundBuffer resetBuffer;
	static SoundBuffer bounceXBuffer;
	static SoundBuffer bounceYBuffer;
public:
	static enum class States {
		TITLE, PLAY
	};

	static const int WORLD_WIDTH = 1280;
	static const int WORLD_HEIGHT = 720; 
	static const float PI;
	static const float PI2;
	static const std::string TITLE;
	static bool closeWindow;
	static void close();
	static long initSeed;
	static bool soundsLoaded;
	static bool fontLoaded;
	static void loadSound();
	static void loadFont();
	static Sound resetSound;
	static Sound bounceXSound;
	static Sound bounceYSound;
	static Font font;
	static float clamp(float n, float min, float max);
	static int clamp(int n, int min, int max);
};

