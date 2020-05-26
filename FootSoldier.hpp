#pragma once
#include "Soldier.hpp"
#include <math.h>  
using namespace std;

class FootSoldier : public virtual Soldier {
	
public:

	FootSoldier(int pl) :Soldier(100,100, 10, pl){}
	void act(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location);
	float distance(int x1, int y1, int x2, int y2);

};
	