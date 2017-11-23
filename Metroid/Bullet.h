#pragma once
#ifndef _BULLET_H_
#define _BULLET_H_

#include "GameObject.h"
#include "Sprite.h"

#define BULLET_SPRITE_PATH L"sprites\\bullet\\bullet.png"
#define BULLET_SPRITE "sprites\\bullet\\BULLET.txt"
#define BULLET_WIDTH 6
#define BULLET_HEIGHT 7
#define BULLET_COUNT 1
#define SPRITE_PER_ROW 1

#define SPEED 0.6f
#define LIMIT_DISTANCE 150

enum BULLET_DIRECTION 
{
	NONE,
	ON_LEFT,
	ON_RIGHT,
	ON_UP
};

class Bullet : public GameObject
{
private:
	int pos_x_holder;
	int pos_y_holder;

	int limit_dist_x;		//limit distance of x
	int limit_dist_y;		//limit distance of y;

	bool isRendering;		//determine if the bullet is in rendering (in case out of distance_limit -> not render)

	LPD3DXSPRITE _SpriteHandler;
	BULLET_DIRECTION direction;
	Sprite * bullet;

	void _Render();
public:
	Bullet();
	Bullet(int x_holder, int y_holder);
	~Bullet();

	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void InitPosition(int posX, int posY);

	BULLET_DIRECTION GetDirection();
	void SetDirection(BULLET_DIRECTION value);
	void Update(int t, int posX, int posY);
	void ResetPosition();
	void Reset();
	void Release();		//destroy the bullet
	void Shoot(BULLET_DIRECTION dir);
};

#endif // !_BULLET_H