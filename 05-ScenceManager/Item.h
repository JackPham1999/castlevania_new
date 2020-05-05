#pragma once
#include "GameObject.h"
#include "Simon.h"
#include "Utils.h"

#define ITEM_STATE_NOT_EXIST 0
#define ITEM_STATE_EXIST 1

#define ITEM_GRAVITY	 0.0002f
#define TIME_ITEM_EXIST 5000

#define ITEM_BBOX_WIDTH	20
#define ITEM_BBOX_HEIGHT	100
#define ID_WHIPUPGRADE	0

class CItem : public CGameObject
{
protected:
	int id;
	/*CItem* item;*/
	DWORD time_exsist;
	//vector<CItem> listItem;
public:
	CItem(float x = 0.0f, float y = 0.0f,int id=0);
	virtual void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b) {
		l = x;
		t = y;
		r = x + 16;
		b = y + 16;
	};
	void SetId(int i) { id = i; }
	int GetId() { return id; };
	/*virtual CItem* GetItem() { return item; }*/
};
