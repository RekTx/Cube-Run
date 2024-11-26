#pragma once

#include "raylib.h"

class Box {

protected:

	Vector3 position;
	Vector3 size;
	Color color;
	Color outlineColor;
	float speed;

	Vector3 groundCenterPos;
	Vector2 groundSize;

public:

	Box(Vector3, Vector2);
	Box(Vector3, Vector3, Color, Color, float, Vector3, Vector2);
	~Box();

	void Draw();

	Vector3 getPosition();
	Vector3 getSize();
	float getSpeed();

	void setPosition(Vector3);
	void setSize(Vector3);
	void setSpeed(float);
	void setColor(Color);
	void setOutlineColor(Color);

};