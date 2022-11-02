#include <iostream>
using namespace std;

int n;
int a, b;
int t[10];
int main()
{
 cin>>n;


t[0]=2;
t[1]=7;
t[2]=2;
t[3]=3;
t[4]=3;
t[5]=4;
t[6]=2;
t[7]=5;
t[8]=1;
t[9]=2;
b=n%10;
    a=n/10;



    cout<<t[a]*t[b];


    return 0;
}