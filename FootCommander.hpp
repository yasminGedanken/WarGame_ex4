#pragma once
#include "Soldier.hpp"
#include "FootSoldier.hpp"
#include <iostream>

class FootCommander : public virtual Soldier {

public:

	FootCommander(int pl) :Soldier(150,150, 20, pl) {}
	void act(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location);
	void actSoldier(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location);
	float distance(int x1, int y1, int x2, int y2);
};
