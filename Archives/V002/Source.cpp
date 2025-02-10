#include"../include/Config.h"
#include"../include/OpenGLCOntext.h"
#include"../include/Glfw_Manager.h"

int main() 
{
	OpenGLCOntext OpenCLCtx;
	
	/*
		- GLFW_Manager Loaded first Before --> OpenGLCOntext OpenCLCtx;

		SO Glfw and Glad Can load the Following Before Processing OppenGL:

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	*/
	
	Glfw_Manager Glfw_Manager(1400, 1000, "UI", NULL, NULL);

	if (!Glfw_Manager.glfwStart()) {
		return -1;
	}


	Glfw_Manager.WindowStart();

	OpenCLCtx.InitializeGL();

	// NOTE! IDK if I need to Load both outside and in the buffer loop or within the While loop Only? 

	while (!Glfw_Manager.windowShouldClose()) {

		OpenCLCtx.GL_Buffer();
		Glfw_Manager.BudderStack();
		Glfw_Manager.GLFW_PollEvents();
	}

	OpenCLCtx.CleanUp();

	return 0;
}
