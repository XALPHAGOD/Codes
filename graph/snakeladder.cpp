#include <bits/stdc++.h>
using namespace std;
int calc(vector<int> &board, int n)
{
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    board[0] = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int i = t + 1; i <= t + 6 && i < n; i++)
        {
            if (!vis[i])
            {
                vis[i] = true;
                if (board[i] == -1)
                    q.push(i);
                else if (board[i] > i)
                {
                    q.push(board[i]);
                    board[board[i]] = board[t] + 1;
                }
                board[i] = board[t] + 1;
                if (i == (n - 1))
                    break;
            }
        }
    }
    return board[n - 1];
}
int main()
{
    int n = 30;
    vector<int> board(n, -1);
    board[2] = 21;
    board[4] = 7;
    board[10] = 25;
    board[19] = 28;

    board[26] = 0;
    board[20] = 8;
    board[16] = 3;
    board[18] = 6;
    cout << calc(board, n) << endl;
    for (int i : board)
        cout << i << " ";
}