/*
Project #4 - Indexing with AVL Trees

This is the implementation file for the AVLTree class. It contains the
implementation of the member functions of the AVLTree class.

Author: Mahmoud Elbasiouny
*/
#include "AVLTree.h"
#include <iostream>

AVLTree::AVLTree()
{
    root = nullptr;
    size = 0;
}

AVLTree::~AVLTree()
{
    deleteNodes(root);
}

AVLTree::AVLTree(const AVLTree &other)
{
    root = copyTree(other.root);
    size = other.size;
}

bool AVLTree::insert(int key, string value)
{
    AVLNode *newNode = new AVLNode(key, value, nullptr, nullptr, nullptr, 0);

    // If the tree is empty, make the new node the root
    if (root == nullptr)
    {
        root = newNode;
        size++;
        return true;
    }
    // If the tree is not empty, find the correct place to insert the new node
    else
    {
        AVLNode *current = root;
        AVLNode *parent = nullptr;
        while (current != nullptr)
        {
            parent = current;
            if (key < current->key)
            {
                // If the key is less than the current node's key, go left
                current = current->left;
            }
            else if (key > current->key)
            {
                // If the key is greater than the current node's key, go right
                current = current->right;
            }
            else
            {
                // If the key is equal to the current node's key, return false
                return false;
            }
        }

        if (key < parent->key)
        {
            // If the key is less than the parent node's key, insert the new node as the left child
            parent->left = newNode;
        }
        else
        {
            // If the key is greater than the parent node's key, insert the new node as the right child
            parent->right = newNode;
        }
        // Set the new node's parent to the parent node
        newNode->parent = parent;
        size++;
        // Update the balance of the new node
        updateBalance(newNode);

        return true;
    }
    return false;
}

void AVLTree::updateBalance(AVLNode *node)
{
    // Check for unbalanced nodes
    if (node->balance > 1 || node->balance < -1)
    {
        // If the node's balance is -2, rotate right
        if (node->balance > 0)
        {
            // If the node's right child's balance is 1, rotate right then left
            if (node->right->balance < 0)
            {
                rightRotate(node->right);
                leftRotate(node);
            }
            // If the node's right child's balance is -1, rotate left
            else
            {
                leftRotate(node);
            }
        }
        // If the node's balance is 2, rotate left
        else if (node->balance < 0)
        {
            // If the node's left child's balance is -1, rotate left then right
            if (node->left->balance > 0)
            {
                leftRotate(node->left);
                rightRotate(node);
            }
            // If the node's left child's balance is 1, rotate right
            else
            {
                rightRotate(node);
            }
        }
        return;
    }

    // If the node's balance is 0, update the balance of the parent node
    if (node->parent != nullptr)
    {
        // If the node is the left child of its parent
        if (node == node->parent->left)
        {
            // Subtract 1 from the parent's balance
            node->parent->balance -= 1;
        }
        // If the node is the right child of its parent
        else if (node == node->parent->right)
        {
            // Add 1 to the parent's balance
            node->parent->balance += 1;
        }

        // If the parent's balance is not 0
        if (node->parent->balance != 0)
        {
            // Update the balance of the parent node
            updateBalance(node->parent);
        }
    }
}

void AVLTree::leftRotate(AVLNode *x)
{
    AVLNode *y = x->right;
    x->right = y->left;

    // Set the parent of the left child of y to x
    if (y->left != nullptr)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;

    // If x is the root node, set y as the root node
    if (x->parent == nullptr)
    {
        this->root = y;
    }
    // If x is the left child of its parent, set y as the left child of x's parent
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    // Otherwise, set y as the right child of x's parent
    else
    {
        x->parent->right = y;
    }
    // Set x as the left child of y and set y as the parent of x
    y->left = x;
    x->parent = y;

    // Update the balance of x and y
    x->balance = getBalance(x);
    y->balance = getBalance(y);
}

void AVLTree::rightRotate(AVLNode *x)
{
    AVLNode *y = x->left;
    x->left = y->right;

    // Set the parent of the right child of y to x
    if (y->right != nullptr)
    {
        y->right->parent = x;
    }
    y->parent = x->parent;

    // If x is the root node, set y as the root node
    if (x->parent == nullptr)
    {
        this->root = y;
    }
    // If x is the right child of its parent, set y as the right child of x's parent
    else if (x == x->parent->right)
    {
        x->parent->right = y;
    }
    // Otherwise, set y as the left child of x's parent
    else
    {
        x->parent->left = y;
    }
    // Set x as the right child of y and set y as the parent of x
    y->right = x;
    x->parent = y;

    // Update the balance of x and y
    x->balance = getBalance(x);
    y->balance = getBalance(y);
}

bool AVLTree::find(int key, string &value)
{
    // Start at the root node
    AVLNode *current = root;
    while (current != nullptr)
    {
        // If the key is equal to the current node's key
        if (key == current->key)
        {
            // Set the value to the current node's value and return true
            value = current->value;
            return true;
        }
        // If the key is less than the current node's key
        else if (key < current->key)
        {
            // Go left
            current = current->left;
        }
        // If the key is greater than the current node's key
        else
        {
            // Go right
            current = current->right;
        }
    }
    return false;
}

bool AVLTree::find(int key) const
{
    // Start at the root node
    AVLNode *current = root;
    while (current != nullptr)
    {
        // If the key is equal to the current node's key
        if (key == current->key)
        {
            // Return true
            return true;
        }
        // If the key is less than the current node's key
        else if (key < current->key)
        {
            // Go left
            current = current->left;
        }
        // If the key is greater than the current node's key
        else
        {
            // Go right
            current = current->right;
        }
    }
    return false;
}

vector<string> AVLTree::findRange(int lowkey, int highkey) const
{
    vector<string> result;
    findRangeHelper(root, lowkey, highkey, result);
    return result;
}

void AVLTree::findRangeHelper(AVLNode *node, int lowkey, int highkey, vector<string> &result) const
{
    if (node == nullptr)
    {
        return;
    }

    if (node->key > highkey)
    {
        findRangeHelper(node->left, lowkey, highkey, result);
    }
    else if (node->key < lowkey)
    {
        findRangeHelper(node->right, lowkey, highkey, result);
    }
    else
    {
        findRangeHelper(node->left, lowkey, highkey, result);
        result.push_back(node->value);
        findRangeHelper(node->right, lowkey, highkey, result);
    }
}

void AVLTree::deleteNodes(AVLNode *node)
{
    // Check if the node is null
    if (node == nullptr)
    {
        return;
    }
    // Post-order traversal to delte all nodes
    else
    {
        deleteNodes(node->left);
        deleteNodes(node->right);
        delete node;
    }
}

int AVLTree::getHeight() const
{
    // Return the height of the root node (entire tree)
    return getHeight(this->root);
}

int AVLTree::getHeight(AVLNode *node) const
{
    // Check if the node is null
    if (node == nullptr)
    {
        return -1;
    }
    else
    {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        // Return the greater of the left and right subtree heights
        return max(leftHeight, rightHeight) + 1;
    }
    return 0;
}

int AVLTree::getSize() const
{
    return size;
}

int AVLTree::getBalance(AVLNode *node) const
{
    // Check if the node is null
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        // Return the difference between the left and right subtree heights
        return getHeight(node->left) - getHeight(node->right);
    }
    return 0;
}

AVLTree &AVLTree::operator=(const AVLTree &tree)
{
    // Check for self-assignment
    if (this == &tree)
    {
        return *this;
    }

    // Delete the current tree
    deleteNodes(root);

    // Create a copy of the new tree
    if (tree.root != nullptr)
    {
        // Copy the root of the source tree to the root of the new tree
        root = copyTree(tree.root);
        size = tree.size;
    }

    // Return a reference to the new tree
    return *this;
}

AVLTree::AVLNode *AVLTree::copyTree(AVLNode *root)
{
    if (root == nullptr)
    {
        // If the source node is null, return null
        return nullptr;
    }
    else
    {
        // Create a new node with the same key and value as the source node
        AVLNode *newNode = new AVLNode(root->key, root->value, nullptr, nullptr, nullptr, 0);

        // Recursively copy the left subtree of the source node to the left subtree of the new node
        newNode->left = copyTree(root->left);
        if (newNode->left != nullptr)
        {
            newNode->left->parent = newNode;
        }

        // Recursively copy the right subtree of the source node to the right subtree of the new node
        newNode->right = copyTree(root->right);
        if (newNode->right != nullptr)
        {
            newNode->right->parent = newNode;
        }

        // Copy the balance factor of the source node to the new node
        newNode->balance = root->balance;

        // Return the ro
        return newNode;
    }
}

ostream &operator<<(ostream &os, const AVLTree &me)
{
    me.printLargestToSmallest(me.root, 0);
    return os;
}

void AVLTree::printLargestToSmallest(AVLNode *node, int depth) const
{
    // Check if the node is null
    if (node == NULL)
        return;

    printLargestToSmallest(node->right, depth + 1);

    // Print the depth of the node as a tab
    for (int i = 0; i < depth; i++)
    {
        cout << "    ";
    }
    // Print the node's key and value
    cout << "(" << (node->key) << ", " << (node->value) << ")" << endl;

    printLargestToSmallest(node->left, depth + 1);
}
