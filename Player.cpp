#include "Player.h"

Player::Player(Vector3 gp, Vector2 gs) : Box(gp, gs) {
	speed = 1.4f;
	color = SKYBLUE;
	outlineColor = DARKBLUE;
}

Player::Player(Vector3 pos, Vector3 s, Color c, Color oc, float sp, Vector3 gp, Vector2 gs)
	: Box(pos, s, c, oc, sp, gp, gs) {
	color = SKYBLUE;
	outlineColor = DARKBLUE;
	speed = 1.4f;
}

Player::~Player() {
}

bool Player::moveLeft(float x) {

	if (position.x - x * speed >= groundCenterPos.x - groundSize.x / 2.0f + size.x/2.0f) {

		position.x -= x * speed;
		return true;

	}

	return false;

}

bool Player::moveRight(float x) {

	if (position.x + x * speed <= groundCenterPos.x + groundSize.x / 2.0f - size.x/2.0f ) {

		position.x += x * speed;
		return true;
	}

	return false;

}