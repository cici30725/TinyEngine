#include "Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>


Shader::Shader()
{

}


Shader::~Shader()
{
}

void Shader::Init(const std::string& filepath) {
	// Parse shader
	ShaderProgramSource source = ParseShader(filepath);

	// Compile shader
	CompileShader(source.vertexShader, source.fragmentShader);
}

void Shader::CompileShader(const std::string& vertexPath, const std::string& fragPath) {
	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const GLchar* vertexSource = vertexPath.c_str();
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// fragment shader
	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar* fragSource = fragPath.c_str();
	glShaderSource(fragmentShader, 1, &fragSource, NULL);
	glCompileShader(fragmentShader);
	// check for shader compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// link shaders
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Shader::ShaderProgramSource Shader::ParseShader(const std::string& filepath) {
	std::ifstream file(filepath);

	enum class ShaderType {
		NONE = -1,
		VERTEX = 0,
		FRAGMENT = 1
	};

	std::string line;
	ShaderType type = ShaderType::NONE;
	std::stringstream ss[2];

	while (getline(file, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX;
			if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT;
		}
		else {
			if ((int)type == -1)
				std::cout << "error";
			ss[(int)type] << line << '\n';
		}
	}

	return { ss[0].str(), ss[1].str() };
}


void Shader::SetUniform2f(float x, float y, const char* name) {
	GLint location = glGetUniformLocation(shaderProgram, name);
	glUseProgram(shaderProgram);
	glUniform2f(location, x, y);
}

void Shader::SetUniform1i(int x, const char* name) {
	GLint location = glGetUniformLocation(shaderProgram, name);
	glUseProgram(shaderProgram);
	glUniform1i(location, x);
}
