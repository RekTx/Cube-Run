#pragma once

#include "Box.h"

class Player : public Box {

private:

public:

	Player(Vector3, Vector2);
	Player(Vector3, Vector3, Color, Color, float, Vector3, Vector2);
	~Player();

	bool moveLeft(float);
	bool moveRight(float);
};