#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>

#include "SnejkyGL/Engine.h"

#include "SnejkyGL/TestObject.h"
#include "SnejkyGL/Objects/Cube.h"
#include "SnejkyGL/Objects/Pyramid.h"
#include "SnejkyGL/Objects/Plain.h"

#define SCREEN_WIDTH 1280   
#define SCREEN_HEIGHT 720

int main(void)
{
    Engine* engine = new Engine();
    int response = engine->initWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (response != 0) return response;

    TestObject* testObject2 = new TestObject(5, -2, 15);
    testObject2->loadMeshFromJson("SnejkyGL/Meshes/pyramid.json", 2, NULL);
    engine->addGameObject(testObject2);

    /*TestObject* testObject = new TestObject(-5, 2, 15);
    testObject->loadMeshFromJson("SnejkyGL/Meshes/cube.json", 1, NULL);
    engine->addGameObject(testObject);

    float* color = new float[3];
    color[0] = 255;
    color[1] = 0;
    color[2] = 0;
    Cube* cube = new Cube(0, -3, 20, 0.5, color);
    engine->addGameObject(cube);

    Pyramid* pyramid = new Pyramid(0, 0, 20, 1, color);
    engine->addGameObject(pyramid);*/

    Plain* plain = new Plain(-5, -2, 5, 10, 10);
    engine->addGameObject(plain);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(engine->getWindow()))
    {
        //testObject->position[0] -= 0.005;
        testObject2->position[0] -= 0.005;

        engine->update();
        engine->draw();

        engine->render();
    }

    glfwTerminate();

    return 0;
}