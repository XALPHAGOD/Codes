#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int, int>, string> pp;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n)), dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (j == n - 1)
                dp[i][j] = arr[i][j];
        }
    }

    int maxi = 0;
    for (int col = n - 2; col >= 0; col--)
    {
        for (int row = 0; row < n; row++)
        {
            if (row == 0)
                dp[row][col] = arr[row][col] + max(dp[row][col + 1], dp[row + 1][col + 1]);
            else if (row == n - 1)
                dp[row][col] = arr[row][col] + max(dp[row][col + 1], dp[row - 1][col + 1]);
            else
                dp[row][col] = arr[row][col] + max(dp[row][col + 1], max(dp[row + 1][col + 1], dp[row - 1][col + 1]));

            maxi = max(maxi, dp[row][col]);
        }
    }

    // for(int i=0;i<n;cout<<"\n",i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    // }
    // cout<<maxi;
    cout<<"\n";

    queue<pp> q;
    for (int i = 0; i < n; i++)
    {
        if (dp[i][0] == maxi)
        {
            q.push({{i, 0}, to_string(i + 1) + " "});
        }
    }

    while (!q.empty())
    {
        pp x = q.front();
        q.pop();
        int r = x.first.first, c = x.first.second;
        string s = x.second;

        if (c == n - 1)
        {
            cout << s << "\n";
            continue;
        }

        if (r == 0)
        {
            int tm = max(dp[r][c + 1], dp[r + 1][c + 1]);
            if (tm == dp[r][c + 1])
                q.push({{r, c + 1}, s + "d2 "});
            if (tm == dp[r + 1][c + 1])
                q.push({{r + 1, c + 1}, s + "d3 "});
        }
        else if (r == n - 1)
        {
            int tm = max(dp[r][c + 1], dp[r - 1][c + 1]);
            if (tm == dp[r][c + 1])
                q.push({{r, c + 1}, s + "d2 "});
            if (tm == dp[r - 1][c + 1])
                q.push({{r - 1, c + 1}, s + "d1 "});
        }
        else
        {
            int tm = max(dp[r][c + 1], max(dp[r - 1][c + 1], dp[r + 1][c + 1]));
            if (tm == dp[r][c + 1])
                q.push({{r, c + 1}, s + "d2 "});
            if (tm == dp[r + 1][c + 1])
                q.push({{r + 1, c + 1}, s + "d3 "});
            if (tm == dp[r - 1][c + 1])
                q.push({{r - 1, c + 1}, s + "d1 "});
        }
    }
}