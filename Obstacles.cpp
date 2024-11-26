#include "Obstacles.h"

#include <stdio.h>

Obstacles::Obstacles(Vector3 position, Vector2 size) 
	: Box(position, size) {

	speed = 1.1f;
	color = RED;
	outlineColor = MAROON;

}

Obstacles::Obstacles(Vector3 pos, Vector3 s, Color c, Color oc, float sp, Vector3 gp, Vector2 gs)
	: Box(pos, s, c, oc, sp, gp, gs) {}

Obstacles::~Obstacles() {}

void Obstacles::Draw(float fogStartZ, float fogEndZ) {
	Color adjustedColor = color;

	// Apply fog logic based on Z-distance
	if (position.z < fogEndZ) { // Apply fog only for obstacles behind the player
		float alpha = (position.z - fogStartZ) / (fogEndZ - fogStartZ);
		if (alpha > 1.0f) alpha = 1.0f; // Clamp maximum alpha
		if (alpha < 0.0f) alpha = 0.0f; // Clamp minimum alpha
		adjustedColor = Fade(color, alpha);

	}

	// Draw the cube with the adjusted fog color
	DrawCube(position, size.x, size.y, size.z, adjustedColor);

	// Optionally fade the outline color too
	Color adjustedOutlineColor = Fade(outlineColor, adjustedColor.a / 255.0f);
	DrawCubeWires(position, size.x, size.y, size.z, adjustedOutlineColor);
}

bool Obstacles::moveDown(float z) {

	position.z += z * speed;

	return true;
}

bool Obstacles::checkCollision(Vector3 playerPos, Vector3 playerSize) {

	if (position.x - size.x / 2.0f < playerPos.x + playerSize.x / 2.0f &&
		position.x + size.x / 2.0f > playerPos.x - playerSize.x / 2.0f &&
		//position.y - size.y / 2.0f < playerPos.y + playerSize.y / 2.0f &&
		//position.y + size.y / 2.0f > playerPos.y - playerSize.y / 2.0f &&
		position.z - size.z / 2.0f < playerPos.z + playerSize.z / 2.0f &&
		position.z + size.z / 2.0f > playerPos.z - playerSize.z / 2.0f) {

		return true;

	}

	return false;

}