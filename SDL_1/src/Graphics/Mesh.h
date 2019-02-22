#pragma once
#include "glad/glad.h"
#include "glm.hpp"
#include <vector>


struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TextureCoord;
};

class Mesh
{
public:
	Mesh(std::vector<Vertex>&& vertices, std::vector<unsigned int>&& indices);
	~Mesh();
	void Draw();
private:
	// Data
	std::vector<Vertex> vec_Verticies;
	std::vector<unsigned int> vec_Indices;
	// * Texture not supported yet
	GLuint VBO, VAO, EBO;
	GLuint TexVBO;

	// Function
	void SetupMesh();

};

