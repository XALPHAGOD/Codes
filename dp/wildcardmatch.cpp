#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, p;
    getline(cin, s);
    getline(cin, p);
    int sl = s.length(), pl = p.length();

    bool dp[pl + 1][sl + 1];

    for (int r = pl; r >= 0; r--)
    {
        bool forstar = false;
        for (int c = sl; c >= 0; c--)
        {
            forstar |= dp[r + 1][c];    // optimisation for * to prevent O(n^3)

            if (r == pl && c == sl)
                dp[r][c] = true;
            else if (r == pl)
                dp[r][c] = false;
            else if (c == sl)
            {
                if (p[r] == '*')
                    dp[r][c] = dp[r + 1][c];
                else
                    dp[r][c] = false;
            }
            else
            {
                if (p[r] == '?')
                    dp[r][c] = dp[r + 1][c + 1];
                else if (p[r] == '*')       // most important
                    dp[r][c] = forstar;
                else
                    dp[r][c] = (p[r] == s[c]) && dp[r + 1][c + 1];
            }
        }
    }

    for (int i = 0; i <= pl; cout << "\n", i++)
        for (int j = 0; j <= sl; j++)
            cout << dp[i][j] << " ";

    cout << dp[0][0];
}