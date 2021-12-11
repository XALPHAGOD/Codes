#include <bits/stdc++.h>
using namespace std;
// int main() //pairs div by k
// {
//     int arr[] = {2, 2, 1, 7, 5, 3}, k = 4;
//     int n = sizeof(arr) / sizeof(arr[0]);
//     vector<int> freq(k, 0);
//     for (int i = 0; i < n; i++)
//         freq[arr[i] % k]++;
//     int tot = 0;
//     tot += (freq[0] * (freq[0] - 1)) / 2; //directly divisible by k
//     for (int i = 1; i <= (k / 2) && (2 * i) != k; i++)
//         tot += freq[i] * freq[k - i];
//     if (k % 2 == 0)
//         tot += (freq[k / 2] * (freq[k / 2] - 1)) / 2;
//     cout << tot;
// }

int main() //pairs sum to k
{
    int arr[] = {2, 2, 1, 7, 5, 3}, k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    unordered_map<int, int> mp;
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(k - arr[i]) != mp.end())
            tot += mp[k - arr[i]];
        mp[arr[i]]++;
    }
    cout << tot;
}