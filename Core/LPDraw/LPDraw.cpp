#include "LPDraw.h"
#include <iostream>

void LPD_API DrawPixel(std::fstream& out, const std::string& ext, const std::string& header, const Pixel& c) {
	if (ext == "pbm" && header == PPM_ASC)
		out << (c.r == 255 ? '1' : '0') << " ";

	else if (ext == "pbm" && header == PBM_BIN)
		out << (c.r == 255 ? (char)1 : char(0));

	else if (ext == "pgm" && header == PGM_ASC)
		out << (int)c.r << " ";

	else if (ext == "pgm" && header == PGM_BIN)
		out << (char)c.r;

	else if (ext == "ppm" && header == PPM_ASC)
		out << (int)c.r << " " << (int)c.g << " " << (int)c.b << " ";

	else if (ext == "ppm" && header == PPM_BIN)
		out << (char)c.r << (char)c.g << (char)c.b;

	else
		std::cerr << "Format or Magic Number error.\n";
}

void DrawFromArray(const std::string& filename, const std::string& header, int width, int height, const Pixel* data, UINT l) {
	std::string ext = filename.substr(filename.size() - 3, 3);
	std::fstream out(filename, std::ios::out | std::ios::binary);
	out << header << "\n" << width << " " << height << "\n255\n";
	for (UINT i = 0; i < l - 1; i++) {
		DrawPixel(out, ext, header, data[i]);
	}
}

void DrawFromRange(const std::string& filename, const std::string& header, int width, int height, const Pixel* begin, const Pixel* end) {
	std::string ext = filename.substr(filename.size() - 3, 3);
	std::fstream out(filename, std::ios::out | std::ios::binary);
	out << header << "\n" << width << " " << height << "\n255\n";
	for (const Pixel* iter = begin; iter < end; iter++) {
		DrawPixel(out, ext, header, *iter);
	}
}