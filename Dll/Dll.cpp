// Dll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <cstdint>

#define CHECK printf("REACHED %s L%d\n", __FILE__, __LINE__);getchar();

struct p2
{
	uint64_t x{42},y{2};
	p2(){}
};

struct p3
{
	uint64_t x{42},y{2},z{3};
	p3(){}
};

extern "C" __declspec(dllexport) p2 getVec2()
{
	return p2();
}

extern "C" __declspec(dllexport) p3 getVec3()
{
	return p3();
}