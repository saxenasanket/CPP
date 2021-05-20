#include <bits/stdc++.h>
using namespace std;

int lp = 0;

int abs(int val1, int val2)
{
    return val1 > val2 ? val1 - val2 : val2 - val1;
}
// Returns minimum possible difference between sums
// of two subsets
int findMin(int arr[], int n, int idx, vector<int> &set1, vector<int> &set2, int sum1, int sum2, int &ans, vector<vector<int>> &vec)
{
    if (idx == n)
    {
        return abs(sum1, sum2);
    }

    int val1, val2;

    // include element at idx in set1
    set1.push_back(arr[idx]);
    if (vec[0][idx] == -1)
        val1 = vec[0][idx] = findMin(arr, n, idx + 1, set1, set2, sum1 + arr[idx], sum2, ans, vec);
    else
        val1 = vec[0][idx];
    set1.pop_back();

    // include element at idx in set2
    set2.push_back(arr[idx]);
    if (vec[1][idx] == -1)
        val2 = vec[1][idx] = findMin(arr, n, idx + 1, set1, set2, sum1, sum2 + arr[idx], ans, vec);
    else
        val2 = vec[1][idx];

    set2.pop_back();

    return min(val1, val2);
}

// Driver program to test above function
int main()
{
    int arr[] = {3, 1, 4, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<vector<int>> vec(2, vector<int>(n + 1, -1));
    vector<int> set1;
    vector<int> set2;
    int ans = INT_MAX;
    cout << findMin(arr, n, 0, set1, set2, 0, 0, ans, vec);

    // cout << "min is " << ans << endl;
    return 0;
}
