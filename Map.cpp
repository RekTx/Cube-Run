#include "Map.h"

Map::Map(std::string mapName, Vector3 gp, Vector2 gs) {

	this->mapName = mapName;

	float x = gp.x - gs.x / 2.0f + size.x / 2.0f, z = -30.0f;

	for (int i = 0; i < length; i++) {

		x = gp.x - gs.x / 2.0f + size.x / 2.0f;

		for (int j = 0; j < width; j++) {

			if (map[i][j] == 1) {

				//DrawCube({ -9.5f, 0.0f, -10.0f }, 1.0f, 1.0f, 1.0f, RED);
				//DrawCubeWires({ -9.5f, 0.0f, -10.0f }, 1.0f, 1.0f, 1.0f, MAROON);

				//DrawCube({ 9.5f, 0.0f, -10.0f }, 1.0f, 1.0f, 1.0f, RED);
				//DrawCubeWires({ -9.5f, 0.0f, -10.0f }, 1.0f, 1.0f, 1.0f, MAROON);
				

				obstacles.push_back(Obstacles({x, 0.0f, z }, size, RED, MAROON, 7.0f, gp, gs));

			}

			x += 1.0f;

		}

		z -= 20.0f;
	}


}

Map::~Map() {

}

void Map::drawMap(float fogHeight, float fogMaxHeight) {

	for (int i = 0; i < obstacles.size(); i++) {

		obstacles[i].Draw(fogHeight, fogMaxHeight);

	}

}

void Map::drawMapName() {

	DrawText(mapName.c_str(), 900, 15, 50, BLACK);

}

void Map::updateMap() {

	for (int i = 0; i < obstacles.size(); i++) {

		obstacles[i].moveDown(0.1f);

	}

}

bool Map::checkCollision(Vector3 playerPos, Vector3 playerSize) {

	for (int i = 0; i < obstacles.size(); i++) {

		if (obstacles[i].checkCollision(playerPos, playerSize)) {

			return true;

		}

	}

	return false;

}

bool Map::endGame(Vector3 playerPos, Vector3 playerSize) {

	if ((obstacles[obstacles.size() - 1].getPosition().z - obstacles[obstacles.size() - 1].getSize().z / 2.0f) - 20.0f > playerPos.z + playerSize.z / 2.0f) {

		return true;

	}
	
	return false;

}