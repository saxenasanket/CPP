#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n, int idx, vector<vector<int>> &vec)
{

    if (idx == n)
    {
        return vec[idx][W] = 0;
    }

    // included if W>=wt[idx]
    int val1 = -1;

    if (vec[idx][W] != -1)
    {
        return vec[idx][W];
    }

    cout << idx << " " << W << endl;

    if (W >= wt[idx])
    {
        val1 = val[idx] + knapSack(W - wt[idx], wt, val, n, idx + 1, vec);
    }

    // excluded
    int val2 = knapSack(W, wt, val, n, idx + 1, vec);

    // return the maximum value
    return vec[idx][W] = max(val1, val2);
}

// Driver code
int main()
{
    int val[] = {10, 15, 40};
    int wt[] = {10, 10, 10};
    int W = 30;
    int n = sizeof(val) / sizeof(val[0]);

    vector<vector<int>> vec(n + 1, vector<int>(W + 1, -1));
    cout
        << knapSack(W, wt, val, n, 0, vec) << endl;

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= W; j++)
    //     {
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}