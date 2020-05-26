#pragma once
#include "Soldier.hpp"
#include "Sniper.hpp"
#include <iostream>
using namespace std;

class SniperCommander : public virtual Soldier {

public:

	SniperCommander(int pl) :Soldier(120,120, 100, pl) {}
	void act(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location);
	void actSoldier(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location);

};