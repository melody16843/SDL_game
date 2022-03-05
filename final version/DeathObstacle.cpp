#include "DeathObstacle.h"
#include<iostream>
extern LTexture gBar1Texture;
extern LTexture gBar2Texture;
extern LTexture gStoneTexture;

DeathObstacle::DeathObstacle(int x, int y) { this->dosetvalue(x, y); }
DeathObstacle::DeathObstacle() { this->dosetvalue(0, 0); }
DeathObstacle::DeathObstacle(const DeathObstacle& e) { mPosX = e.mPosX; mPosY = e.mPosY; }
DeathObstacle::~DeathObstacle(){}
DeathObstacle& DeathObstacle::operator++() {
	if (this->mPosX < 750)
	{
		if (slowdown == 0)
		{
			this->mPosX += 2; slowdown++;
		}
		else if (slowdown == 20)
			slowdown = 0;
		else
			slowdown++;

	}
	else
	{
		if (slowdown == 0)
		{
			this->mPosX -= 2;  slowdown++;
		}
		else if (slowdown == 20)
			slowdown = 0;
		else
			slowdown++;
	}
	  
	return *this;
}
DeathObstacle& DeathObstacle::operator--() {
	this->mPosY += 5;
	return *this;
}
DeathObstacle DeathObstacle::operator-( int a)
{
	DeathObstacle z=*this;
	z.mPosY += a;
	return z;

}
DeathObstacle& DeathObstacle::operator=(const DeathObstacle &e)
{
	mPosX = e.mPosX;
	mPosY = e.mPosY;
	return *this;
}
bool DeathObstacle::collision(userdown& user) {
	bool death = false;
	if (this->mPosX < 750 && user.mPosX+10 >= this->mPosX&&user.mPosX+10<=this->mPosX+10 )
		death = true;
	if (this->mPosX > 750 && user.mPosX + 210 >= this->mPosX&&user.mPosX+210<=this->mPosX+10)
		death = true;
	
	return death;
}
bool DeathObstacle::collision2(userdown& user) {
	bool death = false;
	if (mPosY + 30 > 300 && mPosY+30<600)
	{
		if (user.mPosX + 270 > mPosX +30 && user.mPosX+50 < mPosX)
			death = true;
	}
	return death;
	
}
bool DeathObstacle::dropend() {
	bool dropend = false;
	if (this->mPosY > 800)
	{
		dropend = true;
	}
	return dropend;
}


