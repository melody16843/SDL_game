
#include "LTexture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "userdown.h"
#include<iostream>
using namespace std;
extern LTexture gUserTexture;
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern const int WALKING_ANIMATION_FRAMES = 4;
extern const int UP_ANIMATION_FRAME = 4;
extern const int DODGE_ANIMATION_FRAME = 4;
extern const int DODGE_STYLE = 2;
extern SDL_Rect gWalkClips[WALKING_ANIMATION_FRAMES];
extern SDL_Rect gWalkUpClips[WALKING_ANIMATION_FRAMES];
extern SDL_Rect gWalkDownClips[WALKING_ANIMATION_FRAMES];
extern SDL_Rect gCutClips[WALKING_ANIMATION_FRAMES][UP_ANIMATION_FRAME];
extern SDL_Rect gUpClips[WALKING_ANIMATION_FRAMES][UP_ANIMATION_FRAME];
extern SDL_Rect gCut2Clips[WALKING_ANIMATION_FRAMES][UP_ANIMATION_FRAME];
extern SDL_Rect gDownClips[WALKING_ANIMATION_FRAMES][UP_ANIMATION_FRAME];
extern SDL_Rect gDodgeClips[DODGE_STYLE][DODGE_ANIMATION_FRAME];

userdown::userdown(int x,int y)
{
    //Initialize the offsets
    mPosX = x;
    mPosY = y;
    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
   
}
userdown::~userdown() {
    
}
void userdown::render(SDL_Rect* clip,SDL_RendererFlip flip)
{
    //Show the dot
    gUserTexture.render(mPosX, mPosY,clip,NULL,NULL,flip);
}
void userdown::handleEventOne(SDL_Event& e)
{
    //If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        //Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_UP: AUP = true; break;
        case SDLK_DOWN: ADOWN=true; break;
        case SDLK_LEFT: mVelX -= DOT_VEL; break;
        case SDLK_RIGHT: mVelX += DOT_VEL; break;
        case SDLK_n:dodge1 = true; break;
        case SDLK_b:dodge2 = true; break;
        }
    }
    //If a key was released
    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        //Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_UP: AUP=false; break;
        case SDLK_DOWN: ADOWN=false; break;
        case SDLK_LEFT: mVelX += DOT_VEL; break;
        case SDLK_RIGHT: mVelX -= DOT_VEL; break;
        case SDLK_n:dodge1 = false; break;
        case SDLK_b:dodge2 = false; break;
        }
    }
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym==SDLK_m)
    {
        ATTACK = true;
    }
    else 
    {
        ATTACK = false;
    }
    
    //請增加判斷閃躲的 if判斷式 閃躲鍵為n 上方為攻擊的可以參考
}
void userdown::handleEventTwo(SDL_Event& e)
{
    //If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        //Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_r: AUP = true; break;
        case SDLK_f: ADOWN = true; break;
        case SDLK_d: mVelX -= DOT_VEL; break;
        case SDLK_g: mVelX += DOT_VEL; break;
        case SDLK_w:dodge1 = true; break;
        case SDLK_q:dodge2 = true; break;
        }
    }
    //If a key was released
    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        //Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_r: AUP = false; break;
        case SDLK_f: ADOWN = false; break;
        case SDLK_d: mVelX += DOT_VEL; break;
        case SDLK_g: mVelX -= DOT_VEL; break;
        case SDLK_w:dodge1 = false; break;
        case SDLK_q:dodge2 = false; break;
        }
    }
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_s)
    {
        ATTACK = true;
    }
    else
    {
        ATTACK = false;
    }
    
    //請增加判斷閃躲的 if判斷式 閃躲鍵為n 上方為攻擊的可以參考
}

void userdown::move()
{
    //Move the dot left or right
    mPosX += mVelX;
   

    //If the dot collided or went too far to the left or right
    if ((mPosX < 0) || (mPosX + DOT_WIDTH > SCREEN_WIDTH) )
    {
        //Move back
        mPosX -= mVelX;
       
    }
    if (mVelX < 0)
    {

        //Update screen

        ++frame;

        //Cycle animation
        if (frame / 2 >= WALKING_ANIMATION_FRAMES)
        {
            frame = 0;
        }
    }
    else if (mVelX > 0)
    {

        //Update screen
        --frame;
        //Cycle animation
        if (frame / 2 <= -WALKING_ANIMATION_FRAMES)
        {
            frame = 0;
        }

    }

}
SDL_Rect* userdown::animatemove()
{
    if (frame >= 0)
    {
       SDL_Rect* currentclip= &gWalkClips[frame / 2];
       
       return currentclip;
    }
    else
    {
        SDL_Rect* currentclip = &gWalkClips[-frame / 2];
        return currentclip;
    }
    
}
SDL_Rect* userdown::animateattack1()
{
    SDL_Rect* currentclip=NULL;
    if (AttackControll1 < 3)
    {
        if (frame >= 0)
        {
            currentclip = &gCutClips[frame / 2][AttackControll1]; AttackControll1++;
           
        }
        if (frame < 0)
        {
            currentclip = &gCutClips[-frame / 2][AttackControll1]; AttackControll1++;
            
        }
        AttackEnd = false;
    }
    else
    {
      if (frame >= 0)
      {
            currentclip = &gCutClips[frame / 2][3];
            
      }
        if (frame < 0)
        {
            currentclip = &gCutClips[-frame / 2][3];
           
        }
    }
    return currentclip;
}
SDL_Rect* userdown::animateattack2()
{
    SDL_Rect* currentclip=NULL;
    if (AttackControll2 < 3)
    {
        if (frame >= 0)
        {
            currentclip = &gCut2Clips[frame / 2][AttackControll2]; AttackControll2++;
            
        }
        if (frame < 0)
        {
           currentclip = &gCut2Clips[-frame / 2][AttackControll2]; AttackControll2++;
            
        }
        AttackEnd = false;
    }
    else
    {
        if (frame >= 0)
        {
            currentclip = &gCut2Clips[frame / 2][3];
           
        }
        if (frame < 0)
        {
           currentclip = &gCut2Clips[-frame / 2][3];
            
        }
    }
    return currentclip;
}
SDL_Rect* userdown::animateup()
{
    SDL_Rect* currentclip=NULL;
    if (UpControll < 3)
    {
        if (frame >= 0)
        {
            currentclip = &gUpClips[frame / 2][UpControll]; UpControll++;
            
        }
        if (frame < 0)
        {
           currentclip = &gUpClips[-frame / 2][UpControll]; UpControll++;
           
        }
        
    }
    else
    {
        if (frame >= 0)
        {
           currentclip = &gWalkUpClips[frame / 2];
            
        }
        else
        {
          currentclip = &gWalkUpClips[-frame / 2];
            
        }
    }
    return currentclip;
}
SDL_Rect* userdown::animatedown()
{
    if (DownControll < 3)
    {
        if (frame >= 0)
        {
            SDL_Rect* currentclip = &gDownClips[frame / 2][DownControll]; DownControll++;
            return currentclip;
        }
        if (frame < 0)
        {
            SDL_Rect* currentclip = &gDownClips[-frame / 2][DownControll]; DownControll++;
            return currentclip;
        }
    }
    else
    {
        if (frame >= 0)
        {
            SDL_Rect* currentclip = &gWalkDownClips[frame / 2];
            return currentclip;
        }
        else
        {
            SDL_Rect* currentclip = &gWalkDownClips[-frame / 2];
            return currentclip;
        }
    }
}
SDL_Rect* userdown::animatedoge1()
{
    if (frame >= 0)
    {
        SDL_Rect* currentclip = &gDodgeClips[0][frame / 2];
        return currentclip;
    }
    else
    {
        SDL_Rect* currentclip = &gDodgeClips[0][-frame / 2];
        return currentclip;
    }

}
SDL_Rect* userdown::animatedoge2()
{
    if (frame >= 0)
    {
        SDL_Rect* currentclip = &gDodgeClips[1][frame / 2];
        return currentclip;
    }
    else
    {
        SDL_Rect* currentclip = &gDodgeClips[1][-frame / 2];
        return currentclip;
    }

}
void userdown::reset()
{
    if (this->movetype() != 1 && AttackControll1 != 0)
    {
        AttackControll1 = 0; AttackEnd = true; 
    }
    if (this->movetype() != 2 && AttackControll2 != 0)
    {
        AttackControll2 = 0; AttackEnd = true;
    }
    if (this->movetype() != 3 && UpControll != 0)
        UpControll = 0;
    if (this->movetype() != 4 && DownControll != 0)
        DownControll = 0;
    //cout << AttackEnd << endl;
}
bool userdown::death(userdown& rival)
{
    bool death = false;
    int interval;
    if (rival.getposition() - mPosX < 0)
        interval = -(rival.getposition() - mPosX);
    else
        interval = rival.getposition() - mPosX;
   // cout << interval <<" " <<death<< endl;
    if (AttackEnd == false && interval < 50)
    {
        
      
        if (this->movetype() == 2 && rival.movetype() != 6)
            death = true;
        if (this->movetype() == 1 && rival.movetype() != 5)
            death = true;
    }
    if (AttackEnd == false && interval < 150)
    {
        if (this->movetype() == 1 && rival.movetype() == 6)
            death = true;
    }

    if (death == true)
        rival.win = true;
    return death;

}
bool userdown::checkwin() const {
    return win;
}
void userdown::gamereset(int x)
{
    frame = 0;
    AUP = false, ADOWN = false, ATTACK = false;
    dodge1 = false, dodge2 = false;

    AttackControll1 = 0, AttackControll2 = 0;
    UpControll = 0, DodgeControll = 0, AttackEnd = true, DownControll = 0,  DodgeControll2 = 0;
    mPosX = x;
    mVelX = 0;
    win = false;
}

int userdown::getposition() const
{
    return mPosX;
}
int userdown::movetype()
{
    if (AUP == true && ATTACK == true)
    {
        return 1;
    }
    else if (ADOWN == true && ATTACK == true)
    {
        return 2;
    }
    else if (AUP == true && ATTACK == false)
        return 3;
    else if (ADOWN == true && ATTACK == false)
        return 4;
    else if (dodge1 == true)
        return 5;
    else if (dodge2 == true)
        return 6;
    
    else
        return 0;
}
ostream& operator<<(ostream& output, const userdown &r) {
    output << "posx:" << r.mPosX << endl
        << "posy:" << r.mPosY << endl
        << "frame" << r.frame << endl
        << "aup:" << r.AUP << endl
        << "adown:" << r.ADOWN << endl
        << "attack:" << r.ATTACK << endl
        << "attackcontroll1:" << r.AttackControll1 << endl
        << "attackcontroll2:" << r.AttackControll2 << endl
        << "upcontroll:" << r.UpControll << endl
        << "downcontroll:" << r.DownControll << endl
        << "dodgecontroll:" << r.DodgeControll << endl
        << "dodgecontroll:" << r.DodgeControll2 << endl
        << "win:" << r.win << endl;
    return output;
}