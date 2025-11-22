#pragma once
#include "entities.h"

Pixel LPS_API Code2Pixel(Code c);
Pixel LPS_API InvertColor(const Pixel& c);
Pixel LPS_API ReduceColor(const Pixel& c, float r);
Pixel LPS_API EnhanceColor(const Pixel& c, float r);
Pixel LPS_API SaturateColor(const Pixel& c, float r);
Pixel LPS_API BrightenColor(const Pixel& c, float r);
Pixel LPS_API DarkenColor(const Pixel& c, float r);
Pixel LPS_API MixColors(const Pixel& c1, const Pixel& c2, float r);
Pixel LPS_API GreyScale(const Pixel& c);
Pixel LPS_API GreyScalePixel(UINT g);
Pixel LPS_API BlackWhite(const Pixel& c, USINT threshold);
Pixel LPS_API InvertGreyScale(const Pixel& c);
Pixel LPS_API RedChannel(const Pixel& c);
Pixel LPS_API GreenChannel(const Pixel& c);
Pixel LPS_API BlueChannel(const Pixel& c);
Pixel LPS_API RedChannelGreyScale(const Pixel& c);
Pixel LPS_API GreenChannelGreyScale(const Pixel& c);
Pixel LPS_API BlueChannelGreyScale(const Pixel& c);
Pixel LPS_API AlphaBlend(const Pixel& c1, const Pixel& c2, float alpha);
Pixel LPS_API SepiaTone(const Pixel& c);
Code LPS_API Pixel2Code(const Pixel& c);
float LPS_API Saturation(const Pixel& c);
float LPS_API Brightness(const Pixel& c);
short LPS_API Hue(const Pixel& c);