// Dll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <cstdint>

#define CHECK printf("REACHED %s L%d\n", __FILE__, __LINE__);getchar();

struct p2
{
	float x{42},y{2};
	p2(){}
	p2(float x, float y):x(x),y(y){};
};

struct p2POD
{
	float x{42},y{2};
	//p2(){}
};

struct p3
{
	float x{42},y{2},z{3};
	p3(){}
};

extern "C" __declspec(dllexport) p2 getVec2()
{
	p2 val;
	return val;
}

extern "C" __declspec(dllexport) void addVec2(p2& result, const p2& a, const p2& b)
{
	p2 val = p2(a.x+b.x, a.y+b.y);
	result = val;
}

extern "C" __declspec(dllexport) void getVec2ref(p2& val)
{
	val = p2();
}

extern "C" __declspec(dllexport) p2POD getVec2fix()
{
	p2 val;
	return *reinterpret_cast<p2POD*>(&val);
}

extern "C" __declspec(dllexport) p3 getVec3()
{
	p3 val;
	return val;
}