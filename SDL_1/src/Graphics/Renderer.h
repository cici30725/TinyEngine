#pragma once
#include "Entity.h"
#include "Shader.h"
#include "Cameras/CameraFPS.h"
#include <vector>
#include <memory>

class Renderer
{
public:
	Renderer(const int ScreenWidth, const int ScreenHeight);
	~Renderer();
	void Render(float fElaspsedTime);
	void addEntity(Entity*);
	void Init();
	inline Camera& GetCamera() const { return *m_CameraFPS; }
private:
	std::vector<Entity*> entityList;
	Shader m_Shader;
	std::unique_ptr<Camera> m_CameraFPS;
	int m_ScreenWidth;
	int m_ScreenHeight;
	glm::mat4 m_Projection;
private:	
	void OnEntityUpdate(Entity&, glm::mat4&);

};

