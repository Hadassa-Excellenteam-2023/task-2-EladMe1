#pragma once

#include "Piece.h"
#include "marcos.h"

class Rook : public Piece {

public:
	Rook(bool isWhite);
	bool isAllwoedMove(const Pos& source, const Pos& des) const override;
	PlayerChess getPlayerChess() const override;

private:

};