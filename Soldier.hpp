#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

class Soldier {

private:
	int HP; // how much health point left
	int fullHP; //health point
	int Damage; ///damage per activity
	int Player; //number of player

public:
	virtual ~Soldier() {};
	virtual void act(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location) {};

	Soldier( int hp = 0, int fullhp=0, int damage = 0,int player=0) 
		:HP(hp),fullHP(fullhp), Damage(damage),  Player(player){}


	virtual int getHP(){
		return HP;
	}
	virtual void setHP(int hp) {
		HP += hp;
	}
	virtual int getFullHP() {
		return fullHP;
	}
	virtual int getDamage() {
		return Damage;
	}
	
	virtual int getPlayer() {
		return Player;
	}





};
