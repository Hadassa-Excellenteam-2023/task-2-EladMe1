#pragma once

#include <memory>
#include <iostream>
#include "marcos.h"
#include "Piece.h"
#include "Facoty.h"



class Board {
public:
    Board(const std::string& board_string);
    int returnResponse(const std::string& move);

private:
   bool m_whiteMoveNext;
   std::unique_ptr<Piece> m_board[ROWS][COLS];
   Pos m_posKing[2];

   void bootBoard();
   bool isEmpty(const Pos src) const;
   bool isRival(const Pos src) const;
   bool currentPlayer(const Pos src) const;
   void update(const Pos src, const Pos des);
   bool wayBlock(const Pos& source, const Pos& dest) const;
   bool isKing(const Pos&pos) const;
   bool PossibleChess(const Pos&src, const Pos&des);
   bool hasMate() const;
   std::vector<Pos> getOpponentMoves() const;
   bool isPawn(const Pos& pos) const;
};