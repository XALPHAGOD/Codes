#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "abcb";
    unordered_map<char, int> mp;
    for (char c = 'a'; c <= 'z'; c++)
    {
        mp[c] = -1;
    }
    int n = s.length();
    vector<int> dp(n, 0);
    dp[0] = 2;
    mp[s[0]] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 2 * dp[i - 1];
        if (mp[s[i]] == 0)
            dp[i] -= 1;
        else if (mp[s[i]] > 0)
            dp[i] -= dp[mp[s[i]] - 1];
        mp[s[i]] = i;
    }
    cout << dp[n - 1] - 1;
}