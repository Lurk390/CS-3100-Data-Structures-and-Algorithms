/*
Project #5 - Alphabet Trie Autocomplete

This is the implementation file for the Trie class. It contains the
implementation of the member functions of the Trie class.

Author: Mahmoud Elbasiouny
*/
#include "Trie.h"

Trie::Trie()
{
    nodes = 0;
    words = 0;
    root = createNode(root);
}

Trie::~Trie()
{
    deleteAll();
}

Trie::Trie(const Trie &)
{
}

bool Trie::insert(string word)
{
    // Start at the root
    Node *node = root;

    // Iterate through each character in the word
    for (char ch : word)
    {
        // Convert the character to an index
        int index = ch - 'a';

        // If child doesn't exist, create a new node
        if (node->children[index] == nullptr)
        {
            node->children[index] = createNode(node->children[index]);
        }

        // Move to the next node
        node = node->children[index];
    }

    // Check if word is already in the trie
    if (node->isWord)
    {
        return false;
    }

    node->isWord = true;
    words++;
    return true;
}

int Trie::count()
{
    return words;
}

int Trie::getSize()
{
    return nodes;
}

int Trie::completeCount(string prefix)
{
    // Return the size of the vector returned by complete()
    return complete(prefix).size();
}

vector<string> Trie::complete(string prefix)
{
    vector<string> result;
    Node *node = root;

    // Iterate through each character in the prefix
    for (char ch : prefix)
    {
        // Convert the character to an index
        int index = ch - 'a';

        // If child doesn't exist, return empty vector
        if (node->children[index] == nullptr)
        {
            return result;
        }

        // Move to the next node
        node = node->children[index];
    }

    // If the prefix is a word, add it to the vector
    if (node->isWord)
    {
        result.push_back(prefix);
    }

    // Iterate through all children of the node
    for (int i = 0; i < 26; i++)
    {
        // If child exists, add it to the vector
        if (node->children[i] != nullptr)
        {
            // Convert the index to a character
            char ch = i + 'a';

            // Recursively call complete() on the child node
            vector<string> temp = complete(prefix + ch);

            // Add the results to the vector
            result.insert(result.end(), temp.begin(), temp.end());
        }
    }
    return result;
}

Trie &Trie::operator=(const Trie &trie)
{
    return *this;
}

Trie::Node *Trie::createNode(Node *node)
{
    node = new Node;

    // Initialize all children to nullptr
    for (int i = 0; i < 26; i++)
    {
        node->children[i] = nullptr;
    }
    nodes++;
    return node;
}

void Trie::deleteAll()
{
}