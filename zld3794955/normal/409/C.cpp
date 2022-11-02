#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a[5]={};
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
    int x=min(min(a[0],a[1]),min(a[2]/2,a[3]/7));
    x=min(x,a[4]/4);
    cout<<x<<endl;
}