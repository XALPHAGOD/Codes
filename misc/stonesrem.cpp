#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r, c, stonecnt;
    cin >> r >> c >> stonecnt;
    vector<pair<int, int>> stones;
    for (int i = 0; i < stonecnt; i++)
    {
        int x, y;
        cin >> x >> y;
        stones.push_back({x, y});
    }
    int moves = 0;

    cout << moves;
}