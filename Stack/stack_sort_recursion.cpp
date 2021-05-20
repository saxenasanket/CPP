
#include <bits/stdc++.h>
using namespace std;

void insertElement(stack<int> &s, int elm)
{
    if (s.empty())
    {

        s.push(elm);
        return;
    }
    int top = s.top();
    if (elm > top)
    {
        s.pop();
        insertElement(s, elm);
    }
    else
    {
        s.push(elm);
        return;
    }

    s.push(top);

    return;
}

void sortStack(stack<int> &s)
{

    if (s.empty())
        return;
    int top = s.top();
    s.pop();
    sortStack(s);
    insertElement(s, top);

    return;
}

int main()
{

    stack<int> s;

    s.push(1);
    s.push(4);
    s.push(2);
    s.push(3);
    s.push(996);
    s.push(0);
    s.push(10);

    sortStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}