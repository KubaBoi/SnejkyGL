#include "../Engine.h"

using namespace std;

Engine::Engine() {
    renderer = new Renderer();
	gameScreen = new GameScreen();

	running = true;
}

int Engine::initWindow(int width, int height) {
    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(width, height, "Game", NULL, NULL);

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
    glOrtho(0, width, 0, height, 0, 600); // essentially set coordinate system
    glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity(); // same as above comment

    return 0;
}

GLFWwindow* Engine::getWindow() {
    return window;
}

void Engine::update() {
	gameScreen->setCamera(1280, 720);
	gameScreen->update();
}

float r = 0;
bool more = true;

void Engine::draw() {
	/*if (r < 1 && more) r += 0.001;
	else if (r > 0 && !more) r -= 0.001;

	if (r <= 0) more = true;
	if (r >= 1) more = false;
	renderer->setBackground(0, r, r, 0);*/

	renderer->clearScreen();
	gameScreen->draw(renderer);

	// Swap front and back buffers
	glfwSwapBuffers(window);

	// Poll for and process events
	glfwPollEvents();
}

void Engine::addGameObject(Object* object) {
	gameScreen->addGameObject(object);
}

void Engine::removeGameObject(Object* object) {
	gameScreen->removeGameObject(object);
}

