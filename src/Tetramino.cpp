#include "Tetramino.h"
#include "ElemCube.h"
#include <GLFW/glfw3.h>
void Tetramino::draw() {
	for (int i = -2; i < 3; i++)
		for (int j = -2; j < 3; j++)
			for (int k = -2; k < 3; k++) {
				if (matrix[i + 2][j + 2][k + 2] != 0) {
					ElemCube::drawCube(xPos + j * cubeSideLength, yPos + i * cubeSideLength, zPos + k * cubeSideLength, cubeSideLength, color1, color2, color3);
				}
				/*if (rotation == 1)
					std::cout << i+2<<":"<<j+2<<":"<<k +2<<" " << matrix[i+2][j+2][k+2]<<std::endl;*/

			}
}
void Tetramino::setRotation(int r) {
		rotation = r;
		int temp;
		/*for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				for (int k = 0; k < 5; k++)
					std::cout << "before" << k << ", " << i << "," << j << " " << matrix[k][i][j] << std::endl;*/
		switch (r) {
		case 0:
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++) {
						matrix[i][j][k] = initialMatrix[i][j][k];
					}
			/*for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)
						std::cout << "Pos1:" << k << ", " << i << "," << j << " " << matrix[k][i][j] << std::endl;*/
			break;
		case 1:

			/*for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					std::cout << i << "," << j << " " << matrix[i][j][2] << std::endl;*/
			for (int i = 0; i < 5; i++)
				for (int j = i + 1; j < 5; j++)
					for (int k = 0; k < 5; k++)
					{

						temp = matrix[i][j][k];
						matrix[i][j][k] = matrix[j][i][k];
						matrix[j][i][k] = temp;
					}
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)

					{
						temp = matrix[i][j][k];
						matrix[i][j][k] = matrix[4 - i][j][k];
						matrix[4 - i][j][k] = temp;
					}
			/*for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)
						std::cout << "Pos2:" << k << ", " << i << "," << j << " " << matrix[k][i][j] << std::endl;*/
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
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)

					{
						temp = matrix[i][j][k];
						matrix[i][j][k] = matrix[4 - i][j][k];
						matrix[4 - i][j][k] = temp;
					}
			/*for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)
						std::cout << "Pos3:" << k << ", " << i << "," << j << " " << matrix[k][i][j] << std::endl;*/
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
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)

					{
						temp = matrix[i][j][k];
						matrix[i][j][k] = matrix[4 - i][j][k];
						matrix[4 - i][j][k] = temp;
					}
			/*for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)
						std::cout << "Pos4:" << k << ", " << i << "," << j << " " << matrix[k][i][j] << std::endl;*/
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
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)

					{
						temp = matrix[j][k][i];
						matrix[j][k][i] = matrix[j][k][4 - i];
						matrix[j][k][4 - i] = temp;
					}
			/*for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k=0; k<5;k++)
						std::cout<<"Pos5:" << k<<", " << i << "," << j << " " << matrix[k][i][j] << std::endl;*/
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
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)

					{
						temp = matrix[j][k][i];
						matrix[j][k][i] = matrix[j][k][4 - i];
						matrix[j][k][4 - i] = temp;
					}
			/*for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)
						std::cout << "Pos6:" << k << ", " << i << "," << j << " " << matrix[k][i][j] << std::endl;*/
			break;
			
		case 6:
			for (int k = 0; k < 5; k++)
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
			/*for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)
						std::cout << "Pos7:" << k << ", " << i << "," << j << " " << matrix[k][i][j] << std::endl;*/
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
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)

					{
						temp = matrix[j][k][i];
						matrix[j][k][i] = matrix[j][k][4 - i];
						matrix[j][k][4 - i] = temp;
					}
			/*for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)
						std::cout << "Pos8:" << k << ", " << i << "," << j << " " << matrix[k][i][j] << std::endl;*/

			break;
		case 8:
			for (int j = 0; j < 5; j++)
				for (int i = 0; i < 5; i++)
					for (int k = i + 1; k < 5; k++)
					{

						temp = matrix[i][j][k];
						matrix[i][j][k] = matrix[k][j][i];
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
			/*for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)
						std::cout << "Pos9:" << k << ", " << i << "," << j << " " << matrix[k][i][j] << std::endl;*/
			break;
		case 9:
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k = j + 1; k < 5; k++)
					{

						temp = matrix[i][j][k];
						matrix[i][j][k] = matrix[i][k][j];
						matrix[i][k][j] = temp;
					}
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)

					{
						temp = matrix[k][i][j];
						matrix[k][i][j] = matrix[k][4 - i][j];
						matrix[k][4 - i][j] = temp;
					}
		
			/*for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)
						std::cout << "Pos10:" << k << ", " << i << "," << j << " " << matrix[k][i][j] << std::endl;*/
			break;
		case 10:
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k = j + 1; k < 5; k++)
					{

						temp = matrix[i][j][k];
						matrix[i][j][k] = matrix[i][k][j];
						matrix[i][k][j] = temp;
					}
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)

					{
						temp = matrix[k][i][j];
						matrix[k][i][j] = matrix[k][4 - i][j];
						matrix[k][4 - i][j] = temp;
					}
			/*for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)
						std::cout << "Pos11:" << k << ", " << i << "," << j << " " << matrix[k][i][j] << std::endl;*/
			break;
		case 11:
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k = j + 1; k < 5; k++)
					{

						temp = matrix[i][j][k];
						matrix[i][j][k] = matrix[i][k][j];
						matrix[i][k][j] = temp;
					}
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)

					{
						temp = matrix[k][i][j];
						matrix[k][i][j] = matrix[k][4 - i][j];
						matrix[k][4 - i][j] = temp;
					}
			/*for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)
						std::cout << "Pos12:" << k << ", " << i << "," << j << " " << matrix[k][i][j] << std::endl;*/
			break;
		}
		

	}


void Tetramino::rotate(int r) {

}

