// This module contains code for operations on queue with arrays.

#include<iostream>
using namespace std;

class queue{
    int front=-1;
    int rear=-1;
    int* arr;
    int arr_size;

    public:

    queue(int n)
    {
        arr = new int[n];
        arr_size = n;
    }
    
    void enqueue(int val)
    {
        if(rear >= arr_size-1)
        {
            cout<<"Overflow"<<endl;
            return;
        }
        if(rear==-1)
        {
            front=0;
        }
        rear++;
        arr[rear] = val;
    }

    void dequeue()
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

    bool isEmpty()
    {
        if(front>rear || front==-1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if(front==0 && rear==arr_size-1)
        {
            return true;
        }
        return false;
    }

    int peek(int pos)
    {
        if((front+pos)>rear)
        {
            cout<<"No element found"<<endl;
            return -1;
        }
        return arr[front+pos];
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

int main()
{
    queue q = queue(10);
    q.display(); //Displaying the queue

    //Inserting in queue
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.enqueue(400);
    q.enqueue(500);
    q.enqueue(600);
    q.enqueue(700);
    q.enqueue(800);
    q.enqueue(900);
    q.enqueue(1000);
    q.enqueue(400);
    q.display();

    //Checking isFull.
    cout<<"ISFULL: "<<q.isFull()<<endl;

    //Deleting the values
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();

    //Checking isFull and isEmpty for another instance
    cout<<"ISFULL: "<<q.isFull()<<endl;
    cout<<"ISEMPTY: "<<q.isEmpty()<<endl;

    //Checking value at 3
    cout<<q.peek(3)<<endl; 

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<"ISEMPTY: "<<q.isEmpty()<<endl;


}