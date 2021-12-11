vector<int> diagSum(Node *root)
{
    queue<Node *> q;
    vector<int> sum;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        int s = 0;
        while (n--)
        {
            Node *t = q.front();
            q.pop();
            while (t)
            {
                s += t->data;
                if (t->left)
                    q.push(t->left);
                t = t->right;
            }
        }
        sum.push_back(s);
    }
    return sum;
}