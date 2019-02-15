#include "pch.h"
#include "CameraFPS.h"


CameraFPS::CameraFPS(glm::vec3 CameraPos, glm::vec3 TargetPos, float fov)
	:Camera(CameraPos, TargetPos, fov)
{
}


CameraFPS::~CameraFPS()
{
}

void CameraFPS::OnKeyUpdate(KeyPressedEvent* event) {
	switch (event->GetKeyCode()) {
	case SDLK_w:
		m_CameraPos += m_CameraSpeed * m_TargetPos;
		break;
	case SDLK_s:
		m_CameraPos -= m_CameraSpeed * m_TargetPos;
		break;
	case SDLK_a:
		m_CameraPos -= glm::normalize(glm::cross(m_TargetPos, m_WorldUp)) * m_CameraSpeed;
		break;
	case SDLK_d:
		m_CameraPos += glm::normalize(glm::cross(m_TargetPos, m_WorldUp)) * m_CameraSpeed;
		break;
	}
}

void CameraFPS::OnNotify(Event* event) {
	EventTypes type = event->GetEventType();
	if (type == KeyPressedEvent::GetStaticType()) {
		OnKeyUpdate((KeyPressedEvent*)event);
	}
}
