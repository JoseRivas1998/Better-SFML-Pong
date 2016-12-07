#include "stdafx.h"
#include "Entity.h"

Entity::Entity() : Entity::Entity(0, 0, 0, 0)
{
}

Entity::Entity(float width, float height) : Entity::Entity(0, 0, width, height)
{
}

Entity::Entity(float x, float y, float width, float height)
{
	m_position.left = x;
	m_position.top = y;
	m_position.width = width;
	m_position.height = height;

	m_velocity.x = 0;
	m_velocity.y = 0;
}

RectangleShape Entity::getRectangleShape(Color color)
{
	RectangleShape shape;
	shape.setPosition(Vector2f(m_position.left, m_position.top));
	shape.setSize(Vector2f(m_position.width, m_position.height));
	shape.setFillColor(color);
	return shape;
}

RectangleShape Entity::getRectangleShape() {
	return getRectangleShape(Color::White);
}

FloatRect Entity::getPosition()
{
	return m_position;
}

void Entity::setPosition(float x, float y, float width, float height)
{
	m_position.left = x;
	m_position.top = y;
	m_position.width = width;
	m_position.height = height;
}

void Entity::setPosition(FloatRect position)
{
	setPosition(position.left, position.top, position.width, position.height);
}

bool Entity::collidingWith(FloatRect r)
{
	return (m_position.left < r.left + r.width &&
			m_position.left + m_position.width > r.left &&
			m_position.top < r.top + r.height &&
			m_position.top + m_position.height > r.top);
}

bool Entity::collidingWith(Entity * e)
{
	return collidingWith(e->getPosition());
}

void Entity::draw(RenderWindow * window)
{
	window->draw(getRectangleShape());
}

void Entity::draw(RenderWindow * window, Color color)
{
	window->draw(getRectangleShape(color));
}

float Entity::getX()
{
	return m_position.left;
}

void Entity::setX(float x)
{
	m_position.left = x;
}

float Entity::getY()
{
	return m_position.top;
}

void Entity::setY(float y)
{
	m_position.top = y;
}

Vector2f Entity::getPos()
{
	return Vector2f(m_position.left, m_position.top);
}

void Entity::setPos(float x, float y)
{
	setX(x);
	setY(y);
}

void Entity::setPos(Vector2f pos)
{
	setPos(pos.x, pos.y);
}

float Entity::getWidth()
{
	return m_position.width;
}

void Entity::setWidth(float width)
{
	m_position.width = width;
}

float Entity::getHeight()
{
	return m_position.height;
}

void Entity::setHeight(float height)
{
	m_position.height = height;
}

Vector2f Entity::getSize()
{
	return Vector2f(m_position.width, m_position.height);
}

void Entity::setSize(float width, float height)
{
	setWidth(width);
	setHeight(height);
}

void Entity::setSize(Vector2f size)
{
	setSize(size.x, size.y);
}

Vector2f Entity::getVelocity()
{
	return m_velocity;
}

void Entity::setVelocity(float x, float y)
{
	m_velocity.x = x;
	m_velocity.y = y;
}

void Entity::setVelocity(Vector2f velocity)
{
	setVelocity(velocity.x, velocity.y);
}
