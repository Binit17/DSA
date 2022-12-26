// factorial of a num using recursion
#include<iostream>
using namespace std;

int fact(int num)
{
    //base case
    if(num==0)
        return 1;
    //recursive relation
    return num*fact(num-1);
}

int main()
{
    int num;
    cout<<"enter num: ";
    cin>>num;
    cout<<"factorial: "<<fact(num);
    return 0;
}