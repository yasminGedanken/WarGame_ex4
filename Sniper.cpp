#include "Sniper.hpp"

void Sniper::act(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location) {
	int max = 0;
	std::pair<int, int> maxHP;
	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] != nullptr &&
				board[i][j]->getPlayer() != board[location.first][location.second]->getPlayer())
				if (board[i][j]->getHP() > max) {
					max = board[i][j]->getHP();
					maxHP.first = i; maxHP.second = j;
			}
		}
	board[maxHP.first][maxHP.second]->setHP(-50);
	if (board[maxHP.first][maxHP.second]->getHP() <= 0) board[maxHP.first][maxHP.second] = nullptr;
		return;
	}
