#include "LTexture.h"
#include"userdown.h"
#include"background .h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

class DeathObstacle: public background
{public:
	DeathObstacle(int x, int y);
	DeathObstacle();
	DeathObstacle(const DeathObstacle& e);
	~DeathObstacle();
	DeathObstacle& operator++();
	DeathObstacle& operator--();
	DeathObstacle& operator=(const DeathObstacle& e);
	bool collision(userdown& user);
	bool collision2(userdown& user);
	bool dropend();
	DeathObstacle operator-(int a);
	
	
private:
	
	int slowdown = 0;	
};

