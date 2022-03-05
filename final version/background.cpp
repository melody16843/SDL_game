#include"background .h"

extern background start;
background::~background()
{
	picture.free();

}

int background::mouseEvent2(SDL_Event& e)
{

	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		//Check if mouse is in button




		if (x >= 750 && x <= 1050 && y >= 0 && y <= 200) {
			return 1;
		}
		if (x >= 750 && x <= 1050 && y >= 250 && y <= 450) {
			return 2;
		}
		if (x >= 750 && x <= 1050 && y >= 500 && y <= 700) {
			return 3;
		}


	}
	else {
		int a, b;
		SDL_GetMouseState(&a, &b);
		if (a >= 750 && a <= 1050 && b >= 0 && b <= 200) {
			return 4;
		}
		if (a >= 750 && a <= 1050 && b >= 250 && b <= 450) {
			return 6;
		}
		if (a >= 750 && a <= 1050 && b >= 500 && b <= 700) {
			return 7;
		}
		else
		{
			return 5;
		}

	}


	//return 0;
}
int background::mouseEvent3(SDL_Event& e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		//Check if mouse is in button
		if (x >= 730 && x <= 900 && y >= 620 && y <= 740) {
			return 1;
		}
		else if (x > 122 && x < 482 && y>266 && y <= 480)
			return 2;
		else if (x > 581 && x < 933 && y>266 && y <= 480)
			return 5;
		else if (x > 1037 && x < 1394 && y>266 && y <= 480)
			return 6;
		else
			return 0;
	}
	else
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		//Check if mouse is in button
		if (x >= 730 && x <= 900 && y >= 620 && y <= 740) {
			return 3;
		}
		else
		{
			return 4;
		}
	}
}
int background::mouseEvent4(SDL_Event& e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		//Check if mouse is in button
		if (x >= 730 && x <= 900 && y >= 620 && y <= 740) {
			return 1;
		}
		else if (x >= 109 && x <= 662 && y >= 339 && y <= 424)
			return 5;
		else if (x >= 759 && x <= 925 && y >= 332 && y <= 450)
			return 6;
		else
		{
			return 0;
		}
	}
	else
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		//Check if mouse is in button
		if (x >= 730 && x <= 900 && y >= 620 && y <= 740) {
			return 3;
		}
		else
		{
			return 4;
		}
	}
}
int background::mouseEventINTRO(SDL_Event& e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		//Check if mouse is in button
		if (x >= 730 && x <= 900 && y >= 620 && y <= 740) {
			return 1;
		}
		else if (x >= 1125 && x <= 1402 && y >= 553 && y <= 728)
			return 2;
		else
		{
			return 0;
		}
	}
	else
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		//Check if mouse is in button
		if (x >= 730 && x <= 900 && y >= 620 && y <= 740) {
			return 3;
		}
		else
		{
			return 4;
		}
	}
}
int background::mouseEventgameover(SDL_Event& e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
		return 1;
	else
		return 0;
}
int background::keyboardEvent(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN/*&&e.key.repeat==0*/)
	{
		switch (e.key.keysym.sym )
		{
		case SDLK_1: return 3;// to start
		}
	}
	return 0;
}
void background::bling(int frame)
{
	//tartTexture.setAlpha(frame);
	start.picture.setAlpha(frame);
}
void background::dosetvalue(int x, int y) {
	mPosX = x;
	mPosY = y;
}

void background::operator!()
{
	picture.render(mPosX, mPosY, NULL);
}
