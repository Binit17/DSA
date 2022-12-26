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

    int pop()
    {
        if(top == -1)
        {
            cout<<"stack is empty"<<endl;
            return 0;
        }
        else
        {
            return arr[top];
            top--;
        }
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

bool isOperator(char c)
{
    return (c=='+' || c=='-' || c=='*' || c== '/');
}

int evaluate(string input)
{
    int n= input.size();
    int operandA, operandB;
    operandA=operandB=0;
    stackk<int> st(n);
    for (int i = 0; i < n; i++)
    {
        if (input[i]>='0' && input[i]<='9')
        {
            st.push(input[i]);
        }
        else if (isOperator(input[i]))
        {
            operandA = st.pop();
            operandB = st.pop();
            switch (input[i])
            {
            case '+':
                st.push(operandA + operandB);
                break;
            
            case '-':
                st.push(operandA - operandB);
                break;
            
            case '*':
                st.push(operandA * operandB);
                break;
            
            case '/':
                st.push(operandA / operandB);
                break;
            
            default:
                break;
            }
        }
    }
    int res= st.pop();
    return res;
}

int main()
{
    string ip="1+1-1";
    cout<<evaluate(ip);
    return 0;
}