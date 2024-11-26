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

void Player::Update(float elapsedTime, sf::Vector2i mousePosition)
{
	if (m_UpPressed)
		m_Position.y -= m_Speed * elapsedTime;

	if (m_DownPressed)
		m_Position.y += m_Speed * elapsedTime;

	if (m_LeftPressed)
		m_Position.x -= m_Speed * elapsedTime;

	if (m_RightPressed)
		m_Position.x += m_Speed * elapsedTime;


	m_Sprite.setPosition(m_Position);


	if (m_Position.x > m_Arena.width - m_Tilesize)
		m_Position.x = m_Arena.width - m_Tilesize;

	if (m_Position.x < m_Arena.left + m_Tilesize)
		m_Position.x = m_Arena.left + m_Tilesize;

	if (m_Position.y > m_Arena.height - m_Tilesize)
		m_Position.y = m_Arena.height - m_Tilesize;

	if (m_Position.y < m_Arena.top + m_Tilesize)
		m_Position.y = m_Arena.top + m_Tilesize;

	//Calculate the player's angle
	float angle = (atan2(mousePosition.y - m_Resolution.y / 2, mousePosition.x - m_Resolution.x / 2)
		* 180) / 3.141;

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

void Player::ResetPlayerStats()
{
	m_Speed = START_SPEED;
	m_Health = START_HEALTH;
	m_MaxHealth = START_HEALTH;
}

bool Player::Hit(sf::Time timeHit)
{
	if (timeHit.asMilliseconds() - m_LastHit.asMilliseconds() > 200)
	{
		m_LastHit = timeHit;
		m_Health -= 10;
		return true;
	}
	else
	{
		return false;
	}
}

void Player::MoveLeft()
{
	m_LeftPressed = true;
}

void Player::MoveRight()
{
	m_RightPressed = true;
}

void Player::MoveUp()
{
	m_UpPressed = true;
}

void Player::MoveDown()
{
	m_DownPressed = false;
}

void Player::StopLeft()
{
	m_LeftPressed = false;
}

void Player::StopRight()
{
	m_RightPressed = false;
}

void Player::StopUp()
{
	m_UpPressed = false;
}

void Player::StopDown()
{
	m_DownPressed = false;
}

void Player::UpgradeSpeed()
{
}



