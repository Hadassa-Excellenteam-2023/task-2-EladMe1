#pragma once

#include "Piece.h"
#include "marcos.h"

class Pawn : public Piece {

public:
	Pawn(bool isWhite);
	bool isAllwoedMove(const Pos& source, const Pos& des) const override;
	void setFirstMove();
	PlayerChess getPlayerChess() const override;

private:
	bool m_isFirstMove = true;

};