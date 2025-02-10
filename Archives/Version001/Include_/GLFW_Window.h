#pragma once
#include<iostream>
#include<GLFW/glfw3.h>

class GLFW_Window {

public:

	GLFW_Window(int width_init, int height_init, const char* title_init);
	~GLFW_Window();

	bool Initsalize();
	void GLFW_PollEvents();
	bool windowShouldClose();
	void changeBuffers();
private:
	int width;
	int heigth;
	const char* title;
	GLFWwindow* Window;
};
