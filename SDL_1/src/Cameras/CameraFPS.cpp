#include "pch.h"
#include "CameraFPS.h"


CameraFPS::CameraFPS(glm::vec3 CameraPos, glm::vec3 TargetPos, float fov)
	:Camera(CameraPos, TargetPos, fov)
	,m_Yaw(-90.0f)
	,m_Pitch(0.0f)
{
}


CameraFPS::~CameraFPS()
{
}

void CameraFPS::OnKeyUpdate(KeyPressedEvent&& event) {
	switch (event.GetKeyCode()) {
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

void CameraFPS::OnMouseMovementUpdate(MouseMovementEvent&& event) {
	if (Input::IsMouseButtonPressed(SDL_BUTTON_RIGHT)) {
		float xoffset = event.GetMouseXRel();
		float yoffset = event.GetMouseYRel();

		float sensitivity = 0.05;
		xoffset *= sensitivity;
		yoffset *= sensitivity;

		m_Yaw += xoffset;
		m_Pitch += yoffset;

		if (m_Pitch > 89.0f)
			m_Pitch = 89.0f;
		if (m_Pitch < -89.0f)
			m_Pitch = -89.0f;

		glm::vec3 front;
		front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
		front.y = sin(glm::radians(m_Pitch));
		front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
		m_TargetPos = glm::normalize(front);
	}
}

void CameraFPS::OnNotify(Event& event) {
	EventTypes type = event.GetEventType();
	if (type == KeyPressedEvent::GetStaticType()) {
		OnKeyUpdate(dynamic_cast<KeyPressedEvent&&>(event));
	}
	else if (type == MouseMovementEvent::GetStaticType()) {
		OnMouseMovementUpdate(dynamic_cast<MouseMovementEvent&&>(event));
	}
}
