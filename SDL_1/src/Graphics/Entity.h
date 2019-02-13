#pragma once
#include "Mesh.h"
#include "Texture.h"

class Entity
{
public:
	Entity();
	~Entity();
	void Render();
private:
	Mesh* m_Mesh = 0;
	Texture* m_Texture = 0;
};

