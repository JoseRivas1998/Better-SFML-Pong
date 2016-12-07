#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class Entity
{
protected:
	FloatRect m_position;
	Vector2f m_velocity;
public:
	Entity();
	Entity(float width, float height);
	Entity(float x, float y, float width, float height);
	RectangleShape getRectangleShape(Color color);
	RectangleShape getRectangleShape();
	FloatRect getPosition();
	void setPosition(float x, float y, float width, float height);
	void setPosition(FloatRect position);
	bool collidingWith(FloatRect r);
	bool collidingWith(Entity * e);
	void draw(RenderWindow* window);
	void draw(RenderWindow* window, Color color);
	float getX();
	void setX(float x);
	float getY();
	void setY(float y);
	Vector2f getPos();
	void setPos(float x, float y);
	void setPos(Vector2f pos);
	float getWidth();
	void setWidth(float width);
	float getHeight();
	void setHeight(float height);
	Vector2f getSize();
	void setSize(float width, float height);
	void setSize(Vector2f size);
	Vector2f getVelocity();
	void setVelocity(float x, float y);
	void setVelocity(Vector2f velocity);
};

