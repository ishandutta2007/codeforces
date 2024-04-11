using namespace std;
#include<iostream>
#include<cstdio>
#include<cstring>
bool nto(int x)
{
    if (x<2) return false;
    if (x==2) return true;
    if (1-x&1) return false;
    for(int k=3;k*k<=x;k+=2)
    if (x%k==0) return false;
    return true;
}
int dao(int n)
{
    int s=0;
    while (n)
    {
        s=s*10+n%10;n/=10;
    }
    return s;
}
int main()
{
    int n;
    cin>>n;
    int res=0;
    for(int i=13;i<=1000000;i++)
    if (nto(i))
    if (dao(i)!=i)
    if (nto(dao(i)))
    {
        res++;
        if (res==n)
        {cout<<i;return 0;}
    }
    return 0;
}