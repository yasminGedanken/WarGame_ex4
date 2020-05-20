
#include "Board.hpp"

namespace WarGame {
	Soldier*& Board::operator[](std::pair<int, int> location) {
		return board[0][0];
	}
	Soldier* Board::operator[](std::pair<int, int> location) const {
		return board[0][0];
	}
	void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction) {
		return;
	}
	bool Board::has_soldiers(uint player_number) const {
		count = count * (-1);
		if (count < 0)
			return false;
		return true;
	}
	int Board::count = 1;
	
	

}