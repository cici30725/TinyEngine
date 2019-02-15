#include "pch.h"
#include "SDL.h"
#include "Engine.h"

int main(int argc, char *argv[]) {
	Engine demo(640, 480);
	demo.Start();
	return 0;
}