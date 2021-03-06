﻿#pragma once
#ifndef _BEDGEHOG_H_
#define _BEDGEHOG_H_

#include "Enemy.h"
#include "Parameters.h"

enum BEDGEHOG_STATE
{
	ON_BEDGEHOG_UP,
	ON_BEDGEHOG_BOTTOM,
	ON_BEDGEHOG_LEFT,
	ON_BEDGEHOG_RIGHT
};

class Bedgehog: public Enemy
{
protected:
	ENEMY_TYPE enemy_type;
	BEDGEHOG_STATE state;
	Sprite * up;
	Sprite * bottom;
	Sprite * left;
	Sprite * right;

public:
	Bedgehog();
	Bedgehog(LPD3DXSPRITE spriteHandler, World * manager, ENEMY_TYPE enemy_type);
	~Bedgehog();

	ENEMY_TYPE GetEnemyType();
	void InitSprites();
	//============== OVERRIDE VIRTUAL METHOD ===================
	virtual void Update(int t);
	virtual void Render();
	//============== END OVERRIDE VIRTUAL METHOD ===============
};

#endif // !_BEDGEHOG_H_
