
// Iterative C++ program to reverse
// a linked list
#include <iostream>
using namespace std;

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList() { head = NULL; }

    /* Function to reverse the linked list */
    void reverse()
    {
        Node *next = head, *temp = NULL;

        while (next)
        {
            next = head->next;
            head->next = temp;
            temp = head;
            if (next)
                head = next;
        }
    }

    /* Function to reverse the linked list in recursive way */
    Node *rreverse(Node *head)
    {

        if (head->next == NULL)
        {
            return head;
        }

        Node *rest = rreverse(head->next);
        head->next->next = head;

        head->next = NULL;

        return rest;
    }

    int length = 0;

    /* Function to reverse the linked list in recursive way */
    Node *kreverse(Node *head, int k)
    {
        Node *current = head, *prev = NULL, *next = NULL, *last, *ref = NULL;
        int batch = 0;
        while (current)
        {
            // take chunck of k size
            int cnt = k;
            last = current;
            while (cnt-- && current)
            {
                next = current->next;
                if (!batch % 2)
                    current->next = prev;
                prev = current;
                current = next;
            }

            if (ref == NULL)
            {
                ref = prev;
            }

            if (!batch % 2)
                last->next = current;

            batch++;
        }

        return ref;
    }
    /* Function to print linked list */
    void print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

/* Driver code*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);
    ll.push(5);
    ll.push(6);
    ll.push(7);
    ll.push(8);
    ll.push(9);
    ll.push(10);
    ll.push(11);
    ll.push(12);
    ll.push(13);

    // cout << "Given linked list\n";
    // ll.print();

    // ll.reverse();

    // Node *ptr = ll.rreverse(ll.head);

    Node *ptr = ll.kreverse(ll.head, 3);

    while (ptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    // cout
    //     << "\nReversed Linked list \n";
    // ll.print();
    return 0;
}