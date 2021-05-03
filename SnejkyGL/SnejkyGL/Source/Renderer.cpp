#include "../Renderer.h"

using namespace std;

Renderer::Renderer() {
	Vector2* vector2 = new Vector2();

	setBackground(0, 0.5, 0.5, 0);
}

void Renderer::clearScreen() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(GLclampf(background[0]),
		GLclampf(background[1]),
		GLclampf(background[2]),
		GLclampf(background[3]));
}

void Renderer::drawTriangle(GLfloat vertices[], GLfloat color[]) {
	glEnableClientState(GL_VERTEX_ARRAY); 
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices); 
	glColorPointer(3, GL_FLOAT, 0, color);
	glDrawArrays(GL_TRIANGLES, 0, 3); 
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY); 
}

void Renderer::drawLine(GLfloat vertices[], GLfloat color[], int width) {
	glEnable(GL_LINE_SMOOTH);
	glEnableClientState(GL_COLOR_ARRAY);
	//glEnable(GL_LINE_STIPPLE); //carkovana
	glPushAttrib(GL_LINE_BIT);
	glLineWidth(width);
	//glLineStipple(1, 0x00FF);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glColorPointer(3, GL_FLOAT, 0, color);
	glDrawArrays(GL_LINES, 0, 2);
	glDisableClientState(GL_VERTEX_ARRAY);
	glPopAttrib();
	//glDisable(GL_LINE_STIPPLE);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisable(GL_LINE_SMOOTH);
}

void Renderer::setBackground(float r, float g, float b, float a) {
	background[0] = r;
	background[1] = g;
	background[2] = b;
	background[3] = a;
}
