#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    while (n) //extract digitss into vector
    {
        arr.push_back(n % 10);
        n /= 10;
    }
    reverse(arr.begin(), arr.end());

    int size = arr.size(), pos = size;
    for (int i = size - 1; i > 0; i--) //find specific index
    {
        if (arr[i] > arr[i - 1])
        {
            pos = i - 1;
            break;
        }
    }
    if (pos == size)
    {
        cout << "Not Possible";
        return 0;
    }
    n = arr[size - 1];
    arr[size - 1] = arr[pos];
    arr[pos] = n;

    reverse(arr.begin() + pos + 1, arr.end()); //reverse from index+1 till end
    for (int i : arr)
        cout << i;
}