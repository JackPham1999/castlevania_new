#pragma once
#include "GameObject.h"

#define SIMON_WALKING_SPEED		0.15f 
//0.1f
#define SIMON_JUMP_SPEED_Y		0.5f
#define SIMON_JUMP_DEFLECT_SPEED 0.2f
#define SIMON_GRAVITY			0.002f
#define SIMON_DIE_DEFLECT_SPEED	 0.5f

#define SIMON_STATE_IDLE			0
#define SIMON_STATE_WALKING_RIGHT	100
#define SIMON_STATE_WALKING_LEFT	200
#define SIMON_STATE_JUMP			300
#define SIMON_STATE_DIE				400
#define SIMON_STATE_ATTACKING		500

#define SIMON_ANI_BIG_IDLE_RIGHT		0
#define SIMON_ANI_BIG_IDLE_LEFT			1

#define SIMON_ANI_WALKING_RIGHT			2
#define SIMON_ANI_WALKING_LEFT			3

#define SIMON_ANI_ATTACKING_RIGHT			4
#define SIMON_ANI_ATTACKING_LEFT			5

#define SIMON_ANI_DIE					6

#define	SIMON_LEVEL_SMALL	1
#define	SIMON_LEVEL_BIG		2

#define SIMON_BIG_BBOX_WIDTH  22
#define SIMON_BIG_BBOX_HEIGHT 28

#define SIMON_SMALL_BBOX_WIDTH  50
#define SIMON_SMALL_BBOX_HEIGHT 35

#define SIMON_UNTOUCHABLE_TIME 5000


class CSimon : public CGameObject
{
	static CSimon* __instance;
	int level;
	int untouchable;
	DWORD untouchable_start;
	bool isJump;
	bool isAttack;

	float start_x;			// initial position of SIMON at scene
	float start_y; 
public: 
	CSimon(float x = 0.0f, float y = 0.0f);
	static CSimon* GetInstance();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void Render();

	void SetState(int state);
	void SetLevel(int l) { level = l; }
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount(); }
	void Reset();
	bool GetisAttack(){ return isAttack;}

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
};