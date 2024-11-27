#include "ZombieArena.h"

int createBackground(sf::VertexArray& rVertexArray, sf::IntRect arena)
{
	//Set up Arena
	const int TILE_SIZE = 50;
	const int TILE_TYPES = 3;
	const int VERTS_IN_QUAD = 4;

	int worldWidth = arena.width / TILE_SIZE;
	int worldHeight = arena.height / TILE_SIZE;

	//Set up Vertex Array
	rVertexArray.setPrimitiveType(sf::Quads);
	rVertexArray.resize(worldWidth * worldHeight * VERTS_IN_QUAD);
	//Start at the beggining of the Vertex Array
	int currentVertex = 0;
	for (int w = 0; w < worldWidth; w++)
	{
		for (int h = 0; h < worldHeight; h++)
		{
			rVertexArray[currentVertex + 0].position = 
				sf::Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);

			rVertexArray[currentVertex + 1].position =
				sf::Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);

			rVertexArray[currentVertex + 2].position =
				sf::Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);

			rVertexArray[currentVertex + 3].position =
				sf::Vector2f((w * TILE_SIZE), (h * TILE_SIZE) + TILE_SIZE);

			if (h == 0 || h == worldHeight - 1 || w == 0 || w == worldWidth - 1)
			{
				//Assign wall texture to borders
				rVertexArray[currentVertex + 0].texCoords =
					sf::Vector2f(0, 0 + TILE_TYPES * TILE_SIZE);

				rVertexArray[currentVertex + 1].texCoords =
					sf::Vector2f(TILE_SIZE, 0 + TILE_TYPES * TILE_SIZE);

				rVertexArray[currentVertex + 2].texCoords =
					sf::Vector2f(TILE_SIZE, TILE_SIZE + TILE_TYPES * TILE_SIZE);

				rVertexArray[currentVertex + 3].texCoords =
					sf::Vector2f(0, TILE_SIZE + TILE_TYPES * TILE_SIZE);
			}
			else
			{
				srand((int)time(0) + h * w - h);
				int mudOrGrass = (rand() % TILE_TYPES);
				int verticalOffset = mudOrGrass * TILE_SIZE;

				rVertexArray[currentVertex + 0].texCoords =
					sf::Vector2f(0, 0 + verticalOffset);

				rVertexArray[currentVertex + 1].texCoords =
					sf::Vector2f(TILE_SIZE, 0 + verticalOffset);

				rVertexArray[currentVertex + 2].texCoords =
					sf::Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);

				rVertexArray[currentVertex + 3].texCoords =
					sf::Vector2f(0, TILE_SIZE + verticalOffset);
			}

			currentVertex += VERTS_IN_QUAD;
		}
	}

	return TILE_SIZE;

}
