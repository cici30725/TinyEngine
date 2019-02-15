#include "pch.h"
#include "Entity.h"



Entity::Entity()
{
	m_Mesh = new Mesh();
	m_Mesh->Init();
	m_Texture = new Texture("res/image/container.jpg");
	m_Transformation = new Transformation();
	m_Transformation->SetRotation(90.0f, 0.0f, 0.0f, 1.0f);
}


Entity::~Entity()
{
}

void Entity::Render() {
	glm::mat4 modelMatrix = m_Transformation->GetModelMatrix();
	//m_Texture->Bind(0);
	m_Mesh->Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
