#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define SCREEN_WIDTH 640*2
#define SCREEN_HEIGHT 480*2
#define WAIT_TIME 5

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void DrawCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength, int counter);
void DrawStaticCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength);
void drawGrid(int a, int b, float gridSpacing);
void drawMatrix(int a, int b, GLfloat centerXPos, GLfloat centerYPos, GLfloat centerZPos, GLfloat edge);
void drawLongPiece(GLfloat xPos, GLfloat yPos, GLfloat zPos, GLfloat cubeSideLength, int rotation);
void drawT(GLfloat xPos, GLfloat yPos, GLfloat zPos, GLfloat cubeSideLength, int rotation);

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;
float  counter = 600.0;
int a = 6, b = 4;
float gridSpacing = 100.0;
GLfloat xCube = (SCREEN_WIDTH - gridSpacing) / 2;
GLfloat zCube = -500 - gridSpacing / 2;

int main(void)
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);
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

    GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
    GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;

    
    // Variables to create periodic event for FPS displaying
    double prevTime = 0.0;
    double crntTime = 0.0;
    double timeDiff;
    int counter2 = 0;
    float yCube = halfScreenHeight+((a -1)* gridSpacing) * 0.5;

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        counter2 += 1;
        // Updates counter and times
        
        crntTime = glfwGetTime();
        timeDiff = crntTime - prevTime;
        //std::cout << timeDiff;
        counter2++;

        if (timeDiff > 3 and yCube>halfScreenHeight-(a-1)*gridSpacing*0.5) {
            yCube -= 100;
            prevTime = crntTime;
            std::cout << timeDiff;
        }
            

          glClear(GL_COLOR_BUFFER_BIT);
          glPushMatrix();
          glTranslatef(halfScreenWidth, halfScreenHeight, -500);
          glRotatef(rotationX, 1, 0, 0);
          glRotatef(rotationY, 0, 1, 0);
          glTranslatef(-halfScreenWidth, -halfScreenHeight, 500);
          //DrawStaticCube(xCube, yCube, zCube, 100);

          drawGrid(a, b, gridSpacing);
          
          /*if (counter2 > 74037)
              yCube = halfScreenHeight + ((a - 1) * gridSpacing) * 0.5 - gridSpacing * 5;*/

          //DrawCube(xCube, yCube, zCube, 100, counter2);
          //drawMatrix(a, b, xCube, yCube, zCube, 100);
          //drawLongPiece(xCube, yCube, zCube, 100, 2);
          drawT(xCube, yCube, zCube, 100, 3);

          glPopMatrix();

          // Swap front and back buffers
          glfwSwapBuffers(window);

          // Poll for and process events
          glfwPollEvents();
          //yCube -= gridSpacing;*/
    }

    glfwTerminate();
    std::cout << counter2 << std::endl;

    return 0;
}



/*void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    //std::cout << key << std::endl;

    const GLfloat rotationSpeed = 10;

    // actions are GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        switch (key)
        {
        case GLFW_KEY_UP:
            rotationX -= rotationSpeed;
            break;
        case GLFW_KEY_DOWN:
            rotationX += rotationSpeed;
            break;
        case GLFW_KEY_RIGHT:
            rotationY += rotationSpeed;
            break;
        case GLFW_KEY_LEFT:
            rotationY -= rotationSpeed;
            break;
        }


    }
}*/

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    //std::cout << key << std::endl;

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
        case GLFW_KEY_UP:
            if (-500-((b - 1) * gridSpacing * 0.5) < zCube) {
                zCube -= gridSpacing;
            }
                break;
        case GLFW_KEY_DOWN:
            if (zCube <-500+ (b-1) * gridSpacing * 0.5)
                zCube += gridSpacing;
            break;
        case GLFW_KEY_RIGHT:
            if ( xCube < (SCREEN_WIDTH+(b-1) * gridSpacing) * 0.5)
                xCube += gridSpacing;
            break;
        case GLFW_KEY_LEFT:
            if ((SCREEN_WIDTH * 0.5) - (b - 1) * gridSpacing * 0.5 * 0.5 < xCube )
                xCube -= gridSpacing;
            break;
        }


    }
}


void DrawCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength, int counter2)
{
    GLfloat halfSideLength = edgeLength * 0.5f;
    
    
        

    GLfloat vertices[] =
    {
        // front face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // bottom right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // bottom left

        // back face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom left

        // left face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top left
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // bottom left

        // right face
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // bottom left

        // top face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top left
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top right
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // bottom right
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // bottom left

        // top face
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // top left
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength  // bottom left
    };

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f( 1, 1, 1 );
    if (counter2 <= 74037) {
        counter = counter - 0.03;
        glTranslated(0.0, counter, 0);
    }
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glDrawArrays(GL_QUADS, 0, 24);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void DrawStaticCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength)
{
    GLfloat halfSideLength = edgeLength * 0.5f;




    GLfloat vertices[] =
    {
        // front face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // bottom right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // bottom left

        // back face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom left

        // left face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top left
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // bottom left

        // right face
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // bottom left

        // top face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // top left
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // top right
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, // bottom right
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, // bottom left

        // top face
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, // top left
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, // bottom right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength  // bottom left
    };

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1, 1, 1);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glDrawArrays(GL_QUADS, 0, 24);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void drawGrid(int a, int b, float gridSpacing) {
    glPushMatrix();
    glTranslatef(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, -500); // Center the grid and adjust the depth

    //float gridSpacing = 100.0f;

    // Draw horizontal grid lines
    for (int i = -a / 2; i <= a / 2; ++i) {
        float yPos = i * gridSpacing;
        glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        glLineWidth(1);
        glVertex3f(-b * gridSpacing / 2, yPos, -(b * gridSpacing) * 0.5);
        glVertex3f(b * gridSpacing / 2, yPos, -(b * gridSpacing) * 0.5);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(1, 0, 0);
        glLineWidth(1);
        glVertex3f(-(b * gridSpacing) * 0.5, yPos, -b * gridSpacing / 2);
        glVertex3f(-(b * gridSpacing) * 0.5, yPos, b * gridSpacing / 2);
        glEnd();
        
    }

    // Draw vertical grid lines
    for (int i = -b / 2; i <= b / 2; ++i) {
        float xPos = i * gridSpacing;
        glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        glLineWidth(1);
        glVertex3f(xPos, -a * gridSpacing / 2, -(b * gridSpacing) * 0.5);
        glVertex3f(xPos, a * gridSpacing / 2, -(b * gridSpacing) * 0.5);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(1, 0, 0);
        glLineWidth(1);
        glVertex3f(-(b * gridSpacing)*0.5, -a * gridSpacing / 2, xPos);
        glVertex3f(-(b * gridSpacing) * 0.5, a * gridSpacing / 2, xPos);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0, 0, 1);
        glLineWidth(1);
        glVertex3f(xPos, -(a * gridSpacing) * 0.5, -b * gridSpacing / 2);
        glVertex3f(xPos, -(a * gridSpacing) * 0.5, b * gridSpacing / 2);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0, 0, 1);
        glLineWidth(1);
        glVertex3f(-b * gridSpacing / 2, -(a * gridSpacing) * 0.5, xPos);
        glVertex3f(b * gridSpacing / 2, -(a * gridSpacing) * 0.5, xPos);
        glEnd();
    }

    glPopMatrix();
}

void drawMatrix(int a, int b, GLfloat centerXPos, GLfloat centerYPos, GLfloat centerZPos, GLfloat edge) {
    for (int i = 0; i < b; ++i)
    {
        for (int j = 0; j < b; ++j)
        {
            for (int k = 0; k < a; ++k)
            {
                GLfloat cubeCenterX = centerXPos + (j - (b - 1) / 2.0f) * edge;
                GLfloat cubeCenterY = centerYPos + (k - (b - 1) / 2.0f) * edge;
                GLfloat cubeCenterZ = centerZPos - (i * edge);

                DrawStaticCube(cubeCenterX, cubeCenterY, cubeCenterZ, edge);
            }
        }
    }
}

void drawLongPiece(GLfloat xPos, GLfloat yPos, GLfloat zPos, GLfloat cubeSideLength, int rotation) {
    if (rotation == 0) {
        for (int i = -2; i < 2; i++) {
            DrawStaticCube(xPos + i * cubeSideLength, yPos, zPos, cubeSideLength);
        }
    }
    else
        if (rotation==1)
            for (int i = -2; i < 2; i++) {
                DrawStaticCube(xPos, yPos + i * cubeSideLength, zPos, cubeSideLength);
            }
        else
            for (int i = -2; i < 2; i++) {
                DrawStaticCube(xPos, yPos, zPos + i * cubeSideLength, cubeSideLength);
            }


}

void drawT(GLfloat xPos, GLfloat yPos, GLfloat zPos, GLfloat cubeSideLength, int rotation) {
    switch (rotation)
    {
    case 0:
        for (int i = -1; i < 2; i++) {
            DrawStaticCube(xPos + i * cubeSideLength, yPos, zPos, cubeSideLength);
        }
        DrawStaticCube(xPos, yPos-cubeSideLength, zPos, cubeSideLength);
        break;
    case 1:
        for (int i = -1; i < 2; i++) {
            DrawStaticCube(xPos + i * cubeSideLength, yPos, zPos, cubeSideLength);
        }
        DrawStaticCube(xPos, yPos + cubeSideLength, zPos, cubeSideLength);
        break;
    case 2:
        for (int i = -1; i < 2; i++) {
            DrawStaticCube(xPos, yPos, zPos + i * cubeSideLength, cubeSideLength);
        }
        DrawStaticCube(xPos + cubeSideLength, yPos, zPos, cubeSideLength);
        break;
    case 3:
        for (int i = -1; i < 2; i++) {
            DrawStaticCube(xPos, yPos, zPos + i * cubeSideLength, cubeSideLength);
        }
        DrawStaticCube(xPos - cubeSideLength, yPos, zPos, cubeSideLength);
        break;

    }
}




    





