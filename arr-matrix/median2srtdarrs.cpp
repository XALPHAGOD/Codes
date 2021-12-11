#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n1, n2;
    cin >> n1;
    cout << "Enter 1st array: ";
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];

    cin >> n2;
    cout << "Enter 2nd array: ";
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    for (int i : arr1)
        cout << i << " ";
    cout << endl;
    for (int i : arr2)
        cout << i << " ";
}