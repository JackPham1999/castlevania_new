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
	static CTorch* __instance;
protected:
	DWORD dt_die;
	int id;
	//CItem* item=new CItem(Random(0,5));
	CItem* item = new CItem(x,y,0);
public:
	CTorch(float x = 0.0f, float y = 0.0f/*,int id=0*/);
	~CTorch() { };
	virtual void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	CItem* GetItem() { return item; }
	CItem* SetItem(CItem* i) { item = i; return item; }
	int Random(int maxN,int minN) {
		int r = minN + rand() % (maxN + 1 - minN);
		return r;
	};
	float GetX() { return x; }
	static CTorch* GetInstance();
	static CTorch* SetInstance(CGameObject* obj);
};
