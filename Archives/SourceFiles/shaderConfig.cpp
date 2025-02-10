#include"../Include_/shaderConfig.h"

unsigned int shaderConfig::make_Shader(const string& vertex_filePath, const string& freagment_filePath)
{
	vector<unsigned int> module;

	module.push_back(make_module(vertex_filePath, GL_VERTEX_SHADER));
	module.push_back(make_module(freagment_filePath, GL_FRAGMENT_SHADER));

	unsigned int shader = glCreateProgram();

	for (unsigned int shaderModule : module) {
		glAttachShader(shader, shaderModule);
	}

	glLinkProgram(shader);

	int success;
	glGetProgramiv(shader, GL_LINK_STATUS, &success);

	if (!success) {
		char errorLog[1024];
		glGetProgramInfoLog(shader, 1024, NULL, errorLog);
		cout << "Shader linking Error: " << errorLog << endl;
	}

	for (unsigned int shaderModule : module) {
		glDeleteShader(shaderModule);
	}

	return shader;
}

unsigned int shaderConfig::make_module(const string& filepath, unsigned int module_type)
{
	ifstream file;
	stringstream bufferedLines;
	string line;

	file.open(filepath);
	while (getline(file, line)) {
		bufferedLines << line << "\n";
	}

	string shaderSource = bufferedLines.str();
	const char* shaderSrc = shaderSource.c_str();

	bufferedLines.str("");
	file.close();

	unsigned int shaderModude = glCreateShader(module_type);
	glShaderSource(shaderModude, 1, &shaderSrc, NULL);
	glCompileShader(shaderModude);

	int success;
	glGetShaderiv(shaderModude, GL_COMPILE_STATUS, &success);

	if (!success) {
		char errorLog[1024];
		glGetShaderInfoLog(shaderModude, 1024, NULL, errorLog);
		cout << "Shader module compile Error: " << errorLog << endl;
	}
	return shaderModude;
}

void shaderConfig::shaderTextLoader()
{
	ifstream file;
	string line;

	// how to load an file:

	file.open("../Src/Shaders/Vertix.txt");
	while (getline(file, line)) {
		cout << line << endl;
	}
	cout << "\n\n";
}
