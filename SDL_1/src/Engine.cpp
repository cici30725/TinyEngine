#include "pch.h"
#include "Engine.h"


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

	// Pre game loop user definitions
	OnUserCreate();

	// Init Timer
	m_Timer.Init();
	while (!quit) {
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
				quit = true;
			else {
				// Pass event to input handle
				m_InputHandle.HandleEvent(event);
			}
				
			/*switch (event.type) {
			
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_w:
					renderer.GetCamera().update(Camera::CameraMovement::KEY_W, m_Timer.GetElapsedTime());
					break;
				case SDLK_a:
					renderer.GetCamera().update(Camera::CameraMovement::KEY_A, m_Timer.GetElapsedTime());
					break;
				case SDLK_s:
					renderer.GetCamera().update(Camera::CameraMovement::KEY_S, m_Timer.GetElapsedTime());
					break;
				case SDLK_d:
					renderer.GetCamera().update(Camera::CameraMovement::KEY_D, m_Timer.GetElapsedTime());
					break;
			}*/
			
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
	// Create Shader
	//shader.Init("res/shader/shader.shader");
	renderer.Init();

	// Create Renderer and add objects
	renderer.addEntity(new Entity());
}


void Engine::Close() {
	SDL_DestroyWindow(&m_Window.GetWindow());
	SDL_Quit();
}
