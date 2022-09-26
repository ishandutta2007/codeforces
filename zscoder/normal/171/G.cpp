#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c;
    if (c==0) {cout<<a;return 0;}
    if (c==1) {cout<<b;return 0;}
    for(int i=1;i<c;i++)
    {
        d=a+b;a=b;b=d;
    }
    cout<<d;
    return 0;
}