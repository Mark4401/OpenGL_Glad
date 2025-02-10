
#include"../Include_/GLFW_Window.h"


using namespace std;

GLFW_Window::GLFW_Window(int width_init, int height_init, const char* title_init)
	: width(width_init), heigth(height_init), title(title_init), Window(nullptr) 
{
	Window = glfwCreateWindow(width, heigth, title, NULL, NULL);
}

GLFW_Window::~GLFW_Window()
{
	if (Window) {
		glfwDestroyWindow(Window);
		cout << "Window Destroyed Correctly!\n\n";
	}
	glfwTerminate();
	cout << "GLFW Terminated Correctly!\n\n";

	
}

bool GLFW_Window::Initsalize()
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

void GLFW_Window::GLFW_PollEvents()
{
	glfwPollEvents();
}

bool GLFW_Window::windowShouldClose()
{
	return glfwWindowShouldClose(Window);
}

void GLFW_Window::changeBuffers()
{
	glfwSwapBuffers(Window);
}


