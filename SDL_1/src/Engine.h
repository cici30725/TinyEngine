#pragma once
#include "Window.h"
#include "SDL.h"
#include "glad/glad.h"
#include "Graphics/Renderer.h"
#include "Graphics/Shader.h"
#include "Cameras/Camera.h"
#include "Timer.h"
#include "Inputs/InputHandle.h"


class Engine
{
public:
	Engine(const int ScreenWidth , const int ScreemHeight);
	~Engine();
	void Start();
private:
	Window m_Window;
	Renderer renderer;
	Timer m_Timer;
	InputHandle m_InputHandle;
private:
	void Close();
	void OnUserCreate();
};

