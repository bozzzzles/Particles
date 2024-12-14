#include "Engine.h"

Engine::Engine() {
    // Get display values to be used with window
    int pixelWidth = VideoMode::getDesktopMode().width;
	int pixelHeight = VideoMode::getDesktopMode().height;
	VideoMode vm(pixelWidth, pixelHeight);

	// Create aCompleted run() from Engine.cppnd open a window for the game
	RenderWindow window(vm, "Particles", Style::Default);
}

void Engine::run() {
    // Construct a local clock to track time per frame
    Clock localClock;
    Time dt = localClock.getElapsedTime();
    // Construct a local Particle to be used for the unit tests
    cout << "Starting Particle unit tests..." << endl;
    Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
    p.unitTests();
    cout << "Unit tests complete.  Starting engine..." << endl;
    //  Create game loop
    localClock.restart();
    this->input();
    this->update(dt.asSeconds());
    this->draw();
}

void Engine::input() {

}
void Engine::update(float dtAsSeconds) {

}
void Engine::draw() {

}