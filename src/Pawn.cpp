#include "..\include\Pawn.h"


Pawn::Pawn(bool isWhite)
	:Piece(isWhite)
{
}

bool Pawn::isAllwoedMove(const Pos& source, const Pos& des) const
{
    if (m_isFirstMove)
        if (this->getColor())
            return (des.x == source.x + 2 || des.x == source.x + 1) && des.y == source.y;
        else
            return (des.x == source.x - 2 || des.x == source.x - 1) && des.y == source.y;
    else
        if (this->getColor())
            return des.x == source.x + 1 && des.y == source.y;
        else
            return des.x == source.x - 1 && des.y == source.y;
}

void Pawn::setFirstMove() {
    m_isFirstMove = false;
}

PlayerChess Pawn::getPlayerChess() const
{
    return PlayerChess::PAWN;
}
