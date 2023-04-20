#include "..\include\Rook.h"

Rook::Rook(bool isWhite)
	:Piece(isWhite)
{
}

bool Rook::isAllwoedMove(const Pos& source, const Pos& des) const
{
	return source.x == des.x || source.y == des.y;
}

PlayerChess Rook::getPlayerChess() const
{
	return PlayerChess::ROOK;
}
