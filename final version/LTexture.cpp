#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "LTexture.h"
extern SDL_Renderer* gRenderer ;
const int WALKING_ANIMATION_FRAMES = 4;
const int UP_ANIMATION_FRAME = 4;
const int DODGE_ANIMATION_FRAME = 4;
const int DODGE_STYLE = 2;
SDL_Rect gWalkClips[WALKING_ANIMATION_FRAMES];
SDL_Rect gWalkUpClips[WALKING_ANIMATION_FRAMES];
SDL_Rect gWalkDownClips[WALKING_ANIMATION_FRAMES];
SDL_Rect gCutClips[WALKING_ANIMATION_FRAMES][UP_ANIMATION_FRAME];
SDL_Rect gUpClips[WALKING_ANIMATION_FRAMES][UP_ANIMATION_FRAME];
SDL_Rect gCut2Clips[WALKING_ANIMATION_FRAMES][UP_ANIMATION_FRAME];
SDL_Rect gDownClips[WALKING_ANIMATION_FRAMES][UP_ANIMATION_FRAME];
SDL_Rect gDodgeClips[DODGE_STYLE][DODGE_ANIMATION_FRAME];

LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile(std::string path)
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}
void LTexture::free()
{
	//Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	//Modulate texture rgb
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void LTexture::setBlendMode(SDL_BlendMode blending)
{
	//Set blending function
	SDL_SetTextureBlendMode(mTexture, blending);
}

void LTexture::setAlpha(Uint8 alpha)
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}
SDL_Texture* LTexture::GetTexture()
{
	return mTexture;
}
void LTexture::load()
{
	gWalkClips[0].x = 0;
	gWalkClips[0].y = 0;
	gWalkClips[0].w = 210;
	gWalkClips[0].h = 370;

	gWalkClips[1].x = 210;
	gWalkClips[1].y = 0;
	gWalkClips[1].w = 210;
	gWalkClips[1].h = 370;

	gWalkClips[2].x = 420;
	gWalkClips[2].y = 0;
	gWalkClips[2].w = 210;
	gWalkClips[2].h = 370;

	gWalkClips[3].x = 630;
	gWalkClips[3].y = 0;
	gWalkClips[3].w = 210;
	gWalkClips[3].h = 370;
	//Set walkup clips
	gWalkUpClips[0].x = 630;
	gWalkUpClips[0].y = 1850;
	gWalkUpClips[0].w = 210;
	gWalkUpClips[0].h = 370;

	gWalkUpClips[1].x = 630;
	gWalkUpClips[1].y = 2220;
	gWalkUpClips[1].w = 210;
	gWalkUpClips[1].h = 370;

	gWalkUpClips[2].x = 630;
	gWalkUpClips[2].y = 2590;
	gWalkUpClips[2].w = 210;
	gWalkUpClips[2].h = 370;

	gWalkUpClips[3].x = 630;
	gWalkUpClips[3].y = 2960;
	gWalkUpClips[3].w = 210;
	gWalkUpClips[3].h = 370;
	//Set walkdown clips
	gWalkDownClips[0].x = 630;
	gWalkDownClips[0].y = 4810;
	gWalkDownClips[0].w = 210;
	gWalkDownClips[0].h = 370;

	gWalkDownClips[1].x = 630;
	gWalkDownClips[1].y = 5180;
	gWalkDownClips[1].w = 210;
	gWalkDownClips[1].h = 370;

	gWalkDownClips[2].x = 630;
	gWalkDownClips[2].y = 5550;
	gWalkDownClips[2].w = 210;
	gWalkDownClips[2].h = 370;

	gWalkDownClips[3].x = 630;
	gWalkDownClips[3].y = 5920;
	gWalkDownClips[3].w = 210;
	gWalkDownClips[3].h = 370;
	// set cutup1 clip
	gCutClips[0][0].x = 0;
	gCutClips[0][0].y = 370;
	gCutClips[0][0].w = 210;
	gCutClips[0][0].h = 370;

	gCutClips[0][1].x = 210;
	gCutClips[0][1].y = 370;
	gCutClips[0][1].w = 210;
	gCutClips[0][1].h = 370;

	gCutClips[0][2].x = 420;
	gCutClips[0][2].y = 370;
	gCutClips[0][2].w = 210;
	gCutClips[0][2].h = 370;

	gCutClips[0][3].x = 630;
	gCutClips[0][3].y = 370;
	gCutClips[0][3].w = 210;
	gCutClips[0][3].h = 370;
	//Set cutup2 clips
	gCutClips[1][0].x = 0;
	gCutClips[1][0].y = 740;
	gCutClips[1][0].w = 210;
	gCutClips[1][0].h = 370;

	gCutClips[1][1].x = 210;
	gCutClips[1][1].y = 740;
	gCutClips[1][1].w = 210;
	gCutClips[1][1].h = 370;

	gCutClips[1][2].x = 420;
	gCutClips[1][2].y = 740;
	gCutClips[1][2].w = 210;
	gCutClips[1][2].h = 370;

	gCutClips[1][3].x = 630;
	gCutClips[1][3].y = 740;
	gCutClips[1][3].w = 210;
	gCutClips[1][3].h = 370;
	//Set cutup3 clips
	gCutClips[2][0].x = 0;
	gCutClips[2][0].y = 1110;
	gCutClips[2][0].w = 210;
	gCutClips[2][0].h = 370;

	gCutClips[2][1].x = 210;
	gCutClips[2][1].y = 1110;
	gCutClips[2][1].w = 210;
	gCutClips[2][1].h = 370;

	gCutClips[2][2].x = 420;
	gCutClips[2][2].y = 1110;
	gCutClips[2][2].w = 210;
	gCutClips[2][2].h = 370;

	gCutClips[2][3].x = 630;
	gCutClips[2][3].y = 1110;
	gCutClips[2][3].w = 210;
	gCutClips[2][3].h = 370;
	//Set cutup4 clips
	gCutClips[3][0].x = 0;
	gCutClips[3][0].y = 1480;
	gCutClips[3][0].w = 210;
	gCutClips[3][0].h = 370;

	gCutClips[3][1].x = 210;
	gCutClips[3][1].y = 1480;
	gCutClips[3][1].w = 210;
	gCutClips[3][1].h = 370;

	gCutClips[3][2].x = 420;
	gCutClips[3][2].y = 1480;
	gCutClips[3][2].w = 210;
	gCutClips[3][2].h = 370;

	gCutClips[3][3].x = 630;
	gCutClips[3][3].y = 1480;
	gCutClips[3][3].w = 210;
	gCutClips[3][3].h = 370;
	//set up1 clip
	gUpClips[0][0].x = 0;
	gUpClips[0][0].y = 1850;
	gUpClips[0][0].w = 210;
	gUpClips[0][0].h = 370;

	gUpClips[0][1].x = 210;
	gUpClips[0][1].y = 1850;
	gUpClips[0][1].w = 210;
	gUpClips[0][1].h = 370;

	gUpClips[0][2].x = 420;
	gUpClips[0][2].y = 1850;
	gUpClips[0][2].w = 210;
	gUpClips[0][2].h = 370;

	gUpClips[0][3].x = 630;
	gUpClips[0][3].y = 1850;
	gUpClips[0][3].w = 210;
	gUpClips[0][3].h = 370;
	//Set up2 clips
	gUpClips[1][0].x = 0;
	gUpClips[1][0].y = 2220;
	gUpClips[1][0].w = 210;
	gUpClips[1][0].h = 370;

	gUpClips[1][1].x = 210;
	gUpClips[1][1].y = 2220;
	gUpClips[1][1].w = 210;
	gUpClips[1][1].h = 370;

	gUpClips[1][2].x = 414;
	gUpClips[1][2].y = 2220;
	gUpClips[1][2].w = 210;
	gUpClips[1][2].h = 370;

	gUpClips[1][3].x = 630;
	gUpClips[1][3].y = 2220;
	gUpClips[1][3].w = 210;
	gUpClips[1][3].h = 370;
	//Set up3 clips
	gUpClips[2][0].x = 0;
	gUpClips[2][0].y = 2590;
	gUpClips[2][0].w = 210;
	gUpClips[2][0].h = 370;

	gUpClips[2][1].x = 210;
	gUpClips[2][1].y = 2590;
	gUpClips[2][1].w = 210;
	gUpClips[2][1].h = 370;

	gUpClips[2][2].x = 420;
	gUpClips[2][2].y = 2590;
	gUpClips[2][2].w = 210;
	gUpClips[2][2].h = 370;

	gUpClips[2][3].x = 630;
	gUpClips[2][3].y = 2590;
	gUpClips[2][3].w = 210;
	gUpClips[2][3].h = 370;
	//Set up4 clips
	gUpClips[3][0].x = 0;
	gUpClips[3][0].y = 2960;
	gUpClips[3][0].w = 210;
	gUpClips[3][0].h = 370;

	gUpClips[3][1].x = 210;
	gUpClips[3][1].y = 2960;
	gUpClips[3][1].w = 210;
	gUpClips[3][1].h = 370;

	gUpClips[3][2].x = 420;
	gUpClips[3][2].y = 2960;
	gUpClips[3][2].w = 210;
	gUpClips[3][2].h = 370;

	gUpClips[3][3].x = 630;
	gUpClips[3][3].y = 2960;
	gUpClips[3][3].w = 210;
	gUpClips[3][3].h = 370;
	// set cutdown1 clip
	gCut2Clips[0][0].x = 0;
	gCut2Clips[0][0].y = 3330;
	gCut2Clips[0][0].w = 210;
	gCut2Clips[0][0].h = 370;

	gCut2Clips[0][1].x = 210;
	gCut2Clips[0][1].y = 3330;
	gCut2Clips[0][1].w = 210;
	gCut2Clips[0][1].h = 370;

	gCut2Clips[0][2].x = 420;
	gCut2Clips[0][2].y = 3330;
	gCut2Clips[0][2].w = 210;
	gCut2Clips[0][2].h = 370;

	gCut2Clips[0][3].x = 630;
	gCut2Clips[0][3].y = 3330;
	gCut2Clips[0][3].w = 210;
	gCut2Clips[0][3].h = 370;
	//Set cutdown2 clips
	gCut2Clips[1][0].x = 0;
	gCut2Clips[1][0].y = 3700;
	gCut2Clips[1][0].w = 210;
	gCut2Clips[1][0].h = 370;

	gCut2Clips[1][1].x = 210;
	gCut2Clips[1][1].y = 3700;
	gCut2Clips[1][1].w = 210;
	gCut2Clips[1][1].h = 370;

	gCut2Clips[1][2].x = 420;
	gCut2Clips[1][2].y = 3700;
	gCut2Clips[1][2].w = 210;
	gCut2Clips[1][2].h = 370;

	gCut2Clips[1][3].x = 630;
	gCut2Clips[1][3].y = 3700;
	gCut2Clips[1][3].w = 210;
	gCut2Clips[1][3].h = 370;
	//Set cutdown3 clips
	gCut2Clips[2][0].x = 0;
	gCut2Clips[2][0].y = 4070;
	gCut2Clips[2][0].w = 210;
	gCut2Clips[2][0].h = 370;

	gCut2Clips[2][1].x = 210;
	gCut2Clips[2][1].y = 4070;
	gCut2Clips[2][1].w = 210;
	gCut2Clips[2][1].h = 370;

	gCut2Clips[2][2].x = 420;
	gCut2Clips[2][2].y = 4070;
	gCut2Clips[2][2].w = 210;
	gCut2Clips[2][2].h = 370;

	gCut2Clips[2][3].x = 630;
	gCut2Clips[2][3].y = 4070;
	gCut2Clips[2][3].w = 210;
	gCut2Clips[2][3].h = 370;
	//Set cutdown4 clips
	gCut2Clips[3][0].x = 0;
	gCut2Clips[3][0].y = 4440;
	gCut2Clips[3][0].w = 210;
	gCut2Clips[3][0].h = 370;

	gCut2Clips[3][1].x = 210;
	gCut2Clips[3][1].y = 4440;
	gCut2Clips[3][1].w = 210;
	gCut2Clips[3][1].h = 370;

	gCut2Clips[3][2].x = 420;
	gCut2Clips[3][2].y = 4440;
	gCut2Clips[3][2].w = 210;
	gCut2Clips[3][2].h = 370;

	gCut2Clips[3][3].x = 630;
	gCut2Clips[3][3].y = 4440;
	gCut2Clips[3][3].w = 210;
	gCut2Clips[3][3].h = 370;
	//set down1 clip
	gDownClips[0][0].x = 0;
	gDownClips[0][0].y = 4810;
	gDownClips[0][0].w = 210;
	gDownClips[0][0].h = 370;

	gDownClips[0][1].x = 210;
	gDownClips[0][1].y = 4810;
	gDownClips[0][1].w = 210;
	gDownClips[0][1].h = 370;

	gDownClips[0][2].x = 420;
	gDownClips[0][2].y = 4810;
	gDownClips[0][2].w = 210;
	gDownClips[0][2].h = 370;

	gDownClips[0][3].x = 630;
	gDownClips[0][3].y = 4810;
	gDownClips[0][3].w = 210;
	gDownClips[0][3].h = 370;
	//Set down2 clips
	gDownClips[1][0].x = 0;
	gDownClips[1][0].y = 5180;
	gDownClips[1][0].w = 210;
	gDownClips[1][0].h = 370;

	gDownClips[1][1].x = 210;
	gDownClips[1][1].y = 5180;
	gDownClips[1][1].w = 210;
	gDownClips[1][1].h = 370;

	gDownClips[1][2].x = 414;
	gDownClips[1][2].y = 5180;
	gDownClips[1][2].w = 210;
	gDownClips[1][2].h = 370;

	gDownClips[1][3].x = 630;
	gDownClips[1][3].y = 5180;
	gDownClips[1][3].w = 210;
	gDownClips[1][3].h = 370;
	//Set down3 clips
	gDownClips[2][0].x = 0;
	gDownClips[2][0].y = 5550;
	gDownClips[2][0].w = 210;
	gDownClips[2][0].h = 370;

	gDownClips[2][1].x = 210;
	gDownClips[2][1].y = 5550;
	gDownClips[2][1].w = 210;
	gDownClips[2][1].h = 370;

	gDownClips[2][2].x = 420;
	gDownClips[2][2].y = 5550;
	gDownClips[2][2].w = 210;
	gDownClips[2][2].h = 370;

	gDownClips[2][3].x = 630;
	gDownClips[2][3].y = 5550;
	gDownClips[2][3].w = 210;
	gDownClips[2][3].h = 370;
	//Set down4 clips
	gDownClips[3][0].x = 0;
	gDownClips[3][0].y = 5920;
	gDownClips[3][0].w = 210;
	gDownClips[3][0].h = 370;

	gDownClips[3][1].x = 210;
	gDownClips[3][1].y = 5920;
	gDownClips[3][1].w = 210;
	gDownClips[3][1].h = 370;

	gDownClips[3][2].x = 420;
	gDownClips[3][2].y = 5920;
	gDownClips[3][2].w = 210;
	gDownClips[3][2].h = 370;

	gDownClips[3][3].x = 630;
	gDownClips[3][3].y = 5920;
	gDownClips[3][3].w = 210;
	gDownClips[3][3].h = 370;
	// set dodge1 clip
	gDodgeClips[0][0].x = 0;
	gDodgeClips[0][0].y = 6290;
	gDodgeClips[0][0].w = 210;
	gDodgeClips[0][0].h = 370;

	gDodgeClips[0][1].x = 210;
	gDodgeClips[0][1].y = 6290;
	gDodgeClips[0][1].w = 210;
	gDodgeClips[0][1].h = 370;

	gDodgeClips[0][2].x = 420;
	gDodgeClips[0][2].y = 6290;
	gDodgeClips[0][2].w = 210;
	gDodgeClips[0][2].h = 370;

	gDodgeClips[0][3].x = 630;
	gDodgeClips[0][3].y = 6290;
	gDodgeClips[0][3].w = 210;
	gDodgeClips[0][3].h = 370;
	// set dodge2 clip
	gDodgeClips[1][0].x = 0;
	gDodgeClips[1][0].y = 6660;
	gDodgeClips[1][0].w = 210;
	gDodgeClips[1][0].h = 370;

	gDodgeClips[1][1].x = 210;
	gDodgeClips[1][1].y = 6660;
	gDodgeClips[1][1].w = 210;
	gDodgeClips[1][1].h = 370;

	gDodgeClips[1][2].x = 420;
	gDodgeClips[1][2].y = 6660;
	gDodgeClips[1][2].w = 210;
	gDodgeClips[1][2].h = 370;

	gDodgeClips[1][3].x = 630;
	gDodgeClips[1][3].y = 6660;
	gDodgeClips[1][3].w = 210;
	gDodgeClips[1][3].h = 370;
}