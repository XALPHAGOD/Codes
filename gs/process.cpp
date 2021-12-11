#include <bits/stdc++.h>
using namespace std;
int main()
{
    int p, q;
    cin >> p >> q;
    vector<char> state(p, 'A');
    for (int i = 0; i < q; i++)
    {
        char src, dst;
        int proc;
        cin >> src >> dst >> proc;
        proc--;
        if (state[proc] == src)
            state[proc] = dst;
    }
    vector<int> ans[5];
    for (int i = 0; i < p; i++)
        ans[state[i] - 'A'].push_back(i + 1);
    for (int i = 0; i < 5; i++)
    {
        cout << (char)('A' + i) << " ";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}