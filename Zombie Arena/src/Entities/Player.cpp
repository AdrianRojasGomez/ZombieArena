#include "Player.h"

Player::Player():
	m_Speed(START_SPEED),
	m_Health(START_HEALTH),
	m_MaxHealth(START_HEALTH),
	m_Texture(),
	m_Sprite()
{
	m_Texture.loadFromFile("res/assets/graphics/player.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setOrigin(25, 25);
}

Player::~Player()
{
}

void Player::Spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize)
{
	m_Position.x = arena.width / 2;
	m_Position.y = arena.height / 2;

	m_Arena.left = arena.left;
	m_Arena.width = arena.width;
	m_Arena.top = arena.top;
	m_Arena.height = arena.height;

	m_Tilesize = tileSize;

	m_Resolution.x = resolution.x;
	m_Resolution.y = resolution.y;


}
