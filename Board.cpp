#include <exception>
#include "Board.hpp"

namespace WarGame {
	Soldier*& Board::operator[](std::pair<int, int> location) {

		if (location.first <0 || location.first>=board.size() || location.second <0 || location.second >=board[0].size())
			throw std::invalid_argument("out_of_range");

	/*	if(*board[location.first][location.second]!=nullptr)
			throw std::invalid_argument("not goood locatin");*/
	
			
		return board[location.first][location.second];
		
	}

	Soldier* Board::operator[](std::pair<int, int> location) const {
		if (location.first <0 || location.first>=board.size() || location.second <0 || location.second >=board[0].size())
			throw std::invalid_argument("out_of_range");

		if (board[location.first][location.second] == nullptr)
			throw std::invalid_argument("not good location");
		
		return board[location.first][location.second];
	}

	//  * There is no soldier in the source location (i.e., the soldier pointer is null);
   //  * The soldier in the source location belongs to the other player.
   //  * There is already another soldier (of this or the other player) in the target location.
	void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction) {

		if (source.first <0 || source.first>= board.size() || source.second <0 || source.second >= board[0].size())
			throw std::invalid_argument("out_of_range");

		if (board[source.first][source.second] == nullptr)
			throw std::invalid_argument("not good location");

		if (board[source.first][source.second]->getPlayer() != player_number)
			throw std::invalid_argument("not belongs to this player");

		if(!canMove(source, direction)) //check if he can move
			throw std::invalid_argument("bad move!");

		moveSoldier(source, direction); //move the soldier
		
		return;
	}

	bool Board::canMove(std::pair<int, int> source, MoveDIR direction) {
		bool ans = false;
		switch (direction)
		{
		case Up:
			if ( source.first+1 < board.size() && (board[source.first + 1][source.second] == nullptr))
				ans = true;
			break;
		case Down:
			if (source.first - 1 >=0 && (board[source.first - 1][source.second] == nullptr))
				ans = true;
			break;
		case Right:
			if (source.second + 1 < board[0].size() && (board[source.first][source.second+1] == nullptr))
				ans = true;
			break;
		case Left:
			if (source.second - 1 >= 0 && (board[source.first][source.second - 1] == nullptr))
				ans = true;
			break;
		
		}
		return ans;
	}

	void Board::moveSoldier(std::pair<int, int> source, MoveDIR direction) {
		std::pair<int, int> destination;
		switch (direction)
		{
		case Up:
			destination.first = source.first + 1; destination.second = source.second;
			board[destination.first][destination.second] = board[source.first][source.second];
			board[source.first][source.second] = nullptr;
			board[destination.first][destination.second]->act(board, destination);
			break;
		case Down:
			destination.first = source.first - 1; destination.second = source.second;
			board[destination.first][destination.second] = board[source.first][source.second];
			board[source.first][source.second] = nullptr;
			board[destination.first][destination.second]->act(board, destination);
			break;
		case Right:
			destination.first = source.first; destination.second = source.second +1;
			board[destination.first][destination.second ] = board[source.first][source.second];
			board[source.first][source.second] = nullptr;
			board[destination.first][destination.second]->act(board, destination);
			break;
		case Left:
			destination.first = source.first; destination.second = source.second - 1;
			board[destination.first][destination.second] = board[source.first][source.second];
			board[source.first][source.second] = nullptr;
			board[destination.first][destination.second]->act(board, destination);
			break;
		}

		return;
	}

	bool Board::has_soldiers(uint player_number) const {
	
		bool ans = false;
		for(int i=0; i< board.size(); i++)
			for(int j=0; j< board[i].size(); j++)
				if (board[i][j]!=nullptr && board[i][j]->getPlayer() == player_number) {
					ans = true;
					break;
				}

		return ans;
	}
	
	
	

}