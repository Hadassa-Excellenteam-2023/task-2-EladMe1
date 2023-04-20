#pragma once

const int ROWS = 8;
const int COLS = 8;

struct Dir {
	int x;
	int y;
};

struct Pos {
	int x;
	int y;

	bool operator==(const Pos& other) const {
		return x == other.x && y == other.y;
	}

	bool operator!=(const Pos& other) const {
		return {x != other.x || y != other.y };
	}

	Pos operator+(const Pos& other) const {
		return { x + other.x, y + other.y };
	}

	Pos& operator+=(const Pos& other) {
		*this = *this + other;
		return *this;
	}

	Pos operator+(const Dir& dir) const {
		return { x + dir.x, y + dir.y };
	}

	Pos& operator+=(const Dir& dir) {
		*this = *this + dir;
		return *this;
	}
};

enum PlayerChess {
	KING,
	QUEEN,
	ROOK,
	BISHOP,
	KNIGHT,
	PAWN	
};

const Pos DEFUALT_LOCATION = { -1,-1 };