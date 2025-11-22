#pragma once
#include "LPShader.h"
#include "LPDraw.h"

UINT DrawUtilWidth, DrawUtilHeight;

struct LPD_API Position2DIter {
	UINT x, y;
	Position2DIter& operator++();
	bool operator<(const Position2DIter& pos)const;
	Position2DIter(UINT tx, UINT ty) : x(tx), y(ty) {};
};

struct LPD_API PureColor {
	Pixel c;
	Pixel operator()(const Position2DIter& vpos)const;
	PureColor(const Pixel& cr) :c(cr) {};
};

struct LPD_API xGradientColor {
	Pixel c1, c2;
	UINT xbegin, xend, ybegin, yend;
	Pixel operator()(const Position2DIter& vpos)const;
	xGradientColor(const Pixel& cr1, const Pixel& cr2, UINT xb, UINT xe, UINT yb, UINT ye) :c1(cr1), c2(cr2), xbegin(xb), xend(xe), ybegin(yb), yend(ye) {};
};

struct LPD_API yGradientColor {
	Pixel c1, c2;
	UINT xbegin, xend, ybegin, yend;
	Pixel operator()(const Position2DIter& vpos)const;
	yGradientColor(const Pixel& cr1, const Pixel& cr2, UINT xb, UINT xe, UINT yb, UINT ye) :c1(cr1), c2(cr2), xbegin(xb), xend(xe), ybegin(yb), yend(ye) {};
};

struct LPD_API dGradientColor {
	Pixel c1, c2;
	UINT xbegin, xend, ybegin, yend;
	Pixel operator()(const Position2DIter& vpos)const;
	dGradientColor(const Pixel& cr1, const Pixel& cr2, UINT xb, UINT xe, UINT yb, UINT ye) :c1(cr1), c2(cr2), xbegin(xb), xend(xe), ybegin(yb), yend(ye) {};
};

struct LPD_API CheckerBoard {
	Pixel c1, c2;
	UINT xbegin, xend, ybegin, yend;
	UINT hgrid, wgrid;
	UINT offsetX, offsetY;
	Pixel operator()(const Position2DIter& vpos)const;
	CheckerBoard(const Pixel& cr1, const Pixel& cr2, UINT xb, UINT xe, UINT yb, UINT ye, UINT hg, UINT wg, UINT oX, UINT oY) :c1(cr1), c2(cr2), xbegin(xb), xend(xe), ybegin(yb), yend(ye), hgrid(hg), wgrid(wg), offsetX(oX), offsetY(oY) {};
};

void LPD_API SetDrawUtilWidth(UINT p);
void LPD_API SetDrawUtilHeight(UINT p);
void LPD_API SetDrawUtilBoard(UINT xp, UINT yp);