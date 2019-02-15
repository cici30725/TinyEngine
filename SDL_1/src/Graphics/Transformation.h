#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class Transformation
{
public:
	Transformation();
	~Transformation();
	void SetTraslation(float , float , float);
	void SetRotation(float degree, float, float ,float);
	void SetScale(float, float, float);
	glm::mat4 GetModelMatrix();
private:
	glm::mat4 m_Translation = glm::mat4(1.0f);
	glm::mat4 m_Rotation = glm::mat4(1.0f);
	glm::mat4 m_Scale = glm::mat4(1.0f);
	glm::mat4 m_ModelMatrix = glm::mat4(1.0f);
};

