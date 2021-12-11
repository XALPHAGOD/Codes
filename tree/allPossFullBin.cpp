#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<Node *> allPossFullBin(int n)
{
    vector<Node *> ans;
    if (n % 2 == 0)
        return ans;
    if (n == 1)
    {
        Node *x = new Node(0);
        ans.push_back(x);
        return ans;
    }
    for (int i = 1; i < n; i += 2)
    {
        vector<Node *> left, right;
        left = allPossFullBin(i);
        right = allPossFullBin(n - i - 1);
        for (Node *l : left)
        {
            for (Node *r : right)
            {
                Node *x = new Node(0);
                x->left = l;
                x->right = r;
                ans.push_back(x);
            }
        }
    }
    return ans;
}