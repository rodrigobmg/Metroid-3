#include "Metroid.h"
#include <time.h>
#include "trace.h"

void Metroid::_InitBackground()
{
}

void Metroid::_InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	samus->InitSprites(d3ddv);
}

void Metroid::_InitPositions()
{
	samus->InitPostition();
}


Metroid::Metroid(HINSTANCE hInstance, LPWSTR Name, int Mode, int IsFullScreen, int FrameRate):Game(hInstance, Name, Mode, IsFullScreen, FrameRate)
{
	samus = new Samus();
}


Metroid::~Metroid()
{
	delete(samus);
}

void Metroid::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
	samus->Update(Delta);
}

void Metroid::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
	
	//if (IsKeyDown(DIK_RIGHT) && IsKeyDown(DIK_UP))
	//{
	//	samus->SetVelocityXLast(samus->GetVelocityX());
	//	samus->SetVelocityX(SAMUS_SPEED);
	//	samus->SetState(AIMING_UP_RIGHT);
	//}
	//else if (IsKeyDown(DIK_LEFT) && IsKeyDown(DIK_UP))
	//{
	//	samus->SetVelocityXLast(samus->GetVelocityX());
	//	samus->SetVelocityX(-SAMUS_SPEED);
	//	samus->SetState(AIMING_UP_LEFT);
	//}
	//else if (IsKeyDown(DIK_LEFT) && IsKeyDown(DIK_X))	//shooting
	//{
	//	samus->SetVelocityXLast(samus->GetVelocityX());
	//	samus->SetVelocityX(-SAMUS_SPEED);
	//	samus->SetState(ON_RUN_SHOOTING_LEFT);
	//}
	//else if (IsKeyDown(DIK_RIGHT) && IsKeyDown(DIK_X))
	//{
	//	samus->SetVelocityXLast(samus->GetVelocityX());
	//	samus->SetVelocityX(SAMUS_SPEED);
	//	samus->SetState(ON_RUN_SHOOTING_RIGHT);
	//}
	if (IsKeyDown(DIK_RIGHT))
	{
		samus->SetVelocityXLast(samus->GetVelocityX());
		samus->SetVelocityX(SAMUS_SPEED);	
		if (samus->GetState() != ON_MORPH_LEFT && samus->GetState() != ON_MORPH_RIGHT
			&& samus->GetState() != ON_JUMP_LEFT && samus->GetState() != ON_JUMP_RIGHT
			/*&& samus->GetState() != ON_RUN_SHOOTING_LEFT && samus->GetState() != ON_RUN_SHOOTING_RIGHT*/)
		{
			if (IsKeyDown(DIK_UP))
				samus->SetState(AIMING_UP_RIGHT);
			else if (IsKeyDown(DIK_Z))
				samus->SetState(ON_RUN_SHOOTING_RIGHT);
			else
				samus->SetState(RIGHTING);
		}
	}
	else if (IsKeyDown(DIK_LEFT))
	{
		samus->SetVelocityXLast(samus->GetVelocityX());
		samus->SetVelocityX(-SAMUS_SPEED);
		if (samus->GetState() != ON_MORPH_LEFT && samus->GetState() != ON_MORPH_RIGHT
			&& samus->GetState() != ON_JUMP_LEFT && samus->GetState() != ON_JUMP_RIGHT
			/*&& samus->GetState() != ON_RUN_SHOOTING_LEFT && samus->GetState() != ON_RUN_SHOOTING_RIGHT*/)
		{
			if (IsKeyDown(DIK_UP))
				samus->SetState(AIMING_UP_LEFT);
			else if (IsKeyDown(DIK_Z))
				samus->SetState(ON_RUN_SHOOTING_LEFT);
			else
				samus->SetState(LEFTING);
		}
	}
	else if (IsKeyDown(DIK_UP))
	{
		samus->SetVelocityX(0);
		samus->ResetAllSprites();
		if (samus->GetVelocityXLast() > 0)
			samus->SetState(IDLING_AIM_UP_RIGHT);
		else if (samus->GetVelocityXLast() < 0)
			samus->SetState(IDLING_AIM_UP_LEFT);
	}
	else
	{
		samus->SetVelocityX(0);
		samus->ResetAllSprites();
		
		if (samus->GetVelocityXLast() < 0)
		{
			if (samus->GetState() != ON_MORPH_LEFT && samus->GetState() != ON_JUMP_LEFT && samus->GetState() != ON_JUMP_RIGHT)
				samus->SetState(IDLE_LEFT);
		}
		else
		{
			if (samus->GetState() != ON_MORPH_RIGHT && samus->GetState() != ON_JUMP_LEFT && samus->GetState() != ON_JUMP_RIGHT)
				samus->SetState(IDLE_RIGHT);
		}
	}
	
}

void Metroid::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	srand((unsigned)time(NULL));
	_InitSprites(d3ddv);
	_InitPositions();
}

void Metroid::OnKeyDown(int KeyCode)
{
	switch (KeyCode)
	{
	case DIK_DOWN:
		//if samus is idle then do morph
		if (samus->GetState() == IDLE_LEFT)
		{
			samus->SetVelocityX(0);
			samus->ResetAllSprites();
			samus->SetState(ON_MORPH_LEFT);
		}
		else if (samus->GetState() == IDLE_RIGHT)
		{
			samus->SetVelocityX(0);
			samus->ResetAllSprites();
			samus->SetState(ON_MORPH_RIGHT);
		}
		else if (samus->GetState() == ON_MORPH_LEFT) //otherwise, reset to idle (left of right)
		{
			samus->SetVelocityX(0);
			samus->ResetAllSprites();
			samus->SetState(IDLE_LEFT);
		}
		else if (samus->GetState() == ON_MORPH_RIGHT)
		{
			samus->SetVelocityX(0);
			samus->ResetAllSprites();
			samus->SetState(IDLE_RIGHT);
		}
		break;
	case DIK_X:
		//**********************************************************************************
		// [CAUTION!!!] Vi pos_y chua chinh theo toa do World, code duoi day chi la tam thoi,
		// se cap nhat lai sau
		if (samus->GetPosY() >= GROUND_Y)
		{
			if (samus->GetVelocityXLast() < 0)
			{
				samus->SetState(ON_JUMP_LEFT);
				samus->SetVelocityY(samus->GetVelocityY() - JUMP_VELOCITY_BOOST);
			}
			else if (samus->GetVelocityXLast() > 0)
			{
				samus->SetState(ON_JUMP_RIGHT);
				samus->SetVelocityY(samus->GetVelocityY() - JUMP_VELOCITY_BOOST);
			}
		}
		//***********************************************************************************
		break;
	case DIK_LEFT:
		if (samus->GetState() == ON_JUMP_RIGHT)
			samus->SetState(ON_JUMP_LEFT);
		if (samus->GetState() == ON_MORPH_RIGHT)
			samus->SetState(ON_MORPH_LEFT);
		else if (samus->GetState() != ON_MORPH_LEFT && samus->GetState() != ON_JUMP_LEFT && samus->GetState() != ON_JUMP_RIGHT)
			samus->SetState(LEFTING);
		break;
	case DIK_RIGHT:
		if (samus->GetState() == ON_JUMP_LEFT)
			samus->SetState(ON_JUMP_RIGHT);
		if (samus->GetState() == ON_MORPH_LEFT)
			samus->SetState(ON_MORPH_RIGHT);
		else if (samus->GetState() != ON_MORPH_RIGHT && samus->GetState() != ON_JUMP_LEFT && samus->GetState() != ON_JUMP_RIGHT)
			samus->SetState(RIGHTING);
		break;
	}

}
