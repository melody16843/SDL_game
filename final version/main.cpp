#include "LTexture.h"
#include"background .h"
#include"userdown.h"
#include"DeathObstacle.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include<iostream>
#include<SDL_mixer.h>
#include <stdlib.h> 
#include <time.h> 
using namespace std;
SDL_Window* gWindow = NULL;
int SCREEN_WIDTH = 1500;
int SCREEN_HEIGHT = 800;
 SDL_Renderer* gRenderer= NULL;
 LTexture gUserTexture; //picture of user
 Mix_Music* gMusic_menu = NULL;//music and sound effects
 Mix_Music* gMusic_game = NULL;
 Mix_Chunk* gMusic_attack = NULL;
 Mix_Chunk* gMusic_die = NULL;
 Mix_Chunk* gMusic_drum = NULL;
 Mix_Chunk* gMusic_page = NULL;
 int volume = 64;
 background menu1; background start(460, 650);
 background menu2; background button1(751, 25); background button2(751, 250); background button3(751, 480); background button4(730, 620);
 background menu3; background menu4; background INtroduction; background INtroduction2;
 background background1; background background2; background background3;
 background gameset(400, 200); background p1win(400, 340); background p2win(400, 340);
 DeathObstacle bar1; DeathObstacle bar2(1490, 0); DeathObstacle rock;
 int RockControll = 0;
 enum BackGroundChange
 {
	 MENU_1 = 1,
	 MENU_2 = 2,
	 MENU_3 = 3,
	 MENU_4 = 4,
	 INTRODUCTION = 5,
	 GAMESTART = 10,
	 BACKGROUND_1=11,
	 BACKGROUND_2 = 12,
	 BACKGROUND_3 = 13,
	 GAMEOVER=20,
 };
bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				//Initialize SDL_mixer
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMediauser()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if (!gUserTexture.loadFromFile("game/usermove.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		//Set walk clips
		gUserTexture.load();
	}
	
	
	return success;
}
bool loadMediabackground()
{
	//Loading success flag
	bool success = true;
	//Load backgrounds sheet texture
	if (!menu1.picture.loadFromFile("game/menu.png"))
	{
		printf("Failed to load menu1 texture!\n");
		success = false;
	}
	if (!menu2.picture.loadFromFile("game/menu2.png"))
	{
		printf("Failed to load menu2 texture!\n");
		success = false;
	}
	if (!menu3.picture.loadFromFile("game/menu3.png"))
	{
		printf("Failed to load menu3 texture!\n");
		success = false;
	}
	if (!menu4.picture.loadFromFile("game/menu4.png"))
	{
		printf("Failed to load menu4 texture!\n");
		success = false;
	}
	if (!INtroduction.picture.loadFromFile("game/introduction.png"))
	{
		printf("Failed to load Introduction texture!\n");
		success = false;
	}
	if (!INtroduction2.picture.loadFromFile("game/introduction2.png"))
	{
		printf("Failed to load Introduction2 texture!\n");
		success = false;
	}
	if (!background1.picture.loadFromFile("game/background1.png"))
	{
		printf("Failed to load background1 texture!\n");
		success = false;
	}
	if (!background2.picture.loadFromFile("game/background2.png"))
	{
		printf("Failed to load background1 texture!\n");
		success = false;
	}
	if (!background3.picture.loadFromFile("game/background3.png"))
	{
		printf("Failed to load background1 texture!\n");
		success = false;
	}
	if (!start.picture.loadFromFile("game/start.png"))
	{
		printf("Failed to load start texture!\n");
		success = false;
	}
	if (!button1.picture.loadFromFile("game/button.png"))
	{
		printf("Failed to load Button1 texture!\n");
		success = false;
	}
	if (!button2.picture.loadFromFile("game/button2.png"))
	{
		printf("Failed to load Button2 texture!\n");
		success = false;
	}
	if (!button3.picture.loadFromFile("game/button3.png"))
	{
		printf("Failed to load Button3 texture!\n");
		success = false;
	}
	if (!button4.picture.loadFromFile("game/button4.png"))
	{
		printf("Failed to load Button4 texture!\n");
		success = false;
	}
	if (!bar1.picture.loadFromFile("game/bar.png"))
	{
		printf("Failed to load bar texture!\n");
		success = false;
	}
	if (!bar2.picture.loadFromFile("game/bar.png"))
	{
		printf("Failed to load bar texture!\n");
		success = false;
	}
	if (!rock.picture.loadFromFile("game/rock.png"))
	{
		printf("Failed to load rock texture!\n");
		success = false;
	}
	if (!gameset.picture.loadFromFile("game/gameset.png"))
	{
		printf("Failed to load Button4 texture!\n");
		success = false;
	}
	if (!p1win.picture.loadFromFile("game/1P.png"))
	{
		printf("Failed to load Button4 texture!\n");
		success = false;
	}
	if (!p2win.picture.loadFromFile("game/2P.png"))
	{
		printf("Failed to load Button4 texture!\n");
		success = false;
	}
	


	return success;
}
bool loadMusic()
{
	//Loading success flag
	bool success = true;

	//Load music
	gMusic_menu = Mix_LoadMUS("game/gMusic_menu.wav");
	if (gMusic_menu == NULL)
	{
		printf("Failed to load menu music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	gMusic_game = Mix_LoadMUS("game/gMusic_game.wav");
	if (gMusic_game == NULL)
	{
		printf("Failed to load game music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	gMusic_attack = Mix_LoadWAV("game/gMusic_attack.wav");
	if (gMusic_attack == NULL)
	{
		printf("Failed to load attack music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	gMusic_die = Mix_LoadWAV("game/gMusic_die.wav");
	if (gMusic_die == NULL)
	{
		printf("Failed to load die music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	gMusic_drum = Mix_LoadWAV("game/gMusic_drum.wav");
	if (gMusic_drum == NULL)
	{
		printf("Failed to load drum music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	gMusic_page = Mix_LoadWAV("game/gMusic_page.wav");
	if (gMusic_drum == NULL)
	{
		printf("Failed to load page music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	return success;
}


void close()
{
	

	
	
	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gUserTexture.free();
	gWindow = NULL;
	gRenderer = NULL;
	//free the music
	Mix_FreeMusic(gMusic_menu);
	gMusic_menu = NULL;
	Mix_FreeMusic(gMusic_game);
	gMusic_game = NULL;
	//free the sound effects
	Mix_FreeChunk(gMusic_attack);
	Mix_FreeChunk(gMusic_die);
	gMusic_attack = NULL;
	gMusic_die = NULL;

	//Quit SDL subsystems
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}



int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else if (!loadMusic())
	{
		printf("Failed to load music!\n");
	}
	else
	{
		//Load media
		if (!loadMediauser()||!loadMediabackground()||!loadMusic)
		{
			printf("Failed to load media!\n");
		}
		else
		{
			
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//The dot that will be moving around on the screen
			userdown userone(680,230); userdown usertwo(600,230);
			 SDL_Rect* currentClip = NULL; SDL_Rect* currentClip2 = NULL;
			//Set the wall
			bool GameStart = false;
			bool DeathStart = false;
			int DeathAnimate = 0;
			//yes or not to open the button picture
			int backgroundchange = MENU_1; int ingamebackground=0;
			int count = 0; int rockdrop=5;
			//While application is running
			Mix_FadeInMusic(gMusic_menu, -1, 4000);
			while (!quit)
			{
				int alpha = 0; int alpha_change = 0;
				while (backgroundchange == MENU_1)
				{
					if (SDL_PollEvent(&e) != 0)
					{
						//User requests quit
						if (e.type == SDL_QUIT)
						{
							quit = true; break;
						}

						//Handle input for the meu

						switch (menu1.keyboardEvent(e))
						{
						case 3:backgroundchange = MENU_2; break;
						}


					}
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
					SDL_RenderClear(gRenderer);
					//menu1.render(1);
					//start.render(3);
					!menu1;
					!start;
					start.bling(alpha);
					SDL_RenderPresent(gRenderer);

					if (alpha == 255)
						alpha_change = -1;
					if (alpha == 0)
						alpha_change = 1;
					alpha += alpha_change;


					if (quit == true)
						break;




				}
				while (backgroundchange == MENU_2)
				{
					//yes or not to open the button picture
					static bool b1 = false;
					static bool b2 = false;
					static bool b3 = false;
					static bool b4 = false;
					static bool playmusic = true;
					if (SDL_PollEvent(&e) != 0)
					{
						//User requests quit
						if (e.type == SDL_QUIT)
						{
							quit = true; break;
						}

						//Handle input for the meu
						switch (menu2.mouseEvent2(e))
						{
						case 1: backgroundchange = MENU_3;  break;//map
						case 2: backgroundchange = MENU_4; break;//music
						case 3: backgroundchange = INTRODUCTION; break;//teach

						}
						//yes or no the open the button picture by the mouse direction
						switch (menu2.mouseEvent2(e))
						{
						case 4: b1 = true;  break;
						case 6: b2 = true; break;
						case 7: b3 = true; break;
						case 5: b1 = false; b2 = false; b3 = false; playmusic = true; break;
						}


					}
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
					SDL_RenderClear(gRenderer);
					//meu2.render(8);
					!menu2;
					//yes or no to open the button 
					
					if (b1 == true)
					{
						//button1.render(4);
						!button1; 
						if(playmusic==true)
							Mix_PlayChannel(-1, gMusic_drum, 0); 
						playmusic = false;
					}
					if (b2 == true)
					{
						//button2.render(5); 
						!button2;
						if (playmusic == true)
							Mix_PlayChannel(-1, gMusic_drum, 0); 
						playmusic = false;
					}
					if (b3 == true)
					{
						//button3.render(6); 
						!button3; 
						if (playmusic == true) 
							Mix_PlayChannel(-1, gMusic_drum, 0); 
						playmusic = false;
					}
					SDL_RenderPresent(gRenderer);
				}
				while (backgroundchange == MENU_3)
				{
					//yes or no to render the back button
					static bool backbutton = false;
					static bool playmusic = true;
					if (SDL_PollEvent(&e) != 0)
					{
						//User requests quit
						if (e.type == SDL_QUIT)
						{
							quit = true; break;
						}

						//Handle input for the menu
						switch (menu3.mouseEvent3(e))
						{
						case 1: backgroundchange = MENU_2;  break;//map
						case 2: backgroundchange = GAMESTART; ingamebackground = BACKGROUND_1;
							//changing the music
							Mix_PauseMusic();
							Mix_PlayMusic(gMusic_game, -1); break;
						case 5: backgroundchange = GAMESTART; ingamebackground = BACKGROUND_2;
							Mix_PauseMusic();
							Mix_PlayMusic(gMusic_game, -1); 
							break;
						case 6: backgroundchange = GAMESTART; ingamebackground = BACKGROUND_3; 
							Mix_PauseMusic();
							Mix_PlayMusic(gMusic_game, -1); 
							break;
						}
						//yes or no the open the button picture by the mouse direction
						switch (menu3.mouseEvent3(e))
						{
						case 3:backbutton = true; break;
						case 4:backbutton = false; playmusic = true; break;
						}


					}
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
					SDL_RenderClear(gRenderer);
					//menu3.render(9);
					!menu3;
					//yes or no to open the button 
					if (backbutton == true)
					{
						//button4.render(7);
						!button4;
						if (playmusic == true)
							Mix_PlayChannel(-1, gMusic_drum, 0);
						playmusic = false;
					}
					SDL_RenderPresent(gRenderer);
				}
				while (backgroundchange == MENU_4)
				{
					static bool backbutton = false;
					static bool playmusic = true;
					bool biggermusic = false;
					bool smallermusic = false;
					if (SDL_PollEvent(&e) != 0)
					{
						//User requests quit
						if (e.type == SDL_QUIT)
						{
							quit = true; break;
						}

						//Handle input for the meu
						switch (menu4.mouseEvent4(e))
						{
						case 1: backgroundchange = MENU_2;  break;//map
						case 5: smallermusic = true; break;
						case 6: biggermusic = true; break;
						case 0: biggermusic = false; smallermusic = false; break;
						}
						//yes or no the open the button picture by the mouse direction
						switch (menu4.mouseEvent4(e))
						{
						case 3:backbutton = true; break;
						case 4:backbutton = false; biggermusic = false; smallermusic = false; playmusic = true;  break;
						}


					}
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
					SDL_RenderClear(gRenderer);
					//menu4.render(10);
					!menu4;
					//bigger or smaller the music
					if (biggermusic == true)
					{
						volume = (volume > 125) ? 128 : (volume += 20);
						Mix_VolumeMusic(volume);
						Mix_VolumeChunk(gMusic_attack, volume);
						Mix_VolumeChunk(gMusic_die, volume);
						Mix_VolumeChunk(gMusic_drum, volume);

					}
					if (smallermusic == true)
					{
						volume = (volume < 5) ? (-1) : (volume -= 20);
						Mix_VolumeMusic(volume);
						Mix_VolumeChunk(gMusic_attack, volume);
						Mix_VolumeChunk(gMusic_die, volume);
						Mix_VolumeChunk(gMusic_drum, volume);

					}
					//yes or no to open the button 
					if (backbutton == true)
					{
						//button4.render(7);
						!button4;
						if (playmusic == true)
							Mix_PlayChannel(-1, gMusic_drum, 0);
						playmusic = false;
					}
					SDL_RenderPresent(gRenderer);
				}
				while (backgroundchange == INTRODUCTION)
				{
					static bool backbutton = false;
					static bool playmusic = true;
					static int pagechange = 0;
					if (SDL_PollEvent(&e) != 0)
					{
						//User requests quit
						if (e.type == SDL_QUIT)
						{
							quit = true; break;
						}

						//Handle input for the menu
						switch (INtroduction.mouseEventINTRO(e))
						{
						case 1: backgroundchange = MENU_2;  break;//map 
						case 2:pagechange++; Mix_PlayChannel(-1, gMusic_page, 0); Mix_VolumeChunk(gMusic_page, 5000); break;
						}
						//yes or no the open the button picture by the mouse direction
						switch (INtroduction.mouseEvent3(e))
						{
						case 3:backbutton = true; break;
						case 4:backbutton = false; playmusic = true; break;
						}


					}
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
					SDL_RenderClear(gRenderer);
					//INtroduction.render(11);
					if(pagechange%2==0)
						!INtroduction;
					if (pagechange % 2 == 1)
						!INtroduction2;
					//yes or no to open the button 
					if (backbutton == true)
					{
						//button4.render(7);
						!button4;
						if (playmusic == true)
							Mix_PlayChannel(-1, gMusic_drum, 0);
						playmusic = false;
					}
					SDL_RenderPresent(gRenderer);
				}
				while (backgroundchange==GAMESTART)
				{
					static bool playmusic = true;
					//Handle events on queue
					if (SDL_PollEvent(&e) != 0)
					{
						//User requests quit
						if (e.type == SDL_QUIT)
						{
							quit = true; break;
						}

						//Handle input for the dot
						userone.handleEventOne(e);
						usertwo.handleEventTwo(e);
					}
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
					SDL_RenderClear(gRenderer);
					
					
					
					//Move the dot and check collision
					switch (userone.movetype())
					{
					case 0:userone.move();
						currentClip =userone.animatemove();
						break;
					case 1:
						currentClip = userone.animateattack1();
						Mix_PlayChannel(-1, gMusic_attack, 0);
						break;
					case 2: //水平
						currentClip = userone.animateattack2();
						Mix_PlayChannel(-1, gMusic_attack, 0);
						break;
					case 3: //舉刀
						userone.move();
						currentClip=userone.animateup();
						break;
					case 4:
						userone.move();
						currentClip=userone.animatedown();
						break;
					case 5:  //請實作側身閃躲
						userone.move();
						currentClip=userone.animatedoge1();
						break;

					case 6: //請實作蹲下閃躲 具體實作可參考上面程式
						userone.move();
						currentClip=userone.animatedoge2();
						break;

					}
					
					
					switch (usertwo.movetype())
					{
					case 0:
						usertwo.move();
						currentClip2 = usertwo.animatemove();
						break;
					case 1://vertical
						currentClip2 = usertwo.animateattack1();
						Mix_PlayChannel(-1, gMusic_attack, 0);
						break;
					case 2: //horizontal
						currentClip2 = usertwo.animateattack2();
						Mix_PlayChannel(-1, gMusic_attack, 0);
						break;
					case 3: //up

						usertwo.move();
						currentClip2=usertwo.animateup();
						break;
					case 4://down

						usertwo.move();
						currentClip2=usertwo.animatedown();
						break;
					case 5://dodge1

						usertwo.move();
						currentClip2=usertwo.animatedoge1();
						break;

					case 6: //dodge2

						usertwo.move();
						currentClip2=usertwo.animatedoge2();
						break;

					}

					
					

					if (userone.death(usertwo) == true )
						DeathStart = true;
					if (usertwo.death(userone) == true)
						DeathStart = true;
					if (DeathStart == true)
					{
						DeathAnimate++; SDL_Delay(50); Mix_PlayChannel(-1, gMusic_die, 0);
					}
					if (DeathAnimate == 8)
					{
						backgroundchange = GAMEOVER;  Mix_PauseMusic();
						Mix_PlayMusic(gMusic_menu, -1);
					}

					userone.reset();
					usertwo.reset();
					//background set
					switch (ingamebackground)
					{
					case BACKGROUND_1: !background1; break;
					case BACKGROUND_2:!background2; break;
					case BACKGROUND_3:!background3; break;
					}
					//special background
					int x;
					switch (ingamebackground)
					{
					case BACKGROUND_3: {
						
						count++;
						if (rock.dropend() == true)
						{
							srand(time(NULL)*1000);
							x = rand()%1400;
							rock.dosetvalue(x, 0);
						}
						if (count == 200)
						{
							rockdrop++;
							count = 0;
						}
						rock=rock - rockdrop;
						!rock;

					}break;
					case BACKGROUND_2: {
						++bar1;
						++bar2;
						!bar1;
						!bar2;
					}break;
					}
					switch (ingamebackground)
					{
					case BACKGROUND_2: {
						if (bar1.collision(userone) == true ||
							bar1.collision(usertwo) == true ||
							bar2.collision(userone) == true ||
							bar2.collision(usertwo) == true)
						{
							
							DeathAnimate = 8; Mix_PlayChannel(-1, gMusic_die, 0); Mix_PauseMusic();
							Mix_PlayMusic(gMusic_menu, -1);
						}
					case BACKGROUND_3: {
						if (rock.collision2(userone) == true || rock.collision2(usertwo) == true)
						{
							DeathAnimate = 8; Mix_PlayChannel(-1, gMusic_die, 0); Mix_PauseMusic();
							Mix_PlayMusic(gMusic_menu, -1);
						}
					}
					}
					}

					
					userone.render(currentClip, SDL_FLIP_HORIZONTAL);
					usertwo.render(currentClip2, SDL_FLIP_NONE);
					SDL_RenderPresent(gRenderer);
				}

				while (backgroundchange == GAMEOVER)
				{
					
					if (SDL_PollEvent(&e) != 0)
					{
						
						//User requests quit
						if (e.type == SDL_QUIT)
						{
							quit = true; break;
						}
						switch (gameset.mouseEventgameover(e))
						{
						case 1:backgroundchange = MENU_3;
							DeathAnimate = 0; DeathStart = false;
							userone.gamereset(680); usertwo.gamereset(600);
							bar1.dosetvalue(0, 0); bar2.dosetvalue(1490, 0);
							rock.dosetvalue(0, 0); rockdrop = 5;
							break;
						}
						//Handle input for the dot

					}
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
					SDL_RenderClear(gRenderer);
					switch (ingamebackground)
					{
					case BACKGROUND_1: !background1; break;
					case BACKGROUND_2:!background2; break;
					case BACKGROUND_3:!background3; break;
					}
					userone.render(currentClip, SDL_FLIP_HORIZONTAL);
					usertwo.render(currentClip2, SDL_FLIP_NONE);
					
					!gameset;
					if (userone.checkwin() == true)
					{
						!p1win;
					}
					if (usertwo.checkwin() == true)
					{
						!p2win;
					}
					
					
					SDL_RenderPresent(gRenderer);
				}
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}