#include "Menu.h"

Menu::Menu(float w, float h) {
    if (!font.loadFromFile("arial.ttf")) {
        cout << "Error loading text from file" << endl;
    }
    menu[0].setFont(font);
    menu[0].setColor(Color::Red);
    menu[0].setString("Play Particles");
    menu[0].setPosition(Vector2f(w / 2, h / (MAX_ITEMS + 1 * 1)));

    menu[1].setFont(font);
    menu[1].setColor(Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(Vector2f(w / 2, h / (MAX_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(Vector2f(w / 2, h / (MAX_ITEMS + 1) * 3));

    selectedItemIndex = 0;
}

Menu::~Menu() {

}

void Menu::draw(RenderWindow &window) {
    for (int i= 0; i < MAX_ITEMS; i++) {

    }
}

void Menu::MoveUp() {
  if (selectedItemIndex - 1 >= 0) {
    menu[selectedItemIndex].setColor(Color::White);
    selectedItemIndex--;
    menu[selectedItemIndex].setColor(Color::Red);
  }
}

void Menu::MoveDown() {
  if (selectedItemIndex + 1 < MAX_ITEMS) {
    menu[selectedItemIndex].setColor(Color::White);
    selectedItemIndex++ ;
    menu[selectedItemIndex].setColor(Color::Red);
  }
}