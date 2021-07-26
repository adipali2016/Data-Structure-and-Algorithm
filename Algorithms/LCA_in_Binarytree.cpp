#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};

bool getPath(Node* root, vector<int> &path, int n)
{
    if(root==NULL)
    {
        return false;
    }
    path.push_back(root->val);

    if(root->val==n)
    {
        return true;
    }
    if(getPath(root->left, path, n) || getPath(root->right, path, n))
    {
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2)
{
    vector<int> path1, path2;

    if(!getPath(root, path1, n1) || !getPath(root, path2, n2))
    {
        return -1;
    }

    int pc=0;
    for(pc=0; pc<path1.size() && pc<path2.size(); pc++)
    {
        if(path1[pc]!=path2[pc])
        {
            break;
        }
    }

    return path1[pc-1];
}

Node* LCA2(Node* root, int n1, int n2)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->val == n1 || root->val == n2)
    {
        return root;
    }

    Node* leftL = LCA2(root->left, n1, n2);
    Node* rightL = LCA2(root->right, n1, n2);

    if(leftL && rightL)
    {
        return root;
    }

    if(leftL!=NULL)
    {
        return leftL;
    }

    return rightL;

}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->right = new Node(7);

    cout<<LCA(root,6,7)<<endl;

    cout<<LCA2(root, 4, 7)->val<<endl;

}