#pragma once
#include "Camera.h"
class CameraFPS : public Camera
{
public:
	CameraFPS(glm::vec3 CameraPos, glm::vec3 TargetPos, float fov);
	~CameraFPS();
	void OnKeyUpdate(KeyPressedEvent* event) override;
	virtual void OnNotify(Event* event);
};

