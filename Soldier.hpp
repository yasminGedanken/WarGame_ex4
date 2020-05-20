#pragma once
using namespace std;

class Soldier {

private:
	int HP; // health point 
	int Damage; ///damage per activity
	int Player; //number of player

public:

	Soldier( int hp = 0, int damage = 0,int player=0) 
		:HP(hp), Damage(damage),  Player(player){}

	
	int getHP() const{
		return HP;
	}
	int getDamage() const {
		return Damage;
	}
	
	int getPlayer() const {
		return Player;
	}




};
