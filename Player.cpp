#include "Player.h"

Player::Player(Vector3 gp, Vector2 gs) {

	groundCenterPos = gp;
	groundSize = gs;

	position = { 0.0f, 0.0f, -1.0f };
	size = { 1.0f, 1.0f, 1.0f };
	color = SKYBLUE;
	outlineColor = DARKBLUE;
	speed = 1.4f;

}

Player::Player(Vector3 pos, Vector3 s, Color c, Color oc, float sp, Vector3 gp, Vector2 gs)
	: position(pos), size(s), color(c), speed(sp), outlineColor(oc), groundCenterPos(gp), groundSize(gs) {
}

Player::~Player() {
}

void Player::Draw() {

	DrawCube(position, size.x, size.y, size.z, color);
	DrawCubeWires(position, size.x, size.y, size.z, outlineColor);

}

bool Player::moveLeft(float x) {

	if (position.x - x * speed >= groundCenterPos.x - groundSize.x / 2.0f + size.x + 0.1f) {

		position.x -= x * speed;
		return true;

	}

	return false;

}

bool Player::moveRight(float x) {

	if (position.x + x * speed <= groundCenterPos.x + groundSize.x / 2.0f - size.x - 0.1f ) {

		position.x += x * speed;
		return true;
	}

	return false;

}

Vector3 Player::getPosition() {

	return position;

}

Vector3 Player::getSize() {

	return size;

}

float Player::getSpeed() {

	return speed;

}

void Player::setPosition(Vector3 pos) {

	position = pos;

}

void Player::setSize(Vector3 s) {

	size = s;

}

void Player::setSpeed(float sp) {

	speed = sp;

}

void Player::setColor(Color c) {

	color = c;

}

void Player::setOutlineColor(Color oc) {

	outlineColor = oc;

}