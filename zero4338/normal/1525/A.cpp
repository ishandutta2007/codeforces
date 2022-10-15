#include<iostream>
#include<cstdio>
using namespace std;
int t;
int k;
int gcd(int a,int b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int k;scanf("%d",&k);
        int d=gcd(k,100-k);
        printf("%d\n",k/d+(100-k)/d);
    }
    return 0;
}