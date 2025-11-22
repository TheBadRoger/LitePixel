#pragma once
#ifdef PROJ_LPDRAW
#define LPD_API _declspec(dllexport)
#else
#define LPD_API _declspec(dllimport)
#endif

#include "LPShader.h"
#include <fstream>
#include <cstring>

constexpr auto PPM_BIN = "P6";
constexpr auto PPM_ASC = "P3";
constexpr auto PGM_BIN = "P5";
constexpr auto PGM_ASC = "P2";
constexpr auto PBM_BIN = "P4";
constexpr auto PBM_ASC = "P1";

void LPD_API DrawPixel(std::fstream& out, const std::string& ext, const std::string& header, const Pixel& c);

void LPD_API DrawFromArray(const std::string& filename, const std::string& header, int width, int height, const Pixel* data, UINT l);

void LPD_API DrawFromRange(const std::string& filename, const std::string& header, int width, int height, const Pixel* begin, const Pixel* end);

template <class Draw, typename Type>
void ApplyDrawer(const std::string& filename, const std::string& header, int width, int height,const Draw& drawer, Type begin, Type end) {
	std::string ext = filename.substr(filename.size() - 3, 3);
	std::fstream out(filename, std::ios::out | std::ios::binary);
	out << header << "\n" << width << " " << height << "\n255\n";
	for (Type iter = begin; iter < end; ++iter) {
		DrawPixel(out, ext, header, drawer(iter));
	}
}