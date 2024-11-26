#pragma once

#include "Box.h"

class Obstacles : public Box {

private:

public:

	Obstacles(Vector3, Vector2);
	Obstacles(Vector3, Vector3, Color, Color, float, Vector3, Vector2);
	~Obstacles();

	void Draw(float, float);

	bool moveDown(float);

	bool checkCollision(Vector3, Vector3);

};