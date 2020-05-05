#include "Torch.h"
#include"Simon.h"

CTorch* CTorch::__instance = NULL;
//CSimon* simon;

CTorch* CTorch::GetInstance()
{
	if (__instance == NULL) __instance = new CTorch();
	return __instance;
}
CTorch* CTorch::SetInstance(CGameObject* obj)
{
	__instance = (CTorch*)obj;
	return __instance;
}


CTorch::CTorch(float x, float y/*,int id*/) :CGameObject()
{
	SetState(TORCH_STATE_EXIST);
	GetPosition(x, y);
	this->x = x;
	this->y = y;
	/*switch (id)
	{
	case ID_WHIPUPGRADE:
		item = GetItem();
		id = 0;
	}*/
}

void CTorch::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	//vector<LPGAMEOBJECT> listObj;
	// Collision logic with items
	//if(state==TORCH_ANI_NOT_EXIST)
	//item->SetPosition(150, 100);
		item->Update(dt, coObjects);////////// có thễ là do update 2 lần vì update chạy trc nên render sau
	///////////////////////////////////// thử ep x,y trong item()
}

void CTorch::Render()
{
	int ani;
	/*if (state == TORCH_STATE_NOT_EXIST)
	{
		ani = TORCH_ANI_NOT_EXIST;
	}
	else
		ani = TORCH_ANI_EXIST;*/
	if (state == TORCH_STATE_EXIST)
	{
		ani = TORCH_ANI_EXIST;
		animation_set->at(ani)->Render(x, y);
		item->SetPosition(x, y);
	}
	else
	{
	////////////////////////////////////// thành công
		//DebugOut(L"\n[DEBUG] into the render item");
		item->SetState(ITEM_STATE_EXIST);
		//item->SetPosition(100, 100);
		item->Render();
	}
	//animation_set->at(id)->Render(x, y);
	//item->SetPosition(150, 100);
	/*item->SetState(ITEM_STATE_EXSIST);
	item->Render();
	RenderBoundingBox();*/
	RenderBoundingBox();
}
void CTorch::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (CSimon::GetInstance()->GetState() == SIMON_STATE_ATTACKING)
	{
		l = x;
		t = y;
		r = x + TORCH_BBOX_WIDTH;
		b = y + TORCH_BBOX_HEIGHT;
	}
	else
		l = t = r = b = 0;
}