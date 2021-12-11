#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n), left(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if (st.empty())
            left[i] = -1;
        else
            left[i] = st.top();
        st.push(i);
    }
    int maxi = 0;
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        if (st.empty())
            maxi = max(maxi, (n - left[i] - 1) * arr[i]);
        else
            maxi = max(maxi, (st.top() - left[i] - 1) * arr[i]);
        st.push(i);
    }
    cout << maxi;
}