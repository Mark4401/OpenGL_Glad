// My implementation attempt

public:
    WindowManager(int w, int h, const char* t);
    ~WindowManager();

	WindowManager::WindowMNG(int w, int h, const char* t)
	: width(w), height(h), tittle(t), Window(nullptr) {}


// Correct implementation
public:
	WindowMNG(int w, int h, const char* t);
	~WindowMNG();

	WindowManager::WindowMNG(int w, int h, const char* t)
	: width(w), height(h), tittle(t), Window(nullptr) {}

whats the difference IDK? 

//////////////////////////////////////////////////////////////////////////////////////////

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

	GLfloat vertices[] = {
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f, -0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
	};

	const int width = 900;
	const int length = 800;

	GLFWwindow* Window;

	if (!glfwInit()) {
		
		cerr << "GLFW failed to Initialize!\n\n";

		return -1;
	}
	else {
		cout << "GLFW initialize Correctly!\n\n";
	}

	Window = glfwCreateWindow(width, length, "UI", NULL, NULL);

	if (!Window) {
		cerr << "Failed to create an Window!\n";
		glfwTerminate();
		return -1;
	}

	// initialize OpenGL Context Window
	glfwMakeContextCurrent(Window);
	
	if (!gladLoadGL(glfwGetProcAddress)) {

		cerr << "Glad loader failed to Initialize!\n\n";

		glfwTerminate();
		
		return -1;
	}

	/************** OPENGL AND GLAD ****************/

	glClearColor(0.35f, 0.45f, 0.75f, 1.0f); // it clears the color and sets it to back in the RGB rnage

	glClear(GL_COLOR_BUFFER_BIT); // it clears the buffer of the current Color saved within

	glfwSwapBuffers(Window);

	/************** OPENGL AND GLAD ****************/
	// main loop:

	while (!glfwWindowShouldClose(Window)) {

		glfwPollEvents();
	}

	/******************************************************/

	glfwTerminate();

	cout << "GLFW Terminated Correctly!\n\n";

	/***********************************************/////////////

	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

	GLfloat vertices[] = {
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f, -0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
	};

	const int width = 900;
	const int length = 800;

	GLFWwindow* Window;

	if (!glfwInit()) {

		cerr << "GLFW failed to Initialize!\n\n";

		return -1;
	}
	else {
		cout << "GLFW initialize Correctly!\n\n";
	}

	Window = glfwCreateWindow(width, length, "UI", NULL, NULL);

	if (!Window) {
		cerr << "Failed to create an Window!\n";
		glfwTerminate();
		return -1;
	}

	// initialize OpenGL Context Window
	glfwMakeContextCurrent(Window);

	if (!gladLoadGL(glfwGetProcAddress)) {

		cerr << "Glad loader failed to Initialize!\n\n";

		glfwTerminate();

		return -1;
	}

	/************** OPENGL AND GLAD ****************/

	glClearColor(0.35f, 0.45f, 0.75f, 1.0f); // it clears the color and sets it to back in the RGB rnage

	glClear(GL_COLOR_BUFFER_BIT); // it clears the buffer of the current Color saved within

	glfwSwapBuffers(Window);

	/************** OPENGL AND GLAD ****************/
	// main loop:

	while (!glfwWindowShouldClose(Window)) {

		glfwPollEvents();
	}

	/******************************************************/

	glfwTerminate();
	cout << "GLFW Terminated Correctly!\n\n";










	//////////////////////////////////////////////////////////////////////////////////////////////////////////

```cpp
// Create Vertex Shader Object and get its reference
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// Attach Vertex Shader source to the Vertex Shader Object
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(vertexShader);

	// Create Fragment Shader Object and get its reference
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// Attach Fragment Shader source to the Fragment Shader Object
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(fragmentShader);

	// Create Shader Program Object and get its reference
	GLuint shaderProgram = glCreateProgram();
	// Attach the Vertex and Fragment Shaders to the Shader Program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	// Wrap-up/Link all the shaders together into the Shader Program
	glLinkProgram(shaderProgram);

	// Delete the now useless Vertex and Fragment Shader objects
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);



	// Vertices coordinates
	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
	};

	// Create reference containers for the Vartex Array Object and the Vertex Buffer Object
	GLuint VAO, VBO;

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



	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		glUseProgram(shaderProgram);
		// Bind the VAO so OpenGL knows to use it
		glBindVertexArray(VAO);
		// Draw the triangle using the GL_TRIANGLES primitive
		glDrawArrays(GL_TRIANGLES, 0, 3);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}

```










