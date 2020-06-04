#include "Paramedic.hpp"


void Paramedic::act(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location) {
	
		for(int i=location.first-1;i< location.first+2;i++)
			for (int j = location.second - 1; j < location.second + 2; j++) {
				if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size()) {
					if (board[i][j] != nullptr && board[i][j]->getPlayer() == board[location.first][location.second]->getPlayer()
						&& board[i][j] != board[location.first][location.second]) {
						int life = board[i][j]->getHP();
						int fullLife = board[i][j]->getFullHP();
						board[i][j]->setHP(fullLife - life);

					}
				}
			}
	
		return;
	}
