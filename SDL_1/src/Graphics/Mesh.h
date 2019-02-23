#pragma once
#include "glad/glad.h"
#include "glm.hpp"
#include <vector>
#include "Shader.h"


struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TextureCoord;
};

struct Texture {
	GLuint id;
	std::string type;
	std::string path;
};

class Mesh
{
public:
	Mesh(std::vector<Vertex>&& vertices, std::vector<unsigned int>&& indices, std::vector<Texture>&& textures);
	~Mesh();
	void Draw(Shader& shader);
private:
	// Data
	std::vector<Vertex> vec_Verticies;
	std::vector<unsigned int> vec_Indices;
	std::vector<Texture> vec_Textures;
	// * Texture not supported yet
	GLuint VBO, VAO, EBO;
	GLuint TexVBO;

	// Function
	void SetupMesh();

};

