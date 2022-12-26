// fibonacci series using recursion

#include<iostream>
using namespace std;

int fibonacci(int num)
{
    //base case
    if(num==0 || num==1)
        return num;
    
    //recursive relation
    return fibonacci(num-1)+ fibonacci(num-2);
}

int main()
{
int n = 9;
    cout << "fib(" << n << ") = "<< fibonacci(n) << endl;
    return 0;
}