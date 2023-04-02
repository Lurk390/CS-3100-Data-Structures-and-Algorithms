/*
Project #5 - Alphabet Trie Autocomplete

This is the header file for the Trie class. It contains the declaration
of the member functions of the Trie class.

Author: Mahmoud Elbasiouny
*/
#include <string>
#include <vector>

using namespace std;

class Trie
{
private:
    struct Node
    {
        bool isWord = false;
        Node *children[26];
    };

    Node *root;
    int nodes; // Number of nodes in the trie
    int words; // Number of words in the trie

    // Creates a new node and initializes all children to nullptr. Returns a pointer
    // to the new node.
    Node *createNode(Node *);

    // Deletes all nodes in the trie.
    void deleteAll(Node *);

public:
    // Default constructor. Creates an empty Trie.
    Trie();

    // Destructor. Frees all memory allocated to the Trie.
    ~Trie();

    // Copy constructor. Creates a new Trie that is a deep copy of the given Trie.
    Trie(const Trie &);

    // Inserts a new word into the Trie. Duplicate words are not allowed.
    // Returns true if the word is successfully inserted into the Trie,
    // and false if the word could not be inserted.
    bool insert(string);

    // Returns the number of words in the Trie.
    int count();

    // Returns the total number of nodes in the trie
    int getSize();

    // Returns the number of words in the dictionary that begin with the given input
    // string. If no matching words are found, this function will return zero.
    int completeCount(string);

    // Returns the number of words in the Trie that start with the given input string.
    // For each word found in the trie, there will be one value in the vector. If no
    // matching words are found, this function will return an empty vector.
    vector<string> complete(string);

    // Removes all contents of the original trie and makes an independant copy in
    // another trie.
    Trie &operator=(const Trie &);
};