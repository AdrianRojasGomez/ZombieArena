#include <SFML/Graphics.hpp>
#include "Entities/Player.h"
#include "Backgrounds/ZombieArena.h"

int main()
{
	enum class State { PAUSED, LEVELING_UP, GAME_OVER, PLAYING };

	State state = State::GAME_OVER;

	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;
	sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Zombie Arena", sf::Style::Fullscreen);

	sf::View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	sf::Clock clock;

	sf::Time gameTimeTotal;

	sf::Vector2f mouseWorldPosition;

	sf::Vector2i mouseScreenPosition;

	//player instance
	Player player;
	//arena bounds
	sf::IntRect arena;
	//Background creation
	sf::VertexArray background;
	sf::Texture textureBackground;

	textureBackground.loadFromFile("res/assets/graphics/background_sheet.png");

	

	while (window.isOpen())
	{
		//TODO: handle Input

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				//Pause game
				if (event.key.code == sf::Keyboard::Return && state == State::PLAYING)
				{
					state = State::PAUSED;
				}
				// Restart if PAUSED
				else if (event.key.code == sf::Keyboard::Return && state == State::PAUSED)
				{
					state = State::PLAYING;
					clock.restart();
				}
				//Start a new game if GAME OVER
				else if (event.key.code == sf::Keyboard::Return && state == State::GAME_OVER)
				{
					state = State::LEVELING_UP;
				}

				if (state == State::PLAYING)
				{

				}


			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		if (state == State::PLAYING)
		{
			//WASD Movement

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				player.MoveUp();
			else
				player.StopUp();


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				player.MoveDown();
			else
				player.StopDown();


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				player.MoveLeft();
			else
				player.StopLeft();


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				player.MoveRight();
			else
				player.StopRight();
		}

		if (state == State::LEVELING_UP)
		{
			if (event.key.code == sf::Keyboard::Num1)
				state = State::PLAYING;

			if (event.key.code == sf::Keyboard::Num2)
				state = State::PLAYING;

			if (event.key.code == sf::Keyboard::Num3)
				state = State::PLAYING;

			if (event.key.code == sf::Keyboard::Num4)
				state = State::PLAYING;

			if (event.key.code == sf::Keyboard::Num5)
				state = State::PLAYING;

			if (event.key.code == sf::Keyboard::Num6)
				state = State::PLAYING;


			if (state == State::PLAYING)
			{
				//placeholders values
				arena.width = 500;
				arena.height = 500;
				arena.left = 0;
				arena.top = 0;

				int tileSize = CreateBackground(background, arena);

				player.Spawn(arena, resolution, tileSize);
				clock.restart();
			}

		}

		//Update the frame
		if (state == State::PLAYING)
		{
			//Update delta Time
			sf::Time dt = clock.restart();
			gameTimeTotal += dt;

			//Fraction of 1 from the delta time
			float dtAsSeconds = dt.asSeconds();
			//Locate mouse pointer
			mouseScreenPosition = sf::Mouse::getPosition();
			//convert mouse position to world position based on mainView
			mouseWorldPosition = window.mapPixelToCoords(sf::Mouse::getPosition(), mainView);
			//Update Player
			player.Update(dtAsSeconds, sf::Mouse::getPosition());
			sf::Vector2f playerPosition(player.GetCenter());
			// Center View around player
			mainView.setCenter(player.GetCenter());
		}

		//Draw the scene
		if (state == State::PLAYING)
		{
			window.clear();
			window.setView(mainView);
			window.draw(background, &textureBackground);
			window.draw(player.GetSprite());
		}

		if (state == State::LEVELING_UP)
		{

		}

		if (state == State::PAUSED)
		{

		}

		if (state == State::GAME_OVER)
		{

		}

		window.display();
	}

	return 0;
}