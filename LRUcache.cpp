#include <bits/stdc++.h> //unord_map & dll
using namespace std;
typedef struct node
{
    int val;
    struct node *left, *right;
} Node;
void moveFront(Node **x, Node **head, Node **cur)
{
    if ((*x) == (*head))
        return;
    if ((*x) == (*cur))
        (*cur) = (*cur)->left;
    (*x)->left->right = (*x)->right;
    if ((*x)->right)
        (*x)->right->left = (*x)->left;
    (*x)->right = (*head);
    (*x)->left = NULL;
    (*head)->left = (*x);
    (*head) = (*x);
}
void addFront(int d, Node **head, Node **cur)
{
    Node *x = new Node();
    x->val = d;
    x->left = NULL;
    x->right = (*head);
    if (!(*head))
        (*cur) = x;
    else
        (*head)->left = x;
    (*head) = x;
}
void removeLeast(Node **head, Node **cur)
{
    if ((*cur)->left)
    {
        Node *x = (*cur)->left;
        x->right = NULL;
        free((*cur));
        (*cur) = x;
    }
    else
    {
        free((*head));
        (*head) = (*cur) = NULL;
    }
}
int main()
{
    unordered_map<int, Node *> mp;
    int cnt = 0, size;
    while (true)
    {
        cout << "Set Size: ";
        cin >> size;
        if (size > 0)
            break;
    }
    Node *head = NULL, *cur = NULL;
    cout << "Start Caching:\n";
    cout << "CUR    LRU\n";
    while (true)
    {
        int d;
        cin >> d;
        if (d == -1)
            break;
        if (mp.find(d) != mp.end() && mp[d])
            moveFront(&mp[d], &head, &cur);
        else
        {
            if (cnt == size)
            {
                mp[cur->val] = NULL;
                removeLeast(&head, &cur);
                cnt--;
            }
            addFront(d, &head, &cur);
            mp[d] = head;
            cnt++;
        }
        cout << "\t" << cur->val << "\n";
    }
    while (head)
    {
        Node *x = head;
        head = head->right;
        free(x);
    }
}