#include "Engine.h"

Engine::Engine() {
    int pixelWidth = VideoMode::getDesktopMode().width;
	int pixelHeight = VideoMode::getDesktopMode().height;
	VideoMode vm(pixelWidth, pixelHeight);

	// Create and open a window for the game
	RenderWindow window(vm, "Particles", Style::Default);
}
