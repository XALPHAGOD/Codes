#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int, int>, string> pp;

int main()
{
    int n, s = 0;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; s += arr[i], i++)
        cin >> arr[i];

    int sum;
    cin >> sum;

    if (sum > s)
    {
        cout << "Not Possible";
    }
    else
    {
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (j < arr[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
        }

        // for (int i = 0; i <= n; cout << "\n", i++)
        //     for (int j = 0; j <= sum; j++)
        //         cout << dp[i][j] << " ";

        // cout << "\n";

        queue<pp> q;

        if (dp[n][sum])
            q.push({{n, sum}, ""});

        while (!q.empty())
        {
            pp x = q.front();
            q.pop();

            int r = x.first.first, c = x.first.second;
            string s = x.second;
            // cout << r << " " << c << " " << s << "\n";
            if (c == 0)
            {
                cout << s << "\n";
                continue;
            }

            if (dp[r - 1][c])
                q.push({{r - 1, c}, s});

            if (c >= arr[r - 1] && dp[r - 1][c - arr[r - 1]])
                q.push({{r - 1, c - arr[r - 1]}, to_string(r - 1) + " " + s});
        }
    }
}