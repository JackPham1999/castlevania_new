#pragma once
#include "GameObject.h"

#define TORCH_BBOX_WIDTH		20
#define TORCH_BBOX_HEIGHT		100
#define TORCH_STATE_EXIST		0
#define TORCH_STATE_NOT_EXIST	1
#define TORCH_ANI_EXIST			0
#define TORCH_ANI_NOT_EXIST		1

class CTorch : public CGameObject
{
public:
	CTorch();
	virtual void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
};
