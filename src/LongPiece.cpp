#include "LongPiece.h"
#include "ElemCube.h"
#include <GLFW/glfw3.h>
#include <iostream>

LongPiece::LongPiece(float xPos, float yPos, float zPos, float cubeSideLength, int rotation) : Tetramino(xPos, yPos, zPos, cubeSideLength, rotation) {
	color1 = 0.647f;
	color2 = 0.941f;
	color3 = 0.392f;
	for (int i=0; i<5; i++)
		for (int j=0; j<5; j++)
			for (int k = 0; k < 5; k++) {
				if (j == 2 && k == 2 && i<4) {
					if (i == 2)
						matrix[i][j][k] = 2;
					else
						matrix[i][j][k] = 1;
				}
				else
					matrix[i][j][k] = 0;
			}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++) {
				initialMatrix[i][j][k] = matrix[i][j][k];
			}

}

/*void LongPiece::draw() {
	switch (rotation) {
	case 0: 
		for (int i = -2; i < 2; i++) 
			ElemCube::drawCube(xPos + i * cubeSideLength, yPos, zPos, cubeSideLength);
		break;
	case 1:
		for (int i = -2; i < 2; i++) 
			ElemCube::drawCube(xPos, yPos + i * cubeSideLength, zPos, cubeSideLength);
		break;
	case 2:
		for (int i = -2; i < 2; i++)
			ElemCube::drawCube(xPos - i * cubeSideLength, yPos, zPos, cubeSideLength);
		break;
	case 3:
		for (int i = -2; i < 2; i++)
			ElemCube::drawCube(xPos, yPos - i * cubeSideLength, zPos, cubeSideLength);
		break;

	case 4:
		for (int i = -2; i < 2; i++) 
			ElemCube::drawCube(xPos, yPos, zPos + i * cubeSideLength, cubeSideLength);
		break;
	case 5:
		for (int i = -2; i < 2; i++)
			ElemCube::drawCube(xPos, yPos + i * cubeSideLength, zPos, cubeSideLength);
		break;
	case 6:
		for (int i = -2; i < 2; i++)
			ElemCube::drawCube(xPos, yPos, zPos - i * cubeSideLength, cubeSideLength);
		break;
	case 7:
		for (int i = -2; i < 2; i++)
			ElemCube::drawCube(xPos, yPos - i * cubeSideLength, zPos, cubeSideLength);
		break;
	}
}*/

/*void LongPiece::setRotation(int r) {
	rotation = r;
	int temp;
	switch (r) {
	case 0:
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				for (int k = 0; k < 5; k++) {
					if (j == 2 && k == 2 && i < 4) {
						if (i == 2)
							matrix[i][j][k] = 2;
						else
							matrix[i][j][k] = 1;
					}
					else
						matrix[i][j][k] = 0;
				}
		break;
	case 1:
		
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				std::cout << i << "," << j << " " << matrix[i][j][2] << std::endl;
		for (int i = 0; i < 5; i++)
			for (int j = i+1; j < 5; j++)
				for (int k=0; k<5; k++)
				{

					temp = matrix[i][j][k];
					matrix[i][j][k] = matrix[j][i][k];
					matrix[j][i][k] = temp;
				}
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				std::cout<<i<<","<<j<<" " << matrix[i][j][2] << std::endl;
		break;
	case 2:
		for (int i = 0; i < 5; i++)
			for (int j = i + 1; j < 5; j++)
				for (int k = 0; k < 5; k++)
			{

				temp = matrix[i][j][k];
				matrix[i][j][k] = matrix[j][i][k];
				matrix[j][i][k] = temp;
			}
		for (int i = 0; i < 3; i++) 
			for (int j=0; j<5; j++)
				for (int k = 0; k < 5; k++)
		
		{
			temp = matrix[i][j][k];
			matrix[i][j][k] = matrix[4-i][j][k];
			matrix[4-i][j][k] = temp;
		}
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				std::cout << i << "," << j << " " << matrix[i][j][2] << std::endl;
		break;
	case 3:
		for (int i = 0; i < 5; i++)
			for (int j = i + 1; j < 5; j++)
				for (int k = 0; k < 5; k++)
			{

				temp = matrix[i][j][k];
				matrix[i][j][k] = matrix[j][i][k];
				matrix[j][i][k] = temp;
			}
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				std::cout << i << "," << j << " " << matrix[i][j][2] << std::endl;
		break;

	case 4:
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				for (int k = j + 1; k < 5; k++)
				{

					temp = matrix[i][j][k];
					matrix[i][j][k] = matrix[i][k][j];
					matrix[i][k][j] = temp;
				}
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				std::cout << i << "," << j << " " << matrix[2][i][j] << std::endl;
		break;
	case 5:
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				for (int k = j + 1; k < 5; k++)
				{

					temp = matrix[i][j][k];
					matrix[i][j][k] = matrix[i][k][j];
					matrix[i][k][j] = temp;
				}
		break;
	case 6:
		for (int k= 0; k < 5; k++)
			for (int i = 0; i < 5; i++)
				for (int j = i + 1; j < 5; j++)
				{

					temp = matrix[k][i][j];
					matrix[k][i][j] = matrix[k][j][i];
					matrix[k][j][i] = temp;
				}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 5; j++)
				for (int k = 0; k < 5; k++)

				{
					temp = matrix[j][k][i];
					matrix[j][k][i] = matrix[j][k][4 - i];
					matrix[j][k][4 - i] = temp;
				}
		break;
	case 7:

		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				for (int k = j + 1; k < 5; k++)
				{

					temp = matrix[i][j][k];
					matrix[i][j][k] = matrix[i][k][j];
					matrix[i][k][j] = temp;
				}
		
		break;
	}
	
}*/

/*void LongPiece::draw2() {
	for (int i = -2; i < 3; i++)
		for (int j = -2; j < 3; j++)
			for (int k = -2; k < 3; k++) {
				if (matrix[i+2][j+2][k+2] != 0) {
					ElemCube::drawCube(xPos + i* cubeSideLength, yPos+ j* cubeSideLength, zPos + k*cubeSideLength, cubeSideLength);
				}
				if (rotation == 1)
					std::cout << i+2<<":"<<j+2<<":"<<k +2<<" " << matrix[i+2][j+2][k+2]<<std::endl;

			}
}*/