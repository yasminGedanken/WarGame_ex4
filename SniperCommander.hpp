#pragma once
#include "Soldier.hpp"
using namespace std;

class SniperCommander : public virtual Soldier {

public:

	SniperCommander(int pl) :Soldier(120, 100, pl) {}
	void act();


};