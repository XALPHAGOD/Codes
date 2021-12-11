vector<int> iterPre(Node *root)
{
    vector<int> ans;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *t = st.top();
        st.pop();
        ans.push_back(t->data);
        if (t->right)
            st.push(t->right);
        if (t->left)
            st.push(t->left);
    }
    return ans;
}

vector<int> iterIn(Node *root)
{
    vector<int> ans;
    stack<Node *> st;
    Node *x = root;
    while (true)
    {
        if (x)
        {
            st.push(x);
            x = x->left;
        }
        else
        {
            if (st.empty())
                break;
            x = st.top();
            st.pop();
            ans.push_back(x->data);
            x = x->right;
        }
    }
    return ans;
}

vector<int> iterPos(Node *root)
{
    vector<int> ans;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *t = st.top();
        st.pop();
        ans.push_back(t->data);
        if (t->left)
            st.push(t->left);
        if (t->right)
            st.push(t->right);
    }
    ans.reverse();
    return ans;
}