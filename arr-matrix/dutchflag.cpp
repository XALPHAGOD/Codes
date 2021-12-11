#include <bits/stdc++.h>
using namespace std;
void swap(int *arr, int i, int j)
{
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}
int main()
{
    int arr[] = {0, 1, 1, 0, 2, 0, 1, 0, 1, 1, 2, 1, 0, 1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]), head = 0, tail = n - 1, i = 0;
    while (i <= tail)
    {
        if (arr[i] == 0)
        {
            swap(arr, i, head);
            head++;
            i++;
        }
        else if (arr[i] == 2)
        {
            swap(arr, i, tail);
            tail--;
        }
        else
            i++;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}