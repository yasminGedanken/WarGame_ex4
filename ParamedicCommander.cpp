#include "ParamedicCommander.hpp"

void ParamedicCommander::act(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location) {
	if (location.first + 1 < board.size() && board[location.first + 1][location.second] != nullptr
		&& board[location.first + 1][location.second]->getPlayer() == board[location.first][location.second]->getPlayer())
	{
		int life = board[location.first + 1][location.second]->getHP();
		int fullLife = board[location.first + 1][location.second]->getFullHP();
		board[location.first + 1][location.second]->setHP(fullLife - life);
	}

	if (location.first - 1 >= 0 && board[location.first - 1][location.second] != nullptr
		&& board[location.first - 1][location.second]->getPlayer() == board[location.first][location.second]->getPlayer())
	{
		int life = board[location.first - 1][location.second]->getHP();
		int fullLife = board[location.first - 1][location.second]->getFullHP();
		board[location.first - 1][location.second]->setHP(fullLife - life);
	}

	if (location.second + 1 < board[0].size() && board[location.first][location.second + 1] != nullptr
		&& board[location.first][location.second + 1]->getPlayer() == board[location.first][location.second]->getPlayer())
	{
		int life = board[location.first][location.second + 1]->getHP();
		int fullLife = board[location.first][location.second + 1]->getFullHP();
		board[location.first][location.second + 1]->setHP(fullLife - life);
	}

	if (location.second - 1 >= 0 && board[location.first][location.second - 1] != nullptr
		&& board[location.first][location.second - 1]->getPlayer() == board[location.first][location.second]->getPlayer())
	{
		int life = board[location.first][location.second - 1]->getHP();
		int fullLife = board[location.first][location.second - 1]->getFullHP();
		board[location.first][location.second - 1]->setHP(fullLife - life);
	}

	actSoldier(board, location);
		return;
	}
void ParamedicCommander::actSoldier(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location) {
	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board[i].size(); j++) {
			Paramedic* s = dynamic_cast<Paramedic*>(board[i][j]);
				if (s)
					if (board[i][j]->getPlayer() == board[location.first][location.second]->getPlayer())
						board[i][j]->act(board, { i,j });
		}
}
