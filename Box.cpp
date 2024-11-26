#include "Box.h"

Box::Box(Vector3 gp, Vector2 gs) {

	groundCenterPos = gp;
	groundSize = gs;

	position = { 0.0f, 0.0f, -1.0f };
	size = { 1.0f, 1.0f, 1.0f };
	color = WHITE;
	outlineColor = BLACK;
	speed = 1.0f;

}

Box::Box(Vector3 pos, Vector3 s, Color c, Color oc, float sp, Vector3 gp, Vector2 gs)
	: position(pos), size(s), color(c), speed(sp), outlineColor(oc), groundCenterPos(gp), groundSize(gs) {
}

Box::~Box() {
}

void Box::Draw() {

	DrawCube(position, size.x, size.y, size.z, color);
	DrawCubeWires(position, size.x, size.y, size.z, outlineColor);

}

Vector3 Box::getPosition() {

	return position;

}

Vector3 Box::getSize() {

	return size;

}

float Box::getSpeed() {

	return speed;

}

void Box::setPosition(Vector3 pos) {

	position = pos;

}

void Box::setSize(Vector3 s) {

	size = s;

}

void Box::setSpeed(float sp) {

	speed = sp;

}

void Box::setColor(Color c) {

	color = c;

}

void Box::setOutlineColor(Color oc) {

	outlineColor = oc;

}