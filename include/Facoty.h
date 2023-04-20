#pragma once
#include <memory>
#include <functional>
#include <map>


#include "marcos.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Pawn.h"
#include "Knight.h"

class Factory {
public:

    std::unique_ptr<Piece> GenerateQueen(bool isWhite) {
        return std::make_unique<Queen>(isWhite);
    }

    std::unique_ptr<Piece> GenerateKing(bool isWhite) {
        return std::make_unique<King>(isWhite);
    }

    std::unique_ptr<Piece> GenerateRook(bool isWhite) {
        return std::make_unique<Rook>(isWhite);
    }

    std::unique_ptr<Piece> GenerateKnight(bool isWhite) {
        return std::make_unique<Knight>(isWhite);
    }

    std::unique_ptr<Piece> GenerateBishop(bool isWhite) {
        return std::make_unique<Bishop>(isWhite);
    }

    std::unique_ptr<Piece> GeneratePawn(bool isWhite) {
        return std::make_unique<Pawn>(isWhite);
    }

    Factory() {
        m_PieceGeneraor['Q'] = std::bind(&Factory::GenerateQueen, this, std::placeholders::_1);
        m_PieceGeneraor['K'] = std::bind(&Factory::GenerateKing, this, std::placeholders::_1);;
        m_PieceGeneraor['R'] = std::bind(&Factory::GenerateRook, this, std::placeholders::_1);;
        m_PieceGeneraor['N'] = std::bind(&Factory::GenerateKnight, this, std::placeholders::_1);;
        m_PieceGeneraor['B'] = std::bind(&Factory::GenerateBishop, this, std::placeholders::_1);;
        m_PieceGeneraor['P'] = std::bind(&Factory::GeneratePawn, this, std::placeholders::_1);;
    }

    std::unique_ptr<Piece> GeneratePiece(char piece) {
        bool is_upper = std::isupper(piece);
        std::map<char, PieceGeneraor>::iterator iter = m_PieceGeneraor.find(std::toupper(piece));
        return(iter != m_PieceGeneraor.end()) ? iter->second(is_upper) : nullptr;
    }

private:
    typedef std::function<std::unique_ptr<Piece>(bool)> PieceGeneraor;
    std::map<char, PieceGeneraor> m_PieceGeneraor;

};