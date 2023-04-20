#pragma once

#include "Piece.h"
#include "marcos.h"

class King : public Piece {

public:
	King(bool isWhite);
	bool isAllwoedMove(const Pos& source, const Pos& des) const override;
	PlayerChess getPlayerChess() const override;

private:
};