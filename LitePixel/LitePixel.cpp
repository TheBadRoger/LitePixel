#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
#include "LPDraw.h"
using namespace std;

struct exampleIter {
	int x, y;
	exampleIter(int _x, int _y) :x(_x), y(_y) {}
	exampleIter& operator++() {
		x++;
		if (x >= 960)y++, x = 0;
		return *this;
	}
	bool operator<(const exampleIter& b)const {
		return x + y < b.x + b.y;
	}
};

struct exampleDraw {
	Pixel operator()(exampleIter p)const {
		if ((p.x / 60 + p.y / 60) & 1)
			return Pixel(White);
		else
			return Pixel(Black);
	}
};

int main()
{
	ApplyDrawer("test.ppm", "P6", 16 * 60, 9 * 60, exampleDraw(), exampleIter(0, 0), exampleIter(960, 540));
}