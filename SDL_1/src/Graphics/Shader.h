#pragma once
#include "glad/glad.h"
#include "glm.hpp"
#include <string>

class Shader
{
public:
	Shader(const std::string& filepath);
	~Shader();
	const GLuint& GetProgram() { return shaderProgram; }

public:
	void SetUniform2f(float, float, const char*);
	void SetUniform1i(int, const char*);
	void SetUniformMat4f(glm::mat4& , const char*);

private:
	GLuint shaderProgram = NULL;
	struct ShaderProgramSource {
		std::string vertexShader, fragmentShader;
	};

	struct ShaderProgramSource ParseShader(const std::string& filepath);
	void CompileShader(const std::string& , const std::string&);
};

