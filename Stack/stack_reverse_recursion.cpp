// C++ code to reverse a
// stack using recursion
#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<char> &s, char elm)
{
    if (s.empty())
    {
        s.push(elm);
        return;
    }
    char top = s.top();
    s.pop();

    insertAtBottom(s, elm);

    s.push(top);

    return;
}

void reverse(stack<char> &s)
{

    if (s.empty())
        return;
    char top = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, top);

    return;
}

// Driver Code
int main()
{

    // using std::stack for
    // stack implementation
    stack<char> st;

    // intializing a string to store
    // result of reversed stacks
    string ns = "";

    // push elements into
    // the stack
    st.push('1');
    st.push('2');
    st.push('6');
    st.push('3');
    st.push('4');
    // function to reverse
    // the stack
    reverse(st);

    // insertAtBottom(st, '5');
    cout
        << "Reversed Stack"
        << endl;

    while (!st.empty())
    {
        char p = st.top();
        st.pop();
        ns += p;
    }

    //display of reversed stack
    cout << ns << endl;
    return 0;
}
