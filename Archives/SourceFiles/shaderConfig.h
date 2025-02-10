#pragma once
#include<iostream>
#include<glad/gl.h>
#include<GLFW/glfw3.h>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;
class shaderConfig {

public:
	unsigned int make_Shader(const string& vertex_filePath, const string& freagment_filePath);
	unsigned int make_module(const string& filepath, unsigned int module_type);

	void shaderTextLoader();
	void ShaderProgram();
};

