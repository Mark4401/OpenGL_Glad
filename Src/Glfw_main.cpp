#include"../Headers/Glfw_main.h"

GLFWwindow* Window;

bool Appication::Start()
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

	return true;
}

bool Appication::MainWindow()
{
	Window = glfwCreateWindow(1400, 1000, "UI", NULL, NULL);

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

void Appication::PoolEvents()
{
	glfwPollEvents();
}

bool Appication::WindowShouldClose()
{
	return glfwWindowShouldClose(Window);
}

void Appication::Buffer()
{
	// Main Window Buffer
	glfwSwapBuffers(Window);
}

Appication::Appication()
{

}

Appication::~Appication()
{
	if (Window) {
		glfwDestroyWindow(Window);
		cout << "Window Destroyed Correctly!\n\n";
	}
	glfwTerminate();
	cout << "GLFW Terminated Correctly!\n\n";
}

