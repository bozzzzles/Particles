#include "Engine.h"

Engine::Engine() {
    int pixelWidth = VideoMode::getDesktopMode().width;
	int pixelHeight = VideoMode::getDesktopMode().height;
	VideoMode vm(pixelWidth, pixelHeight);

	// Create and open a window for the game
	RenderWindow window(vm, "Particles", Style::Default);
}

void Engine::run() {
    Clock localClock;
    Time dt = localClock.getElapsedTime();
    cout << "Starting Particle unit tests..." << endl;
    Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
    p.unitTests();
    cout << "Unit tests complete.  Starting engine..." << endl;
}

void Engine::input() {

}
void Engine::update(float dtAsSeconds) {

}
void Engine::draw() {

}