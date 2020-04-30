#include "Item.h"
#include "Torch.h"
#include "Brick.h"

CItem::CItem(/*float x, float y,*/int id) :CGameObject()
{/*
	this->x = x;
	this->y = y;*/
	this->id = id;
	time_exsist = 0;
	state = ITEM_STATE_EXSIST;
	/*switch (id)
	{
	case ID_WHIPUPGRADE:
		
	}*/
}

void CItem::Render()
{
	//if (state == ITEM_STATE_EXSIST)
	//{
		if (animation_set->size() > 0)
			animation_set->at(0)->Render(x, y);
	//}
	//RenderBoundingBox();
}




void CItem::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (!time_exsist)
	{
		time_exsist = GetTickCount();
	}
	else
	{
		if (GetTickCount() - time_exsist >= TIME_ITEM_EXSIST)
			state = ITEM_STATE_NOT_EXSIST;
	}
	CGameObject::Update(dt);

	// Simple fall down
	vy += ITEM_GRAVITY * dt;

	vector<LPGAMEOBJECT> listBrick;
	for (int i = 0; i < coObjects->size(); i++)
	{

		if (dynamic_cast<CBrick*>(coObjects->at(i)))
		{
			///DebugOut(L"[DEBUG] = enter loop ");
			CBrick* brick = dynamic_cast<CBrick*>(coObjects->at(i));
			listBrick.push_back(brick);
		}

	}
	DebugOut(L"[DEBUG] listBrick= %d",listBrick.size());
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	// turn off collision when die 
	if (state != ITEM_STATE_NOT_EXSIST)
	{
		CalcPotentialCollisions(&listBrick, coEvents);
	}
	// No collision occured, proceed normally
	if (coEvents.size() == 0)
	{
		x += dx;
		y += dy;
		DebugOut(L"[DEBUG] normally");
	}
	else
	{
		DebugOut(L"[DEBUG] okkkkk");
		float min_tx, min_ty, nx = 0, ny;
		float rdx = 0;
		float rdy = 0;

		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny, rdx, rdy);

		//// block 
		//x += min_tx * dx + nx * 0.4f;		// nx*0.4f : need to push out a bit to avoid overlapping next frame
		y += min_ty * dy + ny * 0.4f;

		if (nx != 0) vx = 0;
		if (ny != 0) vy = 0;
	}
	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];



}
