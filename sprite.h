#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
using namespace std;
class xSprite{
public:
	// Get Values
	int getTime(){return timer.getElapsedTime().asMilliseconds();};
	int getSpeed(){return speed;};
	// Set Values
	void move();
	void draw(sf::RenderWindow *App);
	xSprite(string Sprite, bool Controllable, int Speed, int Lag, int PosX, int PosY);
	void setSpeed(int Speed);
	void setLag(int Lag);
	void restartTime(){timer.restart();};
	void setPosition(int x, int y);
	void setRect(int PosX, int PosY, int Width, int Height, int DistanceX, int DistanceY);
private:
	int speed;
	int lag;
	bool isMoving;
	bool controllable;
	int position[2];
	int health;
	int rectVars[4];
	int rectDist[2];
	int rectStart[2];
	sf::Sprite sprite;
	sf::Texture texture;
	sf::IntRect textureRect;
	sf::Clock timer;
};
#endif
