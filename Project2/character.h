/*
Project #2 - FIGHT!

This is the header file for the character class. It contains the class
declarations and the declarations of the member functions.

Mahmoud Elbasiouny
*/
#include <string>

using namespace std;

class Character
{
private:
	// Character data
	string name;	 // character's name
	string role;	 // type of character (wizard, fighter, rogue, etc.)
	int hitPoints;	 // character's current health. If this reaches 0, the character is dead
	int attackBonus; // this is added to a character's attack role to determine if an attack hits
	int damageBonus; // this is added to a character's damage roll when attacking
	int armorClass;	 // determines how hard a character is to hit

public:
	// Default constructor
	Character()
	{
		name = "";
		role = "";
		hitPoints = 0;
		attackBonus = 0;
		damageBonus = 0;
		armorClass = 0;
	}

	// Constructor with parameters
	Character(string newName, string newRole, int newHitPoints,
			  int newAttackBonus, int newDamageBonus, int newArmorClass);

	// Character member functions
	void print() const;							  // prints the character's data to the console
	void attack(Character &otherCharacter) const; // attacks another character
	void damage(int amount);					  // subtract amount from the character's current hit points

	// Getters and setters
	int getHealth() const;					 // returns the character's current health
	string getName() const;					 // returns the character's name
	string getRole() const;					 // returns the character's role
	void setName(string newName);			 // sets the character's name
	void setRole(string newRole);			 // sets the character's role
	void setHitPoints(int newHitPoints);	 // sets the character's hit points
	void setAttackBonus(int newAttackBonus); // sets the character's attack bonus
	void setDamageBonus(int newDamageBonus); // sets the character's damage bonus
	void setArmorClass(int newArmorClass);	 // sets the character's armor class
};
