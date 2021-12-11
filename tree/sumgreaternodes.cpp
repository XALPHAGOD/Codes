int revInorder(Node *root, int sum)
{
    if (!root)
        return 0;
    int right = revInorder(root->right, sum);
    int cpy = root->data;
    root->data = right + sum;
    int left = revInorder(root->left, root->data + cpy);
    return cpy + left + right;
}

void revInorder(Node *root, int *sum)
{
    if (!root)
        return;
    revInorder(root->right, sum);
    *sum += root->data;
    root->data = *sum - root->data;
    revInorder(root->left, sum);
}