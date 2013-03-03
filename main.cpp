#include <iostream>
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
using namespace std;
int main(){
	// Window settings
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	sf::RenderWindow App(sf::VideoMode(900,600,32), "Text", sf::Style::Default, settings);
	App.setFramerateLimit(60);
	// Initiate our wonderfully original sprite from image and all other necessary variables
	sf::Texture marioText;
	if(!marioText.loadFromFile("marioSprites.png"))return EXIT_FAILURE;
	sf::Sprite mario(marioText);
	int spritePos[2] = {500,500};
	bool isMoving=false;
	bool isJumping=false;
	int yUp=0;
	const int GRAVITY = 10;
	const int VELOCITY = 20;
	const int LAG  = 90;
	sf::Clock timer;
	// Create rectangle
	sf::IntRect r1(5,170,33,35);
	int rectPos[2] = {5,170};
	// Initiate inspirational message
	sf::Font font;
	if (!font.loadFromFile("fonts/arial.ttf"))
		return EXIT_FAILURE;
	sf::Text text("Look, an error!",font);
	text.setPosition(500,0);
	// Application Loop
	bool running = true;
	while(running){
		// Clear screen & buffer 
		glClearColor(.0f,.0f,.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Check for events and respond appropriately
		sf::Event event;
		while(App.pollEvent(event)){
			if(event.type==sf::Event::Closed){
				running=false;
			}	
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				running=false;
			}
		}	
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && timer.getElapsedTime().asMilliseconds()>=LAG){
			text.setString("Right");
			if(rectPos[1]!=170){
				rectPos[0]=-28;
				spritePos[0]-=VELOCITY;
			}
			rectPos[1]=170;
			rectPos[0]+=33;
			spritePos[0]+=VELOCITY;
			isMoving=true;
			timer.restart();
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && timer.getElapsedTime().asMilliseconds()>=LAG){
			text.setString("LEFT!");
			if(rectPos[1]!=99){
				rectPos[0]=-28;
				spritePos[0]+=VELOCITY;
			}
			rectPos[1]=99;
			rectPos[0]+=33;
			spritePos[0]-=VELOCITY;
			isMoving=true;
			timer.restart();
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isJumping==false){
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			text.setString("DOWN!");
		} else if(timer.getElapsedTime().asMilliseconds()>=LAG){
			isMoving=false;
		}
		if(isMoving==false){
			rectPos[0]=5;
		}
		if(rectPos[0]>=136)rectPos[0]=5;
		r1 = {rectPos[0],rectPos[1],33,35};
		mario.setPosition(spritePos[0],spritePos[1]);
		mario.setTextureRect(r1);
		App.draw(mario);
		App.draw(text);
		App.display();
	}
	return EXIT_SUCCESS;
}
