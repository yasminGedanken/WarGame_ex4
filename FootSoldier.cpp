
#include "FootSoldier.hpp"



void FootSoldier::act(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location) {
	float min=INFINITY;
	std::pair<int, int> close;
	for(int i=0; i<board.size();i++)
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] != nullptr) {

					if ( board[i][j]->getPlayer() != board[location.first][location.second]->getPlayer()) {
						float temp = distance(i, j, location.first, location.second);
						if (temp < min) {
							min = temp;
							close.first = i; close.second = j;
						}
					}
			}
		}
	if (min != INFINITY) {
		board[close.first][close.second]->setHP(-10);
		if (board[close.first][close.second]->getHP() <= 0) board[close.first][close.second] = nullptr;
		return;
	}
	return;
	}
// Function to calculate distance 
float FootSoldier::distance(int x1, int y1, int x2, int y2)
{
	// Calculating distance 
	return sqrt(pow(x2 - x1, 2) +
		pow(y2 - y1, 2) * 1.0);
}