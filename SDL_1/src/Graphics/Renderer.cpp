#include "pch.h"
#include "Renderer.h"



Renderer::Renderer(const int ScreenWidth, const int ScreenHeight)
	:m_ScreenWidth(ScreenWidth)
	,m_ScreenHeight(ScreenHeight)
	,m_Shader("res/shader/shader.shader")
	,m_CameraFPS(new CameraFPS(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, -1.0f), 45.0f))
	,m_Projection(glm::perspective(glm::radians(m_CameraFPS->GetFOV()), (float)m_ScreenWidth/(float)m_ScreenHeight, 0.1f, 100.0f))
{
}


Renderer::~Renderer()
{
}

void Renderer::Init() {
	//m_CameraFPS = new CameraFPS(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, -1.0f));
}

void Renderer::addEntity(Entity* entity) {
	entityList.emplace_back(entity);
}

void Renderer::Render(float fElapsedTime) {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glm::mat4 view = m_CameraFPS->GetViewMatrix();
	glm::mat4 PV = m_Projection * view;

	glUseProgram(m_Shader.GetProgram());
	for (Entity* entity : entityList) {
		OnEntityUpdate(*entity, PV);
		entity->Render();
	}
}

void Renderer::OnEntityUpdate(Entity& entity, glm::mat4& PV_Matrix) {
	glm::mat4 modelMatrix = PV_Matrix * entity.GetModelMatrix();
	m_Shader.SetUniformMat4f(modelMatrix, "MVP");
}
