#pragma once
#include "../Constants.h"
#include "../GameStates/GameState.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class GameState;
class GameStateManager
{
private:
	GameState* state;
public:
	GameStateManager();
	GameStateManager(Constants::States defaultState);
	void setState(Constants::States newState);
	void handleInput();
	void update(float dt);
	void draw(RenderWindow* window);
};

