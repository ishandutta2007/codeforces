#include<bits/stdc++.h>
using namespace std;

int T,a,b;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&a,&b);
        puts(__gcd(a,b)==1?"Finite":"Infinite");
    }
}