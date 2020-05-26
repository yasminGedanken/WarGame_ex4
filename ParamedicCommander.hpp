#pragma once
#include "Soldier.hpp"
#include "Paramedic.hpp"
using namespace std;

class ParamedicCommander : public virtual Soldier {

public:

	ParamedicCommander(int pl) :Soldier(200,200, 100, pl) {}
	void act(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location);
	void actSoldier(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location);

};