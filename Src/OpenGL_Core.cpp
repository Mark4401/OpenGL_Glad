#include"../Headers/OpenGL_Core.h"

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

static unsigned int ShaderLoader() {

	unsigned int VertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(VertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(VertexShader);

	unsigned int FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(FragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(FragmentShader);

	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, VertexShader);
	glAttachShader(shaderProgram, FragmentShader);

	// Wrap-up/Link all the shaders together into the Shader Program
	glLinkProgram(shaderProgram);

	// Delete the now useless Vertex and Fragment Shader objects
	glDeleteShader(VertexShader);
	glDeleteShader(FragmentShader);

	return shaderProgram;
}

static float vertices[] = {

		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
};

unsigned int VAO, VBO;

static void ShaderMesh() {

	// Generate the VAO and VBO with only 1 object each
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	// Make the VAO the current Vertex Array Object by binding it
	glBindVertexArray(VAO);

	// Bind the VBO specifying it's a GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// Introduce the vertices into the VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Configure the Vertex Attribute so that OpenGL knows how to read the VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// Enable the Vertex Attribute so that OpenGL knows to use it
	glEnableVertexAttribArray(0);

	// Bind both the VBO and VAO to 0 so that we don't accidentally modify the VAO and VBO we created
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	return glBindVertexArray(VAO);
}

void Gl_Core::Start()
{
	if (!gladLoadGL(glfwGetProcAddress)) {

		cerr << "Glad failed to Initialize!\n\n";
		glfwTerminate();
	}
	else {
		cout << "Glad Initialize!\n\n";
	}
}



void Gl_Core::GL_Buffer()
{
	glClearColor(0.35f, 0.45f, 0.75f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Triangle Data
	ShaderMesh();
	glUseProgram(ShaderLoader());
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

Gl_Core::Gl_Core()
{
}

Gl_Core::~Gl_Core()
{
	// Delete all the objects we've created
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(ShaderLoader());
}
