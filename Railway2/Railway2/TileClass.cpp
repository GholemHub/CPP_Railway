#include "TileClass.h"
#include <iostream>
Tile::Tile()
{
}

Tile::Tile(TileState State)
{
	Backgrond = new Image(L"tileHelm.png");
}
