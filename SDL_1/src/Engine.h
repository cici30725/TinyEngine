#pragma once
#include "Window.h"
#include "SDL.h"
#include "glad/glad.h"
#include "Graphics/Renderer.h"
#include "Graphics/Shader.h"

class Engine
{
public:
	Engine();
	~Engine();
	void ConstructWindow(int ScreenWidth = 640, int ScreenHeight = 480);
	void Start();
private:
	Window* m_Window = NULL;
	SDL_GLContext gContext = NULL;
	Renderer renderer;
	Shader shader;
private:
	bool Init();
	void Close();
	void OnUserCreate();
};

