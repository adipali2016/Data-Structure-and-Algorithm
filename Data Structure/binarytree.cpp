#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;


    Node(int val)
    {
        data = val;
        left=NULL;
        right=NULL;
    }
};

//Traversal

//1. PreOrder
void preOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

//2. InOrder
void inOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

//3. PostOrder
void postOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

//4. Level order Traversal
void levelOrder(Node* root)
{
    if(root ==  NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();
        if(node!=NULL)
        {
            cout<<node->data<<" ";
            if(node->left!=NULL)
            {
                q.push(node->left);
            }
            if(node->right!=NULL)
            {
                q.push(node->right);
            }
        } 
        else if(!q.empty())
        {
            q.push(NULL);
        }
    }
}

int search(int inOrder[], int start, int end, int curr)
{
    for(int i=start; i<=end; i++)
    {
        if(inOrder[i]==curr)
        {
            return i;
        }
    }
    return -1;
}

//Creating tree from PreOrder and Inorder.
Node* buildTreePre(int preOrder[], int inOrder[], int start, int end)
{
    static int idx = 0;
    if(start>end)
    {
        return NULL;
    }

    int curr = preOrder[idx];
    Node* node = new Node(curr);
    idx++;
    if(start == end)
    {
        return node;
    }
    int pos = search(inOrder, start, end, curr);
    node->left = buildTreePre(preOrder, inOrder, start, pos-1);
    node->right = buildTreePre(preOrder, inOrder, pos+1, end);

    return node;
}

//Creating tree from PostOrder and Inorder.
Node* buildTreePost(int postOrder[], int inOrder[], int start, int end)
{
    static int idx = end;
    if(start>end)
    {
        return NULL;
    }

    int curr = postOrder[idx];
    Node* node = new Node(curr);
    idx--;
    if(start==end)
    {
        return node;
    }
    int pos = search(inOrder, start, end, curr);
    node->right = buildTreePost(postOrder, inOrder, pos+1, end);
    node->left = buildTreePost(postOrder, inOrder, start, pos-1);

    return node;
}

//Sum at kth level
int sumAtK(Node* root, int k)
{
    if(root==NULL)
    {
        return -1;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();
        if(node!=NULL)
        {
            if(level==k)
            {
                sum+=node->data;
            }
            if(node->left != NULL)
            {
                q.push(node->left);
            }
            if(node->right!=NULL)
            {
                q.push(node->right);
            }
        } 
        else if(!q.empty())
        {
            q.push(NULL);
            level++;
        } 
    }
    return sum;
}

//Count of total node
int count(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    return count(root->left)+count(root->right)+1;
}

//Sum of all the nodes
int sum(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    return sum(root->left) + sum(root->right) + root->data;
}

//Height of a tree
int calH(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int lheight = calH(root->left);
    int rheight = calH(root->right);

    return max(lheight, rheight)+1;
}

//Diameter of a tree
int calD(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int lheight = calH(root->left);
    int rheight = calH(root->right);

    int currD = lheight + rheight + 1;

    int rD = calD(root->left);
    int lD = calD(root->right);

    return max(currD, max(lD, rD));

    /*
    More optimised way

    int calD(Node* root, int &height)
    {
        if(root==Null)
        {
            *height = 0;
            return 0;
        }

        int lh = 0, rh=0;
        int ld = calD(root->left, &lh);
        int rd = claD(root->right, &rh);

        int currh = lh+rh+1;
        *height = max(lh,rh)+1;

        return max(*currh, max(ld, rd)); 
    }
    */
}


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //inOrder, preOrder, postOrder and levelOrder
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    levelOrder(root);
    cout<<endl;

    //Building tree form PreOrder and Inorder
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};

    Node* root2 = buildTreePre(preorder, inorder, 0, 4);
    inOrder(root2);
    cout<<endl;

    //Building tree form PostOrder and Inorder
    int postorder[] = {4,2,5,3,1};
    Node* root3 = buildTreePost(postorder, inorder, 0, 4);
    inOrder(root3);
    cout<<endl;

    //Sum  at kth Level
    cout<<sumAtK(root, 2)<<endl;

    //Count of all total nodes present
    cout<<count(root)<<endl;

    //Sum of all the nodes
    cout<<sum(root)<<endl;

    //Calculating height
    cout<<calH(root)<<endl;

    //Calculating Diameter
    cout<<calD(root)<<endl;

}