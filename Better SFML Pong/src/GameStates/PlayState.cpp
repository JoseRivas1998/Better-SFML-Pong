#include "stdafx.h"
#include "PlayState.h"
#include "../Managers/MyInput.h"
#include <sstream>

PlayState::PlayState(GameStateManager* gsm) : GameState(gsm)
{
	init();
}

void PlayState::init()
{
	ball = new Ball(25, 25, Ball::BounceMode::TOP_BOTTOM);
	player = new PlayerPaddle(25, 100, Paddle::Side::LEFT);
	aiPaddle = new AIPaddle(25, 100, Paddle::Side::RIGHT);
	leftScore = 0;
	rightScore = 0;
	resetTime = 0;

	rightText.setFont(Constants::font);
	leftText.setFont(Constants::font);

	rightText.setCharacterSize(64);
	leftText.setCharacterSize(64);

	rightText.setString("0");
	FloatRect rightRect = rightText.getLocalBounds();
	rightText.setOrigin(rightRect.left + rightRect.width * .5f, rightRect.top + rightRect.height * .5f);
	rightText.setPosition(Vector2f(Constants::WORLD_WIDTH * .75f, Constants::WORLD_HEIGHT * .25f));

	leftText.setString("0");
	FloatRect leftRect = leftText.getLocalBounds();
	leftText.setOrigin(leftRect.left + leftRect.width * .5f, leftRect.top + leftRect.height * .5f);
	leftText.setPosition(Vector2f(Constants::WORLD_WIDTH * .25f, Constants::WORLD_HEIGHT * .25f));
}

void PlayState::handleInput()
{
	if (MyInput::keyPressed(MyInput::BACK))
	{
		m_gsm->setState(Constants::States::TITLE);
	}
	player->setY(ball);
}

void PlayState::update(float dt)
{
	ball->update(dt);
	player->update(dt);
	aiPaddle->setY(ball);
	aiPaddle->update(dt);
	ball->collision(player);
	ball->collision(aiPaddle);
	if (ball->getX() < 0 || ball->getX() + ball->getWidth() > Constants::WORLD_WIDTH)
	{
		resetTime += dt;
		if (resetTime > resetTimer)
		{
			if (ball->getX() < 0)
			{
				rightScore++;
				std::stringstream rightss;
				rightss << rightScore;
				rightText.setString(rightss.str());
				FloatRect rightRect = rightText.getLocalBounds();
				rightText.setOrigin(rightRect.left + rightRect.width * .5f, rightRect.top + rightRect.height * .5f);
				rightText.setPosition(Vector2f(Constants::WORLD_WIDTH * .75f, Constants::WORLD_HEIGHT * .25f));
			}
			else
			{
				leftScore++;
				std::stringstream leftss;
				leftss << leftScore;
				leftText.setString(leftss.str());
				FloatRect leftRect = leftText.getLocalBounds();
				leftText.setOrigin(leftRect.left + leftRect.width * .5f, leftRect.top + leftRect.height * .5f);
				leftText.setPosition(Vector2f(Constants::WORLD_WIDTH * .25f, Constants::WORLD_HEIGHT * .25f));
			}
			ball->reset();
		}
	}
	else
	{
		resetTime = 0;
	}
}

void PlayState::draw(RenderWindow* window)
{
	float rectHeight = 5;
	float rectWidth = 10;
	float rectX = (Constants::WORLD_WIDTH * .5f) - (rectWidth * .5f);
	int numRects = int(floor(Constants::WORLD_HEIGHT / (rectHeight * 2)));
	for (int i = 0; i < numRects; i++)
	{
		float rectY = (rectHeight * .5f) + (i * (rectHeight * 2));
		RectangleShape r;
		r.setPosition(Vector2f(rectX, rectY));
		r.setSize(Vector2f(rectWidth, rectHeight));
		window->draw(r);
	}
	ball->draw(window);
	player->draw(window);
	aiPaddle->draw(window);
	window->draw(rightText);
	window->draw(leftText);
}
