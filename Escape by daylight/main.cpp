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
	if (!playerTexture2.loadFromFile("C:/Users/เคโรโระ/Downloads/assets/assets/player/man2.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	
	if (!Enermy.loadFromFile("C:/Users/เคโรโระ/Downloads/DarkSaber/DarkSaber/walk/darksabers3.png"))
	{
		std::cout << "Load failed" << std::endl;
	}


	////// Sprite
	sf::Sprite shapeSprite; //ตัวเอก
	sf::Sprite shapeSprite2; // ตัวเอกฟลิป
	sf::Sprite shapeSprite1; //ศัตรู
	sf::Sprite bg;
	sf::Sprite bg1;
	sf::Sprite bg2;
	bg2.setTexture(Backgound0);
	bg.setTexture(Backgound);
	bg1.setTexture(Backgound1);
	shapeSprite.setTexture(playerTexture);	
	shapeSprite1.setTexture(Enermy);
	shapeSprite2.setTexture(playerTexture2);
	
	
	int spriteSizeX = playerTexture.getSize().x / 8;
	int spriteSizeY = playerTexture.getSize().y / 4;

	int sprite1SizeX = Enermy.getSize().x / 14.99;
	int sprite1SizeY = Enermy.getSize().y / 1;

	//int sprite0SizeX = Backgound.getSize().x / 1;
	//int sprite0SizeY = Backgound.getSize().y / 1;

	
	
	bg.setScale(1.0f,1.0f);
	
	bg1.setTextureRect(sf::IntRect(0, 0, 1080, 720));
	bg2.setTextureRect(sf::IntRect(0, 0, 1080, 720));
	shapeSprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
	shapeSprite2.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
	shapeSprite1.setTextureRect(sf::IntRect(0, 0, sprite1SizeX, sprite1SizeY));

	
	sf::Vector2f spawn2Point = { 600.f, 510.f }; //จุดสปอนตัวเอก
	sf::Vector2f spawnPoint = { 0.f, 200.f }; //จุดสปอนศัตรู
	sf::Vector2f OffPoint = { 600.f, 200.f };
	shapeSprite1.setPosition(spawnPoint);
	shapeSprite.setPosition(spawn2Point);
	bg1.setPosition(1080.f,0.f);
	bg2.setPosition(2160.f, 0.f);
	shapeSprite2.setPosition(spawn2Point);

	int animationFrame = 0;
	int animationFrame1 = 0;
	int animationFrame2 = 0;

	bool canJump = true;
	const float gravity = 1;
	float movespeed = 1.0f ,jumpspeed = 15.1f,jumpheight = 50.0f;
	int groundheight = 400 ,j=0;
	//sf::Vector2f velocity(sf::Vector2f(0, 0));
	sf::Vector2f s;
	

	sf::View view,view1;
	view.reset(sf::FloatRect(0, 0, 1080, 720));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	
	

	sf::Vector2f position(0, 0);
	sf::Vector2f position2(0, 0);

	
	
	sf::FloatRect       fBounds(1080.f, 0.f, 1000.f, 1000.f);
	sf::IntRect         iBounds(fBounds);

	while (window.isOpen())
	{
		
		window.setView(view);
		
		window.draw(bg);
		window.draw(bg1);
		window.draw(bg2);
		window.draw(shapeSprite);
		window.draw(shapeSprite1);
		//window.draw(shapeSprite2);
		//window.setView(window.getDefaultView());
		window.display();
		
		
		Sleep(60);
		shapeSprite1.move(1.0f, 0.f);
		shapeSprite1.setTextureRect(sf::IntRect(sprite1SizeX * animationFrame1, sprite1SizeY * 0, sprite1SizeX, sprite1SizeY));
		
		
		
		shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * 0, spriteSizeY * 0, spriteSizeX, spriteSizeY));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{	
			shapeSprite.move(15.1f, 0.f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
			//velocity.x = movespeed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{	
			shapeSprite.move(-15.1f, 0.f);			
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
			//velocity.x = -movespeed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump == true)
		{	
			j = 8;
			canJump = false;	
			
			//shapeSprite.move(velocity.x, velocity.y);
			//shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * 5, spriteSizeY * 1, spriteSizeX, spriteSizeY));
					
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

		//velocity.x = 0;


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
			
			shapeSprite.move(15.0f, 0.f);		
		}

		position.x = shapeSprite.getPosition().x +250 - 1080 ;
		position.y = shapeSprite.getPosition().y +10 - 720 ;

		//bg1.setPosition(fBounds.left, fBounds.top /* - 1000.f + View.getSize().y */ - 0);

		if (position.x < 0 )
		{
			position.x = 0;
		
		}
		if (position.y < 0)
		{
			position.y = 0;
		}
		view.reset(sf::FloatRect(position.x, position.y, 1080, 720));
		if (canJump == false)
		{
			if (j > 4)
			{
				j--;
				s.y = -(jumpheight);
				shapeSprite.move(s);
				shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * 5, spriteSizeY * 1, spriteSizeX, spriteSizeY));
				printf("%d", j);
				printf(" ");
			}
			else if (j <= 4)
			{
				if (j == 0)
				{
					canJump == true;
				}
				else
				{
					j--;
					s.y = jumpheight;
					shapeSprite.move(s);
					shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * 5, spriteSizeY * 1, spriteSizeX, spriteSizeY));
					printf("%d", j);
					printf(" ");

					
				}
				
			}
			
		}
		
	
		
		window.clear();
	}
	return 0;
}
