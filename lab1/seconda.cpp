//infix to postfix expression

#include<iostream>
#include<cstring>
#include<string>
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

int priority (char alpha){
    if(alpha == '+' || alpha =='-')
        return 1;
 
    if(alpha == '*' || alpha =='/')
        return 2;
 
    if(alpha == '^')
        return 3;

 
    return 0;
}
string convertToPostfix(string infix)
{
    int i = 0;
    int n=infix.size();
    string postfix = "";

    stackk<char> s(n);

    while(infix[i]!='\0')
    {
        // if operand add to the postfix expression
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')          
        {
            postfix += infix[i];
            i++;
        }
        // if opening bracket then push the stack
        else if(infix[i]=='(')
        {
            s.push(infix[i]);
            i++;
        }
        // if closing bracket encounted then keep popping from stack until 
        // closing a pair opening bracket is not encountered
        else if(infix[i]==')')
        {
            while(s.peek()!='('){
                postfix += s.peek();
                s.pop();
            }
            s.pop();
            i++;
        }
        else            
        {
            while (!s.isEmpty() && priority(infix[i]) <= priority(s.peek())){
                postfix += s.peek();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while(!s.isEmpty()){
        postfix += s.peek();
        s.pop();
    }


    cout << "Postfix is : " << postfix; //it will print postfix conversion  
    return postfix;
}

string convertToPrefix(string infix)
{
    int i = 0;
    infix=strrev(infix); //this is to reverse the string.
    int n=infix.size();
    string prefix = "";

    stackk<char> s(n);

    while(infix[i]!='\0')
    {
        // if operand add to the postfix expression
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')          
        {
            prefix += infix[i];
            i++;
        }
        // if closing bracket then push the stack
        else if(infix[i]==')')
        {
            s.push(infix[i]);
            i++;
        }
        // if opening bracket encounted then keep popping from stack until 
        // closing a pair closing bracket is not encountered
        else if(infix[i]=='(')
        {
            while(s.peek()!=')'){
                prefix += s.peek();
                s.pop();
            }
            s.pop();
            i++;
        }
        else            
        {
            while (!s.isEmpty() && priority(infix[i]) <= priority(s.peek())){
                prefix += s.peek();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while(!s.isEmpty()){
        prefix += s.peek();
        s.pop();
    }


    cout << "Prefix is : " << strrev(prefix); //it will print prefix conversion  
    return prefix;
}


int main()
{
    string infix = "((a+(b*c))-d)"; 
    string postfix,prefix;
    cout<<"infix is : "<< infix<<endl;
    postfix = convertToPostfix(infix);
    prefix = convertToPrefix(infix);
    return 0;
}