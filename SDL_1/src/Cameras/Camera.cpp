#include "pch.h"
#include "Camera.h"


Camera::Camera(glm::vec3 CameraPos, glm::vec3 TargetPos, float fov)
	:m_CameraPos(CameraPos)
	,m_TargetPos(TargetPos)
	,m_FovDegree(fov)
	,Observer()
{
}


Camera::~Camera()
{
}

glm::mat4& Camera::GetViewMatrix() {
	m_ViewMatrix = glm::lookAt(m_CameraPos, m_CameraPos + m_TargetPos, m_WorldUp);
	return m_ViewMatrix;
}
