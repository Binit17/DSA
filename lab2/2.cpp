//circular queue

#include<iostream>
using namespace std;

class circularQueue
{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    circularQueue(int n)
    {
        this -> size = n;
        arr=new int[size];
        front = rear = -1;
    } 

    void enqueue(int value)
    {
        if ((rear+1)%size == front)
            cout<<"cannot perform operation, queue is full. "<<endl;
        else if(front == -1)
            front =0;
        rear = (rear+1)%size;
        arr[rear]=value;
    }

    int dequeue()
    {
        if (front ==-1)
        {
            cout<<"queue is empty. cannot dequeue";
            return -1;
        }
        int result = arr[front];
        if (front == rear)
        {
            return result;
            front =rear =-1;
        }
        else
        {
             front = (front +1 )% size;
            return result;
        }
    }
};

int main()
{
    int c,i;
    circularQueue d(3);
    do{
      cout<<"\n 1.perform enqueue";
      cout<<"\n 2.perform dequeue";
      cout<<"\n 3. Stop";
      cout<<"\n enter your choice:";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"enter the element to be inserted: ";
            cin>>i;
            d.enqueue(i);
         break;
         case 2:
            d.dequeue();
         break;
         default:
            cout<<"invalid choice";
         break;
      }
   } while(c!=3);
   return 0;
}