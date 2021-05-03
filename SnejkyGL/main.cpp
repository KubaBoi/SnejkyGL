#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>

#include "SnejkyGL/Engine.h"

#include "SnejkyGL/TestObject.h"

#define SCREEN_WIDTH 1280   
#define SCREEN_HEIGHT 720

int main(void)
{
    Engine* engine = new Engine();
    int response = engine->initWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (response != 0) return response;

    TestObject* testObject = new TestObject(10, 0, 10);
    engine->addGameObject(testObject);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(engine->getWindow()))
    {
        testObject->position[0] -= 0.001;
        
        if (testObject->position[2] < 0) {
            engine->gameScreen->camera->forward[2] = -1;
            engine->gameScreen->camera->right[0] = 1;
            engine->gameScreen->camera->S[2] = -1;
        }

        engine->update();
        engine->draw();
    }

    glfwTerminate();

    return 0;
}