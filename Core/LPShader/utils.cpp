#include "utils.h"
#include <algorithm>

Pixel Code2Pixel(Code c) {
	return Pixel(
		c >> 16 & 0xFF, c >> 8 & 0xFF, c & 0xFF);
}

Pixel InvertColor(const Pixel& c) {
	return Pixel(255 - c.r, 255 - c.g, 255 - c.b);
}

Pixel ReduceColor(const Pixel& c, float r) {
	return Pixel(c.r * r, c.g * r, c.b * r);
}

Pixel EnhanceColor(const Pixel& c, float r) {
	return Pixel(c.r + (255 - c.r) * r, c.g + (255 - c.g) * r, c.b + (255 - c.b) * r);
}

Pixel SaturateColor(const Pixel& c, float r) {
	USINT gray = USINT(0.299 * c.r + 0.587 * c.g + 0.114 * c.b);
	return Pixel(
		gray + (c.r - gray) * (1.0f + r),
		gray + (c.g - gray) * (1.0f + r),
		gray + (c.b - gray) * (1.0f + r)
	);
}

Pixel BrightenColor(const Pixel& c, float r) {
	return Pixel(
		std::min(c.r + 255 * r, 255.0f),
		std::min(c.g + 255 * r, 255.0f),
		std::min(c.b + 255 * r, 255.0f)
	);
}

Pixel DarkenColor(const Pixel& c, float r) {
	return Pixel(
		std::max((short)c.r - 255 * r, 0.0f),
		std::max((short)c.g - 255 * r, 0.0f),
		std::max((short)c.b - 255 * r, 0.0f)
	);
}

Pixel MixColors(const Pixel& c1, const Pixel& c2, float r) {
	return Pixel(
		c1.r * (1.0f - r) + c2.r * r,
		c1.g * (1.0f - r) + c2.g * r,
		c1.b * (1.0f - r) + c2.b * r
	);
}

Pixel GreyScale(const Pixel& c) {
	return Pixel(
		0.299f * c.r + 0.587f * c.g + 0.114f * c.b,
		0.299f * c.r + 0.587f * c.g + 0.114f * c.b,
		0.299f * c.r + 0.587f * c.g + 0.114f * c.b
	);
}

Pixel LPS_API GreyScalePixel(UINT g) {
	return Pixel(g, g, g);
}

Pixel BlackWhite(const Pixel& c, USINT threshold) {
	USINT gray = USINT(0.299f * c.r + 0.587f * c.g + 0.114f * c.b);
	if (gray >= threshold)
		return Pixel(255, 255, 255);
	else
		return Pixel(0, 0, 0);
}

Pixel RedChannel(const Pixel& c) {
	return Pixel(c.r, 0, 0);
}

Pixel GreenChannel(const Pixel& c) {
	return Pixel(0, c.g, 0);
}

Pixel BlueChannel(const Pixel& c) {
	return Pixel(0, 0, c.b);
}

Pixel RedChannelGreyScale(const Pixel& c) {
	return Pixel(c.r, c.r, c.r);
}

Pixel GreenChannelGreyScale(const Pixel& c) {
	return Pixel(c.g, c.g, c.g);
}

Pixel BlueChannelGreyScale(const Pixel& c) {
	return Pixel(c.b, c.b, c.b);
}

Pixel InvertGreyScale(const Pixel& c) {
	USINT gray = USINT(0.299f * c.r + 0.587f * c.g + 0.114f * c.b);
	USINT invgray = 255 - gray;
	return Pixel(invgray, invgray, invgray);
}

Pixel AlphaBlend(const Pixel& c1, const Pixel& c2, float alpha) {
	return Pixel(
		c1.r * (1.0f - alpha) + c2.r * alpha,
		c1.g * (1.0f - alpha) + c2.g * alpha,
		c1.b * (1.0f - alpha) + c2.b * alpha
	);
}

Pixel SepiaTone(const Pixel& c) {
	return Pixel(
		std::min(0.393f * c.r + 0.769f * c.g + 0.189f * c.b, 255.0f),
		std::min(0.349f * c.r + 0.686f * c.g + 0.168f * c.b, 255.0f),
		std::min(0.272f * c.r + 0.534f * c.g + 0.131f * c.b, 255.0f)
	);
}

UINT Pixel2Code(const Pixel& c) {
	return c.r << 16 | c.g << 8 | c.b;
}

float Saturation(const Pixel& c) {
	USINT maxc = std::max({ c.r, c.g, c.b });
	USINT minc = std::min({ c.r, c.g, c.b });
	if (maxc == 0) return 0;
	return (maxc - minc) * 255 / maxc;
}

float Brightness(const Pixel& c) {
	return (std::max({ c.r, c.g, c.b }) + std::min({ c.r, c.g, c.b })) / 2;
}

short Hue(const Pixel& c) {
	UINT maxc = std::max({ c.r, c.g, c.b });
	UINT minc = std::min({ c.r, c.g, c.b });

	if (maxc == minc) return 0;

	short hue = 0;
	if (maxc == c.r)
		hue = 60 * (short(c.g) - short(c.b)) / (short(maxc) - short(minc));

	else if (maxc == c.g)
		hue = 120 + 60 * (short(c.b) - short(c.r)) / (short(maxc) - short(minc));

	else
		hue = 240 + 60 * (short(c.r) - short(c.g)) / (short(maxc) - short(minc));

	if (hue < 0) hue += 360;
	return hue;
}