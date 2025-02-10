#pragma once
#include"../include/Config.h"

class Glfw_Manager {

private:

	int width;
	int height;
	const char* title;
	GLFWwindow* Window;
	GLFWmonitor* monitor;
	GLFWwindow* share;

	// int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share

public:

	Glfw_Manager(int width_init, int height_init, const char* title_init, GLFWmonitor* monitor_init, GLFWwindow* share_init);
	~Glfw_Manager();

	bool glfwStart();
	bool WindowStart();
	void GLFW_PollEvents();
	bool windowShouldClose();
	void BudderStack();
};