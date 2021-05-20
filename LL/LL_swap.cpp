// Iterative C++ program to find length
// or count of nodes in a linked list
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
public:
    int data;
    Node *next;
};

/* Given a reference (pointer to pointer) to the head 
of a list and an int, push a new node on the front 
of the list. */
void push(Node **head_ref, int new_data)
{
    /* allocate node */
    Node *new_node = new Node();

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Counts no. of nodes in linked list */
int getCount(Node *head)
{

    if (!head)
        return 0;

    return 1 + getCount(head->next);
}

void printLL(Node *head)
{

    while (head)
    {
        cout << head->data << " ";

        head = head->next;
    }
}

int swapNodes(int data1, int data2, Node *root)
{

    Node *p1 = NULL, *b1 = NULL, *a1 = NULL, *p2 = NULL, *a2 = NULL, *b2 = NULL, *head = root;

    if (root->data == data1)
    {
        p1 = root;
        a1 = root->next;
    }

    if (root->data == data2)
    {
        p2 = root;
        a2 = root->next;
    }

    while (root->next)
    {
        if (root->next->data == data1 && !p1)
        {
            b1 = root;
            p1 = root->next;
            a1 = root->next->next;
        }

        if (root->next->data == data2 && !p2)
        {
            b2 = root;
            p2 = root->next;
            a2 = root->next->next;
        }

        root = root->next;
    }

    // check if node not found

    if (!p1 || !p2)
    {
        cout << "either of the nodes is not there";
        return 0;
    }

    // cout << b1->data << p1->data << a1->data;
    // cout << b2->data << p2->data << a2->data;

    // check if nodes are adjacent

    if (p1 == b2 || p2 == b1)
    {

        // return 0;
    }

    if (b1)
    {

        b1->next = p2;
    }

    else
    {
        // if p1 is first node

        head = p2;
    }

    p2->next = a1;

    if (b2)
    {
        b2->next = p1;
    }

    else
    {

        // if p2 is first node

        head = p1;
    }

    p1->next = a2;

    printLL(head);

    return 0;
}

/* Driver program to test count function*/
int main()
{
    /* Start with the empty list */
    Node *head = NULL;

    /* Use push() to construct below list 
    1->2->1->3->1 */
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    /* Check the count function */
    // cout << "count of nodes is " << getCount(head);

    swapNodes(2, 3, head);

    // printLL(head);

    return 0;
}
