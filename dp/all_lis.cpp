#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> pp;

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n), dp(n, 1);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int lenlis = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                lenlis = max(lenlis, dp[i]);
            }
        }
    }

    // for (int x : dp)
    //     cout << x << " ";

    queue<pp> q;

    for (int i = 0; i < n; i++)
    {
        if (dp[i] == lenlis)
        {
            q.push({i, to_string(arr[i])});
        }
    }

    int cnt = 0;
    while (!q.empty())
    {
        cnt++;
        pp x = q.front();
        q.pop();

        if (dp[x.first] == 1)
        {
            cout << x.second << "\n";
            continue;
        }

        for (int i = 0; i < x.first; i++)
        {
            if (arr[x.first] > arr[i] && dp[x.first] == dp[i] + 1)      // dp check for optimisation else all dp[i]+2, ... would be included
            {
                q.push({i, to_string(arr[i]) + " " + x.second});
            }
        }
    }

    cout << lenlis << " " << cnt;
}