#pragma once
#include "Camera.h"
class CameraFPS : public Camera
{
public:
	CameraFPS(glm::vec3 CameraPos, glm::vec3 TargetPos, float fov);
	~CameraFPS();
	virtual void OnKeyUpdate(KeyPressedEvent&& event) override;
	virtual void OnMouseMovementUpdate(MouseMovementEvent&& event) override;
	virtual void OnNotify(Event& event) override;
private:
	float m_Yaw;
	float m_Pitch;
};

