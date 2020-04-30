#pragma once
#include "GameObject.h"
#include"Item.h"

#define TORCH_BBOX_WIDTH		20
#define TORCH_BBOX_HEIGHT		100
#define TORCH_STATE_EXIST		0
#define TORCH_STATE_HIT_EFFECT		1
#define TORCH_STATE_NOT_EXIST	2
#define TORCH_ANI_EXIST			0
#define TORCH_ANI_HIT_EFFECT	1
#define TORCH_ANI_NOT_EXIST		2

class CTorch : public CGameObject
{
protected:
	DWORD dt_die;
	int id;
	/*CItem* item;*/
public:
	CTorch(float x = 0.0f, float y = 0.0f/*,int id=0*/);
	virtual void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	/*virtual CItem* GetItem() { return item; }
	CItem* SetItem(CItem* i) { item = i; return item; }*/
};
