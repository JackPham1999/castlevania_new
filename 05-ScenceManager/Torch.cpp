#include "Torch.h"
#include"Simon.h"

CTorch::CTorch(float x, float y/*,int id*/) :CGameObject()
{
	SetState(TORCH_STATE_EXIST);
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

}

void CTorch::Render()
{
	int ani;
	if (state == TORCH_STATE_NOT_EXIST)
	{
		ani = TORCH_ANI_NOT_EXIST;
	}
	else
		ani = TORCH_ANI_EXIST;
	animation_set->at(ani)->Render(x, y);
	//animation_set->at(id)->Render(x, y);
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