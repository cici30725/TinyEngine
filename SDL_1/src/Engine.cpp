#include "pch.h"
#include "Engine.h"
#include "Terrain/Terrain.h"


Engine::Engine(const int ScreenWidth, const int ScreenHeight)
	:m_Window(ScreenWidth, ScreenHeight)
	,renderer(ScreenWidth, ScreenHeight)
	,m_Timer()
	,m_InputHandle(&(renderer.GetCamera()))
{

}


Engine::~Engine()
{
}


void Engine::Start() {
	SDL_Event event;
	bool quit = false;

	SDL_SetRelativeMouseMode(SDL_TRUE);

	// Pre game loop user definitions
	OnUserCreate();

	// Init Timer
	m_Timer.Init();

	// WireFrame mode
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!quit) {

		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
				quit = true;
			else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
				quit = true;
			else {
				// Pass event to input handle
				m_InputHandle.HandleEvent(event);
			}
				
		
		}

		// render
		//glUseProgram(shader.GetProgram());
		renderer.Render(m_Timer.GetElapsedTime());


		// Update Screen
		SDL_GL_SwapWindow(&m_Window.GetWindow());
	};

	Close();
}

void Engine::OnUserCreate() {
	m_InputHandle.addObserver(EventTypes::KeyPressedEvent, &(renderer.GetCamera()));
	m_InputHandle.addObserver(EventTypes::MouseMovementEvent, &(renderer.GetCamera()));

	//Terrain t("res/heightmap/heightmap.png");

	// Create Shader
	//shader.Init("res/shader/shader.shader");
	renderer.Init();

	// Create Renderer and add objects
	renderer.addEntity(new Entity("res/model/source/scene.fbx"));
}


void Engine::Close() {
	SDL_DestroyWindow(&m_Window.GetWindow());
	SDL_Quit();
}
