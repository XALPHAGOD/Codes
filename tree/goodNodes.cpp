void cnt(Node *root, int &cnt, int maxi)
{
    if (!root)
        return;
    if (root->val >= maxi)
    {
        cnt++;
        maxi = root->val;
    }
    cnt(root->left, cnt, maxi);
    cnt(root->right, cnt, maxi);
}

int cnt = 1;
cnt(root, cnt, INT_MIN);
cout << cnt;