bool isBST(Node *root, Node *gt, Node *lt)
{
    if (!root)
        return true;
    if (gt && root->val <= gt->val)
        return false;
    if (lt && root->val >= lt->val)
        return false;
    return isBST(root->left, gt, root) && isBST(root->right, root, lt);
}

cout << isBST(root, NULL, NULL);