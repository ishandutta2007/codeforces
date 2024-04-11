#include<bits/stdc++.h>
using namespace std;

int T;

long long x,y;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&x,&y);    
        if(x>y)
            printf("%lld\n",x+y);
        else
        {
            long long k=y/x*x;
            printf("%lld\n",(k+y)/2);
        }
    }
}