#include<SFML/Graphics.hpp>
#include<iostream>
#include<Windows.h>


int main()
{
	int i = 1;
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Escape by daylight");

	////// Circle
	//sf::CircleShape collision(100.f);
	//collision.setPosition({ 200.f, 200.f });
	//collision.setFillColor(sf::Color::Red);

	////// Texture
	sf::Texture playerTexture;
	sf::Texture playerTexture2;
	sf::Texture Enermy;
	sf::Texture Backgound;//แบกกลาวจอกลาง
	sf::Texture Backgound1;//แบกกลาวหลุดจอขวา
	sf::Texture Backgound0;//แบกกลาวหลุดจอซ้าย
	
	if (!Backgound.loadFromFile("C:/Users/เคโรโระ/Downloads/jpg2png/backgound.jpg"))
	{
		std::cout << "Load failed" << std::endl;
	}
	if (!Backgound1.loadFromFile("C:/Users/เคโรโระ/Downloads/jpg2png/backgound.jpg"))
	{
		std::cout << "Load failed" << std::endl;
	}
	if (!Backgound0.loadFromFile("C:/Users/เคโรโระ/Downloads/jpg2png/backgound.jpg"))
	{
		std::cout << "Load failed" << std::endl;
	}
	
	if (!playerTexture.loadFromFile("C:/Users/เคโรโระ/Downloads/assets/assets/player/man.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	
	if (!Enermy.loadFromFile("C:/Users/เคโรโระ/Downloads/DarkSaber/DarkSaber/walk/darksabers3.png"))
	{
		std::cout << "Load failed" << std::endl;
	}


	////// Sprite
	sf::Sprite shapeSprite;
	sf::Sprite shapeSprite2;
	sf::Sprite shapeSprite1;
	sf::Sprite bg;
	sf::Sprite bg1;
	sf::Sprite bg0;
	bg0.setTexture(Backgound0);
	bg.setTexture(Backgound);
	bg1.setTexture(Backgound1);
	shapeSprite.setTexture(playerTexture);	
	shapeSprite1.setTexture(Enermy);
	
	
	int spriteSizeX = playerTexture.getSize().x / 8;
	int spriteSizeY = playerTexture.getSize().y / 4;

	int sprite1SizeX = Enermy.getSize().x / 14.99;
	int sprite1SizeY = Enermy.getSize().y / 1;

	//int sprite0SizeX = Backgound.getSize().x / 1;
	//int sprite0SizeY = Backgound.getSize().y / 1;

	
	bg.setTextureRect(sf::IntRect(0, 0, 1080, 720));
	bg1.setTextureRect(sf::IntRect(0, 0, 1080, 720));
	bg0.setTextureRect(sf::IntRect(0, 0, 1080, 720));
	shapeSprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
	//shapeSprite2.setTextureRect(sf::IntRect(0, 0, sprite2SizeX, sprite2SizeY));
	shapeSprite1.setTextureRect(sf::IntRect(0, 0, sprite1SizeX, sprite1SizeY));

	
	sf::Vector2f spawn2Point = { 600.f, 510.f }; //จุดสปอนตัวเอก
	sf::Vector2f spawnPoint = { 0.f, 200.f }; //จุดสปอนศัตรู
	sf::Vector2f OffPoint = { 600.f, 200.f };
	shapeSprite1.setPosition(spawnPoint);
	shapeSprite.setPosition(spawn2Point);
	bg1.setPosition(1080.f,0.f);
	bg0.setPosition(-1080.f, 0.f);
	//shapeSprite2.setPosition(spawn2Point);

	int animationFrame = 0;
	int animationFrame1 = 0;
	int animationFrame2 = 0;

	while (window.isOpen())
	{
		window.draw(bg);
		window.draw(bg1);
		window.draw(bg0);
		window.draw(shapeSprite);
		window.draw(shapeSprite1);
		
		window.display();
		
		
		Sleep(60);
		shapeSprite1.move(1.0f, 0.f);
		shapeSprite1.setTextureRect(sf::IntRect(sprite1SizeX * animationFrame1, sprite1SizeY * 0, sprite1SizeX, sprite1SizeY));
		
		


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			shapeSprite.move(15.1f, 0.f);
			if (shapeSprite.getPosition().y) { printf("555"); }
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
			bg.move(-2.0f, 0.f);
			bg.setTextureRect(sf::IntRect(1080 * animationFrame2, 720 *0 , 1080, 720));
			bg1.move(-2.0f, 0.f);
			bg1.setTextureRect(sf::IntRect(1080 * animationFrame2, 720 * 0, 1080, 720));
			bg0.move(-2.0f, 0.f);
			bg0.setTextureRect(sf::IntRect(1080 * animationFrame2, 720 * 0, 1080, 720));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			
			shapeSprite.move(-15.1f, 0.f);			
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
			bg.move(2.0f, 0.f);
			bg.setTextureRect(sf::IntRect(1080 * animationFrame2, 720 * 0, 1080, 720));
			bg1.move(2.0f, 0.f);
			bg1.setTextureRect(sf::IntRect(1080 * animationFrame2, 720 * 0, 1080, 720));
			bg0.move(2.0f, 0.f);
			bg0.setTextureRect(sf::IntRect(1080 * animationFrame2, 720 * 0, 1080, 720));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			
			shapeSprite.move(0.f, -15.1f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			
			shapeSprite.move(0.f, 15.1f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
		}
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		animationFrame++;
		animationFrame1++;
		animationFrame2++;
		
	

		if (animationFrame >= 6) {
			animationFrame = 0;
		}
		if (animationFrame1 >= 15) {
			animationFrame1 = 0;
		}
		if (animationFrame2 >= 1) {	
			animationFrame2 = 0;	
			
		}
		if (shapeSprite1.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {
			shapeSprite1.setPosition(spawnPoint);
		//	Sleep(120);
		}
		window.clear();
	}
	return 0;
}