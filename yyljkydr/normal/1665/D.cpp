#include<bits/stdc++.h>
using namespace std;

#define int long long

int T,gs;

int ask(int x,int y)
{
    printf("? %lld %lld\n",x,y);
    fflush(stdout);
    int r;
    // r=__gcd(x+gs,y+gs);
    scanf("%lld",&r);
    return r;
}

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        // scanf("%lld",&gs);
        int x=0;
        for(int i=0;i<30;i++)
        {
            int p=1<<i;
            int a=p-x,b=3*p-x;
            int g=ask(a,b);
            if(g==p*2)
                x+=1<<i;
        }
        printf("! %lld\n",x);
        fflush(stdout);
    }
}