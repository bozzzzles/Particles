#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;
#define max_items 3

class Menu {
  public:
    Menu(float width, float height);
    ~Menu();

    void draw(RenderWindow &window);
    void MoveUp();
    void MoveDown();
  private:
    int selectedItemIndex;
    Font font;
    Text text[max_items];

};