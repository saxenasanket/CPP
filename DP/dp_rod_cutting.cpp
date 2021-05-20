#include <bits/stdc++.h>
using namespace std;

// A utility function to get the maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

/* Returns the best obtainable price for a rod of length n and
price[] as prices of different pieces */
int cutRod(int price[], int n, vector<int> &vec)
{

    if (n == 0)
        return 0;

    if (vec[n] != -1)
        return vec[n];

    cout << n << endl;
    int mx = -1;
    for (int i = 1; i <= n; i++)
    {

        mx = max(mx, price[i - 1] + cutRod(price, n - i, vec));
    }

    return vec[n] = mx;
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> vec(size + 1, -1);
    printf("Maximum Obtainable Value is %dn", cutRod(arr, size, vec));
    // getchar();
    return 0;
}
