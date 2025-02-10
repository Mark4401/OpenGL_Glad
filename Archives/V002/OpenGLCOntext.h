#pragma once
#include"../include/Config.h"

class OpenGLCOntext {

private: 
	GLuint shaderProgram;

public:
	void InitializeGL();
	void GL_Buffer();
	void CleanUp();
};