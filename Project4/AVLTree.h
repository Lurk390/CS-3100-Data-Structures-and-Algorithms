#include <string>
#include <vector>

using namespace std;

class AVLTree
{
public:
    // Default constructor. Creates an empty AVL tree.
    AVLTree();

    // Destructor. Frees all memory allocated to the AVL tree.
    ~AVLTree();

    // Inserts a new key/value pair into the tree. Duplicate keys are not allowed.
    // Returns true if the key/value pair is successfully inserted into the map,
    // and false if the pair could not be inserted. O(log2 n) time complexity.
    bool insert(int key, string value);

    // If the given key is found in the AVL tree, this function returns true and place
    // the corresponding value in value. Otherwise this function returns false (and the
    // value in value can be anything). O(log2 n) time complexity.
    bool find(int key, string &value);

    // Returns the height of the AVL tree. O(1) time complexity.
    int getHeight();

    // Returns the total number of nodes (key/value pairs) in the AVL tree.
    // O(1) time complexity.
    int getSize();

    // Returns a vector of strings containing all of the values in the tree with keys ≥ lowkey
    // and ≤ highkey. For each key found in the given range, there will be one value in the
    // vector. If no matching key/value pairs are found, the function returns an empty vector.
    vector<string> findRange(int lowkey, int highkey);

    // Prints the tree using the << operator. Overloads the << operator to print the
    // AVL tree “sideways” using indentation to show the structure of the tree.
    friend ostream &operator<<(ostream &os, const AVLTree &me);

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

        AVLNode(int key, string value, AVLNode *parent, AVLNode *left, AVLNode *right)
            : key(key),
              value(value),
              parent(parent),
              left(left),
              right(right)
        {
        }
    };

    AVLNode *root;
    int size;
    int height;
};
