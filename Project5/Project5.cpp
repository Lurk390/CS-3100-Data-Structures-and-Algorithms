/*
Project #5 - Alphabet Trie Autocomplete

This is the main file for the Trie class. It contains the main function
that will be used to test the Trie class and its member functions.

Author: Mahmoud Elbasiouny
*/
#include "Trie.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ifstream fileIn("wordlist.txt");
    vector<string> wordlist;

    if (fileIn.good())
    {
        string word;

        while (!fileIn.eof())
        {
            fileIn >> word;
            wordlist.push_back(word);
        }
        fileIn.close();
    }
    else
    {
        cerr << "File not found" << endl;
    }

    for (auto word : wordlist)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}