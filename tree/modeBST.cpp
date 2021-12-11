int maxfreq = 0, curfreq = 0;
TreeNode *prev = NULL;

void inOrder(TreeNode *root, vector<int> &vec)
{
    if (!root)
        return;
    inOrder(root->left, vec);
    if (prev)
    {
        if (prev->val == root->val)
        {
            curfreq++;
            if (curfreq > maxfreq)
            {
                maxfreq = curfreq;
                vec.clear();
                vec.push_back(root->val);
            }
            else if (curfreq == maxfreq)
                vec.push_back(root->val);
        }
        else
        {
            curfreq = 1;
            if (curfreq == maxfreq)
                vec.push_back(root->val);
        }
    }
    else
    {
        maxfreq = curfreq = 1;
        vec.push_back(root->val);
    }
    prev = root;
    inOrder(root->right, vec);
}
vector<int> findMode(TreeNode *root)
{
    vector<int> res;
    inOrder(root, res);
    return res;
}