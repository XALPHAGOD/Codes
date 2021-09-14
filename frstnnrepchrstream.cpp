#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    char ch;
    struct node *left, *right;
} Node;
void addNode(char x, Node **head, Node **cur, vector<Node *> &point)
{
    Node *n = new Node();
    n->ch = x;
    n->left = (*cur);
    n->right = NULL;
    if (!(*head))
        (*head) = n;
    else
        (*cur)->right = n;
    (*cur) = n;
    point[x] = n;
}
void deleteNode(char x, Node **head, Node **cur, vector<Node *> &point)
{
    Node *p = point[x];
    point[x] = NULL;
    if (p == (*head))
        (*head) = (*head)->right;
    if (p == (*cur))
        (*cur) = (*cur)->left;
    if (p->left)
        p->left->right = p->right;
    if (p->right)
        p->right->left = p->left;
    free(p);
}
int main()
{
    string s;
    getline(cin, s);
    // vector<int> cnt(256, 0);
    // queue<char> q;
    // for (char c : s)
    // {
    //     if (cnt[c] == 0)
    //         q.push(c);
    //     cnt[c]++;
    //     while (!q.empty() && cnt[q.front()] > 1)
    //         q.pop();
    //     cout << q.front() << " ";
    // }
    // // for (int i : cnt)
    // //     cout << i << " ";
    // cout << "\n"
    //      << q.front();

    vector<bool> repeated(256, false);
    vector<Node *> point(256, NULL);
    Node *head = NULL, *cur = NULL;
    for (char c : s)
    {
        if (!repeated[c] && !point[c])
            addNode(c, &head, &cur, point);
        else if (!repeated[c] && point[c])
        {
            repeated[c] = true;
            deleteNode(c, &head, &cur, point);
        }
        // Node *t = head;
        // while (t)
        // {
        //     cout << t->ch;
        //     t = t->right;
        //     if (t)
        //         cout << " -> ";
        // }
        // cout << "\n";
        cout << (head ? head->ch : '#') << " ";
    }
    // if (head)
    //     cout << head->ch;
}