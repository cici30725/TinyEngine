#pragma once
#include "Mesh.h"
#include "Texture.h"
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
	void Render();
	inline glm::mat4 GetModelMatrix() { return m_Transformation->GetModelMatrix(); }
private:
	// Functions
	void LoadModel(const std::string& filepath);
	void ProcessNode(aiNode* node, const aiScene* scene);
	Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
	// Data
	std::vector<Mesh> vec_Meshes;
	Texture* m_Texture = 0;
	Transformation* m_Transformation = 0;
};

