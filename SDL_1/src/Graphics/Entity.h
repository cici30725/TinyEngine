#pragma once
#include "Mesh.h"
#include "Texture.h"
#include "Transformation.h"

class Entity
{
public:
	Entity();
	~Entity();
	void Render();
	inline glm::mat4 GetModelMatrix() { return m_Transformation->GetModelMatrix(); }
private:
	Mesh* m_Mesh = 0;
	Texture* m_Texture = 0;
	Transformation* m_Transformation = 0;
};

