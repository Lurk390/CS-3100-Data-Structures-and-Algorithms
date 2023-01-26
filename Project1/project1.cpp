/*
Project #1 - Simulating dice rolls

This program prompts the user for a number of rolls to make. For each roll,
two dice rolls are simulated and summed. Each result is stored in an array
which keeps track of how many times each result occured. Once the simulation is
completed, the array is printed to show how many times each total was rolled.

Mahmoud Elbasiouny
*/
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int input;
	int arr[11] = {0};

	cout << "How many rolls?: ";
	cin >> input;

	cout << "Simulating " << input << " rolls..." << endl;

	srand(time(nullptr));
	for (int i = 0; i < input; i++)
	{
		int dice1 = (rand() % 6) + 1;
		int dice2 = (rand() % 6) + 1;
		int result = dice1 + dice2;

		arr[result - 2]++;
	}

	cout << "Results:" << endl;
	for (int i = 2; i <= 12; i++)
	{
		cout << i << " was rolled " << arr[i - 2] << " times" << endl;
	}
}