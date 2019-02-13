#pragma once
#include "glad/glad.h"
#include <string>

class Shader
{
public:
	Shader();
	~Shader();
	void Init(const std::string& filepath);
	const GLuint& GetProgram() { return shaderProgram; }

public:
	void SetUniform2f(float, float, const char*);
	void SetUniform1i(int, const char*);

private:
	GLuint shaderProgram = NULL;
	struct ShaderProgramSource {
		std::string vertexShader, fragmentShader;
	};

	struct ShaderProgramSource ParseShader(const std::string& filepath);
	void CompileShader(const std::string& , const std::string&);
};

