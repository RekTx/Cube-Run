#pragma once

#include "Player.h"
#include "Map.h"

class Game {

private:

	const int screenWidth;
	const int screenHeight;
	int score;

	bool gameOver;
	bool pause;
	bool levelEnd;
	
	Camera3D camera = { 0 };

	Vector3 groundCenterPos = { 0.0f, -0.5f, -40.0f };
	Vector2 groundSize = { 16.0f, 550.0f };

	Player player;
	Map *currentMap;

public:

	Game(int, int);
	~Game();

	void Run();
	void Update();
	void Draw();
	void Draw2d();
	void Draw3d();
	void Check();
	void Input();
	void gameLoop();
	void drawScore();

};