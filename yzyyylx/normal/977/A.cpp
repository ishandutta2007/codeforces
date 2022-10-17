#include<iostream>
#include<cstdio>
using namespace std;

int n,k;

int main()
{
    int i,j;
    cin>>n>>k;
    while(k--)
    {
        if(n%10==0) n/=10;
        else n--;
    }
    cout<<n;
}