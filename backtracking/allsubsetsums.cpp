#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    vector<int> sums;
    sums.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int j = sums.size();
        for (int k = 0; k < j; k++)
            sums.push_back(sums[k] + arr[i]);
    }
    for (int i : sums)
        cout << i << " ";
}