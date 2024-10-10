#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ElemCube.h"
#include "LongPiece.h"
#include "Grid.h"
#include "T.h"
#include "S.h"
#include "O.h"
#include "L.h"

#define SCREEN_WIDTH 640*2
#define SCREEN_HEIGHT 480*2
#define WAIT_TIME 5
#define GRID_SPACING 75

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;
float  counter = 600.0;
GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;
// Loop until the user closes the window
GLfloat yCube = halfScreenHeight + ((B_HIGHT - 1) * GRID_SPACING) * 0.5;
Tetramino * cube= new LPiece(halfScreenWidth + GRID_SPACING / 2, yCube, -500 - GRID_SPACING / 2, GRID_SPACING, 0);
Grid g(halfScreenWidth, halfScreenHeight, -500, GRID_SPACING);


double prevTime = 0.0;
double crntTime = 0.0;
double timeDiff;

int main() {
    int r = 1;
    srand(time(NULL));
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris 3D", NULL, NULL);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

    


    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glViewport(0.0f, 0.0f, screenWidth, screenHeight); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode(GL_PROJECTION); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1000); // essentially set coordinate system
    glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity(); // same as above comment

    
    
    //bool b=g.isMovementPossibe(cube, 0, 0, -GRID_SPACING);
    //bool b2 = g.isRotationPossible(cube, 5);
    //std::cout << b2;
    while (!glfwWindowShouldClose(window))
    {
        if (!g.isMovementPossibe(*cube, 0, -GRID_SPACING, 0) && !g.isGameOver()) {
            //Tetramino* cube2 = cube;
            g.storePiece(*cube, r);

            r = rand() % 5+1;
            //std::cout << !g.isGameOver() << std::endl;
            switch (r) {
            case 1:
                cube = new LongPiece(halfScreenWidth + GRID_SPACING / 2, yCube, -500 - GRID_SPACING / 2, GRID_SPACING, 0);
                break;
            case 2:
                cube = new LPiece(halfScreenWidth + GRID_SPACING / 2, yCube, -500 - GRID_SPACING / 2, GRID_SPACING, 0);
                break;
            case 3:
                cube = new TPiece(halfScreenWidth + GRID_SPACING / 2, yCube, -500 - GRID_SPACING / 2, GRID_SPACING, 0);
                break;
            case 4:
                cube = new SPiece(halfScreenWidth + GRID_SPACING / 2, yCube, -500 - GRID_SPACING / 2, GRID_SPACING, 0);
                break;
            case 5:
                cube = new OPiece(halfScreenWidth + GRID_SPACING / 2, yCube, -500 - GRID_SPACING / 2, GRID_SPACING, 0);
                break;
            }
            
            //delete cube2;

        }
        crntTime = glfwGetTime();
        timeDiff = crntTime - prevTime;
        /*if (timeDiff > 2 && g.isMovementPossibe(*cube, 0, -GRID_SPACING, 0)) {
            cube->moveDown(GRID_SPACING);
            prevTime = crntTime;
        }*/
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        glTranslatef(halfScreenWidth, halfScreenHeight, -500);
        glRotatef(rotationX, 1, 0, 0);
        glRotatef(rotationY, 0, 1, 0);
        glTranslatef(-halfScreenWidth, -halfScreenHeight, 500);
        g.draw();
        g.deletePlane();
        g.drawBlocks();
        cube->draw();
        glPopMatrix();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
	return 0;
}

int rotationCount = 0;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

    const GLfloat rotationSpeed = 10;

    // actions are GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        switch (key)
        {
        case GLFW_KEY_W:
            rotationX -= rotationSpeed;
            break;
        case GLFW_KEY_X:
            rotationX += rotationSpeed;
            break;
        case GLFW_KEY_D:
            rotationY += rotationSpeed;
            break;
        case GLFW_KEY_A:
            rotationY -= rotationSpeed;
            break;
        case GLFW_KEY_KP_ADD:
            rotationCount++;
            while (!(g.isRotationPossible(*cube, rotationCount % 12))) {
                cube->setRotation(rotationCount % 12);
                rotationCount++;
            }
            cube->setRotation(rotationCount%12);
            break;
        case GLFW_KEY_UP:
            if (g.isMovementPossibe(*cube, 0, 0, -GRID_SPACING))
                cube->moveBackward(GRID_SPACING);
            break;
        case GLFW_KEY_DOWN:
            if (g.isMovementPossibe(*cube, 0, 0, GRID_SPACING))
                cube->moveForward(GRID_SPACING);
            break;
        case GLFW_KEY_RIGHT:
            if (g.isMovementPossibe(*cube, GRID_SPACING, 0, 0))
                cube->moveRight(GRID_SPACING);
            break;
        case GLFW_KEY_LEFT:
            if (g.isMovementPossibe(*cube, -GRID_SPACING, 0, 0))
                cube->moveLeft(GRID_SPACING);
            break;
        case GLFW_KEY_M:
            //cube->moveDown(B_HIGHT*GRID_SPACING- cube->getXPos());

            break;



        }
    }
}