#include "AVLTree.h"

AVLTree::AVLTree()
{
    root = nullptr;
    size = 0;
    height = NULL;
}

AVLTree::~AVLTree()
{
}

bool AVLTree::insert(int key, string value)
{
    if (root == nullptr)
    {
        root = new AVLNode(key, value, nullptr, nullptr, nullptr);
        size++;
        height = 0;
        return true;
    }
    else
    {
        AVLNode *current = root;
        while (current != nullptr)
        {
            // Check for duplicate key
            if (key == current->key)
            {
                return false;
            }
            // If key is less than current node, go left
            else if (key < current->key)
            {
                // If left child is null, insert new node
                if (current->left == nullptr)
                {
                    current->left = new AVLNode(key, value, current, nullptr, nullptr);
                    size++;
                    return true;
                }
                // Otherwise, go left
                else
                {
                    current = current->left;
                }
            }
            // If key is greater than current node, go right
            else
            {
                // If right child is null, insert new node
                if (current->right == nullptr)
                {
                    current->right = new AVLNode(key, value, current, nullptr, nullptr);
                    size++;
                    return true;
                }
                // Otherwise, go right
                else
                {
                    current = current->right;
                }
            }
        }
    }

    return false;
}

bool AVLTree::find(int key, string &value)
{
    return false;
}

int AVLTree::getHeight()
{
    return 0;
}

int AVLTree::getSize()
{
    return 0;
}

vector<string> AVLTree::findRange(int lowkey, int highkey)
{
    return vector<string>();
}

ostream &operator<<(ostream &os, const AVLTree &me)
{
    // Right-child-first inorder traversal
    return os;
}
