#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int st;
        cin >> st;
        st--;
        bool vis[n];
        memset(vis, false, sizeof(vis));
        queue<int> q;
        q.push(st);
        bool flag = false;
        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            vis[f] = true;
            if (arr[f] == 0)
            {
                flag = true;
                break;
            }
            if ((f + arr[f]) < n && !vis[f + arr[f]])
            {
                if (arr[f + arr[f]] == 0)
                {
                    flag = true;
                    break;
                }
                q.push(f + arr[f]);
            }
            if ((f - arr[f]) >= 0 && !vis[f - arr[f]])
            {
                if (arr[f - arr[f]] == 0)
                {
                    flag = true;
                    break;
                }
                q.push(f - arr[f]);
            }
        }
        if (flag)
            puts("Yes");
        else
            puts("No");
    }
}