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
int maxWidth(struct Node *root)
{
    int result = 1;
    queue<Node *> q;
    q.push(root);

    int lvl = 0;

    while (!q.empty())
    {
        int size = q.size();
        lvl++;

        cout << "Nodes for level " << lvl << " are ";

        // cout << "size " << size << endl;

        while (size--)
        {

            Node *child = q.front();
            cout << child->data << " ";

            q.pop();
            if (child->left)
                q.push(child->left);

            if (child->right)
                q.push(child->right);
        }

        cout << endl;
    }

    return result;
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
    maxWidth(root);
    return 0;
}

// This code is contributed by Nikhil Kumar
// Singh(nickzuck_007)
