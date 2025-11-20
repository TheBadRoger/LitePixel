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

template <typename Type>
void LPD_API DrawFromArray(const std::string& filename, const std::string& header, int width, int height, const Type* data, UINT l);

template <typename Type>
void LPD_API DrawFromRange(const std::string& filename, const std::string& header, int width, int height, const Type* begin, const Type* end);

template <class Drawer, typename Type>
void LPD_API ApplyDrawer(const std::string& filename, const std::string& header, int width, int height, Drawer drawer, Type iter, Type begin, Type end);