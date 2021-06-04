//This module will provide code for functions related to Arrays. 

#include<iostream>
using namespace std;

int top; // Variable which contains empty index of the array
int array_size; //Size of the array
void insert(int* a, int x)
{
    //Insertion at the end of the list.
    if(top>array_size-1)
    {
        cout<<"Could not insert"<<endl;
        return;
    }
    a[top] = x;
    top++;
}

//Insert at pos
void insertAtPos(int* a, int x, int m)
{
    //Insertion at an specific position.
    // m is the index where 'x' is inserted.
    int pos = a[m];
    if(top>array_size-1)
    {
        cout<<"Could not insert due to unavailability of space in the array"<<endl;
        return;
    }
    for(int i=m; i<top; i++)
    {
        a[m] = x;
        x = a[m+1];
        a[m+1] = pos;
    }
    top++;
}

//Traverse
void traverse(int* a)
{
    if(top>0)
    {
        for(int i=0; i<top; i++)
        {
            cout<<a[i]<<" ";
        }cout<<endl;
    }
    else{
        cout<<"No element present";
    }

}

//Search
int search(int* a, int m)
{
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0; i<n; i++)
    {
        if(a[i]==m)
        {
            return i;
        }
    }
    return -1;
}

//Deletion
void deletion(int* a, int m)
{
    int x = search(a,m);
    if(x==-1)
    {
        cout<<"Could not find m in the array"<<endl;
        return;
    }
    int temp=0;
    for(int i=x+1; i<top; i++)
    {
        temp = a[i];
        a[x] = temp;
        x++;
    }
    a[top-1]= 0;
    top--;
}

int main()
{
    int n;
    cin>>n;
    array_size = n;
    int a[n];
    insert(a,5);
    //cout<<"TOP IS: "<<top<<endl;
    insert(a, 9);
    //cout<<"TOP IS: "<<top<<endl;
    insert(a, 10);
    //cout<<"TOP IS: "<<top<<endl;
    insert(a,1);
    //cout<<"TOP IS: "<<top<<endl;
    insertAtPos(a, 8, 3);
    //cout<<"TOP IS: "<<top<<endl;
    insert(a, 12);
    traverse(a);
    //cout<<"TOP IS: "<<top<<endl;
    deletion(a,5);
    traverse(a);
    cout<<"TOP IS: "<<top<<endl;
    return 0;
}
