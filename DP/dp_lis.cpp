/* Dynamic Programming C++ implementation of LCS problem */
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

// recursion + memoization
int lis(int arr[], int n, int dp[])
{
    if (n == 0)
    {
        return dp[0] = 1;
    }

    int mx = 1;

    for (int i = 0; i <= n - 1; i++)
    {
        if (arr[n - 1] > arr[i])
        {
            mx = max(mx, 1 + lis(arr, i, dp));
        }
        else
        {
            mx = max(mx, lis(arr, i, dp));
        }
    }

    return dp[n] = mx;
}

/* Driver program to test above function */
int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    int dp[n];

    for (int i = 0; i < n; i++)
    {
        // store the outputs in dp array
        dp[i] = -1;
    }

    printf("Length of lis is %dn", lis(arr, n, dp));
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }

    return 0;
}
