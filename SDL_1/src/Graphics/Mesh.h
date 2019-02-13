#pragma once
#include "glad/glad.h"

class Mesh
{
public:
	Mesh();
	~Mesh();
	void Init();
	void Bind();
private:
	float vertices[12] = {
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};
	unsigned int indices[6] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

	float texture_coor[8] = {
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f
	};
	
	GLuint VBO, VAO, EBO;
	GLuint TexVBO;

};

