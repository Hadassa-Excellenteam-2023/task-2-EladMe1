#include "..\include\King.h"
#include <iostream>

King::King(bool isWhite)
	:Piece(isWhite)
{
}

bool King::isAllwoedMove(const Pos& source, const Pos& des) const
{
    auto row = std::abs(des.x - source.x);
    auto col = std::abs(des.y - source.y);

    return (row == 0 && col == 0) ? false : ((row <= 1 && col <= 1) ? true : false);
}

PlayerChess King::getPlayerChess() const
{
    return PlayerChess::KING;
}
