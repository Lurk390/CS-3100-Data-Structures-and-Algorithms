/*
Project #2 - FIGHT!

This is the main file for the project. It contains the main function and
the functions that are used to initialize the characters and to fight
between them.

Mahmoud Elbasiouny
*/
#include <iostream>
#include "character.h"

using namespace std;

void initializeCharacter(Character &character);		  // Prompt the user to enter the character's information
void fight(Character &char1, Character &char2);		  // Simulate the fight between the two characters until one of them reaches 0 hit points
void checkWinner(Character &char1, Character &char2); // Check who is the winner

int main()
{
	Character char1("Ulgar", "Barbarian", 80, 5, 5, 24); // Used to test without inputs
	char1.print();
	// Character char1;
	// initializeCharacter(char1);

	Character char2("Zimzizz", "Wizard", 40, 5, 15, 18); // Used to test without inputs
	char2.print();
	// Character char2;
	// initializeCharacter(char2);

	srand(time(nullptr)); // Seed the random number generator
	fight(char1, char2);
	checkWinner(char1, char2);

	return 0;
}

void initializeCharacter(Character &character)
{
	string name;
	cout << endl
		 << "First character name? ";
	cin >> name;
	character.setName(name);

	string role;
	cout << name << "'s role? ";
	cin >> role;
	character.setRole(role);

	int hitPoints;
	cout << name << " the " << role << "'s hit points? ";
	cin >> hitPoints;
	character.setHitPoints(hitPoints);

	int attackBonus;
	cout << name << " the " << role << "'s attack bonus? ";
	cin >> attackBonus;
	character.setAttackBonus(attackBonus);

	int damageBonus;
	cout << name << " the " << role << "'s damage bonus? ";
	cin >> damageBonus;
	character.setDamageBonus(damageBonus);

	int armorClass;
	cout << name << " the " << role << "'s armor class? ";
	cin >> armorClass;
	character.setArmorClass(armorClass);

	cout << endl
		 << "Character summary" << endl;
	cout << "-----------------" << endl;
	character.print();
}

void fight(Character &char1, Character &char2)
{
	while (char1.getHealth() > 0 && char2.getHealth() > 0)
	{
		if (char1.getHealth() > 0)
		{
			char1.attack(char2);
			cout << endl;
		}

		if (char2.getHealth() > 0)
		{
			char2.attack(char1);
			cout << endl;
		}
	}
}

void checkWinner(Character &char1, Character &char2)
{
	if (char1.getHealth() > 0)
	{
		cout << char1.getName() << " wins!" << endl;
	}
	else
	{
		cout << char2.getName() << " wins!" << endl;
	}
}