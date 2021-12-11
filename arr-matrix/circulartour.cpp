#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[][2] = {{6, 4}, {3, 6}, {7, 3}}, n = 3;
    int extra = 0, needed = 0, start = 0;
    for (int i = 0; i < n; i++)
    {
        extra += arr[i][0] - arr[i][1];
        if (extra < 0) //  extra<0 => needed increment by extra value
        {
            needed += extra;
            extra = 0;
            start = i + 1;
        }
    }
    if ((extra + needed) >= 0)
        cout << start;
    else
        cout << -1;
}