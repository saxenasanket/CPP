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

// Function to find the maximum width of the tree
// using level order traversal
int zigzag(Node *root)
{

    if (root == NULL)
    {

        cout << "empty tree";
    }

    queue<Node *> q;
    q.push(root);
    int lvl = 0;

    while (!q.empty())
    {

        lvl++;
        int size = q.size();
        cout << lvl << " ";

        while (size--)
        {
            Node *first = q.front();
            cout << first->data << " ";
            q.pop();

            if (first->left)
            {
                q.push(first->left);
            }
            if (first->right)
            {
                q.push(first->right);
            }
        }

        cout << endl;
    }
}

int printAncestor(Node *root, vector<int> &vec, int key)
{
    if (root == NULL)
        return 0;

    if (root->data == key)
    {
        return 1;
    }
    vec.push_back(root->data);
    return (printAncestor(root->left, vec, key) || printAncestor(root->right, vec, key));
    vec.pop_back();
    return 0;
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct Node *newNode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
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

    printAncestor(root, vec, 4);

    // printAncestor(root, vec, 7);

    // printAncestor(root, vec, 2);

    // printAncestor(root, vec, 5);

    // // Declaring iterator to a vector
    // vector<Node *>::iterator ptr;

    // // Displaying vector elements using begin() and end()
    // cout << "The vector elements are : ";
    // for (ptr = vec.begin(); ptr < vec.end(); ptr++)
    //     cout << *ptr << " ";

    return 0;
}
