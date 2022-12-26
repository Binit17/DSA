//infix to postfix expression

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

int precedence(char ch)
{
    switch(ch){
        case '-':
        case '+':
            return 1;
        case '*':
        case '/':
            return 2;
        default :
            return -1;
    }
}

bool isOperand(char ch)
{
    return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z');
}

string infixToPostfix(string infix)
{
    //first find the length of infix
    int n=infix.size();
    //create a stack
    stackk<char> st(n);

    string postfix;
    for (int i = 0; i < n; i++)
    {
        if (isOperand(infix[i]))
        {
            postfix.push_back(infix[i]);
        }
        else if(infix[i]=='(')
        {
            st.push('(');
        }
        else if(infix[i]==')')
        {
            while (infix[i]!='(')
            {
                // char ch=st.top();
                postfix.push_back(st.peek());
                st.pop();
            }
            st.pop(); // this is to remove '('
        }
        else
        {
            while (!st.isEmpty() && st.peek()!='(' && precedence(st.peek())>=precedence(infix[i])){
                postfix.push_back(st.peek());
                st.pop();
            }
            st.push(infix[i]);
        }

    }

    while(!st.isEmpty())
    {
        postfix.push_back(st.peek());
        st.pop();
    }   
    return postfix; 
}



int main()
{
    //your code goes here
    string infix="a*(b+c+d)";
    cout<<infix.size();
    // string postfix=infixToPostfix(infix);
    cout<<"infix expression: "<<infix<<endl;
    // cout<<"postfix expression: "<<postfix<<endl;
    return 0;
}