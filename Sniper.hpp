#pragma once
#include "Soldier.hpp"
using namespace std;

class Sniper : public virtual Soldier {

public:

	Sniper(int pl) :Soldier(100, 50, pl) {}
	void act();


};