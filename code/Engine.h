#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Particle.h"
using namespace sf;
using namespace std;

class Engine
{
private:
	// A regular RenderWindow
	RenderWindow m_Window;

	//vector for Particles
	vector<Particle> m_particles;

	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();

	// Texture, sprite, and music
	Font m_font;
	Text m_text;
	Texture m_texture;
	Sprite m_sprite;
	Music m_music;

public:
	// The Engine constructor
	Engine();

	// Run will call all the private functions
	void run();

};