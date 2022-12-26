// factorial of a num using recursion
#include<iostream>
using namespace std;

int fact(int num,int result)
{
    //base case
    if(num==0)
        return result;
    //recursive relation
    return fact(num-1,num*result);
}
int fact(int num)
{
    return fact(num,1);
}

int main()
{
    int num;
    cout<<"enter num: ";
    cin>>num;
    cout<<"factorial: "<<fact(num);
    return 0;
}