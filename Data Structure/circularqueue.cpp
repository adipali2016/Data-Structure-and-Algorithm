// This module contains code for circular queue by arrays

#include<iostream>
using namespace std;

class cqueue{
    int front = -1;
    int rear = -1;
    int array_size;
    int* arr;

    public:
    cqueue(int n)
    {
        arr = new int[n];
        array_size = n;
    }

    void enqueue(int val)
    {
        if(front==-1 && rear==-1)
        {
            front=0;
            rear=0;
            arr[rear] = val;
            return;
        }
        if((rear+1)%array_size==front)
        {
            cout<<val<<" value could not be inserted: Overflow"<<endl;
            return;
        }
        rear = (rear+1)%array_size;
        arr[rear] = val;
    }

    void dequeue()
    {
        if(front == -1)
        {
            cout<<"Underflow"<<endl;
            return;
        }
        arr[front] = 0;
        if(front==rear)
        {
            front = -1;
            rear = -1;
            return;
        }
        front = (front+1)%array_size;
    }

    void display()
    {
        if(rear==-1)
        {
            cout<<"No values found"<<endl;
            return;
        }
        int temp = front;
        while(temp!=rear)
        {
            cout<<arr[temp]<<" ";
            temp = (temp+1)%array_size;
        }
        cout<<arr[rear]<<endl;
    }

    bool isEmpty()
    {
        if(rear==-1)
        {
            return true;
        }
        return false;
    }

    int peek(int pos)
    {
        if(rear==-1)
        {
            return -1;
        }
        int temp = front;
        while(pos)
        {
            temp = (temp+1)%array_size;
            pos--;
        }
        return arr[temp];
    }
};

void testcase1()
{
    cqueue q = cqueue(5);
    
    //Inserting values in circular queue
    cout<<"isEmpty function result: "<<q.isEmpty()<<endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();

    //Deleting values in circular queue;
    q.dequeue();
    q.dequeue();
    q.display();

    //Inserting again in circular queue
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.display();
    cout<<"isEmpty function result: "<<q.isEmpty()<<endl;

    //General testcase
    q.dequeue();
    q.dequeue();
    q.enqueue(80);
    q.display();

    //Value at pos=2
    cout<<q.peek(2)<<endl;  //pos is different from index. It is position in queue and not in array.

    //Empty situation
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    cout<<"isEmpty function result: "<<q.isEmpty()<<endl;

}

void testcase2()
{
    cqueue q = cqueue(5);
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<"isEmpty function result: "<<q.isEmpty()<<endl;
}

int main()
{
    testcase1();
    testcase2();
}