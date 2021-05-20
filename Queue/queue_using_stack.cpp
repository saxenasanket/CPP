// C++ program to find whether an array
// is subset of another array
// enqueue is O(1) here but dequeue is O(n) here

#include <bits/stdc++.h>

using namespace std;

class Queue
{

public:
    stack<int> s1, s2;

    void enqueue(int);
    int dequeue();
};

void Queue::enqueue(int val)
{
    // simply push element to stack1
    s1.push(val);
    return;
};

int Queue::dequeue()
{

    if (s1.empty() && s2.empty())
    {

        throw std::runtime_error("queue is empty");
        return 0;
    }

    if (s2.empty())
    {

        while (!s1.empty())
        {
            int top = s1.top();
            s1.pop();
            s2.push(top);
        }
    }

    int top = s2.top();
    s2.pop();
    return top;
};

// Driver code
int main()
{

    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.dequeue();

    q.enqueue(5);

    cout << q.dequeue();

    // getchar();
    return 0;
}
