#include "Game.h"
#include <string>

Game::Game(int x = 1920, int y = 1080) 
	: player(groundCenterPos, groundSize), screenWidth(x), screenHeight(y), gameOver(false), levelEnd(false), score(0), pause(false) {

	currentMap = NULL;
	camera.position = { 0.0f, 2.0f, 10.0f };
	camera.target = groundCenterPos;
	//camera.target = player.getPosition();
	camera.up = { 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

}

Game::~Game() {

	CloseWindow();

}

void Game::Run() {

	InitWindow(screenWidth, screenHeight, "Box Game");


	//DisableCursor();

	SetTargetFPS(60);

	currentMap = new Map("Level 1", groundCenterPos, groundSize);

	gameLoop();
	
}

void Game::gameLoop() {

	while (!WindowShouldClose()) {

		Input();

		if (!pause) {
			Update();
			Check();
			if (gameOver) {
				break;
			}
			score++;
		}
		
		Draw();

	}

	// show gameover screen if levelEnd is false

	BeginDrawing();
	if (gameOver && !levelEnd) {
		
		DrawText("Game Over!", screenWidth / 2 - 100 +1, 200, 40, BLACK);
		DrawText("Game Over!", screenWidth / 2 - 100 -1, 200, 40, BLACK);
		DrawText("Game Over!", screenWidth / 2 - 100, 200 +1, 40, BLACK);
		DrawText("Game Over!", screenWidth / 2 - 100, 200 -1, 40, BLACK);

		DrawText("Game Over!", screenWidth / 2 - 100, 200, 40, RED);

		DrawText(("Score: " + std::to_string(score)).c_str(), screenWidth / 2 - 100 +1, 400, 40, BLACK);
		DrawText(("Score: " + std::to_string(score)).c_str(), screenWidth / 2 - 100 -1, 400, 40, BLACK);
		DrawText(("Score: " + std::to_string(score)).c_str(), screenWidth / 2 - 100, 400 +1, 40, BLACK);
		DrawText(("Score: " + std::to_string(score)).c_str(), screenWidth / 2 - 100, 400 -1, 40, BLACK);

		DrawText(("Score: " + std::to_string(score)).c_str(), screenWidth / 2 - 100, 400, 40, RED);
	}
	else if (gameOver && levelEnd) {

		DrawText("Level 1 Completed!", screenWidth / 2 - 100 + 1, 200, 40, BLACK);
		DrawText("Level 1 Completed!", screenWidth / 2 - 100 - 1, 200, 40, BLACK);
		DrawText("Level 1 Completed!", screenWidth / 2 - 100, 200 + 1, 40, BLACK);
		DrawText("Level 1 Completed!", screenWidth / 2 - 100, 200 - 1, 40, BLACK);

		DrawText("Level 1 Completed!", screenWidth / 2 - 100, 200, 40, GREEN);
		
		DrawText(("Score: " + std::to_string(score)).c_str(), screenWidth / 2 - 100 + 1, 400, 40, BLACK);
		DrawText(("Score: " + std::to_string(score)).c_str(), screenWidth / 2 - 100 - 1, 400, 40, BLACK);
		DrawText(("Score: " + std::to_string(score)).c_str(), screenWidth / 2 - 100, 400 + 1, 40, BLACK);
		DrawText(("Score: " + std::to_string(score)).c_str(), screenWidth / 2 - 100, 400 - 1, 40, BLACK);

		DrawText(("Score: " + std::to_string(score)).c_str(), screenWidth / 2 - 100, 400, 40, GREEN);
	}
	EndDrawing();

	WaitTime(2);

}

void Game::Update() {

	// multiplying player pos with 0.1f and giving it to camera position
	//camera.position = { player.getPosition().x * 0.2f, camera.position.y, player.getPosition().z * 0.2f };
	//camera.target = groundCenterPos;

	currentMap->updateMap();

}

void Game::Draw() {

	BeginDrawing();
	ClearBackground(RAYWHITE);

	// 3d
	Draw3d();
	
	// 2d
	Draw2d();

	EndDrawing();

}

void Game::Draw2d() {

	drawScore();
	currentMap->drawMapName();

}

void Game::Draw3d() {

	BeginMode3D(camera);
	
	// ground
	DrawPlane(groundCenterPos, groundSize, LIGHTGRAY);

	//const float fogStartZ = camera.position.z - 40.0f; // Start fading after 10 units from the camera
	//const float fogEndZ = camera.position.z + 10.0f;   // Fully obscured after -10 units from the camera

	float fogStartZ = -50.0f; // Start fogging at Z = -50
	float fogEndZ = -30.0f;     // Fully visible at Z = 0


	// obstacles
	currentMap->drawMap(fogStartZ, fogEndZ);

	// player
	player.Draw();

	EndMode3D();
}

void Game::Check() {

	if (currentMap->checkCollision(player.getPosition(), player.getSize())) {
		gameOver = true;
		levelEnd = false;
	}

	if (currentMap->endGame(player.getPosition(), player.getSize())) {
		gameOver = true;
		levelEnd = true;
	}

}

void Game::Input() {

	if (IsKeyPressed(KEY_P)) {
		pause = !pause;
	}

	if (IsKeyDown(KEY_A)) {
		player.moveLeft(0.1f);
	}

	if (IsKeyDown(KEY_D)) {
		player.moveRight(0.1f);
	}

	if (IsKeyPressed(KEY_R)) {
		player.setPosition({ 0.0f, 0.0f, 0.0f });
	}

}


void Game::drawScore() {
	
	DrawRectangle(10, 10, 250, 70, Fade(SKYBLUE, 0.5f));

	DrawText(("Score: " + std::to_string(score)).c_str(), 20, 20, 40, DARKBLUE);

}