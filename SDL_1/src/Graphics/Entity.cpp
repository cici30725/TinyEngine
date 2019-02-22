#include "pch.h"
#include "Entity.h"



Entity::Entity(const std::string& filepath)
{
	LoadModel(filepath);
	m_Transformation = new Transformation();
	//m_Transformation->SetRotation(90.0f, 0.0f, 0.0f, 1.0f);
}


Entity::~Entity()
{
}

void Entity::LoadModel(const std::string& filepath) {
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(filepath, aiProcess_Triangulate | aiProcess_FlipUVs);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
		return;
	}

	ProcessNode(scene->mRootNode, scene);


}

void Entity::ProcessNode(aiNode* node, const aiScene* scene) {
	for (unsigned int i = 0; i < node->mNumMeshes; i++) {
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		vec_Meshes.emplace_back(std::move(ProcessMesh(mesh, scene)));
	}

	for (unsigned int i = 0; i < node->mNumChildren; i++) {
		ProcessNode(node->mChildren[i], scene);
	}
}

Mesh Entity::ProcessMesh(aiMesh* mesh, const aiScene* scene) {
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
		Vertex v;
		v.Position.x = mesh->mVertices[i].x;
		v.Position.y = mesh->mVertices[i].y;
		v.Position.z = mesh->mVertices[i].z;

		v.Normal.x	 = mesh->mNormals[i].x;
		v.Normal.y	 = mesh->mNormals[i].y;
		v.Normal.z	 = mesh->mNormals[i].z;

		if (mesh->mTextureCoords[0]) {
			v.TextureCoord.x = mesh->mTextureCoords[0][i].x;
			v.TextureCoord.y = mesh->mTextureCoords[0][i].y;
		}
		else
			v.TextureCoord = glm::vec2(0.0f, 0.0f);

		vertices.emplace_back(std::move(v));
	}

	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; j++)
			indices.emplace_back(face.mIndices[j]);
	}

	// *Material not supproted Yet

	return Mesh(std::move(vertices), std::move(indices));
}

void Entity::Render() {
	glm::mat4 modelMatrix = m_Transformation->GetModelMatrix();
	for (auto& mesh : vec_Meshes) {
		mesh.Draw();
	}
}
