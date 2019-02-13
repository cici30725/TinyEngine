#pragma once
#include "glad/glad.h"
#include <string>

class Texture
{
public:
	Texture(const std::string& filepath);
	~Texture();
	void Bind(int slot);
private:
	GLuint m_TextureID;
	int m_Width, m_Height, m_nChannels;
};

