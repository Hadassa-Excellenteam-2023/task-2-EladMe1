#pragma once

#include "Piece.h"
#include "marcos.h"

class Queen : public Piece {

public:
	Queen(bool isWhite);
	bool isAllwoedMove(const Pos& source, const Pos& des) const override;
	PlayerChess getPlayerChess() const override;

private:
};