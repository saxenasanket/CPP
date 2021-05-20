// C++ program to find whether an array
// is subset of another array
#include <bits/stdc++.h>

using namespace std;

/* Return 1 if arr2[] is a subset of
arr1[] */
bool isSubset(int arr1[], int arr2[],
              int m, int n)
{
    unordered_set<int> h;
    int found = 0;

    for (int i = 0; i < n; i++)
    {
        h.insert(arr2[i]);
    }

    for (int i = 0; i < m; i++)
    {
        // if found increment
        if (h.find(arr1[i]) != h.end())
        {
            found++;
        }
    }

    return found == n;
}

// Driver code
int main()
{
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1, 6};

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    if (isSubset(arr1, arr2, m, n))
        printf("arr2[] is subset of arr1[] ");
    else
        printf("arr2[] is not a subset of arr1[]");

    // getchar();
    return 0;
}
