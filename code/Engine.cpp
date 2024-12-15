#include "Engine.h"

Engine::Engine()
{
    // Get display values to be used with window
    VideoMode vm(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height);

    // Create a Completed run() from Engine.cpp and open a window for the game
    m_Window.create(vm, "Particles", Style::Default);
}

void Engine::run()
{
    // Construct a local clock to track time per frame
    Clock localClock;
    Time dt;
    // Construct a local Particle to be used for the unit tests
    cout << "Starting Particle unit tests..." << endl;
    Particle p(m_Window, 4, {(int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2});
    p.unitTests();
    cout << "Unit tests complete.  Starting engine..." << endl;
    //  Create game loop
    while (m_Window.isOpen())
    {
        dt = localClock.restart();
        input();
        update(dt.asSeconds());
        draw();
    }
}

void Engine::input()
{
}
void Engine::update(float dtAsSeconds)
{
}
void Engine::draw()
{
}