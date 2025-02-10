#pragma once
#include<iostream>
#include<glad/gl.h>
#include<GLFW/glfw3.h>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

class ShaderContext {
private:
    GLuint VAO, VBO;

public:

    ShaderContext();
    ~ShaderContext();

    void InitBuffer(); // Setup buffer
    void Cleanup();     // Deletes buffers and shaders
};