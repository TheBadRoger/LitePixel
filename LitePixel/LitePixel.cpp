#include "LPDraw.h"
#include "DrawingUtilities.h"

const int w = 16 * 60;
const int h = 9 * 60;

int main()
{
	SetDrawUtilBoard(w, h);
	ApplyDrawer("test1.ppm", "P6", w, h,
		dGradientColor(Red, Yellow, 0, w, 0, h), Position2DIter(0, 0), Position2DIter(w, h));
}