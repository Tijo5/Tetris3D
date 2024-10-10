#pragma once
#include "Tetramino.h"

class LongPiece: public Tetramino
{
private:


public:
	LongPiece(float xPos, float yPos, float zPos, float cubeSideLength, int rotation);
	~LongPiece() {};
	int getPieceType() { return 1; };
	//void setRotation(int r);
	//void draw();
	//void draw2();
};


