//perform enque and deque in linear queue

#include<iostream>
using namespace std;

class Queue
{
    public:
    int *arr;
    int size;
    int front, rear;

    Queue(int size){   //constructor
        // cout<<"queue has been created."<<endl;
        this->size=size;
        arr=new int[size];
        front=0;
        rear=0;
    }

    void enqueue(int data)
    {
        if(rear==size)
            cout<<"queue is full"<<endl;
        else
        {
            arr[rear]=data;
            rear++;
        }
    }
    int dequeue(){
        if (front==rear){ 
            cout<<"queue is empty"<<endl;
            return -1;
        }
        else
        {
            int ans=arr[front];
            arr[front]=-1;
            front++;
            if (front==rear){
                front=0;
                rear=0;
            }
            return ans;
        }
    }
    int frontdata()
    {
        if(front==rear)
        {
            cout<<"queue is empty."<<endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
};

int main()
{
    int c,i;
    Queue d(5);
    do{
      cout<<"\n 1.perform enqueue";
      cout<<"\n 2.perform dequeue";
      cout<<"\n 3.show front data";
      cout<<"\n 4. Stop";
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
         case 3:
            cout<<d.frontdata()<<endl;
         break;
         default:
            cout<<"invalid choice";
         break;
      }
   } while(c!=4);
   return 0;
}