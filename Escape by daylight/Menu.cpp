#include "Menu.h"
Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Begok v15_2015___free.ttf"))
	{
		//handle error
	}
	menu[0].setFont(font);
	menu[0].setCharacterSize(56);
	menu[0].setFillColor(sf::Color::Green);
	menu[0].setString("new game");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setCharacterSize(46);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("hall of frame");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("exit game");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 3));

}
Menu::~Menu()
{

}
void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}
void Menu::moveup()
{
	if (selecteditem - 1 >= 0)
	{
		menu[selecteditem].setFillColor(sf::Color::White);
		selecteditem--;
		menu[selecteditem].setFillColor(sf::Color::Green);
	}
}
void Menu::movedown()
{
	if (selecteditem + 1 < MAX_ITEMS)
	{
		menu[selecteditem].setFillColor(sf::Color::White);
		selecteditem++;
		menu[selecteditem].setFillColor(sf::Color::Green);
	}
}