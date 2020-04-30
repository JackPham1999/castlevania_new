#pragma once
#include "GameObject.h"
#include "Simon.h"

#define ITEM_STATE_NOT_EXSIST 0
#define ITEM_STATE_EXSIST 1

#define ITEM_GRAVITY	 0.02f
#define TIME_ITEM_EXSIST 5000

#define ITEM_BBOX_WIDTH	20
#define ITEM_BBOX_HEIGHT	100
#define ID_WHIPUPGRADE	0

class CItem : public CGameObject
{
protected:
	int id;
	/*CItem* item;*/
	DWORD time_exsist;
public:
	CItem(/*float x = 0.0f, float y = 0.0f,*/int id=0);
	virtual void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b) { l = t = r = b = 0; };
	void SetId(int i) { id = i; }
	/*virtual CItem* GetItem() { return item; }*/
};
