#pragma once
#include <string>
class Constants
{
public:
	static enum class States {
		TITLE, PLAY
	};

	static const int WORLD_WIDTH = 800;
	static const int WORLD_HEIGHT = 600;
	static const std::string TITLE;
	static bool closeWindow;
	static void close();

};

