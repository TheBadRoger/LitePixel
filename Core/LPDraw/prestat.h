#pragma once

#ifdef PROJ_LPDRAW
#define LPD_API _declspec(dllexport)
#else
#define LPD_API _declspec(dllimport)
#endif

constexpr auto LPD_API P6_FORMAT = "P6";
constexpr auto LPD_API P3_FORMAT = "P3";

typedef unsigned int UINT, Code;
typedef unsigned short USINT, Channel;

constexpr LPD_API Code Black = 0x000000;
constexpr LPD_API Code Red = 0xFF0000;
constexpr LPD_API Code Green = 0x00FF00;
constexpr LPD_API Code Blue = 0x0000FF;
constexpr LPD_API Code Yellow = 0xFFFF00;
constexpr LPD_API Code Cyan = 0x00FFFF;
constexpr LPD_API Code Magenta = 0xFF00FF;
constexpr LPD_API Code White = 0xFFFFFF;
constexpr LPD_API Code Gray = 0x808080;
constexpr LPD_API Code LightGray = 0xC0C0C0;
constexpr LPD_API Code DarkGray = 0x404040;
constexpr LPD_API Code Orange = 0xFFA500;
constexpr LPD_API Code Purple = 0x800080;
constexpr LPD_API Code Brown = 0xA52A2A;
constexpr LPD_API Code Pink = 0xFFC0CB;
constexpr LPD_API Code Lime = 0x00FF00;
constexpr LPD_API Code Navy = 0x000080;
constexpr LPD_API Code Teal = 0x008080;
constexpr LPD_API Code Olive = 0x808000;
constexpr LPD_API Code Maroon = 0x800000;
constexpr LPD_API Code Silver = 0xC0C0C0;
constexpr LPD_API Code Gold = 0xFFD700;