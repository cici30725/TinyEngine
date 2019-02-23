#include "pch.h"
#include "SDL.h"
#include "Engine.h"

int main(int argc, char *argv[]) {
	Engine demo(1280, 800);
	demo.Start();
	return 0;
}