#include <string>
#include <vector>

using namespace std;

class AVLTree
{
private:
    // Private inner class for AVLTree nodes
    class AVLNode
    {
    public:
        int key;
        string value;
        AVLNode *parent;
        AVLNode *left;
        AVLNode *right;
        int balance;

        AVLNode(int key, string value, AVLNode *parent, AVLNode *left, AVLNode *right, int balance = 0)
            : key(key),
              value(value),
              parent(parent),
              left(left),
              right(right),
              balance(balance)
        {
        }
    };

    AVLNode *root;
    int size;

public:
    // Default constructor. Creates an empty AVL tree.
    AVLTree();

    // Destructor. Frees all memory allocated to the AVL tree.
    ~AVLTree();

    // Inserts a new key/value pair into the tree. Duplicate keys are not allowed.
    // Returns true if the key/value pair is successfully inserted into the map,
    // and false if the pair could not be inserted.
    bool insert(int key, string value);

    // Checks if node is unbalanced and performs rotations if necessary
    void updateBalance(AVLNode *node);

    // Single left rotation
    void leftRotate(AVLNode *node);

    // Single right rotation
    void rightRotate(AVLNode *node);

    // If the given key is found in the AVL tree, this function returns true and place
    // the corresponding value in value. Otherwise this function returns false (and the
    // value in value can be anything).
    bool find(int key, string &value);

    // If the given key is found in the AVL tree, this function returns true.
    bool find(int key) const;

    // Returns a vector of strings containing all of the values in the tree with keys ≥ lowkey
    // and ≤ highkey. For each key found in the given range, there will be one value in the
    // vector. If no matching key/value pairs are found, the function returns an empty vector.
    vector<string> findRange(int lowkey, int highkey) const;

    // Helper function for findRange
    void findRangeHelper(AVLNode *node, int lowkey, int highkey, vector<string> &result) const;

    // Postoreder traversal to delete all nodes
    void deleteNodes(AVLNode *node);

    // Returns the height of the AVL tree.
    int getHeight() const;

    // Returns the height of the subtree from a given node.
    int getHeight(AVLNode *node) const;

    // Returns the total number of nodes (key/value pairs) in the AVL tree.
    int getSize() const;

    // Returns the balance of a given node.
    int getBalance(AVLNode *node) const;

    // Prints the tree using the << operator. Overloads the << operator to print the
    // AVL tree “sideways” using indentation to show the structure of the tree.
    friend ostream &operator<<(ostream &os, const AVLTree &me);

    // Right-child-first inorder traversal
    void printLargestToSmallest(AVLNode *node, int depth) const;
};
