#pragma once
#include "Soldier.hpp"
using namespace std;

class FootSoldier : public virtual Soldier {
	
public:

	FootSoldier(int pl) :Soldier(100, 10, pl){}
	void act();


};
	