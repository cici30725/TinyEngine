#include "pch.h"
#include "Shader.h"
#include <gtc/type_ptr.hpp>


Shader::Shader(const std::string& filepath)
{
	// Parse shader
	ShaderProgramSource source = ParseShader(filepath);

	// Compile shader
	CompileShader(source.vertexShader, source.fragmentShader);
}


Shader::~Shader()
{
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
		std::string info = infoLog;
		ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" + info);
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
		std::string info = infoLog;
		ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" + info);
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
		std::string info = infoLog;
		ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" + info);
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

void Shader::SetUniformMat4f(glm::mat4& matrix, const char* name) {
	GLint location = glGetUniformLocation(shaderProgram, name);
	glUseProgram(shaderProgram);
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}