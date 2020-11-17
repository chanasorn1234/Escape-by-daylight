#include<SFML/Graphics.hpp>
#include<iostream>
#include<Windows.h>
#include "Menu.h"
#include<SFML/Audio.hpp>

sf::RenderWindow window(sf::VideoMode(1080, 720), "Escape by daylight");
int main()
{
	int i = 1;
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Escape by daylight");

	
	Menu menu(window.getSize().x, window.getSize().y);
	
	

	////// Texture
	sf::Texture playerTexture;
	sf::Texture playerTexture2;
	sf::Texture Enermy;
	sf::Texture Backgound;//แบกกลาวจอกลาง
	sf::Texture Backgound1;//แบกกลาวหลุดจอขวา
	sf::Texture Backgound0;//แบกกลาวหลุดจอซ้าย
	sf::Texture HPbar;
	sf::Texture bgme;
	
	////sound
	sf::SoundBuffer soundmenu;
	sf::SoundBuffer soundgame;

	if (!soundgame.loadFromFile("TerrorRadius_Qatar.wav"))
	{
		std::cout << "Erorr" << std::endl;
	}
	if (!soundmenu.loadFromFile("Original_Survivor_Theme.wav"))
	{
		std::cout << "Erorr" << std::endl;
	}
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
	if (!HPbar.loadFromFile("C:/Users/เคโรโระ/Downloads/assets/assets/player/HP.jpg"))
	{
		std::cout << "Load failed" << std::endl;
	}
	if (!bgme.loadFromFile("werewolf.jpg"))
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
	sf::Sprite hpbar;
	sf::Sprite bgm;
	bg2.setTexture(Backgound0);
	bg.setTexture(Backgound);
	bg1.setTexture(Backgound1);
	bgm.setTexture(bgme);
	shapeSprite.setTexture(playerTexture);	
	shapeSprite1.setTexture(Enermy);
	shapeSprite2.setTexture(playerTexture2);
	hpbar.setTexture(HPbar);
	
	
	int spriteSizeX = playerTexture.getSize().x / 8;
	int spriteSizeY = playerTexture.getSize().y / 4;

	int sprite1SizeX = Enermy.getSize().x / 14.99;
	int sprite1SizeY = Enermy.getSize().y / 1;

	//int sprite0SizeX = Backgound.getSize().x / 1;
	//int sprite0SizeY = Backgound.getSize().y / 1;
	
	bg.setScale(1.0f,1.0f);
	bg1.setTextureRect(sf::IntRect(0, 0, 1080, 720));
	//bg2.setTextureRect(sf::IntRect(0, 0, 1080, 720));
	bgm.setScale(2.0f, 2.8f);
	//bgm.setTextureRect(sf::IntRect(0, 0, 1080, 720));
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
	hpbar.setPosition(0, 0);

	int myhp = 91800;
	sf::RectangleShape hp(sf::Vector2f(myhp / 250, 40));//เซตขนาดของหลอดเลือด
	hp.setFillColor(sf::Color::Red);//เซตสี
	hp.setPosition(sf::Vector2f(32, 0));//เซตตำแหน่งของหลอด
	


	int animationFrame = 0;
	int animationFrame1 = 0;
	int animationFrame2 = 0;

	bool canJump = true;
	const float gravity = 1;
	float movespeed = 1.0f ,jumpspeed = 15.1f,jumpheight = 50.0f;
	int groundheight = 400 ,j=0;
	sf::Vector2f velocity(sf::Vector2f(0, 0));
	sf::Vector2f s;
	

	sf::View view,view1;
	view.reset(sf::FloatRect(0, 0, 1080, 720));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	
	sf::Vector2f position(0, 0);
	sf::Vector2f position2(0, 0);
	
	sf::FloatRect       fBounds(1080.f, 0.f, 1000.f, 1000.f);
	sf::IntRect         iBounds(fBounds);

	sf::Sound soundmen;
	soundmen.setBuffer(soundmenu);
	soundmen.setVolume(40);
	soundmen.setLoop(true);
	soundmen.play();

	sf::Sound soundgam;
	soundgam.setBuffer(soundgame);
	soundgam.setVolume(40);
	soundgam.setLoop(true);
	

	Game:
		while (window.isOpen())
		{
			
			sf::Event event;
			window.display();
			window.draw(bgm);
			menu.draw(window);
			while (window.pollEvent(event)) {
				switch (event.type)
				{
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
					case sf::Keyboard::Up: 
						menu.moveup();
						break;
					case sf::Keyboard::W:
						menu.moveup();
						break;
					case sf::Keyboard::S:
						menu.movedown();
						break;
					case sf::Keyboard::Down:
						menu.movedown();
						break;
					
					case sf::Keyboard::Return:
						switch (menu.Getpresseditem())
						{
						case 0:
							std::cout << "Play" << std::endl;
							soundmen.stop();
							goto Main;
							break;
						case 1:
							std::cout << "Hall oF Frame" << std::endl;
							break;
						case 2:
							window.close();
							break;
						}
						break;

					}
					break;
				}
				break;
			}
		
		
			//window.clear();
			//break;
		
		}
	

	Main:
		soundgam.play();
		while (window.isOpen())
		{
			window.setView(view);	
			window.draw(bg);
			window.draw(bg1);
			window.draw(hpbar);
			window.draw(hp);
			//window.draw(bg2);
			window.draw(shapeSprite);
			window.draw(shapeSprite1);
			//window.draw(shapeSprite2);
			//window.setView(window.getDefaultView());
			//menu.draw(window);
			window.display();
		
		
			Sleep(60);
			//shapeSprite1.move(1.0f, 0.f);
			shapeSprite1.setTextureRect(sf::IntRect(sprite1SizeX * animationFrame1, sprite1SizeY * 0, sprite1SizeX, sprite1SizeY));
		
		
		
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * 0, spriteSizeY * 0, spriteSizeX, spriteSizeY));
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX* animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{	
				//shapeSprite.move(15.1f, 0.f);
				shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
				if (shapeSprite.getPosition().x < 960)
				{
					shapeSprite.move(15.1f, 0.f);
				}
			

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{	
				//shapeSprite.move(-15.1f, 0.f);			
				shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
				if (shapeSprite.getPosition().x > 140)
				{
					shapeSprite.move(-15.1f, 0.f);
				}
			
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump == true|| sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump == true)
			{	
				j = 8;
				canJump = false;
							
			}	
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{								
				main();				
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
			
				shapeSprite.move(12.0f, 0.f);
				shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * 0, spriteSizeY * 2, spriteSizeX, spriteSizeY));
				myhp -= 1000;
				hp.setSize(sf::Vector2f(myhp / 250, 40));
				if (myhp == -1200)
				{
					main();
				}
				
			}
		

			//เมื่อภาพไม่อยู่ในขนาดกว้าง 1024 ของหน้าจอทางซ้าย ให้ย้ายตำแหน่งไปทางขวา
				if (bg.getPosition().x < -1080)
					bg.setPosition(bg1.getPosition().x + 1080, 0);
				if (bg1.getPosition().x < -1080)
					bg1.setPosition(bg.getPosition().x + 1080, 0);
				//เมื่อภาพไม่อยู่ในขนาดกว้าง 1024 ของหน้าจอทางซ้าย ให้ย้ายตำแหน่งไปทางขวา
				/*if (bg.getPosition().x > 1080) bg.setPosition(-
					bg1.getPosition().x + 1080, 0);
				if (bg1.getPosition().x > 1080) bg1.setPosition(-
					bg.getPosition().x + 1080, 0);*/

				if (bg.getPosition().x > 1080) bg.setPosition(-1080, 0);
				if (bg1.getPosition().x > 1080) bg1.setPosition(-1080, 0);
				//ขยับไปโดย ระยะทาง = ความเร็ว * เวลาที่เปลี่ยนไป
				bg.move(-15.0f, 0.f);
				bg1.move(-15.0f, 0.f);
		
			
			if (canJump == false)
			{
				if (j > 4)
				{
					j--;
					s.y = -(jumpheight);
					shapeSprite.move(s);
					shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * 5, spriteSizeY * 1, spriteSizeX, spriteSizeY));
				
				}
				else if (j <= 4)
				{
					if (j == 0)
					{
						canJump = true;
					
					}
					else
					{
						j--;
						s.y = jumpheight;
						shapeSprite.move(s);
						shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * 5, spriteSizeY * 1, spriteSizeX, spriteSizeY));
					
					
					
					}
				
				}
		
			}
				
			window.clear();
		
		}
		return 0;
	
	
}
