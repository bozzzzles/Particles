#include "Menu.h"

Menu::Menu(float w, float h) {
    if (!font.loadFromFile("arial.ttf")) {
        cout << "Error loading text from file" << endl;
    }

}