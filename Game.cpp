#include "Game.h"
#include <string>

Game::Game(int x = 1920, int y = 1080) 
	: player(groundCenterPos, groundSize), screenWidth(x), screenHeight(y), gameOver(false), score(0), pause(false) {

	camera.position = { 0.0f, 5.0f, 12.0f };
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


	DisableCursor();

	SetTargetFPS(60);



	gameLoop();
	
}

void Game::gameLoop() {

	while (!WindowShouldClose()) {

		Input();

		if (!pause) {
			Update();
			Check();
		}
		
		Draw();

	}

}

void Game::Update() {

	// multiplying player pos with 0.1f and giving it to camera position
	camera.position = { player.getPosition().x * 0.2f, camera.position.y, 12.0f + player.getPosition().z * 0.2f };
	camera.target = groundCenterPos;



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

}

void Game::Draw3d() {

	BeginMode3D(camera);

	// ground
	DrawPlane(groundCenterPos, groundSize, LIGHTGRAY);

	// player
	player.Draw();

	EndMode3D();
}

void Game::Check() {
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