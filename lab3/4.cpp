// TOWER OF HANOI
#include<iostream>
using namespace std;

void TOH(int num, string source, string dest, string aux)
{
    if(num==1)
    {
        cout<<"move disk 1 from tower "<<source<<" to tower "<< dest<< endl;
    }
    else{
        TOH(num-1,source, aux, dest);
        cout<<" move disk "<< num << " from tower "<< source << " to tower "<< dest << endl;
        TOH(num-1,aux,dest,source);
    }
}

int main()
{
    int num;
    cout<<"enter the no. of disks: ";
    cin>>num;
    cout<<"the sequence of moves: \n";
    TOH(num,"I","III","II");
    return 0;
}