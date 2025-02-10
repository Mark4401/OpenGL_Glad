#include"../Include_/OpenGL_Context.h"
#include"../Include_/ShaderContext.h"


ShaderContext Obj;


unsigned int LoaderPointer() {

	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	//Fragment Shader source code
	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
		"}\n\0";

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vertexShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	// Wrap-up/Link all the shaders together into the Shader Program
	glLinkProgram(shaderProgram);

	// Delete the now useless Vertex and Fragment Shader objects

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return shaderProgram;
}

void OpenGL_Context::initialize()
{
	if (!gladLoadGL(glfwGetProcAddress)) {
		
		cerr << "Glad loader failed to Initialize!\n\n";
		glfwTerminate();
	}
}

void OpenGL_Context::glMainContext()
{
	glClearColor(0.35f, 0.45f, 0.75f, 1.0f); // it clears the color and sets it to back in the RGB rnage
	glClear(GL_COLOR_BUFFER_BIT);

	//unsigned int shad	r = make_Shader(
	//	"../Src/Shaders/vertex.txt",
	//	"../Src/Shaders/fragment.txt"
	//);

	// calling the vertex and fragment files
	
}


void OpenGL_Context::renderBUffer()
{
	glClearColor(0.35f, 0.45f, 0.75f, 1.0f); // it clears the color and sets it to back in the RGB rnage

	glClear(GL_COLOR_BUFFER_BIT); // it clears the buffer of the current Color saved within
	//glUseProgram(shader);
	/*
	We manage this memory via so called vertex buffer objects (VBO)
	that can store a large number of vertices's in the GPU's memory. T
	*/
	glUseProgram(LoaderPointer());
	Obj.InitBuffer();
	glDrawArrays(GL_TRIANGLES, 0, 3);

}

void OpenGL_Context::glProgramDeletion()
{
	Obj.Cleanup();
}

