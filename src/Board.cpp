#include "..\include\Board.h"

Board::Board(const std::string& boardStr)
	:m_whiteMoveNext(true)
{
	bootBoard();

	Factory factory;
	for (auto i = 0; i < boardStr.size(); ++i) {
		auto row = i / ROWS;
		auto col = i % COLS;
		if (boardStr[i] == 'K')
			m_posKing[1] = { row, col };
		else if (boardStr[i] == 'k')
			m_posKing[0] = { row, col };

		m_board[row][col] = factory.GeneratePiece(boardStr[i]);
	}
}

int Board::returnResponse(const std::string& str)
{
	Pos src = { str[0] - 'a', str[1] - '1' };
	Pos dst = { str[2] - 'a', str[3] - '1' };

	if (isEmpty(src)) 
		return 11;
	if (isRival(src)) 
		return 12;
	if (currentPlayer(dst))
		return 13;
	if (!m_board[src.x][src.y]->isAllwoedMove(src, dst) ||
		wayBlock(src, dst))
		return 21;
	if (PossibleChess(src, dst))
		return 31;

	update(src, dst);

	if (hasMate())
		return 41;

	return 42;
}

void Board::bootBoard()
{
	m_posKing[0] = DEFUALT_LOCATION;
    m_posKing[1] = DEFUALT_LOCATION;

	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
			m_board[row][col] = nullptr;
	}
}

bool Board::isEmpty(const Pos source) const
{
	return m_board[source.x][source.y] == nullptr;
}

bool Board::isRival(const Pos source) const
{
	return m_board[source.x][source.y]->getColor() != m_whiteMoveNext;
}

bool Board::currentPlayer(const Pos source) const
{
	return !isEmpty(source) && !isRival(source);
}

bool Board::wayBlock(const Pos& source, const Pos& des) const
{
	int dx = des.x - source.x;
	int dy = des.y - source.y;

	if (dx != 0 && dy != 0 && std::abs(dx) != std::abs(dy)) {
		return false;
	}

	int x_way = (dx > 0) ? 1 : ((dx < 0) ? -1 : 0);
	int y_way = (dy > 0) ? 1 : ((dy < 0) ? -1 : 0);
	Pos curPos = source;
	curPos.x += x_way;
	curPos.y += y_way;
	while (curPos.x != des.x || curPos.y != des.y) {
		if (!isEmpty(curPos)) {
			return true;
		}
		curPos.x += x_way;
		curPos.y += y_way;
	}
	return false;
}

bool Board::PossibleChess(const Pos& source, const Pos& des) 
{
	auto temp = std::move(m_board[des.x][des.y]);

	m_board[des.x][des.y] = std::move(m_board[source.x][source.y]);

	if (isKing(des))
		m_posKing[m_board[des.x][des.y]->getColor()] = des;

	bool checkMate = hasMate();

	if (isKing(des))
		m_posKing[m_board[des.x][des.y]->getColor()] = source;

	m_board[source.x][source.y] = std::move(m_board[des.x][des.y]);
	m_board[des.x][des.y] = std::move(temp);

	return checkMate;
}

bool Board::isKing(const Pos& pos) const
{
	return m_board[pos.x][pos.y]->getPlayerChess() == PlayerChess::KING;
}

bool Board::hasMate() const
{
	auto opponent = getOpponentMoves();

	for (int i = 0; i < opponent.size(); ++i) {
		if (m_board[opponent[i].x][opponent[i].y]->isAllwoedMove(opponent[i], m_posKing[m_whiteMoveNext]) &&
			!wayBlock(opponent[i], m_posKing[m_whiteMoveNext])) {
			return true;
		}
	}

	return false;

}

std::vector<Pos> Board::getOpponentMoves() const {

	std::vector<Pos> opponent;

	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			Pos Pos = { r, c };
			if (!isEmpty(Pos) && !currentPlayer(Pos)) {
				opponent.push_back(Pos);
			}
		}
	}
	return opponent;
}

void Board::update(const Pos src, const Pos des)
{
	if (isKing(src))
		m_posKing[m_board[src.x][src.y]->getColor()] = des;
	if (isPawn(src))
	{
		Pawn* pwan = dynamic_cast<Pawn*>(m_board[src.x][src.y].get());
		pwan->setFirstMove();
	}
		
	m_board[des.x][des.y] = std::move(m_board[src.x][src.y]);
	m_board[src.x][src.y] = nullptr;
	m_whiteMoveNext = !m_whiteMoveNext;
}

bool Board::isPawn(const Pos& pos) const {
	return m_board[pos.x][pos.y]->getPlayerChess() == PlayerChess::PAWN;
}
