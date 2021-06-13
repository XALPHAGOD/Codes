#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    getline(cin, a);

    int n = a.length();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
                dp[i][j] = 1;
            else if (gap == 1)
                dp[i][j] = (a[i] == a[j]) ? 2 : 1;
            else if (a[i] == a[j])
                dp[i][j] = 2 + dp[i + 1][j - 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    // for (int i = 0; i < n; cout << "\n", i++)
    //     for (int j = 0; j < n; j++)
    //         cout << dp[i][j] << " ";

    cout << dp[0][n - 1];
}