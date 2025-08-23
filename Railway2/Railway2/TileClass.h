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
	int Id;
	Image* Backgrond;
	TileState State;

public:
	Image* GetBackgrond() {return Backgrond;}
	void SetBackgrond(Image* i) {Backgrond = i;}
	Tile();
	Tile(TileState State);

};