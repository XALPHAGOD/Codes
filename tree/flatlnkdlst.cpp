void flatten(Node *root)
{
    if (!root)
        return;
    flatten(root->left);
    Node *right = root->right;
    root->right = root->left;
    root->left = NULL;
    if (root->right)
    {
        Node *t = root->right;
        while (t->right)
            t = t->right;
        t->right = right;
    }
    else
        root->right = right;
    flatten(right);
}