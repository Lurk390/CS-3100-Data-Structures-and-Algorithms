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
    return 0;
}

vector<string> Trie::complete(string prefix)
{
    vector<string> result;
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