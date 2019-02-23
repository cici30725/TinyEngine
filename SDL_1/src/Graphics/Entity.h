#pragma once
#include "Mesh.h"
#include "Transformation.h"
#include <vector>
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Entity
{
public:
	Entity(const std::string& filepath);
	~Entity();
	void Render(Shader& shader);
	inline glm::mat4 GetModelMatrix() { return m_Transformation->GetModelMatrix(); }
private:
	// Functions
	void LoadModel(const std::string& filepath);
	void ProcessNode(aiNode* node, const aiScene* scene);
	Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* material, aiTextureType type, const std::string& typeName);
	GLuint TextureFromFile(const char *path, const std::string& directory);
	// Data
	std::vector<Mesh> vec_Meshes;
	std::vector<Texture> vec_TextureLoaded;
	Texture* m_Texture = 0;
	Transformation* m_Transformation = 0;
	std::string directory;
};

