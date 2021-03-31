#include<bits/stdc++.h>
using namespace std;
int c=0;
struct node
{
    int val;
    node *left,*right;
    node(int x)
    {
        val=x;
        left=NULL;
        right=NULL;
    }
};
node *head=NULL;
node* func(string x)
{
    if(x[c]==')')
    {
        c++;
        return NULL;
    }
    if(x[c]=='(')
        c++;
    node *t=new node(x[c++]-'0');
    t->left=func(x);
    if(!t->left)
    {
        t->right=NULL;
        return t;
    }
    t->right=func(x);
    c++;
    return t;
}
void disp(node *x)
{
    if(!x)
        return;
    cout<<x->val<<" ";
    disp(x->left);
    disp(x->right);
}
int main()
{
    string x;
    getline(cin,x);
    if(x[0]=='(')
        return 0;
    head=func(x);
    disp(head);
}