#ifndef UTILS_H
#define UTILS_H

#include <cstdint> 
#include <functional>
#include <string>

struct Color
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	Color() : r(0x00), g(0x00), b(0x00), a(0xFF) {}
};

static std::hash<std::string> hashFn;

#endif //UTILS_H
