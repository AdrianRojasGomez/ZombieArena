#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	~Player();
	void Update(float elapsedTime, sf::Vector2i mousePosition);

	void Spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize);
	void ResetPlayerStats();

	sf::Time GetLastHitTime() { return m_LastHit; }
	bool Hit(sf::Time timeHit);
	sf::FloatRect GetPosition() { return m_Sprite.getGlobalBounds(); }
	sf::Vector2f GetCenter() { return m_Position; }
	float GetRotation() { return m_Sprite.getRotation(); }
	sf::Sprite GetSprite() { return m_Sprite; }

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void StopLeft();
	void StopRight();
	void StopUp();
	void StopDown();

	void UpgradeSpeed();
	void UpgradeHealth();

	void IncreaseHealthLevel(int amount);
	int GetHealth() { return m_Health; }



private:
	const float START_SPEED = 100.0f;
	const float START_HEALTH = 100.0f;

	sf::Vector2f m_Position;
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	sf::Vector2f m_Resolution;
	sf::IntRect m_Arena;
	int m_Tilesize;

	bool m_LeftPressed;
	bool m_RightPressed;
	bool m_UpPressed;
	bool m_DownPressed;

	int m_Health;
	int m_MaxHealth;
	sf::Time m_LastHit;
	float m_Speed;

};
