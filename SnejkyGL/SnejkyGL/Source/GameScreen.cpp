#include "../GameScreen.h"

GameScreen::GameScreen() {
	camera = new Camera(0, 0, 0);
	camera->centerOfScreen[0] = 0;
	camera->centerOfScreen[1] = 0;
}

void GameScreen::update() {
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->update();
	}
}

void GameScreen::input(UINT* uMsg) {
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->input(uMsg);
	}
}

void GameScreen::draw(Renderer* renderer) {
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->draw(renderer, camera);
	}
}

void GameScreen::addGameObject(Object* object) {
	objects.push_back(object);
}

void GameScreen::removeGameObject(Object* object) {
	objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
}

void GameScreen::setCamera(int width, int heigth) {
	camera->centerOfScreen[0] = width / 2;
	camera->centerOfScreen[1] = heigth / 2;
}