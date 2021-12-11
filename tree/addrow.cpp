#include <bits/stdc++.h>
using namespace std;
typedef pair<Node *, int> PP;
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
Node *addrow(Node *root, int k)
{
    if (!root)
        return root;
    k--;
    queue<PP> q;
    queue<Node *> res;
    q.push({root, 0});
    while (!q.empty())
    {
        PP p = q.front();
        Node *t = p.first;
        int h = p.second;
        q.pop();
        if (h > k)
            continue;
        if (h == k)
            res.push(t);
        else
        {
            if (t->left)
                q.push({t->left, h + 1});
            if (t->right)
                q.push({t->right, h + 1});
        }
    }
    while (!res.empty())
    {
        Node *t = res.front();
        res.pop();
        if (t->left)
        {
            Node *x = new Node(0);
            x->left = t->left;
            t->left = x;
        }
        if (t->right)
        {
            Node *x = new Node(0);
            x->right = t->right;
            t->right = x;
        }
    }
}