#include <bits/stdc++.h>
using namespace std;

// if order matters
int count(int S[], int m, int n, vector<int> &vec, vector<int> &dp)
{
    if (n == 0)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
        return 1;
    }

    if (n < 1)
    {
        return 0;
    }

    if (dp[n] != -1)
        return dp[n];

    int cnt = 0;
    // get count for all possible steps in
    for (int i = 0; i < m; i++)
    {
        // let's add element at i idx
        vec.push_back(S[i]);
        cnt += count(S, m, n - S[i], vec, dp);
        vec.pop_back();
    }

    return dp[n] = cnt;
}

// Driver program to test above function
int main()
{
    int i, j;
    int arr[] = {1, 2, 3};
    int m = sizeof(arr) / sizeof(arr[0]);

    vector<int> vec;

    vector<int> dp(5, -1);
    count(arr, m, 4, vec, dp);

    // for (int i = 0; i < dp.size(); i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    return 0;
}