#pragma once

#include "Piece.h"
#include "marcos.h"

class Knight : public Piece {

public:
	Knight(bool isWhite);
	bool isAllwoedMove(const Pos& source, const Pos& des) const override;
	PlayerChess getPlayerChess() const override;

private:

};