#include<iostream>
#include"../Include_/config.h"
#include"../Include_/OpenGL_Context.h"
#include"../Include_/GLFW_Window.h"

using namespace std;

int main() {
	OpenGL_Context Obj;

	GLFW_Window GLFW_Window(900, 800, "UI");

	if (!GLFW_Window.Initsalize()) {
		return -1;
	}

	OpenGL_Context renderer;
	renderer.initialize();
	renderer.glMainContext();

	while (!GLFW_Window.windowShouldClose()) {
		renderer.renderBUffer(); // 	glClear(GL_COLOR_BUFFER_BIT); // it clears the buffer of the current Color saved within
		GLFW_Window.changeBuffers(); // main background color in glfw window class
		GLFW_Window.GLFW_PollEvents(); // pool events
	}

	renderer.glProgramDeletion();

	return 0;
}

