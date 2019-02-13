#include "SDL.h"
#include "Engine.h"
#include <iostream>

int main(int argc, char *argv[]) {
	Engine demo;
	demo.ConstructWindow();
	demo.Start();
	return 0;
}