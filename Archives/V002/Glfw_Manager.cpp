#include "../include/Glfw_Manager.h"

Glfw_Manager::Glfw_Manager(int width_init, int height_init, const char* title_init, GLFWmonitor* monitor_init, GLFWwindow* share_init)
	: width(width_init), height(height_init), title(title_init), Window(nullptr), monitor(monitor_init), share(share_init)
{
}

Glfw_Manager::~Glfw_Manager()
{
	if (Window) {
		glfwDestroyWindow(Window);
		cout << "Window Destroyed Correctly!\n\n";
	}
	glfwTerminate();
	cout << "GLFW Terminated Correctly!\n\n";
}


bool Glfw_Manager::glfwStart()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if (!glfwInit()) {

		cerr << "GLFW failed to Initialize!\n\n";

		return false;
	}
	else {
		cout << "GLFW initialize Correctly!\n\n";
	}
	
	// Window = glfwCreateWindow(width, height, title, monitor, share);

	return true;
}

bool Glfw_Manager::WindowStart()
{
	Window = glfwCreateWindow(width, height, title, monitor, share);

	if (!Window) {
		cerr << "Failed to create an Window!\n";
		glfwTerminate();
		return false;
	}
	else {
		cout << "Window Creation Successful!\n\n";
	}

	glfwMakeContextCurrent(Window);
	return true;
}


void Glfw_Manager::GLFW_PollEvents()
{
	glfwPollEvents();
}

bool Glfw_Manager::windowShouldClose()
{
	return glfwWindowShouldClose(Window);
}

void Glfw_Manager::BudderStack()
{
	glfwSwapBuffers(Window);
}


