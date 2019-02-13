#include "Engine.h"
#include <iostream>

Engine::Engine()
{
}


Engine::~Engine()
{
}

void Engine::ConstructWindow(int ScreenWidth, int ScreenHeight) {
	// Create Window
	m_Window = new Window(ScreenWidth, ScreenHeight);
	m_Window->Init();

	Init();
}

void Engine::Start() {
	SDL_Event eventHandler;
	bool quit = false;

	// Pre game loop user definitions
	OnUserCreate();

	while (!quit) {
		while (SDL_PollEvent(&eventHandler) != 0)
		{
			//User requests quit
			if (eventHandler.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		// render
		glUseProgram(shader.GetProgram());
		renderer.Render();


		// Update Screen
		SDL_GL_SwapWindow(&m_Window->GetWindow());
	};

	Close();
}

void Engine::OnUserCreate() {
	// Create Shader
	shader.Init("res/shader/shader.shader");

	// Create Renderer and add objects
	renderer.addEntity(new Entity());
}

bool Engine::Init() {
	//Create context
	SDL_Window& window = m_Window->GetWindow();
	gContext = SDL_GL_CreateContext(&window);
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


void Engine::Close() {
	SDL_DestroyWindow(&m_Window->GetWindow());
	SDL_Quit();
}
