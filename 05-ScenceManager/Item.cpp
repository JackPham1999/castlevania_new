#include "Item.h"
#include "Torch.h"
#include "Brick.h"

CItem::CItem(float x, float y,int id) :CGameObject()
{
	this->x = x;
	this->y = y;
	this->id = id;
	time_exsist = 0;
	state = ITEM_STATE_NOT_EXSIST;
	/*switch (id)
	{
	case ID_WHIPUPGRADE:
		
	}*/
}

void CItem::Render()
{
	CAnimationSets* animation_sets = CAnimationSets::GetInstance();
	LPANIMATION_SET ani_set = animation_sets->Get(6);
	SetAnimationSet(ani_set);
	if (state == ITEM_STATE_EXSIST)
	{
		//SetPosition(150, 100);
		if (animation_set->size() > 0)/////animation_set=null
			animation_set->at(0)->Render(x, y);
			/*animation_set->at(0)->Render(150, 100);*/
	}
	RenderBoundingBox();
}




void CItem::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	
	CGameObject::Update(dt);

	// Simple fall down
	vy += ITEM_GRAVITY*dt;
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();


	CalcPotentialCollisions(coObjects, coEvents);
	//DebugOut(L"\n[DEBUG] coEvent simon == %d", coEvents.size()); 
	float l, t, r, b;
	GetBoundingBox(l, t, r, b);
	//DebugOut(L"\n[DEBUG] l t r b %f %f %f %f", l,t,r,b);

	// No collision occured, proceed normally
	if (coEvents.size() == 0)
	{
		x += dx;
		y += dy;
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;
		float rdx = 0;
		float rdy = 0;
		//DebugOut(L"\n[DEBUG] updating item");
		//DebugOut(L"\n[DEBUG] x y %f %f", x,y);
		// TODO: This is a very ugly designed function!!!!
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny, rdx, rdy);
		//RenderBoundingBox();
		if (nx != 0) vx = 0;
		if (ny != 0) vy = 0;

		// clean up collision events
		for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
	}
}
