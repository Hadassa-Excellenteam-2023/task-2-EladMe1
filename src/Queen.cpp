#include "..\include\Queen.h"
#include<iostream>

Queen::Queen(bool isWhite)
	:Piece(isWhite)
{
}

bool Queen::isAllwoedMove(const Pos& source, const Pos& des) const
{
	return (source.x == des.x || source.y == des.y) ||
		(abs(des.x - source.x) == abs(des.y - source.y));
}

PlayerChess Queen::getPlayerChess() const
{
	return PlayerChess::QUEEN;
}
