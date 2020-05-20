#pragma once
#include "Soldier.hpp"

class FootCommander : public virtual Soldier {

public:

	FootCommander(int pl) :Soldier(150, 20, pl) {}
	void act();


};
