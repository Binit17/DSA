#include<iostream>
using namespace std;

template <class T>
class stackk
{
    public:
    T *arr;
    int top;
    int sizee;

    stackk(int sizee)
    {
        cout<<"stack created."<<endl;
        this->sizee=sizee;
        arr = new T[sizee];
        top=-1;
    }

    void push(T data)
    {
        if(top==sizee-1)
        {
            cout<<"stack is full."<<endl;
        }
        else{
            top++;
            arr[top]=data;
        }
    }

    void pop()
    {
        if(top == -1)
            cout<<"stack is empty"<<endl;
        else
            top--;
    }

    T peek()
    {
        if(top==-1)
        {
            cout<<"stack is empty."<<endl;
            return 0;
        }
        else
            return arr[top];
    }

    bool isEmpty()
    {
        return (top==-1);
    }
};

int main()
{
    stackk<char> st(5);
    st.push('b');
    st.push('i');
    st.push('n');
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek();
    return 0;
}