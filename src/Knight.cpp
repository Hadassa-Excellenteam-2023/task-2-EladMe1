#include "..\include\Knight.h"
#include <iostream>

Knight::Knight(bool isWhite)
	:Piece(isWhite)
{
}

bool Knight::isAllwoedMove(const Pos& source, const Pos& des) const
{
	auto row = std::abs(source.x - des.x);
	auto col = std::abs(source.y - des.y);

	return (row == 2 && col == 1) || (row == 1 && col == 2);
}

PlayerChess Knight::getPlayerChess() const
{
	return PlayerChess::KNIGHT;
}
