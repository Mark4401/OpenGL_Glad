#pragma once
#include<iostream>
#include<glad/gl.h>
#include<GLFW/glfw3.h>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

class OpenGL_Context {

public:

	unsigned int shader;

	void initialize();
	void glMainContext();
	void renderBUffer();
	void glProgramDeletion();
};