#pragma once
#include<SFML/Graphics.hpp>
#define MAX_ITEMS 3
class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow& window);
	void moveup();
	void movedown();
	int Getpresseditem() { return selecteditem; }

private:
	int selecteditem = 0;
	sf::Font font;
	sf::Text menu[MAX_ITEMS];


};

