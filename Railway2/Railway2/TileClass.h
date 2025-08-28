#pragma once
#include <windows.h>
#include <objidl.h>     // needed sometimes
#include "TileState.h"     // needed sometimes
#include <gdiplus.h>



#pragma comment (lib, "gdiplus.lib")

using namespace Gdiplus;
using namespace std;

class Tile {
private:
	int Id{};
	TileState State{Empty};

public:
	~Tile()
	{}

	Tile();
	Tile(TileState State);
};
