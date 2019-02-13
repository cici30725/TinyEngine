#pragma once
#include "Entity.h"
#include <vector>

class Renderer
{
public:
	Renderer();
	~Renderer();
	void Render();
	void addEntity(Entity*);
private:
	std::vector<Entity*> entityList;
};

