#pragma once
#include "Soldier.hpp"
using namespace std;

class ParamedicCommander : public virtual Soldier {

public:

	ParamedicCommander(int pl) :Soldier(200, 100, pl) {}
	void act();


};