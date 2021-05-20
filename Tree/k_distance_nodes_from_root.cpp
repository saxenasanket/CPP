// A queue based C++ program to find maximum width
// of a Binary Tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct Node *newNode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

void knodes(Node *root, vector<int> &vec, int k)
{
    if (!root)
        return;
    if (k == 0)
    {
        vec.push_back(root->data);
        return;
    }

    knodes(root->left, vec, k - 1);
    knodes(root->right, vec, k - 1);
    return;
}

// Driver code
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);

    /* Constructed Binary tree is:
				1
			/ \
			2	 3
		/ \	 \
		4 5	 8
					/ \
				6	 7 */

    // Function call
    // zigzag(root);

    vector<int> vec;

    knodes(root, vec, 3);

    // Declaring iterator to a vector
    vector<int>::iterator ptr;

    // Displaying vector elements using begin() and end()
    cout << "The vector elements are : ";
    for (ptr = vec.begin(); ptr < vec.end(); ptr++)
        cout << *ptr << " ";

    return 0;
}
