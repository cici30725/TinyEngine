#include "pch.h"
#include "Window.h"
#include "glad/glad.h"
#include "SDL_opengl.h"



Window::Window(int ScreenWidth, int ScreenHeight)
	:m_ScreenWidth(ScreenWidth),m_ScreenHeight(ScreenHeight)
{
	Init();
}


Window::~Window()
{
}

bool Window::Init() {

	Log::Init();


	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::string info = SDL_GetError();
		ERROR("SDL could not be initialized! SDL error : " + info);
		return false;
	}

	// Use OpenGL 4.6 core
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// Create Window
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_ScreenWidth, m_ScreenHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	if (window == NULL) {
		std::string info = SDL_GetError();
		ERROR("Window could not be created! SDL_Error: %s\n" + info);
		return false;
	}

	//Create context
	gContext = SDL_GL_CreateContext(window);
	if (gContext == NULL)
	{
		printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	// Initialize glad
	int version = gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
	if (version == 0)
	{
		std::cout << "Failed to initialize OpenGL context" << std::endl;
		return false;
	}
	return true;
}
