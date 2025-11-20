#pragma once

#ifdef PROJ_LPSHADER
#define LPS_API _declspec(dllexport)
#else
#define LPS_API _declspec(dllimport)
#endif

typedef unsigned int UINT, Code;
typedef unsigned short USINT, Channel;

constexpr Code Black = 0x000000;
constexpr Code Red = 0xFF0000;
constexpr Code Green = 0x00FF00;
constexpr Code Blue = 0x0000FF;
constexpr Code Yellow = 0xFFFF00;
constexpr Code Cyan = 0x00FFFF;
constexpr Code Magenta = 0xFF00FF;
constexpr Code White = 0xFFFFFF;
constexpr Code Gray = 0x808080;
constexpr Code LightGray = 0xC0C0C0;
constexpr Code DarkGray = 0x404040;
constexpr Code Orange = 0xFFA500;
constexpr Code Purple = 0x800080;
constexpr Code Brown = 0xA52A2A;
constexpr Code Pink = 0xFFC0CB;
constexpr Code Lime = 0x00FF00;
constexpr Code Navy = 0x000080;
constexpr Code Teal = 0x008080;
constexpr Code Olive = 0x808000;
constexpr Code Maroon = 0x800000;
constexpr Code Silver = 0xC0C0C0;
constexpr Code Gold = 0xFFD700;