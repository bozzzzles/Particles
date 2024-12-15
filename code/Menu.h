#pragma once
#include "SFML/Graphics.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;
#define MAX_ITEMS 3

class Menu {
  public:
    Menu(float width, float height);
    ~Menu();

    void draw(RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() {return selectedItemIndex;}
  private:
    int selectedItemIndex;
    Font font;
    Text menu[MAX_ITEMS];
};