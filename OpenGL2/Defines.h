#pragma once

class Vertex { 
private:
	float x;
	float y;
	float z;
public:
	Vertex() {
	
	}
	Vertex(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	~Vertex() {
		x = NULL;
		y = NULL;
		z = NULL;
	}

	float getX() { return x; }
	float getY() { return y; }
	float getZ() { return z; }

	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }
	void setZ(float z) { this->z = z; }

};

