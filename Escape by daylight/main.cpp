#include<SFML/Graphics.hpp>
#include<iostream>
#include<Windows.h>


int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Escape by daylight");

	////// Circle
	//sf::CircleShape collision(100.f);
	//collision.setPosition({ 200.f, 200.f });
	//collision.setFillColor(sf::Color::Red);

	////// Texture
	sf::Texture playerTexture;
	sf::Texture Enermy;
	sf::Texture Backgound;
	
	if (!Backgound.loadFromFile("C:/Users/‡§‚√‚√–/Downloads/jpg2png/backgound.jpg"))
	{
		std::cout << "Load failed" << std::endl;
	}
	
	if (!playerTexture.loadFromFile("C:/Users/‡§‚√‚√–/Downloads/assets/assets/player/man.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	if (!Enermy.loadFromFile("C:/Users/‡§‚√‚√–/Downloads/DarkSaber/DarkSaber/walk/en1.png"))
	{
		std::cout << "Load failed" << std::endl;
	}


	////// Sprite
	sf::Sprite shapeSprite;
	sf::Sprite shapeSprite1;
	sf::Sprite shapeSprite0;
	shapeSprite0.setTexture(Backgound);
	shapeSprite.setTexture(playerTexture);
	shapeSprite1.setTexture(Enermy);
	shapeSprite0.setTextureRect(sf::IntRect(0, 0, 1080, 720));
	
	int spriteSizeX = playerTexture.getSize().x / 8;
	int spriteSizeY = playerTexture.getSize().y / 4;

	

	shapeSprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
	
	sf::Vector2f spawn2Point = { 0.f, 510.f };
	sf::Vector2f spawnPoint = { 600.f, 300.f };
	shapeSprite1.setPosition(spawnPoint);
	shapeSprite.setPosition(spawn2Point);

	int animationFrame = 0;

	while (window.isOpen())
	{
		window.draw(shapeSprite0);
		window.draw(shapeSprite);
		window.draw(shapeSprite1);
		//window.draw(collision);
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			Sleep(60);
			shapeSprite.move(15.1f, 0.f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
				
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			Sleep(60);
			shapeSprite.move(-15.1f, 0.f);
			
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			Sleep(60);
			shapeSprite.move(0.f, -15.1f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Sleep(60);
			shapeSprite.move(0.f, 15.1f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
		}
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		animationFrame++;
		

		if (animationFrame >= 6) {
			animationFrame = 0;
		}
		if (shapeSprite1.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {
			shapeSprite.setPosition(spawn2Point);
			Sleep(120);
		}
		window.clear();
	}
	return 0;
}