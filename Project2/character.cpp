/*
Project #2 - FIGHT!

This is the character class file. It contains the class definition and the
implementation of the member functions.

Mahmoud Elbasiouny
*/
#include <iostream>
#include "character.h"

using namespace std;

// Constructor with parameters
Character::Character(string newName,
					 string newRole,
					 int newHitPoints,
					 int newAttackBonus,
					 int newDamageBonus,
					 int newArmorClass)
	: name(newName),
	  role(newRole),
	  hitPoints(newHitPoints),
	  attackBonus(newAttackBonus),
	  damageBonus(newDamageBonus),
	  armorClass(newArmorClass) {}

// Character member functions
void Character::print() const
{
	cout << name << " the " << role << endl;
	cout << "HP: " << hitPoints << endl;
	cout << "AB: " << attackBonus << endl;
	cout << "DB: " << damageBonus << endl;
	cout << "AC: " << armorClass << endl;
	cout << endl;
};

void Character::attack(Character &otherCharacter) const
{
	int roll20 = (rand() % 20) + 1;			 // Roll a 20-sided die
	int attackResult = roll20 + attackBonus; // Add the attack bonus to the roll

	// If the result is equal to or higher than the opponent's armor
	// class, then the attack hits. Otherwise it misses.
	if (attackResult >= otherCharacter.armorClass)
	{
		// If the attack hits, roll a 10-sided die and add the attacking character's damage bonus.
		cout << name << " attacks!" << endl;
		cout << "Attack Roll: " << roll20 << " + " << attackBonus << " = " << attackResult << " --> HIT!" << endl;

		int roll10 = (rand() % 10) + 1;
		int damageResult = roll10 + damageBonus;
		cout << "Damage: " << roll10 << " + " << damageBonus << " = " << damageResult << endl;

		otherCharacter.damage(damageResult); // Subtract the damage from the opponent's hit points
		cout << otherCharacter.getName() << " has " << otherCharacter.getHealth() << " hit points remaining." << endl;
	}
	else
	{
		cout << name << " attacks!" << endl;
		cout << "Attack Roll: " << roll20 << " + " << attackBonus << " = " << attackResult << " --> MISS!" << endl;
	}
};

void Character::damage(int amount)
{
	hitPoints -= amount;

	// Can't have negative hit points so set it to 0 if it's negative
	if (hitPoints < 0)
	{
		hitPoints = 0;
	}
};

// Getters and setters
int Character::getHealth() const
{
	return hitPoints;
};

string Character::getName() const
{
	return name;
};

string Character::getRole() const
{
	return role;
}

void Character::setName(string newName)
{
	name = newName;
};

void Character::setRole(string newRole)
{
	role = newRole;
};

void Character::setHitPoints(int newHitPoints)
{
	hitPoints = newHitPoints;
};

void Character::setAttackBonus(int newAttackBonus)
{
	attackBonus = newAttackBonus;
};

void Character::setDamageBonus(int newDamageBonus)
{
	damageBonus = newDamageBonus;
};

void Character::setArmorClass(int newArmorClass)
{
	armorClass = newArmorClass;
};