#pragma once
#include <GLFW/glfw3.h>

class ElemCube {
private:
	float xPos;
	float yPos;
	float zPos;
	float cubeSideLength;
public:
	ElemCube(float xPos, float yPos, float zPos, float cubeSideLength) : xPos(xPos), yPos(yPos), zPos(zPos), cubeSideLength(cubeSideLength) {};
	void setXPos(float x) { xPos = x; };
	void setYPos(float y) { yPos = y; };
	void setZPos(float z) { zPos = z; };
	void draw();
	static void drawCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength, GLfloat c1, GLfloat c2, GLfloat c3);

};
