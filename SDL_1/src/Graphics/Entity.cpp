#include "Entity.h"



Entity::Entity()
{
	m_Mesh = new Mesh();
	m_Mesh->Init();
	m_Texture = new Texture("res/image/container.jpg");
}


Entity::~Entity()
{
}

void Entity::Render() {
	//m_Texture->Bind(0);
	m_Mesh->Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
