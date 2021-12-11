#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> pp;
bool customComp(pp a, pp b)
{
    return (a.first.first == b.first.first) ? (a.first.second < b.first.second) : (a.first.first < b.first.first);
}
int main()
{
    int arr[] = {2, 6, 8, 3};
    int x = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<pp> vec(n);
    for (int i = 0; i < n; i++)
        vec[i] = {{abs(x - arr[i]), i}, arr[i]};
    sort(vec.begin(), vec.end(), customComp);
    for (pp i : vec)
        cout << i.second << " ";
}