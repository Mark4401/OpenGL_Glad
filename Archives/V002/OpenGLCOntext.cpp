#include "../include/OpenGLCOntext.h"
#include"../include/TriangleRender.h"

TriangleRender TriangleData;

void OpenGLCOntext::InitializeGL()
{
	if (!gladLoadGL(glfwGetProcAddress)) {
		
		cerr << "Glad loader failed to Initialize!\n\n";
		glfwTerminate();
	}
}

void OpenGLCOntext::GL_Buffer()
{
	glClearColor(0.35f, 0.45f, 0.75f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	TriangleData.LoadPositionData();
	TriangleData.LoadMeshData();
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void OpenGLCOntext::CleanUp()
{
	TriangleData.ShaderCleanUp();

	cout << "Triangle Data Deleted and Shader Program Terminated\n\n";
}

