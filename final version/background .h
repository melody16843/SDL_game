#include "LTexture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#ifndef MENU_H
#define MENU_H
class background
{
public:
	//The dimensions of the dot
	static const int MENU_WIDTH = 20;
	static const int MENU_HEIGHT = 20;

	//Maximum axis velocity of the dot
	LTexture picture;

	//Initializes the variables
	background():mPosX(0),mPosY(0){}
	background(int x,int y) :mPosX(x), mPosY(y) {}
	~background();

	//Takes key presses 
	int mouseEvent(SDL_Event& e);
	int mouseEvent2(SDL_Event& e);
	int mouseEvent3(SDL_Event& e);
	int mouseEvent4(SDL_Event& e);
	int mouseEventINTRO(SDL_Event& e);
	int mouseEventgameover(SDL_Event& e);
	int keyboardEvent(SDL_Event& e);
	void bling(int frame);
	void dosetvalue(int x, int y);

	void operator!();

	protected:

	int mPosX, mPosY;

	
};
#endif