#pragma once
#ifndef _SAMUS_H
#define _SAMUS_H_
#include "Sprite.h"

#define SAMUS_SPRITES_PATH L"sprites\\samus\\samus_sprites.png"

#define APPEARING "sprites\\samus\\APPEARING.txt"
#define RUNNING_LEFT "sprites\\samus\\RUNNING_LEFT.txt"
#define RUNNING_RIGHT "sprites\\samus\\RUNNING_RIGHT.txt"
#define JUMP_LEFT "sprites\\samus\\JUMP_LEFT.txt"
#define JUMP_RIGHT "sprites\\samus\\JUMP_RIGHT.txt"
#define RUN_SHOOTING_LEFT "sprites\\samus\\RUN_SHOOTING_LEFT.txt"
#define RUN_SHOOTING_RIGHT "sprites\\samus\\RUN_SHOOTING_RIGHT.txt"
#define RUN_AIM_UP_LEFT "sprites\\samus\\RUN_AIM_UP_LEFT.txt"
#define RUN_AIM_UP_RIGHT "sprites\\samus\\RUN_AIM_UP_RIGHT.txt"
#define IDLE_AIM_UP_LEFT "sprites\\samus\\IDLE_AIM_UP_LEFT.txt"
#define IDLE_AIM_UP_RIGHT "sprites\\samus\\IDLE_AIM_UP_RIGHT.txt"
#define STANDING_LEFT "sprites\\samus\\STANDING_LEFT.txt"
#define STANDING_RIGHT "sprites\\samus\\STANDING_RIGHT.txt"
#define MORPH_BALL_LEFT "sprites\\samus\\MORPH_BALL_LEFT.txt"
#define MORPH_BALL_RIGHT "sprites\\samus\\MORPH_BALL_RIGHT.txt"
#define SOMERSAULT_LEFT "sprites\\samus\\SOMERSAULT_LEFT.txt"
#define SOMERSAULT_RIGHT "sprites\\samus\\SOMERSAULT_RIGHT.txt"
#define JUMPING_SHOOTING_LEFT "sprites\\samus\\JUMP_SHOOTING_LEFT.txt"
#define JUMPING_SHOOTING_RIGHT "sprites\\samus\\JUMP_SHOOTING_RIGHT.txt"

#define APPEARING_WIDTH 16
#define APPEARING_HEIGHT 32
#define RUNNING_WIDTH 18
#define RUNNING_HEIGHT 32
#define JUMP_WIDTH 18
#define JUMP_HEIGHT 25
#define RUN_SHOOTING_WIDTH 25
#define RUN_SHOOTING_HEIGHT 31
#define RUN_AIM_UP_WIDTH 17
#define RUN_AIM_UP_HEIGHT 38
#define IDLE_AIM_UP_WIDTH 14
#define IDLE_AIM_UP_HEIGHT 38
#define STANDING_WIDTH 21
#define STANDING_HEIGHT 32
#define MORPH_BALL_WIDTH 12
#define MORPH_BALL_HEIGHT 13
#define RUN_SHOOTING_WIDTH 22
#define RUN_SHOOTING_HEIGHT 31
#define SOMERSAULT_WIDTH 19
#define SOMERSAULT_HEIGHT 23
#define JUMPING_SHOOTING_WIDTH 23
#define JUMPING_SHOOTING_HEIGHT 25

#define APPEARING_COUNT 5
#define RUNNING_COUNT 3
#define JUMP_COUNT 1
#define RUN_SHOOTING_COUNT 3
#define RUN_AIM_UP_COUNT 3
#define IDLE_AIM_UP_COUNT 1
#define STANDING_COUNT 1
#define MORPH_BALL_COUNT 4
#define RUN_SHOOTING_COUNT 3
#define SPRITE_PER_ROW 1
#define SOMERSAULT_COUNT 4
#define JUMPING_SHOOTING_COUNT 1

#define ANIMATE_RATE 15

#define JUMP_VELOCITY_BOOST 0.02f
#define JUMP_VELOCITY_BOOST_FIRST 0.3f
#define FALLDOWN_VELOCITY_DECREASE 0.2f

#define GROUND_Y 40

#include "GameObject.h"

enum SAMUS_STATE {
	IDLE_LEFT, 
	IDLE_RIGHT,
	LEFTING, 
	RIGHTING,
	IDLING_AIM_UP_LEFT,
	IDLING_AIM_UP_RIGHT,
	AIMING_UP_LEFT,
	AIMING_UP_RIGHT,
	ON_MORPH_LEFT,
	ON_MORPH_RIGHT,
	ON_RUN_SHOOTING_LEFT,
	ON_RUN_SHOOTING_RIGHT,
	ON_JUMP_LEFT,
	ON_JUMP_RIGHT,
	ON_SOMERSAULT_LEFT,
	ON_SOMERSAULT_RIGHT,
	ON_JUMPING_SHOOTING_LEFT,
	ON_JUMPING_SHOOTING_RIGHT
};
class Samus : public GameObject
{
protected:
	LPD3DXSPRITE _SpriteHandler;

	Sprite * appearing;
	Sprite * running_left;
	Sprite * running_right;
	Sprite * jump_left;
	Sprite * jump_right;
	Sprite * run_shooting_left;
	Sprite * run_shooting_right;
	Sprite * run_aim_up_left;
	Sprite * run_aim_up_right;
	Sprite * idle_aim_up_left;
	Sprite * idle_aim_up_right;
	Sprite * idle_left;
	Sprite * idle_right;
	Sprite * morph_ball_left;
	Sprite * morph_ball_right;
	Sprite * somersault_left;
	Sprite * somersault_right;
	Sprite * jumping_shooting_left;
	Sprite * jumping_shooting_right;

	SAMUS_STATE state;

	void _Render();
public:
	Samus();
	~Samus();
	void SetPosX(int value);
	int GetPosX();
	void SetPosY(int value);
	int GetPosY();
	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void InitPostition();

	SAMUS_STATE GetState();
	void SetState(SAMUS_STATE value);

	void ResetAllSprites();
	
	//Update every frame of game	
	void Update(int t);

};
#endif // !_SAMUS_H

