#include "pch.h"
#include "Input.h"
#include "SDL.h"

bool Input::IsKeyPressed(int key) {
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[key])
		return true;
	else
		return false;
}

bool Input::IsMouseButtonPressed(int button) {
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(button))
		return true;
	else
		return false;
}