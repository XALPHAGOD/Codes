#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, maxi;
    cin >> n;
    vector<int> buy(n), sell(n, 0), skip(n, 0);
    for (int i = 0; i < n; i++)
        cin >> buy[i];
    // sell[0] = 0;
    // skip[0] = 0;
    // for (int i = 1; i < n; i++)
    // {
    //     maxi = 0;
    //     for (int j = 0; j < i; j++)
    //     {
    //         if (buy[i] > buy[j])
    //             sell[i] = max(sell[i], buy[i] - buy[j] + skip[j]);
    //         maxi = max(maxi, sell[j]);
    //     }
    //     skip[i] = maxi;
    // }
    // cout << max(sell[n - 1], skip[n - 1]);

    maxi = 0;
    for (int i = 1; i < n; i++)
    {
        if (buy[i] > buy[i - 1])
            maxi += buy[i] - buy[i - 1];
    }
    cout << maxi;
}