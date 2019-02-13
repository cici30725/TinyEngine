#include "Renderer.h"



Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::addEntity(Entity* entity) {
	entityList.emplace_back(entity);
}

void Renderer::Render() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	for (Entity* entity : entityList) {
		entity->Render();
	}
}
