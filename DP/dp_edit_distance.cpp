#include <bits/stdc++.h>
using namespace std;

// Utility function to find minimum of three numbers
int min(int x, int y, int z) { return min(min(x, y), z); }

// recusrion + memoization
int editDist(string str1, string str2, int m, int n, vector<vector<int>> &vec)
{

  if (m == 0)
    return vec[m][n] = n;

  if (n == 0)
    return vec[m][n] = m;

  if (vec[m][n] != -1)
    return vec[m][n];

  cout << m << " " << n << endl;

  if (str1[m] == str2[n])
  {
    return vec[m][n] = editDist(str1, str2, m - 1, n - 1, vec);
  }

  else
    return vec[m][n] = 1 + min(editDist(str1, str2, m - 1, n, vec), editDist(str1, str2, m, n - 1, vec), editDist(str1, str2, m - 1, n - 1, vec));
}

// Driver code
int main()
{
  // your code goes here
  string str1 = "sunday";
  string str2 = "saturday";

  vector<vector<int>> vec(str1.length() + 1, vector<int>(str2.length() + 1, -1));

  cout << editDist(str1, str2, str1.length(),
                   str2.length(), vec);

  return 0;
}
