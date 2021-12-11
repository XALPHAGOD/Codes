#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n), res(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) //init stack with elems in asc ord from rev dir
    {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();
        st.push(arr[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();
        if (st.empty())
            res[i] = -1;
        else
            res[i] = st.top();
        st.push(arr[i]);
    }
    for (int i : res)
        cout << i << " ";
}