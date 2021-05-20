// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c)
{
    int val = (int)c - 48;

    return val >= 0 && val < 10;
}

int evaluatePostfix(string exp)
{

    stack<int> s;
    // s.push(2);
    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];

        if (isOperand(c))
        {
            s.push((int)c - 48);
        }

        else
        {
            // pop two elements evaluate and push

            int first = s.top();
            s.pop();
            int second = s.top();
            s.pop();

            switch (c)
            {

            case '+':
            {
                s.push(first + second);
                break;
            }

            case '-':
            {
                s.push(second - first);
                break;
            }

            case '*':
            {
                s.push(first * second);
                break;
            }

            case '/':
            {
                s.push(second / first);
                break;
            }
            }
        }
        // cout << c << " " << s.top() << endl;
    }

    return s.top();
}

// Driver program to test above functions
int main()
{
    string exp = "231*+9-";
    int result = evaluatePostfix(exp);
    cout << "postfix evaluation: " << result;
    return 0;
}
