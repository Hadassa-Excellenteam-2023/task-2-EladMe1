#include "..\include\Bishop.h"
#include <iostream>

Bishop::Bishop(bool isWhite)
	:Piece(isWhite)
{
}

bool Bishop::isAllwoedMove(const Pos& source, const Pos& des) const
{
	auto row = std::abs(des.x - source.x);
	auto col = std::abs(des.y - source.y);

	return row == col;
}

PlayerChess Bishop::getPlayerChess() const
{
	return PlayerChess::BISHOP;
}
