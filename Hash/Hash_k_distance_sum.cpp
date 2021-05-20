#include <bits/stdc++.h>
using namespace std;

/* C++ program to Check if a given array contains duplicate
elements within k distance from each other */
bool checkDuplicatesWithinK(int arr[], int n, int k)
{
    // create unordered map<int, int> for elm and idx arrays
    unordered_map<int, int> m;

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (m.find(arr[i]) == m.end())
        {

            m[arr[i]] = i;
        }
        else
        {

            // get the latest previous idx
            int idx = m[arr[i]];

            cout << arr[i] << " " << idx << " " << i;
            if (i - idx < k)
            {
                // element found within k distance
                found = true;
            }
            else
            {

                m[arr[i]] = i;
            }
        }
    }

    return found;
}

// using unordered_set

bool checkDuplicatesWithinKUnorderedSet(int arr[], int n, int k)
{
    // create unordered map<int, int> for elm and idx arrays
    unordered_set<int> m;

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (m.find(arr[i]) == m.end())
        {

            m.insert(arr[i]);
        }
        else
        {

            found = true;
            cout << i;
            break;
        }

        m.erase(arr[i - k]);
    }

    return found;
}

// Driver method to test above method
int main()
{
    int arr[] = {10, 5, 3, 4, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (checkDuplicatesWithinKUnorderedSet(arr, n, 3))
        cout << "Yes";
    else
        cout << "No";
}

//This article is contributed by Chhavi
