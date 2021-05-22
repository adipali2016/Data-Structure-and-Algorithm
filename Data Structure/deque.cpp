// This module contains code for Double-ended queue by array.

#include<iostream>
using namespace std;

class deque{
    int array_size;
    int* arr;
    int front;
    int rear;

    public:
    deque(int n)
    {
        arr = new int[n];
        array_size = n;
        front = -1;
        rear = -1;
    }

    void insertionFromFront(int val)
    {
        if(front==-1)
        {
            front = rear = 0;
            arr[front] = val;
            return;
        }
        if((front-1)<0)
        {
            if(rear==array_size-1)
            {
                cout<<"Overflow"<<endl;
                return;
            }
            cout<<"Cannot insert from front"<<endl;
            return;
        }
        front--;
        arr[front] = val;
    }

    void insertionFromRear(int val)
    {
        if(rear >= array_size-1)
        {
            if(front==0)
            {
                cout<<"Overflow"<<endl;
                return;
            }
            cout<<"Cannot insert from rear"<<endl;
            return;
        }
        if(rear==-1)
        {
            front=0;
        }
        rear++;
        arr[rear] = val;
    }

    void deletionFromFront()
    {
        if(front==-1 || front>rear)
        {
            cout<<"Underflow"<<endl;
            if(front>rear)
            {
                front=-1;
                rear=-1;
                return;
            }
            return;
        }
        front++;
    }

    void deletionFromRear()
    {
        if((rear-1)<0)
        {
            cout<<"Underflow"<<endl;
            return;
        }
        if(front>rear)
        {
            cout<<"Underflow"<<endl;
            front=-1;
            rear=-1;
            return;
        }
        rear--;
    }

    bool isEmpty()
    {
        if(front==-1)
        {
            return true;
        }
        return false;
    }

    void display()
    {
        if(rear==-1)
        {
            cout<<"No element"<<endl;
            return;
        }
        for(int i=front; i<=rear; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

void testcase1()
{
    deque q = deque(5);
    
    //Insertion form both sides
    q.insertionFromFront(10);
    q.insertionFromRear(20);
    q.insertionFromRear(30);
    q.insertionFromRear(40);
    q.insertionFromFront(20);
    q.insertionFromRear(50);
    q.insertionFromRear(60);
    q.display();

    //Deletion from both sides
    q.deletionFromFront();
    q.deletionFromRear();
    q.deletionFromFront();
    q.display();
    q.deletionFromRear();
    q.deletionFromFront();
    q.deletionFromRear();

    //Insertion and Deletion from both sides.
    q.insertionFromFront(10);
    q.insertionFromRear(20);
    q.deletionFromFront();
    q.insertionFromRear(30);
    q.insertionFromFront(40);
    q.insertionFromFront(50);
    q.display();
}

int main()
{
    testcase1();
}