#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> dp(n, 0);
    int lowest = arr[0];
    int maxtr = 0;
    for (int i = 0; i < n; i++)
    {
        lowest = min(lowest, arr[i]);
        maxtr = max(maxtr, arr[i] - lowest);
        dp[i] = maxtr;
        cout << dp[i] << " ";
    }
    cout << "\n";
    int gmax = 0;
    // for (int i = 0; i < n; i++)  O(n^2)
    // {
    //     int maxi = 0;
    //     for (int j = 0; j < i; j++)
    //     {
    //         maxi = max(maxi, dp[j] + max(arr[i] - arr[j], 0));
    //     }
    //     gmax = max(gmax, maxi);
    //     cout << gmax << " ";
    // }
    // cout << gmax;
    int maxsp = arr[n - 1];
    stack<int> forPrinting;
    forPrinting.push(dp[n - 1]);
    for (int i = n - 2; i >= 0; i--) //O(n)
    {
        maxsp = max(maxsp, arr[i]);
        gmax = max(gmax, dp[i] + maxsp - arr[i]);
        forPrinting.push(gmax);
    }
    while (!forPrinting.empty())
    {
        cout << forPrinting.top() << " ";
        forPrinting.pop();
    }
}