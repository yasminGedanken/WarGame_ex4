#include "SniperCommander.hpp"


void SniperCommander::act(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location) {
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
	board[maxHP.first][maxHP.second]->setHP(-100);
	if (board[maxHP.first][maxHP.second]->getHP() <= 0) board[maxHP.first][maxHP.second] = nullptr;
	actSoldier(board, location);
		return;
	}

void SniperCommander::actSoldier(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location) {
	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] != nullptr) {
				Sniper* s = dynamic_cast<Sniper*>(board[i][j]);
				SniperCommander* c = dynamic_cast<SniperCommander*>(board[i][j]);
				if (s && !c)
					if (board[i][j]->getPlayer() == board[location.first][location.second]->getPlayer())
						board[i][j]->act(board, { i,j });
			}
		}
}