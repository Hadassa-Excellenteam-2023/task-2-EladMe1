#pragma once

#include "Piece.h"
#include "marcos.h"

class Bishop : public Piece {

public:
	Bishop(bool isWhite);
	bool isAllwoedMove(const Pos& source, const Pos& des) const override;
	PlayerChess getPlayerChess() const override;

private:
};