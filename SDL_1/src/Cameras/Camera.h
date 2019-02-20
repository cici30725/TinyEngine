#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Inputs/Observer.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

class Camera : public Observer
{
public:
	~Camera();
	enum class CameraMovement {
		KEY_W, KEY_A, KEY_S, KEY_D
	};
	virtual void OnKeyUpdate(KeyPressedEvent&& event) = 0;
	virtual void OnMouseMovementUpdate(MouseMovementEvent&& event) = 0;
	glm::mat4& GetViewMatrix();
	inline float GetFOV() const { return m_FovDegree; }
protected:
	Camera(glm::vec3 CameraPos, glm::vec3 TargetPos, float m_FovDegree);
	glm::mat4 m_ViewMatrix = glm::mat4(1.0f);
	glm::vec3 m_WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 m_CameraPos;
	glm::vec3 m_TargetPos;
	float m_CameraSpeed = 0.05f;
	float m_FovDegree;
};

