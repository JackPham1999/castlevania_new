#pragma once
#include "GameObject.h"
//#include "Textures.h"
//#include "Weapon.h"

#define WHIP_HEIGHT 64
#define WHIP_WIDTH 160

#define WHIP_NOT_ATTACK 0
#define WHIP_ATTACK 1 

#define WHIP_LEVEL1_ANI_ATTACK_RIGHT 0
#define WHIP_LEVEL1_ANI_ATTACK_LEFT  1
#define WHIP_LEVEL2_ANI_ATTACK_RIGHT  2
#define WHIP_LEVEL2_ANI_ATTACK_LEFT  3
#define WHIP_LEVEL3_ANI_ATTACK_RIGHT  4
#define WHIP_LEVEL3_ANI_ATTACK_LEFT  5


class CWhip : public CGameObject
{
	int _level = 1;
	static CWhip* __instance;
public:

	static CWhip* GetInstance();
	CWhip();
	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	//void setUpLevel();
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);

};