#pragma once

#include "marcos.h"

class Piece {
public:
	Piece(bool isWhite);
	virtual ~Piece() = default;
	virtual PlayerChess getPlayerChess() const = 0;
	virtual bool isAllwoedMove(const Pos& pos,const Pos& des) const = 0;
	bool getColor() const;
private:
	bool m_color;
};