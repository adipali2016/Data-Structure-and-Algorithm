#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int n)
    {
        val = n;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node* root, int n)
{
    if(root == NULL)
    {
        return new Node(n);
    }

    if(root->val > n)
    {
        root->left = insertBST(root->left, n);
    }
    else
    {
        root->right = insertBST(root->right, n);
    }

    return root;
}

void inOrder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

//Searching in a BST
Node* searchBST(Node* root, int n)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->val == n)
    {
        return root;
    }

    if(root->val > n)
    {
        return searchBST(root->left, n);
    }

    return searchBST(root->right, n);
}

//Deletion in BST
Node* inOrderSucc(Node* root)
{
    Node* curr = root;
    while(curr && curr->left != NULL)
    {
        curr = curr->left;
    }

    return curr;
}

Node* deleteBST(Node* root, int n)
{
    if(root->val > n)
    {
        root->left = deleteBST(root->left, n);
    }
    else if(root->val < n)
    {
        root->right = deleteBST(root->right, n);
    }
    else{
        if(root->left == NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        Node* temp = inOrderSucc(root->right);
        root->val = temp->val;
        root->right = deleteBST(root->right, temp->val);    
    }

    return root;
}

Node* preOrder(int preorder[], int *preorderidx, int key, int min, int max, int n)
{   
    if(*preorderidx>=n)
    {
        return NULL;
    }

    Node* root = NULL;
    if(key<max && key>min)
    {
        root = new Node(key);
        *preorderidx = *preorderidx + 1;
        if(*preorderidx<n)
        {
            root->left = preOrder(preorder, preorderidx, preorder[*preorderidx], min, key, n);
        }
        if(*preorderidx<n)
        {
            root->right = preOrder(preorder, preorderidx, preorder[*preorderidx], key, max, n);
        }
    }

    return root;
}


int main()
{
    Node* root = NULL;
    root = insertBST(root,6);
    insertBST(root,3);
    insertBST(root,7);
    insertBST(root,1);
    insertBST(root,8);
    insertBST(root,2);

    //Print Inorder
    inOrder(root);
    cout<<endl;

    //Searching in BST
    if(searchBST(root, 5)!=NULL)
    {
        cout<<"exists"<<endl;
    }
    else{
        cout<<"No existence"<<endl;
    }

    deleteBST(root, 7);
    inOrder(root);
    cout<<endl;

    //BST through preOrder array.
    int preorder[] = {7,5,4,6,8,9};
    int preorderidx = 0;
    Node* root2 = preOrder(preorder, &preorderidx, preorder[0], INT16_MIN, INT16_MAX, 6);
    inOrder(root2);
    cout<<endl;

}