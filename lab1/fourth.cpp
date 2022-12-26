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

bool isFrontDelimiter(char c)
{
    if(c=='(' || c =='{' || c=='[')
        return true;
    return false;
}

bool isBackDelimiter(char c)
{
    if(c==')' || c=='}' || c==']')
        return true;
    return false;
}

int codeNum(char c)
{
    switch(c){
        case ')':
        case '(':
            return 1;
        case '{':
        case '}':
            return 2;
        case '[':
        case ']':
            return 3;
        default:
            return 0;
    }
}

bool checkParentheses(string s)
{
    int n=s.size(); 
    stackk<char> st(n);
    for(int i =0;i<n;i++)
    {
        if(isFrontDelimiter(s[i])){
            st.push(s[i]);
        }

        else if(isBackDelimiter(s[i])){
            if (codeNum(s[i])==codeNum(st.peek()))
                st.pop();
            else
                return false;
        }
    }
    if(!st.isEmpty())
        return false;
    else 
        return true;
}

int main()
{
    string input ="(()))";
    bool output = checkParentheses(input);
    if(output == 1)
        cout<<"Given parentheses is balanced.";
    else
        cout<<"Given parentheses is not balanced.";
    return 0;
}