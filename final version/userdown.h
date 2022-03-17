#include "LTexture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include<iostream>
using namespace std;
#ifndef USER_H
#define USER_H
class userdown
{
	friend class DeathObstacle;
	friend ostream& operator<<(ostream& output, const userdown &r);
public:
	//The dimensions of the dot
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	//Maximum axis velocity of the dot
	static const int DOT_VEL = 5;
	//Initializes the variables
	userdown(int x,int y);
	~userdown();
	//Takes key presses and adjusts the dot's velocity
	void handleEventOne(SDL_Event& e);
	void handleEventTwo(SDL_Event& e);
	SDL_Rect* animatemove();
	SDL_Rect* animateattack1();
	SDL_Rect* animateattack2();
	SDL_Rect* animateup();
	SDL_Rect* animatedown();
	SDL_Rect* animatedoge1();
	SDL_Rect* animatedoge2();
	void move();
	void reset();
	bool death(userdown& rival);
	void gamereset(int x);
	//Shows the dot on the screen
	void render(SDL_Rect * clip, SDL_RendererFlip flip);
	 int getposition() const;  int movetype();
	 bool checkwin() const;

private:
	//The X and Y offsets of the dot
	int mPosX,mPosY;
	

	//The velocity of the dot
	int mVelX,mVelY;
	int frame=0;
	bool AUP = false, ADOWN = false , ATTACK = false;
	bool dodge1 = false; bool dodge2 = false;
	
	 int AttackControll1 = 0; int AttackControll2 = 0;
	int UpControll = 0; int DodgeControll = 0; bool AttackEnd = true; int DownControll = 0;  int DodgeControll2 = 0;
	bool win = false;
};
#endif