#include "DrawingUtilities.h"

Position2DIter& Position2DIter::operator++() {
	if (x < DrawUtilWidth)x++;
	if (x == DrawUtilWidth)x = 0, y++;
	return *this;
}

bool Position2DIter::operator<(const Position2DIter& pos)const {
	if (y != pos.y)return y < pos.y;
	else return x < pos.x;
}

Pixel PureColor::operator()(const Position2DIter& vpos)const {
	return c;
}

Pixel xGradientColor::operator()(const Position2DIter& vpos)const {
	if (vpos.x >= xbegin && vpos.x < xend && vpos.y >= ybegin && vpos.y < yend)
		return MixColors(c1, c2, (float)vpos.x / (xend - xbegin));
	else
		return c1;
}

Pixel yGradientColor::operator()(const Position2DIter& vpos)const {
	if (vpos.x >= xbegin && vpos.x < xend && vpos.y >= ybegin && vpos.y < yend)
		return MixColors(c1, c2, (float)vpos.y / (yend - ybegin));
	else
		return c1;
}

Pixel dGradientColor::operator()(const Position2DIter& vpos)const {
	if (vpos.x >= xbegin && vpos.x < xend && vpos.y >= ybegin && vpos.y < yend) {
		return MixColors(c1, c2, (float)(vpos.x + vpos.y) / (xend - xbegin + yend - ybegin));
	}
	else
		return c1;
}

Pixel CheckerBoard::operator()(const Position2DIter& vpos)const {
	UINT width = xend - xbegin, height = yend - ybegin;
	if (vpos.x >= xbegin && vpos.x < xend && vpos.y >= ybegin && vpos.y < yend) {
		if (((vpos.x + offsetX) / wgrid + (vpos.y + offsetY) / hgrid) & 1)
			return c1;
		else
			return c2;
	}
	else
		return c1;
}

void SetDrawUtilWidth(UINT p) {
	DrawUtilWidth = p;
}

void SetDrawUtilHeight(UINT p) {
	DrawUtilHeight = p;
}

void SetDrawUtilBoard(UINT xp, UINT yp) {
	DrawUtilWidth = xp;
	DrawUtilHeight = yp;
}