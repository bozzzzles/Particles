#include "Engine.h"

Engine::Engine()
{
    // Get display values to be used with window
    VideoMode vm(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height);
    srand(time(0));
    // Create a Completed run() from Engine.cpp and open a window for the game
    m_Window.create(vm, "Particles", Style::Default);

    // Load font
    if (!m_font.loadFromFile("Blazed.ttf")) {
        cerr << "Error loading font!" << endl;
        exit(1);
    }
    // Set text
    m_text.setFont(m_font);
    m_text.setString("PARTICLES (AWESOME)");
    m_text.setCharacterSize(40);
    m_text.setFillColor(Color::White);
    m_text.setPosition(VideoMode::getDesktopMode().width / 2 , VideoMode::getDesktopMode().height * (7 / 8));

    // Load texture
    if (!m_texture.loadFromFile("awesomeTruck.png")) {
        cerr << "Error loading sprite texture!" << endl;
        exit(1);
    }

    // Set up sprite
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(VideoMode::getDesktopMode().width / 2 , VideoMode::getDesktopMode().height / 2);

    // Load and set up music
    if (!m_music.openFromFile("danger-zone-official-video---top-gun.wav")) {
        cerr << "Error loading music!" << endl;
        exit(1);
    }
    m_music.setLoop(true);
    m_music.play();
}

void Engine::run()
{
    // Construct a local clock to track time per frame
    Clock localClock;
    Time dt;
    // Construct 
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

// Controls how user interacts with game to create particles
void Engine::input()
{
    Event event;
    while (m_Window.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            m_Window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            m_Window.close();
        }
        if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == Mouse::Left)
            {
                for (int i = 0; i < 5; i++)
                {
                    Vector2i mousePixel(event.mouseButton.x, event.mouseButton.y);
                    Particle p(m_Window, (rand() % 26) + 25, mousePixel);
                    m_particles.push_back(p);
                }
            }
        }
    }
       
}

// Checks which particles should still exist and removes them from vector once TTL expires
void Engine::update(float dtAsSeconds)
{
    for (auto it = m_particles.begin(); it != m_particles.end();)
    {
        if (it->getTTL() > 0.0)
        {
            it->update(dtAsSeconds);
            it++;
        }
        else
        {
            it = m_particles.erase(it);
        }
    }
}

// Loops through each particle in vector to be drawn in window
void Engine::draw()
{
    m_Window.clear();
    for (Particle p : m_particles)
    {
        m_Window.draw(p);
    }
    m_Window.display();
}