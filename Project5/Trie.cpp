/*
Project #5 - Alphabet Trie Autocomplete

This is the implementation file for the Trie class. It contains the
implementation of the member functions of the Trie class.

Author: Mahmoud Elbasiouny
*/
#include "Trie.h"

Trie::Trie()
{
    size = 0;
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
    return false;
}

int Trie::count()
{
    return 0;
}

int Trie::getSize()
{
    return -1;
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
    return node;
}

void Trie::deleteAll()
{
}