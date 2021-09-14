#include <bits/stdc++.h>
using namespace std;
bool prime[1000001];
void sieve()
{
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= 1000000; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 1000000; j += i)
                prime[j] = false;
        }
    }
}
vector<int> dp;
int n;
int solve(string s, int ind, int &x1, int &x2)
{
    ++x1;
    if (ind == n)
        return 1;
    if (dp[ind] != -1)
        return dp[ind];
    if (s[ind] == '0')
        return dp[ind] = 0;
    int cnt = 0;
    string t = "";
    for (int i = ind; i < n; i++)
    {
        t.push_back(s[i]);
        if (prime[stoi(t)])
        {
            cnt += solve(s, i + 1, x1, x2);
        }
    }
    ++x2;
    return dp[ind] = cnt;
}
int main()
{
    sieve();
    string s;
    getline(cin, s);
    n = s.length();
    int x1 = 0;
    int x2 = 0;
    dp.resize(n, -1);
    cout << solve(s, 0, x1, x2) << " ";
    // cout << x1 << " " << x2 << "\n";
    // for (int i : dp)
    //     cout << i << " ";
}