#pragma once

#include "Player.h"

class Game {

private:

	const int screenWidth;
	const int screenHeight;
	bool gameOver;
	bool pause;
	int score;
	Camera3D camera = { 0 };

	Vector3 groundCenterPos = { 0.0f, -1.0f, -40.0f };
	Vector2 groundSize = { 20.0f, 100.0f };

	Player player;

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