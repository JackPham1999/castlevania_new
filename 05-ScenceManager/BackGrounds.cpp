#include "BackGrounds.h"

void CBackGrounds::Render() {
	animation_set->at(0)->Render(x, y);
}

void CBackGrounds::GetBoundingBox(float& l, float& t, float& r, float& b) {
	//ignore backgrounds
	l = t = r = b = 0;
}