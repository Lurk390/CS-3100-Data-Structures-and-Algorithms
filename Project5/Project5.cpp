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
    // Open the wordlist file
    ifstream fileIn("wordlist.txt");
    vector<string> wordlist;

    // Load each word into a vector
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

    // Create a trie and insert each word into the trie
    Trie trie;
    for (string word : wordlist)
    {
        trie.insert(word);
    }

    // Prompt user for input
    cout << "Please enter a word prefix: ";
    string prefix_input;
    cin >> prefix_input;

    // Get the list of words that start with the given prefix
    vector results = trie.complete(prefix_input);

    cout << "There are " << results.size() << " words for the prefix '" << prefix_input << "'. "
         << "Show Completions? (y/n): ";
    string choice;
    cin >> choice;

    // Display the results
    if (choice == "y")
    {
        cout << endl
             << "Completions" << endl
             << "-----------" << endl;
        for (string word : results)
        {
            cout << word << endl;
        }
    }
    else
    {
        cout << "Goodbye!" << endl;
        return 0;
    }
}