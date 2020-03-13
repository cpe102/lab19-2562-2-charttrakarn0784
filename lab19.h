#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<iomanip>

using namespace std;

class Unit{
		string name;
		string type;		
		int hp;
		int hpmax;
		int atk;
		int def; 
		bool guard_on; 		
	public:			
		void create(string);
		void showStatus();
		void newTurn();
		int attack(Unit &);
		int beAttacked(int); //? int from Atk who attack
		int heal();	
		void guard(); //? (ATK-DEF)/3
		bool isDead();	
};

void Unit::create(string t){ 
	if(t == "Hero"){
		type = "Hero";
		cout << "Please input your name: ";
		getline(cin,name);
		hpmax = rand()%20+90; //! 90 - 110
		atk = rand()%5+14; //! 14 - 19
		def = rand()%3+9; //! 9 - 11
	}else if(t == "Monster"){
		type = "Monster";
		name = "Monster";
		hpmax = rand()%20+200; //! 200 - 220
		atk = rand()%5+25; //! 25 - 30
		def = rand()%3+5; //! 5 - 8
	}
	hp = hpmax;
	guard_on = false;
}

void Unit::showStatus(){
	if(type == "Hero"){
		cout << "---------------------------------------\n"; 
		cout << name << "\n"; 
		cout << "HP: " << hp << "/" << hpmax << "\tATK: "<< atk << "\t\tDEF: "<< def;		
		cout << "\n---------------------------------------\n";
	}	
	else if(type == "Monster"){
		cout << "\t\t\t\t---------------------------------------\n"; 
		cout << "\t\t\t\tMonster" << "\n"; 
		cout << "\t\t\t\tHP: " << hp << "\t\tATK: "<< atk << "\t\tDEF: "<< def;
		cout << "\n\t\t\t\t---------------------------------------\n";
	}
}

void Unit::newTurn(){
	guard_on = false;
}

//* Write Function Member attack(), beAttacked(), heal(), guard() and isDead() here
//TODO attack()
int Unit::attack(Unit &target)
{
	return target.beAttacked(atk);
}
//TODO beAttack() calculate DMG = oppatk - def,decease HP by DMG if 
//TODO if Guard_on dmg = dmg/3 decrease HP by DMG return DMG
int Unit::beAttacked(int oppatk)
{
	int dmg = oppatk - def;
	if(guard_on == true) dmg /= 3;
	hp = hp - dmg;
	return dmg;
}
//TODO heal() rand10-30 but not >hpmax if(>) change randNum; and return H 
int Unit::heal()
{
	int heal_dmg = rand()%20+10;
	hp += heal_dmg;
	if(hp > hpmax){
		int excess = hp - hpmax;
		hp -= excess;
		heal_dmg -= excess;
	}
	return heal_dmg;
}
//TODO guard() set guard_on to True
void Unit::guard()
{
	guard_on = true;
}
//TODO isDead() check hp if hp <= 0 return true
bool Unit::isDead()
{
	if(hp <= 0) return true;
	else return false;
}
void drawScene(char p_action,int p,char m_action,int m){
	cout << "                                                       \n";
	if(p_action == 'A'){
	cout << "                                       "<< -p <<"\n";
	}else{
	cout << "                                                       \n";	
	}	
	cout << "                                *               *      \n";
	cout << "                                **  *********  **      \n";
	cout << "                                ****         ****      \n";
	if(m_action == 'A'){
	cout << "                 " << setw(5) << -m << "           *** **   ** ***       Attack!\n";
	}else if(m_action == 'G'){
	cout << "                                 *** **   ** ***       Guard!\n";
	}else{
	cout << "                                 *** **   ** ***       \n";	
	}
	cout << "                                  ** **   ** **        \n";
	cout << "                   ***             *         *         \n";
	if(p_action == 'A'){
	cout << "        Attack!    ***  *           *********          \n";		
	}else if(p_action == 'H'){
	cout << "      Heal! +" << setw(2) << p << "    ***  *           *********          \n";
	}else if(p_action == 'G'){
	cout << "         Guard!    ***  *           *********          \n";
	}else{
	cout << "                   ***  *           *********          \n";	
	}
	cout << "                    *  *       ***  *  *  *            \n";
	cout << "                  *****           **   *   *           \n";
	cout << "                    *                  *    ***        \n";
	cout << "                   * *               **        *       \n";
	cout << "                  *   *                                \n";
	cout << "                                                       \n";
};


void playerWin(){	
	cout << "*******************************************************\n";
	for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	cout << "*                   YOU WIN!!!                        *\n";
	for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	cout << "*******************************************************\n";
};


void playerLose(){
	cout << "*******************************************************\n";
	cout << "*                                                     *\n";
	cout << "*                   YOU LOSE!!!                       *\n";
	cout << "*                                                     *\n";
	cout << "*******************************************************\n";
};

