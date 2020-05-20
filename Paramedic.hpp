#pragma once
#include "Soldier.hpp"
using namespace std;

class Paramedic : public virtual Soldier {

public:

	Paramedic(int pl) :Soldier(100, 50, pl) {}
	void act();


};