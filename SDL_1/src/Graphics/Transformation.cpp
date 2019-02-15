#include "pch.h"
#include "Transformation.h"


Transformation::Transformation()
{
}


Transformation::~Transformation()
{
}

void Transformation::SetTraslation(float x, float y, float z) {
	m_Translation = glm::translate(m_Translation, glm::vec3(x, y, z));
}

void Transformation::SetRotation(float degree, float x, float y, float z) {
	m_Rotation = glm::rotate(m_Rotation, glm::radians(degree), glm::vec3(x, y, z));
}

void Transformation::SetScale(float x, float y, float z) {
	m_Scale = glm::scale(m_Scale, glm::vec3(x, y, z));
}

glm::mat4 Transformation::GetModelMatrix() {
	m_ModelMatrix = m_Translation * m_Rotation * m_Scale;
	return m_ModelMatrix;
}
