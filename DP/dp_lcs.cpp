/* Dynamic Programming C++ implementation of LCS problem */
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b);

// recursion + memoization
int lcs(string x, string y, int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 || n == 0)
        return dp[m][n] = 0;

    cout << m << " " << n << " " << dp[m][n] << endl;

    if (dp[m][n] != -1)
        return dp[m][n];

    if (x[m - 1] == y[n - 1])
    {
        return dp[m][n] = 1 + lcs(x, y, m - 1, n - 1, dp);
    }

    else
    {
        return dp[m][n] = max(lcs(x, y, m, n - 1, dp), lcs(x, y, m - 1, n, dp));
    }
}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Driver Code
int main()
{
    string x = "AGGTAB";
    string y = "GXTXAYB";

    int m = x.length();
    int n = y.length();

    // int dp[1000][1000];

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    cout << "Length of LCS is "
         << lcs(x, y, m, n, dp) << endl;

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// This code is contributed by rathbhupendra
