// C++ program for printing vertical order of a given binary tree
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Structure for a binary tree node
struct Node
{
    int key;
    Node *left, *right;
};

// A utility function to create a new node
struct Node *newNode(int key)
{
    struct Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

void getVerticalOrder(Node *root, int hd, map<int, vector<int>> &m)
{
    if (!root)
        return;

    // save current node with it's hd
    m[hd].push_back(root->key);

    getVerticalOrder(root->left, hd - 1, m);
    getVerticalOrder(root->right, hd + 1, m);

    return;
}

// The main function to print vertical order of a binary tree
// with the given root
void printVerticalOrder(Node *root)
{
    map<int, vector<int>> m;

    getVerticalOrder(root, 0, m);

    //  import: how we print map using iterator
    map<int, vector<int>>::iterator it;

    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}

// Driver program to test above functions
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is n";
    printVerticalOrder(root);
    return 0;
}
