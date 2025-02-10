#include"../Headers/config.h"
#include"../Headers/Glfw_main.h"
#include"../Headers/OpenGL_Core.h"

Gl_Core Render;

Appication App;

int main(int argc, char* argv[]) {

	if (!App.Start()) {
		return -1;
	}

	App.MainWindow();
	Render.Start();

	while (!App.WindowShouldClose()) {

		// OpenGL Buffer
		Render.GL_Buffer();
		App.Buffer();
		App.PoolEvents();
	}

	return 0;
}