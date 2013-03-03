#include <iostream>
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "sprite.h"
using namespace std;
xSprite::xSprite(string Texture, bool Controllable, int Speed, int Lag, int PosX, int PosY){
	// Initialize sprite with variables
	controllable = Controllable;
	speed = Speed;
	lag = Lag;
	position[0]=PosX;
	position[1]=PosY;
	texture.loadFromFile(Texture);
	sprite.setTexture(texture);
}

void move(int right; int left;){
	if (controllable==true){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && timer.getElapsedTime().asMilliseconds()>=lag){
			if rectVars[1]!=right{
				//////////////
				// FIX HERE //
				//////////////
				rectVars[0]=rectVars[3];
			}
		}
	}
}

void xSprite::setRect(int PosX, int PosY, int Width, int Height, int DistanceX, int DistanceY){
	// Set needed information for texture rectangle
	rectVars[0]=PosX;
	rectVars[1]=PosY;
	rectVars[2]=Width;
	rectVars[3]=Height;
	rectDist[0]=DistanceX;
	rectDist[1]=DistanceY;
	rectStart[0]=PosX;
	rectStart[1]=PosY;
}

void xSprite::setPosition(int x, int y){
	position[0]=x;
	position[1]=y;
}

void xSprite::draw(sf::RenderWindow *App){
	textureRect={rectVars[0],rectVars[1],rectVars[2],rectVars[3]};
	sprite.setPosition(position[0],position[1]);
	sprite.setTextureRect(textureRect);
	App->draw(sprite);
}

void xSprite::setSpeed(int Speed){
	speed = Speed;
}

void xSprite::setLag(int Lag){
	lag = Lag;
}

